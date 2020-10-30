### cat.c
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define CMD_SIZE 40 // 최대 39개의 문자 입력
#define DIR_SIZE 40 // 최대 39개의 문자 입력
#define BUF_SIZE 102400

void hint(char valid_cmd[])
{
	printf("'%s'를 입력하세요.", valid_cmd);
}

int run_command(char valid_cmd[])
{	
	char cmd[CMD_SIZE];
	char dir_buf[DIR_SIZE];
	while (1)
	{
		printf("\n");
		getcwd(dir_buf, sizeof(dir_buf));
		printf("Trainer@BoB:%s$ ", dir_buf);
		int valid_len = strlen(valid_cmd);
		fgets(cmd, sizeof(cmd), stdin);
		
		// 나머지 입력 값 제거
        	cmd[strlen(cmd)-1] = '\0';
		
		// 입력값 검증 부분
		if (!strcmp(cmd, valid_cmd))
		{
			printf("잘 입력하셨습니다.");
			// 여기서 핵심은 system 함수의 인자로 valid_cmd가 입력된다는 것임. 즉 사용자의 입력값은 사용되지 않음
			system(valid_cmd);
			break;
		}
		// 사용자가 help를 입력했을 때 힌트
		else if (!strcmp(cmd, "help"))
		{
			// 힌트 출력, 힌트는 배열 valid_cmd를 출력하여 올바른 입력 값을 유도 
			hint(valid_cmd);
		}
		else
		{
			printf("잘못된 명령어를 입력하셨습니다.\n힌트를 보려면 'help'를 입력해주세요.");
		}

	}
	return 0;
}

int read_txt(char buf[], int n)
{
	// txt 파일을 읽어온 'buf' array에서 한 글자씩 읽어옴
	// 글자를 읽는 것은 '@'를 만나거나 파일의 끝(NULL)이 될 때 까지
	// 즉 @를 한 문단을 끝내는 플래그로 사용
	for (; buf[n] != '@' && buf[n] != '\0'; n++)
	{
		printf("%c", buf[n]);
		// 출력 버퍼 비우기. 출력 버퍼를 비우지 않으면 한 글자씩 출력되지 
		fflush(stdout);
		// 한 글자씩 출력되는 효과를 위한 sleep. 0으로 한다면 한번에 출력됨
		usleep(300);
	}
	// 다음 배열의 인덱스로 넘어가기 위해 n+1을 리턴
	return n + 1;
}


void training_cat(void)
{
	FILE* fp;
	fp = fopen("cat.txt", "r");
	char buf[BUF_SIZE] = { 0, };
	fread(buf, sizeof(buf), 1, fp);

	// 초기 작업 디렉토리 설정
	char def_dir[DIR_SIZE];
	// rst_dir은 앞에 mkdir, rm -rf의 명령어가 더 들어가기 때문에 문자열의 길이를 10 늘려줌
	char rst_dir[DIR_SIZE + 10];

	// 현재 사용자 계정을 %s 위치에 삽입하여 디폴트 디렉토리 설정
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	// 디폴트 디렉토리가 이미 있을 경우를 대비하여 삭제하는 명령어
	// rm -rf [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);

	// 디폴트 디렉토리를 생성
	// mkdir [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	// 디폴트 디렉토리로 change directory
	chdir(def_dir);
	
    system("echo 'Hello' > hello.txt");
    system("echo 'BoB-Linux' > bob.txt");
	int n = 0;
	n = read_txt(buf, n);
    system("ls");
    n = read_txt(buf, n);

	// run_command의 인자로 특정 명령어를 넘겨주어 그 외의 입력값에 대해서 실행시키지 않음
	run_command("cat hello.txt");
	n = read_txt(buf, n);
	run_command("cat hello.txt bob.txt");
	n = read_txt(buf, n);
	run_command("cat hello.txt bob.txt > test.txt");
	n = read_txt(buf, n);
    system("cat test.txt");
    n = read_txt(buf, n);

	fclose(fp);
	printf("\n");
}

void next_quit()
{
	char select[CMD_SIZE];
	printf("\n다음 명령어를 학습하시려면 Enter를, 종료하시려면 'q'를 입력하세요.\n");
	fgets(select, sizeof(select), stdin);
	select[strlen(select)-1] = '\0';
	if (!strcmp(select, "q"))
		exit(0);
	else
		return;
}

