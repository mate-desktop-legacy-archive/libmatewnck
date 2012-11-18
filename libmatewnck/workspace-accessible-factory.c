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

#include <gtk/gtk.h>
#include "workspace-accessible-factory.h"
#include "workspace-accessible.h"

G_DEFINE_TYPE (MatewnckWorkspaceAccessibleFactory,
               matewnck_workspace_accessible_factory, ATK_TYPE_OBJECT_FACTORY);

static AtkObject* matewnck_workspace_accessible_factory_create_accessible (GObject *obj);

static GType matewnck_workspace_accessible_factory_get_accessible_type (void);

static void
matewnck_workspace_accessible_factory_class_init (MatewnckWorkspaceAccessibleFactoryClass *klass)
{
  AtkObjectFactoryClass *class = ATK_OBJECT_FACTORY_CLASS (klass);

  class->create_accessible = matewnck_workspace_accessible_factory_create_accessible;
  class->get_accessible_type = matewnck_workspace_accessible_factory_get_accessible_type;
}

static void
matewnck_workspace_accessible_factory_init (MatewnckWorkspaceAccessibleFactory *factory)
{
}

AtkObjectFactory*
matewnck_workspace_accessible_factory_new (void)
{
  GObject *factory;
  factory = g_object_new (MATEWNCK_TYPE_WORKSPACE_ACCESSIBLE_FACTORY, NULL);
  return ATK_OBJECT_FACTORY (factory);
}

static AtkObject*
matewnck_workspace_accessible_factory_create_accessible (GObject *obj)
{
  return matewnck_workspace_accessible_new (obj);
}

static GType
matewnck_workspace_accessible_factory_get_accessible_type (void)
{
  return MATEWNCK_WORKSPACE_TYPE_ACCESSIBLE;
}
