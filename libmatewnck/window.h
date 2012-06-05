/* window object */
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

#ifndef MATEWNCK_WINDOW_H
#define MATEWNCK_WINDOW_H

#include <glib-object.h>
#include <libmatewnck/screen.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

G_BEGIN_DECLS

/**
 * MatewnckWindowState:
 * @MATEWNCK_WINDOW_STATE_MINIMIZED: the window is minimized.
 * @MATEWNCK_WINDOW_STATE_MAXIMIZED_HORIZONTALLY: the window is horizontically
 * maximized.
 * @MATEWNCK_WINDOW_STATE_MAXIMIZED_VERTICALLY: the window is vertically maximized.
 * @MATEWNCK_WINDOW_STATE_SHADED: the window is shaded.
 * @MATEWNCK_WINDOW_STATE_SKIP_PAGER: the window should not be included on pagers.
 * @MATEWNCK_WINDOW_STATE_SKIP_TASKLIST: the window should not be included on
 * tasklists.
 * @MATEWNCK_WINDOW_STATE_STICKY: the window is sticky (see
 * matewnck_window_is_sticky()).
 * @MATEWNCK_WINDOW_STATE_HIDDEN: the window is not visible on its #MatewnckWorkspace
 * and viewport (when minimized, for example).
 * @MATEWNCK_WINDOW_STATE_FULLSCREEN: the window is fullscreen.
 * @MATEWNCK_WINDOW_STATE_DEMANDS_ATTENTION: the window needs attention (because
 * the window requested activation but the window manager refused it, for
 * example).
 * @MATEWNCK_WINDOW_STATE_URGENT: the window requires a response from the user.
 * @MATEWNCK_WINDOW_STATE_ABOVE: the window is above other windows (see
 * matewnck_window_make_above()).
 * @MATEWNCK_WINDOW_STATE_BELOW: the window is below other windows (see
 * matewnck_window_make_below()).
 *
 * Type used as a bitmask to describe the state of a #MatewnckWindow.
 */
typedef enum
{
  MATEWNCK_WINDOW_STATE_MINIMIZED              = 1 << 0,
  MATEWNCK_WINDOW_STATE_MAXIMIZED_HORIZONTALLY = 1 << 1,
  MATEWNCK_WINDOW_STATE_MAXIMIZED_VERTICALLY   = 1 << 2,
  MATEWNCK_WINDOW_STATE_SHADED                 = 1 << 3,
  MATEWNCK_WINDOW_STATE_SKIP_PAGER             = 1 << 4,
  MATEWNCK_WINDOW_STATE_SKIP_TASKLIST          = 1 << 5,
  MATEWNCK_WINDOW_STATE_STICKY                 = 1 << 6,
  MATEWNCK_WINDOW_STATE_HIDDEN                 = 1 << 7,
  MATEWNCK_WINDOW_STATE_FULLSCREEN             = 1 << 8,
  MATEWNCK_WINDOW_STATE_DEMANDS_ATTENTION      = 1 << 9,
  MATEWNCK_WINDOW_STATE_URGENT                 = 1 << 10,
  MATEWNCK_WINDOW_STATE_ABOVE                  = 1 << 11,
  MATEWNCK_WINDOW_STATE_BELOW                  = 1 << 12
} MatewnckWindowState;

