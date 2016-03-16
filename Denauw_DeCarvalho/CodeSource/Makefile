CHEM1 = HOME/local/include
CHEM2 = HOME/local/lib

code: code.o CUnit.o
	gcc -Werror -L$(CHEM2) code.o CUnit.o -lcunit -o code
	./code 2048
code.o: code.c code.h
	gcc -Werror -c code.c
CUnit.o: CUnit.c code.h
	gcc -Werror -lcunit -I$(CHEM1) -c CUnit.c