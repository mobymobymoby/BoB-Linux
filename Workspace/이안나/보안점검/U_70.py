#!/usr/bin/env python3
#3.33 NFS 설정파일 접근권한

import subprocess
import os
from os import stat
from pwd import getpwuid

def U_70(): 
    print("[U-70] NFS 설정파일 접근권한")
    report = False
    def check_mod(out) :
        st = os.stat(out)
        perm = oct(st.st_mode)

        perm = int(perm[5:8])
        if perm > 644 :
            re1 = True
        else :
            re1 = False

        owner = getpwuid(stat(out).st_uid).pw_name
        if owner == "root" :
            re2 = True
        else :
            re2 = False

        return re1 or re2

    out = '/etc/exports'
    if os.path.exists(out):
        report = check_mod(out)

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
