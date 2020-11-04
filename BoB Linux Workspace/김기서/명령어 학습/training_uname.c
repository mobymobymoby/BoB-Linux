#include "common_func.h"

void training_rm()
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

	printf("이번에 학습할 명령어는 'uname'입니다. uname은 시스템의 정보를 출력해줍니다.");
	getchar();
	printf("uname 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ uname [옵션]");
	getchar();
	printf("옵션에는 여러가지가 있으나 -a 옵션이 가장 널리 사용됩니다.\n");
	printf("-a, --all: 모든 내용을 출력");
	getchar();
	printf("uname을 입력하여 내용을 확인해보세요.");
	run_command("uname");

	printf("단순히 uname 만 입력하면 현재 시스템이 어떤 커널을 사용하는지만 출력합니다.\n");
	printf("이번에는 -a 옵션을 사용하여 전체 내용을 확인해보세요.");
	run_command("uname -a");

	printf("uname -a 로 전체 정보를 확인 할 수 있습니다.\n");
	printf("띄어쓰기 단위로 각각\n");
	printf("커널 호스트명 커널릴리즈버전 커널빌드버전과빌드날짜 아키텍처 운영체제\n");
	printf("입니다.");

	printf("uname 명령어에 대한 학습이 끝났습니다.\n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}