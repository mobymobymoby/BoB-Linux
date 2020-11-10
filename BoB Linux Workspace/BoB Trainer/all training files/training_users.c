#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_users(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("이번에 학습할 명령어는 'users'입니다.\n\n");
	next_line();
	printf("users는 시스템에 로그인되어 있는 사용자를 출력할 때 사용하는 명령어 입니다.\n\n");
	next_line();
	printf("users명령어는 보통 다음과 같은 형식으로 사용됩니다.\n$ users\n또는\n$ users [옵션]\n\n");
	next_line();
	printf("users에서 사용하는 옵션은 다음과 같습니다.\n --help : 명령어의 도움말을 표시합니다.\n --version : 명령어의 버전 정보를 표시합니다.\n\n");
	next_line();
	printf("users 명령을 사용하여 시스템에 로그인 되어있는 사용자를 출력해보세요.\n\n");
	run_command("users");
	next_line();
	printf("현재 로그인된 사용자는 %s 이므로\n", getlogin());
	printf("성공적으로 출력이 되었다면 %s가 출력되었을 것입니다.\n\n", getlogin());
	next_line();
	printf("users 명령어에 대한 학습이 끝났습니다.");

    delete_defdir();
}
