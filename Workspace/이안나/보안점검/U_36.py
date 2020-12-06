#!/usr/bin/env python3
#3.18 Apache 웹 프로세스 권한 제한

import subprocess
def U_36(): 
    print("[U-36] Apache 웹 프로세스 권한 제한")
    report = False
    out = subprocess.getoutput('apache2 -V | egrep "(HTTPD\_ROOT|SERVER\_CONFIG\_FILE)"')

    if 'HTTPD_ROOT=' in out :
        #사용자의 Apache 홈 디렉토리를 추출
        index1 = out.find('HTTPD_ROOT="') 
        index2 = out.find('"', index1+13)
        apacheHome = out[index1+12:index2]

        index1 = out.find('SERVER_CONFIG_FILE="')
        index2 = out.find('"', index1+21)
        apacheHome = apacheHome + "/" + out[index1+20:index2]
        # print(apacheHome)

        out = subprocess.getoutput('cat ' + apacheHome)
        
        if 'User root' in out :
            report = True

        if 'Group root' in out :
            report = True

        if(report) :
            print("\t[검사 결과] 보안 조치가 필요합니다.")
        else :
            print("\t[검사 결과] 안전합니다.")

    else : 
        print("\t[검사 결과] 안전합니다.")
        report = False
###########################################################################################
    if (report) :
        print("[U-36] 조치 방법")
        print("\t1. 데몬 구동 권한 User, Group을 변경합니다.")
        print("\t\t User & Group 부분을 root가 아닌 별도 계정으로 변경합니다.")
        print("\t\t\t User [root가 아닌 별도의 계정명]]")
        print("\t\t\t Group [root가 아닌 별도의 계정명]")
        print("\t2. Apache 서비스를 재시작합니다.")

U_36()
