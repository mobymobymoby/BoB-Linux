#include "func.h"

void training_nano(void)
{
	create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("nano 명령어는 nano 텍스트 편집기를 불러오는 명령어입니다.\n");
	next_line();
	printf("다른 유명한 텍스트 편집기로는 vi와 vim 등이 있으며,\n");
	printf("nano 에디터는 그 중에서 사용하기 수월한 편에 속합니다.\n");
	next_line();

	printf("'nano [파일 명]' 과 같이 입력하면 특정 파일을 nano 편집기로 열 수 있습니다.\n");
	printf("[실습] test 파일을 nano 편집기로 열어보세요.\n");
	printf("(명령어 실행 후 컨트롤+X를 눌러 빠져나오세요.\n");
	just_run_command("nano test");
	
	printf("nano 텍스트 편집기에서는 기본적으로 방향키로 문자, 라인 이동이 가능합니다.\n");
	next_line();
	printf("이번에는 텍스트를 입력하여 저장해보겠습니다.\n"); 
	next_line();
	printf("아까와 같이 nano [파일명]으로 텍스트 편집기를 킨 후\n원하는 내용을 적은 뒤에 컨트롤+X로 저장합니다.\n");
	next_line();
	printf("내용이 변경되게 되면 '수정한 버퍼 내용을 저장하시겠습니까?\n라는 확인을 하게 되고, y를 누르게 되면 저장할 이름을 정합니다.\n");
	next_line();
	printf("nano test로 'test'라는 파일을 열었기 때문에, \n저장할 이름은 기본적으로 'test'로 지정되어 있습니다.\n");
	next_line();
	printf("따라서 해당 파일에 저장하고 싶다면, 이름을 변경하지 않고\nEnter를 눌러 저장하면 됩니다.\n");
	next_line();
	printf("[실습] test 파일을 nano 편집기로 열어서 아무 내용이나 적어보세요.\n");
	printf("(컨트롤+x를 이용해 저장해주세요)\n");
	just_run_command("nano test");
	
	printf("[실습] test 파일의 내용을 cat [파일명]으로 확인해보세요.\n");
	just_run_command("cat test");
	printf("방금 입력한 내용이 출력됩니다.\n");
	next_line();
	printf("다음은 자주 사용하는 옵션들입니다.\n");
	printf("    nano -B [파일명] : 변경 이전 파일이 '[파일명]~'이름으로 백업됩니다.\n");
	printf("    nano -m [파일명] : 마우스를 사용합니다.\n");
	printf("    nano +[라인] [파일명] : 파일을 열자마자 특정 라인으로 이동합니다.\n");
	next_line();

	printf("nano 편집기 내에서도 다양한 기능들이 존재하는데, 다음과 같습니다.\n");
	printf("\n");
	printf("[부가 기능]\n");
	printf("    ctrl+g (F1) : 도움말 표시\n");
	printf("    ctrl+x (F2) : nano 종료\n");
	printf("    ctrl+o (F3) : 파일 저장\n");
	next_line();

	printf("[유용한 기능]\n");
	printf("    ctrl+w (F6) : 문자 검색\n");
	printf("    ctrl+\\ : 문자 검색 후 수정\n");
	printf("    ctrl+k (F9) : 현재 줄 잘라내기\n");
	printf("    ctrl+u : 이전에 자른 줄을 붙여넣기\n");
	printf("    alt+] : 현재 괄호에 매칭되는 괄호 찾기\n");
	printf("            (코딩시 유용하게 사용될 수 있음)\n");
	next_line();

	printf("[라인 이동]\n");
	printf("    ctrl+y (F7) : 이전 화면으로 이동\n");
	printf("    ctrl+v (F8) : 다음 화면으로 이동\n");
	printf("    ctrl+a : 현재 라인의 시작 위치로 이동\n");
	printf("    ctrl+e : 현재 라인의 끝 위치로 이동\n");
	printf("    alt+( : 현재 문단의 시작으로 이동\n");
	printf("    alt+) : 현재 문단의 끝으로 이동\n");
	printf("    alt+\\ : 파일의 첫 라인으로 이동\n");
	printf("    alt+/ : 파일의 마지막 라인으로 이동\n");
	next_line();
	printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
	printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
	next_line();
	printf("\"nano\" 명령어의 학습이 끝났습니다.\n");
	printf("고생하셨습니다.\n");
	
	delete_defdir();
}
