#include "func.h"

void training_group(void)
{
	create_defdir();

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("이번에 학습할 명령어는 그룹 관련 명령어들 입니다.\n");
	getchar();
	printf("그룹과 관련된 대표적인 명령어는'groups', 'groupadd', 'groupdel', 'gpasswd' 명령어가 있습니다.\n");
	getchar();
	printf("가장 먼저 배울 명령어는 'groups'입니다.\n");
	getchar();
	printf("groups 명령어는 매우 기초적인 명령어로 특정 계정이 속한 그룹 이름을 출력하는 명령어입니다.\n");
	getchar();
	printf("사용 방법은 매우 간단하며, 아래와 같습니다.\n");
	printf("$ groups [계정 이름]\n");
	getchar();
	printf("groups 명령어를 이용하여 'test' 계정이 속한 그룹을 출력해보세요.\n");
	fake_run_command("groups test");
	printf("test : tester\n");
	getchar();
	printf("출력 결과는 'test'라는 계정이 속한 그룹은 'tester'라는 의미입니다.\n");
	getchar();
	printf("groupadd 명령어는 새로운 그룹을 생성하는 명령어 입니다.\n");
	getchar();
	printf("사용법은 다음과 같습니다.\n");
	printf("$ groupadd [옵션] [생성할 그룹 이름]\n");
	getchar();
	printf("groupadd 명령어는 새로운 그룹을 생성하는 명령어기 때문에 관리자 권한을 가진 계정만이 사용할 수 있습니다.\n");
	getchar();
	printf("실습을 위해 잠시동안 관리자 권한을 부여하겠습니다.\n");
	getchar();
	printf("groupadd 명령어를 이용해 'test_group'이라는 그룹을 생성해보세요\n");
	fake_run_command("groupadd test_group");
	getchar();
	printf("그룹을 생성했을 땐 별 다른 메시지를 출력하진 않습니다.\n");
	getchar();
	printf("그룹의 목록은 그룹을 관리하는 파일인 /etc/group을 확인하면 됩니다.\n");
	getchar();
	printf("-g 옵션은 Group ID(GID)를 설정하여 그룹을 생성합니다.\n");
	getchar();
	printf("groupadd가 그룹을 생성하는 명령어라면, 그룹을 삭제하는 명령어는 groupdel 입니다.\n");
	getchar();
	printf("사용법은 다음과 같습니다.\n");
	printf("$ groupdel [옵션] [삭제할 그룹 이름]\n");
	getchar();
	printf("groupdel도 역시 관리자 권한을 가진 계정만이 사용할 수 있는 명령어입니다.\n");
	getchar();
	printf("마지막으로 gpasswd라는 명령어를 배워보겠습니다.\n");
	getchar();
	printf("gpasswd는 특정 그룹에 사용자를 포함시키거나 제외시킬 때 사용하는 명령어입니다.\n");
	getchar();
	printf("사용법은 아래와 같습니다.\n");
	printf("$ gpasswd [옵션] [대상 그룹 이름]\n");
	getchar();
	printf("-a 옵션은 특정 사용자를 그룹에 포함시킵니다. 다음과 같이 사용합니다.\n");
	printf("$ gpasswd -a [대상 계정명] [대상 그룹 이름]\n");
	getchar();
	printf("gpasswd와 -a 옵션을 이용해서 'test' 계정을 'test_group'에 포함시켜보세요.\n");
	fake_run_command("gpasswd -a test test_group");
	printf("Adding user test to group test_group\n");
	getchar();
	
	printf("다시 한 번 groups 명령어로 test 계정의 그룹 목록을 확인해보세요.\n");
	fake_run_command("groups test");
	printf("test : tester test_group\n");
	getchar();
	printf("'test' 계정의 그룹 목록에 test_group이 추가 된 것을 확인할 수 있습니다.\n");
	getchar();
	printf("이번 학습에서는 그룹 관련 명령어를 배워보았습니다. 여러 계정을 관리하는 관리자의 입장에서 유연한 계정 관리를 위해 그룹을 활용할 수 있습니다.\n");
	getchar();
	printf("그룹 관리 학습이 끝났습니다.\n");

    // Delete default directory
	delete_defdir();
}