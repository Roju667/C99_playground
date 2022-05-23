#include "stdio.h"

struct basic
{
    int a;
    int b;
};

void print_basic(struct basic p)
{
    printf("a : %d, b : %d \n", p.a, p.b);
}

void pass_pointer(struct basic *p){};

struct basic *lets_break_it(int a, int b)
{
    struct basic *test_p = &(struct basic){a, b};
    return test_p;
}

int main()
{

    // int r[] = (int[]){1, 2, 3}; // this causes error
    //  easy example -> assign not existing array to p (and create it)
    int *p = (int[]){1, 2, 3};
    int *r = (int[3]){1, 2, 3, 4}; // only warning here
    int check = r[3];              // will this work?

    print_basic((struct basic){r[7], r[0]}); // possible but with random value
    int *deref = &r[4];                      // all gucci no segmentation

    // assign unnamed struct to pointer variable
    struct basic a = (struct basic){4, 6};

    pass_pointer(&(struct basic){.a = 123, .b = 345});
    // pass unnamed struct to function
    print_basic((struct basic){4, 2});

    int another = 3;
    int *p_to_another = &another;

    // creates and array from unnanem object, [0] is value from p_to_another, [1] is 5
    p_to_another = (int[2]){*p_to_another, 5};

    struct basic *break_me_pointer = lets_break_it(1, 2);
    break_me_pointer = lets_break_it(1, 2);
    struct basic *break_it_here = lets_break_it(4, 5);
    break_it_here = lets_break_it(4, 5);
    print_basic(*break_me_pointer); // this is printing 4,5 so its broken beacuse of auto lifetime of compound literals

    return 0;
}