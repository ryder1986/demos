HEADERS += \
    player.h \
    tools.h

SOURCES += \
    main.cpp \
    player.cpp \
    tools.cpp

#QMAKE_CXXFLAGS+=-std=c++11
win32{
CVPATH="opencv-vs2013-x86"
INCLUDEPATH +="$$CVPATH/include"
LIBS+="$$CVPATH\lib/opencv_core249d.lib"
LIBS+="$$CVPATH\lib\opencv_highgui249d.lib"
LIBS+="$$CVPATH\lib\opencv_ml249d.lib"
LIBS+="$$CVPATH\lib\opencv_video249d.lib"
LIBS+="$$CVPATH\lib\opencv_imgproc249d.lib"
LIBS+="$$CVPATH\lib\opencv_objdetect249d.lib"
#LIBS+="-L$$CVPATH/x86/vc12/bin/ -lopencv_core249d "
}
#QMAKE_CXXFLAGS+=-std=c++11
#QMAKE_LFLAGS+="-Wl,--rpath=E://opencv-libs"
#LIBS +=-LE://opencv-lib -lopencv_core249d
#PATH=$$(PATH):"E://opencv-libs"

#DLLDESTDIR+="E:\opencv-libs"
#DESTDIR+="E:\opencv-libs"
unix{
CVPATH="../res"
QMAKE_CXXFLAGS+="-std=c++11"
INCLUDEPATH +="$$CVPATH/include"
#LIBS+=-L$$CVPATH/lib/  -lopencv_core  -lopencv_highgui  -lopencv_objdetect -lopencv_imgproc -lopencv_ml -lopencv_video
#LIBS += -lX11 -L/root/sources/opencv-2.4.9/build/__install/lib/  -lopencv_core  -lopencv_highgui  -lopencv_objdetect -lopencv_imgproc -lopencv_ml -lopencv_video

}
