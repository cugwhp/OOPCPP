QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

HEADERS       = imageviewer.h \
    RSImage.h \
    dialogdispopt.h \
    dialoginfo.h \
    treeitem.h \
    treemodel.h \
    mainwindow.h
SOURCES       = imageviewer.cpp \
                main.cpp \
    RSImage.cpp \
    dialogdispopt.cpp \
    dialoginfo.cpp \
    treeitem.cpp \
    treemodel.cpp \
    mainwindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/imageviewer
INSTALLS += target

FORMS += \
    dialogdispopt.ui \
    dialoginfo.ui \
    mainwindow.ui
