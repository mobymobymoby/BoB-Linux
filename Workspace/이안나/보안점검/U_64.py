#!/usr/bin/env python3
#3.27 ftpusers 파일 소유자 및 권한 설정

import subprocess
import os
from os import stat
from pwd import getpwuid

def U_64(): 
    print("[U-64] ftpusers 파일 소유자 및 권한 설정")
    report1 = False
    report2 = False
    def check_mod(out) :
        st = os.stat(out)
        perm = oct(st.st_mode)

        perm = int(perm[5:8])
        if perm > 640 :
            re1 = True
        else :
            re1 = False

        owner = getpwuid(stat(out).st_uid).pw_name
        if owner == "root" :
            re2 = False
        else :
            re2 = True

        print("\n")
        #파일의 소유자가 root가 아니거나, 권한이 640이하가 아닌경우 취약
        return re1 or re2

    #ls -al /etc/ftpd/ftpusers 2>/dev/null
    #ls -al /etc/ftpusers 2>/dev/null
    out = '/etc/ftpusers'
    if os.path.exists(out):
        report1 = check_mod(out)

    out = '/etc/ftpd/ftpusers'
    if os.path.exists(out):
        report2 = check_mod(out)

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
