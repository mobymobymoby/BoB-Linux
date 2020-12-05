#include "func.h"

void training_lsblk(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    	printf("이번에 학습할 명령어는 'lsblk'입니다.\n");
	printf("lsblk는 'list block devices'의 약자입니다.\n");
	next_line();
	printf("리눅스에서는 하드디스크, 플로피디스크 등 다양한 디스크 종료의 장치를 'Block'으로 관리합니다.\n");
	printf("이러한 블록 디바이스의 정보를 트리 구조로 볼 수 있는 명령어가 바로 'lsblk'입니다\n");
	next_line();
	printf("아무런 옵션 없이 lsblk를 입력해 현재 연결되어 있는 블록 디바이스의 정보를 확인할 수 있습니다.\n");
	next_line();
	printf("옵션 없이 lsblk를 입력해 디바이스의 정보를 확인해보세요\n사용법은 아래와 같습니다.\n");
	printf("$ lsblk [옵션]\n");
	run_command("lsblk");
	next_line();
	printf("첫번째 필드인 'NAME'은 해당 디바이스의 이름을 나타냅니다.\n");
	next_line();
	printf("두번째 필드인 'MAJ:MIN'는 해당 디바이스의 MAJOR 번호와 MINOR 번호를 나타냅니다.\n");
	next_line();
	printf("세번째 필드인 'RM'은 해당 디바이스의 제거 가능 여부(Removable)를 나타냅니다.\n");
	printf("해당 필드의 값이 0이라면 제거 불가능 상태이며 1이라면 제거 가능한 상태입니다.\n");
	next_line();
	printf("네번째 필드인 'SIZE'는 해당 디바이스의 용량을 나타냅니다.\n");
	printf("-b 옵션을 추가하면 해당 필드의 값이 바이트(bytes)로 표시됩니다.\n");
	next_line();
	printf("다섯번째 필드인 'RO'은 해당 디바이스의 읽기 전용(Read Only) 여부를 나타냅니다.\n");
	printf("해당 값이 0이라면 읽기 전용이 아니며, 1이라면 읽기 전용 디바이스 입니다.\n");
	next_line();
	printf("여섯번째 필드인 'TYPE'은 해당 디바이스의 타입을 나타냅니다.\n");
	next_line();
	printf("일곱번째 필드인 'MOUNTPOINT'는 해당 디바이스가 마운트 되어 있는 경로를 표시합니다.\n");
	next_line();

	printf("lsblk는 옵션과 함께 사용하여 더욱 다양한 정보를 출력할 수 있습니다.\n");
	printf("-a 옵션은 'all'의 약자로, 비어 있는 디바이스. 즉 용량이 0인 디바이스를 포함하여 출력합니다.\n");
	next_line();
	printf("lsblk와 -a 옵션을 이용해 더 많은 블록 디바이스를 출력해보세요.\n");
	printf("$ lsblk [옵션]\n");
	run_command("lsblk -a");
	next_line();
	printf("아까보다 더 많은 디바이스 정보가 출력된 것을 확인할 수 있습니다.\n");
	next_line();
	printf("-p 옵션은 디바이스의 전체 경로를 출력합니다.\n");
	printf("-p 옵션을 이용해 디바이스 목록의 전체 경로를 출력해보세요.\n");
	printf("$ lsblk [옵션]\n");
	run_command("lsblk -p");
	next_line();
	printf("NAME 필드에 디바이스 전체 경로가 출력됩니다.\n");
	next_line();

	printf("lsblk 명령어는 이처럼 디바이스와 관련한 정보를 볼 수 있기 때문에 mount 명령어와 함께 사용하곤 합니다.\n");
	next_line();

	printf("lsblk 명령어 학습이 끝났습니다. 고생하셨습니다.\n");
	next_line();

    // Delete default directory
	delete_defdir();
}
