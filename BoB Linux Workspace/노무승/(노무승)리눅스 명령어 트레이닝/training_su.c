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
        printf("Password:\n");
        printf("Trainer@BoB:%s#\n", d_buf);
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
    printf("su 명령어는 사용자를 전환하기 위한 명령어입니다.\n");
    pause();

    printf("'su [전환할 사용자 이름]' 과 같이 사용합니다.\n");
    printf("위 예시와 같이 사용하면 전환하기 전 사용자 환경변수를 사용합니다.\n");
    pause();

    training("su root","su 명령어를 사용해 root 사용자로 전환해보세요. (su [전환할 사용자 이름])");

    printf("'su - [전환할 사용자 이름]' 과 같이 중간에 - 를 추가하면\n");
    printf("해당 사용자의 홈 디렉터리로 이동합니다.\n");
    printf("이는 해당 전환 대상 사용자의 환경 변수를 사용하는 것을 의미합니다.\n");
    pause();

    printf("고생하셨습니다!\n");
}
