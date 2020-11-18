#include "func.h"

void training_kill(void)
{
    create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("이번에 학습할 명령어는 \"kill\" 입니다,\n\n");
    next_line();
    printf("\"kill\" 명령어는 PID를 이용해 프로세스를 종료하는 명령어입니다.\n");
    printf("PID란 Process ID의 줄임말이며, 프로세스의 고유 번호를 의미합니다.\n");
    next_line();

    printf("\"kill\" 명령어의 실행 파일은 \"/usr/bin/kill\"(으)로 있습니다.\n");
    printf("'root' 디렉토리(폴더) 밑에 'usr' 디렉토리(폴더) 밑에 'bin' 디렉토리(폴더) 밑에 \"kill\"(으)로 있습니다.\n");
    next_line();

    printf("사용법은 \"kill [옵션 or 시그널] [PID]\" 입니다.\n");
    next_line();

    printf("시그널을 통해 다양한 종료 옵션을 지정해줄 수 있으며\n");
    printf("시그널을 지정하지 않으면 기본값인 TERM(15번) 시그널로 설정됩니다.\n");
    printf("(ex. 'kill [PID]' -> 15번 TERM 시그널 전송)\n");
    next_line();

    printf("기타 세부 시그널 옵션을 보는 방법은 \"kill -l\" 명령어를 입력하면 됩니다.\n\n");
    next_line();
    printf("다음은 \"kill -l\"을 입력했을 때 출력되는 결과로 시그널 종류를 출력합니다.\n");
    system("kill -l");
    next_line();

    printf("[알아두면 좋은 시그널 옵션]은 다음과 같습니다.\n\n");
    printf("TERM (15번) = 기본 종료\n");
    printf("KILL (9번)  = 강제 종료\n");
    next_line();

    printf("특히 강제 종료(9번)는 최후의 수단으로 사용해야 합니다.\n");
    printf("프로세스를 강제 종료하게 되면 데이터가 유실될 수 있기 때문입니다.\n");
    next_line();

    printf("[실습] \"kill\" 명령어로 PID가 '1234'인 프로세스를 '강제 종료' 하십시오. (시그널 번호 사용)\n");
    printf("사용법 : kill -[시그널 번호] [PID]\n");
    fake_run_command("kill -9 1234");
    next_line();
    printf("[실습] \"kill\" 명령어로 PID가 '5678'인 프로세스를 '정상 종료' 하십시오. (시그널 번호 사용)\n");
    printf("사용법 : kill -[시그널 번호] [PID]\n");
    fake_run_command("kill -15 5678");
    next_line();
    printf("[실습] \"kill\" 명령어에 옵션을 넣지 않고 PID가 '2020'인 프로세스를 '정상 종료' 하십시오. (PID 사용)\n");
    printf("사용법 : kill [PID]\n");
    fake_run_command("kill 2020");
    next_line();
    // 명령어 실습

    printf("현재 실행 중인 프로세스의 'PID'를 확인하는 방법으로는\n");
    printf("\"ps\" 명령어나 \"top\" 명령어를 사용하시면 됩니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}
