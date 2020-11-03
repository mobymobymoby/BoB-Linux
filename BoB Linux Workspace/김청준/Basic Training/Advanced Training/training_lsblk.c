#include "common_func.h"

void training_lsblk(void)
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

    printf("이번에 학습할 명령어는 'lsblk'입니다.\n");
	getchar();
	printf("lsblk는 'list block devices'의 약자입니다.\n");
	getchar();
	printf("리눅스에서는 하드디스크, 플로피디스크 등 다양한 디스크 종료의 장치를 'Block'으로 관리합니다.\n");
	getchar();
	printf("이러한 블록 디바이스의 정보를 트리 구조로 볼 수 있는 명령어가 바로 'lsblk'입니다\n");
	getchar();
	printf("아무런 옵션 없이 lsblk를 입력해 현재 연결되어 있는 블록 디바이스의 정보를 확인할 수 있습니다.\n");
	getchar();
	printf("옵션 없이 lsblk를 입력해 디바이스의 정보를 확인해보세요\n사용법은 아래와 같습니다.\n");
	printf("$ lsblk [옵션]\n");
	run_command("lsblk");
	getchar();
	printf("첫번째 필드인 'NAME'은 해당 디바이스의 이름을 나타냅니다.\n");
	getchar();
	printf("두번째 필드인 'MAJ:MIN'는 해당 디바이스의 MAJOR 번호와 MINOR 번호를 나타냅니다.\n");
	getchar();
	printf("세번째 필드인 'RM'은 해당 디바이스의 제거 가능 여부(Removable)를 나타냅니다.\n");
	printf("해당 필드의 값이 0이라면 제거 불가능 상태이며 1이라면 제거 가능한 상태입니다.\n");
	getchar();
	printf("네번째 필드인 'SIZE'는 해당 디바이스의 용량을 나타냅니다.\n");
	printf("-b 옵션을 추가하면 해당 필드의 값이 바이트(bytes)로 표시됩니다.\n");
	getchar();
	printf("다섯번째 필드인 'RO'은 해당 디바이스의 읽기 전용(Read Only) 여부를 나타냅니다.\n");
	printf("해당 값이 0이라면 읽기 전용이 아니며, 1이라면 읽기 전용 디바이스 입니다.\n");
	getchar();
	printf("여섯번째 필드인 'TYPE'은 해당 디바이스의 타입을 나타냅니다.\n");
	getchar();
	printf("일곱번째 필드인 'MOUNTPOINT'는 해당 디바이스가 마운트 되어 있는 경로를 표시합니다.\n");
	getchar();

	printf("lsblk는 옵션과 함께 사용하여 더욱 다양한 정보를 출력할 수 있습니다.\n");
	getchar();
	printf("-a 옵션은 'all'의 약자로, 비어 있는 디바이스. 즉 용량이 0인 디바이스를 포함하여 출력합니다.\n");
	getchar();
	printf("lsblk와 -a 옵션을 이용해 더 많은 블록 디바이스를 출력해보세요.\n");
	printf("$ lsblk [옵션]\n");
	run_command("lsblk -a");
	getchar();
	printf("아까보다 더 많은 디바이스 정보가 출력된 것을 확인할 수 있습니다.\n");
	getchar();
	printf("-p 옵션은 디바이스의 전체 경로를 출력합니다.\n");
	getchar();
	printf("-p 옵션을 이용해 디바이스 목록의 전체 경로를 출력해보세요.\n");
	printf("$ lsblk [옵션]\n");
	run_command("lsblk -p");
	getchar();
	printf("NAME 필드에 디바이스 전체 경로가 출력됩니다.\n");
	getchar();

	printf("lsblk 명령어는 이처럼 디바이스와 관련한 정보를 볼 수 있기 때문에 mount 명령어와 함께 사용하곤 합니다.\n");
	getchar();

	printf("lsblk 명령어 학습이 끝났습니다.\n");
	getchar();

    // Delete default directory
	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}