#include "common_func.h"

void advanced_trainer()
{
    void (*fp[57])(void);

    printf("심화 명령어 학습입니다.\n");
    next_line();
    printf("해당 커리큘럼에서는 보안을 위해 리눅스를 사용할 때 응용할 수 있는 명령어를 학습합니다.\n");
    next_line();
    printf("명령어 목록입니다.\n");
    next_line();
    printf("[1. curl], [2. group](+관련 명령어), [3. head](+tail), [4. lsblk], [5. mkfs], [6. ping], [7. sed], [8. user](+관련 명령어+passwd)\n");
    next_line();
    printf("[9. file], [10. find], [11. history], [12. make], [13. more](+less), [14. mount], [15. sort], [16. tar], [17. umask], [18. uname]\n");
    next_line();
    printf("[19. fsck], [20. halt], [21. ifconfig], [22. init], [23. kill], [24. nano], [25. netstat], [26. poweroff], [27. reboot], [28. runlevel], [29. shutdown], [30. su], [31. sudo], [32. top], [33. wget]\n");
    next_line();
    printf("[34. chmod], [35. chown], [36. chroot], [37. cp], [38. dd], [39. echo], [40. env], [41. export], [42. ln], [43. mv], [44. redirection], [45. users]\n"); 
    next_line();
    printf("[46. ], [47. ], [48. ], [49. ], [50. ], [51. ], [52. ], [53. ], [54. ], [55. ], [56. ], [57. ]\n"); // 57개
    next_line();
    printf("원하시는 명령어의 번호 또는 [ ]안의 명령어 이름을 입력하세요.\nex) [curl] -> '1' 또는 'curl' 입력, [head](+tail) -> '3' 또는'head' 입력\n");
    next_line();
    char select[20];
    fgets(select, sizeof(select), stdin);
    select[strlen(select)-1] = '\0';
    /* 첫번째 인덱스의 값이 아스키 코드로 49~57 사이면 숫자로 판단 각 번호에 있는 명령어 시작. 판별하는 switch문은 따로 함수 구성 */
    /* 각 명령어의 문자열을 숫자로 치환. 결국에 숫자로 명령어를 시작하게 됨. 치환 하는 함수 호출 후 숫자로 변환된 값을 switch문 함수에 보내어 시작  */
    



 
    printf("\n");
    next_line();
    printf("\n");
    next_line();
}