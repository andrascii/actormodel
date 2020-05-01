#include "math_operation_handler.h"
#include "handler_registry.h"
#include "irequest.h"
#include "math_operation_request.h"
#include "math_operation_response.h"
#include "thread_message_dispatcher.h"

namespace Services {

MathOperationHandler::MathOperationHandler() {
  MessageDispatcher::HandlerRegistry& handler_registry = MessageDispatcher::HandlerRegistry::instance();
  handler_registry.registrate_handler(this, MessageDispatcher::RequestType::RequestMathOperation);
}

void MathOperationHandler::handle_request(MessageDispatcher::RequesterSharedPtr requester) {
  MathOperationRequest* request = dynamic_cast<MathOperationRequest*>(requester->request());  // use fast_cast<> instead

  const std::shared_ptr<MathOperationResponse> response = std::make_shared<MathOperationResponse>();

  switch(request->operation) {
    case MathOperationRequest::Plus: {
      response->result = request->first_operand + request->second_operand;
      break;
    }
    case MathOperationRequest::Minus: {
      response->result = request->first_operand - request->second_operand;
      break;
    }
    case MathOperationRequest::Multiply: {
      response->result = request->first_operand * request->second_operand;
      break;
    }
    case MathOperationRequest::Divide: {
      response->result = request->first_operand / request->second_operand;
      break;
    }
    default: {
      response->result = std::numeric_limits<int>::max();  // for example this is an error mark
    }
  }

  // send response to the requester
  MessageDispatcher::ThreadMessageDispatcher::for_thread(requester->thread())->post_response(requester, response);
}

void MathOperationHandler::stop_request_handling(MessageDispatcher::RequesterSharedPtr) {
  // do nothing
  // in this simple example we can't to cancel our work
}

}  // namespace Services
