#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "common_func.h"

void main(void)
{
	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];
	char wd[BUFSIZ];
	getcwd(wd,BUFSIZ);

	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);
	
	printf("\n\"pwd\" 명령어를 학습하겠습니다.\n");
	printf("\"pwd\" 명령어는 현재 작업 중인 디렉터리 경로를 절대 경로로 보여주는 명령어입니다.\n");
	getchar();
	printf("\"pwd\" 명령어는 'Print Working Directory'의 앞글자들만 따와서 조합한 것입니다.\n");
	printf("현재 자신이 어떤 디렉터리 경로에 있는 지 확인하고 싶을 때 사용합니다.\n");
	getchar();
	printf("\"pwd\" 명령어는 '-L' 옵션과 '-P' 옵션이 있습니다.\n\n");
	printf("'-L(--logical)' - 심볼릭을 포함하더라도 pwd 환경 변수를 사용해줍니다.\n");
	printf("'-P(--physical)' - 심볼릭 정보를 무시하고 출력해줍니다.\n");
	printf("'--help' - pwd 명령어의 사용법을 출력해줍니다.\n");
	printf("'--version' - pwd 명령어의 버전 정보를 출력해줍니다.\n");
	getchar();
	printf("\"pwd\" 명령어의 사용법은 'pwd [옵션]'와 같이 입력하면 됩니다.\n");
	printf("(옵션은 입력하지 않고 명령어만 입력해도 됩니다.)\n");
	printf("ex) pwd -L 또는 pwd --logical\n");
	getchar();
	printf("한 번 명령어를 입력하여 실습해보세요.\n");
	run_command("pwd");
	getchar();
	printf("위에 보이시는 '%s'가 현재 작업 중인 디렉터리 경로를 절대 경로로 보여준 것입니다.\n", wd);
	getchar();
	printf("\"pwd\" 명령어의 학습이 끝났습니다.\n");
	printf("\"pwd\" 명령어는 자주 사용하는 명령어들 중 하나입니다.\n");
	getchar();

	chdir(def_dir);
 	chdir("..");
	system(rm_dir);
}
