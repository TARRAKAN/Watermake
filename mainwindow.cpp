#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QPainter>

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
    QImage img(filename);

    QPainter *painter = new QPainter(&img);
    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 100));
    painter->drawText(img.rect(), Qt::AlignCenter, "TEXT\n");
    QPixmap pic(QPixmap::fromImage(img));
    ui->label->setPixmap(pic.scaled(ui->label->size()));
    qDebug() << filename;
}
