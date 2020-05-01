#pragma once

#include "requester.h"

namespace Services {

class MathOperationHandler : public QObject {
  Q_OBJECT

 public:
  MathOperationHandler();

  Q_INVOKABLE void handle_request(MessageDispatcher::RequesterSharedPtr requester);
  Q_INVOKABLE void stop_request_handling(MessageDispatcher::RequesterSharedPtr);
};

}  // namespace Services
