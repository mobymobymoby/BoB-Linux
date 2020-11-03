#include <stdio.h>
#include <unistd.h> // sleep, getcwd �Լ�
#include <string.h> // strncmp �Լ� 
// #include <stdlib.h> // system �Լ�

int training(char test[],char guide[]){
    char cmd[31]={}; // �ִ� �ǽ� ��ɾ� ���� ����
    char d_buf[30]={};
    int num=0,num2=0;

    while(1) {
        if (test[num]==0) {
            break;
        } else {
            ++num;
        }
    } // �ǽ� ��ɾ� ���� ����

    if ((num <= 1) || (num >= 30)) return -1;
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
    printf("cd ��ɾ�� �۾� ���͸��� �ű� �� ����ϴ� ��ɾ��Դϴ�.\n");
    pause();

    rmdir("/home/user/tr"); // (��ɾ� Ʈ���̴� ���� �Լ��� ���� ó���ϸ� ���� ��)
    mkdir("/home/user/tr"); //
    chdir("/home/user/tr"); //

    mkdir("/home/user/tr/test1");
    mkdir("/home/user/tr/test2");
    // �׽�Ʈ ���� ����

    printf("'cd [���͸� ���]' �������� ����ϸ�,\n");
    printf("���͸� ��θ� ������ ��, ���� ��ο� ��� ��θ� �����Ͽ� ����մϴ�.\n");
    pause();

    printf("���� ��δ� �ֻ��� ���͸����� ������ ������ ��θ� �ǹ��մϴ�.\n");
    printf("(ex. /etc/systemd)\n");
    printf("�� ���� /�� ��Ʈ(�ֻ���) ���͸��� �ǹ��ϸ�,\n");
    printf("'cd /' �Է½�, ��Ʈ ���͸��� �̵��ϰ� �˴ϴ�.\n");
    pause();

    training("cd /home/user/tr/test1","cd ��ɾ ����� /home/user/tr/test1 ������ �̵��غ�����.\n(���� : cd [���͸� ���])");
    chdir("/home/user/tr/test1");
    // ���� ��� Ʈ���̴�

    printf("��� ��δ� ������� ��η�, �Ʒ��� ���� ���� ����� �ֽ��ϴ�.\n");
    printf(". : ���� �۾� ���͸��� �ǹ�\n");
    printf(".. : ���� �۾� ������ ���� ���͸��� �ǹ�\n");
    pause();

    printf("���� ��� './1234/' �� ���� �۾� ���͸� ������ 1234 ���͸��� �ǹ��ϰ�,\n");
    printf("    (�۾� ���͸��� /etc �� ��, ./1234 �� /etc/1234�� ����.)\n");
    printf("'../1234/' �� ���� �۾� ���͸� ������ 1234 ���͸��� �ǹ��մϴ�.\n");
    printf("    (�۾� ���͸��� /etc �� ��, ../1234 �� /1234�� ����.)\n");
    pause();

    training("cd ../test2", "���� ��θ� �̿��� ���� ���͸��� test2 ���͸��� �̵��غ�����.\n(���� : cd [���͸� ���])");
    chdir("cd ../test2");
    // ��� ��� Ʈ���̴� 

    printf("���� ���� �۾� ���͸��� ���� ���͸��� �̵��ϰ� �ʹٸ� 'cd ..' �� �Է��ϸ� �˴ϴ�.\n");
    training("cd ..", "'cd ..'�� �Է��� ���� ���͸��� �̵��غ�����.\n(���� : cd [���͸� ���])");
    chdir("cd ..");
    // ���� ��� Ʈ���̴�

    printf("�̵��ϱ� ������ ���͸��� �ǵ��ư��� ���ؼ��� 'cd -'�� �Է��ϸ� �˴ϴ�.\n");    
    training("cd -", "'cd -'�� �Է��� ������ ���͸��� �ǵ��ư� ������.");
    chdir("cd -");
    // ���� ��� Ʈ���̴�

    rmdir("/home/user/tr");     // (��ɾ� Ʈ���̴� ���� �Լ��� ó���ϸ� ���� ��)
    printf("����ϼ̽��ϴ�!\n"); //
}