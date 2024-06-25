# include <stdio.h>
# define arrLength(arr,len){len=(sizeof(arr)/sizeof(arr[0]));}
void displayArr(int[], int);
//int arrLength(int[]);
void swapArrElement(int[], int, int, int);

int main(){
  int arr[] = {0,1,2,3,4,5,6,7,8,9};
  int len;
  arrLength(arr, len)
  printf("arrry length = %d\n", len);
  displayArr(arr, len);
  swapArrElement(arr, len, 2, 3);
  displayArr(arr, len);
}

void displayArr(int arr[], int len){
  for(int index = 0; index < len; index++){
    printf("%d,", arr[index]);
  }
  printf("\n");
}

/*
通过传递数组名参数到子函数中，以获得数组长度是不可行的
因为，a是函数参数，到了本函数中，a只是一个指针（地址，系统在本函数运行时，是不知道a所表示的地址有多大的数据存储空间，这里只是告诉函数：一个数据存储空间首地址）
所以，sizoef(a)的结果是指针变量a占内存的大小，一般在32位机上是4个字节。a[0]是int类型，sizeof(a[0])也是4个字节，所以，结果永远是1
因此，获得数组长度，只能在数组定义所在的代码区中，采用以上方法，才可以达到效果
int arrLength(int arr[]){
  return (int)(sizeof(arr) / sizeof(arr[0]));
}
*/

void swapArrElement(int arr[], int len, int index1, int index2){
  if(index1 >= len || index2 >= len){
    return;
  }
  int tmp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = tmp;
}

