#include "func.h"

void training_su(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("su ���ɾ�� ����ڸ� ��ȯ�ϱ� ���� ���ɾ��Դϴ�.\n");
    next_line();

    printf("'su [��ȯ�� ����� �̸�]' �� ���� ����մϴ�.\n");
    printf("�� ���ÿ� ���� ����ϸ� ��ȯ�ϱ� �� ����� ȯ�溯���� ����մϴ�.\n");
    next_line();

    printf("[�ǽ�] su ���ɾ ����� root ����ڷ� ��ȯ�غ�����. (su [��ȯ�� ����� �̸�])\n");
    fake_run_command("su root");
    printf("Password:\n");
    printf("Trainer@BoB:#\n");
    next_line();

    printf("'su - [��ȯ�� ����� �̸�]' �� ���� �߰��� - �� �߰��ϸ�\n");
    printf("�ش� ������� Ȩ ���͸��� �̵��մϴ�.\n");
    printf("�̴� �ش� ��ȯ ��� ������� ȯ�� ������ ����ϴ� ���� �ǹ��մϴ�.\n");
    next_line();

    delete_defdir();
    printf("�����ϼ̽��ϴ�!\n");
}