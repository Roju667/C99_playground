CORE_FLAGS := -g -std=c99 -Wall -Wextra -pedantic

cl :	comp_lit.c
	gcc -o cl comp_lit.c $(CORE_FLAGS)

sa : strict_aliasing.c
	gcc -o sa strict_aliasing.c $(CORE_FLAGS)

ub : undef_beh.c
	gcc -o ub undef_beh.c $(CORE_FLAGS)

fam : flex_array_mem.c
	gcc -o fam flex_array_mem.c $(CORE_FLAGS)

vla : variable_len_arr.c
	gcc -o vla variable_len_arr.c $(CORE_FLAGS)

clean:
	rm *.o *.exe