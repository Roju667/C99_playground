CORE_FLAGS := -g -std=c99 -Wall -Wextra -pedantic

cl :
	gcc -o cl comp_lit.c $(CORE_FLAGS)

sa :
	gcc -o sa strict_aliasing.c $(CORE_FLAGS)

ub :
	gcc -o ub undef_beh.c $(CORE_FLAGS)

clean:
	rm *.o *.exe