#include<stdio.h>
int main(){
    void test(const int* const r);
    int i =  1;
    printf("%d\n", i);
    printf("%p\n", &i);
    test(&i);
    printf("%d\n", i);
}

void test(const int* const r){
    printf("%d\n", *r);
    printf("%p\n", r);
    //r += 1;
}


