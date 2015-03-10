#include "addtorrentwindow.h"
#include "ui_addtorrentwindow.h"
#include <QFileDialog>
#include <QMessageBox>

AddTorrentWindow::AddTorrentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTorrentWindow)
{
    ui->setupUi(this);
}

AddTorrentWindow::~AddTorrentWindow()
{
    delete ui;
}

void AddTorrentWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "",
                                                    tr("Torrent Files (*.torrent);;All Files (*.*)")
                                                    );
    ui->torrentFileInputBox->setText(fileName);
}

void AddTorrentWindow::on_buttonBox_accepted()
{
    QFile torrentFile(ui->torrentFileInputBox->text());
    torrent = new Torrent(torrentFile);
}

Torrent* AddTorrentWindow::getTorrent()
{
    return torrent;
}
