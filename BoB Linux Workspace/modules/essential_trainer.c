#include "func.h"

void essential_trainer()
{
    printf("기초 명령어 학습입니다.\n");
    next_line();
    printf("해당 커리큘럼에서는 리눅스를 사용하는데 필요한 기초적인 필수 명령어를 학습합니다.\n");
    next_line();
    printf("명령어의 종류는 [whoami, pwd, ls, mkdir, touch, cat, cd, mv, cp, rm, clear]입니다.\n");
    next_line();
    printf("기초 명령어 학습은 리눅스 입문자들을 위한 과정으로, 리눅스를 처음 접해보는 분은 앞의 '기본 설명'을 듣고 오시는 것을 권장합니다.\n");
    next_line();
    printf("이전에 기초 명령어 학습을 진행하셨다면, 각 단계를 마칠 때 주어지는 'flag' 값을 통해 해당 단계 이후부터 시작하실 수 있습니다.\n");
    next_line();
    printf("flag가 있다면 입력해주시고, 처음부터 시작하시는 분은 0을 입력해주세요\n입력 : ");
    int flag_value = 0;

    scanf("%d", &flag_value);
    switch(flag_value)
    {
        default:
            printf("잘못된 flag 값입니다. 처음부터 학습을 시작합니다.\n");
        case 0:
            training_whoami();
            next_quit();
            printf("해당 단계의 flag 값은 '703'입니다.\n");
            next_line();
        case 703:
            training_pwd();
            next_quit();
            printf("해당 단계의 flag 값은 '1017'입니다.\n");
            next_line();
        case 905:
            training_ls();
            next_quit();
            printf("해당 단계의 flag 값은 '630'입니다.\n");
            next_line();
        case 1017:
            training_mkdir();
            next_quit();
            printf("해당 단계의 flag 값은 '1024'입니다.\n");
            next_line();
        case 1024:
            training_touch();
            next_quit();
            printf("해당 단계의 flag 값은 '1106'입니다.\n");
            next_line();
        case 1106:
            training_cat();
            next_quit();
            printf("해당 단계의 flag 값은 '1121'입니다.\n");
            next_line();
        case 1121:
            training_cd();
            next_quit();
            printf("해당 단계의 flag 값은 '1219'입니다.\n");
            next_line();
        case 1219:
            training_mv();
            next_quit();
            printf("해당 단계의 flag 값은 '1223'입니다.\n");
            next_line();
        case 1223:
            training_cp();
            next_quit();
            printf("해당 단계의 flag 값은 '1231'입니다.\n");
            next_line();
        case 1231:
            training_rm();
            next_quit();
            printf("해당 단계의 flag 값은 '808'입니다.\n");
            next_line();
        case 808:
            training_clear();
            break;
    }
    printf("\n기초 명령어 학습 과정이 끝났습니다.\n");
    next_line();
    printf("이제 여러분은 리눅스의 다양한 명령어들을 배울 준비가 되었습니다.\n");
    next_line();
    printf("기초 명령어 학습에서 배운 것은 리눅스를 사용할 때 필수적인 사항이므로 꾸준히 복습하여 숙지하시길 바랍니다.\n");
    next_line();
    printf("고생하셨습니다.\n");
}
