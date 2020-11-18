#include "func.h"

void training_reboot(void)
{
	system("clear");
	create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("이번에 배울 명령어는 'reboot'입니다.\n");
	next_line();
	printf("reboot 명령어는 시스템을 재부팅하는 명령어입니다.\n");
	printf("'-f 옵션을 주어 강제 재부팅이 가능합니다.\n");
	next_line();

	printf("[실습] reboot 명령어를 사용하여 시스템을 '강제 재부팅'해보세요.\n(실제 적용되지는 않습니다.)\n");
	printf("$ reboot [옵션]\n");
	fake_run_command("reboot -f");
	next_line();

	printf("비슷하게 시스템 재부팅을 수행하는 명령어로는 'shutdown', 'init'이 있으며,\n");
	printf("시스템 종료를 수행하는 명령어로는 'shutdown', 'init', 'halt', 'poweroff' 가 있습니다.\n");
	next_line();
	
	printf("이러한 명령어들은 보통 관리자 권한으로 실행됩니다.\n");
	printf("이 말은 즉, 일반 유저들은 '시스템 종료'를 하지 못한다는 말입니다.\n");
	next_line();
	       
	printf("자기 마음대로 시스템을 종료하지 못한다는 것은 \n개인 PC를 쓰는 우리에게 매우 이상하게 느껴집니다\n");
	next_line();
	printf("하지만 리눅스 시스템은 개인용만이 아니라 \n여러 명이 사용하는 '서버'를 구축하는데 많이 사용합니다.\n\n");
	printf("만약 관리자가 아닌 일반 사용자가 시스템을 종료하게 된다면\n그 시스템 위에서 돌아가는 서버 또한 정지합니다.\n\n");
	next_line();
	       
	printf("이러한 불상사를 막기 위해 시스템 종료 명령어는 관리자 권한으로 실행됩니다.\n");
	next_line();
	       
	printf("reboot와 비슷한 명령어로는 'shutdown 명령어의 -r 옵션', 'init 6'가 있습니다.\n");  
	next_line();
	printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
	printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
	next_line();
	       
	printf("\"reboot\" 명령어의 학습이 끝났습니다.\n");
	printf("고생하셨습니다!\n");
	next_line();
	
	delete_defdir();
}
