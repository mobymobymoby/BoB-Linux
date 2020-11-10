#include "func.h"

void training_halt(void)
{
    create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("halt ��ɾ�� �ý����� �����ϴ� ��ɾ��Դϴ�.\n");
    next_line();

    printf("�����ؾ� �� ���� �ý��۸� ����ǰ�, �ý����� ������ ������ �ʴ´ٴ� ���Դϴ�.\n");
    printf("��ü ��ɾ�� 'init', 'shutdown' ��ɾ� ����� ����帳�ϴ�.\n");
    next_line();

    printf("[�ǽ�] halt ��ɾ ����Ͽ� �ý����� �����غ�����.\n(���� ��������� �ʽ��ϴ�.)\n");
    fake_run_command("halt");
    next_line();

    printf("����ϰ� �ý��� ���Ḧ �����ϴ� ��ɾ�δ� 'shutdown', 'init', 'poweroff' �� ������,\n");
    printf("�ý��� ������� �����ϴ� ��ɾ�δ� 'shutdown', 'init', 'reboot'�� �ֽ��ϴ�.\n");
    next_line();
    
    delete_defdir();
    printf("����ϼ̽��ϴ�!\n");
}