#include "func.h"

void training_runlevel(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("runlevel 명령어는 런레벨(RunLevel)을 확인하는 명령어입니다.\n");
    printf("런레벨에 관한 내용은 init 명령어 트레이닝을 참고하시면 됩니다.\n");
    next_line();
    
    printf("[실습] runlevel 명령어를 입력해보세요.\n");
    fake_run_command("runlevel");
    next_line();

    printf("왼쪽에 표기된 것이 이전의 런레벌이고, \n");
    printf("오른쪽에 표기된 것이 현재 런레벨입니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}