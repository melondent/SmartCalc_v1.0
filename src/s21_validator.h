#ifndef SRC_VALIDATOR_H_
#define SRC_VALIDATOR_H_

#include <stdlib.h>
#include <string.h>

enum exit_code { ERROR, OK };

int axis_validator(long double xMax, long double xMin, long double yMin,
                   long double yMax);
int pre_check(char* exp, int string_len, char* actions, char* trigonometry);
int validator(char* exp);
int trigonometry_validator(int counter, char* exp, int* offset);
int lexem_check(char* trig_exp, char* exp, int counter, int* offset);
char* remove_spaces(char* exp);
int check_left(int a);
int check_right(int a);
int is_digit(int a);
int check_check(int i, int i_p, int j, char* exp, char* actions,
                char* trigonometry, int string_len);

#endif