#include "func.h"

void select_menu(void)
{
    char menu[20] = "";
    printf("본 트레이닝은 크게 [기초 명령어 학습]과 [응용 명령어 학습]으로 나뉩니다.\n\n");
    printf("[기초 명령어 학습]은 리눅스를 사용하는데 필요한 내용과\n");
    printf("명령어들을 정해진 순서대로 학습합니다.\n\n\n");
    printf("[응용 명령어 학습]은 리눅스를 효율적으로 사용하기 위한\n");
    printf("다양한 응용 명령어들을 선택하여 학습할 수 있습니다.\n\n");
    next_line();
    
    while (1)
    {
        printf("1 : 리눅스 기본 지식\n2 : 기초 명령어 학습\n3 : 응용 명령어 학습\n0 : 프로그램 정보\nq : 종료\n\n실행할 학습을 선택하세요 : ");

        fgets(menu, sizeof(menu), stdin);

        // 나머지 입력 값 제거
        menu[strlen(menu) - 1] = '\0';

        // 입력값 검증 부분
        if (!strncmp(menu, "1", strlen("1")) && strlen(menu) == strlen("1"))
        {
            training_linux_basic();
            break;
        }
        else if (!strncmp(menu, "2", strlen("2")) && strlen(menu) == strlen("2"))
        {
            essential_trainer();
            break;
        }    
        else if (!strncmp(menu, "3", strlen("3")) && strlen(menu) == strlen("3"))
        {
            advanced_trainer();
            break;
        }
        else if ( (!strncmp(menu, "i", strlen("i")) && strlen(menu) == strlen("i")) || (!strncmp(menu, "I", strlen("I")) && strlen(menu) == strlen("I")) ) || (!strncmp(menu, "info", strlen("info")) && strlen(menu) == strlen("info")) )
        {
            program_information();
            break;
        }
        else if ( (!strncmp(menu, "q", strlen("q")) && strlen(menu) == strlen("q")) || (!strncmp(menu, "Q", strlen("Q")) && strlen(menu) == strlen("Q")) )
        {
            break;
        }
        else
        {
            system("clear");
            printf("잘못된 입력입니다. 다시 입력해주세요.\n\n");
        }
    }
}
