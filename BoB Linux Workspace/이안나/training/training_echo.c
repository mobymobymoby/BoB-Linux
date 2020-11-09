#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_echo(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("이번에 학습할 명령어는 'echo' 입니다.\n\n");
	next_line();
	printf("echo는 터미널의 콘솔에 해당하는 텍스트를 라인으로 출력합니다.\n\n");
	next_line();
	printf("echo 명령어는 다음과 같은 형식으로 사용합니다.\n$ echo [options] 문자열\noption은 선택 사항이며 해당 명령어에 지정할 옵션,\n문자열은 echo 명령을 통해 출력할 텍스트를 의미합니다.\n\n");
	next_line();
	printf("echo에서 자주 사용하는 옵션은 다음과 같습니다.\n -n : 개행 문자를 출력하지 않게 합니다.\n -e : 이스케이프 문자를 인식할 수 있도록 합니다.\necho 명령은 이스케이프 문자를 인식할 수 없는 것이 기본 값입니다.\n\n");
	next_line();
	printf("개행 문자란 줄의 맨 끝에서 줄바꿈 역할을 해주는 new line을 의미하고,\n이스케이프 문자란 기본적인 역할이 정의되어 있어 사용하지 못하는 특수 문자를\n백 슬래시'\'와 붙여 사용 할 수 있도록 만든 문자를 의미합니다.\n\n");
	next_line();
	printf("그럼 echo 명령을 사용해 문자열 'hello'를 출력하도록 입력해보세요.\n");

	run_command("echo hello");

	next_line();
	printf("명령어가 성공적으로 동작했다면 터미널 창에 'hello'가 띄워졌을 것입니다.");
	next_line();
	printf("\necho 명령어에 대한 학습이 끝났습니다. \n");

	delete_defdir();
}
