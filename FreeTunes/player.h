#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include<QWebPage>
#include<QWebElement>
#include<QWebFrame>
#include "web.h"
#include "track.h"
#include <QList>
#include <QProcess>

namespace Ui {
class player;
}

class player : public QMainWindow
{
    Q_OBJECT

public:

    int pos1;
    int pos2;
    Web *webHelper;
    QProcess player_process;
    QList<Track *> trackList;

    explicit player(QWidget *parent = 0);
    ~player();

private slots:
    void on_btnSearch_clicked();

    void on_btnPlay_clicked();

    void html_received(QString html);

    void on_lineSearchBar_returnPressed();

    void play(QString Url);

    void stop();

    void on_btnStop_clicked();

private:
    Ui::player *ui;
};

#endif // PLAYER_H
