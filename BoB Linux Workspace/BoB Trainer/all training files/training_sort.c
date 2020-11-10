#include "func.h"

void training_sort()
{
	create_defdir();
	system("clear");

   	system("ls -f /etc > sort_test_file");

	printf("이번에 학습할 명령어는 'sort' 입니다. sort는 파일의 내용을 행 단위로 끊어서 정렬을 해줍니다. 정렬된 결과를 출력만 해줄 뿐, 따로 저장하거나 원본파일을 변경하지는 않습니다.");
	next_line();
	printf("sort 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("\t$ sort [옵션] 파일");
	next_line();
	printf("우선 cat으로 정렬 전의 'sort_test_file' 파일의 내용을 확인해봅시다.");
	run_command("cat sort_test_file");

	printf("이번엔 sort를 이용하여 'sort_test_file' 파일을 내용을 정렬시켜 확인해보세요.");
	run_command("sort sort_test_file");

	printf("sort 명령어의 옵션은 아래와 같습니다.\n");
	printf("\t-b : 공백은 무시\n");
	printf("\t-d : 사전 순으로 정렬\n");
	printf("\t-f : 대소문자 무시\n");
	printf("\t-n : 숫자를 기준으로 정렬\n");
	printf("\t-r : 내림차순으로 정렬");

	printf("sort 명령어는 정렬하여 출력만 해주므로, 파이프라인|  혹은 리다이렉션>  기법과 같이 많이 사용됩니다.");
	next_line();

	system("rm sort_test_file");

	printf("sort 명령어에 대한 학습이 끝났습니다.\n");

	delete_defdir();
}
