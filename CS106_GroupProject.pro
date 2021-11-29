QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbook.cpp \
    addmember.cpp \
    adminwindow.cpp \
    bookdisplay.cpp \
    checkoutbooks.cpp \
    customcheckoutbooks.cpp \
    librarysystems.cpp \
    login.cpp \
    main.cpp \
    memberinfo.cpp \
    memberwindow.cpp \
    overduebooks.cpp \
    returnbooks.cpp \
    viewbook.cpp \
    viewmember.cpp

HEADERS += \
    addbook.h \
    addmember.h \
    adminwindow.h \
    bookdisplay.h \
    checkoutbooks.h \
    customcheckoutbooks.h \
    librarysystems.h \
    login.h \
    memberinfo.h \
    memberwindow.h \
    overduebooks.h \
    returnbooks.h \
    viewbook.h \
    viewmember.h

FORMS += \
    addbook.ui \
    addmember.ui \
    adminwindow.ui \
    bookdisplay.ui \
    checkoutbooks.ui \
    customcheckoutbooks.ui \
    login.ui \
    memberwindow.ui \
    overduebooks.ui \
    returnbooks.ui \
    viewbook.ui \
    viewmember.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
