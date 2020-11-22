# 출력 모듈

# 글자색
C_END    = "\033[0m"
C_RED    = "\033[31m"
C_GREEN  = "\033[32m"
C_YELLOW = "\033[33m"

def printTitle(report, string):
    print(string)
    report.write(string + '\n')

def printSafe(report):
    print('\t[검사결과] ' + C_GREEN + '안전' + C_END + '합니다.\n')
    report.write('\t[검사결과] 안전합니다.\n\n')

def printNotsafe(report):
    print('\t[검사결과] ' + C_RED + '보안 조치' + C_END + '가 필요합니다.\n')
    report.write('\t[검사결과] 보안 조치가 필요합니다.\n\n')

def printWarning(report, string):
    print('\t[' + C_YELLOW + '경고' + C_END + '] ' + string)
    report.write('\t[경고] ' + string + '\n')

def printNotice(report, string):
    print('\t[알림] ' + string)
    report.write('\t[알림] ' + string + '\n')