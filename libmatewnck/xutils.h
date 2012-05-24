/* Xlib utilities */
/* vim: set sw=2 et: */

/*
 * Copyright (C) 2001 Havoc Pennington
 * Copyright (C) 2005-2007 Vincent Untz
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

#ifndef MATEWNCK_XUTILS_H
#define MATEWNCK_XUTILS_H

#include <glib.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <gdk/gdk.h>
#include <gdk/gdkx.h>

G_BEGIN_DECLS

#define MATEWNCK_STOCK_DELETE "matewnck-stock-delete"
#define MATEWNCK_STOCK_MAXIMIZE "matewnck-stock-maximize"
#define MATEWNCK_STOCK_MINIMIZE "matewnck-stock-minimize"

#define MATEWNCK_APP_WINDOW_EVENT_MASK (PropertyChangeMask | StructureNotifyMask)

gboolean _matewnck_get_cardinal      (Window  xwindow,
                                  Atom    atom,
                                  int    *val);
int      _matewnck_get_wm_state      (Window  xwindow);
gboolean _matewnck_get_window        (Window  xwindow,
                                  Atom    atom,
                                  Window *val);
gboolean _matewnck_get_pixmap        (Window  xwindow,
                                  Atom    atom,
                                  Pixmap *val);
gboolean _matewnck_get_atom          (Window  xwindow,
                                  Atom    atom,
                                  Atom   *val);
char*    _matewnck_get_text_property (Window  xwindow,
                                  Atom    atom);
char*    _matewnck_get_utf8_property (Window  xwindow,
                                  Atom    atom);
gboolean _matewnck_get_window_list   (Window   xwindow,
                                  Atom     atom,
                                  Window **windows,
                                  int     *len);
gboolean _matewnck_get_atom_list     (Window   xwindow,
                                  Atom     atom,
                                  Atom   **atoms,
                                  int     *len);
gboolean _matewnck_get_cardinal_list (Window   xwindow,
                                  Atom     atom,
                                  gulong **cardinals,
                                  int     *len);
char**   _matewnck_get_utf8_list     (Window   xwindow,
                                  Atom     atom);

void     _matewnck_set_utf8_list     (Window   xwindow,
                                  Atom     atom,
                                  char   **list);

void _matewnck_error_trap_push (void);
int  _matewnck_error_trap_pop  (void);

#define _matewnck_atom_get(atom_name) gdk_x11_get_xatom_by_name (atom_name)
#define _matewnck_atom_name(atom)     gdk_x11_get_xatom_name (atom)

void _matewnck_event_filter_init (void);

int   _matewnck_xid_equal (gconstpointer v1,
                       gconstpointer v2);
guint _matewnck_xid_hash  (gconstpointer v);

void _matewnck_iconify   (Window xwindow);
void _matewnck_deiconify (Window xwindow);

void _matewnck_close     (Screen *screen,
		      Window  xwindow,
		      Time    timestamp);

void _matewnck_change_state     (Screen  *screen,
			     Window   xwindow,
                             gboolean add,
                             Atom     state1,
                             Atom     state2);
void _matewnck_change_workspace (Screen  *screen,
			     Window   xwindow,
                             int      new_space);
void _matewnck_activate         (Screen  *screen,
                             Window   xwindow,
                             Time     timestamp);
void _matewnck_activate_workspace (Screen *screen,
                               int     new_active_space,
                               Time    timestamp);
void _matewnck_change_viewport (Screen *screen,
			    int     x,
			    int     y);

char*  _matewnck_get_session_id     (Window xwindow);
int    _matewnck_get_pid            (Window xwindow);
char*  _matewnck_get_name           (Window xwindow);
char*  _matewnck_get_icon_name      (Window xwindow);
char*  _matewnck_get_res_class_utf8 (Window xwindow);
void   _matewnck_get_wmclass        (Window xwindow,
                                 char **res_class,
                                 char **res_name);
gboolean _matewnck_get_frame_extents  (Window  xwindow,
                                   int    *left_frame,
                                   int    *right_frame,
                                   int    *top_frame,
                                   int    *bottom_frame);

void   _matewnck_select_input     (Window xwindow,
                               int    mask);

void   _matewnck_keyboard_move    (Screen *screen,
                               Window  xwindow);

void   _matewnck_keyboard_size    (Screen *screen,
                               Window  xwindow);

void _matewnck_toggle_showing_desktop (Screen  *screen,
                                   gboolean show);

typedef struct _MateWnckIconCache MateWnckIconCache;

MateWnckIconCache *_matewnck_icon_cache_new                  (void);
void           _matewnck_icon_cache_free                 (MateWnckIconCache *icon_cache);
void           _matewnck_icon_cache_property_changed     (MateWnckIconCache *icon_cache,
                                                      Atom           atom);
gboolean       _matewnck_icon_cache_get_icon_invalidated (MateWnckIconCache *icon_cache);
void           _matewnck_icon_cache_set_want_fallback    (MateWnckIconCache *icon_cache,
                                                      gboolean       setting);
gboolean       _matewnck_icon_cache_get_is_fallback      (MateWnckIconCache *icon_cache);

gboolean _matewnck_read_icons         (Window          xwindow,
                                   MateWnckIconCache  *icon_cache,
                                   GdkPixbuf     **iconp,
                                   int             ideal_width,
                                   int             ideal_height,
                                   GdkPixbuf     **mini_iconp,
                                   int             ideal_mini_width,
                                   int             ideal_mini_height);
void _matewnck_get_fallback_icons (GdkPixbuf     **iconp,
                               int             ideal_width,
                               int             ideal_height,
                               GdkPixbuf     **mini_iconp,
                               int             ideal_mini_width,
                               int             ideal_mini_height);



void _matewnck_get_window_geometry (Screen *screen,
				Window  xwindow,
                                int    *xp,
                                int    *yp,
                                int    *widthp,
                                int    *heightp);
void _matewnck_set_window_geometry (Screen *screen,
                                Window  xwindow,
                                int     gravity_and_flags,
                                int     x,
                                int     y,
                                int     width,
                                int     height);

void _matewnck_get_window_position (Screen *screen,
				Window  xwindow,
                                int    *xp,
                                int    *yp);

void _matewnck_set_icon_geometry  (Window xwindow,
			       int    x,
			       int    y,
			       int    width,
			       int    height);

void _matewnck_set_desktop_layout (Screen *xscreen,
                               int     rows,
                               int     columns);

GdkPixbuf* _matewnck_gdk_pixbuf_get_from_pixmap (GdkPixbuf   *dest,
                                             Pixmap       xpixmap,
                                             int          src_x,
                                             int          src_y,
                                             int          dest_x,
                                             int          dest_y,
                                             int          width,
                                             int          height);

#define MATEWNCK_NO_MANAGER_TOKEN 0

int      _matewnck_try_desktop_layout_manager           (Screen *xscreen,
                                                     int     current_token);
void     _matewnck_release_desktop_layout_manager       (Screen *xscreen,
                                                     int     current_token);
gboolean _matewnck_desktop_layout_manager_process_event (XEvent *xev);

G_END_DECLS

#endif /* MATEWNCK_XUTILS_H */
