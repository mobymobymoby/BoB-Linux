#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_set_unset(void)
{
	create_defdir();

	//////////////////////////////////////////////////////////////////////////////////////////////////////


	printf("이번에 학습할 명령어는 'set, unset'입니다.\n\n");
	next_line();

	printf("set은 현재 정의되어 있는 모든 변수(환경 변수, 셸 변수)와 그 값을 출력하고,\n변수의 값을 설정하는 명령어 입니다.\nunset은 선언된 변수를 제거하는 명령어입니다.\n\n");
	next_line();

	printf("환경 변수는 셸의 환경을 정의하는 중요한 역할을 수행하는 변수이며 미리 예약된 변수 명을 사용합니다.\n셸 변수란 특정한 셸에서만 적용되는 변수입니다.\n환경 변수는 현재 셸 뿐만 아니라 서브 셸에서도 적용이 되므로, 셸 변수보다 적용 범위가 넓습니다.\n\n");
	next_line();

	printf("set 명령어는 다음과 같은 형식으로 사용합니다.\n$ set\n현재 환경 변수와 셸 변수 목록을 출력합니다.\n\n");
	next_line();

	printf("unset 명령어는 다음과 같은 형식으로 사용합니다.\n$ unset NAME\nNAME이라는 변수 명으로 선언된 변수가 제거됩니다.\n\n");
	next_line();

	printf("그럼 우선 셸 변수를 선언해봅시다.\n\n");
	next_line();

	printf("'myVal=value'를 입력해 'myVal'의 변수 명으로 'value' 이라는 값을 저장하도록 선언해보세요.\n\n");
	run_command("myVal=value");
	next_line();

	printf("'set'을 입력하면 현재 선언된 많은 변수들이 출력될 것 입니다.\n'set'을 입력해보세요\n\n");
	run_command("set");
	next_line();

	printf("이제 unset 명령어를 사용해 셸 변수를 해제해봅시다.\nunset 명령어를 입력해 'myVal' 변수를 제거해보세요.\n\n");
	run_command("unset myVal");
	next_line();

	printf("unset을 입력하면 셸 변수 목록에서 성공적으로 제거되었을 것입니다.\n\n");
	next_line();

	printf("\nset, unset 명령어에 대한 학습이 끝났습니다. \n");


	delete_defdir();
}