/**
 * MatewnckWindowActions:
 * @MATEWNCK_WINDOW_ACTION_MOVE: the window may be moved around the screen. 
 * @MATEWNCK_WINDOW_ACTION_RESIZE: the window may be resized.
 * @MATEWNCK_WINDOW_ACTION_SHADE: the window may be shaded.
 * @MATEWNCK_WINDOW_ACTION_STICK: the window may be sticked.
 * @MATEWNCK_WINDOW_ACTION_MAXIMIZE_HORIZONTALLY: the window may be maximized
 * horizontally.
 * @MATEWNCK_WINDOW_ACTION_MAXIMIZE_VERTICALLY: the window may be maximized
 * vertically.
 * @MATEWNCK_WINDOW_ACTION_CHANGE_WORKSPACE: the window may be moved between
 * workspaces, or (un)pinned.
 * @MATEWNCK_WINDOW_ACTION_CLOSE: the window may be closed.
 * @MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_HORIZONTALLY: the window may be unmaximized
 * horizontally.
 * @MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_VERTICALLY: the window may be maximized
 * vertically.
 * @MATEWNCK_WINDOW_ACTION_UNSHADE: the window may be unshaded.
 * @MATEWNCK_WINDOW_ACTION_UNSTICK: the window may be unsticked.
 * @MATEWNCK_WINDOW_ACTION_MINIMIZE: the window may be minimized.
 * @MATEWNCK_WINDOW_ACTION_UNMINIMIZE: the window may be unminimized.
 * @MATEWNCK_WINDOW_ACTION_MAXIMIZE: the window may be maximized.
 * @MATEWNCK_WINDOW_ACTION_UNMAXIMIZE: the window may be unmaximized.
 * @MATEWNCK_WINDOW_ACTION_FULLSCREEN: the window may be brought to fullscreen.
 * @MATEWNCK_WINDOW_ACTION_ABOVE: the window may be made above other windows.
 * @MATEWNCK_WINDOW_ACTION_BELOW: the window may be made below other windows.
 *
 * Type used as a bitmask to describe the actions that can be done for a
 * #MatewnckWindow.
 */
typedef enum
{
  MATEWNCK_WINDOW_ACTION_MOVE                    = 1 << 0,
  MATEWNCK_WINDOW_ACTION_RESIZE                  = 1 << 1,
  MATEWNCK_WINDOW_ACTION_SHADE                   = 1 << 2,
  MATEWNCK_WINDOW_ACTION_STICK                   = 1 << 3,
  MATEWNCK_WINDOW_ACTION_MAXIMIZE_HORIZONTALLY   = 1 << 4,
  MATEWNCK_WINDOW_ACTION_MAXIMIZE_VERTICALLY     = 1 << 5,
  MATEWNCK_WINDOW_ACTION_CHANGE_WORKSPACE        = 1 << 6, /* includes pin/unpin */
  MATEWNCK_WINDOW_ACTION_CLOSE                   = 1 << 7,
  MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_HORIZONTALLY = 1 << 8,
  MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_VERTICALLY   = 1 << 9,
  MATEWNCK_WINDOW_ACTION_UNSHADE                 = 1 << 10,
  MATEWNCK_WINDOW_ACTION_UNSTICK                 = 1 << 11,
  MATEWNCK_WINDOW_ACTION_MINIMIZE                = 1 << 12,
  MATEWNCK_WINDOW_ACTION_UNMINIMIZE              = 1 << 13,
  MATEWNCK_WINDOW_ACTION_MAXIMIZE                = 1 << 14,
  MATEWNCK_WINDOW_ACTION_UNMAXIMIZE              = 1 << 15,
  MATEWNCK_WINDOW_ACTION_FULLSCREEN              = 1 << 16,
  MATEWNCK_WINDOW_ACTION_ABOVE                   = 1 << 17,
  MATEWNCK_WINDOW_ACTION_BELOW                   = 1 << 18
} MatewnckWindowActions;

/**
 * MatewnckWindowType:
 * @MATEWNCK_WINDOW_NORMAL: the window is a normal window.
 * @MATEWNCK_WINDOW_DESKTOP: the window is a desktop.
 * @MATEWNCK_WINDOW_DOCK: the window is a dock or a panel.
 * @MATEWNCK_WINDOW_DIALOG: the window is a dialog window.
 * @MATEWNCK_WINDOW_TOOLBAR: the window is a tearoff toolbar.
 * @MATEWNCK_WINDOW_MENU: the window is a tearoff menu.
 * @MATEWNCK_WINDOW_UTILITY: the window is a small persistent utility window, such
 * as a palette or toolbox.
 * @MATEWNCK_WINDOW_SPLASHSCREEN: the window is a splash screen displayed as an
 * application is starting up.
 *
 * Type describing the semantic type of a #MatewnckWindow.
 */
