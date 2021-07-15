#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QImage>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_open_clicked()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home",
                                                       tr("Image Files (*.png *jpg *.bmp)"));
    QPixmap pic(filename);
    ui->label->setPixmap(pic.scaled(ui->label->size()));
    qDebug() << filename;
}
