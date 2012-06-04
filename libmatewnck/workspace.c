/* workspace object */
/* vim: set sw=2 et: */

/*
 * Copyright (C) 2001 Havoc Pennington
 * Copyright (C) 2003 Kim Woelders
 * Copyright (C) 2003 Red Hat, Inc.
 * Copyright (C) 2006-2007 Vincent Untz
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <config.h>

#include <glib/gi18n-lib.h>
#include "workspace.h"
#include "xutils.h"
#include "private.h"
#include <string.h>

/**
 * SECTION:workspace
 * @short_description: an object representing a workspace.
 * @see_also: #MatewnckScreen
 * @stability: Unstable
 *
 * The #MatewnckWorkspace represents what is called <ulink
 * url="http://standards.freedesktop.org/wm-spec/wm-spec-latest.html&num;largedesks">virtual
 * desktops</ulink> in the <ulink
 * url="http://standards.freedesktop.org/wm-spec/wm-spec-latest.html">EWMH</ulink>.
 * A workspace is a virtualization of a #MatewnckScreen<!-- -->: only one workspace
 * can be shown on a #MatewnckScreen at a time. It makes it possible, for example,
 * to put windows on different workspaces to organize them.
 *
 * If the #MatewnckWorkspace size is bigger that the #MatewnckScreen size, the
 * workspace contains a viewport. Viewports are defined in the <ulink
 * url="http://standards.freedesktop.org/wm-spec/wm-spec-latest.html&num;id2457064">large
 * desktops</ulink> section of the <ulink
 * url="http://standards.freedesktop.org/wm-spec/wm-spec-latest.html">EWMH</ulink>.
 * The notion of workspaces and viewports are quite similar, and generally both
 * are not used at the same time: there are generally either multiple
 * workspaces with no viewport, or one workspace with a viewport. libmatewnck
 * supports all situations, even multiple workspaces with viewports.
 *
 * Workspaces are organized according to a layout set on the #MatewnckScreen. See
 * matewnck_screen_try_set_workspace_layout() and
 * matewnck_screen_release_workspace_layout() for more information about the
 * layout.
 *
 * The #MatewnckWorkspace objects are always owned by libmatewnck and must not be
 * referenced or unreferenced.
 */

struct _MatewnckWorkspacePrivate
{
  MatewnckScreen *screen;
  int number;
  char *name;
  int width, height;            /* Workspace size */
  int viewport_x, viewport_y;   /* Viewport origin */
  gboolean is_virtual;
};

G_DEFINE_TYPE (MatewnckWorkspace, matewnck_workspace, G_TYPE_OBJECT);
#define MATEWNCK_WORKSPACE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), MATEWNCK_TYPE_WORKSPACE, MatewnckWorkspacePrivate))

enum {
  NAME_CHANGED,
  LAST_SIGNAL
};

static void matewnck_workspace_init        (MatewnckWorkspace      *workspace);
static void matewnck_workspace_class_init  (MatewnckWorkspaceClass *klass);
static void matewnck_workspace_finalize    (GObject        *object);


static void emit_name_changed (MatewnckWorkspace *space);

static guint signals[LAST_SIGNAL] = { 0 };

static void
matewnck_workspace_init (MatewnckWorkspace *workspace)
{
  workspace->priv = MATEWNCK_WORKSPACE_GET_PRIVATE (workspace);

  workspace->priv->screen = NULL;
  workspace->priv->number = -1;
  workspace->priv->name = NULL;
  workspace->priv->width = 0;
  workspace->priv->height = 0;
  workspace->priv->viewport_x = 0;
  workspace->priv->viewport_y = 0;
  workspace->priv->is_virtual = FALSE;
}

static void
matewnck_workspace_class_init (MatewnckWorkspaceClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  g_type_class_add_private (klass, sizeof (MatewnckWorkspacePrivate));

  object_class->finalize = matewnck_workspace_finalize;

  /**
   * MatewnckWorkspace::name-changed:
   * @space: the #MatewnckWorkspace which emitted the signal.
   *
   * Emitted when the name of @space changes.
   */
  signals[NAME_CHANGED] =
    g_signal_new ("name_changed",
                  G_OBJECT_CLASS_TYPE (object_class),
                  G_SIGNAL_RUN_LAST,
                  G_STRUCT_OFFSET (MatewnckWorkspaceClass, name_changed),
                  NULL, NULL,
                  g_cclosure_marshal_VOID__VOID,
                  G_TYPE_NONE, 0);
}

