#include "func.h"

void advanced_trainer()
{
    system("clear");
    printf("심화 명령어 학습입니다.\n");
    next_line();
    printf("해당 커리큘럼에서는 보안을 위해 리눅스를 사용할 때 응용할 수 있는 명령어를 학습합니다.\n");
    next_line();
    printf("아래의 목록에 따라 원하는 명령어를 선택하여 학습할 수 있습니다.\n");
    next_line();
    system("clear");
    
    char select[20];
    while (1)
    {   
        printf("명령어 목록입니다.\n");
        printf("[입력 방법] : [3. head](+tail) -> '3' 또는'head' 입력\n");
        printf(" [1. file] \t\t [2. find] \t\t [3. history] \n [4. make] \t\t [5. more](+less) \t [6. mount] \n [7. sort] \t\t [8. tar] \t\t [9. umask] \n [10. uname]\t\t");
        
        printf(" [11. curl] \t\t [12. group](+관련 명령어) \n [13. head](+tail) \t [14. lsblk] \t\t [15. mkfs] \n [16. ping] \t\t [17. sed] \t\t [18. user](+관련 명령어) \n [19. fsck] \t\t [20. halt] \t\t");

        printf(" [21. ifconfig] \n [22. init] \t\t [23. kill] \t\t [24. nano] \n [25. netstat] \t\t [26. poweroff] \t [27. reboot] \n [28. runlevel] \t [29. shutdown] \t [30. su] \n [31. sudo] \t\t [32. top] \t\t [33. wget] \n [34. alias] \t\t");
        
        printf(" [35. apt] \t\t [36. chsh] \n [37. cmp] \t\t [38. comm] \t\t [39. diff] \n [40. grep] \t\t [41. locate] \t\t [42. man] \n [43. pipe] \t\t [44. ps] \t\t [45. vi] \n [46. whereis] \t\t [47. which] \t\t [48. chmod] \n");
        
        printf(" [49. chown] \t\t [50. chroot] \t\t [51. dd] \n [52. echo] \t\t [53. env] \t\t [54. export] \n [55. git] \t\t [56. ln] \t\t [57. redirection] \n [58. set(+unset)] \t [59. users] \n [q. 종료]\n");

        printf("\n명령어의 번호 또는 이름을 입력하세요 : ");

        int status_code = 1;
        fgets(select, sizeof(select), stdin);
        select[strlen(select) - 1] = '\0';
        /* 첫번째 인덱스의 값이 아스키 코드로 49~57 사이면 숫자로 판단 각 번호에 있는 명령어 시작. 판별하는 switch문은 따로 함수 구성 */
        /* 입력 값이 'q' 또는 'Q'라면 종료 */
        /* 그 외에는 문자열로 판단 if else 문을 이용해 해당하는 함수 실행*/
        if (select[0] >= 49 && select[0] <= 57)
        {
            status_code = call_training(select);
            next_quit();
        }
        else if (select[0] == 'q' || select[0] == 'Q')
            break;
        else
        {
            status_code = convert_name(select);
            next_quit();
        }

        if (status_code == -1)
            printf("올바른 값을 다시 입력해주세요.\n");
    }
    printf("심화 명령어 학습이 종료되었습니다.\n고생하셨습니다.\n");
}
