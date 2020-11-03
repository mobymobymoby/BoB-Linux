#include <stdio.h>
#include <unistd.h> // sleep, getcwd, access 함수
#include <string.h> // strncmp 함수 
#include <stdlib.h> // system 함수
#define MAX_LINE 30 // 최대 실습 명령어 길이 지정

int training(char test[],char guide[]){    
    char cmd[MAX_LINE+1]={}; 
    char d_buf[MAX_LINE]={};
    int num=0,num2=0;

    while(1) {
        if (test[num]==0) {
            break;
        } else {
            ++num;
        }
    } // 실습 명령어 길이 측정

    if ((num <= 1) || (num >= MAX_LINE)) return -1;
    // 최소, 최대 실습 명령어 길이 미충족시 함수 종료

    printf("[실습] %s\n",guide);
    getcwd(d_buf, sizeof(d_buf));
	printf("Trainer@BoB:%s$ ", d_buf);
    fgets(cmd,30,stdin);
    fflush(stdin);

    while(1) {
        if (cmd[num2]==0) {
            break;
        } else {
            ++num2;
        }
    } // 입력받은 명령어 길이 측정

    if ((strncmp(cmd,test,num)==0) && (num==num2-1)){
        system(test);
        printf("잘 하셨습니다!\n");
        pause();
        return 0;
    } else {
        training(test,guide);
    }
}

void file_check(){
    int Result = access("./index.html", 0 );
    if (Result == 0) remove("./index.html");
} // 파일 존재 확인 후, 존재시 삭제

void pause(){
    getchar();
    fflush(stdin);
}

int main(){
    printf("wget 명령어는 웹 상에 있는 파일을 다운받는 명령어이며,\n");
    printf("지원되는 프로토콜은 HTTP, HTTPS, FTP가 있습니다.\n");
    pause();

    printf("기본적으로 웹 상에 있는 파일을 다운받을 때는\n");
    printf("'wget [URL 링크]'와 같이 사용합니다.\n");
    pause();

    file_check();
    training("wget https://www.naver.com","네이버(https://www.naver.com)의 웹 페이지 파일을 다운받아보세요.");
    file_check();
    // 트레이닝 시작

    printf("[기타 유용한 옵션들]\n");
    printf("wget -c [URL] : 파일 이어받기\n");
    printf("wget -0 [URL] : 파라미터 형태의 링크에서 파일 다운로드\n");
    printf("wget -r [URL] : 디렉터리 구조를 유지한채 다운로드\n");
    printf("wget -nd -r --accept=[확장자] [URL] : 특정 확장자 파일만 다운로드\n");
    printf("wget -nd -r --reject=[확장자] [URL] : 특정 확장자 파일만 빼고 다운로드\n");
    printf("이와 같이 옵션을 사용하면 더욱 유용하게 활용할 수 있습니다.\n");
    pause();
    printf("고생하셨습니다!\n");
}
