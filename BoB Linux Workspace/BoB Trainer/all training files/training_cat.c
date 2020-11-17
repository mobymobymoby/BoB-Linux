#include "func.h"

void training_cat(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	system("echo 'Hello' > hello.txt");
	system("echo 'rookie' > rookie.txt");

	printf("이번에 학습할 명령어는 'cat'입니다.\n");
    next_line();
    printf("cat 명령어는 'concatenate'의 약자로\n");
    printf("주로 파일 한 개 이상의 내용을 화면에 출력할 때 사용합니다.\n");
    next_line();
    printf("\"cat\" 명령어의 실행파일은 \"/usr/bin/cat\"으로 있습니다.\n");
    printf("'root' 디렉토리(폴더) 밑에 'usr' 디렉토리(폴더) 밑에 'bin' 디렉토리(폴더) 밑에 \"cat\"으로 있습니다.\n");
    next_line();
	printf("사용법은 \"cat [옵션] [파일명]\" 입니다.\n");
    printf("ex) cat file1 file2 file3\n");
	next_line();
	printf("다음은 현재 디렉토리에 있는 파일들의 목록입니다.\n");
	printf("\n");
	system("ls");
	next_line();
	
	printf("[실습] 'hello.txt' 파일의 내용을 \"cat\" 명령어를 이용해 출력해보세요.\n");
	just_run_command("cat hello.txt");
	printf("\n");
	printf("hello.txt의 내용인 \"Hello\"가 출력되었습니다.");
	next_line();
	printf("cat 명령어는 한 번에 두 개의 파일을 연결해서 출력할 수도 있습니다.\n\n");
    printf("그럴 때에는 간단히 파일명을 띄어쓰기로 구분해서 나열하면 됩니다.\n\n");
	printf("\"cat [옵션] [파일1] [파일2] [파일3] ...\"\n");
    next_line();
    printf("[실습]\"cat hello.txt rookie.txt\"를 입력하여 두 파일의 내용을 출력해보세요.\n");
	just_run_command("cat hello.txt rookie.txt");
	printf("\n'hello.txt'의 내용인 \"Hello\"와 'rookie.txt'의 내용인 \"rookie\"가 출력됩니다.\n");
	next_line();
	
	printf("cat은 보통 '리다이렉션(redirection)' 이라는 문자 '>'와 함께 자주 쓰입니다.\n");
    next_line();
    printf("지금까지는 간단히 터미널에 파일의 내용을 출력시켰지만\n");
    printf("'>' 문자를 이용하면 특정 파일의 내용을 다른 파일에 연결하여 마치 사용자가 입력한 것과 같은 효과를 냅니다.\n");
    next_line();
	printf("\"사용법 : cat [파일 1] [파일 2] ... [파일 n] > [대상 파일명]\"\n");	
	printf("해당 사용법은 [파일 1] [파일 2] ... [파일 n] 까지의 모든 내용을 합쳐\n");
    printf("[대상 파일명]으로 또 하나의 파일을 만듭니다.\n");
    printf("만약 [대상 파일명]이 이미 존재 한다면, 이미 존재하는 파일의 내용을 [파일 1] [파일 2] ... [파일 n]로 덮어 씌웁니다.\n");
	next_line();
	
	printf("[실습] \"cat\" 명령어를 이용하여 'hello.txt' 파일과 'rookie.txt' 파일의 내용을 'test.txt' 파일로 합쳐보세요.\n");
    printf("사용법 : cat [file1][file2] > [file3]\n");
	run_command("cat hello.txt rookie.txt > test.txt");
	
	printf("\n아래의 내용은 새로 만들어진 test.txt 파일을 cat 명령어를 통해 출력한 내용입니다.\n\n");
	system("cat test.txt");
	next_line();
	
	printf("두 파일의 내용이 합쳐졌음을 알 수 있습니다.\n");
    printf("즉, \"cat hello.txt rookie.txt\"의 출력 결과가 'test.txt' 파일에 입력되어 저장(연결)됩니다.\n");
    next_line();
	printf("cat을 이용해 이미 존재하는 파일에 덮어쓰는게 아닌, 내용을 추가해 덧붙일 수 있습니다.\n");
    printf("\"사용법 : cat [파일 1] >> [대상 파일]\"\n");
    next_line();
	printf("만약 [파일 1]의 내용이 \"Training\"이고, \"[대상 파일]의 내용이 \"Linux\"라고 되어 있다면\n");
    printf("위의 명령어를 실행 후 [대상 파일]의 내용은 아래와 같습니다.\n\n");	
	printf("\"Training\"\n\"Linux\"\n");
    next_line();
    printf("여기서 주의할 점은 두 파일의 내용 사이에 '개행(new line)'이 넣어져 구분된다는 것입니다.\n");
	next_line();
	
	printf("리다이렉션에 대해서는 심화 명령어 트레이닝에서 다시 한 번 다루게 됩니다.\n");
	next_line();
	
	printf("cat의 옵션은 다음과 같습니다.\n");
	next_line();
	
	printf("-b : 줄번호를 화면 왼쪽에 출력하지만 비어있는 행은 출력하지 않습니다.\n");
	printf("-n : 줄번호를 화면 왼쪽에 출력하고, 비어있는 행도 출력합니다.\n");
	printf("-s : 연속되는 2개 이상의 빈 행을 하나의 행으로 출력합니다.\n");
	printf("-E : 행마다 끝에 $ 문자를 출력합니다.\n");
	printf("-e : 제어 문자를 ^ 형태로 출력하면서, 각 행의 끝에 $를 출력합니다.\n");
	next_line();
	
	printf("cat 명령어는 자주 쓰게 될 것이므로, 여러 가지의 텍스트 파일을 이용해 연습하면 좋습니다.\n\n");
	printf("가장 많이 쓰이는 구문은 cat 명령어를 통해 파일의 내용을 보거나\n");
    printf("리다이렉션하여 파일의 내용을 변경하는 것 입니다.\n");
	next_line();
    printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
    printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
    next_line();
	printf("cat 명령어 학습이 끝났습니다. 고생하셨습니다.\n");

	delete_defdir();
}
