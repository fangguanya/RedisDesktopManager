#pragma once
#include <QApplication>
#include <QSharedPointer>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QMenu>

#ifndef RDM_VERSION
#include "../version.h"
#endif

class QmlUtils;
class ConnectionsManager;
class Updater;
class LogHandler;
class TabViewModel;
namespace ValueEditor { class ViewModel; }
namespace ValueEditor { class FormattersManager; }
namespace BulkOperations { class Manager; }


class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int &argc, char **argv);
    void initModels();
    void initQml();

private:
    void initAppInfo();
    void initAppFonts();    
    void registerQmlTypes();
    void registerQmlRootObjects();
    void initLog();
    void initConnectionsManager();
    void initUpdater();
    void installTranslator();
    void processCmdArgs();

private slots:
      void OnNewUpdateAvailable(QString &url);

private:
    QQmlApplicationEngine m_engine;
    QSharedPointer<QmlUtils> m_qmlUtils;
    QSharedPointer<ConnectionsManager> m_connections;
    QSharedPointer<Updater> m_updater;
    QSharedPointer<ValueEditor::ViewModel> m_keyValues;
    QSharedPointer<ValueEditor::FormattersManager> m_formattersManager;
    QSharedPointer<BulkOperations::Manager> m_bulkOperations;
    QSharedPointer<TabViewModel> m_consoleModel;
    QSharedPointer<TabViewModel> m_serverStatsModel;
    LogHandler* m_logger;
    QString m_settingsDir;
    QString m_renderingBackend;
};
