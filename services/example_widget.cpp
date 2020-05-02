#include "example_widget.h"
#include "math_operation_request.h"
#include "math_operation_response.h"

namespace MessageDispatcher {

ExampleWidget::ExampleWidget(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* layout = new QVBoxLayout(this);

  QHBoxLayout* first_operand_layout = new QHBoxLayout;
  QLabel* first_operand_label = new QLabel("First operand:");
  first_operand_line_edit_ = new QLineEdit(this);
  first_operand_layout->addWidget(first_operand_label);
  first_operand_layout->addWidget(first_operand_line_edit_);

  QHBoxLayout* second_operand_layout = new QHBoxLayout;
  QLabel* second_operand_label = new QLabel("Second operand:");
  second_operand_line_edit_ = new QLineEdit(this);
  second_operand_layout->addWidget(second_operand_label);
  second_operand_layout->addWidget(second_operand_line_edit_);

  first_operand_line_edit_->setValidator(new QIntValidator(
    std::numeric_limits<int>::min(),
    std::numeric_limits<int>::max(),
    this));

  second_operand_line_edit_->setValidator(new QIntValidator(
    std::numeric_limits<int>::min(),
    std::numeric_limits<int>::max(),
    this));

  layout->addLayout(first_operand_layout);
  layout->addLayout(second_operand_layout);

  QPushButton* calculate_button = new QPushButton("Calculate");
  QObject::connect(calculate_button, SIGNAL(clicked()), this, SLOT(on_calculate_button_clicked()));

  layout->addWidget(calculate_button);

  result_math_operation_label_ = new QLabel("Result: undefined");
  layout->addWidget(result_math_operation_label_);
}

void ExampleWidget::on_calculate_button_clicked() {
  Services::MathOperationRequest plus_operation_request;
  plus_operation_request.operation = Services::MathOperationRequest::Plus;
  plus_operation_request.first_operand = first_operand_line_edit_->text().toInt();
  plus_operation_request.second_operand = second_operand_line_edit_->text().toInt();

  requester_.reset(plus_operation_request, this, &ExampleWidget::on_math_operation_done);
  requester_->start();
}

void ExampleWidget::on_math_operation_done(MessageDispatcher::Requester*, const Services::MathOperationResponse& response) {
  result_math_operation_label_->setText(QString("Result: %1").arg(response.result));
  requester_.reset();
}

}  // namespace MessageDispatcher
