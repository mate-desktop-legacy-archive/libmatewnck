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
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef MATEWNCK_CLASS_GROUP_H
#define MATEWNCK_CLASS_GROUP_H

#include <glib-object.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_CLASS_GROUP              (matewnck_class_group_get_type ())
#define MATEWNCK_CLASS_GROUP(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_CLASS_GROUP, MateWnckClassGroup))
#define MATEWNCK_CLASS_GROUP_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_CLASS_GROUP, MateWnckClassGroupClass))
#define MATEWNCK_IS_CLASS_GROUP(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_CLASS_GROUP))
#define MATEWNCK_IS_CLASS_GROUP_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_CLASS_GROUP))
#define MATEWNCK_CLASS_GROUP_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_CLASS_GROUP, MateWnckClassGroupClass))

typedef struct _MateWnckClassGroupClass   MateWnckClassGroupClass;
typedef struct _MateWnckClassGroupPrivate MateWnckClassGroupPrivate;

/**
 * MateWnckClassGroup:
 *
 * The #MateWnckClassGroup struct contains only private fields and should not be
 * directly accessed.
 */
struct _MateWnckClassGroup
{
  GObject parent_instance;

  MateWnckClassGroupPrivate *priv;
};

struct _MateWnckClassGroupClass
{
  GObjectClass parent_class;

  void (* name_changed) (MateWnckApplication *app);
  void (* icon_changed) (MateWnckApplication *app);
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

GType matewnck_class_group_get_type (void) G_GNUC_CONST;

MateWnckClassGroup *matewnck_class_group_get (const char *res_class);

GList *matewnck_class_group_get_windows (MateWnckClassGroup *class_group);
const char * matewnck_class_group_get_res_class (MateWnckClassGroup *class_group);

const char * matewnck_class_group_get_name (MateWnckClassGroup *class_group);

GdkPixbuf *matewnck_class_group_get_icon (MateWnckClassGroup *class_group);
GdkPixbuf *matewnck_class_group_get_mini_icon (MateWnckClassGroup *class_group);

G_END_DECLS

#endif
