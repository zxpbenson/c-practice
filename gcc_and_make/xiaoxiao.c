#include <stdio.h>
int main()
{
    char input;
    while(1)
    {
        scanf("%c", &input);
        if(input == '\n') continue;
        printf("笑笑刚才笑嘻嘻的输入了 %c\n", input);
        if(input == '0') break;
    }
}
