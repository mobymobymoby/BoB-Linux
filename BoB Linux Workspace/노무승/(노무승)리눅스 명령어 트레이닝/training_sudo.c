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
        printf("[sudo] password for Trainer:\n");
        printf("Trainer@BoB:%s#\n", d_buf);;
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
    printf("sudo ��ɾ�� root ������ ȹ���ϱ� ���� ��ɾ��Դϴ�.\n");
    pause();
    
    printf("root ������ �������� �ֻ��� �������ν�,\n");
    printf("������ �ý��� ��ü�� �ǵ帱 �� �����Ƿ� ��뿡 ���ǰ� �ʿ��մϴ�.\n");
    pause();
    
    printf("Ư�� ��ɾ root �������� �����ϰ� �ʹٸ�\n");
    printf("'sudo [��ɾ�]'�� �Է��ϸ� �˴ϴ�.\n");
    pause();

    training("sudo bash","bash ��ɾ root �������� ������Ѻ��ô�.");
    // Ʈ���̴� 1

    printf("�Ϲ� �������� root ������ ��ȯ�ϰ� �ʹٸ�\n");
    printf("'sudo -s' ��ɾ �Է��ϸ� �˴ϴ�.\n");
    pause();

    training("sudo -s","sudo ��ɾ �̿��� �Ϲ� �������� root ������ ��ȯ�غ��ô�.");
     // Ʈ���̴� 2   

    printf("root ������ �ٲ�� ����� ������ ������\n");
    printf("'$'���� '#'���� �ٲ� ���� �� �� �ֽ��ϴ�.\n");
    pause();

    printf("sudo ��ɾ�� ���� ��½�, '/etc/sudoers' ������ �����ϸ�\n");
    printf("�ش� ���Ͽ� ��ϵ� ����ڸ� root ���� ����� �����մϴ�.\n");
    printf("��ϵ��� ���� ����ڿ��� root ���� ����� �ϰ� �Ǹ�\n");
    printf("'{�����̸�} is not in the sudoers file.' ��� ���� ������ �߰� �˴ϴ�.\n");
    pause();

    printf("���� ����� ���� ����ڴ� ������ ���� ��ϵ˴ϴ�.\n");
    printf("{���� �̸�} ALL=(ALL:ALL) ALL\n");
    pause();

    printf("����� �ٸ� ����ڷ� �����ϴ� ��ɾ�δ� 'su' ��ɾ �ֽ��ϴ�.\n");
    pause();
    printf("����ϼ̽��ϴ�!\n");
}
