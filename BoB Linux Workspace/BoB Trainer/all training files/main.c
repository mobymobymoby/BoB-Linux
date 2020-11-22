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

    printf("본 트레이닝은 '기초 명령어 학습'과 '심화 명령어 학습'으로 나뉩니다.\n\n");
    printf("기초 명령어 학습은 리눅스를 사용하는데 필요한 내용과 명령어들을 정해진 순서대로 학습합니다.\n\n");
    printf("심화 명령어 학습은 리눅스를 효율적으로 사용하기 위한 다양한 응용 명령어들을 선택하여 학습할 수 있습니다.\n");
    next_line();

    char menu;
    while (1)
    {
        printf("1 : 기초 명령어 학습\n2 : 심화 명령어 학습\nq : 종료\n실행할 학습을 선택하세요 : ");
        menu = getchar();
        __fpurge(stdin);
        
        
        if (menu == '1')
        {
            training_linux_basic();
            break;
        }
        else if (menu == '2')
        {
            essential_trainer();
            break;
        }
        else if (menu == '3')
        {
            advanced_trainer();
            break;
        }
        else if ( menu == 'q' || menu == 'Q')
        {
            break;
        }
        else
        {
            system("clear");
            printf("잘못된 입력입니다. 다시 입력해주세요.\n\n");
        }
    }
    return 0;
}
