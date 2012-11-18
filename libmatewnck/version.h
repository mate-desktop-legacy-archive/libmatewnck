/* version info */
/* vim: set sw=2 et: */

/*
 * Copyright (C) 2011 Novell, Inc.
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
 *
 * Authors:
 *      Vincent Untz <vuntz@gnome.org>
 */

/**
 * SECTION:version
 * @Short_description: variables and functions to check the libmatewnck version
 * @stability: Unstable
 *
 * libmatewnck provides version information, primarily useful in configure checks
 * for builds that have a configure script, and to write code against different
 * versions of libmatewnck that do not provide the same API.
 */

#ifndef MATEWNCK_VERSION_H
#define MATEWNCK_VERSION_H

/**
 * MATEWNCK_MAJOR_VERSION:
 *
 * Return value: the major version number of the libmatewnck library, from the
 * headers used at application compile time, rather than from the library
 * linked against at application run time.
 * (e.g. in libmatewnck version 1.2.5 this is 1.)
 *
 * Since: 2.32
 */
#define MATEWNCK_MAJOR_VERSION (2)

/**
 * MATEWNCK_MINOR_VERSION:
 *
 * Return value: the minor version number of the libmatewnck library, from the
 * headers used at application compile time, rather than from the library
 * linked against at application run time.
 * (e.g. in libmatewnck version 1.2.5 this is 2.)
 *
 * Since: 2.32
 */
#define MATEWNCK_MINOR_VERSION (31)

/**
 * MATEWNCK_MICRO_VERSION:
 *
 * Return value: the micro version number of the libmatewnck library, from the
 * headers used at application compile time, rather than from the library
 * linked against at application run time.
 * (e.g. in libmatewnck version 1.2.5 this is 5.)
 *
 * Since: 2.32
 */
#define MATEWNCK_MICRO_VERSION (0)

/**
 * MATEWNCK_CHECK_VERSION:
 * @major: major version (e.g. 1 for version 1.2.5)
 * @minor: minor version (e.g. 2 for version 1.2.5)
 * @micro: micro version (e.g. 5 for version 1.2.5)
 *
 * Return value: %TRUE if the version of the libmatewnck header files
 * is the same as or newer than the passed-in version, %FALSE
 * otherwise.
 *
 * Since: 2.32
 */
#define MATEWNCK_CHECK_VERSION(major,minor,micro)                           \
    (MATEWNCK_MAJOR_VERSION > (major) ||                                    \
     (MATEWNCK_MAJOR_VERSION == (major) && MATEWNCK_MINOR_VERSION > (minor)) || \
     (MATEWNCK_MAJOR_VERSION == (major) && MATEWNCK_MINOR_VERSION == (minor) && \
      MATEWNCK_MICRO_VERSION >= (micro)))

#endif /* MATEWNCK_VERSION_H */
