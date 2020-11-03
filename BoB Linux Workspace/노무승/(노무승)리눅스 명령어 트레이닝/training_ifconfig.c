#include <stdio.h>
#include <unistd.h> // sleep, getcwd �Լ�
#include <string.h> // strncmp �Լ� 
#include <stdlib.h> // system �Լ�

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
        system(test);
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
    printf("ifconfig ��ɾ�� ��Ʈ��ũ �������̽��� Ȯ���ϰ� ������ �� �ִ� ��ɾ��Դϴ�.\n");
    pause();

    training("ifconfig","ifconfig ��ɾ �Է��� ��Ʈ��ũ �������̽��� Ȯ���غ�����.");
    // ��Ʈ��ũ �������̽� ��� �ǽ�

    printf("�� ������ ��� ��Ʈ��ũ �������̽��� �̸�(ex. enp0s3) �Դϴ�.\n");
    pause();

    printf("lo �������̽��� ���, loop back�� ���ڷ�\n");
    printf("�ڱ� �ڽŰ� ����ϱ� ���� ���� �������̽��Դϴ�.\n");
    pause();

    printf("flags�� �������̽��� ���¸� ���ϸ�,\n");
    printf("mtu�� ��Ʈ��ũ �������̽��� �ִ� ���� �����Դϴ�.\n");
    pause();
    
    printf("inet�� ��Ʈ��ũ �������̽��� �Ҵ�� ������ �ּ�(ipv4)�� �ǹ��ϸ�,\n");
    printf("inet6�� ��Ʈ��ũ �������̽��� �Ҵ�� ipv6 �ּҸ� �ǹ��մϴ�.\n");
    printf("�Ϲ������� '���� ������'�� �θ��� �ּҴ� ipv4 ������ inet �ּ��Դϴ�.\n");
    pause();

    printf("netmask�� ���� �����Ͽ� ��Ʈ��ũ�� �Ҵ��� �� �ִ� ������ �ּ��� �ִ� ���� �� �ϸ�,\n");
    printf("brodcast�� ��Ʈ��ũ�� ���ϴ� ��� ȣ��Ʈ���� �����͸� ���� �� �ִ� �ּҸ� �� �մϴ�.\n");
    printf("ether�� ��Ʈ��ũ �������̽��� �ϵ���� �ּ��̸�, �ٸ� ���δ� ��(MAC) �ּҶ�� �θ��ϴ�.\n");
    pause();

    printf("ifconfig ��ɾ ����� Ư�� �������̽��� ��Ȱ��ȭ, Ȱ��ȭ �� ���� �ִµ�,\n");
    printf("'ifconfig [�������̽� �̸�] up/down' ���� ����մϴ�.\n");
    pause();

    printf("��Ȱ��ȭ�� �������̽��� �ܼ� 'ifconfig' ��ɾ�δ� ��Ÿ���� ������,\n");
    printf("-a �ɼ��� �ָ� ��Ȱ��ȭ�� �������̽����� ��� �� �� �ֽ��ϴ�.\n");
    pause();

    printf("���ϴ� �������̽��� ������ ���� �ʹٸ�\n");
    printf("'ifconfig [�������̽� �̸�]'���� �����մϴ�.\n");
    pause();

    training("ifconfig lo","ifconfig ��ɾ �̿��� lo �������̽��� ������ ����غ�����.");
    // Ư�� �������̽� ������ ����ϵ��� �ǽ�

    printf("�� ��Ʈ��ũ �������̽��� �Ҵ�� ������ �ٲٰ� ���� ���� �Ʒ��� ���� �Է��ϸ� �˴ϴ�.\n");
    printf("IP �ּ� ����        : ifconfig [�������̽� �̸�] [IP]\n");
    printf("netmask �ּ� ����   : ifconfig [�������̽� �̸�] netmask [IP]\n");
    printf("brodcast �ּ� ����  : ifconfig [�������̽� �̸�] brodcast [IP]\n");
    printf("���ּ� ����         : ifconfig [�������̽� �̸�] hw ether [IP]\n");
    printf("������ �ٲ� ���� �׻� �����ؾ� �ϸ�, �ظ��ؼ� �Ժη� ������ �ٲ��� �ʴ� ���� ��õ�帳�ϴ�.\n");
    pause();

    printf("����ϼ̽��ϴ�!\n");
}