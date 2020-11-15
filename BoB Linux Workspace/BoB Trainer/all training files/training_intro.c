#include "func.h"

void training_intro()
{
    system("clear");
    printf("트레이닝에 앞서 기본적인 사항을 설명드리겠습니다.\n");
    next_line();
    printf("1. 트레이닝 진행 방법\n");
    printf("기본적으로 Enter 키를 누르면 다음 메시지가 뜨는 방식으로 진행할 수 있습니다.\n");
    printf("\n");
    printf("특정 설명에서는 여러분으로 부터 입력을 받아 명령어를 실행하기도 합니다.\n");
    printf("이 때 조건에 일치하는 명령어를 입력해야 하며, 잘못된 명령어를 입력했을 때는 다시 입력을 받게 됩니다.\n");
    next_line();
    system("clear");
    printf("2. 옵션의 중첩\n");
    printf("트레이닝 기능에서 배우게 되는 대부분의 옵션은 중첩하여 사용할 수 있습니다.\n");
    printf("예를 들어 'ls' 명령어의 '-a' 옵션과 '-l' 옵션은 \"ls -a\"이나 \"ls -l\"로 따로 쓸 수도 있지만 \"ls -al\"과 같이 한 번에 사용할 수 있습니다.\n\n");
    printf("이 때의 기능은 -a 옵션과 -l의 옵션을 합친 것이 됩니다. 이러한 법칙은 ls 뿐만 아니라 대부분의 명령어에 통용됩니다.\n");
    next_line();
    system("clear");
    printf("3. 터미널에서의 스크롤 이동 방법\n");
    printf("BoB Linux Trainer는 터미널을 통해 작동합니다.\n");
    printf("\n");
    printf("터미널에서는 키보드 방향키 위에 있는 \"PgUp\" 키와 \"PgDn\" 키를 이용해 스크롤을 이동할 수 있습니다.\n");
    printf("<Shift + PgUp>은 스크롤을 위로, <Shift + PgDn>은 스크롤을 아래로 움직입니다.\n");
    next_line();
    system("clear");
    printf("4. 트레이닝 기본 디렉토리\n");
    printf("트레이닝을 진행할 때는 사용자가 리눅스의 다른 디렉토리나 파일을 변형할 위험이 있으므로 별도의 디렉토리를 설정합니다.\n");
    printf("'home/[사용자 계정 이름]/tr' 디렉토리가 기본 디렉토리가 되어 명령어를 수행합니다.\n");
    printf("이는 사용자 계정 명과 함께 트레이닝 기능 중간에 명령어를 입력받을 때 터미널에 출력됩니다.\n");
    next_line();
    system("clear");
    printf("5. [사용자 계정 이름]@localhost:/home/[사용자 계정 이름]/tr$ \n");
    printf("         (1)            (2)                 (3)           (4)\n\n");
    printf("트레이닝 진행 시 여러분의 입력이 필요한 부분에서는 위와 같은 메시지가가 출력됩니다.\n");
    printf("해당 입력 창은 '프롬프트'라고 부르며, 리눅스의 터미널 창과 같은 구조로 되어 있습니다.\n");
    printf("프롬프트 창의 구조는 리눅스 마다 다르지만, 거의 비슷한 구조를 따릅니다.\n위에서는 크게 4가지로 분류할 수 있습니다.\n\n");
    printf("(1) : 사용자의 계정 이름이 들어갑니다.\n");
    printf("(2) : '호스트'의 이름이 들어갑니다.\n");
    printf("(3) : 현재 작업 디렉토리가 표시됩니다.\n");
    printf("(4) : 현재 사용자가 루트 계정이라면 #으로, 아니라면 $으로 표시됩니다.\n");
    next_line();
    system("clear");
    printf("6. '-' 옵션과 '--' 옵션(롱 옵션)\n");
    printf("리눅스 명령어에는 다양한 기능을 처리하기 위한 옵션이 존재합니다.\n");
    printf("보통 옵션은 '-a'와 같이 -(dash)를 이용하여 사용합니다.\n");
    printf("하지만, '-'를 두 번 붙여서 사용하는 방법으로 옵션을 쓸 수도 있습니다.\n\n");
    printf("예를 들어 ls 명령어의 '-a' 옵션을 롱 옵션으로 사용하면 'ls --all'으로 입력하면 됩니다.\n");
    printf("기능 상의 차이는 없으며, 대부분의 사람들은 더 짧은 옵션을 사용하지만 간혹가다가 롱 옵션을 사용하는 경우도 존재합니다.\n");
    next_line();
    system("clear");
    printf("기본 설명은 여기까지 입니다.\n");
    next_line();
    system("clear");
}
