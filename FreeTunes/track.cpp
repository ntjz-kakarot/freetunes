#include "track.h"



Track::Track(QString track_html)
{

    html = track_html;

}



QString Track::getTitle()
{
    pos1 = html.indexOf("<span class=\"title\">") + 20;
    pos2 = html.indexOf("</span>", pos1);
    return html.mid(pos1, pos2-pos1);
}


QString Track::getArtist()
{
    pos1 = html.indexOf("<span class=\"artist\">") + 21;
    pos2 = html.indexOf("</span>", pos1);
    return html.mid(pos1, pos2-pos1);
}


QString Track::getUrl()
{
    pos1 = html.indexOf("<li class=\"i-download\"><a href=") + 32;
    pos2 = html.indexOf("\">", pos1);
    return html.mid(pos1, pos2-pos1);
}


QString Track::getFileSize()
{
    pos1 = html.indexOf("<div class=\"specs\">") + 20;
    pos2 = html.indexOf(",\n", pos1);
    return html.mid(pos1, pos2-pos1).trimmed();
}



