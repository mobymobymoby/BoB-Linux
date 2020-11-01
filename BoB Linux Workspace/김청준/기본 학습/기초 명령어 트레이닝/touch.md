### touch.c
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "common_func.h"

void training_touch(void)
{
	FILE* fp;
	fp = fopen("touch.txt", "r");
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

	//////////////////////////////////////////////////////////////////////////////////////////////////////

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
```
