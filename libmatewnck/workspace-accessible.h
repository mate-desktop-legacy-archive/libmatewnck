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

#ifndef __MATEWNCK_WORKSPACE_ACCESSIBLE_H__
#define __MATEWNCK_WORKSPACE_ACCESSIBLE_H__

#include <gtk/gtk.h>
#include <atk/atk.h>
#include "workspace.h"
#include "pager-accessible.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MATEWNCK_WORKSPACE_TYPE_ACCESSIBLE                     (matewnck_workspace_accessible_get_type ())
#define MATEWNCK_WORKSPACE_ACCESSIBLE(obj)                     (G_TYPE_CHECK_INSTANCE_CAST ((obj), MATEWNCK_WORKSPACE_TYPE_ACCESSIBLE, MatewnckWorkspaceAccessible))
#define MATEWNCK_WORKSPACE_ACCESSIBLE_CLASS(klass)             (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_WORKSPACE_TYPE_ACCESSIBLE, MatewnckWorkspaceAccessibleClass))
#define MATEWNCK_IS_WORKSPACE_ACCESSIBLE(obj)                  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MATEWNCK_WORKSPACE_TYPE_ACCESSIBLE))
#define MATEWNCK_IS_WORKSPACE_ACCESSIBLE_CLASS(klass)          (G_TYPE_CHECK_CLASS_TYPE ((klass), MatewnckWorkspaceAccessible))
#define MATEWNCK_WORKSPACE_ACCESSIBLE_GET_CLASS(obj)           (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_WORKSPACE_TYPE_ACCESSIBLE, MatewnckWorkspaceAccessibleClass)) 

typedef struct _MatewnckWorkspaceAccessible MatewnckWorkspaceAccessible;
typedef struct _MatewnckWorkspaceAccessibleClass MatewnckWorkspaceAccessibleClass;

struct _MatewnckWorkspaceAccessible
{
  AtkGObjectAccessible parent;

  int index;
};

struct _MatewnckWorkspaceAccessibleClass 
{
  AtkGObjectAccessibleClass parent_class;
};

GType matewnck_workspace_accessible_get_type (void) G_GNUC_CONST;

AtkObject* matewnck_workspace_accessible_new (GObject *obj); 

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __MATEWNCK_WORKSPACE_ACCESSIBLE_H__ */
