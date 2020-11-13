#include "func.h"

void training_umask()
{
	create_defdir();
	system("clear");

    printf("이번에 학습할 명령어는 'umask'입니다. umask는 파일이나 폴더가 생성될 때 기본 권한을 지정합니다.\n");
    next_line();
    printf("umask를 입력하여 현재의 umask 값을 확인해 보세요.\n");
    run_command("umask");

    printf("혹시 ls -al 를 기억하시나요? 결과에 -rw-r--r-- 같은 것을 본 기억이 나시나요?\n");
    next_line();
    printf("바로 그 권한이 umask를 통해서 정해집니다.\n");
    next_line();
    printf("기본 권한은 아래의 계산 결과로 정해집니다.\n");
    printf("디렉토리 = 0777 - umask\n");
    printf("  파일 = 0666 - umask\n");
    next_line();
    printf("예를 들어 umask가 0022 이었다면 \n");
    printf("디렉토리 = 0777 - 0022 = 0755 = drwxr-xr-x\n");
    printf("  파일 = 0666 - 0022 = 0644 = -rw-r--r--\n");
    printf("이 됩니다.\n");
    next_line();

    printf("umask는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ umask 값\n");
    next_line();
    printf("umask 자체의 값이 권한이 아니라 0777, 0666에서 뺀 값인 점을 꼭 기억해주세요~\n");
    next_line();
    
    printf("umask 명령어에 대한 학습이 끝났습니다.\n");

	delete_defdir();
}