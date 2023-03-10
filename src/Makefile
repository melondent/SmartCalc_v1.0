APP = build/SmartCalc*
BACKEND_FILES = s21_smartcalc.c
BACKEND_FILES_O = s21_smartcalc.o

CC+FLAGS = gcc -Wall -Wextra -Werror -std=c11
GCOVFLAGS = -L. --coverage -ls21_smartcalc
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -lm -pthread -lrt -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

TEST_COMPILE = $(CC+FLAGS) s21_tests.c s21_smartcalc.a $(CHECK_FLAGS) -L. -ls21_smartcalc

all: install test clean

build:
	mkdir build
	cd ./build/ && qmake ../ && make

install: build
	@mkdir ../SmartCalc
	@cp -rf $(APP) ../SmartCalc
	make clean

uninstall:
	@rm -rf ../SmartCalc*

dvi:
	open dvi.html

test: s21_smartcalc.a
	$(TEST_COMPILE)
	./a.out

gcov_report: test
	rm -f *.g*
	$(CC+FLAGS) s21_tests.c s21_smartcalc.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info

s21_smartcalc.a: s21_smartcalc.o
	ar rcs libs21_smartcalc.a *.o
	rm -rf *.o
	ranlib libs21_smartcalc.a
	cp libs21_smartcalc.a s21_smartcalc.a
	cp libs21_smartcalc.a ls21_smartcalc.a

s21_smartcalc.o:
	$(CC+FLAGS) -c *.c

clean:
	rm -rf *.o *.a
	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf s21_calc s21_test
	rm -rf ./build*
	rm -rf a.out

rebuild: clean uninstall all

reinstall: clean uninstall install