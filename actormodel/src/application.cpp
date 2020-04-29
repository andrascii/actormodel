#include "application.h"
#include "download_request.h"
#include "download_response.h"
#include "thread_manager.h"
#include "qt_based_download_handler.h"

using namespace CrawlerEngine;

Application::Application(int& argc, char** argv) : QCoreApplication(argc, argv)
{
  registerDownloadHandler();

  CrawlerRequest crawlerRequest{ Url("https://praimont.ru"), DownloadRequestType::RequestTypeGet };

  DownloadRequest request(
    crawlerRequest,
    0,
    DownloadRequest::Status::LinkStatusFirstLoading,
    DownloadRequest::BodyProcessingCommand::CommandAutoDetectionBodyLoading,
    true
  );

  m_requester.reset(request, this, &Application::onLoadingDone);
  m_requester->start();
}

void Application::registerDownloadHandler() const
{
  ThreadManager& threadManager = ThreadManager::instance();
  threadManager.moveObjectToThread(new QtBasedDownloadHandler, "DownloaderThread");
}

void Application::onLoadingDone(CrawlerEngine::Requester* requester, const CrawlerEngine::DownloadResponse& response)
{
  for (const auto& hop : response.hopsChain)
  {
    qDebug() << "Loaded: " << hop.url().toDisplayString();
    qDebug() << hop.responseHeaders().makeString();
  }

  m_requester.reset();
}
