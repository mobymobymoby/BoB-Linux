#include <stdio.h>
#include <unistd.h> // sleep �Լ�

void training(){
    char cmd[6]={};
    char d_buf[30]={};
    printf("[�ǽ�] init ��ɾ �̿��� �ý����� �����ϵ��� �Ͻʽÿ�.\n");
    printf("        ('init {����}' ��ɾ� �Է��� ���� {����} �������� �ٲ� �� �ֽ��ϴ�.)\n");
    printf("        (���� �ý��ۿ� ��������� �ʽ��ϴ�.)\n"); 
    printf("\n");

    getcwd(d_buf, sizeof(d_buf));
	printf("Trainer@BoB:%s$ ", d_buf);
    fgets(cmd,7,stdin);
    fflush(stdin);
    
    if (strncmp(cmd,"init 0",6)!=0){
        training();
    }
}

void pause(){
    getchar();
    fflush(stdin);
}

int main(){
    printf("init ��ɾ�� ������(RunLevel)�� �����ϴ� ��ɾ��Դϴ�.\n");
    pause();

    printf("[�������̶�?]\n");
    printf("�������� ���� ���� �ִ� 8���� �������� �����ϸ�,\n");
    printf("�Ϲ������� 0���� 6������ �� 7���� �������� ����մϴ�.\n");
    pause();

    printf("[�� ������ �� �ǹ�]\n");
    printf("RunLevel 0 (Power Off) : �ý��� ���� ����Դϴ�.\n");
    printf("	�ش� �������� �ٲٸ� �ý����� ����˴ϴ�.\n");
    pause();

    printf("RunLevel 1 (Resuce): �ؽ�Ʈ(CLI) ���� ����� ����Դϴ�.\n");
    printf("	�ý��� ������ ���� ���Ǹ�, ������ ���� ����մϴ�.\n");
    pause();
    
    printf("RunLevel 2 (Multi-User): ��Ʈ��ũ�� ������� �ʴ� �ؽ�Ʈ(CLI) ���� ����� ����Դϴ�.\n");
    printf("	����� ������� ������, ȣȯ���� ���� ������ 3�� �����ϰ� ��޵˴ϴ�.\n");
    pause();

    printf("RunLevel 3 (Full Multi-User): �ؽ�Ʈ(CLI) ���� ����� ����Դϴ�.\n");
    printf("	�Ϲ������� �ؽ�Ʈ ���� ����� �θ��� �ش� �������� �ǹ��մϴ�.\n");
    pause();

    printf("RunLevel 4 (Multi-User(unused)): ������� �ʴ� ���� ����� ����Դϴ�.\n");
    printf("	ȣȯ���� ���� ������ 3�� �����ϰ� ��޵˴ϴ�.\n");
    pause();

    printf("RunLevel 5 (Graphical): �׷���(GUI) ���� ����� ����Դϴ�.\n");
    printf("	�⺻������ ������ 3�� �����ϸ�, �׷����� �����Ѵٴ� ������ ���̰� �ֽ��ϴ�.\n");
    pause();

    printf("RunLevel 6 (Reboot): �ý��� ����� ����Դϴ�.\n");
    printf("	�ش� �������� �ٲٸ� �ý����� ����õ˴ϴ�.\n");
    pause();

    printf("[�ֿ� ������ ����]\n");
    printf("0 (�ý��� ����), 6 (�ý��� �����)\n");
    printf("3 (CLI ���� �����), 5 (GUI ���� �����)\n");
    pause();
    
    training();
    printf("�� �ϼ̽��ϴ�! �����ε� �̷� ������ �������� �ٲٸ� �˴ϴ�.\n");
    pause();
    
    printf("���� �������� Ȯ���ϴ� ������� 'runlevel' ��ɾ�� 'who -r' ��ɾ ������,\n");
    printf("�ý����� �����ϴ� ��ɾ�δ� 'shutdown', 'half', 'reboot' ��ɾ �ֽ��ϴ�.\n");
    pause();

    printf("����ϼ̽��ϴ�!");
}