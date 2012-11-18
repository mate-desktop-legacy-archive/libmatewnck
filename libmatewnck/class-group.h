/* class group object */
/* vim: set sw=2 et: */

/*
 * Copyright (C) 2003 Ximian, Inc.
 * Authors: Federico Mena-Quintero <federico@ximian.com>
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

#ifndef MATEWNCK_CLASS_GROUP_H
#define MATEWNCK_CLASS_GROUP_H

#include <glib-object.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_CLASS_GROUP              (matewnck_class_group_get_type ())
#define MATEWNCK_CLASS_GROUP(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_CLASS_GROUP, MatewnckClassGroup))
#define MATEWNCK_CLASS_GROUP_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_CLASS_GROUP, MatewnckClassGroupClass))
#define MATEWNCK_IS_CLASS_GROUP(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_CLASS_GROUP))
#define MATEWNCK_IS_CLASS_GROUP_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_CLASS_GROUP))
#define MATEWNCK_CLASS_GROUP_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_CLASS_GROUP, MatewnckClassGroupClass))

typedef struct _MatewnckClassGroupClass   MatewnckClassGroupClass;
typedef struct _MatewnckClassGroupPrivate MatewnckClassGroupPrivate;

/**
 * MatewnckClassGroup:
 *
 * The #MatewnckClassGroup struct contains only private fields and should not be
 * directly accessed.
 */
struct _MatewnckClassGroup
{
  GObject parent_instance;

  MatewnckClassGroupPrivate *priv;
};

struct _MatewnckClassGroupClass
{
  GObjectClass parent_class;

  void (* name_changed) (MatewnckApplication *app);
  void (* icon_changed) (MatewnckApplication *app);
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

GType matewnck_class_group_get_type (void) G_GNUC_CONST;

MatewnckClassGroup *matewnck_class_group_get (const char *res_class);

GList *matewnck_class_group_get_windows (MatewnckClassGroup *class_group);
const char * matewnck_class_group_get_res_class (MatewnckClassGroup *class_group);

const char * matewnck_class_group_get_name (MatewnckClassGroup *class_group);

GdkPixbuf *matewnck_class_group_get_icon (MatewnckClassGroup *class_group);
GdkPixbuf *matewnck_class_group_get_mini_icon (MatewnckClassGroup *class_group);

G_END_DECLS

#endif
