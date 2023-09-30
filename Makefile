CC = gcc
CC_FLAGS = --std=c11 -Wall -Werror -Wextra
GCOV_FLAGS = -lgcov --coverage

O_EXT = o_ext/

UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
LIBS = -lcheck 
endif
ifeq ($(UNAME), Linux)
LIBS = -lcheck -lsubunit -lm
endif

all : clean my_math.a test

test: clean my_math.a
	$(CC) $(CFLAGS) my_math_test.c -L. my_math.a -o test -lcheck -lsubunit -lm
	./test

my_math.a: my_math.o
	ar rcs my_math.a $(O_EXT)*.o
	ranlib my_math.a

my_math.o:
	mkdir $(O_EXT)
	#other functions
	$(CC) $(CFLAGS) -c my_math.c -o $(O_EXT)my_math.o 

my_gcov.gcno: clean
	mkdir $(O_EXT)
	#other functions
	$(CC) $(CFLAGS) -c my_math.c -o $(O_EXT)my_math.o $(GCOV_FLAGS)

gcov_report : clean my_gcov.gcno 
	$(CC) my_math_test.c $(O_EXT)*.o -o test_check $(LIBS) $(GCOV_FLAGS)
	-./test_check > test.log
	lcov --capture --directory . -o test.info
	genhtml test.info -o report
	open report/index.html

clean :
	rm -rf *.gcno *.gcda *.o *.a *.info my_math report $(O_EXT) test

clang :
	clang-format -style="{BasedOnStyle: Google}" -i */*.c */*.h *.c *.h
