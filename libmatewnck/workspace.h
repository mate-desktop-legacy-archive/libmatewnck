/* workspace object */
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

#ifndef MATEWNCK_WORKSPACE_H
#define MATEWNCK_WORKSPACE_H

#include <glib-object.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_WORKSPACE              (matewnck_workspace_get_type ())
#define MATEWNCK_WORKSPACE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_WORKSPACE, MateWnckWorkspace))
#define MATEWNCK_WORKSPACE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_WORKSPACE, MateWnckWorkspaceClass))
#define MATEWNCK_IS_WORKSPACE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_WORKSPACE))
#define MATEWNCK_IS_WORKSPACE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_WORKSPACE))
#define MATEWNCK_WORKSPACE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_WORKSPACE, MateWnckWorkspaceClass))

typedef struct _MateWnckWorkspaceClass   MateWnckWorkspaceClass;
typedef struct _MateWnckWorkspacePrivate MateWnckWorkspacePrivate;

/**
 * MateWnckWorkspace:
 *
 * The #MateWnckWorkspace struct contains only private fields and should not be
 * directly accessed.
 */
struct _MateWnckWorkspace
{
  GObject parent_instance;

  MateWnckWorkspacePrivate *priv;
};

struct _MateWnckWorkspaceClass
{
  GObjectClass parent_class;

  void (* name_changed) (MateWnckWorkspace *space);
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

GType matewnck_workspace_get_type (void) G_GNUC_CONST;

int         matewnck_workspace_get_number     (MateWnckWorkspace *space);
const char* matewnck_workspace_get_name       (MateWnckWorkspace *space);
void        matewnck_workspace_change_name    (MateWnckWorkspace *space,
                                           const char    *name);
MateWnckScreen* matewnck_workspace_get_screen     (MateWnckWorkspace *space);
void        matewnck_workspace_activate       (MateWnckWorkspace *space,
                                           guint32        timestamp);
int         matewnck_workspace_get_width      (MateWnckWorkspace *space);
int         matewnck_workspace_get_height     (MateWnckWorkspace *space);
int         matewnck_workspace_get_viewport_x (MateWnckWorkspace *space);
int         matewnck_workspace_get_viewport_y (MateWnckWorkspace *space);
gboolean    matewnck_workspace_is_virtual     (MateWnckWorkspace *space);


int matewnck_workspace_get_layout_row          (MateWnckWorkspace       *space);
int matewnck_workspace_get_layout_column       (MateWnckWorkspace       *space);
MateWnckWorkspace* matewnck_workspace_get_neighbor (MateWnckWorkspace       *space,
                                            MateWnckMotionDirection  direction);

G_END_DECLS

#endif /* MATEWNCK_WORKSPACE_H */
