#ifndef ADDTORRENTWINDOW_H
#define ADDTORRENTWINDOW_H

#include "torrent.h"
#include <QDialog>

namespace Ui {
class AddTorrentWindow;
}

class AddTorrentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddTorrentWindow(QWidget *parent = 0);
    ~AddTorrentWindow();
    Torrent* getTorrent();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::AddTorrentWindow *ui;
    Torrent* torrent;
};

#endif // ADDTORRENTWINDOW_H
