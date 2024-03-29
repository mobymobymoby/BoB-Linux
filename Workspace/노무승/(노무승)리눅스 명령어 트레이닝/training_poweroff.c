#include "func.h"

void training_poweroff(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("poweroff 명령어는 시스템을 종료하는 명령어입니다.\n");
    next_line();

    printf("poweroff 명령어는 하드디스크와 메모리를 동기화 시키지 않고 바로 종료하기 때문에,\n");
    printf("poweroff 명령어는 가급적 사용하지 않는 것이 좋습니다.\n");
    next_line();

    printf("대체 명령어로 'init', 'shutdown' 명령어 사용을 권장드립니다.\n");
    next_line();

    printf("[실습] poweroff 명령어를 사용하여 시스템을 종료해보세요.\n(실제 적용되지는 않습니다.)\n");
    fake_run_command("poweroff");
    next_line();

    printf("비슷하게 시스템 종료를 수행하는 명령어로는 'shutdown', 'init', 'halt' 가 있으며,\n");
    printf("시스템 재부팅을 수행하는 명령어로는 'shutdown', 'init', 'reboot'가 있습니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}