#include "func.h"

void training_nano(void)
{
    create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("nano ��ɾ�� nano �ؽ�Ʈ �����⸦ �ҷ����� ��ɾ��Դϴ�.\n");
    next_line();
    printf("�ٸ� ������ �ؽ�Ʈ ������δ� vi�� vim ���� ������,\n");
    printf("nano �����ʹ� �� �߿��� ����ϱ� ������ �� ���մϴ�.\n");
    next_line();

    printf("'nano [���� ��]' �� ���� �Է��ϸ� Ư�� ������ nano ������� �� �� �ֽ��ϴ�.\n");
    printf("[�ǽ�] test ������ nano ������� �������.\n");
    fake_run_command("nano test");
        printf("  GNU nano 4.8                          test                                    \n");
        printf("TEST FILE\n");
        printf("                                  [ New File ]\n");
        printf("^G Get Help  ^O Write Out ^W Where Is  ^K Cut Text  ^J Justify   ^C Cur Pos\n");
        printf("^X Exit      ^R Read File ^\ Replace   ^U Paste Text^T To Spell  ^_ Go To Line\n");
        next_line();
        
    printf("�⺻������ ����Ű�� ����, ���� �̵��� �����մϴ�.\n");
    next_line();

    printf("������ ���� ����ϴ� �ɼǵ��Դϴ�.\n");
    printf("    nano -B [���ϸ�] : ���� ���� ������ '[���ϸ�]~'�̸����� ����˴ϴ�.\n");
    printf("    nano -m [���ϸ�] : ���콺�� ����մϴ�.\n");
    printf("    nano +[����] [���ϸ�] : ������ ���ڸ��� Ư�� �������� �̵��մϴ�.\n");
    next_line();

    printf("nano ������ �������� �پ��� ��ɵ��� �����ϴµ�, ������ �����ϴ�.\n");
    printf("\n");
    printf("[�ΰ� ���]\n");
    printf("    ctrl+g (F1) : ���� ǥ��\n");
    printf("    ctrl+x (F2) : nano ����\n");
    printf("    ctrl+o (F3) : ���� ����\n");
    next_line();

    printf("[������ ���]\n");
    printf("    ctrl+w (F6) : ���� �˻�\n");
    printf("    ctrl+\\ : ���� �˻� �� ����\n");
    printf("    ctrl+k (F9) : ���� �� �߶󳻱�\n");
    printf("    ctrl+u : ������ �ڸ� ���� �ٿ��ֱ�\n");
    printf("    alt+] : ���� ��ȣ�� ��Ī�Ǵ� ��ȣ ã��\n");
    printf("            (�ڵ��� �����ϰ� ���� �� ����)\n");
    next_line();
    
    printf("[���� �̵�]\n");
    printf("    ctrl+y (F7) : ���� ȭ������ �̵�\n");
    printf("    ctrl+v (F8) : ���� ȭ������ �̵�\n");
    printf("    ctrl+a : ���� ������ ���� ��ġ�� �̵�\n");
    printf("    ctrl+e : ���� ������ �� ��ġ�� �̵�\n");
    printf("    alt+( : ���� ������ �������� �̵�\n");
    printf("    alt+) : ���� ������ ������ �̵�\n");
    printf("    alt+\\ : ������ ù �������� �̵�\n");
    printf("    alt+/ : ������ ������ �������� �̵�\n");
    next_line();

    delete_defdir();
    printf("����ϼ̽��ϴ�!\n");
}