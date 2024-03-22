#ifndef OBJFILELOADER_H
#define OBJFILELOADER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ObjFileLoader;
}
QT_END_NAMESPACE

class ObjFileLoader : public QMainWindow
{
    Q_OBJECT

public:
    ObjFileLoader(QWidget *parent = nullptr);
    ~ObjFileLoader();

private slots:
    void on_Open_triggered(void);


private:
    Ui::ObjFileLoader *ui;

};
#endif // OBJFILELOADER_H
