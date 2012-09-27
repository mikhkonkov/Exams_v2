#include "plugininfo.h"

PluginInfo::PluginInfo()
{
}

QString PluginInfo::getAuthor()
{
    return author;
}

QStringList PluginInfo::getCodes()
{
    return codes;
}

QString PluginInfo::getDescription()
{
    return description;
}

QString PluginInfo::getTitle()
{
    return title;
}

QString PluginInfo::getVersion()
{
    return version;
}

