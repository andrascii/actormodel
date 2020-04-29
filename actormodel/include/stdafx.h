#pragma once

#define _SCL_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#pragma warning(disable:4127)
#pragma warning(disable:745)
#pragma warning(disable:749)
#pragma warning(disable:333)
#pragma warning(disable:317)
#pragma warning(disable:597)
#pragma warning(disable:4251)
#pragma warning(disable:4702)
#pragma warning(disable:4456)
#pragma warning(disable:5054)

#define CHECK_LICENSE
// #define ENABLE_SCREENSHOTS

//
// Qt
//
#include <QThread>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTableView>
#include <QTextCodec>
#include <QAbstractListModel>
#include <QMetaObject>
#include <QMetaMethod>
#include <QMetaType>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkProxy>
#include <QtNetwork/QAuthenticator>
#include <QTimer>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMutex>
#include <QMutexLocker>
#include <QReadWriteLock>
#include <QSemaphore>
#include <QWaitCondition>
#include <QQueue>
#include <QDebug>
#include <QProcess>
#include <QDateTime>
#include <QAbstractNetworkCache>
#include <QStringBuilder>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QBuffer>
#include <QPointer>
#include <QSharedMemory>
#include <QDir>
#include <QUrlQuery>
#include <QJsonDocument>

//
// C/C++
//
#include <cstdlib>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <atomic>
#include <memory>
#include <utility>
#include <cassert>
#include <functional>
#include <optional>
#include <csignal>
#include <optional>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

#include "common_macro_helpers.h"

using namespace std::chrono_literals;
using std::size_t;

#ifndef QT_DEBUG
#define PRODUCTION
#endif

#ifndef PRODUCTION
#define DEBUG
#endif

/*
#if defined(Q_OS_WIN)

#include <ws2tcpip.h>
#include <mstcpip.h>

#define CANNOT_CREATE_SOCKET INVALID_SOCKET

#endif

#if defined(Q_OS_MACOS) || defined(Q_OS_UNIX)

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>

#define SOCKET int
#define CANNOT_CREATE_SOCKET -1

#endif
*/

using namespace std::chrono_literals;