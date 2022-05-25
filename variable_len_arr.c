#include <stdio.h>

int vla_fun(size_t len) {
  int array[len];
  int ret_val = 0;

  for (size_t i = 0; i < len; i++) {
    array[i] = i;
    ret_val += array[i];
  }

  return ret_val;
}

int main() {

  printf("value : %d \n", vla_fun(10));
  return 0;
}