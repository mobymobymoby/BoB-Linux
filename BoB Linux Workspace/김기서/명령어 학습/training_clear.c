#include "common_func.h"

void training_clear()
{
	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];

	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	chdir(def_dir);

	printf("이번에 학습할 명령어는 'clear' 입니다. 말그대로 지우다(clear), 터미널 화면을 싹 지워줍니다.");
	getchar();
	printf("바로 clear를 입력해봅시다.");
	run_command("clear");

	printf("위에 있던 내용들이 다 지워졌나요? 어떤가요, 정말 쉽죠?");
	getchar();
	printf("항상 새 것과 같은 터미널에서 작업하고 싶다면 clear를 기억해주세요!");
	getchar();
	printf("Ctrl + L 로도 지울 수 있답니다.");
	getchar();

	printf("clear 명령어에 대한 학습이 끝났습니다.\n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}
