#include "func.h"

void training_ls(void)
{
    create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("ls ���ɾ�� �����̳� ������ ����, ������ �����ִ� ���ɾ��Դϴ�.\n");
    next_line();

    system("touch 1234.txt");
    system("touch 5678.txt");
    system("chmod 777 1234.txt");
    system("chmod 764 5678.txt");
    // �׽�Ʈ ���� ����

    printf("[�ǽ�] ls ���ɾ �Է��غ�����\n");
    run_command("ls");
        printf("�ܼ��� ls ���ɾ �Է��ϸ� dir ���ɾ�� ���� �� �ٸ� ���� ����\n");
        printf("���� �۾� ���͸��� �ִ� ���ϰ� ������ �����ݴϴ�.\n");
        next_line();
        
    printf("[�ǽ�] ls -l ���ɾ �Է��غ�����\n");
    run_command("ls -l");
    next_line();
        printf("-l �ɼ��� �ָ� ���� ���� ����Ʈ ������ \n");
        printf("���� �۾� ���͸��� �ִ� ���ϰ� ������ �� �� �ֽ��ϴ�.\n");
        next_line();
        printf("���� ls -l�� ���ɾ ���� ���� ��� ����� ������ ���ٰ� �����غ��ô�.\n");
        printf("drwxrw-r-- 1 kim bob 1024 2020-10-10 test\n");
        printf("ù ��° 'drwxrw-r--'�� ������ ��Ÿ����, �� ��° '1'�� ��ũ�� ����,\n");
        printf("�� ��° 'kim'�� ������ �̸�(UID), �� ��° 'bob'�� �׷� �̸�(GID)�Դϴ�.\n");
        printf("�ټ� ��° '1024'�� ���� ũ��, ���� ��° '2020-10-10'�� ���� ���� ���� ��¥,\n");
        printf("�ϰ� ��°�� ���� �̸��Դϴ�.\n");
        next_line();
        printf("���⼭ 10�ڸ��� ���ڷ� ������ ��Ÿ�� ���� �� ���� 'drwxrw-r--'�Դϴ�.\n");
        printf("���� ��� 'drwxrw-r--'�̶�� 10�ڸ� ������ ������ �ִٸ�, ũ�� 4�κ����� ������ ������ �� �ֽ��ϴ�.\n");
        printf("���� �� ���� 'd'�� directory��� �ǹ��Դϴ�.\n");
        printf("���� �ش� �κ��� '-'�� �Ǿ� �ִٸ�, �װ��� '����'�̶�� ���� ���մϴ�.\n");
        printf("�������� ������ 9�ڸ��� 'rwx' 'rw-' 'r--'�� ���� 3�ڸ��� ��� ������ �� �ֽ��ϴ�.\n");
        next_line();
        printf("�տ��� ����� ���ɾ��� 'pwd'�� ��� ����� UID�� ���ٸ�, ���� ����ڴ� �ش� ������ �����ڰ� �˴ϴ�.\n");
        printf("������ ���� �ʴٸ� '�׷�' �����̳� '��ü' ������ ����޽��ϴ�.\n");
        printf("�ڽ��� �׷�� GID�� ��ġ �Ѵٸ�, �׷� ������ ����ް� �ǰ�, �׷��� �ʴٸ� ��ü ������ ����ް� �Ǵ� ���Դϴ�.\n");
        printf("���� UID�� GID�� ��� ��ġ�Ѵٸ�, UID�� �켱 ���� �ްԵ˴ϴ�.\n");
        next_line();
        printf("�׷� �ٽ� ���� ���÷� ���ƿͼ�, ���� 'rwx' �κ��� '�����(������,owner)' �����Դϴ�.\n");
        printf("�տ��� ���캸�Ҵ� pwd�� ���� ����ڸ� �� �� �־����ϴ�.\n");
        printf("'r'�� �б�, 'w'�� ����, 'x'�� ���� ������ �ǹ��ϸ�, ���� 'r-x'�� ���� �Ǿ� �ִٸ� �б�� ���� ������ ������,\n");
        printf("���� ���� �ڸ��� '-'�� ������ֱ� ������ ���� ������ ���ٴ� ���� �ǹ��մϴ�.\n");
        next_line();
        printf("���� �κ��� 'rw-' �κ��� '�׷�(group)' ���� �Դϴ�.\n");
        printf("���� ����ڰ� �����ִ� �׷��� �ش� �����̳� ���丮�� GID�� ���ٸ�\n");
        printf("�б� ���Ѱ� ���� ������ �ְ�, ���� ������ ������ �ǹ��մϴ�.\n");
        next_line();
        printf("������ �κ��� 'r--' �κ��� '��ü(other)' �����Դϴ�.\n");
        printf("�б� ���Ѹ� �ְ� ���� �����̳� ���� ������ ������ �ǹ��մϴ�.\n");
        next_line();
        printf("���ݱ����� 10�ڸ� ���ڷ� ������ ��Ÿ��������, 3�ڸ��� ���ڷ� ��Ÿ�� ���� �ֽ��ϴ�.\n");
        printf("�� �ڸ��� ���ڷ� ��Ÿ���� ��İ� ���� ������, �׷�, ��ü �������� �����ϴ�.\n");
        printf("(����, ���丮�� ��Ÿ���ִ� �� �� �ڸ��� ������ ���̶�� �����ϸ� �˴ϴ�.)\n");
        next_line();
        printf("�б� ������ ���� '4', ���� ������ ���� '2', ���� ������ ���� '1'�� ����ϰ�\n");
        printf("�� ������ ���� ���� �� �ڸ��� ǥ���մϴ�.\n");
        next_line();
        printf("���� '764'�̶�� ������ �ִٸ�, �� ���� '7'�� ������ ���� �κ��̸�, 4+2+1�̹Ƿ�,\n");
        printf("�б�, ����, ���� ������ ��� ������ �ǹ��մϴ�. �� ���ڷ� ǥ�õ� 'rwx' ���Ѱ� �����ϴ�.\n");
        printf("�������� '6'�� �׷� ���� �κ��̸�, 4+2+0�̹Ƿ�, �б� ���Ѱ� ���� ������ ������,\n");
        printf("��������� '1'�� �ƴ�, '0'�̹Ƿ� ��������� �����ϴ�.\n");
        printf("���������� '4'�� ��ü ���� �κ��̸�, 4+0+0�̹Ƿ� �б� ���Ѹ� �ִٰ� �� �� �ֽ��ϴ�.\n");
        next_line();
        printf("�̷��� ���� �ý����� ���������� �߿��� ����������,\n");
        printf("�������� ����ϸ鼭 ������ �ͼ������� �ǹǷ� ������ �ܿ�ų� �� �ʿ�� �����ϴ�.\n");
        next_line();
    printf("[�ǽ�] ls -al ���ɾ �Է��غ�����\n(-a �ɼ��� �߰��� �ָ� ���� ���ϱ��� ��� �� �� �ֽ��ϴ�.)\n");
    run_command("ls -al");
    next_line();
    printf("[�ǽ�] ls -alh ���ɾ �Է��غ�����\n(-h �ɼ��� �߰��� �ָ� ���� ũ�⸦ K, M, G ������ �� �� �ֽ��ϴ�.)\n");
    run_command("ls -alh");
    next_line();
    
    delete_defdir();
    printf("�����ϼ̽��ϴ�!\n");
}