typedef enum
{
  MATEWNCK_WINDOW_NORMAL,       /* document/app window */
  MATEWNCK_WINDOW_DESKTOP,      /* desktop background */
  MATEWNCK_WINDOW_DOCK,         /* panel */
  MATEWNCK_WINDOW_DIALOG,       /* dialog */
  MATEWNCK_WINDOW_TOOLBAR,      /* tearoff toolbar */
  MATEWNCK_WINDOW_MENU,         /* tearoff menu */
  MATEWNCK_WINDOW_UTILITY,      /* palette/toolbox window */
  MATEWNCK_WINDOW_SPLASHSCREEN  /* splash screen */
} MatewnckWindowType;

/**
 * MatewnckWindowGravity:
 * @MATEWNCK_WINDOW_GRAVITY_CURRENT: keep the current gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_NORTHWEST: use the left top corner of the frame window
 * as gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_NORTH: use the center of the frame window's top side as
 * gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_NORTHEAST: use the right top corner of the frame window
 * as gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_WEST: use the center of the frame window's left side as
 * gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_CENTER: use the center of the frame window as gravity
 * point.
 * @MATEWNCK_WINDOW_GRAVITY_EAST: use the center of the frame window's right side
 * as gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_SOUTHWEST: use the left bottom corner of the frame
 * window as gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_SOUTH: use the center of the frame window's bottom side
 * as gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_SOUTHEAST: use the right bottom corner of the frame
 * window as gravity point.
 * @MATEWNCK_WINDOW_GRAVITY_STATIC: use the left top corner of the client window as
 * gravity point.
 *
 * Flag used when changing the geometry of a #MatewnckWindow. This is the gravity
 * point to use as a reference for the new position.
 *
 * Since: 2.16
 */
typedef enum
{
  MATEWNCK_WINDOW_GRAVITY_CURRENT   = 0,
  MATEWNCK_WINDOW_GRAVITY_NORTHWEST = 1,
  MATEWNCK_WINDOW_GRAVITY_NORTH     = 2,
  MATEWNCK_WINDOW_GRAVITY_NORTHEAST = 3,
  MATEWNCK_WINDOW_GRAVITY_WEST      = 4,
  MATEWNCK_WINDOW_GRAVITY_CENTER    = 5,
  MATEWNCK_WINDOW_GRAVITY_EAST      = 6,
  MATEWNCK_WINDOW_GRAVITY_SOUTHWEST = 7,
  MATEWNCK_WINDOW_GRAVITY_SOUTH     = 8,
  MATEWNCK_WINDOW_GRAVITY_SOUTHEAST = 9,
  MATEWNCK_WINDOW_GRAVITY_STATIC    = 10
} MatewnckWindowGravity;

/**
 * MatewnckWindowMoveResizeMask:
 * @MATEWNCK_WINDOW_CHANGE_X: X coordinate of the window should be changed.
 * @MATEWNCK_WINDOW_CHANGE_Y: Y coordinate of the window should be changed.
 * @MATEWNCK_WINDOW_CHANGE_WIDTH: width of the window should be changed.
 * @MATEWNCK_WINDOW_CHANGE_HEIGHT: height of the window should be changed.
 *
 * Flag used as a bitmask when changing the geometry of a #MatewnckWindow. This
 * indicates which part of the geometry should be changed.
 *
 * Since: 2.16
 */
typedef enum
{
  MATEWNCK_WINDOW_CHANGE_X      = 1 << 0,
  MATEWNCK_WINDOW_CHANGE_Y      = 1 << 1,
  MATEWNCK_WINDOW_CHANGE_WIDTH  = 1 << 2,
  MATEWNCK_WINDOW_CHANGE_HEIGHT = 1 << 3
} MatewnckWindowMoveResizeMask;

#define MATEWNCK_TYPE_WINDOW              (matewnck_window_get_type ())
#define MATEWNCK_WINDOW(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_WINDOW, MatewnckWindow))
#define MATEWNCK_WINDOW_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_WINDOW, MatewnckWindowClass))
#define MATEWNCK_IS_WINDOW(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_WINDOW))
#define MATEWNCK_IS_WINDOW_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_WINDOW))
#define MATEWNCK_WINDOW_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_WINDOW, MatewnckWindowClass))

