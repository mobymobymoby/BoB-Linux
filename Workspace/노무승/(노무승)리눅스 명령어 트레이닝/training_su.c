#include "func.h"

void training_su(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("su 명령어는 사용자를 전환하기 위한 명령어입니다.\n");
    next_line();

    printf("'su [전환할 사용자 이름]' 과 같이 사용합니다.\n");
    printf("위 예시와 같이 사용하면 전환하기 전 사용자 환경변수를 사용합니다.\n");
    next_line();

    printf("[실습] su 명령어를 사용해 root 사용자로 전환해보세요. (su [전환할 사용자 이름])\n");
    fake_run_command("su root");
    printf("Password:\n");
    printf("Trainer@BoB:#\n");
    next_line();

    printf("'su - [전환할 사용자 이름]' 과 같이 중간에 - 를 추가하면\n");
    printf("해당 사용자의 홈 디렉터리로 이동합니다.\n");
    printf("이는 해당 전환 대상 사용자의 환경 변수를 사용하는 것을 의미합니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}
