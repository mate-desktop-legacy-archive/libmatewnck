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
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef MATEWNCK_SCREEN_H
#define MATEWNCK_SCREEN_H

#include <glib-object.h>

G_BEGIN_DECLS

/* forward decls */
typedef struct _MateWnckApplication MateWnckApplication;
typedef struct _MateWnckClassGroup  MateWnckClassGroup;
typedef struct _MateWnckWindow      MateWnckWindow;
typedef struct _MateWnckWorkspace   MateWnckWorkspace;

/* Screen */

#define MATEWNCK_TYPE_SCREEN              (matewnck_screen_get_type ())
#define MATEWNCK_SCREEN(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_SCREEN, MateWnckScreen))
#define MATEWNCK_SCREEN_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_SCREEN, MateWnckScreenClass))
#define MATEWNCK_IS_SCREEN(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_SCREEN))
#define MATEWNCK_IS_SCREEN_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_SCREEN))
#define MATEWNCK_SCREEN_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_SCREEN, MateWnckScreenClass))

typedef struct _MateWnckScreen        MateWnckScreen;
typedef struct _MateWnckScreenClass   MateWnckScreenClass;
typedef struct _MateWnckScreenPrivate MateWnckScreenPrivate;

/**
 * MateWnckScreen:
 *
 * The #MateWnckScreen struct contains only private fields and should not be
 * directly accessed.
 */
struct _MateWnckScreen
{
  GObject parent_instance;

  MateWnckScreenPrivate *priv;
};

struct _MateWnckScreenClass
{
  GObjectClass parent_class;

  /* focused window changed */
  void (* active_window_changed)    (MateWnckScreen *screen,
                                     MateWnckWindow *previous_window);
  /* current workspace changed */
  void (* active_workspace_changed) (MateWnckScreen *screen,
                                     MateWnckWorkspace *previous_workspace);
  /* stacking order changed */
  void (* window_stacking_changed)  (MateWnckScreen *screen);
  /* window added */
  void (* window_opened)            (MateWnckScreen *screen,
                                     MateWnckWindow *window);
  /* window removed */
  void (* window_closed)            (MateWnckScreen *screen,
                                     MateWnckWindow *window);
  /* new workspace */
  void (* workspace_created)        (MateWnckScreen *screen,
                                     MateWnckWorkspace *space);
  /* workspace gone */
  void (* workspace_destroyed)      (MateWnckScreen *screen,
                                     MateWnckWorkspace *space);
  /* new app */
  void (* application_opened)       (MateWnckScreen      *screen,
                                     MateWnckApplication *app);
  /* app gone */
  void (* application_closed)       (MateWnckScreen      *screen,
                                     MateWnckApplication *app);

  /* New background */
  void (* background_changed)       (MateWnckScreen      *screen);

  /* new class group */
  void (* class_group_opened)       (MateWnckScreen     *screen,
                                     MateWnckClassGroup *class_group);
  /* class group gone */
  void (* class_group_closed)       (MateWnckScreen     *screen,
                                     MateWnckClassGroup *class_group);
  /* Toggle showing desktop */
  void (* showing_desktop_changed)  (MateWnckScreen      *screen);

  /* Viewport stuff changed */
  void (* viewports_changed)        (MateWnckScreen      *screen);
  
  /* Window manager changed */
  void (* window_manager_changed)   (MateWnckScreen      *screen);

  /* Padding for future expansion */
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
  void (* pad5) (void);
  void (* pad6) (void);
};

#ifndef MATEWNCK_DISABLE_DEPRECATED
typedef struct _MateWnckWorkspaceLayout MateWnckWorkspaceLayout;

/**
 * MateWnckWorkspaceLayout:
 * @rows: number of rows in the layout grid.
 * @cols: number of columns in the layout grid.
 * @grid: array of size @grid_area containing the index (starting from 0) of
 * the #MateWnckWorkspace for each position in the layout grid, or -1 if the
 * position does not correspond to any #MateWnckWorkspace.
 * @grid_area: size of the grid containing all #MateWnckWorkspace. This can be
 * bigger than the number of #MateWnckWorskpace because the grid might not be
 * filled.
 * @current_row: row of the specific #MateWnckWorkspace, starting from 0.
 * @current_col: column of the specific #MateWnckWorkspace, starting from 0.
 *
 * The #MateWnckWorkspaceLayout struct contains information about the layout of
 * #MateWnckWorkspace on a #MateWnckScreen, and the exact position of a specific
 * #MateWnckWorkspace.
 *
 * Since: 2.12
 * Deprecated:2.20:
 */
struct _MateWnckWorkspaceLayout
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
 * MateWnckMotionDirection:
 * @MATEWNCK_MOTION_UP: search a neighbor #MateWnckWorkspace above another
 * #MateWnckWorkspace. 
 * @MATEWNCK_MOTION_DOWN: search a neighbor #MateWnckWorkspace below another
 * #MateWnckWorkspace.
 * @MATEWNCK_MOTION_LEFT: search a neighbor #MateWnckWorkspace at the left of another
 * #MateWnckWorkspace.
 * @MATEWNCK_MOTION_RIGHT: search a neighbor #MateWnckWorkspace at the right of another
 * #MateWnckWorkspace.
 *
 * Type defining a direction in which to search a neighbor #MateWnckWorkspace.
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
} MateWnckMotionDirection;