typedef struct _MatewnckWindowClass   MatewnckWindowClass;
typedef struct _MatewnckWindowPrivate MatewnckWindowPrivate;

/**
 * MatewnckWindow:
 *
 * The #MatewnckWindow struct contains only private fields and should not be
 * directly accessed.
 */
struct _MatewnckWindow
{
  GObject parent_instance;

  MatewnckWindowPrivate *priv;
};

struct _MatewnckWindowClass
{
  GObjectClass parent_class;

  /* window name or icon name changed */
  void (* name_changed) (MatewnckWindow *window);

  /* minimized, maximized, sticky, skip pager, skip task, shaded
   * may have changed
   */
  void (* state_changed) (MatewnckWindow     *window,
                          MatewnckWindowState changed_mask,
                          MatewnckWindowState new_state);

  /* Changed workspace or pinned/unpinned state */
  void (* workspace_changed) (MatewnckWindow *window);

  /* Changed icon */
  void (* icon_changed)      (MatewnckWindow *window);

  /* Changed actions */
  void (* actions_changed)   (MatewnckWindow       *window,
                              MatewnckWindowActions changed_mask,
                              MatewnckWindowActions new_actions);

  /* Changed size/position */
  void (* geometry_changed)      (MatewnckWindow       *window);
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

GType matewnck_window_get_type (void) G_GNUC_CONST;

MatewnckWindow* matewnck_window_get (gulong xwindow);

MatewnckScreen* matewnck_window_get_screen    (MatewnckWindow *window);

gboolean    matewnck_window_has_name      (MatewnckWindow *window);
const char* matewnck_window_get_name      (MatewnckWindow *window);
gboolean    matewnck_window_has_icon_name (MatewnckWindow *window);
const char* matewnck_window_get_icon_name (MatewnckWindow *window);

MatewnckApplication* matewnck_window_get_application  (MatewnckWindow *window);
MatewnckWindow*      matewnck_window_get_transient    (MatewnckWindow *window);
gulong           matewnck_window_get_group_leader (MatewnckWindow *window);
gulong           matewnck_window_get_xid          (MatewnckWindow *window);

MatewnckClassGroup *matewnck_window_get_class_group (MatewnckWindow *window);

const char* matewnck_window_get_session_id        (MatewnckWindow *window);
const char* matewnck_window_get_session_id_utf8   (MatewnckWindow *window);
int         matewnck_window_get_pid               (MatewnckWindow *window);
gint        matewnck_window_get_sort_order        (MatewnckWindow *window);
void        matewnck_window_set_sort_order        (MatewnckWindow *window, 
						gint order);

MatewnckWindowType matewnck_window_get_window_type    (MatewnckWindow *window);
void           matewnck_window_set_window_type    (MatewnckWindow *window,
                                               MatewnckWindowType wintype);

gboolean matewnck_window_is_minimized              (MatewnckWindow *window);
gboolean matewnck_window_is_maximized_horizontally (MatewnckWindow *window);
gboolean matewnck_window_is_maximized_vertically   (MatewnckWindow *window);
gboolean matewnck_window_is_maximized              (MatewnckWindow *window);
gboolean matewnck_window_is_shaded                 (MatewnckWindow *window);
gboolean matewnck_window_is_above                  (MatewnckWindow *window);
gboolean matewnck_window_is_below                  (MatewnckWindow *window);
gboolean matewnck_window_is_skip_pager             (MatewnckWindow *window);
gboolean matewnck_window_is_skip_tasklist          (MatewnckWindow *window);
gboolean matewnck_window_is_fullscreen             (MatewnckWindow *window);
gboolean matewnck_window_is_sticky                 (MatewnckWindow *window);
gboolean matewnck_window_needs_attention           (MatewnckWindow *window);
gboolean matewnck_window_or_transient_needs_attention (MatewnckWindow *window);

void matewnck_window_set_skip_pager    (MatewnckWindow *window,
                                    gboolean skip);
void matewnck_window_set_skip_tasklist (MatewnckWindow *window,
                                    gboolean skip);
void matewnck_window_set_fullscreen (MatewnckWindow *window,
                                 gboolean fullscreen);

void matewnck_window_close                   (MatewnckWindow *window,
                                          guint32     timestamp);
void matewnck_window_minimize                (MatewnckWindow *window);
void matewnck_window_unminimize              (MatewnckWindow *window,
                                          guint32     timestamp);
void matewnck_window_maximize                (MatewnckWindow *window);
void matewnck_window_unmaximize              (MatewnckWindow *window);
void matewnck_window_maximize_horizontally   (MatewnckWindow *window);
void matewnck_window_unmaximize_horizontally (MatewnckWindow *window);
void matewnck_window_maximize_vertically     (MatewnckWindow *window);
void matewnck_window_unmaximize_vertically   (MatewnckWindow *window);
void matewnck_window_shade                   (MatewnckWindow *window);
void matewnck_window_unshade                 (MatewnckWindow *window);
void matewnck_window_make_above              (MatewnckWindow *window);
void matewnck_window_unmake_above            (MatewnckWindow *window);
void matewnck_window_make_below              (MatewnckWindow *window);
void matewnck_window_unmake_below            (MatewnckWindow *window);
void matewnck_window_stick                   (MatewnckWindow *window);
void matewnck_window_unstick                 (MatewnckWindow *window);
void matewnck_window_keyboard_move           (MatewnckWindow *window);
void matewnck_window_keyboard_size           (MatewnckWindow *window);

MatewnckWorkspace* matewnck_window_get_workspace     (MatewnckWindow    *window);
void           matewnck_window_move_to_workspace (MatewnckWindow    *window,
                                              MatewnckWorkspace *space);

/* pinned = on all workspaces */
gboolean matewnck_window_is_pinned (MatewnckWindow *window);
void     matewnck_window_pin       (MatewnckWindow *window);
void     matewnck_window_unpin     (MatewnckWindow *window);

void     matewnck_window_activate  (MatewnckWindow *window,
                                guint32     timestamp);
gboolean matewnck_window_is_active (MatewnckWindow *window);
gboolean matewnck_window_is_most_recently_activated (MatewnckWindow *window);
void     matewnck_window_activate_transient (MatewnckWindow *window,
                                         guint32     timestamp);
gboolean matewnck_window_transient_is_most_recently_activated (MatewnckWindow *window);

GdkPixbuf* matewnck_window_get_icon      (MatewnckWindow *window);
GdkPixbuf* matewnck_window_get_mini_icon (MatewnckWindow *window);

gboolean matewnck_window_get_icon_is_fallback (MatewnckWindow *window);

void matewnck_window_set_icon_geometry        (MatewnckWindow *window,
					   int         x,
					   int         y,
					   int         width,
					   int         height);

MatewnckWindowActions matewnck_window_get_actions (MatewnckWindow *window);
MatewnckWindowState   matewnck_window_get_state   (MatewnckWindow *window);

void matewnck_window_get_client_window_geometry (MatewnckWindow *window,
                                             int        *xp,
                                             int        *yp,
                                             int        *widthp,
                                             int        *heightp);
void matewnck_window_get_geometry (MatewnckWindow *window,
                               int        *xp,
                               int        *yp,
                               int        *widthp,
                               int        *heightp);
void matewnck_window_set_geometry (MatewnckWindow               *window,
                               MatewnckWindowGravity         gravity,
                               MatewnckWindowMoveResizeMask  geometry_mask,
                               int                       x,
                               int                       y,
                               int                       width,
                               int                       height);

gboolean matewnck_window_is_visible_on_workspace (MatewnckWindow    *window,
                                              MatewnckWorkspace *workspace);
gboolean matewnck_window_is_on_workspace         (MatewnckWindow    *window,
                                              MatewnckWorkspace *workspace);
gboolean matewnck_window_is_in_viewport          (MatewnckWindow    *window,
                                              MatewnckWorkspace *workspace);

G_END_DECLS

#endif /* MATEWNCK_WINDOW_H */
