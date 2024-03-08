#include "objviewerform.h"
#include "ui_objviewerform.h"

ObjViewerForm::ObjViewerForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ObjViewerForm)
{
    ui->setupUi(this);
}

ObjViewerForm::~ObjViewerForm()
{
    delete ui;
}
