#include <stdio.h>
#include <unistd.h> // sleep, getcwd, access �Լ�
#include <string.h> // strncmp �Լ� 
#include <stdlib.h> // system �Լ�
#define MAX_LINE 30 // �ִ� �ǽ� ��ɾ� ���� ����

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
    } // �ǽ� ��ɾ� ���� ����

    if ((num <= 1) || (num >= MAX_LINE)) return -1;
    // �ּ�, �ִ� �ǽ� ��ɾ� ���� �������� �Լ� ����

    printf("[�ǽ�] %s\n",guide);
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
    } // �Է¹��� ��ɾ� ���� ����

    if ((strncmp(cmd,test,num)==0) && (num==num2-1)){
        system(test);
        printf("�� �ϼ̽��ϴ�!\n");
        pause();
        return 0;
    } else {
        training(test,guide);
    }
}

void file_check(){
    int Result = access("./index.html", 0 );
    if (Result == 0) remove("./index.html");
} // ���� ���� Ȯ�� ��, ����� ����

void pause(){
    getchar();
    fflush(stdin);
}

int main(){
    printf("wget ��ɾ�� �� �� �ִ� ������ �ٿ�޴� ��ɾ��̸�,\n");
    printf("�����Ǵ� ���������� HTTP, HTTPS, FTP�� �ֽ��ϴ�.\n");
    pause();

    printf("�⺻������ �� �� �ִ� ������ �ٿ���� ����\n");
    printf("'wget [URL ��ũ]'�� ���� ����մϴ�.\n");
    pause();

    file_check();
    training("wget https://www.naver.com","���̹�(https://www.naver.com)�� �� ������ ������ �ٿ�޾ƺ�����.");
    file_check();
    // Ʈ���̴� ����

    printf("[��Ÿ ������ �ɼǵ�]\n");
    printf("wget -c [URL] : ���� �̾�ޱ�\n");
    printf("wget -0 [URL] : �Ķ���� ������ ��ũ���� ���� �ٿ�ε�\n");
    printf("wget -r [URL] : ���͸� ������ ������ä �ٿ�ε�\n");
    printf("wget -nd -r --accept=[Ȯ����] [URL] : Ư�� Ȯ���� ���ϸ� �ٿ�ε�\n");
    printf("wget -nd -r --reject=[Ȯ����] [URL] : Ư�� Ȯ���� ���ϸ� ���� �ٿ�ε�\n");
    printf("�̿� ���� �ɼ��� ����ϸ� ���� �����ϰ� Ȱ���� �� �ֽ��ϴ�.\n");
    pause();
    printf("����ϼ̽��ϴ�!\n");
}
