#include "common_func.h"

void training_curl(void)
{
	// 초기 작업 디렉토리 설정
	char def_dir[DIR_SIZE];
	// rst_dir은 앞에 mkdir, rm -rf의 명령어가 더 들어가기 때문에 문자열의 길이를 10 늘려줌
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];

	// 현재 사용자 계정을 %s 위치에 삽입하여 디폴트 디렉토리 설정
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	// 디폴트 디렉토리가 이미 있을 경우를 대비하여 삭제하는 명령어
	// rm -rf [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	// 디폴트 디렉토리를 생성
	// mkdir [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	// 디폴트 디렉토리로 change directory
	chdir(def_dir);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("이번에 학습할 명령어는 'curl'입니다.\n");
	getchar();
	printf("curl은 커맨드라인에서 URL을 통해 데이터를 전송하는 것에 사용합니다.\n");
	getchar();
	printf("먼저 curl을 통해 네이버의 URL인 'www.naver.com'에서 데이터를 받아보도록 하곘습니다.\n");
	getchar();
	printf("사용법은 아래와 같습니다\n$ curl [옵션] [URL]\n");
	getchar();
	printf("curl을 이용해 http://www.naver.com의 데이터를 받아보세요.(http 까지 모두 입력하세요)\n");
	run_command("curl http://www.naver.com");
	getchar();
	printf("몇 줄의 출력 결과가 나온 것을 확인할 수 있습니다.\n");
	getchar();
	printf("해당 출력 메시지는 HTTP 프로토콜과 관련된 메시지며, 302 Found라는 내용이 포함되었을 것입니다.\n");
	getchar();

	printf("'302 Found' 메세지는 해당 주소가 다른 주소로 변경되었음을 알려주고, 다른 주소의 정보가 존재한다는 의미입니다.\n");
	getchar();
	printf("즉, 여기서 제시된 다른 주소로 접속하면 된다는 의미입니다. 우리가 chrome과 같은 인터넷 브라우저로 접속했을 땐 이런 과정을 자동으로 수행합니다.\n");
	getchar();
	printf("하지만 curl에서는 따로 옵션을 주어 수행해야 합니다.\n");
	getchar();
	printf("이 때 사용하는 옵션이 바로 -L(Location의 약자)입니다.\n");
	getchar();
	printf("다시 한번 curl에 -L 옵션을 이용해 http://www.naver.com의 데이터를 받아오세요.\n");
	printf("$ curl [옵션] [URL]\n");
	run_command("curl -L http://www.naver.com");
	getchar();
	printf("이번에는 더 많은 데이터들이 출력되는 것을 확인할 수 있습니다. 이것이 바로 https://www.naver.com의 데이터입니다.\n");
	getchar();
	printf("실제로 웹 브라우저에서 http://www.naver.com을 입력하여 접속하려고 하면 https://www.naver.com으로 '리다이렉션'됩니다.\n");
	getchar();
	printf("이것은 http보다 https를 사용하는 프로토콜이 더 안전하기 때문에 해당 주소를 사용하도록 한 것입니다.\n");
	getchar();
	printf("-L 옵션을 통해 리다이렉션된 주소로 이동하여 curl을 받아왔기 때문에, 최종적인 결과는 curl https://www.naver.com이 됩니다.\n");
	getchar();

	printf("한편, curl을 통한 더 많은 정보를 얻고 싶을 때가 있습니다.\n");
	getchar();
	printf("이럴 때는 -v 옵션을 추가하여 수행하면 됩니다.\n");
	getchar();
	printf("다시 http://www.naver.com의 데이터를 curl을 통해서 받아오되 -v 옵션으로 추가적인 정보를 받아보세요.\n");
	printf("$ curl [옵션] [URL]\n");
	run_command("curl -v http://www.naver.com");
	getchar();
	printf("처음 curl을 통해 http://www.naver.com의 정보를 받아왔을 때 보다 다양한 정보가 출력됩니다.\n");
	getchar();
	printf("특히 눈여겨봐야 할 것은 Location 부분입니다.\n");
	getchar();
	printf("Location 부분이 'https://www.naver.com'으로 되어 있는 것을 확인할 수 있습니다.\n");
	getchar();
	printf("-L 옵션은 이러한 Location의 약자로, Location 정보를 따라서 리다이렉션된 URL로 접속을 시도합니다.\n");
	getchar();

	printf("curl은 단순히 데이터를 콘솔에 출력하는 역할도 있지만, 특정 URL을 통해 출력 결과나 파일을 다운로드 받을 수도 있습니다.\n");
	getchar();
	printf("이때 사용하는 옵션은 -o 옵션입니다. -o 옵션은 curl -o [저장할 파일 이름] [URL]의 형식으로 사용하면 됩니다.\n");
	getchar();
	printf("curl과 -o 옵션을 이용해 https://www.naver.com의 데이터를 'naver'라는 이름의 파일로 다운로드 해보세요.\n");
	printf("$ curl -o [저장할 파일 이름] [URL]\n");
	run_command("curl -o naver https://www.naver.com");
	getchar();
	printf("위에서 출력되는 메시지들은 curl을 통해 다운로드 되는 파일의 진행 사항입니다.\n");
	getchar();
	printf("지금 다운로드 받는 데이터는 텍스트 정보로 용량이 매우 작아 아주 빠르게 다운로드 되었지만, 용량이 큰 파일을 다운로드 받을 때는 진행 사항이 도움이 됩니다.\n");
	getchar();
	printf("ls를 통해 'naver' 파일이 생성된 것을 확인해보세요.\n");
	run_command("ls");
	getchar();
	printf("이번에는 cat을 이용해 'naver' 파일의 정보를 출력해보세요.\n");
	printf("$ cat [출력할 파일 이름]\n");
	run_command("cat naver");
	getchar();
	printf("위에서 curl을 통해 https://www.naver.com의 데이터를 받아왔을 때와 같은 출력 결과입니다.\n");
	getchar();
	printf("이처럼 curl을 통한 출력 결과를 -o 옵션을 통해 파일로 저장할 수도 있습니다.\n");
	getchar();
	printf("또한 특정 다운로드 링크를 URL로 지정하여 입력하면, 그 다운로드 링크를 통해 다운로드되는 파일을 받을 수도 있습니다.\n");
	getchar();
	printf("이번 학습에서는 curl을 통한 다운로드 위주로 살펴보았지만, curl로 파일을 업로드할 수도 있습니다.\n");
	getchar();
	printf("이 때는 -T 옵션을 사용하며 서버를 다루는 것에 숙련된다면 사용하게 될 옵션입니다.\n");
	getchar();
	printf("curl과 비슷한 명령어로는 'wget'이 있습니다. 둘의 사용법은 비슷하므로 하나만 배워도 숙지하기가 쉬울 것입니다.\n");
	getchar();
	printf("curl 학습이 끝났습니다.\n");
	
    // Delete default directory
	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}