static void
matewnck_workspace_finalize (GObject *object)
{
  MatewnckWorkspace *workspace;

  workspace = MATEWNCK_WORKSPACE (object);

  g_free (workspace->priv->name);
  workspace->priv->name = NULL;
  
  G_OBJECT_CLASS (matewnck_workspace_parent_class)->finalize (object);
}

/**
 * matewnck_workspace_get_number:
 * @space: a #MatewnckWorkspace.
 * 
 * Gets the index of @space on the #MatewnckScreen to which it belongs. The
 * first workspace has an index of 0.
 * 
 * Return value: the index of @space on its #MatewnckScreen, or -1 on errors.
 **/
int
matewnck_workspace_get_number (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), -1);
  
  return space->priv->number;
}

/**
 * matewnck_workspace_get_name:
 * @space: a #MatewnckWorkspace.
 * 
 * Gets the human-readable name that should be used to refer to @space. If
 * the user has not set a special name, a fallback like "Workspace 3" will be
 * used.
 * 
 * Return value: the name of @space.
 **/
const char*
matewnck_workspace_get_name (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), NULL);
  
  return space->priv->name;
}

/**
 * matewnck_workspace_change_name:
 * @space: a #MatewnckWorkspace.
 * @name: new name for @space.
 *
 * Changes the name of @space.
 * 
 * Since: 2.2
 **/
void
matewnck_workspace_change_name (MatewnckWorkspace *space,
                            const char    *name)
{
  g_return_if_fail (MATEWNCK_IS_WORKSPACE (space));
  g_return_if_fail (name != NULL);

  _matewnck_screen_change_workspace_name (space->priv->screen,
                                      space->priv->number,
                                      name);
}

/**
 * matewnck_workspace_get_screen:
 * @space: a #MatewnckWorkspace.
 *
 * Gets the #MatewnckScreen @space is on.
 *
 * Return value: the #MatewnckScreen @space is on. The returned #MatewnckScreen is
 * owned by libmatewnck and must not be referenced or unreferenced.
 **/
MatewnckScreen*
matewnck_workspace_get_screen (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), NULL);

  return space->priv->screen;
}

/**
 * matewnck_workspace_activate:
 * @space: a #MatewnckWorkspace.
 * @timestamp: the X server timestamp of the user interaction event that caused
 * this call to occur.
 * 
 * Asks the window manager to make @space the active workspace. The window
 * manager may decide to refuse the request (to not steal the focus if there is
 * a more recent user activity, for example).
 *
 * This function existed before 2.10, but the @timestamp argument was missing
 * in earlier versions.
 * 
 * Since: 2.10
 **/
void
matewnck_workspace_activate (MatewnckWorkspace *space,
                         guint32        timestamp)
{
  g_return_if_fail (MATEWNCK_IS_WORKSPACE (space));

  _matewnck_activate_workspace (MATEWNCK_SCREEN_XSCREEN (space->priv->screen),
                            space->priv->number,
                            timestamp);
}

MatewnckWorkspace*
_matewnck_workspace_create (int number, MatewnckScreen *screen)
{
  MatewnckWorkspace *space;
  
  space = g_object_new (MATEWNCK_TYPE_WORKSPACE, NULL);
  space->priv->number = number;
  space->priv->name = NULL;
  space->priv->screen = screen;

  _matewnck_workspace_update_name (space, NULL);
  
  /* Just set reasonable defaults */
  space->priv->width = matewnck_screen_get_width (screen);
  space->priv->height = matewnck_screen_get_height (screen);
  space->priv->is_virtual = FALSE;

  space->priv->viewport_x = 0;
  space->priv->viewport_y = 0;

  return space;
}

