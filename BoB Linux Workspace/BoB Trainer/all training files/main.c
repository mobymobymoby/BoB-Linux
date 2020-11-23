#include "func.h"

int main()
{
    system("clear");
    print_banner();

    printf("BoB Linux Training에 오신 것을 환영합니다.\n");
    printf("(Enter 키를 눌러 진행할 수 있습니다)\n\n");
    printf("본 트레이닝 기능은 BoB 9th Team \"Black Moon\"에서 제작하였습니다.\n\n");
    printf("이어서 트레이닝에 앞서 기본적인 사항을 설명드리겠습니다.\n");
    next_line();
    system("clear");

    training_intro();

    select_menu(void);
    
    printf("\n[트레이너를 종료합니다.]\n");
    
    return 0;
}
