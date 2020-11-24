#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_redirection(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("이번에 학습할 명령어는 입출력 'redirection'입니다.\n");
	next_line();
	printf("리다이렉션은 어떤 프로세스의 입/출력을 표준 입출력이 아닌\n다른 입출력으로 변경할 때 사용합니다.\n");
	next_line();
	printf("리다이렉션을 사용해 다른 출력으로 변경하면, 출력 결과를 파일로 저장하거나\n파일의 내용을 어떠한 프로세스의 입력으로 사용할 수 있습니다.\n");
	next_line();
	printf("리다이렉션의 종류는 다음과 같습니다.\n\n");
	printf(" > : 프로세스의 출력을 표준 출력에서 다른 출력으로 변경합니다.\n >> : 프로세스의 출력을 지정한 출력(보통 파일)에 추가합니다.\n");
	printf(" < : 프로세스의 입력을 표준 입력에서 다른 입력으로 변경합니다.\n << : 기호 뒤에 지정한 문자열을 입력으로 받아 \n");
	printf("      해당 문자열이 나오기 전까지를 표준 입력을 삼아 해당 내용을 출력합니다.\n");
	next_line();
	printf("리다이렉션은 보통 다음과 같은 형식으로 사용합니다.\n$ [입/출력 관련 명령어] [리다이렉션 기호] [출력(파일)]\n");
	next_line();
	printf("터미널에 텍스트를 출력하는 echo 명령의 출력을 변경하여\n입력한 문자열을 file로 출력되게 해봅시다.\n");
	next_line();
	printf("[실습] 'echo' 명령어와 출력 변경 리다이렉션 '>' 를 사용하여\n'hello' 문자열을 'file' 파일로 출력해보세요.\n");
	printf("$ echo [문자열] > [대상 파일]\n");
	run_command("echo hello > file");
	next_line();
	printf("[실습] cat file로 'hello'가 'file'파일에 출력된 결과를 확인하세요.\n");
	just_run_command("cat file");
	printf("\n[실습] 'echo' 명령어와 출력 변경 리다이렉션 '>>' 를 사용하여\n'linux' 문자열을 'file' 파일에 텍스트를 추가해보세요.\n");
	printf("$ echo [문자열] >> [대상 파일]\n");
	run_command("echo linux >> file");
	next_line();
	printf("cat file로 파일 내용을 확인하면 입력한 텍스트가 추가되어 저장된 것을 볼 수 있습니다.\n");
	printf("[실습] 'cat file'을 입력해보세요.\n");
	run_command("cat file");
	next_line();
	printf("방금 리다이렉션으로 내보낸 텍스트인 'hello'와 'linux'가 출력되었을 것입니다.\n");
	next_line();
	printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
	printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
	next_line();
	printf("\"redirection\" 학습이 끝났습니다.\n");
	printf("고생하셨습니다.\n");
		

	delete_defdir();
}

