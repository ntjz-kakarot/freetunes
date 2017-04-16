#ifndef WEB_H
#define WEB_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>



class Web : public QObject
{    
Q_OBJECT
public:
    QNetworkAccessManager *networkAccessManager;
    QNetworkReply *networkReply;
    QNetworkRequest *networkRequest;

public:
    Web();
    ~Web();
    void getHTML(QString url);

signals:
    void htmlReceived(QString HTML);

public slots:
    void finished();


};

#endif // WEB_H
