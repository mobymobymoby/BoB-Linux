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
    printf("cd 명령어는 작업 디렉터리를 옮길 때 사용하는 명령어입니다.\n");
    sleep(3);
    printf("\n");

    printf("'cd {디렉터리 경로}' 형식으로 사용하며,\n");
    sleep(3);
    printf("디렉터리 경로를 지정할 때, 절대 경로와 상대 경로를 지정하여 사용합니다.\n");
    sleep(5);
    printf("\n");

    printf("절대 경로는 최상위 디렉터리부터 나열된 고유한 경로를 의미합니다.\n");
    sleep(5);
    printf("(ex. /etc/systemd)\n");
    sleep(3);
    printf("\n");
    printf("맨 앞의 /가 루트(최상위) 디렉터리를 의미하며,\n");
    sleep(3);
    printf("'cd /' 입력시, 루트 디렉터리로 이동하게 됩니다.\n");
    sleep(3);
    printf("\n");

    training("cd /etc/systemd","cd 명령어를 사용해 /etc/systemd 폴더로 이동해보세요.");
    // 절대 경로 트레이닝

    printf("상대 경로는 상대적인 경로로, 아래와 같은 지정 방식이 있습니다.\n");
    sleep(3);
    printf(". : 현재 작업 디렉터리를 의미\n");
    sleep(5);
    printf(".. : 현재 작업 디렉터의 상위 디렉터리를 의미\n");
    sleep(5);
    printf("\n");

    printf("예를 들어 './1234/' 는 현재 작업 디렉터리 하위의 1234 디렉터리를 의미하고,\n");
    sleep(5);
    printf("(작업 디렉터리가 /etc 일 때, ./1234 는 /etc/1234와 같음.)\n");
    sleep(5);
    printf("\n");

    printf("'../1234/' 는 현재 작업 디렉터리 상위의 1234 디렉터리를 의미합니다.\n");
    sleep(5);
    printf("(작업 디렉터리가 /etc 일 때, ../1234 는 /1234와 같음.)\n");
    sleep(5);
    printf("\n");

    training("cd ../test", "상위 경로를 이용해 상위 디렉터리의 test 디렉터리로 이동해보세요.\n");
    // 상대 경로 트레이닝 

    printf("만약 현재 작업 디렉터리의 상위 디렉터리로 이동하고 싶다면 'cd ..' 을 입력하면 됩니다.\n");
    sleep(5);
    printf("\n");

    training("cd ..", "'cd ..'을 입력해 루트 디렉터리로 이동해보세요.");
    // 상위 경로 트레이닝

    printf("이동하기 이전의 디렉터리로 되돌아가기 위해서는 'cd -'를 입력하면 됩니다.\n");
    sleep(5);
    printf("\n");
    
    training("cd -", "'cd -'을 입력해 이전의 디렉터리로 되돌아가 보세요.");
    // 이전 경로 트레이닝

    printf("고생하셨습니다!\n");
}
