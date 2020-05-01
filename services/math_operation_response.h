#pragma once

#include "iresponse.h"

namespace Services {

struct MathOperationResponse : public MessageDispatcher::IResponse {
  DEFINE_RESPONSE_STATIC_TYPE_IN_CLASS(MessageDispatcher::ResponseType::ResponseTypeMathOperation);

  MessageDispatcher::ResponseType type() const noexcept override {
    return MessageDispatcher::ResponseType::ResponseTypeMathOperation;
  }

  int result = 0;
};

}  // namespace Services
