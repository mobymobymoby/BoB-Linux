# U-49 하
# 1.10 불필요한 계정 제거
import printModule as pm

def U49():
    report = open('./U-49.txt', mode='w', encoding='utf-8')
    pm.printTitle(report, '[U-49] 불필요한 계정 제거')
    pm.printNotice(report, 'U-49의 점검은 U-49.txt를 참고하여 관리자가 직접 수행바랍니다.\n')

    report.write('[U-49] 조치 방법\n')
    report.write('\t"/etc/passwd\" 파일을 확인하여\n')
    report.write('\t미사용 계정, 의심스러운 계정, 사용하지 않지만 기본적으로 생성되는 계정들을 확인합니다.\n')
    report.write('\t불필요한 사용자 계정은 제거합니다.\n')
    report.write('\t\t# userdel <user_name>\n')

    report.close()

U49()
