CONFIG += ordered

TEMPLATE = subdirs

SUBDIRS += \
    FinanceExamples \
    QtYahooFinance

FinanceExamples.depends = QtYahooFinance
