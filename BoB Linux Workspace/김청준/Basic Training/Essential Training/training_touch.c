#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "common_func.h"

void training_touch(void)
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

	int n = 0;
	system("touch test");
	
	printf("이번에 학습할 명령어는 'touch' 입니다.\ntouch는 특정 파일의 날짜 및 시간 정보를 변경하는 명령어입니다.\n");
	getchar();
	
	printf("아무런 옵션을 주지 않고 사용하면 서버의 현재 시간으로 파일의 최근 사용 시간(access time), 최근 수정 시간(modify time), 최근 변경 시간(change time)을 변경합니다.\n");
	getchar();
	printf("access time, modify time, change time은 보통 atime과 mtime, ctime으로 줄여 사용합니다.\n");
	getchar();
	
	printf("atime, mtime, ctime을 파일의 '타임스탬프' 값이라고 합니다.\ntouch 명령어는 다음과 같은 형식으로 사용합니다.\n$ touch [옵션] [파일명]\n");
	getchar();
	printf("먼저 미리 생성한 'test'라는 파일의 타임 스탬프 정보를 보여드리겠습니다.\n");
	getchar();
	printf("타임 스탬프를 보는 명령어는 'stat' 명령어 입니다. 이에 대해서는 '심화 명령어 트레이닝' 파트에서 다루게 됩니다.");
	printf("\n");
	system("stat test");
	getchar();
	
	printf("Access, Modify, Change 다음에 있는 값이 각각 atime, mtime, ctime을 나타냅니다.\n");
	getchar();
	printf("touch 명령어를 이용해서 'test' 파일의 타임스탬프를 현재 시간으로 바꿔보세요.\n");
	getchar();
	printf("TIP : 아무런 옵션을 주지 않고 사용하면 서버의 현재 시간으로 파일의 최근 사용 시간(access time)과 최근 수정 시간(modify time)을 변경\n");
	printf("$ touch [옵션] [파일명]\n");
	
	// run_command의 인자로 특정 명령어를 넘겨주어 그 외의 입력값에 대해서 실행시키지 않음
	run_command("touch test");
	
	printf("아래는 변경된 'test' 파일의 타임스탬프 입니다.\n");
	printf("\n");
	system("stat test");
	getchar();
	
	printf("옵션 없이 사용하여 해당 파일을 현재 시간으로 변경할 수도 있지만, 자신이 원하는 시간으로 타임스탬프 값을 변경할 수도 있습니다.\n");
	getchar();
	printf("-t 옵션은 자신이 원하는 시간으로 타임스탬프를 변경할 수 있습니다. 이 때는 파일의 atime과 mtime만 변경됩니다.\n");
	getchar();
	printf("-t 옵션 다음에 시간을 [YYYYMMDDhhmm.ss] 형태로 지정하면 됩니다.\n");
	getchar();
	
	printf("★리눅스 지식★\n");
	printf("[YYYYMMDDhhmm.ss]과 같은 형태는 시스템에서 날짜를 지정하는 방식인데, 앞으로도 이와 같은 형식의 날짜 표기를 자주 보게 될 것입니다.\n");
	getchar();
	
	printf("Y는 Year의 약자로, '년도'를 2020과 같이 4자리로 표현하는 것을 의미하고, MM은 Month의 약자로 '월'을 2자리로 표현하는 것을 의미합니다.\n");
	getchar();
	
	printf("D는 Day의 약자로 '일'을 2자리로 표현하는 것을 의미하고, h와 m은 각각 hour과 minute로 '시'와 '분'을 각각 2자리로 표현하는 것을 의미합니다.\n");
	getchar();
	
	printf("마지막으로 s는 second의 약자로 초를 2자리로 표현하는 것을 의미합니다.\n");
	getchar();
	
	printf("따라서 \"2000년 1월 2일 3시 4분 5초\" 라는 날짜는 [YYYYMMDDhhmm.ss] 형식으로 200001020304.05로 표기하면 됩니다.\n");
	getchar();
	printf("-t 옵션을 touch 명령어와 조합하여 'test' 파일의 atime, mtime을 2099년 1월 1일 1시 1분 1초로 변경해보세요.\n");
	getchar();
	printf("$ touch -t [변경할 시간] [파일명]\n");
	
	run_command("touch -t 209901010101.01 test");
	
	printf("아래는 변경된 'test' 파일의 타임스탬프 입니다.\n");
	printf("\n");
	system("stat test");
	getchar();
	
	printf("-a 옵션은 현재 시간으로 파일의 atime과 mtime을 변경합니다.\n");
	getchar();
	printf("아무 옵션을 주지 않고 touch [파일명]의 형식으로 사용하면, 모든 타임스탬프가 현재 시간으로 변경되지만, -a 옵션은 ctime에는 영향을 미치지 않습니다.\n");
	getchar();
	
	printf("한편, touch 명령어는 빈 파일을 만들 때도 자주 사용합니다.\n");
	getchar();
	printf("아무런 옵션 없이 touch [디렉토리에 없는 파일명]의 형식으로 0바이트를 가진 빈 파일을 생설할 수 있습니다.\n");
	getchar();
	
	printf("touch 명령어를 이용해 'testfile'이라는 빈 파일을 만들어보세요.\n");
	printf("$ touch [디렉토리에 없는 파일명]\n");
	
	run_command("touch testfile");
	
	printf("아래는 현재 디렉토리에 있는 파일 목록입니다. testfile이라는 빈 파일이 생성된 것을 확인할 수 있습니다.\n");
	printf("\n");
	system("ls");
	getchar();
	
	printf("touch 명령어에 대한 학습이 끝났습니다.\n");
	
	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}
