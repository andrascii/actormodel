#pragma once

#include "requester_wrapper.h"
#include "example_widget.h"

namespace Services {

struct MathOperationResponse;

}  // namespace Services

namespace MessageDispatcher {

class Application : public QApplication {
  Q_OBJECT

 public:
  Application(int& argc, char** argv);

 private:
  void initialize();
  void registrate_math_handler() const;

 private:
  std::unique_ptr<ExampleWidget> example_widget_;
};

}  // namespace MessageDispatcher
