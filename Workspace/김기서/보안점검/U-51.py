# U-51 하
# 1.12 계정이 존재하지 않는 GID 금지
import printModule as pm

def U51():
    report = open('./U-51.txt', mode='w', encoding='utf-8')
    pm.printTitle(report, '[U-51] 계정이 존재하지 않는 GID 금지')
    pm.printNotice(report, 'U-51의 점검 및 조치는 시스템 관리자와 검토하여야 합니다.')
    pm.printNotice(report, 'U-51.txt를 참고하여 관리자와 사용자가 직접 수행바랍니다.\n')

    report.write('[U-51] 조치 방법\n')
    report.write('\t계정이 존재하지 않고 시스템 운영에 사용되지 않는 그룹 등\n')
    report.write('\t불필요한 그룹이 존재하는 경우 해당 그룹을 제거하세요.\n')
    report.write('\t\t\"/etc/group\" 파일과 \"/etc/passwd\" 파일을 같이 확인하여 불필요한 그룹을 확인\n')
    report.write('\t\t# groupdel <group_name>\n')

    report.close()

U51()
