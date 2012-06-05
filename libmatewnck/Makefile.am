lib_LTLIBRARIES = libmatewnck.la
bin_PROGRAMS =			\
	matewnckprop		\
	matewnck-urgency-monitor
noinst_PROGRAMS =		\
	test-pager		\
	test-matewnck		\
	test-selector		\
	test-tasklist		\
	test-urgent

AM_CPPFLAGS =					\
	$(LIBMATEWNCK_CFLAGS)			\
	-I$(top_srcdir)				\
	-DMATEWNCK_LOCALEDIR=\"$(matewncklocaledir)\"	\
	$(DISABLE_DEPRECATED_CFLAGS)

AM_CFLAGS = $(WARN_CFLAGS)

matewnck_headers =			\
	libmatewnck.h		\
	pager.h			\
	application.h		\
	class-group.h		\
	screen.h		\
	selector.h		\
	tasklist.h		\
	util.h			\
	window.h 		\
	window-action-menu.h	\
	workspace.h

matewnck_built_installed_headers = matewnck-enum-types.h

libmatewnckincludedir = $(includedir)/libmatewnck/libmatewnck
libmatewnckinclude_HEADERS =		\
	$(matewnck_headers)			\
	$(matewnck_built_installed_headers)	\
	version.h

# Sources that are relevant for introspection
matewnck_sources =			\
	application.c		\
	class-group.c		\
	pager.c			\
	screen.c		\
	selector.c		\
	tasklist.c		\
	util.c			\
	window.c		\
	window-action-menu.c	\
	workspace.c

matewnck_accessibility_files =			\
	pager-accessible.c			\
	pager-accessible.h			\
	pager-accessible-factory.c		\
	pager-accessible-factory.h		\
	workspace-accessible.c			\
	workspace-accessible.h			\
	workspace-accessible-factory.c		\
	workspace-accessible-factory.h

matewnck_built_headers = $(matewnck_built_installed_headers) matewnck-marshal.h inlinepixbufs.h
matewnck_built_cfiles = matewnck-enum-types.c matewnck-marshal.c

libmatewnck_la_SOURCES = 		\
	$(matewnck_built_headers)	\
	$(matewnck_built_cfiles)	\
	$(matewnck_sources)		\
	private.h		\
	xutils.c		\
	xutils.h		\
	$(matewnck_accessibility_files)

$(libmatewnck_la_OBJECTS): $(matewnck_built_headers)

libmatewnck_la_CPPFLAGS =			\
	$(AM_CPPFLAGS)			\
	$(XLIB_CFLAGS)			\
	-DG_LOG_DOMAIN=\"Matewnck\"		\
	-DSN_API_NOT_YET_FROZEN=1

libmatewnck_la_LIBADD =	\
	$(LIBMATEWNCK_LIBS)	\
	$(XLIB_LIBS)	\
	$(LIBM)

libmatewnck_la_LDFLAGS =								\
	-version-info $(LIBMATEWNCK_CURRENT):$(LIBMATEWNCK_REVISION):$(LIBMATEWNCK_AGE)	\
	-no-undefined								\
	-export-symbols-regex "^[^_].*"

matewnckprop_SOURCES = matewnckprop.c
matewnck_urgency_monitor_SOURCES = matewnck-urgency-monitor.c
test_matewnck_SOURCES = test-matewnck.c
test_tasklist_SOURCES = test-tasklist.c
test_selector_SOURCES = test-selector.c
test_pager_SOURCES = test-pager.c
test_urgent_SOURCES = test-urgent.c

matewnckprop_LDADD = $(LIBMATEWNCK_LIBS) ./$(lib_LTLIBRARIES)
matewnck_urgency_monitor_LDADD = $(LIBMATEWNCK_LIBS) ./$(lib_LTLIBRARIES)
test_matewnck_LDADD = $(LIBMATEWNCK_LIBS) ./$(lib_LTLIBRARIES)
test_tasklist_LDADD = $(LIBMATEWNCK_LIBS) ./$(lib_LTLIBRARIES)
test_selector_LDADD = $(LIBMATEWNCK_LIBS) ./$(lib_LTLIBRARIES)
test_pager_LDADD = $(LIBMATEWNCK_LIBS) ./$(lib_LTLIBRARIES)
test_urgent_LDADD = $(LIBMATEWNCK_LIBS)

