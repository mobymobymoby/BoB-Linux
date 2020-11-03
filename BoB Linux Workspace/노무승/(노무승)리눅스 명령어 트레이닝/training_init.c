#include <stdio.h>
#include <unistd.h> // sleep 함수

void training(){
    char cmd[6]={};
    char d_buf[30]={};
    printf("[실습] init 명령어를 이용해 시스템을 종료하도록 하십시오.\n");
    printf("        ('init {숫자}' 명령어 입력을 통해 {숫자} 런레벨로 바꿀 수 있습니다.)\n");
    printf("        (실제 시스템에 적용되지는 않습니다.)\n"); 
    printf("\n");

    getcwd(d_buf, sizeof(d_buf));
	printf("Trainer@BoB:%s$ ", d_buf);
    fgets(cmd,7,stdin);
    fflush(stdin);
    
    if (strncmp(cmd,"init 0",6)!=0){
        training();
    }
}

void pause(){
    getchar();
    fflush(stdin);
}

int main(){
    printf("init 명령어는 런레벨(RunLevel)을 변경하는 명령어입니다.\n");
    pause();

    printf("[런레벨이란?]\n");
    printf("리눅스의 부팅 모드로 최대 8가지 런레벨이 존재하며,\n");
    printf("일반적으로 0에서 6까지의 총 7가지 런레벨을 사용합니다.\n");
    pause();

    printf("[각 런레벨 별 의미]\n");
    printf("RunLevel 0 (Power Off) : 시스템 종료 모드입니다.\n");
    printf("	해당 런레벨로 바꾸면 시스템이 종료됩니다.\n");
    pause();

    printf("RunLevel 1 (Resuce): 텍스트(CLI) 단일 사용자 모드입니다.\n");
    printf("	시스템 복구를 위해 사용되며, 관리자 쉘을 사용합니다.\n");
    pause();
    
    printf("RunLevel 2 (Multi-User): 네트워크를 사용하지 않는 텍스트(CLI) 다중 사용자 모드입니다.\n");
    printf("	현재는 사용하지 않으며, 호환성을 위해 런레벨 3과 동일하게 취급됩니다.\n");
    pause();

    printf("RunLevel 3 (Full Multi-User): 텍스트(CLI) 다중 사용자 모드입니다.\n");
    printf("	일반적으로 텍스트 유저 모드라고 부르면 해당 런레벨을 의미합니다.\n");
    pause();

    printf("RunLevel 4 (Multi-User(unused)): 사용하지 않는 다중 사용자 모드입니다.\n");
    printf("	호환성을 위해 런레벨 3과 동일하게 취급됩니다.\n");
    pause();

    printf("RunLevel 5 (Graphical): 그래픽(GUI) 다중 사용자 모드입니다.\n");
    printf("	기본적으로 런레벨 3과 동일하며, 그래픽을 제공한다는 점에서 차이가 있습니다.\n");
    pause();

    printf("RunLevel 6 (Reboot): 시스템 재부팅 모드입니다.\n");
    printf("	해당 런레벨로 바꾸면 시스템이 재부팅됩니다.\n");
    pause();

    printf("[주요 런레벨 정리]\n");
    printf("0 (시스템 종료), 6 (시스템 재부팅)\n");
    printf("3 (CLI 다중 사용자), 5 (GUI 다중 사용자)\n");
    pause();
    
    training();
    printf("잘 하셨습니다! 앞으로도 이런 식으로 런레벨을 바꾸면 됩니다.\n");
    pause();
    
    printf("현재 런레벨을 확인하는 방법으로 'runlevel' 명령어와 'who -r' 명령어가 있으며,\n");
    printf("시스템을 종료하는 명령어로는 'shutdown', 'half', 'reboot' 명령어가 있습니다.\n");
    pause();

    printf("고생하셨습니다!");
}