/* vim: set sw=2 et: */
/*
 * Copyright 2002 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __MATEWNCK_PAGER_ACCESSIBLE_H__
#define __MATEWNCK_PAGER_ACCESSIBLE_H__

#include <gtk/gtk.h>
#include <atk/atk.h>
#include "pager.h"
#include "screen.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MATEWNCK_PAGER_TYPE_ACCESSIBLE                     (matewnck_pager_accessible_get_type ())
#define MATEWNCK_PAGER_ACCESSIBLE(obj)                     (G_TYPE_CHECK_INSTANCE_CAST ((obj), MATEWNCK_PAGER_TYPE_ACCESSIBLE, MatewnckPagerAccessible))
#define MATEWNCK_PAGER_ACCESSIBLE_CLASS(klass)             (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_PAGER_TYPE_ACCESSIBLE, MatewnckPagerAccessibleClass))
#define MATEWNCK_PAGER_IS_ACCESSIBLE(obj)                  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MATEWNCK_PAGER_TYPE_ACCESSIBLE))
#define MATEWNCK_PAGER_IS_ACCESSIBLE_CLASS(klass)          (G_TYPE_CHECK_CLASS_TYPE ((klass), MatewnckPagerAccessible))
#define MATEWNCK_PAGER_ACCESSIBLE_GET_CLASS(obj)           (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_PAGER_TYPE_ACCESSIBLE, MatewnckPagerAccessibleClass)) 

typedef struct _MatewnckPagerAccessible MatewnckPagerAccessible;
typedef struct _MatewnckPagerAccessibleClass MatewnckPagerAccessibleClass;

struct _MatewnckPagerAccessible
{
  GtkAccessible parent;
};

struct _MatewnckPagerAccessibleClass
{
  GtkAccessibleClass parent_class;
};

GType matewnck_pager_accessible_get_type (void) G_GNUC_CONST;

AtkObject* matewnck_pager_accessible_new (GtkWidget *widget); 

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __MATEWNCK_PAGER_ACCESSIBLE_H__ */
