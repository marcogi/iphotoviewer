TEMPLATE = app
TARGET = iPhotoViewer
QT += core \
    gui \
    xml
HEADERS += model/IPhotoPhotos.h \
    iphotoviewer.h
SOURCES += model/IPhotoPhotos.cpp \
    main.cpp \
    iphotoviewer.cpp
FORMS += iphotoviewer.ui
RESOURCES += 
