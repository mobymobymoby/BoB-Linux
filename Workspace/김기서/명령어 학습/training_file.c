#include "func.h"

void training_file()
{
	create_defdir();
	system("clear");
	
	system("echo $SHELL > file.txt");

	printf("이번에 학습할 명령어는 'file' 입니다. 파일의 종류를 알려줍니다.\n");
	next_line();
	printf("file 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("\t$ file [옵션] 파일\n");
	next_line();
	printf("file 명령어를 입력하여 'file.txt' 의 종류를 확인해보세요.\n");
	run_command("file file.txt");

	printf("텍스트 파일임을 알 수 있습니다.\n");
	next_line();
	printf("이번에는 '.'이 어떤 종류인지 확인해보세요.\n");
	run_command("file .");

	printf("file 명령어로 디렉토리인지도 확인이 가능합니다.\n");
	next_line();
	printf("- 리눅스 지식 -");
	printf("리눅스에서는 디렉토리도 파일로 취급합니다.\n");
	printf(".  은 현재 디렉토리를 가리키는 파일입니다.\n");
	printf(".. 은 상위 디렉토리를 가리키는 파일입니다.\n");
	next_line();
	printf("확장자가 없는 파일들을 file 명령어를 통해 어떤 유형의 파일인지 확인할 수 있습니다.\n");
	next_line();
	
	printf("file 명령어에 대한 학습이 끝났습니다.\n");

	delete_defdir();
}
