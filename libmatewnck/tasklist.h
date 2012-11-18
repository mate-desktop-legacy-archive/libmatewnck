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
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef MATEWNCK_TASKLIST_H
#define MATEWNCK_TASKLIST_H

#include <gtk/gtk.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_TASKLIST              (matewnck_tasklist_get_type ())
#define MATEWNCK_TASKLIST(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_TASKLIST, MatewnckTasklist))
#define MATEWNCK_TASKLIST_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_TASKLIST, MatewnckTasklistClass))
#define MATEWNCK_IS_TASKLIST(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_TASKLIST))
#define MATEWNCK_IS_TASKLIST_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_TASKLIST))
#define MATEWNCK_TASKLIST_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_TASKLIST, MatewnckTasklistClass))

typedef struct _MatewnckTasklist        MatewnckTasklist;
typedef struct _MatewnckTasklistClass   MatewnckTasklistClass;
typedef struct _MatewnckTasklistPrivate MatewnckTasklistPrivate;

/**
 * MatewnckTasklist:
 *
 * The #MatewnckTasklist struct contains only private fields and should not be
 * directly accessed.
 */
struct _MatewnckTasklist
{
  GtkContainer parent_instance;

  MatewnckTasklistPrivate *priv;
};

struct _MatewnckTasklistClass
{
  GtkContainerClass parent_class;
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

/**
 * MatewnckTasklistGroupingType:
 * @MATEWNCK_TASKLIST_NEVER_GROUP: never group multiple #MatewnckWindow of the same
 * #MatewnckApplication.
 * @MATEWNCK_TASKLIST_AUTO_GROUP: group multiple #MatewnckWindow of the same
 * #MatewnckApplication for some #MatewnckApplication, when there is not enough place
 * to have a good-looking list of all #MatewnckWindow.
 * @MATEWNCK_TASKLIST_ALWAYS_GROUP: always group multiple #MatewnckWindow of the same
 * #MatewnckApplication, for all #MatewnckApplication.
 *
 * Type defining the policy of the #MatewnckTasklist for grouping multiple
 * #MatewnckWindow of the same #MatewnckApplication.
 */
typedef enum {
  MATEWNCK_TASKLIST_NEVER_GROUP,
  MATEWNCK_TASKLIST_AUTO_GROUP,
  MATEWNCK_TASKLIST_ALWAYS_GROUP
} MatewnckTasklistGroupingType;

GType matewnck_tasklist_get_type (void) G_GNUC_CONST;

GtkWidget *matewnck_tasklist_new (MatewnckScreen *screen);
const int *matewnck_tasklist_get_size_hint_list (MatewnckTasklist  *tasklist,
					      int           *n_elements);

void matewnck_tasklist_set_grouping (MatewnckTasklist             *tasklist,
				 MatewnckTasklistGroupingType  grouping);
void matewnck_tasklist_set_switch_workspace_on_unminimize (MatewnckTasklist  *tasklist,
						       gboolean       switch_workspace_on_unminimize);
void matewnck_tasklist_set_grouping_limit (MatewnckTasklist *tasklist,
				       gint          limit);
void matewnck_tasklist_set_include_all_workspaces (MatewnckTasklist *tasklist,
					       gboolean      include_all_workspaces);
void matewnck_tasklist_set_button_relief (MatewnckTasklist *tasklist,
                                      GtkReliefStyle relief);
#ifndef MATEWNCK_DISABLE_DEPRECATED
void matewnck_tasklist_set_minimum_width (MatewnckTasklist *tasklist, gint size);
gint matewnck_tasklist_get_minimum_width (MatewnckTasklist *tasklist);
void matewnck_tasklist_set_minimum_height (MatewnckTasklist *tasklist, gint size);
gint matewnck_tasklist_get_minimum_height (MatewnckTasklist *tasklist);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

/**
 * MatewnckLoadIconFunction:
 * @icon_name: an icon name as in the Icon field in a .desktop file for the
 * icon to load.
 * @size: the desired icon size.
 * @flags: not defined to do anything yet.
 * @data: data passed to the function, set when the #MatewnckLoadIconFunction has
 * been set for the #MatewnckTasklist.
 *
 * Specifies the type of function passed to matewnck_tasklist_set_icon_loader().
 *
 * Returns: it should return a <classname>GdkPixbuf</classname> of @icon_name
 * at size @size, or %NULL if no icon for @icon_name at size @size could be
 * loaded.
 *
 * Since: 2.2
 */
typedef GdkPixbuf* (*MatewnckLoadIconFunction) (const char   *icon_name,
                                            int           size,
                                            unsigned int  flags,
                                            void         *data);

void matewnck_tasklist_set_icon_loader (MatewnckTasklist         *tasklist,
                                    MatewnckLoadIconFunction  load_icon_func,
                                    void                 *data,
                                    GDestroyNotify        free_data_func);


#ifndef MATEWNCK_DISABLE_DEPRECATED
void       matewnck_tasklist_set_screen (MatewnckTasklist *tasklist,
				     MatewnckScreen   *screen);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* MATEWNCK_TASKLIST_H */


