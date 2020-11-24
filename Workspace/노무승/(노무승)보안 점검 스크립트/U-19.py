# [U-19] finger 서비스 설치 여부 검사
# 2020/11/19 : 노무승
#   1. 명령어 설치 여부를 dpkg 명령어와 finger 명령어로 확인
#   2. 데비안 계열 뿐만 아니라 레드햇 계열도 검사/방안 제시

import subprocess

def U19():
    print("[U-19] finger 서비스 설치 여부를 검사합니다.")
    flag = False

    # if install dpkg (exam. Debian Base (Ubuntu/Mint))
    output = subprocess.getoutput("dpkg --get-selections | grep finger")
    output = output.split()
    if (output == ['finger','install']) :
        print("\t[경고] finger 서비스가 설치되어 있습니다.") 
        flag = True

    # if not install dpkg (exam. Redhat Base)
    else : 
        output = subprocess.getoutput("finger")
        output = output.split()
        if (output[0]=="Login") and (output[1]=="Name") and (output[2]=="Tty") :
            print("\t[경고] finger 서비스가 설치되어 있습니다.") 
            flag = True
    
    if (flag) :
        print("\t[검사 결과] 보안이 필요합니다.\n")
    else :
        print("\t[알림] finger 서비스가 설치되어 있지 않습니다.")
        print("\t[검사 결과] 안전합니다.\n")
    return flag

def U19_report():
    print("[U-19] 조치 방법")
    print("\t1. Debian 계열 (Ubuntu, Mint 등)의 경우,")
    print("\t\t'apt remove finger -y'로 패키지를 삭제하십시오.")
    print("\t2. Redhat 계열 (Redhat, CentOS 등)의 경우,")
    print("\t\t'yum remove finger -y'로 패키지를 삭제하십시오.")

if(U19()) : U19_report()
