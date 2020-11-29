#!/usr/bin/env python3
#-*- coding:utf-8 -*-
#3.14 일반 사용자의 Sandmail 실행 방지

import subprocess

def U_32(): 
    print("[U-32] 일반 사용자의 Sandmail 실행 방지")
    out = subprocess.getoutput('ps -ef | grep sendmail | grep -v "grep"')

    if 'sendmail' in out :
        out = subprocess.getoutput('grep -v "^ *#" /etc/mail/sendmail.cf | grep PrivacyOptions');

        if 'restrictqrun' in out :
            print("\t[검사 결과] 안전합니다.\n")
            report = False
        else :
            print("")
            print("\t[검사 결과] 보안 조치가 필요합니다.\n")
            report = True

    #sendmail이 없으면 점검을 수행하지 않음
    else : 
        print("\t[검사 결과] 안전합니다. : SMTP 서비스가 사용중이지 않음\n")
        report = False

###########################################################################################
    if (report) :
        print("[U-32] 조치 방법")
        print("\t1. vi 편집기를 이용하여 sendmail.cf 설정 파일을 엽니다.")
        print("\t2. 'O PrivacyOptions=' 설정 부분에 'restrictqrun' 옵션을 추가합니다.")
        print("\t\t (수정 전) O PrivacyOptions=authwarnings, novrfy, noexpn")
        print("\t\t (수정 후) O PrivacyOptions=authwarnings, novrfy, noexpn, restrictqrun")
        print("\t3. 설정 후 Sendmail 서비스를 재시작합니다.")

U_32()