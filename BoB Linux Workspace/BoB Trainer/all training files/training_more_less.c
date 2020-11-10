#include "func.h"

void training_more_less()
{
	create_defdir();
	system("clear");

	FILE* fp = fopen("more.txt", "w");
	for(int i = 0; i < 10; i++)
	{
		fprintf(fp, "이것은 more 명령어의 테스트 파일 more.txt 입니다.\n\n");
		fprintf(fp, "more와 less로 내용을 보는 중에는 아래와 같은 입력을 통해서 제어할 수 있습니다.\n\n");
		fprintf(fp, "\tspace : 다음 페이지\n");
		fprintf(fp, "\tb : 이전 페이지\n");
		fprintf(fp, "\tq : 나가기\n\n");
	}
	fclose(fp);

	printf("이번에 학습할 명령어는 'more'와 'less'입니다.\n");
	printf("두 명령어 모두 파일의 내용을 화면에 출력하는 기능을 합니다.");
	next_line();
	printf("cat과 같은 명령어와 다른 점은 화면 단위, 페이지 단위로 보여준다는 점입니다.\n");
	printf("내용이 긴 파일을 cat을 이용하여 화면에 출력하면 터미널 화면을 초과하는 앞의 내용을 볼 수가 없는 단점이 있습니다.\n");
	printf("shift+PgUp, shift+PgDn 으로 넘길 수는 있으나 불편한 키 조합일 수도 있습니다.");
	next_line();
	printf("이럴 때 사용하는 것이 more와 less입니다.");
	printf("more는 화면 사이즈만큼, less는 페이지 단위로 출력합니다.");
	next_line();
	printf("more와 less로 내용을 보는 중에는 아래와 같은 입력을 통해서 제어할 수 있습니다.\n");
	printf("\tspace : 다음 페이지\n");
	printf("\tb : 이전 페이지\n");
	printf("\tq : 나가기");
	next_line();
	printf("more를 통해 more.txt를 읽어봅시다.\n");
	printf("이 후 space, b, q를 통해 화면을 넘겨보세요.");
	run_command("more more.txt");

	printf("추후 파이프라인| 이란것을 배우게 될 것입니다. 결과 내용이 너무 많아서 화면을 뚫고 나간다면 more을 활용하여 페이지를 넘겨가며 내용을 볼 수 있습니다.");
	next_line();

	printf("more 및 less 명령어에 대한 학습이 끝났습니다.\n");

	system("rm -f more.txt");

	delete_defdir();
}
