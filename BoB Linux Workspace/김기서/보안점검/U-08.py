# U-08 상
# 2.4 /etc/shadow 파일 소유자 및 권한 설정
# kisa에는 400이지만 우분투는 640으로 설정되어 있다.
from os import path
from os import stat

import printModule as pm

def U08():
    report = open('./U-08.txt', mode='w', encoding='utf-8')
    pm.printTitle(report, '[U-08] /etc/shadow 파일 소유자 및 권한 설정')

    isShadow = path.isfile('/etc/shadow')
    if not isShadow:
        pm.printNotice(report, '/etc/shadow 파일이 없습니다.')
        report.closed()
        return

    status = stat('/etc/shadow')

    isRightOwner = False
    owner = status.st_uid
    if owner == 0:
        isRightOwner = True
        pm.printNotice(report, '/etc/shadow 파일의 소유자가 root 입니다.')
    else:
        pm.printWarning(report, '/etc/shadow 파일의 소유자가 root가 아닙니다.')

    isRightPerm = False
    perm = int(oct(status.st_mode)[-3:])
    if perm <= 400:
        isRightPerm = True
        pm.printNotice(report, '/etc/shadow 파일의 권한이 400 이하입니다.')
    else:
        pm.printWarning(report, '/etc/shadow 파일의 권한이 400 이하가 아닙니다.')

    if isRightOwner and isRightPerm:
        pm.printSafe(report)
    else:
        pm.printNotsafe(report)
        report.write('[U-08] 조치 방법\n')
        report.write('\t/etc/shadow 파일의 소유자를 root로 권한을 400으로 변경하세요.\n')
        report.write('\t\t#chown root /etc/shadow\n')
        report.write('\t\t#chmod 400 /etc/shadow\n')

    report.close()

U08()