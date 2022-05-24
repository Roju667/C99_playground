#include <stdio.h>

int break_with_zero(int a, int b) { return a / b; };
//  Exception has occurred.
//  Arithmetic exception
//

int *break_with_pointer(void) {
  int *ptr;
  *ptr = 32;
  return ptr;
}

int main() {

  int tab[3] = {0, 1, 2};
  int *p = &tab[3]; // undef

  int try_this;
  printf("undef value : %d\n", try_this); // undef beh but worked

  int *undef_pointer;
  int now_break = undef_pointer[3]; // work as a charm but its undef beh

  int *my_breaking_point = break_with_pointer(); // undef but worked

  int overflow = __INT_MAX__ + 50;
  printf("overflow : %d\n", overflow);

  printf("my breaking point is %d\n",
         *my_breaking_point); // arithmetic exepction

  char text[] = "lets try to edit this\n";
  text[2] = 'z'; // actually worked

  int *ptr = NULL;
  int abc = *ptr; // segmentation fault

  printf("break : %d\n", break_with_zero(1, 0));

  return 0;
}