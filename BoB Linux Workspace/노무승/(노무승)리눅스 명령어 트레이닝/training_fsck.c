#include "func.h"

void training_fsck(void){
    system("clear");
    create_defdir();

    printf("fsck 명령어는 리눅스 파일 시스템을 검사하고 수리하는 명령어입니다.\n");
    next_line();

    printf("파일 시스템 검사 절차는 다음과 같습니다.\n");
    printf("    단계 1  : 블록들과 파일 크기 검사\n");
    printf("    단계 2a : 중복된 이름이 있는지 검사\n");
    printf("    단계 2b : 경로 이름 검사\n");
    printf("    단계 3  : 연결성 검사\n");
    printf("    단계 4  : 참조 수 검사\n");
    printf("    단계 5  : 싸이클 그룹 검사\n");
    next_line();

    printf("fsck 명령이 손상된 파일이나 디렉터리를 수리할 때,\n");
    printf("/lost+found 디렉터리에서 작업을 수행하고 복구가 완료되면 사라집니다.\n");
    next_line();

    printf("fsck 명령으로 검사하거나 수리할 파티션은 마운트가 된 상태면 안됩니다.\n");
    printf("반드시 umount 명령어 등으로 마운트를 헤제하고 수행해주어야 합니다.\n");
    next_line();

    printf("기본적으로 'fsck [파티션 경로]' 와 같은 형식으로 사용합니다.\n");
    printf("[실습] fsck 명령어로 /dev/sdb1 파티션을 검사해보세요. (실제 반영되지는 않습니다.)\n");
    fake_run_command("fsck /dev/sdb1");
    next_line();

    printf("기본적인 사용법 이외에도 다양한 명령 옵션이 있습니다.\n");
    printf("    -v : 점검 내역을 자세하게 출력해줍니다.\n");
    printf("    -y : 모든 응답을 다 yes를 해서 자동으로 점검, 수리를 수행합니다.\n");
    printf("    -n : 모든 응답을 다 no를 해서 점검만 수행합니다.\n");
    printf("    -f : 파일 시스템 이상 유무와 관계없이 강제로 점검을 합니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}