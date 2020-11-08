#include <stdio_ext.h>

void next_line(void)
{
    getchar();
    __fpurge(stdin);
}
