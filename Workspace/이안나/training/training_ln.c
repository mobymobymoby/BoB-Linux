#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_ln(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    //실습할 파일&디렉토리 제공
	system("touch file1");


	printf("이번에 학습할 명령어는 'ln'입니다.\n\n");
	next_line();
	printf("ln은 파일의 링크('하드 링크' 또는 '심볼릭 링크')를 생성하는 명령어입니다.\n\n");
	next_line();
	printf("하나의 파일을 여러 개의 이름으로 관리하거나\n디렉터리의 접근 경로를 단축하는 형태를 '링크'라고 합니다.\n");
	next_line();
	printf("파일이나 디렉터리가 생성될 때 'I-node(index node)'라는 번호가 부여되고\n이 번호를 기준으로 파일이 관리되는데,\n이때 이 번호가 같다면 내부적으로 같은 파일로 인식됩니다.\n\n");
	next_line();
	printf("하드 링크란 하나의 동일한 파일을 디스크의 다른 곳에 복사하여\n여러 이름의 파일로 사용되는 형식입니다.\n\n");
	next_line();
	printf("하드 링크의 특징은 다음과 같습니다.\n - i-node 번호가 원본 파일과 같다.\n - 원본 파일과 링크 파일의 크기가 같다.\n - 원본과 링크 둘 중 하나를 수정하면 서로 같이 반영된다.\n - 원본을 삭제해도 링크는 영향을 받지 않는다.\n - 하드 링크는 파일에 대해서만 생성이 가능하다.\n\n");
	next_line();
	printf("심볼릭 링크란 하나의 파일을 여러 이름으로 가리키게 하는 것이며\n원본과 링크 파일은 완전히 다른 파일로 관리됩니다.\n윈도우에서 바로가기 아이콘과 비슷하다고 생각하면 이해하기 쉽습니다.\n\n");
	next_line();
	printf("심볼릭 링크의 특징은 다음과 같습니다.\n - i-node 번호가 원본 파일과 다르다.\n - 원본 파일보다 링크 파일의 크기가 매우 작다\n - 원본과 링크 둘 중 하나를 수정하면 서로 같이 반영된다.\n - 원본을 삭제하면 링크 파일은 사용하지 못한다.\n - 'ls -l' 파일 목록 출력시 권한 표시 앞에 'l'이 표시된다.\n\n");
	next_line();
	printf("ln 명령어는 다음과 같은 형식으로 사용합니다.\n$ ln [option] 원본 대상파일명\noption은 선택 사항이며 해당 명령어에 지정할 옵션,\n원본은 해당 파일의 원본,\n대상파일명은 생성할 심볼릭 링크 파일의 이름을 입력하여 사용합니다.\n\n");
	next_line();
	printf("ln에서 자주 사용하는 옵션은 다음과 같습니다.\n-s, --symbolic : 심볼릭 링크 생성시에 사용하는 옵션입니다.\n-v, --verbose : 링크를 만드는 정보를 자세히 출력합니다.\n-f, --force : 링크 파일 존재 시에 삭제하고 생성합니다.\n옵션을 입력하지 않으면 하드 링크를 생성합니다.\n\n");
	next_line();

	system("ls -al");

	printf("\n\n현재 directory에 file1이 있습니다.\nln 명령어를 입력해 file1의 하드 링크를 'link1'라는 이름으로 생성해보세요.\n\n");
	run_command("ln file1 link1");
	next_line();

	printf("ln 명령어와 -s 옵션을 입력해 file1의 심볼릭 링크를 'link2'라는 이름으로 생성해보세요.\n\n");
	run_command("ln -s file1 link2");
	next_line();

	system("ls -al");
	printf("\n\n파일 목록을 확인해보면 두 링크 모두 성공적으로 생성된 것을 확인할 수 있습니다.\n\n");

	printf("링크를 삭제하고 싶다면 rm 명령어를 사용하면 됩니다.\n'rm -f 링크파일명'\n\nrm 명령어의 -r 옵션을 사용하면 링크의 원본 파일도 함께 삭제됩니다.\n\n");
	next_line();

	printf("ln 명령어에 대한 학습이 끝났습니다.\n");

	delete_defdir();
}

