#include <stdio.h>
#include <unistd.h> // sleep, getcwd �Լ�
#include <string.h> // strncmp �Լ� 
// #include <stdlib.h> // system �Լ�

int training(char test[],char guide[]){
    char cmd[21]={}; // �ִ� �ǽ� ��ɾ� ���� ����
    char d_buf[30]={};
    int num=0,num2=0;

    while(1) {
        if (test[num]==0) {
            break;
        } else {
            ++num;
        }
    } // �ǽ� ��ɾ� ���� ����

    if ((num <= 1) || (num >= 20)) return -1;
    // �ּ�, �ִ� �ǽ� ��ɾ� ���� �������� �Լ� ����

    printf("[�ǽ�] %s\n",guide);
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
    } // �Է¹��� ��ɾ� ���� ����

    if ((strncmp(cmd,test,num)==0) && (num==num2-1)){
        printf("Password:\n");
        printf("Trainer@BoB:%s#\n", d_buf);
        printf("�� �ϼ̽��ϴ�!\n");
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
    printf("su ��ɾ�� ����ڸ� ��ȯ�ϱ� ���� ��ɾ��Դϴ�.\n");
    pause();

    printf("'su [��ȯ�� ����� �̸�]' �� ���� ����մϴ�.\n");
    printf("�� ���ÿ� ���� ����ϸ� ��ȯ�ϱ� �� ����� ȯ�溯���� ����մϴ�.\n");
    pause();

    training("su root","su ��ɾ ����� root ����ڷ� ��ȯ�غ�����. (su [��ȯ�� ����� �̸�])");

    printf("'su - [��ȯ�� ����� �̸�]' �� ���� �߰��� - �� �߰��ϸ�\n");
    printf("�ش� ������� Ȩ ���͸��� �̵��մϴ�.\n");
    printf("�̴� �ش� ��ȯ ��� ������� ȯ�� ������ ����ϴ� ���� �ǹ��մϴ�.\n");
    pause();

    printf("����ϼ̽��ϴ�!\n");
}
