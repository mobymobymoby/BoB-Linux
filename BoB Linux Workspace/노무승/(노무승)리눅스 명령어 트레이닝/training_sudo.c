#include "func.h"

void training_sudo(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("sudo 명령어는 root 권한을 획득하기 위한 명령어입니다.\n");
    next_line();
    
    printf("root 권한은 리눅스의 최상위 권한으로써,\n");
    printf("리눅스 시스템 자체를 건드릴 수 있으므로 사용에 주의가 필요합니다.\n");
    next_line();
    
    printf("특정 명령어를 root 권한으로 실행하고 싶다면\n");
    printf("'sudo [명령어]'를 입력하면 됩니다.\n");
    next_line();

    printf("[실습] bash 명령어를 root 권한으로 실행시켜봅시다.\n");
    fake_run_command("sudo bash");
    next_line();
    // 트레이닝 1

    printf("일반 유저에서 root 유저로 전환하고 싶다면\n");
    printf("'sudo -s' 명령어를 입력하면 됩니다.\n");
    next_line();

    printf("[실습] sudo 명령어를 이용해 일반 유저에서 root 유저로 전환해봅시다.\n");
    fake_run_command("sudo -s");
    printf("[sudo] password for Trainer:\n");
    printf("Trainer@BoB:#\n");
    next_line();
     // 트레이닝 2   

    printf("root 유저로 바뀌면 명령줄 왼쪽의 문구가\n");
    printf("'$'에서 '#'으로 바뀐 것을 볼 수 있습니다.\n");
    next_line();

    printf("sudo 명령어로 권한 상승시, '/etc/sudoers' 파일을 참조하며\n");
    printf("해당 파일에 기록된 사용자만 root 권한 상승이 가능합니다.\n");
    printf("기록되지 않은 사용자에서 root 권한 상승을 하게 되면\n");
    printf("'{계정이름} is not in the sudoers file.' 라는 에러 문구가 뜨게 됩니다.\n");
    next_line();

    printf("권한 상승이 허용된 사용자는 다음과 같이 기록됩니다.\n");
    printf("{계정 이름} ALL=(ALL:ALL) ALL\n");
    next_line();

    printf("참고로 다른 사용자로 변경하는 명령어로는 'su' 명령어가 있습니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}
