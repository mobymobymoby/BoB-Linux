#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_dd(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    //실습할 파일&디렉토리 제공
	system("mkdir dir1 dir2");
	system("echo hello linux > dir1/file1");


	printf("이번에 학습할 명령어는 'dd'입니다.\n\n");
	next_line();
	printf("dd는 파일을 파티션이나 디스크 단위로 백업할 때 사용하는 명령어입니다.\n\n");
	next_line();
	printf("dd명령어는 보통 다음과 같은 형식으로 사용됩니다.\n$ dd [operand] ... \n또는 \n$ dd [option]\n\n");
	next_line();
	printf("dd [operand] ... 형식인 경우\n보통 'if=대상디스크/파티션 of=저장파일 단위명=사이즈' 를 입력해 사용합니다.\n예시를 들자면 dd if=/dev/sda of=/dev/sdb bs=1k 인 경우,\n/dev/sda를 /dev/sdb로 블록 사이즈 1kb 단위로 백업하는 것입니다.\n\n");
	next_line();
	printf("dd에서 사용하는 옵션은 다음과 같습니다.\n --help : 명령어의 도움말을 표시합니다.\n --version : 명령어의 버전 정보를 표시합니다.\n\n");
	next_line();
	printf("dd에서 사용하는 operand는 다음과 같습니다.\n if=FILE : 입력 대상이 될 파일을 설정합니다.\n");
	printf(" of=FILE : 출력 대상이 될 파일을 설정합니다.\n");
	printf(" bs=BYTES : 한번에 BYTES bytes 단위로 읽고 씁니다.\n");
	printf(" ibs=BYTES : 한번에 BYTES bytes 단위로 읽습니다.\n");
	printf(" obs=BYTES : 한번에 BYTES bytes 단위로 씁니다\n");
	printf(" cbs=BYTES : 한번에 BYTES bytes 단위로 변환합니다.\n");
	printf(" count=BLOCKS : 입력된 블록 크기만큼 복사합니다.\n");
	printf(" conv=CONVS : 쉼표 기호로 구분된 것을 파일로 변환합니다.\n");
	printf(" iflag=FLAGS : 쉼표 기호로 구분된 파일을 읽습니다.\n");
	printf(" oflag=FLAGS : 쉼표 기호로 구분된 파일을 씁니다.\n");
	printf(" seek=BLOCKS : 지정된 단위만큼 obs크기를 건너뛰고 출력합니다.\n");
	printf(" skip=BLOCKS : 지정된 단위만큼 ibs크기를 건너뛰고 입력합니다.\n\n");
	next_line();

	system("ls -al");
	next_line();

	printf("\n\'ls -al\' 명령을 통해 확인해보면, 현재 폴더에 dir1과 dir2이 있고 dir1에는 file1이 있습니다.\n");

	printf("dd 명령을 사용해 디스크 if=dir1/file1를 of=dir2/file1로,\n블록 사이즈 bs=1M 단위로 읽고 쓰도록 명령어를 입력해보세요.\n\n");

	run_command("dd if=dir1/file1 of=dir2/file1 bs=1M");
	
	next_line();
	system("ls -al dir2");

	printf("\ndir1/file1의 내용이 dir2/file1으로 성공적으로 써진 것을 확인할 수 있습니다.\n\n");
	next_line();
	printf("dd 명령어에 대한 학습이 끝났습니다.\n");

	delete_defdir();
}

