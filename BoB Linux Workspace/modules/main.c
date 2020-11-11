#include "func.h"

int main()
{
    system("clear");
    printf(" ____        ____            _     _                  \n");
    usleep(100000);
    printf("| __ )  ___ | __ )          | |   (_)_ __  _   ___  __\n");
    usleep(100000);
    printf("|  _ \\ / _ \\|  _ \\   _____  | |   | | '_ \\| | | \\ \\/ /\n");
    usleep(100000);
    printf("| |_) | (_) | |_) | |_____| | |___| | | | | |_| |>  < \n");
    usleep(100000);
    printf("|____/ \\___/|____/          |_____|_|_| |_|\\__,_/_/\\_\\ \n\n");

    printf(" _____          _\n");
    usleep(100000);
    printf("|_   _| __ __ _(_)_ __   ___ _ \n");
    usleep(100000);
    printf("  | || '__/ _` | | '_ \\ / _ \\ '__| \n");
    usleep(100000);
    printf("  | || | | (_| | | | | |  __/ |   \n");
    usleep(100000);
    printf("  |_||_|  \\__,_|_|_| |_|\\___|_|   \n\n");
    usleep(100000);

    printf("BoB Linux Training에 오신 것을 환영합니다. (Enter 키를 눌러 진행할 수 있습니다)\n");
    next_line();
    printf("본 트레이닝 기능은 BoB 9th Team \"Black Moon\"에서 제작하였습니다.\n");
    next_line();

    /* 기본 설명 듣기 : 1 듣지 않기 : 0 */
    int menu = 0;

    printf("트레이너 학습 전에 기본 설명을 들으시겠습니까?\n(리눅스를 처음 시작한다면 듣는 것을 권장)\n");
    printf("1번을 입력하면 기본 설명을 시작하고 0번을 입력하면 넘어갑니다.\n숫자를 입력해 주세요 : ");
    scanf("%d", &menu);
    printf("\n");
    if (menu == 1)
    {
        training_intro();
        menu = 0;
    }

    printf("본 트레이닝은 '기초 명령어 학습'과 '심화 명령어 학습'으로 나뉩니다.\n");
    next_line();
    printf("기초 명령어 학습은 리눅스를 사용하는데 필요한 내용과 명령어들을 정해진 순서대로 학습합니다.\n");
    printf("심화 명령어 학습은 리눅스를 효율적으로 사용하기 위한 다양한 응용 명령어들을 선택하여 학습할 수 있습니다.\n");
    next_line();


    while (1)
    {
        printf("1 : 기초 명령어 학습\n2 : 심화 명령어 학습\n0 : 종료\n실행할 학습을 선택하세요 : ");
        scanf("%d", &menu);

        if (menu == 1)
        {
            essential_trainer();
            break;
        }
        else if (menu == 2)
        {
            advanced_trainer();
            break;
        }
        else if ( menu == 0)
        {
            break;
        }
        else
        {
            printf("잘못된 번호를 입력했습니다. 다시 입력해주세요.\n");
        }
    }
    return 0;
}
