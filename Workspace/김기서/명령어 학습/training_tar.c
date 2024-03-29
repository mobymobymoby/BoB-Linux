#include "func.h"

void training_tar()
{
	create_defdir();
	system("clear");
	
    system("touch file1 file2 file3");

	printf("이번에 학습할 명령어는 'tar'입니다.\n");
	printf("tar 명령어는 Tape ARchive의 약자로, 여러 파일들을 하나의 파일로 묶는 명령어 입니다.\n");
	next_line();
	printf("tar 명령어의 옵션은 아래와 같습니다.\n");
	printf("\t-c, --create : 새로운 tar 파일을 생성\n");
	printf("\t-f, --file : tar 파일의 이름을 지정\n");
	printf("\t-j, --bzip : bzip2를 이용한 압축\n");
	printf("\t-t, --list : tar 파일 내용을 출력\n");
	printf("\t-v, --verbose : 상세한 정보를 출력\n");
	printf("\t-x, --extract : tar 파일을 푼다.\n");
	printf("\t-z, --gzip : gzip을 이용한 압축\n");
	next_line();
	printf("tar 명령어는 단독으로 사용되거나 하나의 옵션만으로 사용되는 경우는 거의 없습니다.\n");
	printf("다양한 옵션의 조합으로 사용됩니다.\n");
	next_line();
	printf("대표적인 조합 두 가지는 아래와 같습니다.\n");
	printf("\t-cvf : 여러 파일을 하나의 tar 파일로 묶을 때 사용\n");
	printf("\t-xvf : 묶여있는 tar 파일을 풀 때 사용\n");
	printf("이 두 옵션은 잘 기억☆해주셨으면 합니다.\n");
	next_line();
	printf("tar 명령어는 다음과 같이 사용합니다.\n");
	printf("\t$ tar [옵션] 결과파일이름 묶을파일1 묶을파일2 ...\n");
	next_line();
	printf("tar -cvf 를 이용하여 file1, file2, file3를 'test.tar'로 묶어보세요.\n");
	run_command("tar -cvf test.tar file1 file2 file3");

	printf("이번에는 tar -lf 를 이용하여 'test.tar'의 내용을 확인해보세요.\n");
	run_command("tar -lf test.tar");
	
	printf("-lf 옵션을 사용하여 방금 전에 하나로 합친 파일 들을 볼 수 있습니다.\n");
	next_line();
	printf("그러면 다시 tar -xvf 를 이용하여 'test.tar'를 풀어봅시다.\n");
	run_command("tar -xvf test.tar");

	printf("단순히 tar 로 묶는 것으로는 압축은 되지 않습니다. tar는 어디까지나 묶어만 줍니다.\n");
	printf("압축은 -j 혹은 -z 옵션을 덧붙여서 이뤄집니다.\n");
	next_line();

	system("rm file1 file2 file3 test.tar");

	printf("tar 명령어에 대한 학습이 끝났습니다.\n");

	delete_defdir();
}