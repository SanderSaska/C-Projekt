#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"
#include "../lib/valikuteleht.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setFixedSize(780, 320);

    ui->setupUi(this);

    //ui->textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
    //ui->textBrowser_2->setTextInteractionFlags(Qt::NoTextInteraction);

    QObject::connect(ui->actionV_lju, &QAction::triggered, this, &MainWindow::close);

    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::openValikuteleht);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::openValikuteleht()
{
    ValikuteLeht *valikuteleht = new ValikuteLeht(this);
    ui->centralwidget->close();
    ui->menubar->close();
    valikuteleht->show();
    valikuteleht->setFixedSize(780, 300);
}
