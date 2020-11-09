#include "func.h"

void training_netstat(void)
{
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("netstat ��ɾ�� ��Ʈ��ũ ���� ������ �����ִ� ��ɾ��Դϴ�.\n");
    next_line();

    printf("�ɼ��� 'netstat -[�ɼ�]'�� ���� ����ϸ�, �ɼ��� �Ʒ��� �����ϴ�.\n");
    printf("    a : ��� ������ �����ݴϴ�.\n");
    printf("    l : ���� ������ ����(listen)�� �����ݴϴ�.\n");
    printf("    t : tcp ���Ӹ� �����ݴϴ�.\n");
    printf("    u : udp ���Ӹ� �����ݴϴ�.\n");
    printf("    p : �ش� ���������� ����ϴ� ProcessID(=PID)�� �����ݴϴ�.\n");
    printf("    n : �ּ� ������ ������, ��Ʈ �������� ����մϴ�.\n");
    printf("    c : 1�� ������ �簻���մϴ�.\n");
    next_line();

    printf("�� �߿��� ���� ����ϴ� �ɼ� ������ �Ʒ��� �����ϴ�.\n");
    printf("    'netstat -nap'                    : ������ ��ٸ��� ���α׷��� �����ݴϴ�.\n");
    printf("    'netstat -anp | grep [��Ʈ��ȣ]'    : Ư�� ��Ʈ�� � ���α׷����� ��� �� ���� Ȯ���մϴ�.\n");
    printf("    'netstat -nlpt'                   : TCP Listening ������ ���α׷��� �����ݴϴ�.\n");
    next_line();

    printf("[�ǽ�] 80�� ��Ʈ�� � ���α׷����� ��� ������ Ȯ���ϴ� ��ɾ �Է��غ�����.\n");
    fake_run_command("netstat -anp | grep 80");
        printf("Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name\n");
        printf("tcp        0      0 10.0.1.2:12345          1.1.1.1:80              ESTABLISHED 1234/TEST\n");
        printf("\n");
        next_line();

    printf("Proto�� ���������� ������ �ǹ��ϸ�, �ַ� tcp, udp ���� �ֽ��ϴ�.\n");
    printf("Recv-Q�� Send-Q�� ���۽ŵ� ��Ŷ �߿��� ���� ó������ ���� ����Ʈ ���� ���մϴ�.\n");
    printf("Local Address�� ������ ���� �����ǿ� ��Ʈ�� �ǹ��ϸ�,\n");
    printf("Foreign Address�� ������ �����ǿ� ��Ʈ�� �ǹ��մϴ�.\n");
    printf("State�� �ش� ������ ���� ���¸� �ǹ��մϴ�.\n");
    printf("PID/Program name�� �ش� ������ ����ϰ� �ִ� ���α׷� �̸�, ���μ��� ���� ��ȣ�� ���մϴ�.\n");
    next_line();

    printf("State �� �� �ٽ����� ����鸸 �˾ƺ��ڽ��ϴ�.\n");
    printf("    ESTABLISHED : ������ �ξ��� ����\n");
    printf("    SYN-SENT    : ������ ��û�� ���� \n");
    printf("    SYN-RECV    : ���� ��û�� ������ ����\n");
    printf("    TIME-WAIT   : �������� �Ŀ� �ѵ��� �����ϰ� �ִ� ����\n");
    printf("    CLOSED      : ������ ������� �ʴ� ����\n");
    printf("    LISTEN      : ������ ���ο� ������ ��ٸ��� ����\n");
    printf("    TIME_WAIT   : ������ ����Ǿ����� ��а� ������ ���� ���� ����, �ð��� ������ �����\n");
    printf("    UNKNOWN	    : ������ ���¸� �� �� ����\n");
    next_line();

    printf("����ϼ̽��ϴ�!\n");
}