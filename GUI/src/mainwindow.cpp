#include "../lib/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setFixedSize(780, 320);

    ui->setupUi(this);

    //ui->textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
    //ui->textBrowser_2->setTextInteractionFlags(Qt::NoTextInteraction);

    QObject::connect(ui->actionV_lju, &QAction::triggered, this, &MainWindow::close);

    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}
