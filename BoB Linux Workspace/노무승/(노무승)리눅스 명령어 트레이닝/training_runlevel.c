#include <stdio.h>
#include <unistd.h> // sleep, getcwd �Լ�
#include <string.h> // strncmp �Լ� 
#include <stdlib.h> // system �Լ�

void training(){
    char cmd[9]={};
    char d_buf[30]={};
    printf("[�ǽ�] runlevel ��ɾ �Է��غ�����.\n");
    getcwd(d_buf, sizeof(d_buf));
	printf("Trainer@BoB:%s$ ", d_buf);
    fgets(cmd,sizeof(cmd),stdin);
    
    if (strncmp(cmd,"runlevel",8)==0){
        system("runlevel");
        fflush(stdin);
    } else {
        training();
    }
}

void pause(){
    getchar();
    fflush(stdin);
}

int main(){
    printf("runlevel ��ɾ�� ������(RunLevel)�� Ȯ���ϴ� ��ɾ��Դϴ�.\n");
    printf("�������� ���� ������ init ��ɾ� Ʈ���̴��� �����Ͻø� �˴ϴ�.\n");
    pause();
    
    training();
    printf("�� �ϼ̽��ϴ�!\n");
    pause();

    printf("���ʿ� ǥ��� ���� ������ �������̰�, \n");
    printf("�����ʿ� ǥ��� ���� ���� �������Դϴ�.\n");
    pause();
    printf("����ϼ̽��ϴ�!\n");
}