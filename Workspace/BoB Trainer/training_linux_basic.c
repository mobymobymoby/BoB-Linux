#include "func.h"

void training_linux_basic(void)
{
    create_defdir();
    system("clear");
    
    char menu[20] = "";
    printf("환영합니다.\n\n");
    printf("여기서는 리눅스가 무엇인지와 종류, 필요성 그리고 기본 디렉토리들을 배울 것입니다.\n\n\n");
    printf("1. 리눅스란 무엇인가\n\n");
    printf("2. 리눅스 배포판과 종류\n\n");
    printf("3. 리눅스의 필요성\n\n");
    printf("4. 리눅스의 기본 디렉토리들\n");
    next_line();
    
    while (1)
    {
        printf("1 : 리눅스란 무엇인가\n2 : 리눅스 배포판과 종류\n3 : 리눅스의 필요성\n4 : 리눅스의 기본 디렉토리들\nq : 종료(quit)\n\n실행할 학습을 선택하세요 : ");

        fgets(menu, sizeof(menu), stdin);

        // 나머지 입력 값 제거
        menu[strlen(menu) - 1] = '\0';

        // 입력값 검증 부분
        if (!strncmp(menu, "1", strlen("1")) && strlen(menu) == strlen("1"))
        {
            training_whatislinux();
            next_quit();
        }
        else if (!strncmp(menu, "2", strlen("2")) && strlen(menu) == strlen("2"))
        {
            training_linux_distro();
            next_quit();
        }    
        else if (!strncmp(menu, "3", strlen("3")) && strlen(menu) == strlen("3"))
        {
            training_whyneedlinux();
            next_quit();
        }
        else if (!strncmp(menu, "4", strlen("4")) && strlen(menu) == strlen("4"))
        {
            training_linux_defdir();
            next_quit();
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
           
    system("clear");
    
    /*
    printf("이상으로 리눅스 기본 지식 Part가 끝났습니다.\n\n");
    
    printf("이 트레이닝에서 배운 것만으로는 많이 부족할 것입니다.\n");
    printf("추후에 꼭 구글에 검색을 해보시거나 서적 등을 통해 더 많이 공부하시길 바랍니다.\n\n");
    */
    printf("고생하셨습니다.\n");
    
    delete_defdir();
}
