# [U-14] 공통 환경 변수 파일 검사
# 2020/11/17~18 : 노무승
#   1. 매뉴얼에 나오지 않은 환경 변수 파일 추가
#   2. 다른 사용자 뿐 만 아니라 그룹 유저도 검사
#   3. ls 명령어 옵션과 문자열 파싱을 이용하여 구현

import subprocess
import os.path

def U14(user):
    flag = False
    if (user == "root"):
        path = "/etc/"
        user = ["root"]
        list = "environment bash.bashrc profile bashrc profile.d"
        list = list.split()
        print("[U-14] 공통 환경 변수를 검사합니다.")
    elif (user == "user"):   
        user = subprocess.getoutput("ls /home")
        user = user.split() # User Count
        list = ".bashrc .bash_profile .bash_login .bash_logout .profile .kshrc .cshrc .login .exrc .netrc"
        list = list.split()
        print("[U-14] 사용자별 환경 변수를 검사합니다.")

    for i in user:
        if (i != "root"):
            path = "/home/" + i + "/"
        for j in list:
            if os.path.exists(path + j) :  # if setting file exist
                output = subprocess.getoutput("ls -aldGQ " + path + j)
                if (output[5] == 'w'): # GID write able check
                    print("\t[경고] " + path + j + " : 그룹에 소속된 사용자(GID)가 해당 파일을 쓸 수 있습니다.")
                    flag = True
                if (output[8] == 'w'): # Other User write able check
                    print("\t[경고] " + path + j + " : 다른 모든 사용자가 해당 파일을 쓸 수 있습니다.")
                    flag = True
                output = output.split("\"")
                if (output[0].find("root")==-1) : # File Owner check
                    if (output[0].find(i)==-1) :
                        print("\t[경고] " + path + j + " : 파일의 소유권(UID)이 '" + i + "'계정이 아닙니다.")
                        flag = True
 
    if (flag==False):
        print("\t[검사 결과] 안전합니다.\n")
        return False
    else:
        print("\t[검사 결과] 보안이 필요합니다.\n")
        return True

def U14_report():
    print("[U-14] 조치 방법")
    print("\t1. 'chmod og-w [파일명]'으로 소유자외 다른 유저의 파일 실행을 막을 수 있습니다.")
    print("\t2. 'chown [소유자] [파일명]'으로 소유자를 변경할 수 있습니다.")

U14flag = False
if (U14("root")): U14flag = True
if (U14("user")): U14flag = True
if (U14flag) : U14_report()
