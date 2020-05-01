#include "application.h"
#include "thread_manager.h"
#include "math_operation_handler.h"
#include "math_operation_request.h"
#include "math_operation_response.h"

namespace MessageDispatcher {

Application::Application(int& argc, char** argv) : QApplication(argc, argv) {
  registrate_math_handler();
  initialize();
}

void Application::registrate_math_handler() const {
  ThreadManager& thread_manager = ThreadManager::instance();
  thread_manager.move_object_to_thread(new Services::MathOperationHandler(), "Math Operation Handler Thread");
}

void Application::initialize() {
  example_widget_ = std::make_unique<ExampleWidget>();
  example_widget_->show();
}

}  // namespace MessageDispatcher
