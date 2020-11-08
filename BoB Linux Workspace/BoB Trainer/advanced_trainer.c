#include "common_func.h"

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
        printf("[1. file], [2. find], [3. history], [4. make], [5. more](+less), [6. mount], [7. sort], [8. tar], [9. umask], [10. uname]\n");
        printf("[11. curl], [12. group](+관련 명령어), [13. head](+tail), [14. lsblk], [15. mkfs], [16. ping], [17. sed], [18. user](+관련 명령어+passwd)\n");
        printf("[19. fsck], [20. halt], [21. ifconfig], [22. init], [23. kill], [24. nano], [25. netstat], [26. poweroff], [27. reboot], [28. runlevel], [29. shutdown], [30. su], [31. sudo], [32. top], [33. wget]\n");
        printf("[34. ], [35. ], [36. ], [37. ], [38. ], [39. ], [40. ], [41. ], [42. ], [43. ], [44. ], [45. ]\n");
        printf("[46. chmod], [47. chown], [48. chroot], [49. dd], [50. echo], [51. env], [52. export], [53. ln], [54. redirection], [55. users]\n");

        printf("원하시는 [ ]안의 명령어의 번호 또는 이름을 입력하세요.\nex) [1. curl] -> '1' 또는 'curl' 입력, [3. head](+tail) -> '3' 또는'head' 입력\n");
        printf("'0'을 입력하면 종료합니다.");

        int status_code = 1;
        fgets(select, sizeof(select), stdin);
        select[strlen(select) - 1] = '\0';
        /* 첫번째 인덱스의 값이 아스키 코드로 49~57 사이면 숫자로 판단 각 번호에 있는 명령어 시작. 판별하는 switch문은 따로 함수 구성 */
        /* 입력 값이 '0'이라면 종료 */
        /* 그 외에는 문자열로 판단 if else 문을 이용해 해당하는 함수 실행*/
        if (select[0] >= 49 && select[0] <= 57)
            status_code = call_training(select);
        else if (select[0] == '0')
            break;
        else
            status_code = convert_name(select);

        if (status_code == -1)
            printf("올바른 값을 다시 입력해주세요.\n");

        next_quit();
    }
    printf("\n");
    next_line();
    printf("\n");
    next_line();
}