#include "func.h"

void training_which(void)
{

    create_defdir();

    system("clear");

    printf("이번에 배울 명령어는 \"which\" 입니다.\n\n");
    
    printf("\"which\" 명령어는 특정 명령어의 실행 파일 혹은 링크 위치를 환경 변수를 기반으로 검색하고 찾아주는 명령어입니다.\n");
    next_line();
    
    printf("\"which\" 명령어의 실행 파일은 \"/usr/bin/which\"로 있습니다.\n");
    printf("'root' 디렉토리(폴더) 밑에 'usr' 디렉토리(폴더) 밑에 'bin' 디렉토리(폴더) 밑에\n");
    printf("\"which\"로 있습니다.\n");
    next_line();
    
    printf("사용법은 \"which [옵션] [위치를 찾고 싶은 명령어]\" 입니다.\n");
    printf("ex)which ls\n");
    next_line();
    
    printf("\"which\" 명령어는 엄청 간단하고 쉽습니다.\n");
    next_line();
    
    printf("\"which\" 명령어를 이용하여 \"pwd\" 명령어의 위치를 알아보세요.\n");
    printf("사용법 : which [위치를 찾고 싶은 명령어]\n");
    just_run_command("which pwd");
    
    next_line();
    printf("잘 따라오셨다면 \"/bin/pwd\" 라고 출력되었을 것입니다.\n");
    next_line();
    
    printf("해석하자면 \"'root' 디렉토리 밑에 'bin' 디렉토리 밑에 위치하고 있다\" 입니다.\n");
    next_line();
    
    printf("\"which\" 명령어의 옵션은 '-a' 하나 입니다.\n");
    printf("-a : 입력된 찾고자 하는 명령어가 검색되는 모든 경로를 출력해줍니다.\n");
    next_line();
    
    printf("\"which\" 명령어는 정말 쉽고 간단하여 내용도 짧습니다.\n");
    next_line();
    
    printf("\"which\" 명령어의 옵션은 위에 나온 것들 말고도 여러가지가 있습니다.\n");
    next_line();
    
    printf("이후에 콘솔 혹은 터미널에 \"man\" 명령어나\n");
    printf("\"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
    printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
    next_line();
    
    printf("\"which\" 명령어의 학습이 끝났습니다.\n");
    next_line();

    delete_defdir();
}
