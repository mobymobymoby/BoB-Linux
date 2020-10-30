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
    printf("fsck 명령어는 리눅스 파일 시스템을 검사하고 수리하는 명령어입니다.\n");
    sleep(5);
    printf("\n");

    printf("파일 시스템 검사 절차는 다음과 같습니다.\n");
    sleep(3);
    printf("    단계 1  : 블록들과 파일 크기 검사\n");
    sleep(3);
    printf("    단계 2a : 중복된 이름이 있는지 검사\n");
    sleep(3);
    printf("    단계 2b : 경로 이름 검사\n");
    sleep(3);
    printf("    단계 3  : 연결성 검사\n");
    sleep(3);
    printf("    단계 4  : 참조 수 검사\n");
    sleep(3);
    printf("    단계 5  : 싸이클 그룹 검사\n");
    sleep(3);
    printf("\n");

    printf("fsck 명령이 손상된 파일이나 디렉터리를 수리할 때,\n");
    sleep(3);
    printf("/lost+found 디렉터리에서 작업을 수행하고 복구가 완료되면 사라집니다.\n");
    sleep(5);
    printf("\n");

    printf("fsck 명령으로 검사하거나 수리할 파티션은 마운트가 된 상태면 안됩니다.\n");
    sleep(5);
    printf("반드시 umount 명령어 등으로 마운트를 헤제하고 수행해주어야 합니다.\n");
    sleep(5);
    printf("\n");

    printf("기본적으로 'fsck [파티션 경로]' 와 같은 형식으로 사용합니다.\n");
    sleep(3);
    printf("\n");

    training("fsck /dev/sdb1","fsck 명령어로 /dev/sdb1 파티션을 검사해보세요.\n(실제 반영되지는 않습니다.)");

    printf("기본적인 사용법 이외에도 다양한 명령 옵션이 있습니다.\n");
    sleep(3);
    printf("    -v : 점검 내역을 자세하게 출력해줍니다.\n");
    sleep(3);
    printf("    -y : 모든 응답을 다 yes를 해서 자동으로 점검, 수리를 수행합니다.\n");
    sleep(3);
    printf("    -n : 모든 응답을 다 no를 해서 점검만 수행합니다.\n");
    sleep(3);
    printf("    -f : 파일 시스템 이상 유무와 관계없이 강제로 점검을 합니다.\n");
    sleep(3);
    printf("\n");

    printf("고생하셨습니다!\n");
}
