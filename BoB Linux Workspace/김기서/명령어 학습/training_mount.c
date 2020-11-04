#include "common_func.h"

void training_mount()
{
	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];

	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	chdir(def_dir);

	printf("이번에 학습할 명령어는 'mount' 입니다. 역할은 장치와 파일시스템을 연결하는 역할을 합니다.");
	getchar();
	printf("리눅스에서는 모든 것이 파일로 다뤄집니다. 디스크 장치 또한 예외가 아닙니다. 이 디스크 장치를 사용하기 위해서 장치 파일과 디렉토리와 연결(mount)해주는 명령어가 mount 명령어 입니다.");
	getchar();
	printf("우선 mount -l 을 입력하여 현재 마운트 목록을 살펴보세요.");
	run_command("mount -l");

	printf("/dev/sda 와 같이 앞 쪽은 장치를 나타냅니다.\n");
	printf("on 뒤의 / 는 마운트 된 디렉토리를 나타냅니다.\n");
	printf("type 뒤에는 파일시스템을 나타냅니다.");
	getchar();
	printf("mount 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ mount [옵션] 마운트할디바이스 연결할디렉토리");
	getchar();
	printf("mount 명령어의 옵션은 아래와 같습니다.\n");
	printf("\t-r : 읽기 전용으로 마운트\n");
	printf("\t-w : 읽기/쓰기로 마운트\n");
	printf("\t-t : 파일 시스템의 형식을 지정");
	getchar();
	printf("umount 명령어는 마운트를 해제하는 명령어 입니다. UN이 아니라 U입니다.");
	getchar();

	printf("mount 명령어에 대한 학습이 끝났습니다.\n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}