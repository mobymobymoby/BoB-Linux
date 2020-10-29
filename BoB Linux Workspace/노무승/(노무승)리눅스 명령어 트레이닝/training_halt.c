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
        printf("\n");
        sleep(2);
        return 0;
    } else {
        training(test,guide);
    }
}

int main(){
    printf("halt 명령어는 시스템을 종료하는 명령어입니다.\n");
    sleep(3);
    printf("주의해야 할 점은 시스템만 종료되고, 시스템의 전원은 꺼지지 않는다는 점입니다.\n");
    sleep(5);
    printf("\n");

    training("halt","halt 명령어를 사용하여 시스템을 종료해보세요.\n(실제 적용되지는 않습니다.)");

    printf("비슷하게 시스템 종료를 수행하는 명령어로는 'shutdown', 'init', 'poweroff' 가 있으며,\n");
    sleep(5);
    printf("시스템 재부팅을 수행하는 명령어로는 'shutdown', 'init', 'reboot'가 있습니다.\n");
    sleep(5);
    printf("\n");

    printf("고생하셨습니다!\n");
}
