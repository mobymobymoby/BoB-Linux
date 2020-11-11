#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_export(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("이번에 학습할 명령어는 'export'입니다.\n\n");
	next_line();
	printf("export는 쉘 변수를 환경 변수로 내보낼 수 있도록 해주는 명령어입니다.\n\n");
	next_line();
	printf("export 명령어는 다음과 같은 형식으로 사용합니다.\n$ export 'NAME'='VALUE'\n또는\n$ export 'NAME'\n또는\n$ export\n'export'만 입력할 경우 현재 환경 변수 목록을 출력합니다.\n\n");
	next_line();
	printf("'myVal=value'를 입력해 'myVal'의 변수 명으로 'value' 라는 값을 저장하도록 선언해보세요.\n\n");
	run_command("myVal=value");
	next_line();
	printf("이제 'export myVal'를 입력해 셸 변수를 환경변수로 내보내보세요.\n\n");
	run_command("export myVal");
	next_line();
	printf("'export'라고 입력하면 현재 선언된 환경 변수들이 출력될 것 입니다.\n\n");
	run_command("export");
	next_line();
	printf("export 명령어에 대한 학습이 끝났습니다.\n");


    delete_defdir();
}