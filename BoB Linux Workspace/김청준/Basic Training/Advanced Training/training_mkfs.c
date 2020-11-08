#include "func.h"

void training_mkfs(void)
{
	create_defdir();

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("이번에 학습할 명령어는 'mkfs'입니다.\n");
	next_line();
	printf("mkfs는 make file system의 약자입니다.\n");
	next_line();
	printf("mkfs는 보통 새로 생성한 파티션에 대해서 많이 사용합니다.\n");
	next_line();
	printf("fdisk 등의 명령어로 파티션을 새로 생성한 후에는 해당 파티션을 어떤 형식의 파일 시스템으로 만들어 주어야 합니다.\n");
	next_line();
	printf("이 때 사용하는 것이 mkfs입니다.\n");
	next_line();
	printf("사용법은 아래와 같습니다.\n");
	next_line();
	printf("$ mkfs [옵션] [-t] [파일 시스템 옵션] [장치] [크기]\n");
	next_line();
	printf("가만 보면 어려워 보이지만, 이해하고 나면 그렇게 어렵지 않습니다.\n");
	next_line();
	printf("한 가지 예를 들어 설명을 드리겠습니다.\n");
	next_line();
	printf("'/dev/sdb1' 파티션 전체를 ext4 파일 형식으로 포맷하는 명령어는 다음과 같습니다. \n");
	next_line();
	printf("mkfs -t ext4 /dev/sdb1\n");
	next_line();
	printf("보통은 위의 명령어만으로 명령어가 완료되지만, 정상적으로 실행되었는지 여부를 출력하는 명령어인 -v 옵션과 같이 사용할 수 있습니다.\n");
	next_line();
	printf("따라서 mkfs -v -t [파일 시스템 옵션] [장치]의 형식으로 알아두면 편할 것입니다.\n");
	next_line();
	printf("여기서 만약 따로 크기를 지정해야 한다면 맨 뒤에 크기를 입력하면 됩니다.\n");
	next_line();
	printf("mkfs와 매우 유사한 명령어로는, mkfs.[fs]이 있습니다.(사실은 동일한 명령어입니다.)\n");
	next_line();
	printf("해당 명령어는 블록 사이즈, 클러스터 사이즈, inode 사이즈 등 좀 더 세부적인 옵션을 다룰 수 있습니다.\n");
	next_line();
	printf("mkfs를 직접 사용하여 파티션을 포맷해보겠습니다.\nmkfs도 장치의 파일 시스템을 포맷하는 중요한 작업을 하기 때문에 관리자 권한이 필요합니다.\n");
	next_line();
	printf("'lsblk'를 이용하여 현재 블록 디바이스의 목록을 출력할 수 있습니다. lsblk를 입력해보세요.\n");
	next_line();
	printf("이번 트레이닝 동안 관리자 권한을 부여해드리겠습니다.\n");
	fake_run_command("lsblk");

	printf("sda      8:0    0    40G  0 disk\n└─sda1   8:1    0    40G  0 part /\nsdb      8:16   0    10G  0 disk\n");
	next_line();

	printf("sda 밑에 sda1, 그리고 sdb가 있는 것을 확인할 수 있습니다. 우리가 포맷할 디바이스는 'sdb'입니다.\n");
	next_line();
	printf("mkfs는 매우 조심해서 사용해야 합니다. 잘못 사용하면 정상적인 디바이스를 포맷해버릴 수 있기 때문입니다.\n");
	next_line();
	printf("이것이 바로 mkfs 명령어에 관리자 권한이 필요한 이유입니다.\n");
	next_line();
	printf("mkfs를 이용해서 '/dev/sdb' 파티션을 ext4로 포맷해보세요. (단 -v 옵션을 사용하지 않고 실행하세요.)\n");
	next_line();
	printf("$ mkfs -t [파일 시스템 옵션] [장치]\n");
	fake_run_command("mkfs -t ext4 /dev/sdb");
	printf("mke2fs 1.44.1 (24-Mar-2018)\n");
	usleep(30000);
	printf("Creating filesystem with 2621440 4k blocks and 655360 inodes\n");
	printf("Filesystem UUID: 793d30de-8abe-479f-6a32-g2174xrwc0c8\n");
	printf("Superblock backups stored on blocks: \n");
	printf("	32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632\n\n");
	usleep(30000);
	printf("Allocating group tables: done\n");                                     
	printf("Writing inode tables: done\n");
	printf("Creating journal (16384 blocks): done\n");
	printf("Writing superblocks and filesystem accounting information: done\n");
	next_line();
	printf("출력된 결과를 보겠습니다.\n");
	next_line();
	printf("'mke2fs 1.44.1'은 mkfs 명령어를 수행하는데 사용되는 패키지의 버전을 나타냅니다.\n");
	next_line();
	printf("mke2fs는 mkfs 명령어를 수행하는데 사용되며, mkfs.[fs] 명령어를 실행할 때도 사용됩니다.\n");
	next_line();
	printf("Creating filesystem with 2621440 4k blocks and 655360 inodes : 해당 파일시스템이 2621440개의 4K 블록과 655360개의 inodes로 생성되었음을 말합니다.\n");
	next_line();
	printf("Filesystem UUID : 특정 파일 시스템을 식별하기 위한 값입니다.(Universally Unique IDentifier)\n");
	next_line();
	printf("16bytes로 규격화된 슷자로, 생성시 시간 값을 반영해 겹치지 않도록 고유한 식별 ID를 생성하는 것입니다.\n");
	next_line();
	printf("Superblock backups stored on blocks: 슈퍼블록은 리눅스 파일시스템의 중요한 정보가 들어 있는 메타데이터입니다.\n");
	next_line();
	printf("슈퍼블록의 데이터가 훼손되는 것을 막기 위해 리눅스 파일 시스템에서는 슈퍼블록의 복사본을 여러 곳에 저장합니다.\n");
	next_line();
	printf("위에서 출력되는 값인 '32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632'는 복사된 슈퍼블록의 위치입니다.(블록 단위)\n");
	next_line();
	printf("그리고 마지막 4개의 출력 메시지는 적혀있는 각각의 작업이 성공적으로 수행되었음을 뜻합니다.\n");
	next_line();
	printf("mkfs 명령어는 주로 블록 디바이스와 파티션을 다루는 lsblk, fdisk와 같은 명령어와 함께 사용됩니다.\n");
	next_line();
	printf("mkfs 명령어 학습이 끝났습니다.\n");

    // Delete default directory
	delete_defdir();
}