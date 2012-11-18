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

#include <libmatewnck/libmatewnck.h>
#include <gtk/gtk.h>
#include <errno.h>
#include <unistd.h>
#include "workspace-accessible.h"
#include "private.h"
static void        matewnck_workspace_accessible_class_init          (MatewnckWorkspaceAccessibleClass *klass);
static const char* matewnck_workspace_accessible_get_name            (AtkObject                    *obj);
static const char* matewnck_workspace_accessible_get_description     (AtkObject                    *obj);
static int         matewnck_workspace_accessible_get_index_in_parent (AtkObject                    *obj);
static void        atk_component_interface_init                  (AtkComponentIface            *iface);
static void        matewnck_workspace_accessible_get_extents         (AtkComponent                 *component,
                                                                  int                          *x,
                                                                  int                          *y,
                                                                  int                          *width,
                                                                  int                          *height,
                                                                  AtkCoordType                  coords);
static void        matewnck_workspace_accessible_get_position        (AtkComponent                 *component,
                                                                  int                          *x,
                                                                  int                          *y,
                                                                  AtkCoordType                  coords);
static gboolean    matewnck_workspace_accessible_contains            (AtkComponent                 *component,
                                                                  int                           x,
                                                                  int                           y,
                                                                  AtkCoordType                  coords);
static void        matewnck_workspace_accessible_get_size            (AtkComponent                 *component,
                                                                  int                          *width,
                                                                  int                          *height);

GType
matewnck_workspace_accessible_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      const GTypeInfo tinfo = 
      {
        sizeof (MatewnckWorkspaceAccessibleClass),
        (GBaseInitFunc) NULL, /* base init */
        (GBaseFinalizeFunc) NULL, /* base finalize */
        (GClassInitFunc) matewnck_workspace_accessible_class_init,
        (GClassFinalizeFunc) NULL, /* class finalize */
        NULL, /* class data */
        sizeof (MatewnckWorkspaceAccessible), /* instance size*/
        0, /* nb preallocs */
        (GInstanceInitFunc) NULL, /* instance init */
        NULL /* value table */
      };

      const GInterfaceInfo atk_component_info = 
      {
        (GInterfaceInitFunc) atk_component_interface_init,
        (GInterfaceFinalizeFunc) NULL,
        NULL
      };

      type = g_type_register_static (ATK_TYPE_GOBJECT_ACCESSIBLE, "MatewnckWorkspaceAccessible", &tinfo, 0);
      g_type_add_interface_static (type, ATK_TYPE_COMPONENT, &atk_component_info);
  }
  return type;
}

static void
atk_component_interface_init (AtkComponentIface *iface)
{
  g_return_if_fail (iface != NULL);

  iface->get_extents = matewnck_workspace_accessible_get_extents;
  iface->get_size = matewnck_workspace_accessible_get_size;
  iface->get_position = matewnck_workspace_accessible_get_position;
  iface->contains = matewnck_workspace_accessible_contains;
}

static void 
matewnck_workspace_accessible_get_extents (AtkComponent *component,
                                       int          *x, 
                                       int          *y, 
                                       int          *width,
                                       int          *height,
                                       AtkCoordType  coords)
{
  AtkGObjectAccessible *atk_gobj;
  MatewnckWorkspace *workspace;
  MatewnckPager *pager;
  GdkRectangle rect;
  GtkWidget *widget;
  AtkObject *parent;
  GObject *g_obj;
  int px, py;

  g_return_if_fail (MATEWNCK_IS_WORKSPACE_ACCESSIBLE (component));

  atk_gobj = ATK_GOBJECT_ACCESSIBLE (component);
  g_obj = atk_gobject_accessible_get_object (atk_gobj);
  if (g_obj == NULL)
    return;

  g_return_if_fail (MATEWNCK_IS_WORKSPACE (g_obj));
  workspace = MATEWNCK_WORKSPACE (g_obj);

  parent = atk_object_get_parent (ATK_OBJECT(component));
#if GTK_CHECK_VERSION(2,21,0)
  widget = gtk_accessible_get_widget (GTK_ACCESSIBLE (parent));
#else
  widget = GTK_ACCESSIBLE (parent)->widget;
#endif

  if (widget == NULL)
    {
      /*
       *State is defunct
       */
      return;
    }

  g_return_if_fail (MATEWNCK_IS_PAGER (widget));
  pager = MATEWNCK_PAGER (widget);

  g_return_if_fail (MATEWNCK_IS_PAGER (pager));

  atk_component_get_position (ATK_COMPONENT (parent), &px,&py, coords);

  _matewnck_pager_get_workspace_rect (pager, MATEWNCK_WORKSPACE_ACCESSIBLE (component)->index, &rect);
  
  *x = rect.x + px;
  *y = rect.y + py;
  *height = rect.height;
  *width = rect.width; 
}

