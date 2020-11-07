#include "common_func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_env(void)
{
	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());
	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	chdir(def_dir);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("이번에 학습할 명령어는 'env'입니다. \n\n");
	getchar();
	printf("env는 환경번수를 출력하고 수정할 수 있는 명령어입니다.\n\n");
	getchar();
	printf("env 명령어는 다음과 같은 형식으로 사용합니다.\n$ env 'NAME'='VALUE'\n또는\n$ env\n옵션 없이 'env'만 입력할 경우 현재 환경 변수 목록을 출력합니다.\n\n");
	getchar();
	printf("env 명령어를 입력해 'myVal'의 변수 명으로 'valueOfEnv' 라는 값을 저장하도록 선언해보세요.\n\n");

	run_command("env myVal=valueOfEnv");
	getchar();

	printf("출력된 변수 목록을 살펴보면 myVal이 성공적으로 추가된 것을 확인할 수 있습니다. \n\n");
	getchar();

	printf("이제 선언된 환경변수를 수정해봅시다.\n\n");
	getchar();
	printf("env 명령어를 입력해 'myVal'의 변수를 'modifiedValue' 라는 값으로 수정해보세요.\n\n");

	run_command("env myVal=modifiedValue");
	getchar();

	printf("myVal의 값이 성공적으로 수정된 것을 확인할 수 있습니다.\n");
	getchar();

	printf("env는 -u 옵션을 사용해 환경 변수를 해제할 수 있습니다.\n");
	printf("'env -u myVal'을 입력해보세요.\n");

	run_command("env -u myVal");
	getchar();

	printf("myVal의 값이 성공적으로 해제된 것을 확인할 수 있습니다.\n");
	getchar();

	printf("env 명령어에 대한 학습이 끝났습니다.");

    snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
}

int main()
{
	training_env();
	next_quit();
	printf("이 메시지가 출력된다면 next 기능이 정상적으로 실행된 것\n");
	return 0;
}
