#include "func.h"

void training_linux_basic(void)
{
    create_defdir();
    system("clear");
    
    printf("환영합니다.\n\n");
    printf("여기서는 리눅스가 무엇인지와 종류, 필요성 그리고 기본 디렉토리들을 배울 것입니다.\n\n\n");
    printf("1. 리눅스란 무엇인가\n");
    printf("2. 리눅스 배포판과 종류\n");
    printf("3. 리눅스의 필요성\n");
    printf("4. 리눅스의 기본 디렉토리들\n");
    next_line();

    system("clear");
    //리눅스란 무엇인가
    printf("[1. 리눅스란 무엇인가?]\n\n");
    printf("\"Linux\" 자체는 리눅스 운영 체제에 있는 '커널의 이름'입니다.\n\n");
    printf("'커널'은 운영체제의 핵심 부분이지만\n");
    printf("'커널'만으로는 운영체제의 역할을 수행할 수 없습니다.\n");
    next_line();
    printf("\"Linux 배포판\"은 \"리누스 토르발스\" 또는 \"리누스 토발즈\"가 만든\n");
    printf("운영 체제의 커널인 '리눅스 커널'에 기반을 두고\n");
    printf("'Unix(유닉스)'라는 운영 체제를 모델로 하여 만든 \n");
    printf("\"오픈 소스로 된 네트워크 운영 체제(Network OS)\" 입니다.\n");
    next_line();

    printf("현재는 수 많은 \"Linux 배포판\"에서 \"Linux\"라고 이름을 붙여 사용하기 때문에\n");
    printf("\"Linux\"와 \"Linux 배포판\"의 의미가 동일하게 쓰이는 경우가 많습니다.\n");
    next_line();

    printf("\"Linux 배포판\"들은 'Linux 커널'과 여러 시스템 소프트웨어와 자유 소프트웨어\n");
    printf("그리고 각종 라이브러리들을 포함한 운영 체제 입니다.\n\n");
    printf("이러한 소프트웨어나 라이브러리들의 다수가 'GNU 프로젝트'에 의해 제공됩니다.\n");
    next_line();
    
    system("clear");
    //GNU란 무엇인가
    printf("\"GNU\"는 GNU's Not Unix의 약자이며, 말 그대로 'GNU는 유닉스가 아니다'라는 의미입니다.\n\n");
    printf("\"GNU 프로젝트\"는 \"리처드 스톨먼\"에 의해서 설립된 자유 소프트웨어 재단인\n");
    printf("\"FSF(Free Software Foundation)\"에서 시작되었습니다.\n");
    next_line();

    printf("\"GNU 프로젝트\"에 의해 완성된 \"Linux\"는\n");
    printf("\"FSF\"에서 'GNU 소프트웨어'의 중요성을 강조하기 위해\n");
    printf("\"GNU/Linux\"라는 이름을 사용합니다.\n");
    next_line();

    printf("\"GNU 프로젝트\"는 소프트웨어를 상업화하는 것에 반대하여\n");
    printf("\"모두가 공유할 수 있는 소프트웨어\"를 만드는 것에 목표를 두고 있습니다.\n");
    next_line();
    printf("그리하여 \"Linux 배포판\"을 사용하면 사용자들은\n");
    printf("\"GNU 프로젝트\"에서 무료로 제공해주는 소프트웨어들을 바로 사용할 수 있습니다.\n\n");
    printf("그리고 \"Linux\"는 \"GNU 프로젝트\"와 연계되어 발전해왔기 때문에\n");
    printf("\"Linux 배포판\"에 있는 \"GNU 소프트웨어\"들은 'FSF(Free Software Foundation)'의\n");
    printf("GPL(General Public License)이라는 저작권 라이센스 규약을 따릅니다.\n");
    next_line();
    
    system("clear");
    //리눅스 시스템의 특징
    printf("\"Linux\" 시스템의 특징은 다음과 같습니다.\n\n\n\n");
    printf("1. 다중 사용자 및 다중 처리 시스템입니다.\n\n");
    printf("2. 오픈 소스로 되어 있어 완전히 공개된 시스템입니다.\n\n");
    printf("3. 다양한 네트워크 환경을 지원합니다.\n\n");
    printf("4. 다양한 파일 시스템을 지원합니다.\n\n");
    printf("5. 뛰어난 이식성을 가지고 있습니다.\n\n");
    printf("6. 유연성과 확장성이 뛰어납니다.\n\n");
    printf("7. 안정성과 보안성이 뛰어납니다.\n\n");
    printf("8. 다양한 응용 프로그램들이 무료로 제공됩니다.\n\n");
    printf("9. 우수한 가성비를 가지고 있습니다.\n\n");
    printf("10. 다양한 배포판들이 존재합니다.\n\n");
    next_line();

    system("clear");
    //리눅스의 기술적인 특징
    printf("\"Linux\"의 기술적인 특징은 다음과 같습니다.\n\n\n\n");
    printf("1. 계층적인 파일 구조를 가지고 있습니다.\n\n");
    printf("2. 모든 장치를 파일화하여 관리하고 사용합니다.\n\n");
    printf("3. 가상메모리를 사용합니다.\n\n");
    printf("4. 동적 라이브러리를 지원합니다.\n\n");
    printf("5. 가상 콘솔을 지원합니다.\n\n");
    printf("6. 파이프(|)와 리다이렉션( < , > ) 기능이 있습니다.\n\n");
    next_line();

    system("clear");
    //리눅스의 단점
    printf("하지만 이런 \"Linux\" 시스템에도 단점이 존재합니다\n\n\n\n");
    printf("1. 기술 지원이 부족합니다.\n\n");
    printf("2. 특정 하드웨어에 대한 지원이 부족합니다.\n\n");
    printf("3. 사용자들의 기술적인 숙련도를 필요로 합니다.\n\n");
    next_line();
    
    system("clear");
    //리눅스의 예시
    printf("\"Linux\"는 처음에 x86 아키텍처에 기반한 개인용 PC에 맞게 개발되었습니다.\n\n");
    printf("그러나 이후에 다른 운영 체제와 더 많은 플랫폼으로 이식하게 되었는데\n\n");
    printf("현재 스마트폰 운영체제 중 하나인 'Android(안드로이드)'가 리눅스 기반이고\n");
    printf("Server 시장에서 대부분의 운영 체제로 사용되고 있으며\n");
    printf("임베디드 시스템에서도 사용되고 있습니다.\n\n\n");
    next_line();

    //리눅스 텍스트 모드와 그래픽 모드
    printf("\"리눅스 운영 체제\"에서는 GUI(Graphical User Interface) 환경과\n");
    printf("CUI(Character User Interface) 혹은 TUI(Text User Interface) 환경\n");
    printf("이렇게 2개의 환경으로 나뉘어져 있습니다.\n\n");
    printf("기본적으로는 그래픽이 없는 'CUI 환경' 혹은 'TUI 환경'을 제공하며\n");
    printf("서버용으로 사용하기 적합하지만\n");
    printf("사용자가 일반적으로 데스크톱 환경에서 사용할 수 있도록 'GUI 환경'도 제공해 줍니다.\n");
    next_line();

    system("clear");
    //리눅스 배포판 종류
    printf("[2. 리눅스 배포판과 종류]\n\n");
    printf("\"Linux 배포판\"은 'Linux'라는 커널에 여러 자유 소프트웨어들과 라이브러리들을 포함하여 만들어진 운영 체제 입니다.\n\n");
    next_line();

    printf("\"Windows\" 운영 체제에는 '95', 'xp', '7', '10' (와)과 같이 여러 버전이 있습니다.\n\n");
    printf("\"Linux\"도 \"Windows\"처럼 여러 버전이 존재하는데\n");
    printf("운영 체제의 핵심인 '커널'과 다수의 소프트웨어들의 코드가 공개되어 있어서\n");
    printf("수 많은 사용자들이 자신이 사용할 목적이나 연구를 위해\n");
    printf("변형하거나 수정하여 배포하기 때문에\n\n");
    printf("\"Windows\"보다 몇 배 이상 많은 버전이 존재하고\n");
    printf("이 버전들을 \"리눅스 배포판\" 이라고 합니다.\n\n\n");
    next_line();

    printf("\"Linux 배포판\"을 크게 3가지 계열로 나누자면 다음과 같습니다.\n\n");
    printf("1. \"Slackware(슬랙웨어)\" 계열\n");
    printf("2. \"Debian(데비안)\" 계열\n");
    printf("3. \"RedHat(레드햇)\" 계열\n");
    next_line();

    printf("위의 3가지 리눅스 배포판 계열를 제외하고도 여러가지가 있지만\n");
    printf("그 중 가장 최초의 리눅스 배포판은 \"SLS(Softlanding Linux System)\" 입니다.\n");
    next_line();

    system("clear");
    //SLS
    printf("[SLS(Softlanding Linux System)]\n\n");
    printf("1992년 5월에 '피터 맥도날드'에 의해 만들어진 초기 리눅스 배포판입니다.\n\n\n");
    printf("\"SLS\"(은)는 한 때 가장 유명한 리눅스 배포판였지만, 버그가 많은 배포판이었습니다.\n");
    next_line();
    
    system("clear");
    //slackware
    printf("[Slackware]\n\n");
    printf("\"Slackware\"는 '패트릭 볼커딩'이 \"SLS\"에 존재하는 버그들을 잡기 시작하고\n");
    printf("이 결과로 만들어진 배포판이며, 현재까지도 살아있는 가장 오래된 배포판입니다.\n\n\n");
    printf("\"Slackware\"는 \"가장 Unix다운 리눅스 배포판\"이라는 목적에 따라\n");
    printf("사용자에게 시스템의 권한을 최대한 넘겨주었고\n");
    printf("그리하여 사용자가 의도하지 않는 결과는 거의 일어나지 않습니다.\n\n\n");
    printf("하지만, Unix와 비슷하게 만든다는 목적으로 인해\n");
    printf("사용자들이 불편을 감수해야 하는 것들이 있습니다.\n\n");
    printf("그 중 하나는 프로그램을 설치할 때 설치에 필요한 것들을 자동으로 처리해주지 않는다는 것입니다.\n\n\n");
    printf("\"SlwackWare\" 계열의 배포판에는 \"SuSE\", \"Porteus\", \"Vector Linux\", \"Slackintosh\" 등이 있습니다.\n");
    next_line();
    
    system("clear");
    //Debian
    printf("[Debian]\n\n");
    printf("\"Debian\"은 \"Slackware\" 다음으로 오래된 배포판이며\n");
    printf("인기가 많고 영향력이 있는 배포판입니다.\n\n\n");
    printf("현재는 \"Debian GNU/Linux\"만 정식 지원하고\n");
    printf("'GNU 프로젝트'의 지원을 받아 '데비안 프로젝트'라는 공동체에서 개발하고 있습니다.\n\n\n");
    printf("\"Debian\"은 안정성과 보안에 중점을 두어 개발되고 있으며\n");
    printf("\"RedHat\"과는 달리 오픈 소스쪽에 가깝습니다.\n\n\n");
    printf("\"Debian\" 계열의 배포판에는 \"Ubuntu\", \"Kubuntu\", \"Lindows\", \"Backtrack\" 등이 있습니다.\n");
    next_line();
    
    system("clear");
    //RedHat
    printf("[RedHat]\n\n");
    printf("\"RedHat\"은 기업용 서버 운영 체제로 가장 인기 있으며\n");
    printf("\"RedHat 리눅스\"는 유료 버전과 무료 버전 둘 다 배포했었지만\n\n");
    printf("현재 \"RedHat 리눅스\"의 의미는 상용으로 판매되는\n");
    printf("'RHEL(RedHat Enterprise Linux)'만을 의미합니다.\n\n");
    printf("\"RedHat\" 계열의 리눅스 중에는 유명한 \"Fedora\"와 \"CentOS\"가 있습니다.\n\n");
    printf("\"Fedora\"는 기존의 'RedHat 리눅스'의 무료 버전 배포를 중단하고 이름을 \"Fedora\"로 바꾼 것입니다.\n");
    printf("\"Fedora\"는 기업용 리눅스인 \"RHEL(RedHat Enterprise Linux)\"에 들어갈 기능들을\n");
    printf("테스트 하는 용도로 사용되고 있으며, 개발자들에게 주로 쓰이는 운영체제 입니다.\n\n");
    printf("\"Centos\"는 'The Community ENTerprise Operating System'의 약자이며\n");
    printf("\"RHEL(RedHat Enterprise Linux)\"와 완전히 호환되는 기업용 무료 리눅스 운영체제입니다.\n");
    printf("\"RHEL(RedHat Enterprise Linux)\"를 무료로 바꾼 배포판이라고 자주 언급되며\n");
    printf("중소 기업이나 개인적인 서버로 사용하기 좋습니다.\n\n");
    printf("\"RedHat\" 계열의 배포판에는 \"Oracle Enterprise\", \"AsianLinux\", \"OpenNode\" 등이 있습니다.\n");
    next_line();
    
    system("clear");
    printf("이렇게 큰 뿌리를 맡고 있는 리눅스 배포판 계열 3가지에 대해 배웠습니다.\n\n");
    printf("하지만, 위의 3가지는 리눅스 배포판들을 큰 계열로 나눈 것이며\n");
    printf("리눅스 배포판들은 수도 없이 많고\n");
    printf("현재도 많은 사용자들이 변형하여 사용하거나 배포하고 있습니다.\n\n");
    printf("그리고 사용자들에게 많이 사용되는 배포판은\n");
    printf("\"Ubuntu\", \"kali linux\", \"Jentoo Linux\" 등이 있습니다.\n\n");
    printf("더 많은 리눅스 배포판들을 확인해보고 싶으시면 아래의 링크로 접속하여 확인해보시면 됩니다.\n\n");
    printf("http://futurist.se/gldt/\n");
    next_line();

    system("clear");
    //리눅스의 필요성
    printf("[3.리눅스의 필요성]\n\n");
    printf("대부분의 사람들은 윈도우 운영 체제에 익숙해져 있습니다.\n");
    printf("그런 사람들에게 \"Linux\"라는 운영 체제는 생소하고 어렵고 새로울 것입니다.\n\n");
    printf("하지만, \"Linux\"는 이미 사람들 일상 속에 존재하며 다양하게 자주 이용되고 있습니다.\n");
    printf("예를 들어, 안드로이드 계열 스마트폰이나 가전 제품이나 여러 임베디드 시스템들입니다.\n\n");
    next_line();

    printf("\"Linux\"는 커널의 이름입니다.\n\n");
    printf("\"Linux\" 커널에 여러 소프트웨어들과 라이브러리들을 합하여 탄생하는 것이\n");
    printf("\"Linux 배포판\"입니다.\n\n");
    printf("이렇듯 \"Linux\"는 컴퓨터 운영 체제들 중 한 종류이자 커널 자체를 의미합니다.\n");
    next_line();

    printf("\"Linux\"의 가장 큰 장점 두 가지는 소스 코드가 공개되어 있다는 것과\n");
    printf("다중 사용자 및 다중 처리를 지원하는 네트워크 운영 체제(NOS)라는 것입니다.\n");
    next_line();

    printf("\"Linux\"는 \"Windows\"와 달리 무료라는 점에서 전 세계적으로 사용자들이\n");
    printf("피드백을 하고 취약점이 발견되면 빠르게 패치할 수 있습니다.\n\n");
    printf("그리고 \"Linux\"는 모든 환경을 원하는대로 커스터마이징하여 사용할 수 있고\n");
    printf("개발친화적인 면 때문에 개발자들에게 인기가 많으며\n");
    printf("Linux 서버를 관리하기 쉽기 때문에 엔지니어들에게도 인기가 많습니다.\n\n\n");
    next_line();

    printf("정리하자면 \"Linux 시스템\"은 대부분 소스 코드가 오픈되어 있어서 광범위하게 사용되고\n");
    printf("다중 사용자 및 다중 처리를 지원함으로 서버를 운영하기에 적합하고\n\n");
    printf("무엇보다 무료인 점으로 인해 전 세계의 사용자로부터 도움을 받을 수 있다는 것입니다.\n\n");
    printf("또한 \"Linux\"를 사용하며 공부한다면\n");
    printf("운영체제와 커널의 전체적인 흐름과 동작 원리를 아는 것에 도움이 될 수 있습니다.\n");
    next_line();
    
    system("clear");
    //리눅스 기본 디렉토리들
    printf("[4. Linux 배포판의 기본 디렉토리들]\n\n");
    printf("\"Linux\"의 디렉토리 또는 파일 시스템 구조는\n");
    printf("\"Windows\"와는 조금 다른 구조로 되어있습니다.\n\n");
    printf("\"Windows\"에서는 '폴더'라고 부르지만, \"Linux\"에서는 '디렉토리'라고 부릅니다.\n");
    next_line();

    printf("\"Linux 시스템\"은 모든 것을 디렉토리 및 파일화 하여 관리합니다.\n\n");
    printf("\"Linux 배포판\"들은 리눅스 파일 시스템 표준인 \"FSSTND(FileSystem STaNDard)\"를 준수하고 있으므로 기본적인 디렉토리 구조가 비슷합니다.\n\n");
    next_line();
    printf("\"FSSTND(FileSystem STaNDard)\"는 1994년 2월에 발표되었으며, 리눅스 뿐만 아니라\n");
    printf("다른 Unix 계열의 운영 체제에서도 일반화하여 추후에 \"FHS\"로 이름이 변경되었습니다.\n\n");
    next_line();
    printf("\"FHS\"에서는 다른 물리적 장치에 저장되어 있다고 하더라도 모든 디렉토리가\n");
    printf("루트 디렉토리라고 불리는 ' / '의 밑에 존재하게 되어 있습니다.\n");
    next_line();

    //root Directory
    system("clear");
    printf("[ / ]\n\n");
    printf("\"Linux 배포판들\"에서 가장 중요한 디렉토리로, 모든 디렉토리의 최상위 디렉토리입니다.\n\n");
    printf("어떠한 디렉토리 경로를 '절대 경로'로 표기할 때 기준이 되는 디렉토리로서\n");
    printf("모든 디렉토리들은 이 디렉토리로부터 시작하게 됩니다.\n");
    next_line();

    system("clear");
    printf("[ /bin ]\n\n");
    printf("\"Linux 배포판\"에서 기본적인 명령어들의 실행 파일들이 저장되어 있는 디렉토리입니다.\n\n");
    printf("\"Linux 시스템\"을 사용하기 위해 꼭 있어야 하고 가장 기본이 되는 명령어들\n");
    printf("ls, cp, mv, rm  등의 실행 파일들이 이 디렉토리에 존재합니다.\n\n");
    printf("'root 사용자'와 '일반 사용자' 모두 사용할 수 있는 디렉토리입니다.\n\n\n");
    next_line();

    printf("[ /sbin ]\n\n");
    printf("'ifconfig', 'halt' 등과 같은\n");
    printf("시스템 관리자들이 사용하는 명령어의 실행 파일들이 존재합니다.\n\n");
    printf("오직 'root 사용자'만 실행할 수 있는 실행 파일들입니다.\n");
    next_line();
    
    system("clear");
    printf("[ /boot ]\n\n");
    printf("\"Linux\"를 부팅할 때 이용되는 부트로더가 들어있는 디렉토리입니다.\n\n");
    printf("부팅에 핵심적인 커널 이미지와 부팅 정보 파일을 담고 있는 디렉토리로서\n");
    printf("GRUB과 같은 부팅할 때에 매우 중요한 파일들이 존재합니다.\n\n\n");
    next_line();

    printf("[ /dev ]\n\n");
    printf("'Device'의 약자이며, 물리적인 장치들이 파일화 되어 저장되어 있습니다.\n");
    printf("CD-ROM과 같은 장치 파일들이 존재합니다.\n");
    printf("한 때는 백도어 파일이 숨겨져 있는 디렉토리로 유명했습니다.\n");
    next_line();

    system("clear");
    printf("[ /etc ]\n\n");
    printf("\"Linux\"에서 대부분의 설정 파일들이 저장되는 디렉토리입니다.\n\n");
    printf("시스템 전체에서 사용하는 설정과 비밀번호나 유저 정보들 같은 중요한 데이터들도 저장됩니다.\n\n");
    next_line();

    printf("[ /home ]\n\n");
    printf("사용자의 홈 디렉토리로, 이 디렉토리 밑에 대부분 사용자의 ID와 동일한 이름으로 디렉토리가 생성됩니다.\n");
    printf("ex) 'rookie'라는 사용자의 홈 디렉토리는 '/home/rookie'와 같이 생성됩니다.\n\n");
    next_line();
    
    printf("[ /lib ]\n\n");
    printf("\"Linux(커널)\"(이)가 필요로 하는 커널 모듈 파일들과 C와 C++ 등으로 작성되어 만들어진\n");
    printf("프로그램들에 필요한 각종 라이브러리 파일들이 존재하는 디렉토리입니다.\n");
    next_line();

    system("clear");
    printf("[ /media ]\n\n");
    printf("DVD, CD-ROM, USB 등과 같은 탈부착이 가능한 장치들의 마운트 포인트로 사용되는 디렉토리입니다.\n\n\n");
    next_line();

    printf("[ /mnt ]\n\n");
    printf("[ /media ] 디렉토리와 비슷한 용도로 탈부착이 가능한 장치들에 대해 일시적인 마운트 포인트로 사용되는 디렉토리입니다.\n");
    next_line();

    system("clear");
    printf("[ /proc ]\n\n");
    printf("가상 파일 시스템이라고 불리는 디렉토리입니다.\n\n");
    printf("각 프로세스 이름에 따라 수 많은 하위 디렉토리들이 존재하고\n");
    printf("현재 실행되는 프로세스에 대한 정보와 데이터가 담겨있습니다.\n\n");
    printf("실제 디스크 공간에는 존재하지 않기 때문에 가상 파일 시스템이라고 불립니다.\n\n");
    printf("여기에 존재하는 파일들 중에는 현재 실행 중인 커널의 옵션값을\n");
    printf("즉시 변경할 수 있는 파라미터 파일들이 있기 때문에\n");
    printf("시스템 운용에 있어서 매우 중요한 의미를 가집니다.\n");
    next_line();

    system("clear");
    printf("[ /root ]\n\n");
    printf("\"Linux 시스템\"에서 최고 관리자인 'root 사용자'의 개인 홈 디렉토리입니다.\n\n\n");
    next_line();

    printf("[ /tmp ]\n\n");
    printf("공용 디렉토리로 불리며, 시스템을 사용하는 모든 사용자들이 공동으로 사용하는 디렉토리입니다.\n\n");
    printf("임시 파일을 저장하는 디렉토리로서 세션 정보 등이 들어 있고\n");
    printf("어떠한 페이지로부터 웹 해킹에 사용되는 파일이 업로드되는 가장 흔한 디렉토리입니다.\n");
    next_line();
    
    system("clear");
    printf("[ /usr ]\n\n");
    printf("시스템이 아닌 일반 사용자들이 주로 사용하는 디렉토리입니다.\n\n");
    printf("C++, chsh, cpp, du, find 등과 같이 일반 사용자들용 명령어들이 \"/usr/bin\" 디렉토리에 저장됩니다.\n\n");
    printf("그리고 \"/usr/local\" 디렉토리는 사용자들이 설치한 어플리케이션들이 설치됩니다.\n\n");
    printf("또한, \"/usr/sbin\" 디렉토리는 각종 어플리케이션을 설치할 때 생성되는 명령어들과\n");
    printf("네트워크에 관련된 명령어들이 존재합니다.\n\n\n");
    next_line();

    printf("[ /var ]\n\n");
    printf("시스템을 운용할 때 생성되었다가 삭제되는 데이터들을\n");
    printf("일시적으로 저장하는 디렉토리입니다.\n\n");
    printf("로그 파일, 데이터베이스 캐싱 파일, 웹 서버 이미지 파일 등이 저장되며\n");
    printf("파일의 크기가 고정적이지 않은 경우 적합한 디렉토리입니다.\n");
    next_line();

    system("clear");
    printf("[ /lost+found ]\n\n");
    printf("최상위 디렉토리인 ' / ' 디렉토리에만 존재하는 것이 아니라\n");
    printf("파일 시스템마다 존재할 수 있는 디렉토리입니다.\n\n");
    printf("파일 시스템 체크 및 복구 유틸리티 실행 후에 주로 생성되는 것으로\n");
    printf("복구되지 않은 채로 블록만 존재하는 파일이나 연결이 끊어진 inode들이 숫자 파일 형태로 존재합니다.\n");
    next_line();

    system("clear");
    printf("이상으로 리눅스 기본 지식 Part가 끝났습니다.\n\n");
    printf("이 트레이닝에서 배운 것만으로는 많이 부족할 것입니다.\n");
    printf("추후에 꼭 구글에 검색을 해보시거나 서적 등을 통해 더 많이 공부하시길 바랍니다.\n\n");
    printf("고생하셨습니다.\n");

    delete_defdir();
}
