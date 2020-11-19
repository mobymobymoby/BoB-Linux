#include "func.h"

void training_cd(void)
{
    create_defdir();
    system("clear");
    char cwd[DIR_SIZE];
    char command_str[DIR_SIZE*2];
    getcwd(cwd, DIR_SIZE);
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    
    printf("이번에 학습할 명령어는 \"cd\" 입니다.\n");
    next_line();
    printf("\"cd\" 명령어는 'Change Directory'의 약자이며, 디렉토리를 이동할 때 사용하는 명령어 입니다.\n");
    next_line();

    system("mkdir dir1");
    system("mkdir dir2");
    // 테스트 폴더 생성 

    printf("사용법은 \"cd [디렉토리 경로]\" 입니다.\n");
    printf("디렉토리 경로를 지정할 때, '절대 경로'나 '상대 경로'를 지정하여 사용합니다.\n");
    next_line();

    printf("[절대 경로]는 \"최상위 디렉토리부터 나열된 고유한 경로\"를 의미합니다.\n");
    printf("(ex. /etc/systemd)\n");
    next_line();
    printf("맨 앞의 '/'가 루트(최상위) 디렉토리를 의미하며\n");
    printf("\"cd /\"를 입력하면, 루트 디렉토리로 이동하게 됩니다.\n");
    next_line();
    
    printf("[실습] \"cd\" 명령어를 사용해 '%s/dir1' 디렉토리로 이동해보세요.\n", cwd);
    printf("사용법 : cd [디렉토리 경로]\n");
    snprintf(command_str, sizeof(command_str), "cd %s/dir1", cwd);
    fake_run_command(command_str);
    chdir(cwd);
    chdir("dir1");
    next_line();
    // 절대 경로 트레이닝

    printf("[상대 경로]는 상대적인 경로로, 아래와 같은 지정 방식이 있습니다.\n");
    printf(". : 현재 작업 디렉토리를 의미합니다.\n");
    printf(".. : 현재 작업 디렉토리의 상위 디렉토리를 의미합니다.\n");
    next_line();
    
    printf("다음과 같이 '/etc' 디렉토리 밑에 'dir1', 'dir2', 'dir3' 디렉토리가 있다고 한다면\n\n");
    printf("     ---- dir1\n");
    printf("     |        \n");
    printf("/etc ---- dir2\n");
    printf("     |        \n");
    printf("     ---- dir3\n");
    next_line();

    printf("[ ./dir1/ ](은)는 현재 작업 디렉토리 밑에 있는 'dir1' 디렉토리를 의미합니다.\n");
    printf("ex) 현재 작업 디렉토리가 '/etc' 일 때, [ ./dir1 ](은)는 \"/etc/dir1\"(와)과 같습니다.)\n\n");
    printf("[ ../dir2/ ](은)는 현재 작업 디렉토리의 상위 디렉토리에 있는 다른 디렉토리인 'dir2'를 의미합니다.\n");
    printf("ex) 현재 작업 디렉토리가 '/etc/dir2' 일 때, [ ../dir3 ](은)는 \"/etc/dir3\"(와)과 같습니다.)\n");
    next_line();
    
    printf("[실습] '상대 경로'의 '상위 경로'를 이용해 상위 디렉토리에 있는 'dir2' 디렉토리로 이동해보세요.\n");
    printf("사용법 : cd [디렉토리 상대 경로]\n");
    fake_run_command("cd ../dir2");
    chdir("cd ../dir2");
    next_line();
    // 상대 경로 트레이닝 

    printf("만약 현재 작업 디렉토리에서 현재 작업 디렉토리의 상위 디렉토리로 이동하고 싶다면\n");
    printf("\"cd ..\"을(를) 입력하면 됩니다.\n");
    next_line();
    printf("[실습] \"cd ..\"을(를) 입력해 상위 디렉토리로 이동해보세요.\n");
    fake_run_command("cd ..");
    chdir("cd ..");
    next_line();
    // 상위 경로 트레이닝

    printf("이동하기 이전의 디렉토리로 되돌아가기 위해서는 'cd -'를 입력하면 됩니다.\n\n");
    printf("[실습] 'cd -'(을)를 입력해 이전의 디렉토리로 되돌아가 보세요.\n");
    fake_run_command("cd -");
    chdir("cd -");
    next_line();
    // 이전 경로 트레이닝
    
    printf("\"cd\" 명령어의 다른 사용법으로는 다음과 같습니다.\n\n");
    printf("[ cd . ]      : 현재 디렉토리를 의미합니다.\n");
    printf("[ cd .. ]     : 한 단계 상위 디렉토리로 이동합니다.\n");
    printf("[ cd / ]      : 최상위 디렉토리로 이동합니다.\n");
    printf("[ cd $변수명] : 지정된 변수명에 저장된 경로로 이동합니다.\n");
    printf("[ cd ~ ]      : 홈 디렉토리로 이동합니다.\n");
    printf("[ cd $HOME ]  : 홈 디렉토리로 이동합니다.\n");
    printf("[ cd ]        : 홈 디렉토리로 이동합니다.\n");
    printf("[ cd ~계정명] : 입력한 사용자의 홈 디렉토리로 이동합니다.\n");
    printf("[ cd - ]      : 이전 경로로 이동합니다.\n");
    next_line();
    printf("\"cd\" 명령어의 학습이 끝났습니다.\n");
    printf("고생하셨습니다.\n");

    delete_defdir();
}
