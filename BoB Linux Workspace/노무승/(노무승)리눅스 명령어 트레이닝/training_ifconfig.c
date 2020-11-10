#include "func.h"

void training_ifconfig(void)
{
	system("clear");
    create_defdir();
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("ifconfig 명령어는 네트워크 인터페이스를 확인하고 설정할 수 있는 명령어입니다.\n");
    next_line();

    printf("[실습] ifconfig 명령어를 입력해 네트워크 인터페이스를 확인해보세요.\n");
    run_command("ifconfig");
    next_line();
    // 네트워크 인터페이스 출력 실습

    printf("맨 좌측의 경우 네트워크 인터페이스의 이름(ex. enp0s3) 입니다.\n");
    next_line();

    printf("lo 인터페이스의 경우, loop back의 약자로\n");
    printf("자기 자신과 통신하기 위한 가상 인터페이스입니다.\n");
    next_line();

    printf("flags는 인터페이스의 상태를 말하며,\n");
    printf("mtu는 네트워크 인터페이스의 최대 전송 단위입니다.\n");
    next_line();
    
    printf("inet은 네트워크 인터페이스에 할당된 아이피 주소(ipv4)를 의미하며,\n");
    printf("inet6는 네트워크 인터페이스에 할당된 ipv6 주소를 의미합니다.\n");
    printf("일반적으로 '내부 아이피'라 부르는 주소는 ipv4 형식인 inet 주소입니다.\n");
    next_line();

    printf("netmask는 쉽게 생각하여 네트워크에 할당할 수 있는 아이피 주소의 최대 값을 뜻 하며,\n");
    printf("brodcast는 네트워크에 속하는 모든 호스트에게 데이터를 보낼 수 있는 주소를 뜻 합니다.\n");
    printf("ether는 네트워크 인터페이스의 하드웨어 주소이며, 다른 말로는 맥(MAC) 주소라고 부릅니다.\n");
    next_line();

    printf("ifconfig 명령어를 사용해 특정 인터페이스를 비활성화, 활성화 할 수도 있는데,\n");
    printf("'ifconfig [인터페이스 이름] up/down' 으로 사용합니다.\n");
    next_line();

    printf("비활성화한 인터페이스는 단순 'ifconfig' 명령어로는 나타나지 않지만,\n");
    printf("-a 옵션을 주면 비활성화한 인터페이스까지 모두 볼 수 있습니다.\n");
    next_line();

    printf("원하는 인터페이스의 정보만 보고 싶다면\n");
    printf("'ifconfig [인터페이스 이름]'으로 가능합니다.\n");
    next_line();

    printf("[실습] ifconfig 명령어를 이용해 lo 인터페이스의 정보만 출력해보세요.\n");
    run_command("ifconfig lo");
    next_line();
    // 특정 인터페이스 정보만 출력하도록 실습

    printf("각 네트워크 인터페이스에 할당된 정보를 바꾸고 싶을 때는 아래와 같이 입력하면 됩니다.\n");
    printf("IP 주소 변경        : ifconfig [인터페이스 이름] [IP]\n");
    printf("netmask 주소 변경   : ifconfig [인터페이스 이름] netmask [IP]\n");
    printf("brodcast 주소 변경  : ifconfig [인터페이스 이름] brodcast [IP]\n");
    printf("맥주소 변경         : ifconfig [인터페이스 이름] hw ether [IP]\n");
    printf("정보를 바꿀 때는 항상 주의해야 하며, 왠만해서 함부로 정보를 바꾸지 않는 것을 추천드립니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}