#include "addtorrentwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appconfig.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    AppConfig config;

    addTorrentWindow = new AddTorrentWindow();
    ui->setupUi(this);

    setWindowTitle(QString::fromStdString(config.getWithDefault("windowTitle", "BitTorrent Client")));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addTorrentWindow;
}

void MainWindow::on_actionAdd_Torrent_triggered()
{
    addTorrentWindow->show();
}
