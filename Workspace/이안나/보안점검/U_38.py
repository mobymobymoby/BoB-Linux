#!/usr/bin/env python3
#3.20 Apache 불필요한 파일 제거

import subprocess
def U_38(): 
    print("[U-38] Apache 불필요한 파일 제거")
    out = subprocess.getoutput('apache2 -V | egrep "(HTTPD\_ROOT|SERVER\_CONFIG\_FILE)"')

    if 'HTTPD_ROOT=' in out :
        #사용자의 Apache 홈 디렉토리를 추출
        index1 = out.find('HTTPD_ROOT="') 
        index2 = out.find('"', index1+13)
        apacheHome = out[index1+12:index2]
        apacheHome = apacheHome + "/"
        print(apacheHome)

        #find /etc/apache2/htdocs/ -name manual 2> /dev/null
        out = subprocess.getoutput('find ' + apacheHome + "htdocs/ -name manual 2> /dev/null")
        if 'manual' in out :
            report = True

        #find /etc/apache2/ -name manual 2> /dev/null
        out = subprocess.getoutput('find ' + apacheHome + "htdocs/ -name manual 2> /dev/null")
        if '' in out :
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
        print("[U-38] 조치 방법")
        print("\t1. ls 명령어로 확인된 메뉴얼 디렉터리와 파일을 제거합니다.")
        print("\t\trm -rf "+ apacheHome + "/htdocs/manual")
        print("\t\trm -rf "+ apacheHome + "/manual")
        print("\t2. ls 명령어로 정상적으로 제거되었는지 확인합니다.")
        print("\t\tls -ld "+ apacheHome + "/htdocs/manual")
        print("\t\tls -ld "+ apacheHome + "/manual"")
        print("\t3. 다른 추가적인 웹서비스 운영에 불필요한 파일이나 디렉토리가 있을 시 제거합니다.")

U_38()