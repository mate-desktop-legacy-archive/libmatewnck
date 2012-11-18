/* pager object */
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

#ifndef MATEWNCK_PAGER_H
#define MATEWNCK_PAGER_H

#include <gtk/gtk.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_PAGER              (matewnck_pager_get_type ())
#define MATEWNCK_PAGER(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_PAGER, MatewnckPager))
#define MATEWNCK_PAGER_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_PAGER, MatewnckPagerClass))
#define MATEWNCK_IS_PAGER(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_PAGER))
#define MATEWNCK_IS_PAGER_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_PAGER))
#define MATEWNCK_PAGER_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_PAGER, MatewnckPagerClass))

typedef struct _MatewnckPager        MatewnckPager;
typedef struct _MatewnckPagerClass   MatewnckPagerClass;
typedef struct _MatewnckPagerPrivate MatewnckPagerPrivate;

/**
 * MatewnckPager:
 *
 * The #MatewnckPager struct contains only private fields and should not be
 * directly accessed.
 */
struct _MatewnckPager
{
  GtkContainer parent_instance;

  MatewnckPagerPrivate *priv;
};

struct _MatewnckPagerClass
{
  GtkContainerClass parent_class;
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

/**
 * MatewnckPagerDisplayMode:
 * @MATEWNCK_PAGER_DISPLAY_NAME: the #MatewnckPager will only display the names of the
 * workspaces.
 * @MATEWNCK_PAGER_DISPLAY_CONTENT: the #MatewnckPager will display a representation
 * for each window in the workspaces.
 *
 * Mode defining what a #MatewnckPager will display.
 */
typedef enum {
  MATEWNCK_PAGER_DISPLAY_NAME,
  MATEWNCK_PAGER_DISPLAY_CONTENT
} MatewnckPagerDisplayMode;

/**
 * MatewnckPagerLayoutPolicy:
 * @MATEWNCK_PAGER_LAYOUT_POLICY_AUTOMATIC: the #MatewnckPager geometry management is
 * "height for width" when in vertical orientation, or "width for height" when
 * in horizontal orientation. This is the default behavior.
 * @MATEWNCK_PAGER_LAYOUT_POLICY_WIDTH_FOR_HEIGHT: the #MatewnckPager calculates its
 * width in proportion to a preset height. This can be used for a vertical
 * #MatewnckPager inside a horizontal panel.
 * @MATEWNCK_PAGER_LAYOUT_POLICY_HEIGHT_FOR_WIDTH: the #MatewnckPager calculates its
 * height in proportion to a preset width. This can be used for a horizontal
 * #MatewnckPager inside a vertical panel.
 *
 * Policy defining the geometry management used by a #MatewnckPager.
 *
 * Since: 2.32
 */
typedef enum {
  MATEWNCK_PAGER_LAYOUT_POLICY_AUTOMATIC,
  MATEWNCK_PAGER_LAYOUT_POLICY_WIDTH_FOR_HEIGHT,
  MATEWNCK_PAGER_LAYOUT_POLICY_HEIGHT_FOR_WIDTH
} MatewnckPagerLayoutPolicy;

GType matewnck_pager_get_type (void) G_GNUC_CONST;

GtkWidget* matewnck_pager_new (MatewnckScreen *screen);

gboolean matewnck_pager_set_orientation (MatewnckPager         *pager,
				     GtkOrientation     orientation);
gboolean matewnck_pager_set_n_rows   (MatewnckPager            *pager,
				  int                   n_rows);
void matewnck_pager_set_display_mode (MatewnckPager            *pager,
				  MatewnckPagerDisplayMode  mode);
void matewnck_pager_set_show_all     (MatewnckPager            *pager,
				  gboolean              show_all_workspaces);
void matewnck_pager_set_shadow_type  (MatewnckPager	       *pager,
				  GtkShadowType		shadow_type);
void matewnck_pager_set_layout_policy (MatewnckPager            *pager,
                                   MatewnckPagerLayoutPolicy policy);


#ifndef MATEWNCK_DISABLE_DEPRECATED
void matewnck_pager_set_screen       (MatewnckPager            *pager,
				  MatewnckScreen           *screen);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* MATEWNCK_PAGER_H */


