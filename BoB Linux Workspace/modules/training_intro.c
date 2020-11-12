#include "func.h"

void training_intro()
{
    printf("트레이닝에 앞서 기본적인 사항을 설명드리겠습니다.\n");
    next_line();
    printf("1. 트레이닝 진행 방법\n");
    printf("기본적으로 Enter 키를 누르면 다음 메시지가 뜨는 방식으로 진행할 수 있습니다.\n");
    printf("\n");
    printf("특정 설명에서는 여러분으로 부터 입력을 받아 명령어를 실행하기도 합니다.\n");
    printf("이 때 조건에 일치하는 명령어를 입력해야 하며, 잘못된 명령어를 입력했을 때는 다시 입력을 받게 됩니다.\n");
    printf("\n");
    next_line();
    printf("2. 옵션의 중첩\n");
    printf("트레이닝 기능에서 배우게 되는 대부분의 옵션은 중첩하여 사용할 수 있습니다.\n");
    printf("예를 들어 'ls' 명령어의 '-a' 옵션과 '-l' 옵션은 \"ls -a\"이나 \"ls -l\"로 따로 쓸 수도 있지만 \"ls -al\"과 같이 한 번에 사용할 수 있습니다.\n");
    printf("이 때의 기능은 -a 옵션과 -l의 옵션을 합친 것이 됩니다. 이러한 법칙은 ls 뿐만 아니라 대부분의 명령어에 통용됩니다.\n");
    printf("\n");
    next_line();
    printf("3. 터미널에서의 스크롤 이동 방법\n");
    printf("BoB Linux Trainer는 터미널 환경에서 작동합니다.\n");
    printf("BoB Linux 환경에서는 마우스의 휠이나 스크롤 바를 이용해 이전 내용을 다시 확인할 수 있습니다.\n");
    printf("\n");
    printf("만약 CUI 환경에서 트레이너 기능을 이용하고 계신다면 키보드 방향키 위에 있는 \"PgUp\" 키와 \"PgDn\" 키를 이용해 스크롤을 이동할 수 있습니다.\n");
    printf("<Shift + PgUp>은 스크롤을 위로, <Shift + PgDn>은 스크롤을 아래로 움직입니다.\n");
    printf("\n");
    next_line();
    printf("4. 트레이닝 기본 디렉토리\n");
    printf("트레이닝을 진행할 때는 사용자가 리눅스의 다른 디렉토리나 파일을 변형할 위험이 있으므로 별도의 디렉토리를 설정합니다.\n");
    printf("'home/[사용자 계정 이름]/tr' 디렉토리가 기본 디렉토리가 되어 명령어를 수행합니다.\n");
    printf("이는 사용자 계정 명과 함께 트레이닝 기능 중간에 명령어를 입력받을 때 터미널에 출력됩니다.\n");
    printf("\n");
    next_line();
    printf("기본 설명은 여기까지 입니다.\n");
    next_line();
    system("clear");
}
