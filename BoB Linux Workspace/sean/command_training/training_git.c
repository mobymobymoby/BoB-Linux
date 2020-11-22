#include "func.h"

void training_git(void)
{
	system("clear");
	printf("이번에 학습할 내용은 'git'입니다.\n\n");
	next_line();
	printf("git이란 리누스 토발즈가 개발한 분산형 버전관리 시스템이며\n파일의 변경사항을 추적하고 여러명의 사용자들이 해당 파일의 작업을 조율할 수 있습니다.\n\n");
	next_line();
	printf("git은 데이터를 파일 시스템 스냅샷의 연속으로 취급하여, 시간순으로 프로젝트의 스냅샷을 저장합니다.\n커밋되거나 프로젝트의 상태가 저장될 떄 마다 이전 상태의 파일에 대한 링크를 저장하는 방식입니다.\n\n");
	next_line();
	printf("git은 데이터베이스에 데이터가 추가되는 방식이기 떄문에 되돌리거나 데이터를 삭제할 순 없습니다.\n하지만 위와 같은 방식 덕분에 일단 스냅샷을 커밋하고 나면 데이터를 잃어버릴 걱정 없이 쉽게 손실된 데이터 복구가 가능합니다.\n\n");
	next_line();
	printf("git에는 총 세가지 상태가 있습니다.\n1. Committed : 데이터가 로컬 데이터베이스에 안전하게 저장되었다는 것을 의미합니다.\n2. Modified : 수정한 파일이 아직 로컬 데이터베이스에 커밋되지 않았다는 것을 의미합니다.\n3. Staged : 현재 수정된 파일이 곧 커밋될 것이라고 표시된 상태를 의미합니다.\n\n");
	next_line();
	printf("git은 명령어를 통해 레포지토리 관리가 가능합니다.\n우선 git 명령어를 사용하기 위해서는 git을 설치해야 합니다.\n데비안이나 우분투 계열에서는 'sudo apt-get install git'을 입력하면\ngit을 설치할 수 있습니다.\n\n");
	next_line();
	printf("자주 사용하는 git 명령어는 다음과 같습니다.\n");
	next_line();
	printf("git help\n\n");
	next_line();
	printf("[작업 영역 생성하기]\ngit init - 빈 git 저장소를 생성하거나 또는 git 저장소 초기화합니다.\ngit clone - 리포지토리를 로컬 디렉토리로 복제하여 가져옵니다.\n\n");
	next_line();
	printf("[현재 상태를 변화시키는 작업]\ngit add - 새로 생성되거나 수정된 파일을 git에 추가합니다.\ngit mv - 파일 또는 디렉토리, 심볼릭 링크를 이동하거나 이름을 변경합니다.\ngit reset - 현재 HEAD를 지정된 상태로 리셋합니다.\ngit rm  - 작업 트리와 인덱스 상에서 해당 파일을 삭제합니다.\n\n");
	next_line();
	printf("[history가 변경되는 작업]\ngit branch : 브랜치를 생성하거나 삭제합니다.\ngit checkout : 다른 브랜치로 전환하거나 작업 트리를 복원합니다.\ngit commit : 저장소에 대한 변경사항을 기록합니다.\ngit diff : 커밋과 작업 트리에 대한 변경 사항을 표시합니다.\ngit merge : 두개 이상의 개발 작업 히스토리를 병합합니다.\ngit rebase : 한 브랜치에서 다른 브랜치로 병합합니다.\ngit tag : 태그를 확인하거나, 태그를 붙이고 삭제합니다.\n\n");
	next_line();
	printf("[공동 작업]\ngit fetch : 리포지토리의 최신 정보를 로컬 저장소로 다운로드 합니다.\ngit pull : 리포지토리 또는 로컬 브랜치에서 최신 정보를 가져와 통합합니다.\ngit push : 로컬의 작업 상황을 원격 저장소에 반영하여 저장합니다.\n\n");
	next_line();
	printf("(예시로, 만약 깃을 처음 사용한다면 아래와 같이 작업합니다.)\ngit에 가입된 사용자가 있다면 conig를 수정하여 사용자명과 이메일 주소를 입력합니다.\ngit config --global user.name <사용자명>\ngit config --global user.email <이메일주소>\n\n");
	next_line();
	printf("레포지토리를 로컬 저장소로 다운받습니다.\ngit clone <주소>\n\n");
	next_line();
	printf("로컬 파일을 수정했다면 해당 파일을 업로드 대기 그룹에 추가시킵니다.\ngit add <파읾명>\n\n");
	next_line();
	printf("현재 대기 그룹에 저장된 목록이나 상태를 확인합니다.\ngit status\n\n");
	next_line();
	printf("대기 그룹에 모아둔 파일을 commit 메시지와 함께 로컬 브랜치에 등록합니다.\ngit commit -m \"commit message\"\n\n");
	next_line();
	printf("로컬 브랜치를 리모트 저장소에 push하여 저장합니다.\ngit push <remote> <branch>\n\n");
	next_line();
	printf("위의 명령어들은 glt 저장소를 만든 후 꼭 직접 실습해보시길 바랍니다.\n\n");

	printf("git에 대한 학습이 끝났습니다.\n\n");

}

