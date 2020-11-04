#include "common_func.h"

void training_make()
{
	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];

	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	chdir(def_dir);
    
    printf("이번에 학습할 명령어는 'make'입니다. make는 여러 소스파일의 빌드 작업은 간소화 시켜줍니다.");
    getchar();
    printf("예를 들어 foo.c 와 main.c 가 있다고 가정해봅시다.");
    getchar();
    printf("터미널에서 이 들을 빌드하려면");
    printf("\t$ gcc -c foo.c\n");
    printf("\t$ gcc -c main.c\n");
    printf("\t$ gcc -o foo foo.o main.o\n");
    printf("와 같이 입력해야 합니다.");
    getchar();
    printf("하지만 코드가 수정되었다면?\n");
    printf("또 저 짓을 반복해야 합니다.");
    getchar();
    printf("게다가 프로젝트의 크기가 커지면 소스 코드의 수도 많아지게 됩니다.\n");
    printf("수 십, 수 백 개의 파일을 gcc 한 줄 한 줄 치다보면 미치기 마련입니다.");
    getchar();
    printf("겨우 다 했는데 코드가 수정되었다?\n");
    printf("난 죽음을 택하겠다!");
    getchar();
    printf("이런 재앙을 막기위해 위대하신 프로그래머님들께서 make라는 획기적인 도구를 만들어 주셨습니다.");
    getchar();
    printf("make는 해당 폴더 안에서 'Makefile'이란 이름을 가진 파일을 찾습니다.\n");
    printf("그렇기 때문에 우선 Makefile 을 작성하여야 합니다.");
    getchar();
    printf("위에서 언급한 foo.c 와 main.c 를 빌드하는 Makefile 을 아래와 같이 작성했습니다.\n");
    printf("\tfoo: foo.o main.o\n");
    printf("\t\tgcc -o foo foo.o main.o\n\n");
    printf("\tfoo.o: foo.c\n");
    printf("\t\tgcc -c foo.c\n\n");
    printf("\tmain.o: main.c\n");
    printf("\t\tgcc -c main.c\n");
    getchar();
    printf("Makefile 은 두 줄 정도 단위인 Rule Block 으로 이루어집니다.\n");
    printf("위의 Makefile 예제와 아래의 Rule Block 공식을 잘 비교해보세요.\n");
    printf("\t[target]: [dependency]\n");
    printf("\t\t[command]\n");
    printf("target: 타겟, 블록 이름\n");
    printf("dependency: 실행에 필요한 파일 등의 의존성 목록");
    printf("command: 실행할 명령문");
    getchar();
    printf("target 과 dependency 는 콜론: 이 사이에 있고 command는 tab으로 들여쓰기가 되어야 합니다. 꼭 기억해 주세요!");
    getchar();

    printf("그럼 다시 예제로 돌아와서\n");
    printf("make를 통해 빌드를 하고 나면 .o 파일들과 실행파일이 생성됩니다.");
    getchar();
    printf("나중에 되면 소스코드만을 필요로 하기 때문에 이를 한 큐에 정리할 필요가 있습니다.\n");
    printf("그러기 위해 관습적으로 'clean'이란 타겟을 만들어 놓습니다.");
    getchar();
    printf("아래와 같이 clean 타겟을 기존의 Makefile 에 추가하였습니다.\n");
    printf("\tclean:\n");
    printf("\t\trm -f foo foo.o main.o\n\n");
    getchar();
    printf("이후 clean 타겟 수행을 위해서는\n");
    printf("\t$ make clean\n");
    printf("라고 입력하면 됩니다.");
    getchar();

    printf("다른 사람들이 작성한 Makefile 을 보게 되면 매크로를 사용하여 Makefile 의 내용도 줄인 것을 볼 수 있을 겁니다.\n");
    printf("여기에서는 Makefile의 매크로까지는 다루지 않겠습니다.");
    getchar();

    printf("make 명령어에 대한 학습이 끝났습니다.\n");

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}