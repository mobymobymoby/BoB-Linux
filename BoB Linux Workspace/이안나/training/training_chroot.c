#include <stdio_ext.h>
#include "common_func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_chroot(void)
{
	char test[20]; 
	char test2[20];

	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	char dir_buf[DIR_SIZE];
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());
	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	chdir(def_dir);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    //실습할 파일&디렉토리 제공
    system("");


	printf("이번에 학습할 명령어는 'chroot'입니다. \n\n");
	getchar();
	printf("chroot는 루트로 사용할 디렉토리를 변경할 때 사용하는 명령입니다.\n루트 디렉토리란 유닉스 계열 운영 체제에서 사용되는 개념이며\n컴퓨터 파일 시스템 계층 구조의 첫번째 또는 최상위 디렉토리를 의미합니다.\n\n");
	getchar();
	printf("chroot 명령어는 다음과 같은 형식으로 사용됩니다.\n$ chroot [option] newroot [command [arg]...]\n또는\n$ chroot option\noption은 해당 명령어에 지정할 옵션,\nnewroot는 새롭게 지정할 루트 디렉토리,\ncommand와 arg는 선택 사항이며 루트 디렉토리를 변경한 후\n해당 루트를 기반으로 실행할 명령어를 입력하여 사용합니다.\n\n");
	getchar();
	printf("chroot에서 자주 사용하는 옵션은 다음과 같습니다.\n --help : 명령어의 도움말을 표시합니다.\n --version : 명령어의 버전 정보를 표시합니다.\n\n");
	getchar();
	printf("chroot 명령어를 사용해 현재 디렉토리를 루트 디렉토리로 변경해보세요.\n");

	printf("현재 디렉토리의 경로는 \'%s\'입니다.\n\n", def_dir);

	strcat( strcat(test2, "chroot "), def_dir);

	while(1){
	getcwd(dir_buf, sizeof(dir_buf));
	printf("Trainer@BoB:%s$ ", dir_buf);
	scanf("%s", test);
		if (strcmp(test, test2) ) {
			printf("\n잘 입력하셨습니다.\n\n");
			__fpurge(stdin);
			break;
		}
		printf("잘못된 명령어를 입력하셨습니다.\n");
		__fpurge(stdin);
	}

	getchar();
	printf("성공적으로 변경이 되었다면 현재 위치는 루트인 '/'로 표시될 것입니다.\n\n");
	getchar();
	printf("chroot는 보통 때에 자주 사용되는 명령어는 아니지만\nchroot로 루트 환경을 새로 구축해 기존 시스템에 영향을 미치지 않게 작업을 하고싶은 경우\n테스트 및 개발, 의존성 제어, 호환성, 복구, 권한 분리의 목적으로 사용됩니다.\n\n");
	getchar();
	printf("chroot 명령어에 대한 학습이 끝났습니다.\n");

    snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
}

int main()
{
	training_chroot();
	next_quit();
	printf("이 메시지가 출력된다면 next 기능이 정상적으로 실행된 것\n");
	return 0;
}
