#ifndef WEBSERVICEAPI_GLOBAL_H
#define WEBSERVICEAPI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WEBSERVICEAPI_LIBRARY)
#  define WEBSERVICEAPISHARED_EXPORT Q_DECL_EXPORT
#else
#  define WEBSERVICEAPISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WEBSERVICEAPI_GLOBAL_H
