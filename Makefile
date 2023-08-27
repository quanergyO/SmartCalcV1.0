CFLAGS = -Wall -Wextra -Werror -std=c11
GCOV = -fprofile-arcs -ftest-coverage -fPIC
FILES = *.c modules/*.c
OS = $(shell uname)

ifeq (${OS}, Linux)
	TEST_FLAGS = -lcheck -lpthread -lm -D_GNU_SOURCE -lrt -lsubunit
else
	TEST_FLAGS = -lcheck
endif

all: clean gcov_report

gcov_report: test
	lcov -t calc.a -o calc.info -c -d .
	genhtml -o report calc.info

ifeq (${OS}, Linux)
	cd report && firefox index.html
else
	cd report && open index.html
endif

test: clean calc.a
	gcc ./test_dir/test.c -c
	gcc ${CFLAGS} ${TEST_FLAGS} ${GCOV} ${FILES} test.o -o test
	./test

calc.a : calc.o
	ar rc libs21_calc.a *.o
	ranlib libs21_calc.a
	cp libs21_calc.a calc.a

calc.o: ${FILES}
	gcc ${CFLAGS} -c ${FILES}

clean:
	rm -rf *.o gcov_report *.a *.gcda *.gcno report calc.info

rebuild: clean calc.a

install:clean
	mkdir build
	cd build && cmake ../view/CMakeLists.txt && make
	cp -rf build/view.app $(HOME)/Desktop/calculator.app

uninstall: clean
	rm -rf build
	rm -rf $(HOME)/Desktop/Calculator.app

dvi:
	doxygen Doxyfile
	open html/index.html

dist:
	mkdir SmartCalc_v1.0/
	mkdir SmartCalc_v1.0/src
	cp Makefile s21_*.c *.h  SmartCalc_v1.0/src/
	cp -R right_version_of_calculator SmartCalc_v1.0/src/
	tar cvzf SmartCalc_v1.0.tgz SmartCalc_v1.0/
	rm -rf SmartCalc_v1.0/
