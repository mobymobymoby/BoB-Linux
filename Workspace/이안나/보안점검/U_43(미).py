#!/usr/bin/env python3
#5.1 로그의 정기적 검토 및 보고

import subprocess
import sys

def U_43(): 
    print("[U-43] 로그의 정기적 검토 및 보고")
    #out = subprocess.getoutput('')
    report = True

    subprocess.call('last > wtmp_log.txt', shell=True)
    subprocess.call('sudo lastb > btmp_log.txt', shell=True)
    subprocess.call('w > utmp_log.txt', shell=True)

    print("\t[검사 결과] \"\" 폴더 위치에 LOG 파일이 저장되었습니다.")
    print("\t파일을 확인하여 조치 방법에 따라 정기적인 로그 점검 수행을 권장합니다.")

###########################################################################################
    if (report) :
        print("[U-43] 조치 방법")
        # wtmp : last 명령어 사용 : 사용자의 로그인/로그아웃 기록
        # btmp : lastb 명령어 사용 : 로그인 실패 기록
        # utmp : w : 현재 로그인 사용자 정보
        # sulog
        # xferlog
        print("\t정기적인 로그 점검을 통해 안정적인 시스템 상태를 유지하고 \n\t외부 공격 여부를 파악할 수 있습니다.")
        print("\n\t정기적인 로그 분석을 위해 아래와 같은 절차를 수행합니다.")
        print("\t1. 정기적인 로그 검토 및 분석 주기를 수립합니다.")
        print("\t2. 로그 분석에 대한 결과 보고서를 작성합니다.")
        print("\t3. 로그 분석 결과보고서의 보고 체계를 수립합니다.")
        print("\n\t다음의 로그 파일을 점검합니다.")
        print("\t1. wtmp : ")
        print("\t\t사용자의 로그인/로그아웃 기록을 점검합니다.")
        print("\t\t\"/var/log\" 위치에 저장되며 \"last\" 명령어를 통해 확인할 수 있습니다.")
        print("\t2. btmp : ")
        print("\t\t로그인 실패 기록을 점검합니다.")
        print("\t\t\"/var/log\" 위치에 저장되며 \"lastb\" 명령어를 통해 확인할 수 있습니다.")
        print("\t3. utmp : ")
        print("\t\t현재 로그인된 사용자 정보를 점검합니다.")
        print("\t\t\"w\" 명령어를 통해 확인할 수 있습니다.")
        print("\t4. sulog")
        print("\t\t허용된 계정 외의 계정이 su 명령어를 통해 \n\t\t권한상승을 시도하였는지 점검합니다.")
        print("\t5. xferlog")
        print("\t\t비인가자의 ftp 접근 여부를 점검합니다.")

U_43()