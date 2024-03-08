#include "objfileloader.h"
#include "./ui_objfileloader.h"

ObjFileLoader::ObjFileLoader(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ObjFileLoader)
{
    ui->setupUi(this);
}

ObjFileLoader::~ObjFileLoader()
{
    delete ui;
}
