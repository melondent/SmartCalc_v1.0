#include <check.h>
#include <limits.h>

#include "s21_smartcalculator.h"
#include "s21_validator.h"

START_TEST(s21_smartcalculator_tests) {
  char *input_expression;
  long double result, x;
  int return_value;

  input_expression = ")cis)(19+4)*";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_int_eq(return_value, ERROR);

  input_expression = "16*sin(2)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 14.5487588292, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "3.5-acos(0.5))";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_int_eq(return_value, ERROR);

  input_expression = "asin()";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_int_eq(return_value, ERROR);

  input_expression = "7+9/(1";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_int_eq(return_value, ERROR);

  input_expression = "11+56/(1mod)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_int_eq(return_value, ERROR);

  input_expression = "sqrt(0.25)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 0.5, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "0+sqrt(0.25)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 0.5, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "-sqrt(0.25)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, -0.5, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "(ln(25.9))";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 3.2542429, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "-log(982.465)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, -2.992317, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "+(-1+(+1))";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "7*(2)*1";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 14, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "2^sin(3)/1";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 1.1027608, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "sin(-1000000)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 0.3499935, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "cos(123456)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, -0.6722948, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "atan(1000000)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 1.5707953, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "tan(2)+ln(40)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 1.5038395, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "log(2)+log(3)";
  return_value = main_func(input_expression, 0, &result);
  ck_assert_double_eq_tol(result, 0.7781512, 1e-7);
  ck_assert_int_eq(return_value, OK);

  x = 654123.891357;
  input_expression = "sin(x)+cos(-x)+tan(+x)";
  return_value = main_func(input_expression, x, &result);
  ck_assert_double_eq_tol(result, 1.5927179, 1e-7);
  ck_assert_int_eq(return_value, OK);

  x = 1;
  input_expression = "x-x*x/x";
  return_value = main_func(input_expression, x, &result);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "(-0)";
  return_value = main_func(input_expression, x, &result);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "(-1*0)";
  return_value = main_func(input_expression, x, &result);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "(0*(-100998789865))";
  return_value = main_func(input_expression, x, &result);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "(0*(-9))";
  return_value = main_func(input_expression, x, &result);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression =
      "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin("
      "10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+"
      "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin("
      "10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)";
  return_value = main_func(input_expression, x, &result);
  ck_assert_double_eq_tol(result, -17.4086755, 1e-7);
  ck_assert_int_eq(return_value, OK);

  input_expression = "";
  return_value = main_func(input_expression, x, &result);
  ck_assert_int_eq(return_value, ERROR);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *s21_test = tcase_create("Test");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, s21_test);

  tcase_add_test(s21_test, s21_smartcalculator_tests);

  srunner_run_all(sr, CK_VERBOSE);
  int errors = srunner_ntests_failed(sr);
  srunner_free(sr);

  return errors == 0 ? 0 : 1;
}