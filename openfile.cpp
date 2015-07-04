#include "openfile.h"
#include "ui_openfile.h"
#include <QWidget>
#include <QDialog>
#include <QFileSystemModel>


OpenFile::OpenFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenFile)
{
    ui->setupUi(this);
    this->setWindowTitle("Открыть изображение");

    lDir = new QFileSystemModel(this);

    lDir->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    lDir->setRootPath("/home");

    ui->listView->setModel(lDir);
    QModelIndex idx = lDir->index("/home/anna");
    ui->listView->setRootIndex(idx);
}

OpenFile::~OpenFile()
{
    delete ui;
}
void OpenFile::on_listView_clicked(const QModelIndex &index)
{


    fname = lDir->filePath(index);
    tDir = new QFileSystemModel(this);
    tDir->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    tDir->setRootPath(fname);
    QModelIndex idx1 = tDir->index(fname);
    ui->treeView->setModel(tDir);
    ui->treeView->setRootIndex(idx1);
}

void OpenFile::on_treeView_clicked(const QModelIndex &index)
{

    QRegExp exp("([a-zA-Z0-9_ \\:\\-\\.])+\\.(JPG|png|jpg|gif|jpeg)");
    fname = tDir->filePath(index);
QString name = tDir->fileInfo(index).fileName();

    if (tDir->isDir(index))
    {
        ui->treeView->setModel(tDir);
        ui->treeView->setRootIndex(index);
    }
    if (exp.exactMatch(name))
    {
        ui->label->setText(name);
        int size = (tDir->fileInfo(index).size()/1024);
        if ( (size/1024) < 1)
            ui->label_2->setText(QString::number(size)+"Kb");
        else
        {
            size/=1024;
            ui->label_2->setText(QString::number(size)+"Mb");
        }

     QImage img(fname);
     QImage img2 = img.scaled(200,200, Qt::KeepAspectRatio);
     QPalette* pal = new QPalette();
     pal->setBrush(ui->widget->backgroundRole(), QBrush(img2));
     ui->widget->setPalette(*pal);

     ui->widget->setAutoFillBackground(true);
     ui->widget->setFixedSize(img2.width(), img2.height());
    }
}

void OpenFile::on_open_clicked()
{
    if (fname.isEmpty())
        ;
    else
    close();
}

void OpenFile::on_treeView_doubleClicked(const QModelIndex &index)
{
    if (fname.isEmpty())
        ;
    else
    close();
}
