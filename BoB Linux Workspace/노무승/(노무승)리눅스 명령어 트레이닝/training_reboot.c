#include "func.h"

void training_reboot(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("reboot ��ɾ�� �ý����� ������ϴ� ��ɾ��Դϴ�.\n");
    printf("'-f �ɼ��� �־� ���� ������� �����մϴ�.\n");
    next_line();

    printf("[�ǽ�] reboot ��ɾ ����Ͽ� �ý����� '���� �����'�غ�����.\n(���� ��������� �ʽ��ϴ�.)\n");
    fake_run_command("reboot -f");
    next_line();
    
    printf("����ϰ� �ý��� ������� �����ϴ� ��ɾ�δ� 'shutdown', 'init'�� ������,\n");
    printf("�ý��� ���Ḧ �����ϴ� ��ɾ�δ� 'shutdown', 'init', 'halt', 'poweroff' �� �ֽ��ϴ�.\n");
    next_line();

    delete_defdir();
    printf("����ϼ̽��ϴ�!\n");
}