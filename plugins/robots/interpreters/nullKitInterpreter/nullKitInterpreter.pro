TEMPLATE = lib
CONFIG += plugin
CONFIG += c++11

DESTDIR = ../../../../bin/plugins/kitPlugins/

QT += widgets

OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .moc
UI_DIR = .ui

LIBS += -L../../../../bin -linterpreterBase

INCLUDEPATH += \
	../interpreterBase/include \
	../../../../ \
	$$PWD/../../../../qrgui/ \

HEADERS += \
	nullKitInterpreterInterface.h \

SOURCES += \
	nullKitInterpreterInterface.cpp \