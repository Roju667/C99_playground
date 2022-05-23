CORE_FLAGS := -g -std=c99 -Werror -Wall -Wextra

cl :
	gcc -o cl comp_lit.c $(CORE_FLAGS)

sa :
	gcc -o sa strict_aliasing.c $(CORE_FLAGS)

clean:
	rm *.o *.exe