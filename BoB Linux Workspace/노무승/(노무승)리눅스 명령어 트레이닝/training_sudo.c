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
        sleep(1);
        printf("[sudo] password for Trainer:\n");
        sleep(1);
        printf("Trainer@BoB:%s#\n", d_buf);
        sleep(1);
        printf("잘 하셨습니다!\n");
        printf("\n");
        sleep(2);
        return 0;
    } else {
        training(test,guide);
    }
}

int main(){
    printf("sudo 명령어는 root 권한을 획득하기 위한 명령어입니다.\n");
    sleep(3);
    printf("\n");
    
    printf("root 권한은 리눅스의 최상위 권한으로써,\n");
    sleep(3);
    printf("리눅스 시스템 자체를 건드릴 수 있으므로 사용에 주의가 필요합니다.\n");
    sleep(3);
    printf("\n");
    
    printf("특정 명령어를 root 권한으로 실행하고 싶다면\n");
    sleep(3);
    printf("'sudo [명령어]'를 입력하면 됩니다.\n");
    sleep(3);
    printf("\n");

    training("sudo bash","bash 명령어를 root 권한으로 실행시켜봅시다.");
    // 트레이닝 1

    printf("일반 유저에서 root 유저로 전환하고 싶다면\n");
    sleep(3);
    printf("'sudo -s' 명령어를 입력하면 됩니다.\n");
    sleep(3);
    printf("\n");

    training("sudo -s","sudo 명령어를 이용해 일반 유저에서 root 유저로 전환해봅시다.");
     // 트레이닝 2   

    printf("root 유저로 바뀌면 명령줄 왼쪽의 문구가\n");
    sleep(3);
    printf("'$'에서 '#'으로 바뀐 것을 볼 수 있습니다.\n");
    sleep(3);
    printf("\n");

    printf("sudo 명령어로 권한 상승시, '/etc/sudoers' 파일을 참조하며\n");
    sleep(3);
    printf("해당 파일에 기록된 사용자만 root 권한 상승이 가능합니다.\n");
    sleep(3);
    printf("기록되지 않은 사용자에서 root 권한 상승을 하게 되면\n");
    sleep(3);
    printf("'{계정이름} is not in the sudoers file.' 라는 에러 문구가 뜨게 됩니다.\n");
    sleep(3);
    printf("\n");

    printf("권한 상승이 허용된 사용자는 다음과 같이 기록됩니다.\n");
    sleep(3);
    printf("{계정 이름} ALL=(ALL:ALL) ALL\n");
    sleep(3);
    printf("\n");

    printf("참고로 다른 사용자로 변경하는 명령어로는 'su' 명령어가 있습니다.\n");
    sleep(3);
    printf("고생하셨습니다!\n");
}
