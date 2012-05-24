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
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef MATEWNCK_PAGER_H
#define MATEWNCK_PAGER_H

#include <gtk/gtk.h>
#include <libmatewnck/screen.h>

G_BEGIN_DECLS

#define MATEWNCK_TYPE_PAGER              (matewnck_pager_get_type ())
#define MATEWNCK_PAGER(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), MATEWNCK_TYPE_PAGER, MateWnckPager))
#define MATEWNCK_PAGER_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), MATEWNCK_TYPE_PAGER, MateWnckPagerClass))
#define MATEWNCK_IS_PAGER(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), MATEWNCK_TYPE_PAGER))
#define MATEWNCK_IS_PAGER_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), MATEWNCK_TYPE_PAGER))
#define MATEWNCK_PAGER_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), MATEWNCK_TYPE_PAGER, MateWnckPagerClass))

typedef struct _MateWnckPager        MateWnckPager;
typedef struct _MateWnckPagerClass   MateWnckPagerClass;
typedef struct _MateWnckPagerPrivate MateWnckPagerPrivate;

/**
 * MateWnckPager:
 *
 * The #MateWnckPager struct contains only private fields and should not be
 * directly accessed.
 */
struct _MateWnckPager
{
  GtkContainer parent_instance;

  MateWnckPagerPrivate *priv;
};

struct _MateWnckPagerClass
{
  GtkContainerClass parent_class;
  
  /* Padding for future expansion */
  void (* pad1) (void);
  void (* pad2) (void);
  void (* pad3) (void);
  void (* pad4) (void);
};

/**
 * MateWnckPagerDisplayMode:
 * @MATEWNCK_PAGER_DISPLAY_NAME: the #MateWnckPager will only display the names of the
 * workspaces.
 * @MATEWNCK_PAGER_DISPLAY_CONTENT: the #MateWnckPager will display a representation
 * for each window in the workspaces.
 *
 * Mode defining what a #MateWnckPager will display.
 */
typedef enum {
  MATEWNCK_PAGER_DISPLAY_NAME,
  MATEWNCK_PAGER_DISPLAY_CONTENT
} MateWnckPagerDisplayMode;

/**
 * MateWnckPagerLayoutPolicy:
 * @MATEWNCK_PAGER_LAYOUT_POLICY_AUTOMATIC: the #MateWnckPager geometry management is
 * "height for width" when in vertical orientation, or "width for height" when
 * in horizontal orientation. This is the default behavior.
 * @MATEWNCK_PAGER_LAYOUT_POLICY_WIDTH_FOR_HEIGHT: the #MateWnckPager calculates its
 * width in proportion to a preset height. This can be used for a vertical
 * #MateWnckPager inside a horizontal panel.
 * @MATEWNCK_PAGER_LAYOUT_POLICY_HEIGHT_FOR_WIDTH: the #MateWnckPager calculates its
 * height in proportion to a preset width. This can be used for a horizontal
 * #MateWnckPager inside a vertical panel.
 *
 * Policy defining the geometry management used by a #MateWnckPager.
 *
 * Since: 2.32
 */
typedef enum {
  MATEWNCK_PAGER_LAYOUT_POLICY_AUTOMATIC,
  MATEWNCK_PAGER_LAYOUT_POLICY_WIDTH_FOR_HEIGHT,
  MATEWNCK_PAGER_LAYOUT_POLICY_HEIGHT_FOR_WIDTH
} MateWnckPagerLayoutPolicy;

GType matewnck_pager_get_type (void) G_GNUC_CONST;

GtkWidget* matewnck_pager_new (MateWnckScreen *screen);

gboolean matewnck_pager_set_orientation (MateWnckPager         *pager,
				     GtkOrientation     orientation);
gboolean matewnck_pager_set_n_rows   (MateWnckPager            *pager,
				  int                   n_rows);
void matewnck_pager_set_display_mode (MateWnckPager            *pager,
				  MateWnckPagerDisplayMode  mode);
void matewnck_pager_set_show_all     (MateWnckPager            *pager,
				  gboolean              show_all_workspaces);
void matewnck_pager_set_shadow_type  (MateWnckPager	       *pager,
				  GtkShadowType		shadow_type);
void matewnck_pager_set_layout_policy (MateWnckPager            *pager,
                                   MateWnckPagerLayoutPolicy policy);


#ifndef MATEWNCK_DISABLE_DEPRECATED
void matewnck_pager_set_screen       (MateWnckPager            *pager,
				  MateWnckScreen           *screen);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* MATEWNCK_PAGER_H */


