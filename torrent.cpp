#include "torrent.h"
#include <QMessageBox>

Torrent::Torrent(const QFile& fromFile)
{
    // we actually open the file a second time here so we can guarantee const-ness of the passed-in file
    QFile torrentFile(fromFile.fileName());
    QByteArray torrentFileRaw;
    if(torrentFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        while(!torrentFile.atEnd()) {
            QByteArray torrentLine = torrentFile.readLine();
            torrentFileRaw.append(torrentLine);
        }
        init(torrentFileRaw.toStdString());
    } else {
        // TODO: break these strings out so they can be localised
        QMessageBox::warning(NULL, "File not found", "I couldn't find the file you asked me for.  It's cute that you're typing it in manually, but the 'browse' button is pretty resistant to this kind of error. :)");
    }
}

Torrent::Torrent(const QByteArray& fromByteArray)
{
    init(fromByteArray.toStdString());
}

Torrent::Torrent(const std::string& fromStdString)
{
    init(fromStdString);
}

Torrent::Torrent(const QString& fromQString)
{
    init(fromQString.toStdString());
}

Torrent::~Torrent()
{

}

void Torrent::init(const std::string &rawData)
{

}
