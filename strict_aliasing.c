#include <assert.h>
#include <stdio.h>

union strict_aliasing_magic
{
    int sam_int;
    float sam_float;
};

_Static_assert(sizeof(int) == sizeof(float), "wops");

int main()
{

    float f = 1.02;

    // strict alising break
    int alias_int = *(int *)&f; // Undefined behaviour

    printf("aliasing sucks : %d\n", alias_int);

    union strict_aliasing_magic new = {.sam_float = 1.00};

    printf("aliasing hacks : %d\n", new); // completly legal

    return 0;
}