void
_matewnck_workspace_update_name (MatewnckWorkspace *space,
                             const char    *name)
{
  char *old;
  
  g_return_if_fail (MATEWNCK_IS_WORKSPACE (space));

  old = space->priv->name;
  space->priv->name = g_strdup (name);

  if (space->priv->name == NULL)
    space->priv->name = g_strdup_printf (_("Workspace %d"),
                                         space->priv->number + 1);

  if ((old && !name) ||
      (!old && name) ||
      (old && name && strcmp (old, name) != 0))
    emit_name_changed (space);

  g_free (old);
}

static void
emit_name_changed (MatewnckWorkspace *space)
{
  g_signal_emit (G_OBJECT (space),
                 signals[NAME_CHANGED],
                 0);
}

gboolean
_matewnck_workspace_set_geometry (MatewnckWorkspace *space,
                              int            w,
                              int            h)
{
  if (space->priv->width != w || space->priv->height != h)
    {
      space->priv->width = w;
      space->priv->height = h;

      space->priv->is_virtual = w > matewnck_screen_get_width (space->priv->screen) ||
				h > matewnck_screen_get_height (space->priv->screen);

      return TRUE;  /* change was made */
    }
  else
    return FALSE; 
}

gboolean
_matewnck_workspace_set_viewport (MatewnckWorkspace *space,
                              int            x,
                              int            y)
{
  if (space->priv->viewport_x != x || space->priv->viewport_y != y)
    {
      space->priv->viewport_x = x;
      space->priv->viewport_y = y;

      return TRUE; /* change was made */
    }
  else
    return FALSE;
}

/**
 * matewnck_workspace_get_width:
 * @space: a #MatewnckWorkspace.
 *
 * Gets the width of @space.
 *
 * Returns: the width of @space.
 *
 * Since: 2.4
 */
int
matewnck_workspace_get_width (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), 0);

  return space->priv->width;
}

/**
 * matewnck_workspace_get_height:
 * @space: a #MatewnckWorkspace.
 *
 * Gets the height of @space.
 *
 * Returns: the height of @space.
 *
 * Since: 2.4
 */
int
matewnck_workspace_get_height (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), 0);

  return space->priv->height;
}

/**
 * matewnck_workspace_get_viewport_x:
 * @space: a #MatewnckWorkspace.
 *
 * Gets the X coordinate of the viewport in @space.
 *
 * Returns: the X coordinate of the viewport in @space, or 0 if @space does not
 * contain a viewport.
 *
 * Since: 2.4
 */
int
matewnck_workspace_get_viewport_x (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), 0);

  return space->priv->viewport_x;
}

/**
 * matewnck_workspace_get_viewport_y:
 * @space: a #MatewnckWorkspace.
 *
 * Gets the Y coordinate of the viewport in @space.
 *
 * Returns: the Y coordinate of the viewport in @space, or 0 if @space does not
 * contain a viewport.
 *
 * Since: 2.4
 */
int
matewnck_workspace_get_viewport_y (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), 0);

  return space->priv->viewport_y;
}

/**
 * matewnck_workspace_is_virtual:
 * @space: a #MatewnckWorkspace.
 *
 * Gets whether @space contains a viewport.
 *
 * Returns: %TRUE if @space contains a viewport, %FALSE otherwise.
 *
 * Since: 2.4
 */
gboolean
matewnck_workspace_is_virtual (MatewnckWorkspace *space)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), FALSE);

  return space->priv->is_virtual;
}

/**
 * matewnck_workspace_get_layout_row:
 * @space: a #MatewnckWorkspace.
 * 
 * Gets the row of @space in the #MatewnckWorkspace layout. The first row has an
 * index of 0 and is always the top row, regardless of the starting corner set
 * for the layout.
 * 
 * Return value: the row of @space in the #MatewnckWorkspace layout, or -1 on
 * errors.
 *
 * Since: 2.20
 **/
