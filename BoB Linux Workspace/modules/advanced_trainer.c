#include "func.h"

void advanced_trainer()
{
    printf("심화 명령어 학습입니다.\n");
    next_line();
    printf("해당 커리큘럼에서는 보안을 위해 리눅스를 사용할 때 응용할 수 있는 명령어를 학습합니다.\n");
    next_line();

    char select[20];
    while (1)
    {
        printf("명령어 목록입니다.\n");
        printf("ex) [3. head](+tail) -> '3' 또는'head' 입력\n");
        printf(" [1. file] \t\t [2. find] \n [3. history] \t\t [4. make] \n [5. more](+less) \t [6. mount] \n [7. sort] \t\t [8. tar] \n [9. umask] \t\t [10. uname]\n");
        
        printf(" [11. curl] \t\t [12. group](+관련 명령어) \n [13. head](+tail) \t [14. lsblk] \n [15. mkfs] \t\t [16. ping] \n [17. sed] \t\t [18. user](+관련 명령어+passwd) \n [19. fsck] \t\t [20. halt] \n");

        printf(" [21. ifconfig] \t [22. init] \n [23. kill] \t\t [24. nano] \n [25. netstat] \t\t [26. poweroff] \n [27. reboot] \t\t [28. runlevel] \n [29. shutdown] \t [30. su] \n [31. sudo] \t\t [32. top] \n [33. wget] \t\t [34. alias] \n");
        
        printf(" [35. apt] \t\t [36. chsh] \n [37. cmp] \t\t [38. comm] \n [39. diff] \t\t [40. grep] \n [41. locate] \t\t [42. man] \n [43. pipe] \t\t [44. ps] \n [45. vi] \t\t [46. whereis] \n [47. which] \t\t [48. chmod] \n");
        
        printf(" [49. chown] \t\t [50. chroot] \n [51. dd] \t\t [52. echo] \n [53. env] \t\t [54. export] \n [55. git] \t\t [56. ln] \n [57. redirection] \t [58. set(+unset)] \n [59. users] \n");

        printf("'q' 또는 'Q'를 입력하면 종료합니다.\n원하시는 [ ]안의 명령어의 번호 또는 이름을 입력하세요. : ");

        int status_code = 1;
        fgets(select, sizeof(select), stdin);
        select[strlen(select) - 1] = '\0';
        /* 첫번째 인덱스의 값이 아스키 코드로 49~57 사이면 숫자로 판단 각 번호에 있는 명령어 시작. 판별하는 switch문은 따로 함수 구성 */
        /* 입력 값이 'q' 또는 'Q'라면 종료 */
        /* 그 외에는 문자열로 판단 if else 문을 이용해 해당하는 함수 실행*/
        if (select[0] >= 49 && select[0] <= 57)
            status_code = call_training(select);
        else if (select[0] == 'q' || select[0] == 'Q')
            break;
        else
            status_code = convert_name(select);

        if (status_code == -1)
            printf("올바른 값을 다시 입력해주세요.\n");

        next_quit();
    }
    printf("심화 명령어 학습이 종료되었습니다.\n고생하셨습니다.\n");
}
