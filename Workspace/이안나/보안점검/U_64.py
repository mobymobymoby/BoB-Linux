#!/usr/bin/env python3
#3.27 ftpusers 파일 소유자 및 권한 설정

import subprocess
def U_64(): 
    print("[U-64] ftpusers 파일 소유자 및 권한 설정")
    def chek_mod(out) :
        if len(out) <= 0 :
            return False

        num=0
        mod=0
        #권한 추출
        # rwx/rwx/rwx
        # 421/421/421
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

    #ls -al /etc/ftpd/ftpusers 2>/dev/null
    #ls -al /etc/ftpusers 2>/dev/null
    out = subprocess.getoutput('ls -al /etc/ftpusers 2>/dev/null')
    report1 = chek_mod(out)

    out = subprocess.getoutput('ls -al /etc/ftpd/ftpusers 2>/dev/null')
    report2 = chek_mod(out)

    report = (report1) or (report2)

    if (report) :
        print("\t[검사 결과] 보안 조치가 필요합니다.")
    else :
        print("\t[검사 결과] 안전합니다.")

###########################################################################################
    if (report) :
        print("[U-64] 조치 방법")
        print("\t1. \"/etc/ftpusers\" 파일의 소유자 및 권한을 확인합니다.")
        print("\t\t#ls -l /etc/ftpusers")
        print("\t2. \"/etc/ftpusers\" 파일의 소유자를 root로, 권한을 640으로 변경합니다.")
        print("\t\t#chown root /etc/ftpusers")
        print("\t\t#chmod 640 /etc/ftpusers")

U_64()