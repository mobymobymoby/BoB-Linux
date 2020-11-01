#include <stdio.h>

void training_clear()
{
	printf("이번에 학습할 명령어는 'clear' 입니다. 말그대로 지우다(clear), 터미널 화면을 싹 지워줍니다.");
	getchar();
	printf("바로 clear를 입력해봅시다.");
	run_command("clear");

	printf("위에 있던 내용들이 다 지워졌나요? 어떤가요, 정말 쉽죠?");
	getchar();
	printf("항상 새 것과 같은 터미널에서 작업하고 싶다면 clear를 기억해주세요!");
	gethar();
	printf("Ctrl + L 로도 지울 수 있답니다.");
	getchar();

	printf("clear 명령어에 대한 학습이 끝났습니다.\n");
}