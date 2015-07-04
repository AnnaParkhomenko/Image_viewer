#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Image Viewer");
    ui->statusBar->addWidget(ui->label);
    wgt = new Painter();
    ui->scrollArea->setWidget(wgt);
    ui->scrollArea->setAlignment(Qt::AlignCenter);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    setCentralWidget(ui->scrollArea);
    ui->mainToolBar->addWidget(ui->ZoomIn);
    ui->mainToolBar->addWidget(ui->ZoomOut);
}

void MainWindow::on_actionOpen_triggered()
{
    OpenFile open;
    open.setWindowFlags(Qt::WindowFullscreenButtonHint);
    open.exec();

    wgt->fileName = open.fname;
    wgt->factor = 1.0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionZoomIn_triggered()
{
    wgt->factor = 1.11 * wgt->factor;
}

void MainWindow::on_actionZoomOut_triggered()
{;
    wgt->factor = 0.9 *wgt->factor;

}

void MainWindow::on_actionNormalSize_triggered()
{
    wgt->factor = 1.0;
}

void MainWindow::on_ZoomIn_clicked()
{
    on_actionZoomIn_triggered();
}

void MainWindow::on_ZoomOut_clicked()
{
    on_actionZoomOut_triggered();
}
