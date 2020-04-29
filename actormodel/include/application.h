#pragma once

#include "requester_wrapper.h"

namespace CrawlerEngine
{

struct DownloadResponse;

}

class Application : public QCoreApplication
{
  Q_OBJECT

public:
  Application(int& argc, char** argv);

private:
  void registerDownloadHandler() const;
  void onLoadingDone(CrawlerEngine::Requester* requester, const CrawlerEngine::DownloadResponse& response);

private:
  CrawlerEngine::RequesterWrapper m_requester;
};
