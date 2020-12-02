#include "func.h"


void next_quit()
{
        char select[CMD_SIZE];
        printf("\n다음 명령어를 학습하시려면 Enter를, 종료하시려면 'q'를 입력하세요.\n");
        fgets(select, sizeof(select), stdin);
        select[strlen(select)-1] = '\0';
        if (!strncmp(select, "q", 1) && strlen(select) == 1)
        {
                printf("종료를 선택하셨습니다.\n\n");
                exit(0);
        }
        else
        {
                printf("진행을 선택하셨습니다.\n\n");
                return;
        }
}