static void
matewnck_workspace_accessible_get_size (AtkComponent *component,
                                    int          *width,
                                    int          *height)
{
  AtkCoordType coords = ATK_XY_SCREEN; 
  int x, y;

  /* FIXME: Value for initialization of coords picked randomly to please gcc */
  
  matewnck_workspace_accessible_get_extents (component, &x, &y, width, height, coords);
}

static void
matewnck_workspace_accessible_get_position (AtkComponent *component,
		                     int         *x,
			      	     int         *y,
			     	     AtkCoordType  coords)
{
  int width, height;
  matewnck_workspace_accessible_get_extents (component, x, y, &width, &height, coords);
}

static gboolean
matewnck_workspace_accessible_contains (AtkComponent *component, 
                                    int           x,
                                    int           y,
                                    AtkCoordType  coords)
{
  int lx, ly, width, height;

  matewnck_workspace_accessible_get_extents (component, &lx, &ly, &width, &height, coords);

  /*
   * Check if the specified co-ordinates fall within the workspace.
   */
  if ( (x > lx) && ((lx + width) >= x)  && (y > ly) && ((ly + height) >= ly) )
    return TRUE;
  else
    return FALSE;
}

static void
matewnck_workspace_accessible_class_init (MatewnckWorkspaceAccessibleClass *klass)
{
  AtkObjectClass *class = ATK_OBJECT_CLASS (klass);

  class->get_name = matewnck_workspace_accessible_get_name;
  class->get_description = matewnck_workspace_accessible_get_description;
  class->get_index_in_parent = matewnck_workspace_accessible_get_index_in_parent;
}

AtkObject*
matewnck_workspace_accessible_new (GObject *obj)
{
  GObject *object;
  AtkObject *atk_object;

  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE (obj), NULL);

  object = g_object_new (MATEWNCK_WORKSPACE_TYPE_ACCESSIBLE, NULL);
  atk_object = ATK_OBJECT (object);
  atk_object_initialize (atk_object, obj);

  g_return_val_if_fail (ATK_IS_OBJECT (atk_object), NULL);

  MATEWNCK_WORKSPACE_ACCESSIBLE (atk_object)->index =
    matewnck_workspace_get_number (MATEWNCK_WORKSPACE (obj));
  
  return atk_object;
}

static const char*
matewnck_workspace_accessible_get_name (AtkObject *obj)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE_ACCESSIBLE (obj), NULL);

  if (obj->name != NULL)
    {
      return obj->name;
    }
  else
    return NULL;
}

static const char*
matewnck_workspace_accessible_get_description (AtkObject *obj)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE_ACCESSIBLE (obj), NULL);

  if (obj->description != NULL)
    {
      return obj->description;
    }
  else
    return NULL;
}

static gint
matewnck_workspace_accessible_get_index_in_parent (AtkObject *obj)
{
  g_return_val_if_fail (MATEWNCK_IS_WORKSPACE_ACCESSIBLE (obj), -1);

  return MATEWNCK_WORKSPACE_ACCESSIBLE (obj)->index;
}
