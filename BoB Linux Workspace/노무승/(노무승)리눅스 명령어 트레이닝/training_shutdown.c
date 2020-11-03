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
    printf("shutdown ��ɾ�� �ý����� �����ϰų� ����� �ϴ� ��ɾ��Դϴ�.\n");
    pause();

    printf("[�ý��� ���� �ɼ�]\n");
    printf("shutdown -h now : ��� �ý��� ����\n");
    printf("shutdown -h [����] : [����] �� �� �ý��� ����\n");
    printf("shutdown -h [hh:mm] : [hh:mm] �ð��� �ý��� ���� (ex. 12:00)\n");
    pause();

    training("shutdown -h now","shutdown ��ɾ ����Ͽ� ��� �ý����� ����ǰ� �غ�����.\n (���� �ݿ������� �ʽ��ϴ�.)");
    // �ý��� ��� ���� �ǽ�

    printf("�ý��� ������� 'shutdown -r [��� �ɼ�]' �� ���� ����ϸ�,\n");
    printf("�ý��� ���� ����� 'shutdown -P [��� �ɼ�]'�� �Է��ϸ� �˴ϴ�.\n");
    printf("[��� �ɼ�]�� �ý��� ����� �����մϴ�.\n");
    pause();

    training("shutdown -r 5","shutdown ��ɾ ����Ͽ� 5�� �� �ý����� ����� �ǰ� �غ�����.\n (���� �ݿ������� �ʽ��ϴ�.)");
    // �ý��� ���� ����� �ǽ�

    printf("shutdown ���� ��Ҵ� 'shutdown -c'�� �Է��ϸ� �˴ϴ�.\n");
    training("shutdown -c","shutdown ���� ����� ��� �غ�����.\n (���� �ݿ������� �ʽ��ϴ�.)");
    // ���� ��� �ǽ�

    printf("����ϰ� �ý��� ���Ḧ �����ϴ� ��ɾ�δ� 'init', 'poweroff', 'halt' �� ������,\n");
    printf("�ý��� ������� �����ϴ� ��ɾ�δ� 'init', 'reboot'�� �ֽ��ϴ�.\n");
    pause();

    printf("����ϼ̽��ϴ�!\n");
}