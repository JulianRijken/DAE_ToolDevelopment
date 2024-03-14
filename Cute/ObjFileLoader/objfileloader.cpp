#include "objfileloader.h"
#include "./ui_objfileloader.h"

#include <QFileDialog>
#include <QVector3D>

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

void ObjFileLoader::on_Open_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Wavefront obj"));

    if(filePath.isEmpty())
        return;

    QFile file{filePath};

    if(not file.open(QIODeviceBase::ReadOnly))
        return;

    QVector<QVector3D> verticies;
    QVector<QVector4D> indices;


    QTextStream fileText{&file};
    while(not fileText.atEnd())
    {
        QString line = fileText.readLine().trimmed();
        QStringList lineParts = line.split(QRegularExpression("\\s+"));

        if (lineParts[0] == "#")
            continue;

        if (lineParts[0] == "v") // Vertices
        {
            verticies.push_back({ lineParts[1].toFloat(), lineParts[2].toFloat(), lineParts[3].toFloat() });
        }

        if (lineParts[0] == "f") // Vertices
        {
            indices.push_back({ lineParts[1].toFloat(), lineParts[2].toFloat(), lineParts[3].toFloat(), lineParts[4].toFloat() });
        }
    }

    file.close(); // bye :)


    auto vector3DToString = [](const QVector3D& value) -> QString
    {
        return "(" +
               QString::number(value.x()) + ", " +
               QString::number(value.y()) + ", " +
               QString::number(value.z()) + ")";
    };

    auto vector4DToString = [](const QVector4D& value) -> QString
    {
        return "(" +
               QString::number(value.x()) + ", " +
               QString::number(value.y()) + ", " +
               QString::number(value.z()) + ", " +
               QString::number(value.w()) + ")";
    };

    //for (size_t i = 0; i < indices.size(); i++)
    //{
    //    int insertedRow = ui->tableWidget->rowCount();
    //    ui->tableWidget->insertRow(insertedRow);

    //    ui->tableWidget->setItem(insertedRow,0,new QTableWidgetItem(vector3DToString(verticies[i])));
    //    ui->tableWidget->setItem(insertedRow,0,new QTableWidgetItem(vector4DToString(indices[i])));
    //}

    for (const QVector4D& face : indices) {
        auto addRow = [&](uint fakeIndex) -> void {
            auto realIndex = fakeIndex - 1;

            int insertedRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(insertedRow);

            ui->tableWidget->setItem(insertedRow,0,new QTableWidgetItem(QString::number(realIndex)));
            ui->tableWidget->setItem(insertedRow,1,new QTableWidgetItem(vector3DToString(verticies[realIndex])));
        };

        addRow(face.x()); addRow(face.y()); addRow(face.z()); addRow(face.w());
    }
}
