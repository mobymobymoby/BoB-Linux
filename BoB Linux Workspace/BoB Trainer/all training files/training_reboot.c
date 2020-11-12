#include "func.h"

void training_reboot(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("reboot 명령어는 시스템을 재부팅하는 명령어입니다.\n");
    printf("'-f 옵션을 주어 강제 재부팅이 가능합니다.\n");
    next_line();

    printf("[실습] reboot 명령어를 사용하여 시스템을 '강제 재부팅'해보세요.\n(실제 적용되지는 않습니다.)\n");
    fake_run_command("reboot -f");
    next_line();
    
    printf("비슷하게 시스템 재부팅을 수행하는 명령어로는 'shutdown', 'init'이 있으며,\n");
    printf("시스템 종료를 수행하는 명령어로는 'shutdown', 'init', 'halt', 'poweroff' 가 있습니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}