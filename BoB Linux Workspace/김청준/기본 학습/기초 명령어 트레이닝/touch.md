### touch.c
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define CMD_SIZE 20
#define BUF_SIZE 102400

void hint(char valid_cmd[])
{
	printf("'%s'를 입력하세요.", valid_cmd);
}

int run_command(char valid_cmd[])
{
	
    char cmd[CMD_SIZE];
    char d_buf[30];
    while(1)
    {
	printf("\n");
	    getcwd(d_buf, sizeof(d_buf));
	    printf("Trainer@BoB:%s$ ", d_buf);
        scanf("%[^\n]s", cmd);
        // 입력 버퍼 삭제
        getchar();
            // 입력값 검증 부분
            if(!strcmp(cmd, valid_cmd)) 
            {
                printf("잘 입력하셨습니다.");
                // 여기서 핵심은 system 함수의 인자로 valid_cmd가 입력된다는 것임. 즉 사용자의 입력값은 사용되지 않음
                system(valid_cmd);
                break;
            }
            // 사용자가 help를 입력했을 때 힌트
            else if(!strcmp(cmd, "help"))
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
	for(; buf[n] != '@' && buf[n] != '\0'; n++)
	{
		printf("%c", buf[n]);
		// 출력 버퍼 비우기. 출력 버퍼를 비우지 않으면 한 글자씩 출력되지 
		fflush(stdout);
		// 한 글자씩 출력되는 효과를 위한 sleep. 0으로 한다면 한번에 출력됨
		usleep(3000);
	}
    // 다음 배열의 인덱스로 넘어가기 위해 n+1을 리턴
	return n+1;
}
	

void training_touch(void)
{
	FILE *fp;
	fp = fopen("touch.txt", "r");
	char buf[BUF_SIZE] = {0,};
	fread(buf, sizeof(buf), 1, fp);
	
	int n = 0;
    system("touch test");
	n = read_txt(buf, n);
    system("stat test");
    n = read_txt(buf, n);
    // run_command의 인자로 특정 명령어를 넘겨주어 그 외의 입력값에 대해서 실행시키지 않음
	run_command("touch test");
    
	n = read_txt(buf, n);
	system("stat test");
    n = read_txt(buf, n);
	run_command("touch -t 209901010101.01 test");
	n = read_txt(buf, n);
    system("stat test");
    n = read_txt(buf, n);
    run_command("touch testfile");
    n = read_txt(buf, n);
	system("ls");
    n = read_txt(buf, n);
	fclose(fp);
	printf("\n");
}

void next_quit()
{
    char cmd[CMD_SIZE];
    printf("\n다음 명령어를 학습하시려면 'next'를, 종료하시려면 'quit'를 입력하세요.\n");
    scanf("%s", cmd);
    if(!strcmp(cmd, "next"))
    return;
    else
    exit(0);
}

int main()
{
    // main 함수는 training_명령어 이름()과 next_quit() 함수로 구성됨
    // 각 명령어 학습 단계를 마친 후 마지막에 트레이닝을 계속 할건지, 그만 할건지 여부를 물어본 후 입력 값에 따라 종료 또는 진행
	training_touch();
    next_quit();
    // training_ls(); 
    printf("이 메시지가 출력된다면 next 기능이 정상적으로 실행된 것\n");
    return 0;
}
```

### touch.txt
```
이번에 학습할 명령어는 'touch' 입니다.
touch는 특정 파일의 날짜 및 시간 정보를 변경하는 명령어입니다.
아무런 옵션을 주지 않고 사용하면 서버의 현재 시간으로 파일의 최근 사용 시간(access time), 최근 수정 시간(modify time), 최근 변경 시간(change time)을 변경합니다.
최근 사용 시간, 최근 수정 시간, 최근 변경 시간은 보통 atime과 mtime, ctime으로 줄여 사용합니다.
atime, mtime, ctime을 파일의 '타임스탬프' 값이라고 합니다.
touch 명령어는 다음과 같은 형식으로 사용합니다.
$ touch [옵션] [파일명]


먼저 미리 생성한 'test'라는 파일의 타임 스탬프 정보룰 보여드리겠습니다.
@

Access, Modify, Change 다음에 있는 값이 각각 atime, mtime, ctime을 나타냅니다.
touch 명령어를 이용해서 'test' 파일의 타임스탬프를 현재 시간으로 바꿔보세요.
TIP : 아무런 옵션을 주지 않고 사용하면 서버의 현재 시간으로 파일의 최근 사용 시간(access time)과 최근 수정 시간(modify time)을 변경
$ touch [옵션] [파일명]@

아래는 변경된 'test' 파일의 타임스탬프 입니다.
@

옵션 없이 사용하여 해당 파일을 현재 시간으로 변경할 수도 있지만, 자신이 원하는 시간으로 타임스탬프 값을 변경할 수도 있습니다.
-t 옵션은 자신이 원하는 시간으로 타임스탬프를 변경할 수 있습니다. 이 때는 파일의 atime과 mtime만 변경됩니다.
-t 옵션 다음에 시간을 [YYYYMMDDhhmm.ss] 형태로 지정하면 됩니다.

★리눅스 지식★
[YYYYMMDDhhmm.ss]과 같은 형태는 시스템에서 날짜를 지정하는 방식인데, 앞으로도 이와 같은 형식의 날짜 표기를 자주 보게 될 것입니다.
Y는 Year의 약자로, '년도'를 2020과 같이 4자리로 표현하는 것을 의미하고, MM은 Month의 약자로 '월'을 2자리로 표현하는 것을 의미합니다.
D는 Day의 약자로 '일'을 2자리로 표현하는 것을 의미하고, h와 m은 각각 hour과 minute로 '시'와 '분'을 각각 2자리로 표현하는 것을 의미합니다.
마지막으로 s는 second의 약자로 초를 2자리로 표현하는 것을 의미합니다.
따라서 "2000년 1월 2일 3시 4분 5초" 라는 날짜는 [YYYYMMDDhhmm.ss] 형식으로 200001020304.05로 표기하면 됩니다.

-t 옵션을 touch 명령어와 조합하여 'test' 파일의 atime, mtime을 2099년 1월 1일 1시 1분 1초로 변경해보세요.
$ touch -t [변경할 시간] [파일명]
@

아래는 변경된 'test' 파일의 타임스탬프 입니다.
@

-a 옵션은 현재 시간으로 파일의 atime과 mtime을 변경합니다.
아무 옵션을 주지 않고 touch [파일명]의 형식으로 사용하면, 모든 타임스탬프가 현재 시간으로 변경되지만, -a 옵션은 ctime에는 영향을 미치지 않습니다.

한편, touch 명령어는 빈 파일을 만들 때도 자주 사용합니다.
아무런 옵션 없이 touch [디렉토리에 없는 파일명]의 형식으로 0바이트를 가진 빈 파일을 생설할 수 있습니다.

touch 명령어를 이용해 'testfile'이라는 빈 파일을 만들어보세요.
$ touch [디렉토리에 없는 파일명]
@

아래는 현재 디렉토리에 있는 파일 목록입니다. testfile이라는 빈 파일이 생성된 것을 확인할 수 있습니다.

touch 명령어에 대한 학습이 끝났습니다.
@
```
