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

    system("touch rm_test_file");
    system("mkdir rm_test_dir");

	printf("이번에 학습할 명령어는 'rm'입니다. rm 명령어는 ReMove의 약자로, 파일을 삭제하는 명령어입니다.");
	getchar();
	printf("rm 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ rm [옵션] 삭제할 파일 이름");
	getchar();
	printf("rm 명령어를 입력하여 'rm_test_file' 파일을 삭제해보세요.\n");
	run_command("rm rm_test_file");

	printf("rm 명령어의 옵션은 아래와 같습니다.\n");
	printf("-f, --force       : 강제 삭제\n");
	printf("-i, --interactive : 삭제 시 확인 절차를 거침\n");
	printf("-r, --recursive   : 디렉토리를 포함하여 삭제\n");
	printf("-v, --verbose     : 삭제 파일의 정보를 화면에 출력");
	getchar();
	printf("그냥 rm 만을 사용하면 디렉토리는 삭제를 할 수 없습니다. -r 혹은 -R 옵션을 주어야만 디렉토리 삭제가 가능합니다.");
	getchar();
	printf("rm -r 을 이용하여 'rm_test_dir' 디렉토리를 삭제해보세요.");
	run_command("rm -r rm_test_dir");
    
	printf("rm 명령어는 파일을 삭제할 수 있기 때문에 항상 조심히 사용하여야 합니다. 한 번 삭제된 것은 돌아오지 않습니다.");
	getchar();
	printf("자신에게 권한이 없는 파일도 삭제가 불가능합니다.");
	getchar();
	printf("'rm -rf /*' 를 입력하라는 사람이 있다면 인성 검증이 시급합니다.");
	getchar();

	printf("rm 명령어에 대한 학습이 끝났습니다.\n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}