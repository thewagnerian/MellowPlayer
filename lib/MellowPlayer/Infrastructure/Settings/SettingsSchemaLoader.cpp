#include <QtCore/QFile>
#include "SettingsSchemaLoader.hpp"

USING_MELLOWPLAYER_NAMESPACE(Infrastructure)

QJsonDocument SettingsSchemaLoader::load() const {
    QFile jsonFile(":/MellowPlayer/Application/Settings/schema.json");
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}
