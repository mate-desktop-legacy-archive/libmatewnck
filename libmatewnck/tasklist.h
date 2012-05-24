/* tasklist object */
/* vim: set sw=2 et: */

/*
 * Copyright (C) 2001 Havoc Pennington
 * Copyright (C) 2003, 2005-2007 Vincent Untz
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

#ifndef MATEWNCK_TASKLIST_H
#define MATEWNCK_TASKLIST_H

#include <gtk/gtk.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_TASKLIST              (matewnck_tasklist_get_type ())
#define MATEWNCK_TASKLIST(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_TASKLIST, MateWnckTasklist))
#define MATEWNCK_TASKLIST_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_TASKLIST, MateWnckTasklistClass))
#define MATEWNCK_IS_TASKLIST(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_TASKLIST))
#define MATEWNCK_IS_TASKLIST_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_TASKLIST))
#define MATEWNCK_TASKLIST_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_TASKLIST, MateWnckTasklistClass))

typedef struct _MateWnckTasklist        MateWnckTasklist;
typedef struct _MateWnckTasklistClass   MateWnckTasklistClass;
typedef struct _MateWnckTasklistPrivate MateWnckTasklistPrivate;

/**
 * MateWnckTasklist:
 *
 * The #MateWnckTasklist struct contains only private fields and should not be
 * directly accessed.
 */
struct _MateWnckTasklist
{
  GtkContainer parent_instance;

  MateWnckTasklistPrivate *priv;
};

struct _MateWnckTasklistClass
{
  GtkContainerClass parent_class;
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

/**
 * MateWnckTasklistGroupingType:
 * @MATEWNCK_TASKLIST_NEVER_GROUP: never group multiple #MateWnckWindow of the same
 * #MateWnckApplication.
 * @MATEWNCK_TASKLIST_AUTO_GROUP: group multiple #MateWnckWindow of the same
 * #MateWnckApplication for some #MateWnckApplication, when there is not enough place
 * to have a good-looking list of all #MateWnckWindow.
 * @MATEWNCK_TASKLIST_ALWAYS_GROUP: always group multiple #MateWnckWindow of the same
 * #MateWnckApplication, for all #MateWnckApplication.
 *
 * Type defining the policy of the #MateWnckTasklist for grouping multiple
 * #MateWnckWindow of the same #MateWnckApplication.
 */
typedef enum {
  MATEWNCK_TASKLIST_NEVER_GROUP,
  MATEWNCK_TASKLIST_AUTO_GROUP,
  MATEWNCK_TASKLIST_ALWAYS_GROUP
} MateWnckTasklistGroupingType;

GType matewnck_tasklist_get_type (void) G_GNUC_CONST;

GtkWidget *matewnck_tasklist_new (MateWnckScreen *screen);
const int *matewnck_tasklist_get_size_hint_list (MateWnckTasklist  *tasklist,
					      int           *n_elements);

void matewnck_tasklist_set_grouping (MateWnckTasklist             *tasklist,
				 MateWnckTasklistGroupingType  grouping);
void matewnck_tasklist_set_switch_workspace_on_unminimize (MateWnckTasklist  *tasklist,
						       gboolean       switch_workspace_on_unminimize);
void matewnck_tasklist_set_grouping_limit (MateWnckTasklist *tasklist,
				       gint          limit);
void matewnck_tasklist_set_include_all_workspaces (MateWnckTasklist *tasklist,
					       gboolean      include_all_workspaces);
void matewnck_tasklist_set_button_relief (MateWnckTasklist *tasklist,
                                      GtkReliefStyle relief);
#ifndef MATEWNCK_DISABLE_DEPRECATED
void matewnck_tasklist_set_minimum_width (MateWnckTasklist *tasklist, gint size);
gint matewnck_tasklist_get_minimum_width (MateWnckTasklist *tasklist);
void matewnck_tasklist_set_minimum_height (MateWnckTasklist *tasklist, gint size);
gint matewnck_tasklist_get_minimum_height (MateWnckTasklist *tasklist);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

/**
 * MateWnckLoadIconFunction:
 * @icon_name: an icon name as in the Icon field in a .desktop file for the
 * icon to load.
 * @size: the desired icon size.
 * @flags: not defined to do anything yet.
 * @data: data passed to the function, set when the #MateWnckLoadIconFunction has
 * been set for the #MateWnckTasklist.
 *
 * Specifies the type of function passed to matewnck_tasklist_set_icon_loader().
 *
 * Returns: it should return a <classname>GdkPixbuf</classname> of @icon_name
 * at size @size, or %NULL if no icon for @icon_name at size @size could be
 * loaded.
 *
 * Since: 2.2
 */
typedef GdkPixbuf* (*MateWnckLoadIconFunction) (const char   *icon_name,
                                            int           size,
                                            unsigned int  flags,
                                            void         *data);

void matewnck_tasklist_set_icon_loader (MateWnckTasklist         *tasklist,
                                    MateWnckLoadIconFunction  load_icon_func,
                                    void                 *data,
                                    GDestroyNotify        free_data_func);


#ifndef MATEWNCK_DISABLE_DEPRECATED
void       matewnck_tasklist_set_screen (MateWnckTasklist *tasklist,
				     MateWnckScreen   *screen);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* MATEWNCK_TASKLIST_H */


