#include "web.h"

Web::Web()
{
    networkAccessManager = new QNetworkAccessManager(this);
}

Web::~Web()
{
    delete networkAccessManager;
    delete networkRequest;
}

void Web::finished()
{

    qDebug() << networkReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    emit htmlReceived(networkReply->readAll());
    networkReply->deleteLater();
}

void Web::getHTML(QString url)
{
    networkRequest = new QNetworkRequest(QUrl(url));
    networkRequest->setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (X11; Linux i586; rv:31.0) Gecko/20100101 Firefox/31.0");

    networkReply = networkAccessManager->get(*networkRequest);

    connect(networkReply, SIGNAL(finished()), this, SLOT(finished()));
}




