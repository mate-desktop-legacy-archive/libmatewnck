/* screen object */
/* vim: set sw=2 et: */

/*
 * Copyright (C) 2001 Havoc Pennington
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
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef MATEWNCK_SCREEN_H
#define MATEWNCK_SCREEN_H

#include <glib-object.h>

G_BEGIN_DECLS

/* forward decls */
typedef struct _MatewnckApplication MatewnckApplication;
typedef struct _MatewnckClassGroup  MatewnckClassGroup;
typedef struct _MatewnckWindow      MatewnckWindow;
typedef struct _MatewnckWorkspace   MatewnckWorkspace;

/* Screen */

#define MATEWNCK_TYPE_SCREEN              (matewnck_screen_get_type ())
#define MATEWNCK_SCREEN(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_SCREEN, MatewnckScreen))
#define MATEWNCK_SCREEN_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_SCREEN, MatewnckScreenClass))
#define MATEWNCK_IS_SCREEN(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_SCREEN))
#define MATEWNCK_IS_SCREEN_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_SCREEN))
#define MATEWNCK_SCREEN_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_SCREEN, MatewnckScreenClass))

typedef struct _MatewnckScreen        MatewnckScreen;
typedef struct _MatewnckScreenClass   MatewnckScreenClass;
typedef struct _MatewnckScreenPrivate MatewnckScreenPrivate;

/**
 * MatewnckScreen:
 *
 * The #MatewnckScreen struct contains only private fields and should not be
 * directly accessed.
 */
struct _MatewnckScreen
{
  GObject parent_instance;

  MatewnckScreenPrivate *priv;
};

struct _MatewnckScreenClass
{
  GObjectClass parent_class;

  /* focused window changed */
  void (* active_window_changed)    (MatewnckScreen *screen,
                                     MatewnckWindow *previous_window);
  /* current workspace changed */
  void (* active_workspace_changed) (MatewnckScreen *screen,
                                     MatewnckWorkspace *previous_workspace);
  /* stacking order changed */
  void (* window_stacking_changed)  (MatewnckScreen *screen);
  /* window added */
  void (* window_opened)            (MatewnckScreen *screen,
                                     MatewnckWindow *window);
  /* window removed */
  void (* window_closed)            (MatewnckScreen *screen,
                                     MatewnckWindow *window);
  /* new workspace */
  void (* workspace_created)        (MatewnckScreen *screen,
                                     MatewnckWorkspace *space);
  /* workspace gone */
  void (* workspace_destroyed)      (MatewnckScreen *screen,
                                     MatewnckWorkspace *space);
  /* new app */
  void (* application_opened)       (MatewnckScreen      *screen,
                                     MatewnckApplication *app);
  /* app gone */
  void (* application_closed)       (MatewnckScreen      *screen,
                                     MatewnckApplication *app);

  /* New background */
  void (* background_changed)       (MatewnckScreen      *screen);

  /* new class group */
  void (* class_group_opened)       (MatewnckScreen     *screen,
                                     MatewnckClassGroup *class_group);
  /* class group gone */
  void (* class_group_closed)       (MatewnckScreen     *screen,
                                     MatewnckClassGroup *class_group);
  /* Toggle showing desktop */
  void (* showing_desktop_changed)  (MatewnckScreen      *screen);

  /* Viewport stuff changed */
  void (* viewports_changed)        (MatewnckScreen      *screen);
  
  /* Window manager changed */
  void (* window_manager_changed)   (MatewnckScreen      *screen);

  /* Padding for future expansion */
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
  void (* pad5) (void);
  void (* pad6) (void);
};

#ifndef MATEWNCK_DISABLE_DEPRECATED
typedef struct _MatewnckWorkspaceLayout MatewnckWorkspaceLayout;

/**
 * MatewnckWorkspaceLayout:
 * @rows: number of rows in the layout grid.
 * @cols: number of columns in the layout grid.
 * @grid: array of size @grid_area containing the index (starting from 0) of
 * the #MatewnckWorkspace for each position in the layout grid, or -1 if the
 * position does not correspond to any #MatewnckWorkspace.
 * @grid_area: size of the grid containing all #MatewnckWorkspace. This can be
 * bigger than the number of #MatewnckWorskpace because the grid might not be
 * filled.
 * @current_row: row of the specific #MatewnckWorkspace, starting from 0.
 * @current_col: column of the specific #MatewnckWorkspace, starting from 0.
 *
 * The #MatewnckWorkspaceLayout struct contains information about the layout of
 * #MatewnckWorkspace on a #MatewnckScreen, and the exact position of a specific
 * #MatewnckWorkspace.
 *
 * Since: 2.12
 * Deprecated:2.20:
 */
struct _MatewnckWorkspaceLayout
{
  int rows;
  int cols;
  int *grid;
  int grid_area;
  int current_row;
  int current_col;
};
#endif /* MATEWNCK_DISABLE_DEPRECATED */

/**
 * MatewnckMotionDirection:
 * @MATEWNCK_MOTION_UP: search a neighbor #MatewnckWorkspace above another
 * #MatewnckWorkspace. 
 * @MATEWNCK_MOTION_DOWN: search a neighbor #MatewnckWorkspace below another
 * #MatewnckWorkspace.
 * @MATEWNCK_MOTION_LEFT: search a neighbor #MatewnckWorkspace at the left of another
 * #MatewnckWorkspace.
 * @MATEWNCK_MOTION_RIGHT: search a neighbor #MatewnckWorkspace at the right of another
 * #MatewnckWorkspace.
 *
 * Type defining a direction in which to search a neighbor #MatewnckWorkspace.
 *
 * Since: 2.14
 */
