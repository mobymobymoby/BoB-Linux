### mkdir.c 파일
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define CMD_SIZE 40 // 최대 39개의 문자 입력
#define DIR_SIZE 40 // 최대 39개의 문자 입력
#define BUF_SIZE 102400

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
			printf("잘 입력하셨습니다.\n");
			// 여기서 핵심은 system 함수의 인자로 valid_cmd가 입력된다는 것임. 즉 사용자의 입력값은 사용되지 않음
			system(valid_cmd);
			break;
		}
		else
		{
			printf("잘못된 명령어를 입력하셨습니다.\n");
		}

	}
	return 0;
}

void training_mkdir(void)
{
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
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	int n = 0;
	printf("이번에 학습할 명령어는 'mkdir'입니다. \nmkdir 명령어는 make directory의 약자로, '디렉토리'를 생성하는 명령어입니다.\n");
	getchar();
	printf("리눅스에서 디렉토리란 윈도우 환경의 '폴더'와 비슷한 개념입니다. 디렉토리에는 '파일'이나 또 다른 디렉토리가 포함될 수 있습니다.\n");
	getchar();
	printf("mkdir 명령어는 다음과 같은 형식으로 사용합니다.\n$ mkdir [옵션] [생성할 디렉토리 이름]\n");
	getchar();
	printf("mkdir 명령어를 입력하여 'test_dir' 디렉토리를 생성해보세요.\n");
	run_command("mkdir test_dir");
	printf("mkdir의 옵션은 상당히 간단합니다.\n-m 옵션은 디렉토리를 생성할 때 권한을 설정합니다.\n-m xxx의 형식으로 사용하며, 아무런 값을 지정하지 않았을 때는 기본으로 755로 입력됩니다.\n");
	getchar();
	printf("mkdir -m xxx에서 'xxx'에 해당하는 것이 바로 앞에서 배운 3자리 숫자의 권한 표시 방식입니다.\n즉 소유자, 그룹, 전체 권한을 숫자 형식으로 표시해주어 디렉토리를 생성할 수 있는 것입니다.\n");
	getchar();
	printf("mkdir -m 명령어를 이용해 'drwxr-x-w-' 권한을 가진 디렉토리 'test_dir2'를 생성해보세요.\n$ mkdir -m [권한] [생성할 디렉토리 이름]\n");
	run_command("mkdir -m 752 test_dir2");
	printf("-p 옵션은 하위 디렉토리를 함께 생성할 때 사용합니다.\n예를 들어 mkdir 명령어를 통해 '과일'이라는 디렉토리를 생성하고, 그 안에 '사과'라는 하위 디렉토리를 생성하고 싶을 때 사용합니다.");
	getchar();
	printf("위의 예시처럼 생성하기 위해서는 'mkdir -p 과일/사과'를 입력하면 됩니다.\nmkdir -p 명령어를 이용해 'fruits' 디렉토리 안에 'apple' 디렉토리를 생성해보세요.\n");
	run_command("mkdir -p fruits/apple");
	
	printf("mkdir 명령어에 대한 학습이 끝났습니다. \n");
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
	training_mkdir();
	next_quit();
	// training_ls(); 
	printf("이 메시지가 출력된다면 next 기능이 정상적으로 실행된 것\n");
	return 0;
}
```

### mkdir.txt
```

```
