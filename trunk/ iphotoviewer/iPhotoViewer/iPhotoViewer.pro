TEMPLATE = app
TARGET = iPhotoViewer
QT += core \
    gui \
    xml
HEADERS += model/Roll.h \
    model/BaseModel.h \
    model/BaseList.h \
    model/Album.h \
    model/Photo.h \
    iphotoviewer.h
SOURCES += model/Roll.cpp \
    model/BaseModel.cpp \
    model/BaseList.cpp \
    model/Album.cpp \
    model/Photo.cpp \
    main.cpp \
    iphotoviewer.cpp
FORMS += iphotoviewer.ui
RESOURCES += 
