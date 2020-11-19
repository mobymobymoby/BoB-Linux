# [U-17] 'r' command 원격 접속 파일 검사
# 2020/11/19 : 노무승
#   1. 2>/dev/null 문구로 권한 에러를 뜨지 않게 함

import subprocess
import os.path
import getpass

def U17():
    print("[U-17] 'r' command 원격 접속 파일을 검사합니다.")

    # File List
    list = ["/etc/hosts.equiv","$HOME/.rhosts"]
    list[1] = subprocess.getoutput("echo $HOME") + "/.rhosts"
    flag = False

    # Sec Check
    for i in list :
        if (os.path.isfile(i)):
            output = subprocess.getoutput("ls -l " + i + " 2>/dev/null")
            output = output.split()
            if (output[2] != "root") and (output[2] != getpass.getuser()):
                print("\t[경고] " + i + " : 파일의 소유권이 root 또는 현재 계정이 아닙니다.")
                flag = True
            if (output[0] != "-rw-------"):
                print("\t[경고] " + i + " : 파일의 권한이 600(-rw-------)이 아닙니다.")
                flag = True
            output = subprocess.getoutput("cat " + i + " 2>/dev/null")
            if (output.find("+") != -1) :
                print("\t[경고] " + i + " : 파일 내부에 + (무분별 허용) 문자가 포함되어 있습니다.")
                flag = True
    
    if (flag) :
        print("\t[검사 결과] 보안이 필요합니다.\n")
    else :
        print("\t[검사 결과] 안전합니다.\n")
    return flag

def U17_report():
    print("[U-17] 조치 방법")
    print("\t1. 'chmod 600 [파일명]'으로 설정 파일 권한을 변경하십시오.")
    print("\t2. 'chown [유저명] [파일명]'으로 파일의 소유권을 root 또는 현재 계정으로 변경하십시오.")
    print("\t3.  텍스트 편집기(vi, vim, nano 등)로 설정 파일 내부의 + (무분별 허용) 문자를 변경하십시오.")
    print("")

if (U17()): U17_report()
