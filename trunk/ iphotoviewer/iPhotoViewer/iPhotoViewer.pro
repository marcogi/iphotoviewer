TEMPLATE = app
TARGET = iPhotoViewer
QT += core \
    gui \
    xml
HEADERS += widgets/ClickLabel.h \
    widgets/photoviewer.h \
    widgets/photoframe.h \
    widgets/photopanel.h \
    model/Roll.h \
    model/BaseModel.h \
    model/BaseList.h \
    model/Album.h \
    model/Photo.h \
    iphotoviewer.h
SOURCES += widgets/ClickLabel.cpp \
    widgets/photoviewer.cpp \
    widgets/photoframe.cpp \
    widgets/photopanel.cpp \
    model/Roll.cpp \
    model/BaseModel.cpp \
    model/BaseList.cpp \
    model/Album.cpp \
    model/Photo.cpp \
    main.cpp \
    iphotoviewer.cpp
FORMS += widgets/photoviewer.ui \
    widgets/photoframe.ui \
    widgets/photopanel.ui \
    iphotoviewer.ui
RESOURCES += 
