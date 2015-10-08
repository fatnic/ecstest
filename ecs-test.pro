TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-window -lsfml-system -lsfml-graphics

SOURCES += main.cpp \
    animator.cpp \
    assetmanager.cpp

HEADERS += \
    entity.hpp \
    entitymanager.hpp \
    spritecomponent.hpp \
    positioncomponent.hpp \
    animator.hpp \
    assetmanager.hpp \
    animatedcomponent.hpp \
    attachtomousecomponent.hpp \
    keyboardcontrolcomponent.hpp \
    velocitycomponent.hpp \
    gravitycomponent.hpp \
    rotationcomponent.hpp \
    singleton.hpp \
    healthcomponent.hpp \
    healthbarcomponent.hpp

