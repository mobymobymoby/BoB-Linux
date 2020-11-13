#include "func.h"

void training_find()

{
	create_defdir();
	system("clear");

	system("touch find_test_file");

	printf("이번에 학습할 명령어는 'find'입니다. 이름에서 알 수 있듯이 파일을 찾는 명령어입니다.\n");
	printf("주어진 조건으로 파일을 찾아 해당 경로를 표시합니다.\n");
	next_line();
	printf("find 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ find [찾을 경로] [옵션] [파일명]\n");
	next_line();
	printf("[찾을 경로]를 생략하면 현재 디렉토리에서 부터 검색을 합니다.\n");
	next_line();
	printf("find 명령어의 옵션은 아래와 같습니다.\n");
	printf("-name 찾을이름 : 이름으로 파일 찾기\n");
	printf("-user 유저이름 : 소유자가 유저이름인 파일 찾기\n");
	printf("-type [bcdfls] : 파일 유형에 따라 파일 찾기\n");
	printf("	b: 블록파일\n");
	printf("	c: 문자\n");
	printf("	d: 디렉토리\n");
	printf("	f: 파일\n");
	printf("	l: 링크파일\n");
	printf("	s: 소켓\n");
	printf("-size [+/-]n : 파일 크기로 찾기\n");
	printf("	+n : n보다 큰 파일\n");
	printf("	-n : n보다 작은 파일\n");
	printf("	n : n인 파일\n");
	printf("-perm 퍼미션 : 퍼미션 값으로 파일 찾기\n");
	printf("-exec 명령어 {}\\ : 찾은 파일을 대상으로 수행할 명령어 지정. {}\\을 명령어 끝에 붙여야 한다.\n");
	next_line();
	printf("find 명령어를 사용하여 find_test_file을 찾아보세요.\n");
	run_command("find find_test_file");

	printf("경로를 생략했기 때문에 현재 디렉토리 내에서 파일을 검색하게 됩니다.\n");
	next_line();
	printf("그럼 다시 한 번 find 명령어를 사용하여 find_test_file을 찾고 동시에 -exec 옵션을 이용하여 삭제까지 해보세요.\n");
	run_command("find find_test_file -exec rm {}\\");

	printf("find 명령어를 잘 활용하면 원하는 파일에만 대해서 다양한 작업을 한 큐에 실행이 가능합니다.\n");
	next_line();
	
	printf("find 명령어에 대한 학습이 끝났습니다.\n");

	delete_defdir();
}