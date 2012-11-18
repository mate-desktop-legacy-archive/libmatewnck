/* application object */
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
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef MATEWNCK_APPLICATION_H
#define MATEWNCK_APPLICATION_H

#include <glib-object.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_APPLICATION              (matewnck_application_get_type ())
#define MATEWNCK_APPLICATION(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_APPLICATION, MatewnckApplication))
#define MATEWNCK_APPLICATION_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_APPLICATION, MatewnckApplicationClass))
#define MATEWNCK_IS_APPLICATION(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_APPLICATION))
#define MATEWNCK_IS_APPLICATION_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_APPLICATION))
#define MATEWNCK_APPLICATION_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_APPLICATION, MatewnckApplicationClass))

typedef struct _MatewnckApplicationClass   MatewnckApplicationClass;
typedef struct _MatewnckApplicationPrivate MatewnckApplicationPrivate;

/**
 * MatewnckApplication:
 *
 * The #MatewnckApplication struct contains only private fields and should not be
 * directly accessed.
 */
struct _MatewnckApplication
{
  GObject parent_instance;

  MatewnckApplicationPrivate *priv;
};

struct _MatewnckApplicationClass
{
  GObjectClass parent_class;

  /* app name or icon name changed */
  void (* name_changed) (MatewnckApplication *app);

  /* icon changed */
  void (* icon_changed) (MatewnckApplication *app);
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

GType matewnck_application_get_type (void) G_GNUC_CONST;

MatewnckApplication* matewnck_application_get (gulong xwindow);

gulong matewnck_application_get_xid (MatewnckApplication *app);

GList* matewnck_application_get_windows   (MatewnckApplication *app);
int    matewnck_application_get_n_windows (MatewnckApplication *app);

/* application_get_name, application_get_pid, etc.; prefer to read
 * properties straight off the group leader, and failing that, if the
 * prop is the same for all windows in the app, return the values for
 * the window. Failing that, they make stuff up.
 */
const char* matewnck_application_get_name      (MatewnckApplication *app);
const char* matewnck_application_get_icon_name (MatewnckApplication *app);
int         matewnck_application_get_pid       (MatewnckApplication *app);
GdkPixbuf*  matewnck_application_get_icon      (MatewnckApplication *app);
GdkPixbuf*  matewnck_application_get_mini_icon (MatewnckApplication *app);
gboolean    matewnck_application_get_icon_is_fallback (MatewnckApplication *app);
const char* matewnck_application_get_startup_id (MatewnckApplication *app);

G_END_DECLS

#endif /* MATEWNCK_APPLICATION_H */


