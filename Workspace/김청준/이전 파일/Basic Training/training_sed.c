#include "func.h"

void training_sed(void)
{
	create_defdir();
	system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    	system("echo '1번째 줄 : Welcome to BoB-Linux' >> textfile");
	system("echo '2번째 줄 : This is sed training' >> textfile");
	system("echo '3번째 줄 : Black Moon' >> textfile");
	system("echo '4번째 줄 : My name is KCJ' >> textfile");
	system("echo '5번째 줄 : hello' >> textfile");
	system("echo '' >> textfile");
	system("echo '7번째 줄 : hello world' >> textfile");
	system("echo '8번째 줄 : hi world' >> textfile");
	system("echo '9번째 줄 : ' >> textfile");
	system("echo '마지막 줄' >> textfile");
	
	printf("이번에 학습할 명령어는 'sed'입니다.\n");
	printf("sed는 파일의 내용을 출력하는데 쓰이는 유용한 명령어입니다.\n");
	next_line();
	printf("sed 명령어를 통해 수행한 출력 결과는 원본에 반영되지 않습니다.\n");
	printf("따라서 원본을 유지한 채 원하는 텍스트가 있는 줄(Line)을 찾거나 치환할 때 사용합니다.\n");
	next_line();
	printf("먼저 이번 학습에서 사용할 파일인 'textfile'의 내용을 cat을 통해 보여드리겠습니다.\n");
	next_line();
	system("cat textfile");
	printf("총 10개의 줄이 있으며, 6번째 줄은 공백으로 비어 있는 줄입니다.\n");
	next_line();
	printf("sed의 기본적인 사용 방법은 p(print의 약자)를 이용해 파일의 내용을 출력하는 것입니다.\n");
	printf("사용법은 다음과 같습니다.\n$ sed [옵션] '[출력할 줄 번호]p' [파일의 이름]");
	printf("만약 'test'라는 파일의 5번째 줄을 출력하고 싶다면\n\"sed '5p' test\"라고 입력하면 됩니다.\n");
	next_line();
	printf("sed를 이용해 'textfile' 파일의 2번째 줄을 출력(p)해 보세요.\n");
	printf("$ sed '[출력할 줄 번호]p' [파일의 이름]\n");
	run_command("sed '2p' textfile");
	next_line();
	printf("textfile의 2번째 줄의 내용이 정상적으로 출력된 것을 확인할 수 있습니다.\n");
	printf("특이한 점은 textfile의 전체 내용이 출력됨녀서 2번째 줄이 두 번 출력되었다는 것입니다.\n");
	next_line();
	printf("sed 명령어를 -n 옵션 없이 출력(p)하게 되면 대상 파일의 전체 내용을 출력하면서 해당하는 줄의 내용이 한번 더 출력됩니다.\n");
	printf("보통 자신이 원하는 라인만 출력하기 위해 -n 옵션을 더해서 사용합니다.\n");
	next_line();
	printf("sed와 -n 옵션을 이용해 textfile 파일의 2번째 줄을 출력(p)해 보세요.\n");
	printf("$ sed [옵션] '[출력할 줄 번호]p' [파일의 이름]\n");
	run_command("sed -n '2p' textfile");
	next_line();
	printf("-n 옵션을 붙여 2번째 줄만 출력이 된 모습입니다.\n");
	next_line();
	printf("지금까지는 하나의 줄만 대상으로 하였지만, 여러 가지 줄을 한 번에 출력할 수도 있습니다.\n");
	printf("2~5번째 줄 까지 출력하기 위해서는 '2,5p'와 같이 입력하면 됩니다.\n");
	next_line();
	printf("sed와 -n 옵션을 이용해 textfile 파일의 2~5번째줄을 출력(p)해 보세요.\n");
	printf("$ sed [옵션] '[출력할 줄 번호]p' [파일의 이름]\n");
	run_command("sed -n '2,5p' textfile");
	next_line();
	printf("2~5번째 줄이 정상적으로 출력되었습니다.\n");
	next_line();
	printf("또한 sed 명령어에서 '$'라는 문자는 마지막 줄을 뜻합니다. '$'라는 문자는 정규 표현식의 메타 문자중 하나이며, 문자열의 끝을 의미합니다.\n");
	printf("따라서 만약 3번째줄 부터 마지막 줄 까지 출력하고 싶다면 '3,$p'라고 입력하면 됩니다.\n");
	next_line();
	printf("sed와 -n 옵션을 이용해 textfile 파일의 3~마지막 줄을 출력(p)해 보세요.\n");
	printf("$ sed [옵션] '[출력할 줄 번호]p' [파일의 이름]\n");
	run_command("sed -n '3,$p' textfile");
	next_line();
	printf("만약 2번째줄과 4~7번째 줄을 출력하고 싶다면 어떻게 해야 할까요?\n");
	next_line();
	printf("-e 옵션을 추가하면 됩니다.\n");
	next_line();
	printf("sed -n -e '2p' -e '4,7p'와 같이 사용하면 2번째줄과 4~7번째줄을 동시에 출력할 수 있습니다.\n");
	printf("sed와 -n, -e 옵션을 이용해 textfile 파일의 4번째 줄과 7~9번째 줄을 동시에 출력(p)해 보세요.\n");
	printf("$ sed -n -e '[출력할 줄 번호]p' -e '[출력할 줄 번호]p' [파일의 이름]\n");
	run_command("sed -n -e '4p' -e '7,9p' textfile");
	next_line();
	printf("정상적으로 출력되었습니다.\n점점 사용법이 복잡해지기 시작합니다. 하지만 익숙해지면 매우 유용하게 사용할 수 있게 될 것입니다.\n");
	next_line();

	printf("지금까지는 줄 번호를 입력하여 출력헀지만, 특정 단어가 있는 줄 만을 출력할 수도 있습니다.\n");
	printf("예를 들어 hello라는 단어는 5번째줄과 7번째줄에 존재합니다.\n");
	next_line();
	printf("만약 hello라는 단어가 있는 모든 줄을 출력하기 위해서는 sed -n '/hello/p' [파일 이름]과 같이 입력하면 됩니다.\n");
	printf("sed와 -n 옵션을 이용해 textfile 파일의 'hi'라는 단어가 포함된 줄을 출력(p)해 보세요.\n");
	printf("$ sed [옵션] '/찾을 단어/p' [파일의 이름]\n");
	run_command("sed -n '/hi/p' textfile");
	next_line();

	printf("hi라는 단어가 포함된 줄만 출력된 것을 확인할 수 있습니다. 2번째 줄에는 'This'라는 문자열에 'hi'가 포함되어 출력되었습니다.\n");
	printf("방금전에 보았던 메타 문자인 '$'처럼 '^' 또한 메타 문자로, 문자열의 처음을 나타냅니다.\n");
	next_line();
	printf("^ 문자를 이용하여 특정 문자열로 시작하는 줄을 출력할 수 있습니다.\n");
	printf("2번째 줄은 '2'라는 문자로 시작하기 때문에 sed -n '/^2/p' textfile을 통해 2번째 라인을 출력할 수 있습니다.\n");
	next_line();
	printf("sed와 -n 옵션을 이용해 textfile 파일의 '1'으로 시작하는 줄을 출력(p)해 보세요.\n");
	printf("$ sed [옵션] '/^[시작하는 문자열 또는 문자]/p' [파일의 이름]\n");
	run_command("sed -n '/^1/p' textfile");
	next_line();
	printf("1번째 줄이 '1'이라는 문자로 시작하기 때문에 출력되었습니다.\n");
	next_line();
	printf("한편, 특정 문자열로 끝나는 줄을 출력할 수도 있습니다.\n");
	printf("이 때는 아까도 보았던 '$' 메타 문자가 사용됩니다.\n");
	printf("sed -n '/[끝나는 문자열]$/p'와 같이 입력하면 됩니다.\n");
	next_line();
	printf("이번에는 '$' 메타 문자를 이용해 'world'라는 문자열로 끝나는 줄을 출력해 보세요\n");
	printf("$ sed -n '/[끝나는 문자열 또는 문자]$/p' [파일의 이름]\n");
	run_command("sed -n '/world$/p' textfile");
	next_line();
	printf("지금은 메타 문자와 sed의 혼합 사용법이 복잡하지만, 리눅스를 사용하면서 금방 익숙해질 것입니다.\n");
	next_line();

	printf("지금까지는 p를 통한 출력에 대해서 알아보았지만, 'd'를 이용해서 특정 줄을 제외할 수도 있습니다.\n");
	printf("sed '3d' textfile은 textfile의 3번째 줄을 지우는 것을 의미합니다.\n");
	next_line();
	printf("sed 명령어는 -n과 쓰지 않았을 때 전체 파일의 내용을 출력해주는 것을 아까도 확인할 수 있었습니다.\n");
	printf("p 옵션에서는 -n 옵션과 함께 사용하여 전체 내용이 출력되면서 특정 줄의 내용이 한번 더 출력되는 것을 막았습니다.\n");
	next_line();
	printf("하지만 d 옵션에서는 특정 라인의 내용만 출력되지 않고 나머지 내용이 출력되는 방식이기 때문에 -n 옵션을 사용할 필요가 없습니다.\n");
	next_line();
	printf("sed를 이용해'textfile' 파일의 2번째 줄을 제거해 출력해 보세요.\n");
	printf("$ sed '[제거할 줄 번호]d' [파일의 이름]\n");
	run_command("sed '2d' textfile");
	next_line();
	
	printf("2번째 줄의 내용이 제외되어 출력되는 것을 확인할 수 있습니다.\n");
	printf("메타 문자들과 d를 이용해 비어있는 줄을 삭제할 수도 있습니다.\n");
	next_line();
	printf("sed '/^$/d' [파일명]의 형식으로 사용하면, 비어있는 줄을 제외한 줄 만을 출력합니다.\n");
	printf("하지만 d 옵션으로 원본의 내용이 삭제된 것은 아닙니다. 다만 원본의 내용이 출력된 결과가 변경된 것입니다.\n");
	next_line();
	printf("그러나 실제로 원본의 내용에 변한 내용을 반영하여 저장하고 싶을 때가 있을 것입니다.\n");
	printf("이 때에는 리다이렉션 기호인 '>'를 사용합니다.\n'>'기호 기준으로 오른쪽에 있는 것이 새롭게 저장할 파일이 됩니다.\n");
	next_line();
	printf("이번에는 textfile의 2번째 줄을 제외한 내용을 실제로 'new_textfile'에 저장해보세요.\n사용법은 다음과 같습니다.\n");
	printf("$ sed '[제외할 줄 번호]d' [파일명] > [저장할 파일명]\n");
	run_command("sed '2d' textfile > new_textfile");
	next_line();
	printf("cat을 이용해 new_textfile의 내용을 보여드리겠습니다.\n");
	next_line();
	system("cat new_textfile");
	next_line();
	printf("2번째 줄의 내용이 사라졌습니다. 리다이렉션은 출력 결과를 실제로 반영할 수 있는 기능으로 이처럼 유용하게 사용할 수 있습니다.\n");
	next_line();

	printf("이번에는 sed의 유용한 기능 중 하나인 치환 기능을 알아보도록 하겠습니다.\n");
	printf("치환이란 특정 문자열이나 문자를 다른 문자열이나 문자로 바꾸는 것을 의미합니다.\n");
	next_line();
	printf("치환을 위한 옵션은 s입니다.\n");
	printf("치환은 다음과 같은 형식으로 사용합니다.\n");
	next_line();
	printf("$ sed 's/대상 문자열/변경할 문자열/' [파일명]\n");
	printf("위와 같이 입력하면 대상 문자열의 내용이 변경할 문자열로 변경됩니다.\n");
	next_line();
	printf("예를 들어 sed 's/better/best/' [파일명]과 같이 입력하면, [파일명]의 전체 내용 중 각 행의 첫번째 'better'라는 문자열이 'best'로 변경됩니다.\n");
	next_line();
	printf("즉 첫번째 줄의 내용이 만약 \"bob is better of the better\"라는 내용이었고, sed 's/better/best/' [파일명]과 같이 입력했다면\n");
	printf("bob is best of the better와 같이 변경됩니다..\n");
	next_line();
	printf("만약 각 행의 해당하는 첫번째 문자열 만이 아닌 해당하는 모든 문자열을 변경하고 싶다면, 's/better/best/g'와 같이 입력하면됩니다.\n");
	printf("즉 sed 's/better/best/g' [파일명] 처럼 입력했다면 변경된 내용은 \"bob is best of the best\"가 됩니다.\n");
	next_line();

	printf("이번에는 textfile에 내용을 직접 치환하도록 하겠습니다.\n");
	next_line();
	printf("s 옵션을 이용하여 textfile의 'hello'라는 문자열을 'good'으로 바꿔보세요. 단 각 행의 첫번째 일치하는 문자열만 바뀌도록 해보세요.\n");
	printf("$ sed 's/대상 문자열/변경할 문자열/' [파일명]\n");
	run_command("sed 's/hello/good/' textfile");
	next_line();
	printf("hello라는 문자열이 정상적으로 good으로 바뀌었습니다.\n");
	next_line();
	printf("마지막으로 치환된 내용을 리 다이렉션(>)을 이용해 원본 파일에 반영해보도록 하곘습니다.\n");
	next_line();
	printf("s 옵션을 이용하여 textfile의 'l'라는 문자를 'here'로 바꿔 new_textfile에 저장해보세요. 단 일치하는 모든 문자가 바뀌도록 해보세요.\n");
	printf("$ sed 's/대상 문자열/변경할 문자열/g' [파일명] > [파일명]\n");
	run_command("sed 's/l/here/g' textfile > new_textfile");
	next_line();

	printf("변경된 내용을 확인하기 위해 cat new_textfile을 입력해보세요.\n");
	run_command("cat new_textfile");
	next_line();
	printf("변경된 내용이 실제 대상 파일에 반영되었습니다..\n");
	next_line();
	printf("sed 명령어는 정규표현식의 다양한 메타문자와 리다이렉션 기호와 함께 사용하면 더욱 강력한 명령어가 됩니다.\n이에 대해서는 내용이 방대하여 따로 학습해야 합니다.\n");
	next_line();
	printf("sed 명령어 학습이 끝났습니다. 고생하셨습니다.\n");
	next_line();

	
    // Delete default directory
	delete_defdir();
}
