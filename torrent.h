#ifndef TORRENT_H
#define TORRENT_H

#include <QByteArray>
#include <QFile>

class Torrent
{
public:
    Torrent(const QFile& fromFile);
    Torrent(const QByteArray& fromByteArray);
    Torrent(const std::string& fromStdString);
    Torrent(const QString& fromQString);
    ~Torrent();
private:
    void init(const std::string& rawData);
};

#endif // TORRENT_H
