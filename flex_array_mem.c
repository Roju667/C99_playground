#include <stdio.h>
#include <stdlib.h>

typedef struct something {
  char i;
  int fam[];

} something_t;

something_t *create_something(char i, size_t len) {

  // this is still gonna alloced 24 bytes even with char beacuse of padding
  something_t *ptr = malloc(sizeof(something_t) + (len * sizeof(int)));

  if (NULL == ptr) {
    printf("malloc fail \n");
  } else {
    printf("malloced %d \n", sizeof(something_t) + (len * sizeof(int)));
  }

  ptr->i = i;
  return ptr;
}

int main() {
  size_t lenght = 5;
  something_t *smth = create_something(5, lenght);

  printf("size of instance % d\n", sizeof(smth));
  printf("size of something_t %d \n", sizeof(something_t));

  // should be undef beh -> editing address oustide malloced ptr
  smth->fam[lenght] = 5555;

  // fill array
  for (size_t i = 0; i < lenght; i++) {
    smth->fam[i] = i;
  }

  char *woops = NULL;
  woops = (char *)smth++;

  // print all bytes + next byte
  for (size_t i = 0; i < 2 + (lenght * 4); i++) {
    printf("add: %p val %d\n", woops, *woops);
    woops++;
  }

  free(smth);

  return 0;
}