TEMPLATE = app
TARGET = ProprietaireGUI
QT += core \
    gui
HEADERS += supprimervehicule.h \
    saisiecamion.h \
    saisievehiculepromenade.h \
    proprietairegui.h
SOURCES += supprimervehicule.cpp \
    saisiecamion.cpp \
    saisievehiculepromenade.cpp \
    main.cpp \
    proprietairegui.cpp
FORMS += supprimervehicule.ui \
    saisiecamion.ui \
    saisievehiculepromenade.ui \
    proprietairegui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
