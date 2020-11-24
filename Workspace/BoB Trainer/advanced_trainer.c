#include "func.h"

void advanced_trainer()
{
    system("clear");
    printf("심화 명령어 학습입니다.\n\n");
    printf("해당 커리큘럼에선 보안을 위해 리눅스를 사용할 때 응용할 수 있는 명령어를 학습합니다.\n\n");
    printf("아래의 목록에 따라 원하는 명령어를 선택하여 학습할 수 있습니다.\n");
    next_line();
    
    char select[20];
    while (1)
    {   
        system("clear");
        printf("명령어 목록입니다.\n");
        printf("입력 방법 : [22. head](+tail) -> '22' 또는 'head' 입력\n\n");
        printf(" [1. alias] \t\t [2. apt] \t\t [3. chmod] \n [4. chown] \t\t [5. chroot] \t [6. chsh] \n [7. cmp] \t\t [8. comm] \t\t [9. curl] \n [10. dd]\t\t");
        
        printf(" [11. diff] \t\t [12. echo] \n [13. env] \t [14. export] \t\t [15. file] \n [16. find] \t\t [17. fsck] \t\t [18. git] \n [19. grep] \t\t [20. group](+관련 명령어) \t\t");

        printf(" [21. halt] \n [22. head](+tail) \t\t [23. history] \t\t [24. ifconfig] \n [25. init] \t\t [26. kill] \t [27. ln] \n [28. locate] \t [29. lsblk] \t [30. make] \n [31. man] \t\t [32. mkfs] \t\t [33. more](+less) \n [34. mount] \t\t");
        
        printf(" [35. nano] \t\t [36. netstat] \n [37. ping] \t\t [38. pipe] \t\t [39. poweroff] \n [40. ps] \t\t [41. reboot] \t\t [42. redirection] \n [43. runlevel] \t\t [44. sed] \t\t [45. set](+unset) \n [46. shutdown] \t\t [47. sort] \t\t [48. su] \n");
        
        printf(" [49. sudo] \t\t [50. tar] \t\t [51. top] \n [52. umask] \t\t [53. uname] \t\t [54. user](+관련 명령어) \n [55. users] \t\t [56. vi] \t\t [57. wget] \n [58. whereis] \t [59. which] \n [q. 종료]\n");

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
        }
        else if (select[0] == 'q' || select[0] == 'Q')
            break;
        else
        {
            status_code = convert_name(select);
        }

        if (status_code == -1)
        {
            printf("[Enter]를 입력한 후 올바른 값을 다시 입력해주세요.\n");
            next_line();
        }
        else 
            next_quit();
    }
    printf("심화 명령어 학습이 종료되었습니다.\n고생하셨습니다.\n");
}
