#pragma once

#include "irequest.h"

namespace Services {

struct MathOperationRequest : public MessageDispatcher::IRequest {
  enum Operation {
    None,
    Plus,
    Minus,
    Multiply,
    Divide
  };

  std::shared_ptr<MessageDispatcher::IRequest> clone() const override {
    return std::make_shared<MathOperationRequest>(*this);
  }

  MessageDispatcher::RequestType request_type() const noexcept override {
    return MessageDispatcher::RequestType::RequestMathOperation;
  }

  Operation operation = None;
  int first_operand = 0;
  int second_operand = 0;
};

}  // namespace Services
