#include "func.h"

void training_more_less()
{
	create_defdir();
	system("clear");

	FILE* fp = fopen("more.txt", "w");
	for(int i = 0; i < 10; i++)
	{	
		fprintf(fp, "[%d 페이지]\n\n", i+1);
		fprintf(fp, "이것은 more 명령어의 테스트 파일 more.txt 입니다.\n\n");
		fprintf(fp, "more와 less로 내용을 보는 중에는 아래와 같은 입력을 통해서 제어할 수 있습니다.\n\n");
		fprintf(fp, "\tspace : 다음 페이지\n");
		fprintf(fp, "\tb : 이전 페이지\n");
		fprintf(fp, "\tq : 나가기\n\n");
	}
	fclose(fp);

	printf("이번에 학습할 명령어는 'more'와 'less'입니다.\n");
	printf("두 명령어 모두 파일의 내용을 화면에 출력하는 기능을 합니다.\n");
	next_line();
	printf("cat과 같은 명령어와 다른 점은 화면 단위, 페이지 단위로 보여준다는 점입니다.\n");
	next_line();
	printf("내용이 긴 파일을 cat을 이용하여 화면에 출력하면 \n터미널 화면을 초과하는 앞의 내용을 보기 힘든 단점이 있습니다.\n");
	printf("<Shift+PgUp>, <Shift+PgDn> 으로 넘길 수는 있으나 아무래도 불편함이 있습니다.\n");
	next_line();
	printf("이럴 때 사용하는 것이 more와 less입니다.\n");
	printf("more는 화면 사이즈만큼, less는 페이지 단위로 출력합니다.\n");
	next_line();
	printf("more와 less로 내용을 보는 중에는 아래와 같은 입력을 통해서 제어할 수 있습니다.\n\n");
	printf("\t[space : 다음 페이지]\n");
	printf("\t[b : 이전 페이지]\n");
	printf("\t[q : 나가기]\n");
	next_line();
	printf("[실습] more를 통해 more.txt를 읽어봅시다.\n");
	printf("$ more [파일명]\n");
	printf("이 후 space, b, q를 통해 화면을 넘겨보세요.\n");
	just_run_command("more more.txt");

	printf("파이프라인(|)을 배웠다면, 출력된 결과 내용이 너무 많아서 읽기가 어려울 때 \nmore을 활용하여 페이지를 넘겨가며 내용을 볼 수 있습니다.\n");
	next_line();
	printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
	printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
	next_line();
	printf("\"more, less\" 명령어의 학습이 끝났습니다.\n");
	printf("고생하셨습니다.\n");

	system("rm -f more.txt");

	delete_defdir();
}
