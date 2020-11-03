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
    printf("shutdown 명령어는 시스템을 종료하거나 재부팅 하는 명령어입니다.\n");
    pause();

    printf("[시스템 종료 옵션]\n");
    printf("shutdown -h now : 즉시 시스템 종료\n");
    printf("shutdown -h [숫자] : [숫자] 분 후 시스템 종료\n");
    printf("shutdown -h [hh:mm] : [hh:mm] 시간에 시스템 종료 (ex. 12:00)\n");
    pause();

    training("shutdown -h now","shutdown 명령어를 사용하여 즉시 시스템이 종료되게 해보세요.\n (실제 반영되지는 않습니다.)");
    // 시스템 즉시 종료 실습

    printf("시스템 재부팅은 'shutdown -r [사용 옵션]' 과 같이 사용하며,\n");
    printf("시스템 강제 종료는 'shutdown -P [사용 옵션]'를 입력하면 됩니다.\n");
    printf("[사용 옵션]은 시스템 종료와 동일합니다.\n");
    pause();

    training("shutdown -r 5","shutdown 명령어를 사용하여 5분 후 시스템이 재부팅 되게 해보세요.\n (실제 반영되지는 않습니다.)");
    // 시스템 예약 재부팅 실습

    printf("shutdown 예약 취소는 'shutdown -c'를 입력하면 됩니다.\n");
    training("shutdown -c","shutdown 예약 명령을 취소 해보세요.\n (실제 반영되지는 않습니다.)");
    // 예약 취소 실습

    printf("비슷하게 시스템 종료를 수행하는 명령어로는 'init', 'poweroff', 'halt' 가 있으며,\n");
    printf("시스템 재부팅을 수행하는 명령어로는 'init', 'reboot'가 있습니다.\n");
    pause();

    printf("고생하셨습니다!\n");
}