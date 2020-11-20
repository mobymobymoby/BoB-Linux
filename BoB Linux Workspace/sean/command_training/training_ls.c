#include "func.h"

void training_ls(void)
{
    create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("가장 먼저 배울 명령어는 \"ls\" 입니다.\n");
    next_line();
    printf("\"ls\"는 'list segments'의 약자이며\n");
    printf("파일이나 디렉토리의 구조, 정보를 보여주는 명령어입니다.\n");
    next_line();

    system("touch 1234.txt");
    system("touch 5678.txt");
    system("chmod 777 1234.txt");
    system("chmod 764 5678.txt");
    // 테스트 파일 생성

    printf("[실습] ls 명령어를 입력해보세요\n");
    just_run_command("ls");
    printf("\n단순히 ls 명령어를 입력하면 윈도우의 \"dir\" 명령어와 같이 별 다른 구조 없이\n");
    printf("현재 작업 디렉터리에 있는 파일과 폴더를 보여줍니다.\n");
    next_line();
        
    printf("[실습] ls -l 명령어를 입력해보세요\n");
    just_run_command("ls -l");
    next_line();
    printf("'-l' 옵션을 주면 위와 같이 리스트 구조로 \n");
    printf("현재 작업 디렉터리에 있는 파일과 폴더를 볼 수 있습니다.\n");
    next_line();
    printf("만약 명령어 \"ls -l\"을(를) 통해 나온 출력 결과가 다음과 같을 때\n\n");
    printf("drwxrw-r-- 1 kim rookie 1024 2020-10-10 test\n\n");
    printf("첫 번째 'drwxrw-r--'는 어떤 유형인지와 권한을 나타내고\n");
    printf("두 번째 '1'은 해당 파일에 대한 하드링크의 수를 보여줍니다.\n");
    printf("세 번째 'kim'은 소유자 이름(UID)\n");
    printf("네 번째 'rookie'는 그룹 이름(GID)입니다.\n");
    printf("다섯 번째 '1024'는 파일 크기\n");
    printf("여섯 번째 '2020-10-10'는 파일 최종 수정 날짜\n");
    printf("일곱 번째는 파일 이름입니다.\n");
    next_line();
    printf("여기서 10자리의 문자로 유형과 권한을 나타낸 것이 맨 앞의 'drwxrw-r--'입니다.\n");
    next_line();
    printf("예를 들어 유형과 권한을 나타내는 'drwxrw-r--'이라는 10자리 문자가 있다면\n");
    printf("'d', 'rwx', rw-', 'r--'와 같이");
    printf("크게 4부분으로 나누어 생각할 수 있습니다.\n\n");
    next_line();
    printf("먼저 맨 앞의 'd'는 directory라는 의미로 유형을 나타냅니다.\n\n");
    printf("유형을 나타내는 문자로는 다음과 같습니다.\n\n");
    printf("'d' : Directory(디렉토리)를 의미합니다.\n");
    printf("'-' : 일반 파일을 의미합니다.\n");
    printf("'b' : 블록 특수 파일을 의미합니다.\n");
    printf("'c' : 문자 특수 파일을 의미합니다.\n");
    printf("'l' : 링크(바로가기)를 의미합니다.\n");
    printf("'p' : 선입선출(FIFO) 특수 파일을 의미합니다.\n");
    printf("'s' : 로컬 소켓을 의미합니다.\n\n");
    printf("만약 유형을 알려주는 문자가 '-'로 되어 있다면, 그것은 '일반 파일'을 의미합니다.\n");
    next_line();
    printf("다음으로 나머지 9자리는 'rwx' 'rw-' 'r--'와 같이 3자리씩 끊어서 생각할 수 있습니다.\n");
    next_line();
    printf("앞에서 배웠던 명령어인 'pwd'의 출력 결과가 UID와 같다면, 현재 사용자는 해당 파일의 소유자가 됩니다.\n");
    printf("하지만 같지 않다면 '그룹' 권한이나 '전체' 권한을 적용받습니다.\n\n");
    printf("자신의 그룹과 GID가 일치 한다면, 그룹 권한을 적용받게 되고, 그렇지 않다면 전체 권한을 적용받게 되는 것입니다.\n");
    printf("만약 UID와 GID가 모두 일치한다면, UID를 우선 적용 받게됩니다.\n");
    next_line();
    printf("그럼 다시 위의 예시로 돌아와서, 먼저 'rwx' 부분은 '사용자(소유자,owner)' 권한입니다.\n");
    printf("앞에서 살펴보았던 pwd로 현재 사용자를 알 수 있었습니다.\n\n");
    printf("'r'은 읽기, 'w'는 쓰기, 'x'는 실행 권한을 의미하며, 만약 'r-x'와 같이 되어 있다면 읽기와 실행 권한은 있지만,\n");
    printf("쓰기 권한 자리가 '-'로 비워져있기 때문에 쓰기 권한은 없다는 것을 의미합니다.\n");
    next_line();
    printf("다음 부분인 'rw-' 부분은 '그룹(group)' 권한 입니다.\n");
    printf("현재 사용자가 속해있는 그룹이 해당 파일이나 디렉토리의 GID와 같다면\n");
    printf("읽기 권한과 쓰기 권한은 있고, 실행 권한은 없음을 의미합니다.\n");
    next_line();
    printf("마지막 부분인 'r--' 부분은 '전체(other)' 권한입니다.\n");
    printf("읽기 권한만 있고 쓰기 권한이나 실행 권한이 없음을 의미합니다.\n");
    next_line();
    printf("지금까지는 10자리 문자로 권한을 나타내었지만, 3자리의 숫자로 나타낼 수도 있습니다.\n");
    printf("각 자리는 문자로 나타내는 방식과 같이 소유자, 그룹, 전체 권한으로 나뉩니다.\n");
    printf("(파일, 디렉토리를 나타내주는 맨 앞 자리가 없어진 것이라고 생각하면 됩니다.)\n");
    next_line();
    printf("읽기 권한은 숫자 '4', 쓰기 권한은 숫자 '2', 실행 권한은 숫자 '1'로 취급하고\n");
    printf("세 권한을 더한 합을 각 자리에 표시합니다.\n");
    next_line();
    printf("만약 '764'이라는 권한이 있다면, 맨 앞의 '7'은 소유자 권한 부분이며, 4+2+1이므로,\n");
    printf("읽기, 쓰기, 실행 권한이 모두 있음을 의미합니다. 즉 문자로 표시된 'rwx' 권한과 같습니다.\n\n");
    printf("다음으로 '6'은 그룹 권한 부분이며, 4+2+0이므로, 읽기 권한과 쓰기 권한은 있지만,\n");
    printf("실행권한은 '1'이 아닌, '0'이므로 실행권한은 없습니다.\n");
    printf("마지막으로 '4'는 전체 권한 부분이며, 4+0+0이므로 읽기 권한만 있다고 할 수 있습니다.\n");
    next_line();
    printf("이러한 권한 시스템은 리눅스에서 중요한 내용이지만,\n");
    printf("리눅스를 사용하면서 저절로 익숙해지게 되므로 억지로 외우거나 할 필요는 없습니다.\n");
    next_line();
    printf("[실습] ls -al 명령어를 입력해보세요\n(-a 옵션을 추가로 주면 숨김 파일까지 모두 볼 수 있습니다.)\n");
    just_run_command("ls -al");
    next_line();
    printf("[실습] ls -alh 명령어를 입력해보세요\n(-h 옵션을 추가로 주면 파일 크기를 K, M, G 단위로 볼 수 있습니다.)\n");
    just_run_command("ls -alh");
    next_line();
    
    delete_defdir();
    printf("고생하셨습니다!\n");
}
