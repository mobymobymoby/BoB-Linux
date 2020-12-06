# U-07 상
# 2.3 /etc/passwd 파일 소유자 및 권한 설정
from os import stat

import printModule as pm

def U07():
    report = open('./U-07.txt', mode='w', encoding='utf-8')
    pm.printTitle(report, '[U-07] /etc/passwd 파일 소유자 및 권한 설정')

    status = stat('/etc/passwd')

    isRightOwner = False
    owner = status.st_uid
    if owner == 0:
        isRightOwner = True
        pm.printNotice(report, '/etc/passwd 파일의 소유자가 root 입니다.')
    else:
        pm.printWarning(report, '/etc/passwd 파일의 소유자가 root가 아닙니다.')

    isRightPerm = False
    perm = int(oct(status.st_mode)[-3:])
    if perm <= 644:
        isRightPerm = True
        pm.printNotice(report, '/etc/passwd 파일의 권한이 644 이하입니다.')
    else:
        pm.printWarning(report, '/etc/passwd 파일의 권한이 644 이하가 아닙니다.')

    if isRightOwner and isRightPerm:
        pm.printSafe(report)
    else:
        pm.printNotsafe(report)
        report.write('[U-07] 조치 방법\n')
        report.write('\t/etc/passwd 파일의 소유자를 root로 권한을 644로 변경하세요.\n')
        report.write('\t\t#chown root /etc/passwd\n')
        report.write('\t\t#chmod 644 /etc/passwd\n')

    report.close()

U07()