/**
 * MateWnckLayoutOrientation:
 * @MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL: the #MateWnckWorkspace are laid out in
 * rows, with the first #MateWnckWorkspace in the defined #MateWnckLayoutCorner.
 * @MATEWNCK_LAYOUT_ORIENTATION_VERTICAL: the #MateWnckWorkspace are laid out in
 * columns, with the first #MateWnckWorkspace in the defined #MateWnckLayoutCorner.
 *
 * Type defining the orientation of the layout of #MateWnckWorkspace. See
 * matewnck_pager_set_orientation() for more information.
 */
typedef enum
{
  MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL,
  MATEWNCK_LAYOUT_ORIENTATION_VERTICAL
} _MateWnckLayoutOrientation;

/**
 * MateWnckLayoutCorner:
 * @MATEWNCK_LAYOUT_CORNER_TOPLEFT: the first #MateWnckWorkspace is in the top left
 * corner of the layout.
 * @MATEWNCK_LAYOUT_CORNER_TOPRIGHT: the first #MateWnckWorkspace is in the top right
 * corner of the layout.
 * @MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT: the first #MateWnckWorkspace is in the bottom
 * right corner of the layout.
 * @MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT: the first #MateWnckWorkspace is in the bottom
 * left corner of the layout.
 *
 * Type defining the starting corner of the layout of #MateWnckWorkspace, i.e. the
 * corner containing the first #MateWnckWorkspace.
 */
typedef enum
{
  MATEWNCK_LAYOUT_CORNER_TOPLEFT,
  MATEWNCK_LAYOUT_CORNER_TOPRIGHT,
  MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT,
  MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT
} _MateWnckLayoutCorner;

GType matewnck_screen_get_type (void) G_GNUC_CONST;

MateWnckScreen*    matewnck_screen_get_default              (void);
MateWnckScreen*    matewnck_screen_get                      (int         index);
MateWnckScreen*    matewnck_screen_get_for_root             (gulong      root_window_id);
int            matewnck_screen_get_number               (MateWnckScreen *screen);
MateWnckWorkspace* matewnck_screen_get_workspace            (MateWnckScreen *screen,
                                                     int         workspace);
#ifndef MATEWNCK_DISABLE_DEPRECATED
int            matewnck_screen_get_workspace_index      (MateWnckScreen    *screen,
                                                     MateWnckWorkspace *space);
MateWnckWorkspace* matewnck_screen_get_workspace_neighbor   (MateWnckScreen         *screen,
                                                     MateWnckWorkspace      *space,
                                                     MateWnckMotionDirection direction);
#endif /* MATEWNCK_DISABLE_DEPRECATED */
MateWnckWorkspace* matewnck_screen_get_active_workspace     (MateWnckScreen *screen);
GList*         matewnck_screen_get_workspaces           (MateWnckScreen *screen);
MateWnckWindow*    matewnck_screen_get_active_window        (MateWnckScreen *screen);
MateWnckWindow*    matewnck_screen_get_previously_active_window (MateWnckScreen *screen);
GList*         matewnck_screen_get_windows              (MateWnckScreen *screen);
GList*         matewnck_screen_get_windows_stacked      (MateWnckScreen *screen);
void           matewnck_screen_force_update             (MateWnckScreen *screen);
int            matewnck_screen_get_workspace_count      (MateWnckScreen *screen);
void           matewnck_screen_change_workspace_count   (MateWnckScreen *screen,
                                                     int         count);
const char*    matewnck_screen_get_window_manager_name  (MateWnckScreen *screen);
gboolean       matewnck_screen_net_wm_supports          (MateWnckScreen *screen,
                                                     const char *atom);
gulong         matewnck_screen_get_background_pixmap    (MateWnckScreen *screen);
int            matewnck_screen_get_width                (MateWnckScreen *screen);
int            matewnck_screen_get_height               (MateWnckScreen *screen);
gboolean       matewnck_screen_get_showing_desktop      (MateWnckScreen *screen);
void           matewnck_screen_toggle_showing_desktop   (MateWnckScreen *screen,
                                                     gboolean    show);
void           matewnck_screen_move_viewport            (MateWnckScreen *screen,
                                                     int         x,
                                                     int         y);
void           _matewnck_screen_get_workspace_layout     (MateWnckScreen             *screen,
                                                      _MateWnckLayoutOrientation *orientation,
                                                      int                    *rows,
                                                      int                    *columns,
                                                      _MateWnckLayoutCorner      *starting_corner);
int            matewnck_screen_try_set_workspace_layout (MateWnckScreen *screen,
                                                     int         current_token,
                                                     int         rows,
                                                     int         columns);
void           matewnck_screen_release_workspace_layout (MateWnckScreen *screen,
                                                     int         current_token);
#ifndef MATEWNCK_DISABLE_DEPRECATED
void           matewnck_screen_calc_workspace_layout    (MateWnckScreen          *screen,
                                                     int                  num_workspaces,
                                                     int                  space_index,
                                                     MateWnckWorkspaceLayout *layout);
void           matewnck_screen_free_workspace_layout (MateWnckWorkspaceLayout *layout);
#endif /* MATEWNCK_DISABLE_DEPRECATED */


G_END_DECLS

#endif /* MATEWNCK_SCREEN_H */
