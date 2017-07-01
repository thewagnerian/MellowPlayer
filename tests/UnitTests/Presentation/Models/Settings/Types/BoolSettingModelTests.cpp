#include "catch.hpp"
#include "DI.hpp"
#include <MellowPlayer/Presentation/Models/Settings/Types/BoolSettingModel.hpp>
#include <QtTest/QSignalSpy>

USING_MELLOWPLAYER_NAMESPACE(Application)
USING_MELLOWPLAYER_NAMESPACE(Presentation)

TEST_CASE("BoolSettingModelTests") {
    ScopedScope scope;
    auto injector = getTestInjector(scope);
    Settings& settings = injector.create<Settings&>();
    Setting& setting = settings.get(SettingKey::NOTIFICATIONS_ENABLED);
    BoolSettingModel model(setting, nullptr);
    QSignalSpy spy(&model, SIGNAL(valueChanged()));

    SECTION("setValue") {
        REQUIRE(model.getValue());
        REQUIRE(spy.count() == 0);
        model.setValue(false);
        REQUIRE(!model.getValue());
        REQUIRE(spy.count() == 1);
        model.setValue(true);
    }

    SECTION("QML Component looks valid") {
        REQUIRE(model.getQmlComponent().toLower().contains("bool"));
    }
}

