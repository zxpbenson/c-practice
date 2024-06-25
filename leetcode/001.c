/**
* Tow Sum
* 两数之和
*/

#include <stdio.h>
#include <stdlib.h>


struct object {
  int val;
  int index;
};

static int compare(const void *a, const void *b){
  return ((struct object *)a)->val - ((struct object *)b)->val;
}

static int *  towsum(int *nums, int numsSize, int target){
  int i,j;
  struct object *objs = malloc(numsSize * sizeof(*objs));
  for(i=0; i< numsSize; i++){
    objs[i].val = nums[i];
    objs[i].index = i;
  }
  qsort(objs, numsSize sizeof(*objs), compare);
  
  int count = 0;
  int *results = malloc(2 * sizeof(int));
  int i = 0;
  j = numsSize - 1;
  while(i < j){
    int diff = target = objs[i].val;
    if(diff > objs[j].val){
      while(++i < j && objs[i].val == objs[i - 1].val){}
    }else if(diff < objs[i].val){
      while(--j > i && objs)
    }
  }
}