int main()
{
	// main 함수는 training_명령어 이름()과 next_quit() 함수로 구성됨
	// 각 명령어 학습 단계를 마친 후 마지막에 트레이닝을 계속 할건지, 그만 할건지 여부를 물어본 후 입력 값에 따라 종료 또는 진행
	training_cat();
	next_quit();
	// training_ls(); 
	printf("이 메시지가 출력된다면 next 기능이 정상적으로 실행된 것\n");
	return 0;
}
```
### cat.txt
```
이번에 학습할 명령어는 'cat'입니다.
cat 명령어는 'concatenate'의 약자로, 두 개 이상의 파일을 연결(concatenate)하여 출력할 때 사용합니다.
간단하게 생각하면, 여러 파일의 내용을 터미널로 연결시켜 출력한다고 보면 됩니다.
기본 사용법은 다음과 같습니다.
$ cat [옵션] [파일명]

다음은 현재 디렉토리에 있는 파일들의 목록입니다.
@

hello.txt 파일의 내용을 cat 명령어를 이용해 출력해보세요.
@

hello.txt의 내용인 "Hello"가 출력되었습니다.

cat 명령어는 한 번에 두 개의 파일을 연결해서 출력할 수도 있습니다.
그럴 때에는 간단히 파일명을 띄어쓰기로 구분해서 나열하면 됩니다.
$ cat [옵션] [파일1] [파일2] [파일3] ...
hello.txt 파일과 bob.txt 파일을 한 번에 출력해보세요.(hello.txt 다음에 bob.txt를 쓰세요)
@
hello.txt의 내용인 "Hello"와 bob.txt의 내용인 "BoB-Linux"가 출력됩니다.

cat은 보통 '리다이렉션(redirection)' 이라는 기호 '>'와 함께 자주 쓰입니다.
지금까지는 간단히 터미널에 파일의 내용을 출력시켰지만, > 기호를 이용하면 특정 파일의 내용을 다른 파일에 연결할 수 있습니다.
사용법은 다음과 같습니다.
$ cat [파일 1] [파일 2] ... [파일 n] > [대상 파일명]
해당 사용법은 [파일 1] [파일 2] ... [파일 n] 까지의 모든 내용을 합쳐, [대상 파일명]로 만듭니다.
만약 [대상 파일명]이 이미 존재 한다면, 이미 존재하는 파일의 내용을 [파일 1] [파일 2] ... [파일 n]로 덮어 씌웁니다.
cat 명령어를 이용하여 hello.txt와 bob.txt 파일의 내용을 test.txt로 합쳐보세요.
@
아래의 내용은 새로 만들어진 test.txt 파일을 cat 명령어를 통해 출력한 내용입니다.
두 파일의 내용이 합쳐졌음을 알 수 있습니다. 즉, cat hello.txt bob.txt의 출력 결과가 test.txt 파일에 저장(연결)됩니다.
@

cat을 이용해 이미 존재하는 파일에 덮어쓰는게 아닌, 내용을 추가해 덧붙일 수 있습니다.
사용법은 다음과 같습니다.
$ cat [파일 1] >> [대상 파일]
만약 [파일 1]의 내용이 "Linux"고, [대상 파일]의 내용이 "BoB"이라면
명령어를 실행 후 [대상 파일]의 내용은 
"BoB"
"Linux"가 됩니다. 여기서 주의할 점은 "BoBLinux"나 "BoB Linux"가 아닌, '개행(new line)'으로 두 파일이 구분된다는 점 입니다.
리다이렉션에 대해서는 심화 명령어 트레이닝에서 다시 한 번 다루게 됩니다.

cat의 옵션은 여러 가지가 있습니다. 나열하면 다음과 같습니다.
-b : 줄번호를 화면 왼쪽에 출력하지만 비어있는 행은 출력하지 않습니다.
-n : 줄번호를 화면 왼쪽에 출력하고, 비어있는 행도 출력합니다.
-s : 연속되는 2개 이상의 빈 행을 하나의 행으로 출력합니다.
-E : 행마다 끝에 $ 문자를 출력합니다.
-e : 제어 문자를 ^ 형태로 출력하면서, 각 행의 끝에 $를 출력합니다.

cat 명령어는 자주 쓰게 될 것이므로, 여러 가지의 텍스트 파일을 이용해 연습하면 좋습니다.
가장 많이 쓰이는 용법은 cat 명령어를 통해 파일의 내용을 보거나, 리다이렉션 하여 파일의 내용을 변경하는 것 입니다.

cat 명령어 학습이 끝났습니다.
@
```
