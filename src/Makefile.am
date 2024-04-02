## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = foyer

foyer_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonctionc.c fonctionc.h \
	fonction.c fonction.h \
	menu.c menu.h \
	function.c function.h \
	reclamation.c reclamation.h \
	user.c user.h

foyer_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

