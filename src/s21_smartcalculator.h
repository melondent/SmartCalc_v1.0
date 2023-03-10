#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <math.h>
#include <stdio.h>

typedef enum type {
  X,
  NUMBER,
  PLUS,
  SUB,
  MUL,
  DIV,
  MOD,
  DEGREE,
  SIN,
  COS,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  LEFT_BRACKET,
  RIGHT_BRACKET
} type_t;

typedef struct stack_struct {
  long double value;
  int priority;
  type_t type;
  struct stack_struct* next;
} stack;

int main_func(char* exp, long double x_value, long double* result_value);
void next_pop(stack** last_element);
void reverse_polish_notation(stack** first_element, stack** rpn_numbers,
                             stack** suppport);
void pop(stack** last_element);
void reverse_stack(stack** first_element, stack** answer);
int get_number(char* exp, char* single_number, int* i);
void push(long double value, int priority, type_t type, stack** first_element);
void fill_stack(char* exp, int* i, stack** first_element, long double x_value);
void fill_stack_trig(char* exp, int* i, stack** first_element);
void calculation(stack** result, stack** calculated_stack);
void double_pop(stack** last_element);

#endif