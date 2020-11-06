#include <stdio.h>
#include <unistd.h> // sleep, getcwd 함수
#include <string.h> // strncmp 함수 
// #include <stdlib.h> // system 함수

int training(char test[],char guide[]){
    char cmd[31]={}; // 최대 실습 명령어 길이 지정
    char d_buf[30]={};
    int num=0,num2=0;

    while(1) {
        if (test[num]==0) {
            break;
        } else {
            ++num;
        }
    } // 실습 명령어 길이 측정

    if ((num <= 1) || (num >= 30)) return -1;
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
        printf("  GNU nano 4.8                          test                                    \n");
        printf("TEST FILE\n");
        printf("                                  [ New File ]\n");
        printf("^G Get Help  ^O Write Out ^W Where Is  ^K Cut Text  ^J Justify   ^C Cur Pos\n");
        printf("^X Exit      ^R Read File ^\ Replace   ^U Paste Text^T To Spell  ^_ Go To Line\n");

        printf("\n");
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
    printf("nano 명령어는 nano 텍스트 편집기를 불러오는 명령어입니다.\n");
    pause();
    printf("다른 유명한 텍스트 편집기로는 vi와 vim 등이 있으며,\n");
    printf("nano 에디터는 그 중에서 사용하기 수월한 편에 속합니다.\n");
    pause();

    printf("'nano [파일 명]' 과 같이 입력하면 특정 파일을 nano 편집기로 열 수 있습니다.\n");
    training("nano test","test 파일을 nano 편집기로 열어보세요.");

    printf("기본적으로 방향키로 문자, 라인 이동이 가능합니다.\n");
    pause();

    printf("다음은 자주 사용하는 옵션들입니다.\n");
    printf("    nano -B [파일명] : 변경 이전 파일이 '[파일명]~'이름으로 백업됩니다.\n");
    printf("    nano -m [파일명] : 마우스를 사용합니다.\n");
    printf("    nano +[라인] [파일명] : 파일을 열자마자 특정 라인으로 이동합니다.\n");
    pause();

    printf("nano 편집기 내에서도 다양한 기능들이 존재하는데, 다음과 같습니다.\n");
    printf("\n");
    printf("[부가 기능]\n");
    printf("    ctrl+g (F1) : 도움말 표시\n");
    printf("    ctrl+x (F2) : nano 종료\n");
    printf("    ctrl+o (F3) : 파일 저장\n");
    pause();

    printf("[유용한 기능]\n");
    printf("    ctrl+w (F6) : 문자 검색\n");
    printf("    ctrl+\\ : 문자 검색 후 수정\n");
    printf("    ctrl+k (F9) : 현재 줄 잘라내기\n");
    printf("    ctrl+u : 이전에 자른 줄을 붙여넣기\n");
    printf("    alt+] : 현재 괄호에 매칭되는 괄호 찾기\n");
    printf("            (코딩시 유용하게 사용될 수 있음)\n");
    pause();
    
    printf("[라인 이동]\n");
    printf("    ctrl+y (F7) : 이전 화면으로 이동\n");
    printf("    ctrl+v (F8) : 다음 화면으로 이동\n");
    printf("    ctrl+a : 현재 라인의 시작 위치로 이동\n");
    printf("    ctrl+e : 현재 라인의 끝 위치로 이동\n");
    printf("    alt+( : 현재 문단의 시작으로 이동\n");
    printf("    alt+) : 현재 문단의 끝으로 이동\n");
    printf("    alt+\\ : 파일의 첫 라인으로 이동\n");
    printf("    alt+/ : 파일의 마지막 라인으로 이동\n");
    pause();

    printf("고생하셨습니다!\n");
}
