TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra

LIBS           += -lsfml-graphics -lsfml-window -lsfml-system


SOURCES += main.cpp \
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

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Application.h \
    AppliTableau.h \
    Niveau.h \
    Cases.h \
    Action.h \
    Conteneur.h \
    AppliMenu.h \
    Bouton.h \
    Text.h \
    AppliChoixNiveau.h \
    ChangementFenetre.h \
    Robot.h \
    AppliEditeur.h \
    CasesEditeur.h \
    AppliTransition.h \
    AppliChoixEdite.h
