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
    printf("kill ��ɾ�� PID�� �̿��� ���μ����� �����ϴ� ��ɾ��Դϴ�.\n");
    printf("PID�� ProcessID�� ���Ӹ��̸�, ���μ����� ���� ��ȣ�� �� �մϴ�.\n");
    pause();

    printf("�ñ׳��� ���� �پ��� ���� �ɼ��� �������� �� ������,\n");
    printf("�ñ׳��� �������� ������ �ڵ����� TERM(15��) �ñ׳η� �����˴ϴ�.\n");
    printf("(ex. 'kill [PID]' -> 15�� TERM �ñ׳� ����)\n");  
    printf("��Ÿ ���� �ñ׳� �ɼ��� ���� ����� 'kill -l' ��ɾ �Է��ϸ� �˴ϴ�.\n");
    pause();

    printf("[�˾Ƶθ� ���� �ñ׳� �ɼ�]\n");
    printf("TERM (15��) = �⺻ ����\n");
    printf("KILL (9��)  = ���� ����\n");
    pause();

    printf("Ư�� ���� ����(9��)�� ������ �������� ����ؾ� �մϴ�.\n");
    printf("���μ����� ���� �����ϰ� �Ǹ� �����Ͱ� ���ǵ� �� �ֱ� �����Դϴ�.\n");
    pause();

    printf("�ñ׳��� �����ϴ� ����� 'kill -[�ñ׳� ��ȣ] [PID]'�� �����ϴ�.\n");
    training("kill -9 1234","kill ��ɾ�� PID 1234 ���μ����� '���� ����' �Ͻʽÿ�.\n(�ñ׳� ���)");
    training("kill -15 5678","kill ��ɾ�� PID 5678 ���μ����� '���� ����' �Ͻʽÿ�.\n(�ñ׳� ���)");
    training("kill 2020","kill ��ɾ�� PID 2020 ���μ����� '���� ����' �Ͻʽÿ�.\n(�ñ׳� �̻��)");
    // ��ɾ� �ǽ�

    printf("PID�� Ȯ���ϴ� ������δ� 'ps' ��ɾ 'top' ��ɾ ����Ͻø� �˴ϴ�.\n");
    pause();
    printf("����ϼ̽��ϴ�!\n");
}