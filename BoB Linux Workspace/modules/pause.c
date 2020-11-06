#include <stdio_ext.h>

void pause(void)
{
    getchar();
    __fpurge(stdin);
}
