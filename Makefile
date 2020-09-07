#############################################################################
# Makefile for building: Tuto_1
# Generated by qmake (2.01a) (Qt 4.8.6) on: Wed May 31 14:35:21 2017
# Project:  Tuto_1.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -o Makefile Tuto_1.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT
CFLAGS        = -m64 -pipe -g -Wall -W $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -pedantic -Wall -Wextra -g -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I.
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS)   -lsfml-graphics -lsfml-window -lsfml-system 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		Application.cpp \
		AppliTableau.cpp \
		Niveau.cpp \
		Cases.cpp \
		Action.cpp \
		Conteneur.cpp \
		AppliMenu.cpp \
		Bouton.cpp \
		Text.cpp \
		AppliChoixNiveau.cpp \
		ChangementFenetre.cpp \
		Robot.cpp \
		AppliEditeur.cpp \
		CasesEditeur.cpp \
		AppliTransition.cpp \
		AppliChoixEdite.cpp 
OBJECTS       = main.o \
		Application.o \
		AppliTableau.o \
		Niveau.o \
		Cases.o \
		Action.o \
		Conteneur.o \
		AppliMenu.o \
		Bouton.o \
		Text.o \
		AppliChoixNiveau.o \
		ChangementFenetre.o \
		Robot.o \
		AppliEditeur.o \
		CasesEditeur.o \
		AppliTransition.o \
		AppliChoixEdite.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		deployment.pri \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Tuto_1.pro
QMAKE_TARGET  = Tuto_1
DESTDIR       = 
TARGET        = Tuto_1

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: Tuto_1.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		deployment.pri \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -o Makefile Tuto_1.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
deployment.pri:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -o Makefile Tuto_1.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Tuto_11.0.0 || $(MKDIR) .tmp/Tuto_11.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Tuto_11.0.0/ && (cd `dirname .tmp/Tuto_11.0.0` && $(TAR) Tuto_11.0.0.tar Tuto_11.0.0 && $(COMPRESS) Tuto_11.0.0.tar) && $(MOVE) `dirname .tmp/Tuto_11.0.0`/Tuto_11.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Tuto_11.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp AppliTableau.h \
		Application.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		ChangementFenetre.h \
		AppliChoixNiveau.h \
		Bouton.h \
		Text.h \
		AppliMenu.h \
		AppliEditeur.h \
		CasesEditeur.h \
		AppliTransition.h \
		AppliChoixEdite.h \
		Niveau.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Application.o: Application.cpp Application.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Application.o Application.cpp

AppliTableau.o: AppliTableau.cpp AppliTableau.h \
		Application.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		ChangementFenetre.h \
		AppliChoixNiveau.h \
		Bouton.h \
		Text.h \
		AppliMenu.h \
		AppliEditeur.h \
		CasesEditeur.h \
		AppliTransition.h \
		AppliChoixEdite.h \
		Niveau.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AppliTableau.o AppliTableau.cpp

Niveau.o: Niveau.cpp Niveau.h \
		Cases.h \
		Application.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Niveau.o Niveau.cpp

Cases.o: Cases.cpp Cases.h \
		Application.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cases.o Cases.cpp

Action.o: Action.cpp Action.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Action.o Action.cpp

Conteneur.o: Conteneur.cpp Conteneur.h \
		Action.h \
		Robot.h \
		Cases.h \
		Application.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Conteneur.o Conteneur.cpp

AppliMenu.o: AppliMenu.cpp AppliMenu.h \
		Application.h \
		Bouton.h \
		Text.h \
		ChangementFenetre.h \
		AppliChoixNiveau.h \
		AppliTableau.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		Niveau.h \
		AppliEditeur.h \
		CasesEditeur.h \
		AppliTransition.h \
		AppliChoixEdite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AppliMenu.o AppliMenu.cpp

Bouton.o: Bouton.cpp Bouton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Bouton.o Bouton.cpp

Text.o: Text.cpp Text.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Text.o Text.cpp

AppliChoixNiveau.o: AppliChoixNiveau.cpp AppliChoixNiveau.h \
		Application.h \
		Bouton.h \
		Text.h \
		ChangementFenetre.h \
		AppliMenu.h \
		AppliTableau.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		Niveau.h \
		AppliEditeur.h \
		CasesEditeur.h \
		AppliTransition.h \
		AppliChoixEdite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AppliChoixNiveau.o AppliChoixNiveau.cpp

ChangementFenetre.o: ChangementFenetre.cpp ChangementFenetre.h \
		AppliChoixNiveau.h \
		Application.h \
		Bouton.h \
		Text.h \
		AppliMenu.h \
		AppliTableau.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		Niveau.h \
		AppliEditeur.h \
		CasesEditeur.h \
		AppliTransition.h \
		AppliChoixEdite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ChangementFenetre.o ChangementFenetre.cpp

Robot.o: Robot.cpp Robot.h \
		Cases.h \
		Application.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Robot.o Robot.cpp

AppliEditeur.o: AppliEditeur.cpp AppliEditeur.h \
		Application.h \
		CasesEditeur.h \
		Text.h \
		Bouton.h \
		ChangementFenetre.h \
		AppliChoixNiveau.h \
		AppliMenu.h \
		AppliTableau.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		Niveau.h \
		AppliTransition.h \
		AppliChoixEdite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AppliEditeur.o AppliEditeur.cpp

CasesEditeur.o: CasesEditeur.cpp CasesEditeur.h \
		Application.h \
		Text.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CasesEditeur.o CasesEditeur.cpp

AppliTransition.o: AppliTransition.cpp AppliTransition.h \
		Application.h \
		Bouton.h \
		ChangementFenetre.h \
		AppliChoixNiveau.h \
		Text.h \
		AppliMenu.h \
		AppliTableau.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		Niveau.h \
		AppliEditeur.h \
		CasesEditeur.h \
		AppliChoixEdite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AppliTransition.o AppliTransition.cpp

AppliChoixEdite.o: AppliChoixEdite.cpp AppliChoixEdite.h \
		Application.h \
		Bouton.h \
		Text.h \
		ChangementFenetre.h \
		AppliChoixNiveau.h \
		AppliMenu.h \
		AppliTableau.h \
		Cases.h \
		Conteneur.h \
		Action.h \
		Robot.h \
		Niveau.h \
		AppliEditeur.h \
		CasesEditeur.h \
		AppliTransition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AppliChoixEdite.o AppliChoixEdite.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/opt/Tuto_1/bin/ || $(MKDIR) $(INSTALL_ROOT)/opt/Tuto_1/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/opt/Tuto_1/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/opt/Tuto_1/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/Tuto_1/bin/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:
