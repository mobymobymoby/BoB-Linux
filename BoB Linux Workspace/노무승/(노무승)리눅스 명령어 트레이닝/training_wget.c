#include "func.h"

void file_check(){ 
    int Result = access("./index.html", 0 ); // unistd.h
    if (Result == 0) remove("./index.html"); // stdio.h
} // ���� ���� Ȯ�� ��, ����� ����

void training_wget(void)
{
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("wget ��ɾ�� �� �� �ִ� ������ �ٿ�޴� ��ɾ��̸�,\n");
    printf("�����Ǵ� ���������� HTTP, HTTPS, FTP�� �ֽ��ϴ�.\n");
    next_line();

    printf("�⺻������ �� �� �ִ� ������ �ٿ���� ����\n");
    printf("'wget [URL ��ũ]'�� ���� ����մϴ�.\n");
    next_line();

    create_defdir();
    file_check();
    printf("[�ǽ�] ���̹�(https://www.naver.com)�� �� ������ ������ �ٿ�޾ƺ�����.\n");
    run_command("wget https://www.naver.com");
    delete_defdir();
    // Ʈ���̴� ����

    printf("[��Ÿ ������ �ɼǵ�]\n");
    printf("wget -c [URL] : ���� �̾�ޱ�\n");
    printf("wget -0 [URL] : �Ķ���� ������ ��ũ���� ���� �ٿ�ε�\n");
    printf("wget -r [URL] : ���͸� ������ ������ä �ٿ�ε�\n");
    printf("wget -nd -r --accept=[Ȯ����] [URL] : Ư�� Ȯ���� ���ϸ� �ٿ�ε�\n");
    printf("wget -nd -r --reject=[Ȯ����] [URL] : Ư�� Ȯ���� ���ϸ� ���� �ٿ�ε�\n");
    printf("�̿� ���� �ɼ��� ����ϸ� ���� �����ϰ� Ȱ���� �� �ֽ��ϴ�.\n");
    next_line();
    printf("����ϼ̽��ϴ�!\n");
}
