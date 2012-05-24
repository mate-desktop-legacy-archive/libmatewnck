/* Private stuff */
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

#ifndef MATEWNCK_PRIVATE_H
#define MATEWNCK_PRIVATE_H

#include <config.h>
#include "screen.h"
#include "window.h"
#include "workspace.h"
#include "application.h"
#include "xutils.h"
#include "pager.h"
#include "util.h"
#ifdef HAVE_STARTUP_NOTIFICATION
#include <libsn/sn.h>
#endif

G_BEGIN_DECLS

#define MATEWNCK_ACTIVATE_TIMEOUT 1000

MateWnckClientType _matewnck_get_client_type (void);

void _matewnck_application_process_property_notify (MateWnckApplication *app,
                                                XEvent          *xevent);
void _matewnck_window_process_property_notify (MateWnckWindow *window,
                                           XEvent     *xevent);

void _matewnck_screen_process_property_notify (MateWnckScreen *screen,
                                           XEvent     *xevent);
void _matewnck_window_process_configure_notify (MateWnckWindow *window,
                                            XEvent     *xevent);
MateWnckWindow* _matewnck_window_create  (Window      xwindow,
                                  MateWnckScreen *screen,
                                  gint        sort_order);
void        _matewnck_window_destroy (MateWnckWindow *window);

char*       _matewnck_window_get_name_for_display (MateWnckWindow *window,
                                               gboolean    use_icon_name,
                                               gboolean    use_state_decorations);
const char* _matewnck_window_get_startup_id (MateWnckWindow *window);

const char* _matewnck_window_get_resource_class (MateWnckWindow *window);
const char* _matewnck_window_get_resource_name  (MateWnckWindow *window);

time_t      _matewnck_window_get_needs_attention_time (MateWnckWindow *window);
time_t      _matewnck_window_or_transient_get_needs_attention_time (MateWnckWindow *window);

MateWnckWorkspace* _matewnck_workspace_create  (int            number,
					MateWnckScreen    *screen);
void           _matewnck_workspace_destroy (MateWnckWorkspace *space);

void _matewnck_window_set_application    (MateWnckWindow      *window,
                                      MateWnckApplication *app);

void _matewnck_window_set_class_group (MateWnckWindow     *window,
				   MateWnckClassGroup *class_group);

/* this one is in pager.c since it needs code from there to draw the icon */
void 
_matewnck_window_set_as_drag_icon (MateWnckWindow     *window,
                               GdkDragContext *context,
                               GtkWidget      *drag_source);

void _matewnck_application_add_window    (MateWnckApplication *app,
                                      MateWnckWindow      *window);
void _matewnck_application_remove_window (MateWnckApplication *app,
                                      MateWnckWindow      *window);

MateWnckApplication* _matewnck_application_create  (Window           xwindow,
                                            MateWnckScreen      *screen);
void             _matewnck_application_destroy (MateWnckApplication *app);


MateWnckClassGroup*  _matewnck_class_group_create        (const char     *res_class);
void             _matewnck_class_group_destroy       (MateWnckClassGroup *class_group);
void             _matewnck_class_group_add_window    (MateWnckClassGroup *class_group,
                                                  MateWnckWindow     *window);
void             _matewnck_class_group_remove_window (MateWnckClassGroup *class_group,
                                                  MateWnckWindow     *window);

void _matewnck_workspace_update_name (MateWnckWorkspace *workspace,
                                  const char    *name);
void _matewnck_screen_change_workspace_name (MateWnckScreen *screen,
                                         int         number,
                                         const char *name);

gboolean _matewnck_workspace_set_geometry (MateWnckWorkspace *space, int w, int h);
gboolean _matewnck_workspace_set_viewport (MateWnckWorkspace *space, int x, int y);

void _matewnck_init (void);
Display *_matewnck_get_default_display (void);

#define DEFAULT_ICON_WIDTH 32
#define DEFAULT_ICON_HEIGHT 32
#define DEFAULT_MINI_ICON_WIDTH 16
#define DEFAULT_MINI_ICON_HEIGHT 16

#define MATEWNCK_SCREEN_XSCREEN(screen) (_matewnck_screen_get_xscreen (screen))

Screen    *_matewnck_screen_get_xscreen    (MateWnckScreen *screen);
GdkScreen *_matewnck_screen_get_gdk_screen (MateWnckScreen *screen);

#ifdef HAVE_STARTUP_NOTIFICATION
SnDisplay* _matewnck_screen_get_sn_display (MateWnckScreen *screen);
#endif

MateWnckScreen* _matewnck_screen_get_existing (int number);

void           _matewnck_pager_activate_workspace   (MateWnckWorkspace *wspace,
                                                 guint32        timestamp);
int            _matewnck_pager_get_n_workspaces     (MateWnckPager     *pager);
const char*    _matewnck_pager_get_workspace_name   (MateWnckPager     *pager,
                                                 int            i);
MateWnckWorkspace* _matewnck_pager_get_active_workspace (MateWnckPager     *pager);
MateWnckWorkspace* _matewnck_pager_get_workspace        (MateWnckPager     *pager,
                                                 int            i);
void           _matewnck_pager_get_workspace_rect   (MateWnckPager     *pager,
                                                 int            i,
                                                 GdkRectangle  *rect);

void           _make_gtk_label_bold   (GtkLabel *label);
void           _make_gtk_label_normal (GtkLabel *label);

void           _matewnck_stock_icons_init (void);


G_END_DECLS

#endif /* MATEWNCK_PRIVATE_H */
