#include "func.h"

void training_sort()
{
	create_defdir();
	system("clear");

   	system("ls -f /etc > testfile");

	printf("이번에 학습할 명령어는 'sort' 입니다. \n");
	next_line();
	printf("sort는 파일의 내용을 행 단위로 끊어서 정렬을 해줍니다.\n\n");
	printf("하지만, 옵션 없이 사용시 정렬된 결과를 출력만 해줄 뿐, \n따로 저장하거나 원본 파일을 변경하지는 않습니다.\n");
	next_line();
	printf("sort 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ sort [옵션] 파일\n");
	next_line();
	printf("[실습] 우선 cat으로 정렬 전의 'testfile' 파일의 내용을 확인해봅시다.\n");
	just_run_command("cat testfile");

	printf("[실습] 이번엔 sort를 이용하여 'testfile' 파일을 내용을 정렬시켜 확인해보세요.\n");
	just_run_command("sort testfile");

	printf("\nsort 명령어의 옵션은 아래와 같습니다.\n\n");
	printf("\t-b : 공백은 무시\n");
	printf("\t-d : 사전 순으로 정렬\n");
	printf("\t-f : 대소문자 무시\n");
	printf("\t-n : 숫자를 기준으로 정렬\n");
	printf("\t-r : 내림차순으로 정렬\n");
	printf("\t-o : 정렬된 내용을 지정된 파일명에 저장\n\n");
	
	printf("-o 옵션을 이용해 정렬된 내용을 특정 파일에 저장할 수 있습니다.\n");
	next_line();
	printf("사용법은 다음과 같습니다.\n");
	printf("$ sort -o [원본 파일] [대상 파일]\n");
	next_line();
	printf("원본 파일에 있는 내용이 정렬되어 대상 파일에 저장됩니다.\n");
	next_line();
	printf("따라서 원본 파일의 내용을 정렬시켜 저장하고 싶다면, \n원본 파일과 대상 파일을 같게 지정하면 됩니다.\n");
	next_line();
	printf("[실습] sort와 -o 옵션을 이용해 'testfile'을 정렬하여 원본 파일에 저장해보세요.\n");
	printf("$ sort -o [원본 파일] [대상 파일]\n");
	run_command("sort -o testfile testfile");
	next_line();
	printf("[실습] cat으로 정렬 후의 'testfile' 파일의 내용을 확인해봅시다.\n");
	just_run_command("cat testfile");
	printf("파일의 내용이 정렬되어 저장된 것을 확인할 수 있습니다.\n");
	next_line();
	printf("sort 명령어는 파이프라인(|) 혹은 리다이렉션(>) 기호와 같이 자주 사용됩니다.\n");
	next_line();
	printf("예를 들어 sort [원본 파일] > [대상 파일]과 같이 사용하는 것은\nsort -o [원본 파일] [대상 파일]과 같은 결과입니다.\n");
	next_line();
	printf("sort 명령어를 잘 사용한다면 특정한 데이터를 다루기에 좋을 것입니다.\n");
	next_line();
	printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
	printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
	next_line();
	printf("\"sort\" 명령어의 학습이 끝났습니다.\n");
	printf("고생하셨습니다.\n");

	system("rm sort_test_file");

	delete_defdir();
}
