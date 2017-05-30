TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
SOURCES += main.cpp \
    Application.cpp \
    Grille.cpp \
    Bouton.cpp \
    Actions.cpp \
    BoutonSimple.cpp \
    Robot.cpp \
    Proc.cpp \
    Cases.cpp \
    Menu.cpp \
    Hexabot.cpp \
    BarreAction.cpp \
    TinyXML2/tinyxml2.cpp \
    Level.cpp


include(deployment.pri)
qtcAddDeployment()

LIBS           += -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    Application.h \
    Grille.h \
    Bouton.h \
    Actions.h \
    BoutonSimple.h \
    Robot.h \
    Proc.h \
    Cases.h \
    Etats_Cases.h \
    Menu.h \
    Hexabot.h \
    Directions.h \
    TypeBouton.h \
    TypeAction.h \
    BarreAction.h \
    TinyXML2/tinyxml2.h \
    Level.h

