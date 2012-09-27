#ifndef PLUGINCONFIGSERIALIZATOR_H
#define PLUGINCONFIGSERIALIZATOR_H

#include "../Plugins/plugininfo.h"
#include "../DataClasses/dataclasses.h"
#include "../DataClasses/exception.h"
#include "abstractserializator.h"
#include "fieldschecker.h"

class PluginConfigSerializator : public AbstractSerializator
{
private:
    QDomDocument getPluginConfigXML(PluginInfo info);

public:
    PluginConfigSerializator();

    PluginInfo loadPluginConfig(const QString &filename);
    void savePluginConfig(PluginInfo info, const QString &filename) throw (Exception);

};

#endif // PLUGINCONFIGSERIALIZATOR_H
