/* util header */
/* vim: set sw=2 et: */

/*
 * Copyright (C) 2001 Havoc Pennington
 * Copyright (C) 2003 Red Hat, Inc.
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

#ifndef MATEWNCK_UTIL_H
#define MATEWNCK_UTIL_H

#include <gtk/gtk.h>

typedef struct _MatewnckResourceUsage MatewnckResourceUsage;

/**
 * MatewnckResourceUsage:
 * @total_bytes_estimate: estimation of the total number of bytes allocated in
 * the X server.
 * @pixmap_bytes: number of bytes allocated in the X server for resources of
 * type Pixmap.
 * @n_pixmaps: number of Pixmap resources allocated.
 * @n_windows: number of Window resources allocated.
 * @n_gcs: number of GContext resources allocated.
 * @n_pictures: number of Picture resources allocated.
 * @n_glyphsets: number of Glyphset resources allocated.
 * @n_fonts: number of Font resources allocated.
 * @n_colormap_entries: number of Colormap resources allocated.
 * @n_passive_grabs: number of PassiveGrab resources allocated.
 * @n_cursors: number of Cursor resources allocated.
 * @n_other: number of other resources allocated.
 *
 * The #MatewnckResourceUsage struct contains information about the total resource
 * usage of an X client, and the number of resources allocated for each
 * resource type.
 *
 * Since: 2.6
 */
struct _MatewnckResourceUsage
{
  gulong        total_bytes_estimate;
  
  gulong        pixmap_bytes;

  unsigned int n_pixmaps;
  unsigned int n_windows;
  unsigned int n_gcs;
  unsigned int n_pictures;
  unsigned int n_glyphsets;
  unsigned int n_fonts;
  unsigned int n_colormap_entries;
  unsigned int n_passive_grabs;
  unsigned int n_cursors;
  unsigned int n_other;

  /*< private >*/
  unsigned int pad1;
  unsigned int pad2;
  unsigned int pad3;
  unsigned int pad4;
  unsigned int pad5;
  unsigned long pad6;
  unsigned long pad7;
  unsigned long pad8;
  unsigned long pad9;
};

/**
 * MatewnckClientType:
 * @MATEWNCK_CLIENT_TYPE_APPLICATION: the libmatewnck user is a normal application.
 * @MATEWNCK_CLIENT_TYPE_PAGER: the libmatewnck user is an utility application dealing
 * with window management, like pagers and taskbars.
 *
 * Type describing the role of the libmatewnck user.
 *
 * Since: 2.14
 */
typedef enum {
  MATEWNCK_CLIENT_TYPE_APPLICATION = 1,
  MATEWNCK_CLIENT_TYPE_PAGER = 2
} MatewnckClientType;

void matewnck_set_client_type (MatewnckClientType ewmh_sourceindication_client_type);

void matewnck_xid_read_resource_usage (GdkDisplay        *gdk_display,
                                   gulong             xid,
                                   MatewnckResourceUsage *usage);

void matewnck_pid_read_resource_usage (GdkDisplay        *gdk_display,
                                   gulong             pid,
                                   MatewnckResourceUsage *usage);


#ifndef MATEWNCK_DISABLE_DEPRECATED
void matewnck_gtk_window_set_dock_type (GtkWindow *window);
#endif /* MATEWNCK_DISABLE_DEPRECATED */

#endif /* MATEWNCK_UTIL_H */


