#ifndef PLUGININFO_H
#define PLUGININFO_H

#include <QString>
#include <QStringList>

class PluginInfo
{
private:
    QString title;
    QString author;
    QString version;
    QString description;
    QStringList codes;

public:
    PluginInfo();
    PluginInfo(QString _title, QString _author, QString _version, QString _description, QStringList _codes)
        :  title(_title), author(_author), version(_version), description(_description), codes(_codes) {}

    QString getTitle();
    QString getAuthor();
    QString getVersion();
    QString getDescription();
    QStringList getCodes();

};

#endif // PLUGININFO_H
