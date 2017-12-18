#############################################################################
# Makefile for building: gaoyuan
# Generated by qmake (2.01a) (Qt 4.8.7) on: Tue Dec 19 00:27:23 2017
# Project:  gaoyuan.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile gaoyuan.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtNetwork -lQtCore -lpthread 
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
		mainpanal.cpp \
		devicebutton.cpp \
		nodedetail.cpp \
		work_thread.cpp \
		mainwindow.cpp \
		devnodesetting.cpp moc_mainpanal.cpp \
		moc_devicebutton.cpp \
		moc_nodedetail.cpp \
		moc_work_thread.cpp \
		moc_mainwindow.cpp \
		moc_devnodesetting.cpp \
		qrc_res.cpp
OBJECTS       = main.o \
		mainpanal.o \
		devicebutton.o \
		nodedetail.o \
		work_thread.o \
		mainwindow.o \
		devnodesetting.o \
		moc_mainpanal.o \
		moc_devicebutton.o \
		moc_nodedetail.o \
		moc_work_thread.o \
		moc_mainwindow.o \
		moc_devnodesetting.o \
		qrc_res.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		gaoyuan.pro
QMAKE_TARGET  = gaoyuan
DESTDIR       = 
TARGET        = gaoyuan

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

Makefile: gaoyuan.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtNetwork.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile gaoyuan.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtNetwork.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile gaoyuan.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/gaoyuan1.0.0 || $(MKDIR) .tmp/gaoyuan1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/gaoyuan1.0.0/ && $(COPY_FILE) --parents mainpanal.h devicebutton.h nodedetail.h work_thread.h mainwindow.h devnodesetting.h gydata.h .tmp/gaoyuan1.0.0/ && $(COPY_FILE) --parents res.qrc .tmp/gaoyuan1.0.0/ && $(COPY_FILE) --parents main.cpp mainpanal.cpp devicebutton.cpp nodedetail.cpp work_thread.cpp mainwindow.cpp devnodesetting.cpp .tmp/gaoyuan1.0.0/ && (cd `dirname .tmp/gaoyuan1.0.0` && $(TAR) gaoyuan1.0.0.tar gaoyuan1.0.0 && $(COMPRESS) gaoyuan1.0.0.tar) && $(MOVE) `dirname .tmp/gaoyuan1.0.0`/gaoyuan1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/gaoyuan1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainpanal.cpp moc_devicebutton.cpp moc_nodedetail.cpp moc_work_thread.cpp moc_mainwindow.cpp moc_devnodesetting.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainpanal.cpp moc_devicebutton.cpp moc_nodedetail.cpp moc_work_thread.cpp moc_mainwindow.cpp moc_devnodesetting.cpp
moc_mainpanal.cpp: devicebutton.h \
		nodedetail.h \
		gydata.h \
		devnodesetting.h \
		work_thread.h \
		mainpanal.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) mainpanal.h -o moc_mainpanal.cpp

moc_devicebutton.cpp: nodedetail.h \
		gydata.h \
		devnodesetting.h \
		devicebutton.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) devicebutton.h -o moc_devicebutton.cpp

moc_nodedetail.cpp: gydata.h \
		nodedetail.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) nodedetail.h -o moc_nodedetail.cpp

moc_work_thread.cpp: work_thread.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) work_thread.h -o moc_work_thread.cpp

moc_mainwindow.cpp: devnodesetting.h \
		mainpanal.h \
		devicebutton.h \
		nodedetail.h \
		gydata.h \
		work_thread.h \
		mainwindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_devnodesetting.cpp: devnodesetting.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) devnodesetting.h -o moc_devnodesetting.cpp

compiler_rcc_make_all: qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_res.cpp
qrc_res.cpp: res.qrc \
		res/red.png \
		res/green.png \
		res/blue.png \
		res/panel.png \
		res/skin.qss \
		res/yellow.png
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name res res.qrc -o qrc_res.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		devnodesetting.h \
		mainpanal.h \
		devicebutton.h \
		nodedetail.h \
		gydata.h \
		work_thread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainpanal.o: mainpanal.cpp mainpanal.h \
		devicebutton.h \
		nodedetail.h \
		gydata.h \
		devnodesetting.h \
		work_thread.h \
		devicenode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainpanal.o mainpanal.cpp

devicebutton.o: devicebutton.cpp devicebutton.h \
		nodedetail.h \
		gydata.h \
		devnodesetting.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o devicebutton.o devicebutton.cpp

nodedetail.o: nodedetail.cpp nodedetail.h \
		gydata.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o nodedetail.o nodedetail.cpp

work_thread.o: work_thread.cpp work_thread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o work_thread.o work_thread.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		devnodesetting.h \
		mainpanal.h \
		devicebutton.h \
		nodedetail.h \
		gydata.h \
		work_thread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

devnodesetting.o: devnodesetting.cpp devnodesetting.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o devnodesetting.o devnodesetting.cpp

moc_mainpanal.o: moc_mainpanal.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainpanal.o moc_mainpanal.cpp

moc_devicebutton.o: moc_devicebutton.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_devicebutton.o moc_devicebutton.cpp

moc_nodedetail.o: moc_nodedetail.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_nodedetail.o moc_nodedetail.cpp

moc_work_thread.o: moc_work_thread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_work_thread.o moc_work_thread.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_devnodesetting.o: moc_devnodesetting.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_devnodesetting.o moc_devnodesetting.cpp

qrc_res.o: qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_res.o qrc_res.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