matewnck-marshal.h: matewnck-marshal.list
	$(AM_V_GEN)$(GLIB_GENMARSHAL) --prefix=_matewnck_marshal $< --header > $@

matewnck-marshal.c: matewnck-marshal.list matewnck-marshal.h
	$(AM_V_GEN)echo "#include <libmatewnck/libmatewnck.h>" > $@ \
	&& echo "#include \"matewnck-marshal.h\"" >> $@ \
	&& $(GLIB_GENMARSHAL) --prefix=_matewnck_marshal $< --body >> $@

matewnck-enum-types.h: $(matewnck_headers)
	$(AM_V_GEN)glib-mkenums \
		--fhead "#ifndef __MATEWNCK_ENUM_TYPES_H__\n" \
		--fhead "#define __MATEWNCK_ENUM_TYPES_H__\n\n" \
		--fhead "G_BEGIN_DECLS\n\n" \
		--ftail "G_END_DECLS\n\n" \
		--ftail "#endif /* __MATEWNCK_ENUM_TYPES_H__ */\n" \
		--fprod "\n/* enumerations from \"@filename@\" */\n" \
		--eprod "#define MATEWNCK_TYPE_@ENUMSHORT@ @enum_name@_get_type()\n" \
		--eprod "GType @enum_name@_get_type (void);\n" \
		$^ > $@

matewnck-enum-types.c: $(matewnck_headers)
	$(AM_V_GEN)glib-mkenums \
		--fhead "#include <libmatewnck/libmatewnck.h>\n" \
		--fprod "\n/* enumerations from \"@filename@\" */" \
		--vhead "static const G@Type@Value _@enum_name@_values[] = {" \
		--vprod "  { @VALUENAME@, \"@VALUENAME@\", \"@valuenick@\" }," \
		--vtail "  { 0, NULL, NULL }\n};\n\n" \
		--vtail "GType\n@enum_name@_get_type (void)\n{\n" \
		--vtail "  static GType type = 0;\n\n" \
		--vtail "  if (!type)\n" \
		--vtail "    type = g_@type@_register_static (\"@EnumName@\", _@enum_name@_values);\n\n" \
		--vtail "  return type;\n}\n\n" \
		$^ > $@

inlinepixbufs_SOURCES = default_icon.png stock_delete.png stock_maximize.png stock_minimize.png
inlinepixbufs_pairs =						\
	default_icon_data $(srcdir)/default_icon.png 		\
	stock_delete_data $(srcdir)/stock_delete.png 		\
	stock_maximize_data $(srcdir)/stock_maximize.png 	\
	stock_minimize_data $(srcdir)/stock_minimize.png

inlinepixbufs.h: $(inlinepixbufs_SOURCES)
	$(AM_V_GEN)$(GDK_PIXBUF_CSOURCE) --raw --build-list $(inlinepixbufs_pairs) > $@

CLEANFILES =			\
	$(matewnck_built_cfiles)	\
	$(matewnck_built_headers)

EXTRA_DIST = 				\
	$(inlinepixbufs_SOURCES)	\
	version.h.in			\
	matewnck-marshal.list

# Introspection
-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS = --warn-all --add-include-path=$(srcdir)
INTROSPECTION_COMPILER_ARGS = --includedir=$(srcdir)

if HAVE_INTROSPECTION
introspection_sources = $(matewnck_sources) $(libmatewnckinclude_HEADERS)

Matewnck-1.0.gir: libmatewnck.la
Matewnck_1_0_gir_INCLUDES = GObject-2.0 GdkPixbuf-2.0 Gtk-2.0
Matewnck_1_0_gir_CFLAGS = $(AM_CPPFLAGS)
Matewnck_1_0_gir_LIBS = libmatewnck.la
Matewnck_1_0_gir_SCANNERFLAGS = --pkg-export=libmatewnck
Matewnck_1_0_gir_FILES = $(introspection_sources)
INTROSPECTION_GIRS += Matewnck-1.0.gir

girdir = $(INTROSPECTION_GIRDIR)
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(INTROSPECTION_TYPELIBDIR)
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif

-include $(top_srcdir)/git.mk
