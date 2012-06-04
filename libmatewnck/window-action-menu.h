/* window action menu (ops on a single window) */
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

#ifndef MATEWNCK_WINDOW_ACTION_MENU_H
#define MATEWNCK_WINDOW_ACTION_MENU_H

#include <libmatewnck/window.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_ACTION_MENU              (matewnck_action_menu_get_type ())
#define MATEWNCK_ACTION_MENU(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_ACTION_MENU, MatewnckActionMenu))
#define MATEWNCK_ACTION_MENU_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_ACTION_MENU, MatewnckActionMenuClass))
#define MATEWNCK_IS_ACTION_MENU(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_ACTION_MENU))
#define MATEWNCK_IS_ACTION_MENU_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_ACTION_MENU))
#define MATEWNCK_ACTION_MENU_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_ACTION_MENU, MatewnckActionMenuClass))

typedef struct _MatewnckActionMenu        MatewnckActionMenu;
typedef struct _MatewnckActionMenuClass   MatewnckActionMenuClass;
typedef struct _MatewnckActionMenuPrivate MatewnckActionMenuPrivate;

/**
 * MatewnckActionMenu:
 *
 * The #MatewnckActionMenu struct contains only private fields and should not be
 * directly accessed.
 */
struct _MatewnckActionMenu
{
  GtkMenu parent_instance;

  MatewnckActionMenuPrivate *priv;
};

struct _MatewnckActionMenuClass
{
  GtkMenuClass parent_class;

  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

GType matewnck_action_menu_get_type (void) G_GNUC_CONST;

GtkWidget* matewnck_action_menu_new (MatewnckWindow *window);

#ifndef MATEWNCK_DISABLE_DEPRECATED
GtkWidget* matewnck_create_window_action_menu (MatewnckWindow *window);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* MATEWNCK_WINDOW_MENU_H */
