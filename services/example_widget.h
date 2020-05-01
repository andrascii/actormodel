#pragma once

#include "requester_wrapper.h"

namespace Services {

struct MathOperationResponse;

}  // namespace Services

namespace MessageDispatcher {

class ExampleWidget : public QWidget {
  Q_OBJECT

 public:
  explicit ExampleWidget(QWidget* parent = nullptr);

private slots:
  void on_calculate_button_clicked();

 private:
  void on_math_operation_done(MessageDispatcher::Requester* requester, const Services::MathOperationResponse& response);

 private:
  MessageDispatcher::RequesterWrapper requester_;
  QLineEdit* first_operand_line_edit_;
  QLineEdit* second_operand_line_edit_;
  QLabel* result_math_operation_label_;
};

}  // namespace MessageDispatcher
