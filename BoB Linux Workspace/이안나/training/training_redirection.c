#include "common_func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_redirection(void)
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

	printf("이번에 학습할 명령어는 입출력 'redirection'입니다.\n\n");
	getchar();
	printf("리다이렉션은 어떤 프로세스의 입/출력을 표준 입출력이 아닌\n다른 입출력으로 변경할 때 사용합니다.\n리다이렉션을 사용해 다른 출력으로 변경하면, 출력 결과를 파일로 저장하거나\n파일의 내용을 어떠한 프로세스의 입력으로 사용할 수 있습니다.\n\n");
	getchar();
	printf("리다이렉션의 종류는 다음과 같습니다.\n - > : 프로세스의 출력을 표준 출력에서 다른 출력으로 변경합니다.\n - >> : 프로세스의 출력을 지정한 출력(보통 파일)에 추가합니다.\n - < : 프로세스의 입력을 표준 입력에서 다른 입력으로 변경합니다.\n - << : 기호 뒤에 지정한 문자열을 입력으로 받아 해당 문자열이 나오기 전까지를 표준 입력을 삼아 해당 내용을 출력합니다.\n\n");
	getchar();
	printf("리다이렉션은 보통 다음과 같은 형식으로 사용합니다.\n$ 입/출력관련명령어 리다이렉션기호 출력(파일)\n\n");
	getchar();
	printf("터미널에 텍스트를 출력하는 echo 명령의 출력을 변경하여\n입력한 문자열을 file로 출력되게 해봅시다.\n\n");
	getchar();
	printf("'echo' 명령으로 'hello' 문자열을, 출력 변경 리다이렉션 '>' 를 사용하여 'file'로 출력해보세요.\n\n");
	run_command("echo hello > file");
	getchar();
	printf("'echo' 명령으로 'linux' 문자열을, 출력 변경 리다이렉션 '>>' 를 사용하여 'file'에 텍스트를 추가해보세요.\n\n");
	run_command("echo linux >> file");
    getchar();
	printf("cat file로 파일 내용을 확인하면 입력한 텍스트가 파일로 저장된 것을 볼 수 있습니다.\n");
	printf("'cat file'을 입력해보세요.\n\n");
	run_command("cat file");
	getchar();
	printf("방금 리다이렉션으로 내보낸 텍스트인 'hello'와 'linux'가 출력되었을 것입니다.\n");
	getchar();
	printf("\nredirection 명령어에 대한 학습이 끝났습니다. \n");

    snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
}

int main()
{
	training_redirection();
	next_quit();
	printf("이 메시지가 출력된다면 next 기능이 정상적으로 실행된 것\n");
	return 0;
}
