#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->result->setAlignment(Qt::AlignRight);
  ui->lineEdit_step->setAlignment(Qt::AlignHCenter);
  ui->lineEdit_xMax->setAlignment(Qt::AlignHCenter);
  ui->lineEdit_xMin->setAlignment(Qt::AlignHCenter);
  ui->lineEdit_yMax->setAlignment(Qt::AlignHCenter);
  ui->lineEdit_yMin->setAlignment(Qt::AlignHCenter);
  ui->lineEdit_xValue->setAlignment(Qt::AlignHCenter);
  ui->lineEdit_step->setText("0.1");
  ui->lineEdit_xMax->setText("10");
  ui->lineEdit_xMin->setText("-10");
  ui->lineEdit_yMax->setText("10");
  ui->lineEdit_yMin->setText("-10");
  ui->lineEdit_xValue->setText("0");

  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);

  ui->lineText_step->setReadOnly(true);
  ui->lineText_xMax->setReadOnly(true);
  ui->lineText_xMin->setReadOnly(true);
  ui->lineText_yMax->setReadOnly(true);
  ui->lineText_yMin->setReadOnly(true);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_0_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "0");
}

void MainWindow::on_pushButton_1_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "1");
}

void MainWindow::on_pushButton_2_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "2");
}

void MainWindow::on_pushButton_3_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "3");
}

void MainWindow::on_pushButton_4_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "4");
}

void MainWindow::on_pushButton_5_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "5");
}

void MainWindow::on_pushButton_6_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "6");
}

void MainWindow::on_pushButton_7_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "7");
}

void MainWindow::on_pushButton_8_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "8");
}

void MainWindow::on_pushButton_9_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "9");
}

void MainWindow::on_pushButton_dot_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + ".");
}

void MainWindow::on_pushButton_plus_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "+");
}

void MainWindow::on_pushButton_subtracting_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "-");
}

void MainWindow::on_pushButton_multiply_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "*");
}

void MainWindow::on_pushButton_division_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "/");
}

void MainWindow::on_pushButton_leftBracket_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "(");
}

void MainWindow::on_pushButton_rightBracket_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + ")");
}

void MainWindow::on_pushButton_x_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "x");
}

void MainWindow::on_pushButton_sin_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "sin(");
}

void MainWindow::on_pushButton_cos_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "cos(");
}

void MainWindow::on_pushButton_tan_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "tan(");
}

void MainWindow::on_pushButton_atan_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "atan(");
}

void MainWindow::on_pushButton_acos_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "acos(");
}

void MainWindow::on_pushButton_asin_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "asin(");
}

void MainWindow::on_pushButton_log_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "log(");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "sqrt(");
}

void MainWindow::on_pushButton_mod_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "mod");
}

void MainWindow::on_pushButton_ln_clicked() {
  if (!(ui->result->isReadOnly()))
    ui->result->setText(ui->result->text() + "ln(");
}

void MainWindow::on_pushButton_AC_clicked() {
  if (ui->result->isReadOnly()) ui->result->setReadOnly(false);
  ui->result->setText("");
}

void MainWindow::on_pushButton_degree_clicked() {
  ui->result->setText(ui->result->text() + "^");
}

void MainWindow::on_pushButton_answer_clicked() {
  QByteArray tmp = ui->result->text().toLocal8Bit();
  char* expression = tmp.data();
  if (validator(expression)) {
    double x_value = ui->lineEdit_xValue->text().toDouble();
    stack* reversed_first_element = NULL;
    for (int i = 0; expression[i] != '\0'; i++)
      fill_stack(expression, &i, &reversed_first_element, x_value);
    stack* first_element = NULL;
    reverse_stack(&reversed_first_element, &first_element);
    stack* rpn_numbers = NULL;
    stack* support = NULL;
    reverse_polish_notation(&first_element, &rpn_numbers, &support);
    stack* result = NULL;
    reverse_stack(&rpn_numbers, &result);
    stack* calculated_stack = NULL;
    calculation(&result, &calculated_stack);
    QString valueAsDouble = QString::number((double)calculated_stack->value);
    ui->result->setText(valueAsDouble);
    pop(&calculated_stack);
  } else {
    ui->result->setText("Invalid Expression");
    ui->result->setReadOnly(true);
  }
}

void MainWindow::on_pushButton_Graphics_clicked() {
  ui->widget->clearGraphs();

  QString xMa = ui->lineEdit_xMax->text();
  long double xMax = xMa.toDouble();

  QString xMi = ui->lineEdit_xMin->text();
  long double xMin = xMi.toDouble();

  QString yMa = ui->lineEdit_yMax->text();
  long double yMax = yMa.toDouble();

  QString yMi = ui->lineEdit_yMin->text();
  long double yMin = yMi.toDouble();

  QString ste = ui->lineEdit_step->text();
  long double step = ste.toDouble();

  if (axis_validator(xMax, xMin, yMin, yMax)) {
    xBegin = xMin;
    xEnd = xMax;
    h = step;
    N = (xEnd - xBegin) / h + 2;
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);

    QByteArray tmp = ui->result->text().toLocal8Bit();
    char* expression = tmp.data();
    long double result;
    for (X = xBegin; X <= xEnd; X += h) {
      x.push_back(X);
      main_func(expression, X, &result);
      y.push_back(result);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    x.clear();
    y.clear();
  } else {
    QMessageBox::about(this, "Ошибка", "Некорректный ввод");
  }
}
