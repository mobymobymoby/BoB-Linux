#include "func.h"

void training_rm()
{
	create_defdir();
	system("clear");

    	system("touch rm_test_file");
    	system("mkdir rm_test_dir");

	printf("이번에 학습할 명령어는 'rm'입니다. rm 명령어는 ReMove의 약자로, 파일을 삭제하는 명령어입니다.\n");
	next_line();
	printf("rm 실습에 앞서서, rm을 진행하기 위해서는 \n어떤 파일이 있는지 확인해봐야겠죠?\n");
	printf("[실습] 'ls -al'을 입력하여 현재 디렉토리에 있는 파일의 정보를 확인하세요.\n");
	just_run_command("ls -al");
	printf("'rm_test_file'은 일반 파일, \n'rm_test_dir'는 디렉토리임을 확인할 수 있습니다.\n"); 
	next_line();
	printf("rm 명령어는 다음과 같은 형식으로 사용합니다.\n");
	printf("$ rm [옵션] 삭제할 파일 이름\n");
	next_line();
	printf("[실습] rm 명령어를 입력하여 'rm_test_file' 파일을 삭제해보세요.\n");
	run_command("rm rm_test_file");

	printf("rm 명령어의 옵션은 아래와 같습니다.\n");
	printf("-f, --force       : 강제 삭제\n");
	printf("-i, --interactive : 삭제 시 확인 절차를 거침\n");
	printf("-r, --recursive   : 디렉토리를 포함하여 삭제\n");
	printf("-v, --verbose     : 삭제 파일의 정보를 화면에 출력\n");
	next_line();
	printf("그냥 rm 만을 사용하면 디렉토리는 삭제를 할 수 없습니다. -r 혹은 -R 옵션을 주어야만 디렉토리 삭제가 가능합니다.\n");
	next_line();
	printf("rm -r 을 이용하여 'rm_test_dir' 디렉토리를 삭제해보세요.\n");
	run_command("rm -r rm_test_dir");
    
	printf("rm 명령어는 파일을 삭제할 수 있기 때문에 항상 조심히 사용하여야 합니다. 한 번 삭제된 것은 돌아오지 않습니다.\n");
	next_line();
	printf("물론 자신에게 권한이 없는 파일도 삭제가 불가능합니다.\n");
	next_line();
		       
	printf("rm과 유사한 명령어로는 'rmdir'가 있습니다.\n");
	printf("rmdir는 remove directory로 디렉토리를 지운다는 점에서 rm -r 옵션과 유사합니다.\n");
	next_line();
	
	printf("이후에 콘솔 혹은 터미널에 \"man\"명령어나 \"[명령어] --help\"와 같이 '--help' 옵션을 통해\n");
    	printf("더 많은 정보와 옵션들을 확인하시길 바랍니다.\n");
    	next_line();
	
	printf("rm 명령어에 대한 학습이 끝났습니다.\n고생하셨습니다.");

	delete_defdir();
}