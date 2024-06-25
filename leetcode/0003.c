#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int lengthOfLongestSubstring(char *s){
  int offset[128];
  int max_len = 0;
  int len = 0;
  int index = 0;
  //Oxff是16进制，值是255，换成二进制是11111111，offset[x]的长度是4字节，offset长度是512字节，memset是逐字节赋值为11111111
  //赋值完成后 offset中每个元素的值都是四字节32个1，首位是1表示是负数，因为负数都是存的补码，补码=原码取反+1，那么32个1的原码就是表示-1（取反时符号位不变）
  memset(offset, 0xff, sizeof(offset));
  printf("0xff = %d\n", 0xff);
  printf("sizeof(offset[0]) = %lu\n", sizeof(offset[0]));
  printf("sizeof(offset) = %lu\n", sizeof(offset));
  for(int l = 0; l < 128; l++){
    printf("initialize offset[%d]=%d\n", l, offset[l]);
  }
  while(*s != '\0'){
    printf("offset[%d] = %d\n", *s, offset[*s]);
    if(offset[*s] == -1){
      len++;
    }else{
      if(index - offset[*s] > len){
        len++;
      }else{
        len = index - offset[*s];
      }
    }
    if(len > max_len){
      max_len = len;
    }
    offset[*s++] = index++;
  }
  return max_len;
}

int main(int argc, char **argv){
  if(argc != 2){
    fprintf(stderr, "Usage: ./0003 string\n");
    exit(-1);
  }
  printf("%d\n", lengthOfLongestSubstring(argv[1]));
  return 0;
}

