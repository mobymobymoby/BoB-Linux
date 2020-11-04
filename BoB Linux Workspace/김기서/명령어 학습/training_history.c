#include "common_func.h"

void training_history()
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

    printf("이번에는 쉘의 history 기능에 대해 배워보겠습니다.");
    getchar();
    printf("쉘에는 history 라고 하여 이전에 입력하였던 명령어를 기억하고 쉽게 다시 사용할 수 있는 기능을 제공합니다.");
    getchar();
    printf("위 방향키를 누르면 바로 직전에 입력한 명령어가 나오게 됩니다. 위로 더 누르면 더 이전, 아래로 누르면 다시 최근에 입력한 명령어를 시간 순으로 볼 수 있습니다.");
    getchar();
    printf("사용한 명령어는 각자의 홈 디렉토리의 .bash_history 파일에 저장이 됩니다.\n");
    printf("최대 저장되는 개수는 HISTSIZE 라는 환경 변수를 확인해 보면 됩니다.");
    getchar();
    printf("echo $HISTSIZE 를 입력해 보세요.");
    run_command("echo $HISTSIZE");
    printf("1000\n");

    printf("HISTSIZE 만큼 사용한 명령어를 저장을 할 수 있습니다.");
    getchar();
    printf("방향키로 입력했던 명령어를 찾아도 되지만, history 기능은 더욱 편리한 옵션들을 제공합니다.");
    getchar();
    printf("!!  : 마지막으로 실행한 명령문 실행\n");
    printf("!n  : n번째 명령어 실행\n");
    printf("!string : string으로 시작하는 가장 최근의 명령문 실행");
    getchar();
    printf("!!을 입력해 보세요.");
    run_command("!!");
    printf("1000\n");

    printf("좀 전에 실행하였던 echo $HISTSIZE 가 다시 수행된 것을 볼 수 있습니다.");
    getchar();

    printf("history 기능에 대한 학습이 끝났습니다.\n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}