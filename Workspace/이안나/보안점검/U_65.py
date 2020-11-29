#!/usr/bin/env python3
#3.28 ftpusers 파일 설정

import re
import subprocess

def U_65(): 
    print("[U-65] ftpusers 파일 설정")
    out = subprocess.getoutput('cat /etc/ftpusers 2>/dev/null')
    out + subprocess.getoutput('cat /etc/ftpd/ftpusers 2>/dev/null')
    #print(out)
    
    if 'root' in out :
        if ('#root' in out) or re.search('#\s+root', out):
            print("\t[검사 결과] 안전합니다.")
            report = False

        else :
            print("\t[검사 결과] 보안 조치가 필요합니다.")
            report = True

    else : 
        print("\t[검사 결과] 안전합니다.")
        report = False
###########################################################################################
    if (report) :
        print("[U-65] 조치 방법")
        print("\t1. vi 편집기를 이용하여 ftpuser파일을 엽니다.")
        print("\t\t#vi etc/ftpusers 또는 /etc/ftpd/ftpdusers")
        print("\t2. ftpusers 파일에 root 계정 추가 또는, 주석 제거")
        print("\t\t(수정 전) #root 또는 root 계정 미등록")
        print("\t\t(수정 후) root")

U_65()