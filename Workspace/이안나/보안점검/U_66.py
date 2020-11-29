#!/usr/bin/env python3
#3.29 at 파일 소유자 및 권한 설정

import subprocess
def U_66(): 
    print("[U-66] at 파일 소유자 및 권한 설정")
    def chek_mod(out) :
        if len(out) <= 0 :
            return False

        num=0
        mod=0
        for i in range(1, 10) :
            if out[i]=="r" :
                num = num+4
            elif out[i]=="w" :
                num = num+2
            elif out[i]=="x" :
                num = num+1

            if i==3 :
                num = num * 100
                mod = mod + num
                num=0
            elif i==6 :
                num = num * 10
                mod = mod + num
                num=0
            elif i==9 :
                mod = mod + num
        
            if mod > 640 :
                return True
            elif 'root' in out[11:18] :
                return True

        return False

    #ls -l /etc/at.allow
    #ls -l /etc/at.deny
    report1 = chek_mod(subprocess.getoutput('ls -l /etc/at.allow 2>/dev/null'))
    report2 = chek_mod(subprocess.getoutput('ls -l /etc/at.deny 2>/dev/null'))

    report = (report1) or (report2)

    if (report) :
        print("\t[검사 결과] 보안 조치가 필요합니다.")
    else :
        print("\t[검사 결과] 안전합니다.")
###########################################################################################
    if (report) :
        print("[U-66] 조치 방법")
        print("\t\"/etc/at.allow \"와 \"/etc/at.deny\" 파일의 소유자 및 권한을 변경합니다.")
        print("\t\t#chown root /etc/at.allow")
        print("\t\t#chmod 640 /etc/at.allow")
        print("\t\t#chown root /etc/at.deny")
        print("\t\t#chmod 640 /etc/at.deny")

U_66()