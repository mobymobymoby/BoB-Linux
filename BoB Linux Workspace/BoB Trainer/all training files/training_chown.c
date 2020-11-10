#include <stdio_ext.h>
#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_chown(void)
{
	char test[20]; 
	char dir_buf[DIR_SIZE];

	create_defdir();

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    //실습할 파일&디렉토리 제공
    system("touch file1");

	printf("이번에 학습할 명령어는 'chown'입니다. \n\n");
	next_line();
	printf("chown는 파일이나 디렉토리의 소유권 및 그룹 소유권을 변경하는 명령어입니다.\n\n");
	next_line();
	printf("chown 명령어는 다음과 같은 형식으로 사용됩니다.\n$ chown [option] owner[:group] file(s)\noption은 선택 사항이며 해당 명령어에 지정할 옵션,\nowner은 소유권을 부여해줄 사용자,\ngroup은 선택 사항이며 소유권을 부여해줄 그룹,\nfile(s)는 소유권을 변경할 파일명을 입력하여 사용합니다.\n\n");
	next_line();
	printf("chown에서 자주 사용하는 옵션은 다음과 같습니다.\n -R, --recursive : 디렉토리 내부의 모든 하위 디렉토리와 파일의 소유 권한을 변경합니다.\n -c, --change : 변경 정보를 출력합니다.\n -f, --silent, --quite : 중요한 오류메시지가 아닌 경우 출력하지 않습니다.\n --version : 명령어의 버전 정보를 표시합니다.\n\n");
	next_line();

	system("ls -al");
	printf("\n현재 directory에 file1이 있습니다.\n\n");
	next_line();

	printf("chown 명령어를 사용해 file1의 소유자를 test로 변경해보세요.\n\n");

	while(1){
	getcwd(dir_buf, sizeof(dir_buf));
	printf("Trainer@BoB:%s$ ", dir_buf);
	scanf("%s", test);
		if (strcmp(test, "chown test file1")) {
			printf("\n잘 입력하셨습니다.\n\n");
			__fpurge(stdin);
			break;
		}
		printf("잘못된 명령어를 입력하셨습니다.\n");
		__fpurge(stdin);
	}

	next_line();

	printf("-rw-r--r--  1 test %s    0 mm월  dd hh:mm file1\n", getlogin());
	printf("\n명령어가 잘 실행되었다면 소유자가 위와 같이 변경되었을 것입니다.\n\n");
	next_line();

	printf("\nchown 명령어에서 owner를 지정할때 유저명, 그룹명을 직접 입력하기도 하지만,\n유저명, 그룹명 대신 UID, GID를 사용해서 소유권을 부여할 수도 있습니다.\n\n");
	next_line();
	printf("UID란 유저 아이디로 각 사용자마다 부여된 사용자 식별 번호이며,\n슈퍼 유저의 UID는 0입니다.\n각 사용자의 UID는 /etc/passwd에서 확인할 수 있습니다.\n\n");
	next_line();
	printf("마찬가지로 GID란 그룹 아이디로 각 그룹마다 부여된 그룹 식별 번호이며,\n슈퍼 그룹의 GID는 0입니다.\n각 그룹의 GID는 /etc/passwd와 /etc/group에서 확인할 수 있습니다.\n\n");
	next_line();
	printf("chown 명령어에 대한 학습이 끝났습니다.\n");

    delete_defdir();

}
