#include "func.h"

void training_find()
{
	create_defdir();
	system("clear");

	system("touch find_test_file");

	printf("이번에 학습할 명령어는 'find'입니다. 이름에서 알 수 있듯이 파일을 찾는 명령어입니다.");
	next_line();
	printf("find 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ find [찾을 경로] [옵션]");
	next_line();
	printf("[찾을 경로]를 생략하면 현재 디렉토리에서 부터 검색을 합니다.");
	next_line();
	printf("find 명령어의 옵션은 아래와 같습니다.\n");
	printf("-name 찾을이름 : 이름으로 파일 찾기\n");
	printf("-user 유저이름 : 소유자가 유저이름인 파일 찾기\n");
	printf("-type [bcdfls] : 파일 타입으로 파일 찾기\n");
	printf("	b: 블록파일\n");
	printf("	c: 문자\n");
	printf("	d: 디렉토리\n");
	printf("	f: 파일\n");
	printf("	l: 링크파일\n");
	printf("	s: 소켓\n");
	printf("-size [+/-]n : 파일 크기로 찾기\n");
	printf("	+n : n보다 큰 파일\n");
	printf("	-n : n보다 작은 파일\n");
	printf("	n : n인 파일");
	next_line();
	printf("find 명령어를 사용하여 find_test_file을 찾아보세요.");
	run_command("find find_test_file");

	printf("find 명령어에 대한 학습이 끝났습니다.\n");

	system("rm find_test_file");

	delete_defdir();
}