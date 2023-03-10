#include "s21_validator.h"

int validator(char* exp) {
  exp = remove_spaces(exp);
  char* operand = "+-*/^";
  char* trigonometry = "cstalx";
  int string_len = (int)strlen(exp);
  int left_bracket = 0, right_bracket = 0;
  int return_value = OK;
  if (!pre_check(exp, string_len, operand, trigonometry)) return_value = ERROR;
  if (string_len > 255 || string_len < 3) return_value = ERROR;
  for (int i = 0; i < string_len; i++) {
    int offset = 0;
    if (check_left(exp[i])) {
      left_bracket++;
      if (check_right(exp[i + 1])) return_value = ERROR;
    }
    if (check_right(exp[i])) right_bracket++;
    if (exp[i] == '.' && is_digit(exp[i + 1])) return_value = ERROR;
    if (exp[i] == '-' && i != 0) {
      if (!check_left(exp[i - 1]) && !check_right(exp[i - 1]) &&
          exp[i - 1] != 'x' && is_digit(exp[i - 1]))
        return_value = ERROR;
    }
    if (exp[i] == 'm') {
      if (lexem_check("mod", exp, i, &offset)) {
        if ((exp[i - 1] <= '0' && exp[i - 1] >= '9') ||
            (exp[i + 3] <= '0' || exp[i + 3] >= '9'))
          return_value = ERROR;
      } else {
        return_value = ERROR;
      }
    }
    for (int j = 0; trigonometry[j] != '\0'; j++) {
      if (exp[i] == trigonometry[j]) {
        if (!trigonometry_validator(i, exp, &offset)) return_value = ERROR;
        if (offset && !check_left(exp[i + offset + 1])) return_value = ERROR;
      }
    }
    for (int j = 0; operand[j] != '\0'; j++) {
      if (!check_check(i, i + 1, j, exp, operand, trigonometry, string_len))
        return_value = ERROR;
    }
    i += offset;
  }
  if (left_bracket != right_bracket) return_value = ERROR;
  free(exp);
  return return_value;
}

int is_digit(int a) {
  int return_value = ERROR;
  if (a <= '0' && a >= '9') return_value = OK;
  return return_value;
}

int check_left(int a) {
  int return_value = ERROR;
  if (a == '(') return_value = OK;
  return return_value;
}

int check_right(int a) {
  int return_value = ERROR;
  if (a == ')') return_value = OK;
  return return_value;
}

int check_check(int i, int i_p, int j, char* exp, char* operand,
                char* trigonometry, int string_len) {
  int return_value = OK;
  int count = 0;
  if (exp[i] == ')' && exp[i_p] != operand[j] && exp[i_p] != '\0' &&
      !check_right(exp[i_p])) {
    count++;
    if (count == (int)strlen(operand)) return_value = ERROR;
  }
  if (exp[string_len - 1] == operand[j]) return_value = ERROR;
  int operand_counter = 0;
  if (exp[i] == operand[j]) {
    operand_counter++;
    int error_count = 0;
    for (int z = 0; trigonometry[z] != '\0'; z++) {
      if (is_digit(exp[i_p]) && exp[i_p] != '(' && exp[i_p] != trigonometry[z])
        error_count++;
    }
    if (error_count == (int)strlen(trigonometry)) return_value = ERROR;
    for (int k = 0; operand[k] != '\0'; k++) {
      if (exp[i_p] == operand[k]) return_value = ERROR;
    }
  }
  return return_value;
}

int pre_check(char* exp, int string_len, char* operand, char* trigonometry) {
  int action_check = 0;
  int trigonometry_check = 0;
  int return_value = OK;
  if (exp[0] == 'm') {
    return_value = ERROR;
  }
  for (int i = 0; i < string_len; i++) {
    for (int a = 0; operand[a] != '\0'; a++) {
      if (operand[a] == exp[i]) action_check++;
    }
    for (int t = 0; trigonometry[t] != '\0'; t++) {
      if (trigonometry[t] == exp[i] || exp[i] == 'm') trigonometry_check++;
    }
  }
  if (!trigonometry_check && !action_check) return_value = ERROR;
  return return_value;
}

int trigonometry_validator(int counter, char* exp, int* offset) {
  int return_value = OK;
  int check = 0;
  switch (exp[counter]) {
    case 'c':
      check += lexem_check("cos", exp, counter, offset);
      break;
    case 's':
      if (exp[counter + 1] == 'i')
        check += lexem_check("sin", exp, counter, offset);
      else
        check += lexem_check("sqrt", exp, counter, offset);
      break;
    case 't':
      check += lexem_check("tan", exp, counter, offset);
      break;
    case 'a':
      if (exp[counter + 1] == 'c')
        check += lexem_check("acos", exp, counter, offset);
      else if (exp[counter + 1] == 's')
        check += lexem_check("asin", exp, counter, offset);
      else
        check += lexem_check("atan", exp, counter, offset);
      break;
    case 'l':
      if (exp[counter + 1] == 'n')
        check += lexem_check("ln", exp, counter, offset);
      else
        check += lexem_check("log", exp, counter, offset);
      break;
    case 'x':
      check += lexem_check("x", exp, counter, offset);
  }
  if (!check) return_value = ERROR;
  return return_value;
}

int lexem_check(char* trig_exp, char* exp, int counter, int* offset) {
  int return_value = ERROR;
  int check = 0;
  int string_len = (int)strlen(trig_exp);
  for (int i = counter, j = 0; i < counter + string_len; i++) {
    if (exp[i] == trig_exp[j++]) check++;
  }
  if (check == string_len) {
    return_value = OK;
    *offset = string_len - 1;
  }
  return return_value;
}

char* remove_spaces(char* exp) {
  char* return_expression = calloc(strlen(exp), sizeof(char));
  for (int i = 0, j = 0; i < (int)strlen(exp); i++) {
    if (exp[i] != ' ') return_expression[j++] = exp[i];
  }
  return return_expression;
}

int axis_validator(long double xMax, long double xMin, long double yMin,
                   long double yMax) {
  int return_value = OK;
  if (xMin >= xMax || yMin >= yMax) return_value = ERROR;
  return return_value;
}
