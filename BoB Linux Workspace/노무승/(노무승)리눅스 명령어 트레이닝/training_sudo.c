#include "func.h"

void training_sudo(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("sudo ��ɾ�� root ������ ȹ���ϱ� ���� ��ɾ��Դϴ�.\n");
    next_line();
    
    printf("root ������ �������� �ֻ��� �������ν�,\n");
    printf("������ �ý��� ��ü�� �ǵ帱 �� �����Ƿ� ��뿡 ���ǰ� �ʿ��մϴ�.\n");
    next_line();
    
    printf("Ư�� ��ɾ root �������� �����ϰ� �ʹٸ�\n");
    printf("'sudo [��ɾ�]'�� �Է��ϸ� �˴ϴ�.\n");
    next_line();

    printf("[�ǽ�] bash ��ɾ root �������� ������Ѻ��ô�.\n");
    fake_run_command("sudo bash");
    next_line();
    // Ʈ���̴� 1

    printf("�Ϲ� �������� root ������ ��ȯ�ϰ� �ʹٸ�\n");
    printf("'sudo -s' ��ɾ �Է��ϸ� �˴ϴ�.\n");
    next_line();

    printf("[�ǽ�] sudo ��ɾ �̿��� �Ϲ� �������� root ������ ��ȯ�غ��ô�.\n");
    fake_run_command("sudo -s");
    printf("[sudo] password for Trainer:\n");
    printf("Trainer@BoB:#\n");
    next_line();
     // Ʈ���̴� 2   

    printf("root ������ �ٲ�� ����� ������ ������\n");
    printf("'$'���� '#'���� �ٲ� ���� �� �� �ֽ��ϴ�.\n");
    next_line();

    printf("sudo ��ɾ�� ���� ��½�, '/etc/sudoers' ������ �����ϸ�\n");
    printf("�ش� ���Ͽ� ��ϵ� ����ڸ� root ���� ����� �����մϴ�.\n");
    printf("��ϵ��� ���� ����ڿ��� root ���� ����� �ϰ� �Ǹ�\n");
    printf("'{�����̸�} is not in the sudoers file.' ��� ���� ������ �߰� �˴ϴ�.\n");
    next_line();

    printf("���� ����� ���� ����ڴ� ������ ���� ��ϵ˴ϴ�.\n");
    printf("{���� �̸�} ALL=(ALL:ALL) ALL\n");
    next_line();

    printf("����� �ٸ� ����ڷ� �����ϴ� ��ɾ�δ� 'su' ��ɾ �ֽ��ϴ�.\n");
    next_line();

    delete_defdir();
    printf("����ϼ̽��ϴ�!\n");
}
