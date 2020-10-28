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
    printf("kill 명령어는 PID를 이용해 프로세스를 종료하는 명령어입니다.\n");
    sleep(3);
    printf("PID란 ProcessID의 줄임말이며, 프로세스의 고유 번호를 뜻 합니다.\n");
    printf("\n");
    sleep(3);

    printf("시그널을 통해 다양한 종료 옵션을 지정해줄 수 있으며,\n");
    sleep(3);
    printf("시그널을 지정하지 않으면 자동으로 TERM(15번) 시그널로 설정됩니다.\n");
    sleep(3);
    printf("(ex. 'kill [PID]' -> 15번 TERM 시그널 전송)\n");
    printf("\n");
    sleep(3);
    
    printf("시그널 옵션을 보는 방법은 'kill -l' 명령어를 입력하면 됩니다.\n");
    printf("\n");
    sleep(3);
    printf("[알아두면 좋은 시그널 옵션]\n");
    sleep(2);
    printf("TERM (15번) = 기본 종료\n");
    sleep(3);
    printf("KILL (9번)  = 강제 종료\n");
    printf("\n");
    sleep(3);
    printf("특히 강제 종료(9번)는 최후의 수단으로 사용해야 합니다.\n");
    sleep(3);
    printf("프로세스를 강제 종료하게 되면 데이터가 유실될 수 있기 때문입니다.\n");
    sleep(3);

    printf("시그널을 지정하는 방법은 'kill -[시그널 번호] [PID]'와 같습니다.\n");
    printf("\n");
    sleep(4);

    training("kill -9 1234","kill 명령어로 PID 1234 프로세스를 '강제 종료' 하십시오. (시그널 사용)");
    training("kill -15 5678","kill 명령어로 PID 5678 프로세스를 '정상 종료' 하십시오. (시그널 사용)");
    training("kill 2020","kill 명령어로 PID 2020 프로세스를 '정상 종료' 하십시오. (시그널 미사용)");
    // 명령어 실습

    printf("PID를 확인하는 방법으로는 'ps' 명령어나 'top' 명령어를 사용하시면 됩니다.\n");
    sleep(4);
    printf("고생하셨습니다!\n");
}
