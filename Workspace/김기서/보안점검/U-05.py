# U-05 상
# 2.1 root 홈, 패스 디렉터리 권한 및 패스 설정
import subprocess

import printModule as pm

def U05():
    report = open('./U-05.txt', mode='w', encoding='utf-8')
    pm.printTitle(report, '[U-05] root 홈, 패스 디렉터리 권한 및 패스 설정')
    pm.printNotice(report, 'U-05의 점검은 현재 계정의 PATH만을 점검합니다.')

    envList = subprocess.check_output('echo $PATH', shell=True)
    envList = str(envList)
    isNotDot = False
    if '.' in envList:
        pm.printNotsafe(report, 'PATH에 \".\"이 포함되어 있습니다.')
    else:
        isNotDot = True
    isNotColon = False
    if '::' in envList:
        pm.printNotsafe(report, 'PATH에 \":\"이 포함되어 있습니다.')
    else:
        isNotColon = True

    if isNotDot and isNotColon:
        pm.printSafe(report)
    else:
        pm.printNotsafe(report)
        report.write('[U-05] 조치 방법\n')
        report.write('\t환경 설정 파일을 확인 및 수정하세요.\n')
        report.write('\t\t점검이 필요한 파일들\n')
        report.write('\t\t/etc/environment\n')
        report.write('\t\t/etc/profile\n')
        report.write('\t\t/etc/profile.d/*.sh\n')
        report.write('\t\t~/.profile\n')
        report.write('\t\t~/.bashrc\n')
        report.write('\t(수정 전) PATH=\".:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games\"\n')
        report.write('\t(수정 후) PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games\"\n')
        report.write('\t\".\" 혹은 \":\"을 제거')

    report.close()

U05()
