#ifndef TRACK_H
#define TRACK_H

#include <QString>
#include <QDebug>

class Track
{
public:

    int pos1;
    int pos2;
    QString html;

    Track(QString track_html);

    QString getTitle();

    QString getArtist();

    QString getUrl();

    QString getFileSize();

};

#endif // TRACK_H
