#include "func.h"

void training_runlevel(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("runlevel ��ɾ�� ������(RunLevel)�� Ȯ���ϴ� ��ɾ��Դϴ�.\n");
    printf("�������� ���� ������ init ��ɾ� Ʈ���̴��� �����Ͻø� �˴ϴ�.\n");
    next_line();
    
    printf("[�ǽ�] runlevel ��ɾ �Է��غ�����.\n");
    fake_run_command("runlevel");
    next_line();

    printf("���ʿ� ǥ��� ���� ������ �������̰�, \n");
    printf("�����ʿ� ǥ��� ���� ���� �������Դϴ�.\n");
    next_line();

    delete_defdir();
    printf("����ϼ̽��ϴ�!\n");
}