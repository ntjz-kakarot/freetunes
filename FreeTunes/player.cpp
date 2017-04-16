#include "player.h"
#include "ui_player.h"


player::player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::player)
{
    ui->setupUi(this);
    this->setWindowTitle("FreeTunes Player");

    // Requesting the html.
    webHelper = new Web();
    connect(webHelper, SIGNAL(htmlReceived(QString)), this, SLOT(html_received(QString)));

    ui->searchTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

player::~player()
{
    delete ui;
}

void player::on_btnSearch_clicked()
{
    ui->btnSearch->setText("Searching..");
    webHelper->getHTML("https://pleer.com/mobile/search?q=" + ui->lineSearchBar->text());
}


void player::on_btnPlay_clicked()
{
    if (ui->btnPlay->toolTip() == "Play")
    {
        ui->btnPlay->setToolTip("Pause");
        QIcon pauseIcon("btnPause.png");
        ui->btnPlay->setIcon(pauseIcon);

        play(trackList.at(0)->getUrl());    // Plays the first track in TrackList. If doesn't play run: sudo apt-get install libav-tools

    }
    else
    {
        ui->btnPlay->setToolTip("Play");
        QIcon playIcon("btnPlay.png");
        ui->btnPlay->setIcon(playIcon);
    }


}


void player::html_received(QString html)
{

    ui->searchTable->clearContents();                                   // removes previous search results

    Track * track;                                              // object to store details of a track

    // emptying track trackList if previously added
    while (!trackList.isEmpty()){
        track = trackList.first();
        trackList.removeFirst();
        delete track;   // freeing object's memory
    }


    // Iterates through the html to make track objects

    int lowerBound = html.lastIndexOf("<li class=\"track\"");   // The position that track search stops
    pos1 = 0;                                                   // The position that track search begins

    while (pos1 < lowerBound){


        pos1 = html.indexOf("<li class=\"track\"", pos1);
        pos2 = html.indexOf("<li class=\"i-close\">", pos1);
        QString raw_track_data = html.mid(pos1, pos2-pos1);

        track =  new Track(raw_track_data);     // making a track object and storing track's information
        trackList.append(track);                // adding the track to the trackList for later use.

        pos1 = pos2;                            // update the search position to the next track

        // Adding tarck to the table
        int current_row =  trackList.count() - 1;

        ui->searchTable->insertRow(ui->searchTable->rowCount());
        ui->searchTable->setItem(current_row ,0 ,new QTableWidgetItem(track->getTitle()));
        ui->searchTable->setItem(current_row,1 ,new QTableWidgetItem(track->getArtist()));
        ui->searchTable->setItem(current_row,3 ,new QTableWidgetItem(track->getFileSize()));

        // printing tack data
        qDebug() << track->getArtist();
        qDebug() << track->getTitle();
        qDebug() << track->getFileSize();
        qDebug() << track->getUrl();
        qDebug() << "\n";


    }


}



void player::on_lineSearchBar_returnPressed()
{
    on_btnSearch_clicked();
}

void player::play(QString Url)
{

    QString command = "avplay -nodisp " + Url;
    player_process.start(command);

}

void player::stop()
{
    player_process.kill();
}

void player::on_btnStop_clicked()
{
    stop();
}
