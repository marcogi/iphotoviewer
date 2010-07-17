TEMPLATE = app
TARGET = iPhotoViewer
QT += core \
    gui \
    xml
HEADERS += model/Album.h \
    model/PhotoModel.h \
    model/Photo.h \
    iphotoviewer.h
SOURCES += model/Album.cpp \
    model/PhotoModel.cpp \
    model/Photo.cpp \
    main.cpp \
    iphotoviewer.cpp
FORMS += iphotoviewer.ui
RESOURCES += 
