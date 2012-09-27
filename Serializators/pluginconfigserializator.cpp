#include "pluginconfigserializator.h"

PluginConfigSerializator::PluginConfigSerializator()
{

}

PluginInfo PluginConfigSerializator::loadPluginConfig(const QString &filename)
{
    QDomDocument xml;
    try
    {
        loadXmlSchema(":/xsd/xsd/pluginconfig.xsd");

        xml = loadXml(filename);

        if (!checkXml(xml))
        {
            throw Exception(Exception::BadXMLFile, QString("Bad XML file - " + filename));
        }
    }
    catch (const Exception &err)
    {
        throw;
    }

    QString title = xml.elementsByTagName("title").at(0).toElement().text();
    QString version = xml.elementsByTagName("version").at(0).toElement().text();
    QString description = xml.elementsByTagName("startCode").at(0).toElement().text();
    QString author = xml.elementsByTagName("author").at(0).toElement().text();
    QStringList codes;

    QDomNodeList units = xml.elementsByTagName("unit");

    for (int i = 0; i < units.length(); i++)
    {
        codes << (units.at(i).toElement().attribute("code"));
        codes << (units.at(i).toElement().elementsByTagName("title").at(0).toElement().text());
        codes << (units.at(i).toElement().elementsByTagName("practiceFile").at(0).toElement().text());
        codes << (units.at(i).toElement().elementsByTagName("testFile").at(0).toElement().text());
    }

    PluginInfo info(title, author, version, description, codes);
    return info;
}

QDomDocument PluginConfigSerializator::getPluginConfigXML(PluginInfo info)
{
    resultXml.clear();

    QDomElement root = resultXml.createElement("root");
    resultXml.appendChild(root);

    QDomElement globals = resultXml.createElement("globals");
    QDomElement title = resultXml.createElement("title");
    title.appendChild(resultXml.createTextNode(info.getTitle()));
    QDomElement version = resultXml.createElement("version");
    version.appendChild(resultXml.createTextNode(info.getVersion()));
    QDomElement startCode = resultXml.createElement("startCode");
    startCode.appendChild(resultXml.createTextNode(info.getDescription()));
    QDomElement author = resultXml.createElement("author");
    author.appendChild(resultXml.createTextNode(info.getAuthor()));

    globals.appendChild(title);
    globals.appendChild(version);
    globals.appendChild(startCode);
    globals.appendChild(author);
    root.appendChild(globals);

    for(int i = 0; i < info.getCodes().length(); i += 4)
    {
        QDomElement unit = resultXml.createElement("unit");
        unit.setAttribute("code", info.getCodes().at(i));

        QDomElement titleUnit = resultXml.createElement("title");
        titleUnit.appendChild(resultXml.createTextNode(info.getCodes().at(i + 1)));

        QDomElement practiceFile = resultXml.createElement("practiceFile");
        practiceFile.appendChild(resultXml.createTextNode(info.getCodes().at(i + 2)));

        QDomElement testFile = resultXml.createElement("testFile");
        testFile.appendChild(resultXml.createTextNode(info.getCodes().at(i + 3)));

        unit.appendChild(titleUnit);
        unit.appendChild(practiceFile);
        unit.appendChild(testFile);
        root.appendChild(unit);
    }
    return resultXml;
}

void PluginConfigSerializator::savePluginConfig(PluginInfo info, const QString &filename) throw (Exception)
{
    QFile xmlFile(filename);
    if (!xmlFile.open(QIODevice::WriteOnly))
    {
        throw Exception(Exception::FileOperationError, QString("Couldn't open file - " + filename));
    }
    xmlFile.write(getPluginConfigXML(info).toByteArray());
    xmlFile.close();
}


