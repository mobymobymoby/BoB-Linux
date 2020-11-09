#include "func.h"

void training_init(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("init ��ɾ�� ������(RunLevel)�� �����ϴ� ��ɾ��Դϴ�.\n");
    next_line();

    printf("[�������̶�?]\n");
    printf("�������� ���� ���� �ִ� 8���� �������� �����ϸ�,\n");
    printf("�Ϲ������� 0���� 6������ �� 7���� �������� ����մϴ�.\n");
    next_line();

    printf("[�� ������ �� �ǹ�]\n");
    printf("RunLevel 0 (Power Off) : �ý��� ���� ����Դϴ�.\n");
    printf("	�ش� �������� �ٲٸ� �ý����� ����˴ϴ�.\n");
    next_line();

    printf("RunLevel 1 (Resuce): �ؽ�Ʈ(CLI) ���� ����� ����Դϴ�.\n");
    printf("	�ý��� ������ ���� ���Ǹ�, ������ ���� ����մϴ�.\n");
    next_line();
    
    printf("RunLevel 2 (Multi-User): ��Ʈ��ũ�� ������� �ʴ� �ؽ�Ʈ(CLI) ���� ����� ����Դϴ�.\n");
    printf("	����� ������� ������, ȣȯ���� ���� ������ 3�� �����ϰ� ��޵˴ϴ�.\n");
    next_line();

    printf("RunLevel 3 (Full Multi-User): �ؽ�Ʈ(CLI) ���� ����� ����Դϴ�.\n");
    printf("	�Ϲ������� �ؽ�Ʈ ���� ����� �θ��� �ش� �������� �ǹ��մϴ�.\n");
    next_line();

    printf("RunLevel 4 (Multi-User(unused)): ������� �ʴ� ���� ����� ����Դϴ�.\n");
    printf("	ȣȯ���� ���� ������ 3�� �����ϰ� ��޵˴ϴ�.\n");
    next_line();

    printf("RunLevel 5 (Graphical): �׷���(GUI) ���� ����� ����Դϴ�.\n");
    printf("	�⺻������ ������ 3�� �����ϸ�, �׷����� �����Ѵٴ� ������ ���̰� �ֽ��ϴ�.\n");
    next_line();

    printf("RunLevel 6 (Reboot): �ý��� ����� ����Դϴ�.\n");
    printf("	�ش� �������� �ٲٸ� �ý����� ����õ˴ϴ�.\n");
    next_line();

    printf("[�ֿ� ������ ����]\n");
    printf("0 (�ý��� ����), 6 (�ý��� �����)\n");
    printf("3 (CLI ���� �����), 5 (GUI ���� �����)\n");
    next_line();
    
    printf("[�ǽ�] �������� 0���� �ٲ㺸����. (���� �ݿ������� �ʽ��ϴ�.)\n");
    fake_run_command("init 0");
    printf("�� �ϼ̽��ϴ�! �����ε� �̷� ������ �������� �ٲٸ� �˴ϴ�.\n");
    next_line();
    
    printf("���� �������� Ȯ���ϴ� ������� 'runlevel' ��ɾ�� 'who -r' ��ɾ ������,\n");
    printf("�ý����� �����ϴ� ��ɾ�δ� 'shutdown', 'half', 'reboot' ��ɾ �ֽ��ϴ�.\n");
    next_line();

    delete_defdir();
    printf("����ϼ̽��ϴ�!");
}