/* TODO: move this to workspace.h when we break API and remove
 * matewnck_screen_get_workspace_neighbor() */
typedef enum
{
  MATEWNCK_MOTION_UP = -1,
  MATEWNCK_MOTION_DOWN = -2,
  MATEWNCK_MOTION_LEFT = -3,
  MATEWNCK_MOTION_RIGHT = -4
} MatewnckMotionDirection;

/**
 * MatewnckLayoutOrientation:
 * @MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL: the #MatewnckWorkspace are laid out in
 * rows, with the first #MatewnckWorkspace in the defined #MatewnckLayoutCorner.
 * @MATEWNCK_LAYOUT_ORIENTATION_VERTICAL: the #MatewnckWorkspace are laid out in
 * columns, with the first #MatewnckWorkspace in the defined #MatewnckLayoutCorner.
 *
 * Type defining the orientation of the layout of #MatewnckWorkspace. See
 * matewnck_pager_set_orientation() for more information.
 */
typedef enum
{
  MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL,
  MATEWNCK_LAYOUT_ORIENTATION_VERTICAL
} _MatewnckLayoutOrientation;

/**
 * MatewnckLayoutCorner:
 * @MATEWNCK_LAYOUT_CORNER_TOPLEFT: the first #MatewnckWorkspace is in the top left
 * corner of the layout.
 * @MATEWNCK_LAYOUT_CORNER_TOPRIGHT: the first #MatewnckWorkspace is in the top right
 * corner of the layout.
 * @MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT: the first #MatewnckWorkspace is in the bottom
 * right corner of the layout.
 * @MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT: the first #MatewnckWorkspace is in the bottom
 * left corner of the layout.
 *
 * Type defining the starting corner of the layout of #MatewnckWorkspace, i.e. the
 * corner containing the first #MatewnckWorkspace.
 */
typedef enum
{
  MATEWNCK_LAYOUT_CORNER_TOPLEFT,
  MATEWNCK_LAYOUT_CORNER_TOPRIGHT,
  MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT,
  MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT
} _MatewnckLayoutCorner;

GType matewnck_screen_get_type (void) G_GNUC_CONST;

MatewnckScreen*    matewnck_screen_get_default              (void);
MatewnckScreen*    matewnck_screen_get                      (int         index);
MatewnckScreen*    matewnck_screen_get_for_root             (gulong      root_window_id);
int            matewnck_screen_get_number               (MatewnckScreen *screen);
MatewnckWorkspace* matewnck_screen_get_workspace            (MatewnckScreen *screen,
                                                     int         workspace);
#ifndef MATEWNCK_DISABLE_DEPRECATED
int            matewnck_screen_get_workspace_index      (MatewnckScreen    *screen,
                                                     MatewnckWorkspace *space);
MatewnckWorkspace* matewnck_screen_get_workspace_neighbor   (MatewnckScreen         *screen,
                                                     MatewnckWorkspace      *space,
                                                     MatewnckMotionDirection direction);
#endif /* MATEWNCK_DISABLE_DEPRECATED */
MatewnckWorkspace* matewnck_screen_get_active_workspace     (MatewnckScreen *screen);
GList*         matewnck_screen_get_workspaces           (MatewnckScreen *screen);
MatewnckWindow*    matewnck_screen_get_active_window        (MatewnckScreen *screen);
MatewnckWindow*    matewnck_screen_get_previously_active_window (MatewnckScreen *screen);
GList*         matewnck_screen_get_windows              (MatewnckScreen *screen);
GList*         matewnck_screen_get_windows_stacked      (MatewnckScreen *screen);
void           matewnck_screen_force_update             (MatewnckScreen *screen);
int            matewnck_screen_get_workspace_count      (MatewnckScreen *screen);
void           matewnck_screen_change_workspace_count   (MatewnckScreen *screen,
                                                     int         count);
const char*    matewnck_screen_get_window_manager_name  (MatewnckScreen *screen);
gboolean       matewnck_screen_net_wm_supports          (MatewnckScreen *screen,
                                                     const char *atom);
gulong         matewnck_screen_get_background_pixmap    (MatewnckScreen *screen);
int            matewnck_screen_get_width                (MatewnckScreen *screen);
int            matewnck_screen_get_height               (MatewnckScreen *screen);
gboolean       matewnck_screen_get_showing_desktop      (MatewnckScreen *screen);
void           matewnck_screen_toggle_showing_desktop   (MatewnckScreen *screen,
                                                     gboolean    show);
void           matewnck_screen_move_viewport            (MatewnckScreen *screen,
                                                     int         x,
                                                     int         y);
void           _matewnck_screen_get_workspace_layout     (MatewnckScreen             *screen,
                                                      _MatewnckLayoutOrientation *orientation,
                                                      int                    *rows,
                                                      int                    *columns,
                                                      _MatewnckLayoutCorner      *starting_corner);
int            matewnck_screen_try_set_workspace_layout (MatewnckScreen *screen,
                                                     int         current_token,
                                                     int         rows,
                                                     int         columns);
void           matewnck_screen_release_workspace_layout (MatewnckScreen *screen,
                                                     int         current_token);
#ifndef MATEWNCK_DISABLE_DEPRECATED
void           matewnck_screen_calc_workspace_layout    (MatewnckScreen          *screen,
                                                     int                  num_workspaces,
                                                     int                  space_index,
                                                     MatewnckWorkspaceLayout *layout);
void           matewnck_screen_free_workspace_layout (MatewnckWorkspaceLayout *layout);
#endif /* MATEWNCK_DISABLE_DEPRECATED */


G_END_DECLS

#endif /* MATEWNCK_SCREEN_H */
