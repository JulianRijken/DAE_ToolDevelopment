#ifndef OBJVIEWERFORM_H
#define OBJVIEWERFORM_H

#include <QMainWindow>

namespace Ui
{
    class ObjViewerForm;
}

class ObjViewerForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ObjViewerForm(QWidget *parent = nullptr);
    ~ObjViewerForm();

private:
    Ui::ObjViewerForm *ui;
};

#endif // OBJVIEWERFORM_H