int
matewnck_workspace_get_layout_row (MatewnckWorkspace *space)
{
  _MatewnckLayoutOrientation orientation;
  _MatewnckLayoutCorner corner;
  int n_rows;
  int n_cols;
  int row;

  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), -1);

  _matewnck_screen_get_workspace_layout (space->priv->screen,
                                     &orientation, &n_rows, &n_cols, &corner);

  if (orientation == MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL)
    row = space->priv->number / n_cols;
  else
    row = space->priv->number % n_rows;

  if (corner == MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT ||
      corner == MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT)
    row = n_rows - row;

  return row;
}

/**
 * matewnck_workspace_get_layout_column:
 * @space: a #MatewnckWorkspace.
 * 
 * Gets the column of @space in the #MatewnckWorkspace layout. The first column
 * has an index of 0 and is always the left column, regardless of the starting
 * corner set for the layout and regardless of the default direction of the
 * environment (i.e., in both Left-To-Right and Right-To-Left environments).
 * 
 * Return value: the column of @space in the #MatewnckWorkspace layout, or -1 on
 * errors.
 *
 * Since: 2.20
 **/
int
matewnck_workspace_get_layout_column (MatewnckWorkspace *space)
{
  _MatewnckLayoutOrientation orientation;
  _MatewnckLayoutCorner corner;
  int n_rows;
  int n_cols;
  int col;

  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), -1);

  _matewnck_screen_get_workspace_layout (space->priv->screen,
                                     &orientation, &n_rows, &n_cols, &corner);

  if (orientation == MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL)
    col = space->priv->number % n_cols;
  else
    col = space->priv->number / n_rows;

  if (corner == MATEWNCK_LAYOUT_CORNER_TOPRIGHT ||
      corner == MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT)
    col = n_cols - col;

  return col;
}

/**
 * matewnck_workspace_get_neighbor:
 * @space: a #MatewnckWorkspace.
 * @direction: direction in which to search the neighbor.
 * 
 * Gets the neighbor #MatewnckWorkspace of @space in the @direction direction.
 *
 * Return value: the neighbor #MatewnckWorkspace of @space in the @direction
 * direction, or %NULL if no such neighbor #MatewnckWorkspace exists. The returned
 * #MatewnckWorkspace is owned by libmatewnck and must not be referenced or
 * unreferenced.
 *
 * Since: 2.20
 **/
MatewnckWorkspace*
matewnck_workspace_get_neighbor (MatewnckWorkspace       *space,
                             MatewnckMotionDirection  direction)
{
  _MatewnckLayoutOrientation orientation;
  _MatewnckLayoutCorner corner;
  int n_rows;
  int n_cols;
  int row;
  int col;
  int add;
  int index;

  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (space), NULL);

  _matewnck_screen_get_workspace_layout (space->priv->screen,
                                     &orientation, &n_rows, &n_cols, &corner);

  row = matewnck_workspace_get_layout_row (space);
  col = matewnck_workspace_get_layout_column (space);

  index = space->priv->number;

  switch (direction)
    {
    case MATEWNCK_MOTION_LEFT:
      if (col == 0)
        return NULL;

      if (orientation == MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL)
        add = 1;
      else
        add = n_rows;

      if (corner == MATEWNCK_LAYOUT_CORNER_TOPRIGHT ||
          corner == MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT)
        index += add;
      else
        index -= add;
      break;

    case MATEWNCK_MOTION_RIGHT:
      if (col == n_cols - 1)
        return NULL;

      if (orientation == MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL)
        add = 1;
      else
        add = n_rows;

      if (corner == MATEWNCK_LAYOUT_CORNER_TOPRIGHT ||
          corner == MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT)
        index -= add;
      else
        index += add;
      break;

    case MATEWNCK_MOTION_UP:
      if (row == 0)
        return NULL;

      if (orientation == MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL)
        add = n_cols;
      else
        add = 1;

      if (corner == MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT ||
          corner == MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT)
        index += add;
      else
        index -= add;
      break;

    case MATEWNCK_MOTION_DOWN:
      if (row == n_rows - 1)
        return NULL;

      if (orientation == MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL)
        add = n_cols;
      else
        add = 1;

      if (corner == MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT ||
          corner == MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT)
        index -= add;
      else
        index += add;
      break;
    }

  if (index == space->priv->number)
    return NULL;

  return matewnck_screen_get_workspace (space->priv->screen, index);
}
