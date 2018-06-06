QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

HEADERS       = imageviewer.h \
    RSImage.h \
    dialogdispopt.h
SOURCES       = imageviewer.cpp \
                main.cpp \
    RSImage.cpp \
    dialogdispopt.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/imageviewer
INSTALLS += target

FORMS += \
    dialogdispopt.ui
