#! [0]
HEADERS     = calculatorform.h \
    objviewerform.h
#! [0] #! [1]
FORMS       = calculatorform.ui \
    objviewerform.ui
#! [1]
SOURCES     = calculatorform.cpp \
              main.cpp \
              objviewerform.cpp
QT += widgets

target.path = $$[QT_INSTALL_EXAMPLES]/designer/calculatorform
INSTALLS += target
