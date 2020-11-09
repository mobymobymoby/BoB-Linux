#include "func.h"

void training_halt(void)
{
    create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("halt 명령어는 시스템을 종료하는 명령어입니다.\n");
    next_line();

    printf("주의해야 할 점은 시스템만 종료되고, 시스템의 전원은 꺼지지 않는다는 점입니다.\n");
    printf("대체 명령어로 'init', 'shutdown' 명령어 사용을 권장드립니다.\n");
    next_line();

    printf("[실습] halt 명령어를 사용하여 시스템을 종료해보세요.\n(실제 적용되지는 않습니다.)\n");
    fake_run_command("halt");
    next_line();

    printf("비슷하게 시스템 종료를 수행하는 명령어로는 'shutdown', 'init', 'poweroff' 가 있으며,\n");
    printf("시스템 재부팅을 수행하는 명령어로는 'shutdown', 'init', 'reboot'가 있습니다.\n");
    next_line();
    
    delete_defdir();
    printf("고생하셨습니다!\n");
}