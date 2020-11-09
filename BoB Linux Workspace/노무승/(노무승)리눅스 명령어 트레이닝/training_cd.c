#include "func.h"

void training_cd(void){
	create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("cd 명령어는 작업 디렉터리를 옮길 때 사용하는 명령어입니다.\n");
    next_line();

    mkdir("./test1");
    mkdir("./test2");
    // 테스트 폴더 생성

    printf("'cd [디렉터리 경로]' 형식으로 사용하며,\n");
    printf("디렉터리 경로를 지정할 때, 절대 경로와 상대 경로를 지정하여 사용합니다.\n");
    next_line();

    printf("절대 경로는 최상위 디렉터리부터 나열된 고유한 경로를 의미합니다.\n");
    printf("(ex. /etc/systemd)\n");
    printf("맨 앞의 /가 루트(최상위) 디렉터리를 의미하며,\n");
    printf("'cd /' 입력시, 루트 디렉터리로 이동하게 됩니다.\n");
    next_line();

    printf("[실습] cd 명령어를 사용해 /home/user/tr/test1 폴더로 이동해보세요.\n");
    printf("'cd /' 입력시, 루트 디렉터리로 이동하게 됩니다.\n");
    fake_run_command("cd /home/user/tr/test1");
    chdir("/home/user/tr/test1");
    next_line();
    // 절대 경로 트레이닝

    printf("상대 경로는 상대적인 경로로, 아래와 같은 지정 방식이 있습니다.\n");
    printf(". : 현재 작업 디렉터리를 의미\n");
    printf(".. : 현재 작업 디렉터의 상위 디렉터리를 의미\n");
    next_line();

    printf("예를 들어 './1234/' 는 현재 작업 디렉터리 하위의 1234 디렉터리를 의미하고,\n");
    printf("    (작업 디렉터리가 /etc 일 때, ./1234 는 /etc/1234와 같음.)\n");
    printf("'../1234/' 는 현재 작업 디렉터리 상위의 1234 디렉터리를 의미합니다.\n");
    printf("    (작업 디렉터리가 /etc 일 때, ../1234 는 /1234와 같음.)\n");
    next_line();

    printf("[실습] 상위 경로를 이용해 상위 디렉터리의 test2 디렉터리로 이동해보세요.\n");
    fake_run_command("cd ../test2");
    chdir("cd ../test2");
    next_line();
    // 상대 경로 트레이닝 

    printf("만약 현재 작업 디렉터리의 상위 디렉터리로 이동하고 싶다면 'cd ..' 을 입력하면 됩니다.\n");
    printf("[실습] 'cd ..'을 입력해 상위 디렉터리로 이동해보세요.\n");
    fake_run_command("cd ..");
    chdir("cd ..");
    next_line();
    // 상위 경로 트레이닝

    printf("이동하기 이전의 디렉터리로 되돌아가기 위해서는 'cd -'를 입력하면 됩니다.\n");
    printf("[실습] 'cd -'을 입력해 이전의 디렉터리로 되돌아가 보세요.\n");
    fake_run_command("cd -");
    chdir("cd -");
    next_line();
    // 이전 경로 트레이닝

    delete_defdir();
    printf("고생하셨습니다!\n");
}