#include <stdio.h>
#include <unistd.h> // sleep, getcwd 함수
#include <string.h> // strncmp 함수 
// #include <stdlib.h> // system 함수

int training(char test[],char guide[]){
    char cmd[21]={}; // 최대 실습 명령어 길이 지정
    char d_buf[30]={};
    int num=0,num2=0;

    while(1) {
        if (test[num]==0) {
            break;
        } else {
            ++num;
        }
    } // 실습 명령어 길이 측정

    if ((num <= 1) || (num >= 20)) return -1;
    // 최소, 최대 실습 명령어 길이 미충족시 함수 종료

    printf("[실습] %s\n",guide);
    getcwd(d_buf, sizeof(d_buf));
	printf("Trainer@BoB:%s$ ", d_buf);
    fgets(cmd,20,stdin);
    fflush(stdin);

    while(1) {
        if (cmd[num2]==0) {
            break;
        } else {
            ++num2;
        }
    } // 입력받은 명령어 길이 측정

    if ((strncmp(cmd,test,num)==0) && (num==num2-1)){
        printf("잘 하셨습니다!\n");
        pause();
        return 0;
    } else {
        training(test,guide);
    }
}

void pause(){
    getchar();
    fflush(stdin);
}

int main(){
    printf("reboot 명령어는 시스템을 재부팅하는 명령어입니다.\n");
    printf("'-f 옵션을 주어 강제 재부팅이 가능합니다.\n");
    pause();

    training("reboot -f","reboot 명령어를 사용하여 시스템을 '강제 재부팅'해보세요.\n(실제 적용되지는 않습니다.)");

    printf("비슷하게 시스템 재부팅을 수행하는 명령어로는 'shutdown', 'init'이 있으며,\n");
    printf("시스템 종료를 수행하는 명령어로는 'shutdown', 'init', 'halt', 'poweroff' 가 있습니다.\n");
    pause();

    printf("고생하셨습니다!\n");
}