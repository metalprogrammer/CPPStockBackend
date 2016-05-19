TEMPLATE = subdirs
SUBDIRS += \
    BackEndApplication \
    JsonWriter \
    QTHttpGet \
    QtYahooFinanceLib \
    MiscHelpers \
    qhttpserver \
    QtWebServiceApi

QtYahooFinanceLib.depends = QTHttpGet
QtWebServiceApi.depends = qhttpserver
BackEndApplication.depends = QtYahooFinanceLib QtWebServiceApi
