#include "common_func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_mv(void)
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

    //실습할 파일&디렉토리 제공
    system("mkdir directory1");
    system("touch file1 directory1/file1");


	printf("이번에 학습할 명령어는 'cp'입니다.\n\n");
	getchar();
	printf("cp는 파일이나 디렉터리를 복사할 때 사용하는 명령입니다.\ncp 명령어는 다음과 같은 형식으로 사용합니다.\n$ cp [options] source(s) destination\n");
	getchar();
	printf("option은 선택 사항이며 해당 명령어에 지정할 옵션,\nsources는 복사할 대상 파일명 또는 디렉토리명,\ndestination은 복사되어 생성될 파일명 또는 디렉토리명을 입력하여 사용합니다.\n\n");
	getchar();
	printf("cp에서 자주 사용되는 옵션은 다음과 같습니다.\n");
	getchar();
	printf("-r : 복사 대상이 디렉토리인 경우 하위 디렉토리 및 파일까지 함께 복사합니다.\n-i : 복사하여 생성될 파일명과 동일한 파일명이 존재할 경우 덮어 쓸 것인지 물어봅니다. (yes - y /no - n)\n-p : 원본 파일의 소유권, 그룹, 허가권 등을 함께 복사합니다.\n-a : 파일의 속성, 링크 정보들을 그대로 유지하고 그 하위 디렉토리까지 전부 복사합니다.\n-v : 파일을 복사하기 전에 각각 파일명을 표시합니다.\n-u : 복사할 디렉터리에 동일한 파일명이 있을 경우 검사하여 해당 파일이 최신 파일이면 복사하지 않습니다.\n-b : 덮어쓸 때 백업본 파일을 만듭니다.\n\n");
	getchar();
	printf("현재 폴더에 file1이 있습니다.\n");

	system("ls -al");
	getchar();

	printf("cp 명령을 입력해 현재 디렉토리의 파일 file1을 file2로 복사해 보세요.\n");
	run_command("cp file1 file2");
	printf("파일 목록을 출력하면 file1이 file2로 복사된 것을 확인 할 수 있습니다.\n");
	getchar();

	system("ls -al");
	getchar();

	printf("\n이번에는 옵션을 사용해 봅시다.\n");
	getchar();
	printf("-i 옵션을 사용해 동일한 파일명이 존재할경우, 덮어쓸 것인지 확인 절차를 받을 수 있습니다.\n");
	getchar();

    printf("[directory1]\n");
    system("ls -l directory1");

	printf("\n\ndirectory1에는 file1이 들어있습니다.\ncp 명령과 -i 옵션을 사용해 directory1/file1을 현재 폴더의 file1으로 복사해보세요.\n");
	printf("(입력 후 묻는 절차에 y 혹은 n으로 답해보세요)\n");
	run_command("cp -i directory1/file1 file1");

	system("ls -al");
	getchar();

	printf("\n만약 y를 입력했다면 file1은 directory1의 file1으로 덮어 씌워졌을 것이고,\nn을 입력했다면 file1의 복사 작업이 수행되지 않았을 것입니다.\n\n");
	getchar();
	printf("이제 cp 명령을 사용해 디렉토리를 복사해봅시다.\n디렉토리를 복사할 때 -r 옵션을 사용하면, 해당 디렉토리의 하위 파일과 디렉토리도 함께 복사할 수 있습니다.\n\n");
	getchar();

	system("ls -al");
	getchar();
    printf("[directory1]\n");
    system("ls -l directory1");

	printf("\n\n현재 폴더에 directory1이 있고, directory1에는 file1이 있습니다.\ncp 명령과 -r 옵션을 사용해 directory1을 directory2로 현재 폴더에 복사해보세요.\n");
	run_command("cp -r directory1 directory2");
	printf("파일 목록을 출력하면 directory1이 directory2으로 복사되면서,\n하위 파일까지 함께 복사된 것을 볼 수 있습니다.\n\n");
	
	system("ls -al");
	getchar();
    printf("[directory2]\n");
    system("ls -l directory2");

	getchar();
	printf("\ncp 명령어에 대한 학습이 끝났습니다.");
	
    snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
}

int main()
{
	training_mv();
	next_quit();
	printf("next\n");
	return 0;
}
