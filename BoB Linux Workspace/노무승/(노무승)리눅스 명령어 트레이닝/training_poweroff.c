#include "func.h"

void training_poweroff(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("poweroff ��ɾ�� �ý����� �����ϴ� ��ɾ��Դϴ�.\n");
    next_line();

    printf("poweroff ��ɾ�� �ϵ��ũ�� �޸𸮸� ����ȭ ��Ű�� �ʰ� �ٷ� �����ϱ� ������,\n");
    printf("poweroff ��ɾ�� ������ ������� �ʴ� ���� �����ϴ�.\n");
    next_line();

    printf("��ü ��ɾ�� 'init', 'shutdown' ��ɾ� ����� ����帳�ϴ�.\n");
    next_line();

    printf("[�ǽ�] poweroff ��ɾ ����Ͽ� �ý����� �����غ�����.\n(���� ��������� �ʽ��ϴ�.)\n");
    fake_run_command("poweroff");
    next_line();

    printf("����ϰ� �ý��� ���Ḧ �����ϴ� ��ɾ�δ� 'shutdown', 'init', 'halt' �� ������,\n");
    printf("�ý��� ������� �����ϴ� ��ɾ�δ� 'shutdown', 'init', 'reboot'�� �ֽ��ϴ�.\n");
    next_line();

    delete_defdir();
    printf("����ϼ̽��ϴ�!\n");
}