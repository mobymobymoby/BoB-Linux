#include <stdio.h>
#include <unistd.h> // sleep, getcwd 함수
#include <string.h> // strncmp 함수 
#include <stdlib.h> // system 함수

void training(){
    char cmd[9]={};
    char d_buf[30]={};
    printf("[실습] runlevel 명령어를 입력해보세요.\n");
    getcwd(d_buf, sizeof(d_buf));
	printf("Trainer@BoB:%s$ ", d_buf);
    fgets(cmd,sizeof(cmd),stdin);
    
    if (strncmp(cmd,"runlevel",8)==0){
        system("runlevel");
    } else {
        training();
    }
}

int main(){
    printf("runlevel 명령어는 런레벨(RunLevel)을 확인하는 명령어입니다.\n");
    printf("\n");
    sleep(2);

    printf("런레벨에 관한 내용은 init 명령어 트레이닝을 참고하시면 됩니다.\n");
    sleep(2);
    printf("\n");
    
    training();

    printf("잘 하셨습니다!\n");
    sleep(2);
    printf("왼쪽에 표기된 것이 이전의 런레벌이고, \n");
    sleep(2);
    printf("오른쪽에 표기된 것이 현재 런레벨입니다.\n");
    printf("\n");
    sleep(3);
    printf("고생하셨습니다!\n");
}
