#include "func.h"

void training_netstat(void)
{
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("netstat 명령어는 네트워크 접속 정보를 보여주는 명령어입니다.\n");
    next_line();

    printf("옵션은 'netstat -[옵션]'과 같이 사용하며, 옵션은 아래와 같습니다.\n");
    printf("    a : 모든 연결을 보여줍니다.\n");
    printf("    l : 연결 가능한 상태(listen)만 보여줍니다.\n");
    printf("    t : tcp 접속만 보여줍니다.\n");
    printf("    u : udp 접속만 보여줍니다.\n");
    printf("    p : 해당 프로토콜을 사용하는 ProcessID(=PID)를 보여줍니다.\n");
    printf("    n : 주소 형식을 아이피, 포트 형식으로 출력합니다.\n");
    printf("    c : 1초 단위로 재갱신합니다.\n");
    next_line();

    printf("그 중에서 자주 사용하는 옵션 모음은 아래와 같습니다.\n");
    printf("    'netstat -nap'                    : 연결을 기다리는 프로그램을 보여줍니다.\n");
    printf("    'netstat -anp | grep [포트번호]'    : 특정 포트를 어떤 프로그램에서 사용 중 인지 확인합니다.\n");
    printf("    'netstat -nlpt'                   : TCP Listening 상태의 프로그램을 보여줍니다.\n");
    next_line();

    printf("[실습] 80번 포트를 어떤 프로그램에서 사용 중인지 확인하는 명령어를 입력해보세요.\n");
    fake_run_command("netstat -anp | grep 80");
        printf("Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name\n");
        printf("tcp        0      0 10.0.1.2:12345          1.1.1.1:80              ESTABLISHED 1234/TEST\n");
        printf("\n");
        next_line();

    printf("Proto는 프로토콜의 종류를 의미하며, 주로 tcp, udp 등이 있습니다.\n");
    printf("Recv-Q와 Send-Q는 수송신된 패킷 중에서 아직 처리되지 않은 바이트 수를 말합니다.\n");
    printf("Local Address는 본인의 로컬 아이피와 포트를 의미하며,\n");
    printf("Foreign Address는 상대방의 아이피와 포트를 의미합니다.\n");
    printf("State는 해당 소켓의 연결 상태를 의미합니다.\n");
    printf("PID/Program name는 해당 소켓을 사용하고 있는 프로그램 이름, 프로세스 고유 번호를 말합니다.\n");
    next_line();

    printf("State 값 중 핵심적인 내용들만 알아보겠습니다.\n");
    printf("    ESTABLISHED : 연결이 맺어진 상태\n");
    printf("    SYN-SENT    : 연결을 요청한 상태 \n");
    printf("    SYN-RECV    : 연결 요청을 수신한 상태\n");
    printf("    TIME-WAIT   : 연결종료 후에 한동안 유지하고 있는 상태\n");
    printf("    CLOSED      : 소켓을 사용하지 않는 상태\n");
    printf("    LISTEN      : 소켓이 새로운 연결을 기다리는 상태\n");
    printf("    TIME_WAIT   : 연결은 종결되었지만 당분간 소켓을 열어 놓은 상태, 시간이 지나면 사라짐\n");
    printf("    UNKNOWN	    : 소켓의 상태를 알 수 없음\n");
    next_line();

    printf("고생하셨습니다!\n");
}