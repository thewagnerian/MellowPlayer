"""
**MellowPlayer** is a free and cross-platform desktop application that runs a
web interface of **cloud music services** in its own window and provides
**integration with your desktop** (multimedia keys, system tray,
notifications and more).

"""
import sip
# require the variant api to be able to send the proper data types over DBUS
# (if we do not set that property, there is no way (AFAIK) to send a string list
# as it is implicitely converted t QVariantList (Dbus/Mpris except a
# QStringList not a QVariantList)
sip.setapi("QVariant", 1)

__version__ = '1.0a1'