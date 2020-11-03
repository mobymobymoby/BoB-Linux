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
    printf("halt ��ɾ�� �ý����� �����ϴ� ��ɾ��Դϴ�.\n");
    pause();

    printf("�����ؾ� �� ���� �ý��۸� ����ǰ�, �ý����� ������ ������ �ʴ´ٴ� ���Դϴ�.\n");
    printf("��ü ��ɾ�� 'init', 'shutdown' ��ɾ� ����� ����帳�ϴ�.\n");
    pause();

    training("halt","halt ��ɾ ����Ͽ� �ý����� �����غ�����.\n(���� ��������� �ʽ��ϴ�.)");

    printf("����ϰ� �ý��� ���Ḧ �����ϴ� ��ɾ�δ� 'shutdown', 'init', 'poweroff' �� ������,\n");
    printf("�ý��� ������� �����ϴ� ��ɾ�δ� 'shutdown', 'init', 'reboot'�� �ֽ��ϴ�.\n");
    pause();

    printf("����ϼ̽��ϴ�!\n");
}