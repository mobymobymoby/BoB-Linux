#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "common_func.h"

void training_cat(void)
{
	// 초기 작업 디렉토리 설정
	char def_dir[DIR_SIZE];
	// rst_dir은 앞에 mkdir, rm -rf의 명령어가 더 들어가기 때문에 문자열의 길이를 10 늘려줌
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];

	// 현재 사용자 계정을 %s 위치에 삽입하여 디폴트 디렉토리 설정
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	// 디폴트 디렉토리가 이미 있을 경우를 대비하여 삭제하는 명령어
	// rm -rf [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	// 디폴트 디렉토리를 생성
	// mkdir [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	// 디폴트 디렉토리로 change directory
	chdir(def_dir);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	system("echo 'Hello' > hello.txt");
	system("echo 'BoB-Linux' > bob.txt");
	int n = 0;
	printf("이번에 학습할 명령어는 'cat'입니다.\ncat 명령어는 'concatenate'의 약자로, 두 개 이상의 파일을 연결(concatenate)하여 출력할 때 사용합니다.\n");
	getchar();
	printf("간단하게 생각하면, 여러 파일의 내용을 터미널로 연결시켜 출력한다고 보면 됩니다.\n");
	getchar();
	printf("기본 사용법은 다음과 같습니다.\n$ cat [옵션] [파일명]\n");
	getchar();
	printf("다음은 현재 디렉토리에 있는 파일들의 목록입니다.\n");
	printf("\n");
	system("ls");
	getchar();
	
	printf("hello.txt 파일의 내용을 cat 명령어를 이용해 출력해보세요.\n");
	run_command("cat hello.txt");

	printf("hello.txt의 내용인 \"Hello\"가 출력되었습니다.");
	printf("\n");
	printf("cat 명령어는 한 번에 두 개의 파일을 연결해서 출력할 수도 있습니다.\n그럴 때에는 간단히 파일명을 띄어쓰기로 구분해서 나열하면 됩니다.\n");
	getchar();
	
	printf("$ cat [옵션] [파일1] [파일2] [파일3] ...\nhello.txt 파일과 bob.txt 파일을 한 번에 출력해보세요.(hello.txt 다음에 bob.txt를 쓰세요)\n");
	run_command("cat hello.txt bob.txt");
	
	printf("hello.txt의 내용인 \"Hello\"와 bob.txt의 내용인 \"BoB-Linux\"가 출력됩니다.\n");
	getchar();
	
	printf("cat은 보통 '리다이렉션(redirection)' 이라는 기호 '>'와 함께 자주 쓰입니다.\n지금까지는 간단히 터미널에 파일의 내용을 출력시켰지만, > 기호를 이용하면 특정 파일의 내용을 다른 파일에 연결할 수 있습니다.\n");
	getchar();
	
	printf("사용법은 다음과 같습니다.\n$ cat [파일 1] [파일 2] ... [파일 n] > [대상 파일명]\n");
	getchar();
	
	printf("해당 사용법은 [파일 1] [파일 2] ... [파일 n] 까지의 모든 내용을 합쳐, [대상 파일명]로 만듭니다.\n만약 [대상 파일명]이 이미 존재 한다면, 이미 존재하는 파일의 내용을 [파일 1] [파일 2] ... [파일 n]로 덮어 씌웁니다.\n");
	getchar();
	
	printf("cat 명령어를 이용하여 hello.txt와 bob.txt 파일의 내용을 test.txt로 합쳐보세요.\n");
	run_command("cat hello.txt bob.txt > test.txt");
	
	printf("아래의 내용은 새로 만들어진 test.txt 파일을 cat 명령어를 통해 출력한 내용입니다.\n");
	printf("\n");
	system("cat test.txt");
	getchar();
	
	printf("두 파일의 내용이 합쳐졌음을 알 수 있습니다. 즉, cat hello.txt bob.txt의 출력 결과가 test.txt 파일에 저장(연결)됩니다.\n");
	getchar();
	
	printf("cat을 이용해 이미 존재하는 파일에 덮어쓰는게 아닌, 내용을 추가해 덧붙일 수 있습니다.\n");
	getchar();
	
	printf("사용법은 다음과 같습니다.\n$ cat [파일 1] >> [대상 파일]\n");
	getchar();

	printf("만약 [파일 1]의 내용이 \"Linux\"고, [대상 파일]의 내용이 \"BoB\"이라면 명령어를 실행 후 [대상 파일]의 내용은\n");
	getchar();
	
	printf("\"BoB\"\n\"Linux\"\n가 됩니다. 여기서 주의할 점은 \"BoBLinux\"나 \"BoB Linux\"가 아닌, '개행(new line)'으로 두 파일이 구분된다는 점 입니다.\n");
	getchar();
	
	printf("리다이렉션에 대해서는 심화 명령어 트레이닝에서 다시 한 번 다루게 됩니다.\n");
	getchar();
	
	printf("cat의 옵션은 여러 가지가 있습니다. 나열하면 다음과 같습니다.\n");
	getchar();
	
	printf("-b : 줄번호를 화면 왼쪽에 출력하지만 비어있는 행은 출력하지 않습니다.\n");
	printf("-n : 줄번호를 화면 왼쪽에 출력하고, 비어있는 행도 출력합니다.\n");
	printf("-s : 연속되는 2개 이상의 빈 행을 하나의 행으로 출력합니다.\n");
	printf("-E : 행마다 끝에 $ 문자를 출력합니다.\n");
	printf("-e : 제어 문자를 ^ 형태로 출력하면서, 각 행의 끝에 $를 출력합니다.\n");
	getchar();
	
	printf("cat 명령어는 자주 쓰게 될 것이므로, 여러 가지의 텍스트 파일을 이용해 연습하면 좋습니다.\n");
	getchar();
	printf("가장 많이 쓰이는 용법은 cat 명령어를 통해 파일의 내용을 보거나, 리다이렉션 하여 파일의 내용을 변경하는 것 입니다.\n");
	getchar();
	printf("cat 명령어 학습이 끝났습니다.\n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}
