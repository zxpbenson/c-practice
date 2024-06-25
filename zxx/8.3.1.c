#include <stdio.h>
int main(){
  int max(int, int);
  int a, b, c;
  scanf("%d,%d", &a, &b);
  c = max(a, b);
  printf("Max is %d\n", c);
}

int max(int x, int y){
  printf("x=%d\n", x);
  printf("y=%d\n", y);
  int z;
  z = x > y ? x : y;
  return z;
}
