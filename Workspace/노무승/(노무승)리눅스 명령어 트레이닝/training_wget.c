#include "func.h"

void file_check(){ 
    int Result = access("./index.html", 0 ); // unistd.h
    if (Result == 0) remove("./index.html"); // stdio.h
} // 파일 존재 확인 후, 존재시 삭제

void training_wget(void)
{
    create_defdir();
	system("clear");
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("wget 명령어는 웹 상에 있는 파일을 다운받는 명령어이며,\n");
    printf("지원되는 프로토콜은 HTTP, HTTPS, FTP가 있습니다.\n");
    next_line();

    printf("기본적으로 웹 상에 있는 파일을 다운받을 때는\n");
    printf("'wget [URL 링크]'와 같이 사용합니다.\n");
    next_line();

    printf("[실습] 네이버(https://www.naver.com)의 웹 페이지 파일을 다운받아보세요.\n");
    file_check();
    run_command("wget https://www.naver.com");
    next_line();
    // 트레이닝 시작

    printf("[기타 유용한 옵션들]\n");
    printf("wget -c [URL] : 파일 이어받기\n");
    printf("wget -0 [URL] : 파라미터 형태의 링크에서 파일 다운로드\n");
    printf("wget -r [URL] : 디렉터리 구조를 유지한채 다운로드\n");
    printf("wget -nd -r --accept=[확장자] [URL] : 특정 확장자 파일만 다운로드\n");
    printf("wget -nd -r --reject=[확장자] [URL] : 특정 확장자 파일만 빼고 다운로드\n");
    next_line();
    printf("이와 같이 옵션을 사용하면 더욱 유용하게 활용할 수 있습니다.\n");
    next_line();

    delete_defdir();
    printf("고생하셨습니다!\n");
}
