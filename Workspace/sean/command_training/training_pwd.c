#include "func.h"

void training_pwd(void)
{
    create_defdir();
    
    char wd[BUFSIZ];
	getcwd(wd,BUFSIZ);

    system("clear");
    
    printf("이번에 배울 명령어는 \"pwd\" 입니다.\n");
    next_line();
    printf("\"pwd\" 명령어는 현재 작업 중인 디렉터리 경로를 절대 경로로 보여주는 명령어입니다.\n");
    next_line();
    printf("\"pwd\" 명령어는 'Print Working Directory'의 앞글자들만 따와서 조합한 것입니다.\n");
    printf("현재 자신이 어떤 디렉터리 경로에 있는 지 확인하고 싶을 때 사용합니다.\n");
    next_line();
    printf("\"pwd\" 명령어의 실행 파일은 \"/bin/pwd\"로 있습니다.\n");
    printf("'root' 디렉토리(폴더) 밑에 'bin' 디렉토리(폴더) 밑에 \"pwd\"으로 있습니다.\n");
    next_line();
    printf("사용법은 \"pwd [옵션]\" 입니다.\n");
    printf("옵션이 필요하지 않은 경우 옵션은 입력하지 않아도 됩니다.\n");
    printf("ex) pwd 혹은 pwd -L\n");
    next_line();
    printf("\"pwd\" 명령어의 옵션으로는 다음과 같습니다.\n");
    next_line();
    printf("'-L(--logical)' - 심볼릭을 포함하더라도 pwd 환경 변수를 사용해줍니다.\n");
    printf("'-P(--physical)' - 심볼릭 정보를 무시하고 출력해줍니다.\n");
    printf("'--help' - pwd 명령어의 사용법을 출력해줍니다.\n");
    printf("'--version' - pwd 명령어의 버전 정보를 출력해줍니다.\n");
    next_line();
    printf("현재 작업 중이 디렉토리의 경로를 보는 실습을 하겠습니다.\n");
    next_line();
    printf("\"pwd\"을(를) 입력하여 실습해보세요.\n");
    just_run_command("pwd");
    next_line();
    printf("위에 보이시는 '%s'이(가) 현재 작업 중인 디렉터리 경로를 절대 경로로 보여준 것입니다.\n", wd);
    next_line();
    printf("\"pwd\" 명령어는 자주 사용하는 명령어들 중 하나입니다.\n");
    next_line();
    printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
    printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
    next_line();
    printf("\"pwd\" 명령어의 학습이 끝났습니다.\n");
    next_line();

    delete_defdir();
}
