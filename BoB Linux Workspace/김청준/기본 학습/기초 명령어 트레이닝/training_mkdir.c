#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "common_func.h"

void training_mkdir(void)
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
	printf("이번에 학습할 명령어는 'mkdir'입니다. \nmkdir 명령어는 make directory의 약자로, '디렉토리'를 생성하는 명령어입니다.\n");
	getchar();
	printf("리눅스에서 디렉토리란 윈도우 환경의 '폴더'와 비슷한 개념입니다. 디렉토리에는 '파일'이나 또 다른 디렉토리가 포함될 수 있습니다.\n");
	getchar();
	printf("mkdir 명령어는 다음과 같은 형식으로 사용합니다.\n$ mkdir [옵션] [생성할 디렉토리 이름]\n");
	getchar();
	printf("mkdir 명령어를 입력하여 'test_dir' 디렉토리를 생성해보세요.\n");
	run_command("mkdir test_dir");

	printf("아래는 ls -al의 출력 결과 입니다.\n'test_dir' 디렉토리가 추가된 것을 확인할 수 있습니다.\n");
	printf("\n");
	system("ls -al");
	getchar();

	printf("mkdir의 옵션은 상당히 간단합니다.\n");
	getchar();
	printf("-m 옵션은 디렉토리를 생성할 때 권한을 설정합니다.\n");
	getchar();
	printf("-m xxx의 형식으로 사용할 수 있습니다.\n");
	getchar();
	printf("mkdir -m xxx에서 'xxx'에 해당하는 것이 바로 앞에서 배운 3자리 숫자의 권한 표시 방식입니다.\n");
	getchar();
	printf("즉 소유자, 그룹, 전체 권한을 숫자 형식으로 표시해주어 디렉토리를 생성할 수 있는 것입니다.\n");
	getchar();
	printf("mkdir -m 명령어를 이용해 'drwxr-x-w-(752)' 권한을 가진 디렉토리 'test_dir2'를 생성해보세요.\n$ mkdir -m [권한] [생성할 디렉토리 이름]\n");
	run_command("mkdir -m 752 test_dir2");

	printf("아래는 ls -al의 출력 결과 입니다.\n'test_dir2' 디렉토리가 지정한 권한으로 추가된 것을 확인할 수 있습니다.\n");
	printf("\n");
	system("ls -al");
	getchar();

	printf("-p 옵션은 하위 디렉토리를 함께 생성할 때 사용합니다.\n");
	getchar();
	printf("예를 들어 mkdir 명령어를 통해 '과일'이라는 디렉토리를 생성하고, 그 안에 '사과'라는 하위 디렉토리를 생성하고 싶을 때 사용합니다.\n");
	getchar();
	printf("위의 예시처럼 생성하기 위해서는 'mkdir -p 과일/사과'를 입력하면 됩니다.\nmkdir -p 명령어를 이용해 'fruits' 디렉토리 안에 'apple' 디렉토리를 생성해보세요.\n");
	run_command("mkdir -p fruits/apple");

	printf("mkdir 명령어에 대한 학습이 끝났습니다. \n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}
