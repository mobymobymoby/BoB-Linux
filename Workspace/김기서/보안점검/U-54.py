# U-54 하
# 1.15 Session Timeout 설정
import subprocess

import printModule as pm

def U54():
    report = open('./U-54.txt', mode='w', encoding='utf-8')
    pm.printTitle(report, '[U-54] Session Timeout 설정')

    # check bash
    shell = subprocess.check_output('echo $SHELL', shell=True)
    shell = str(shell)
    if not ('bash' in shell):
        pm.printNotice(report, 'bash shell이 아닙니다.')
        report.close()
        return

    echoRst = subprocess.check_output('echo $TMOUT', shell=True)
    echoRst = str(echoRst)
    startIdx = echoRst.find('\'')
    endIdx = echoRst.find('\\n')
    time = echoRst[startIdx+1:endIdx]

    isTimeout = False
    if time == '':
        pm.printWarning(report, 'Session Timeout이 설정되어 있지 않습니다.')
    elif int(time) > 600:
        pm.printWarning(report, 'Session Timeout이 10분 이상으로 설정되어 있습니다.')
    else:
        isTimeout = True

    if isTimeout:
        pm.printSafe(report)
    else:
        pm.printNotsafe(report)
        report.write('[U-54] 조치 방법\n')
        report.write('\tSession Timeout을 10분 이하로 설정하세요.\n')
        report.write('\t\t텍스트 에디터를 이용하여 \"~/.bashrc\" 파일을 엽니다.\n')
        report.write('\t\t아래의 내용을 수정 또는 추가하세요.\n')
        report.write('\t\tTMOUT=600\n')
        report.write('\t\texport TMOUT\n')

    report.close()

U54()
