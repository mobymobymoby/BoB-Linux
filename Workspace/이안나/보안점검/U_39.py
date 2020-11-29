#!/usr/bin/env python3
#3.21 Apache 링크 사용 금지

import subprocess
def U_39(): 
    print("[U-39] Apache 링크 사용 금지")
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

        #Directory 설정 개수 검색
        count = out.count('<Directory')

        index = 0
        for i in range(0, count) :
            #<Directory /> </Directory> 사이에 포함된 옵션
            index1 = out.find('<Directory', index)

            #주석 처리가 되어있다면 건너뜀
            if out[index1-1] == '#':
                continue

            index2 = out.find('</Directory>', index1+13)
            out1 = out[index1+10:index2]
            index = index1+10

            if 'FollowSymLinks' in out1 :
                report = True
                break
            
        if (report) :
            print("\t[검사 결과] 보안 조치가 필요합니다.")
        else :
            print("\t[검사 결과] 안전합니다.")

    else : 
        print("\t[검사 결과] 안전합니다.")
        report = False
###########################################################################################
    if (report) :
        print("[U-39] 조치 방법")
        print("\t1. vi 편집기를 이용하여 " + apacheHome + " 파일을 엽니다.")
        print("\t\t#vi "+ apacheHome)
        print("\t2. 설정된 모든 디렉터리의 Options 지시자에서 FollowSymLinks 옵션을 제거합니다.")
        print("\t\t(수정 전) Options 지시자에 FollowSymLink 옵션이 설정되어 있습니다.")
        print("\t\t<Directory />")
        print("\t\t\tOptions Indexes FollowSymLinks")
        print("\t\t\tAllowOverride None")
        print("\t\t\tOrder allow, deny")
        print("\t\t\tAllow from all")
        print("\t\t</Directory>\n")
        print("\t\t(수정 후) Options 지시자에 None 옵션으로 변경 후 저장합니다.")
        print("\t\t<Directory />")
        print("\t\t\tOptions Indexes FollowSymLinks")
        print("\t\t\tAllowOverride None")
        print("\t\t\tOrder allow, deny")
        print("\t\t\tAllow from all")
        print("\t\t</Directory>\n")

U_39()