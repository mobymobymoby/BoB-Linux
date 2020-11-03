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
        printf("\n");
        sleep(2);
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
    printf("fsck ��ɾ�� ������ ���� �ý����� �˻��ϰ� �����ϴ� ��ɾ��Դϴ�.\n");
    pause();

    printf("���� �ý��� �˻� ������ ������ �����ϴ�.\n");
    printf("    �ܰ� 1  : ��ϵ�� ���� ũ�� �˻�\n");
    printf("    �ܰ� 2a : �ߺ��� �̸��� �ִ��� �˻�\n");
    printf("    �ܰ� 2b : ��� �̸� �˻�\n");
    printf("    �ܰ� 3  : ���Ἲ �˻�\n");
    printf("    �ܰ� 4  : ���� �� �˻�\n");
    printf("    �ܰ� 5  : ����Ŭ �׷� �˻�\n");
    pause();

    printf("fsck ����� �ջ�� �����̳� ���͸��� ������ ��,\n");
    printf("/lost+found ���͸����� �۾��� �����ϰ� ������ �Ϸ�Ǹ� ������ϴ�.\n");
    pause();

    printf("fsck ������� �˻��ϰų� ������ ��Ƽ���� ����Ʈ�� �� ���¸� �ȵ˴ϴ�.\n");
    printf("�ݵ�� umount ��ɾ� ������ ����Ʈ�� �����ϰ� �������־�� �մϴ�.\n");
    pause();

    printf("�⺻������ 'fsck [��Ƽ�� ���]' �� ���� �������� ����մϴ�.\n");
    training("fsck /dev/sdb1","fsck ��ɾ�� /dev/sdb1 ��Ƽ���� �˻��غ�����.\n(���� �ݿ������� �ʽ��ϴ�.)");

    printf("�⺻���� ���� �̿ܿ��� �پ��� ��� �ɼ��� �ֽ��ϴ�.\n");
    printf("    -v : ���� ������ �ڼ��ϰ� ������ݴϴ�.\n");
    printf("    -y : ��� ������ �� yes�� �ؼ� �ڵ����� ����, ������ �����մϴ�.\n");
    printf("    -n : ��� ������ �� no�� �ؼ� ���˸� �����մϴ�.\n");
    printf("    -f : ���� �ý��� �̻� ������ ������� ������ ������ �մϴ�.\n");
    pause();

    printf("����ϼ̽��ϴ�!\n");
}