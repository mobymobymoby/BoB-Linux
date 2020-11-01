#include "common_func.h"


void next_quit()
{
        char select[CMD_SIZE];
        printf("\n?ㅼ쓬 紐낅졊?대? ?숈뒿?섏떆?ㅻ㈃ Enter瑜? 醫낅즺?섏떆?ㅻ㈃ 'q'瑜??낅젰?섏꽭??\n");
        fgets(select, sizeof(select), stdin);
        select[strlen(select)-1] = '\0';
        if (!strcmp(select, "q"))
                exit(0);
        else
                return;
}