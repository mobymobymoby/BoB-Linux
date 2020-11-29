#!/usr/bin/env python3
#3.33 NFS 설정파일 접근권한

import subprocess
def U_70(): 
    print("[U-70] NFS 설정파일 접근권한")
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

    report = chek_mod(subprocess.getoutput('ls -al /etc/exports'))

    if (report) :
        print("\t[검사 결과] 보안 조치가 필요합니다.")
    else :
        print("\t[검사 결과] 안전합니다.")

###########################################################################################
    if (report) :
        print("[U-70] 조치 방법")
        print("\t\"/etc/exports\" 파일의 소유자를 root로, 권한을 644로 변경합니다.")
        print("\t\t#chown root /etc/exports")
        print("\t\t#chmod 644 /etc/exports")

U_70()