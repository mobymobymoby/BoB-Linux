#include "func.h"

void next_line(void)
{
    getchar();
    __fpurge(stdin);
}
