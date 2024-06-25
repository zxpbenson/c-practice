#include<stdio.h>
int main(){
    void test(int& r);
    int i =  1;
    printf("%d\n", i);
    printf("%p\n", &i);
    test(i);
    printf("%d\n", i);
}

void test(int &r){
    printf("%d\n", r);
    printf("%p\n", &r);
    r += 1;
}


