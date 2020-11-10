#include "func.h"

void training_shutdown(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("shutdown ��ɾ�� �ý����� �����ϰų� ����� �ϴ� ��ɾ��Դϴ�.\n");
    next_line();

    printf("[�ý��� ���� �ɼ�]\n");
    printf("shutdown -h now : ��� �ý��� ����\n");
    printf("shutdown -h [����] : [����] �� �� �ý��� ����\n");
    printf("shutdown -h [hh:mm] : [hh:mm] �ð��� �ý��� ���� (ex. 12:00)\n");
    next_line();

    printf("[�ǽ�] shutdown ��ɾ ����Ͽ� ��� �ý����� ����ǰ� �غ�����.\n (���� �ݿ������� �ʽ��ϴ�.)\n");
    fake_run_command("shutdown -h now");
    next_line();
    // �ý��� ��� ���� �ǽ�

    printf("�ý��� ������� 'shutdown -r [��� �ɼ�]' �� ���� ����ϸ�,\n");
    printf("�ý��� ���� ����� 'shutdown -P [��� �ɼ�]'�� �Է��ϸ� �˴ϴ�.\n");
    printf("[��� �ɼ�]�� �ý��� ����� �����մϴ�.\n");
    next_line();

    printf("[�ǽ�] shutdown ��ɾ ����Ͽ� 5�� �� �ý����� ����� �ǰ� �غ�����.\n (���� �ݿ������� �ʽ��ϴ�.)\n");
    fake_run_command("shutdown -r 5");
    next_line();
    // �ý��� ���� ����� �ǽ�

    printf("shutdown ���� ��Ҵ� 'shutdown -c'�� �Է��ϸ� �˴ϴ�.\n");
    printf("[�ǽ�] shutdown ���� ����� ��� �غ�����.\n (���� �ݿ������� �ʽ��ϴ�.)\n");
    fake_run_command("shutdown -c");
    next_line();
    // ���� ��� �ǽ�

    printf("����ϰ� �ý��� ���Ḧ �����ϴ� ��ɾ�δ� 'init', 'poweroff', 'halt' �� ������,\n");
    printf("�ý��� ������� �����ϴ� ��ɾ�δ� 'init', 'reboot'�� �ֽ��ϴ�.\n");
    next_line();

    delete_defdir();
    printf("����ϼ̽��ϴ�!\n");
}