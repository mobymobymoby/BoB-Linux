import subprocess

def U14(user):
    flag = False
    if (user == "root"):
        path = "/etc/"
        user = ["root"]
        list = "environment bash.bashrc profile bashrc profile.d"
        list = list.split()
        print("공통 환경 변수를 검사합니다.")
    elif (user == "user"):   
        user = subprocess.getoutput("ls /home")
        user = user.split() # User Count
        list = ".bashrc .bash_profile .bash_login .bash_logout .profile .kshrc .cshrc .login .exrc .netrc"
        list = list.split()
        print("사용자별 환경 변수를 검사합니다.")

    for i in user:
        if (i != "root"):
            path = "/home/" + i + "/"
        for j in list:
            output = subprocess.getoutput("ls -aldGQ " + path + j)
            if (output.find("No such file or directory")==-1) and (output.find("그런 파일이나 디렉터리가 없습니다")==-1): # if setting file exist
                if (output[5] == 'w'): # GID write able check
                    print("     [경고] " + path + j + " : 그룹에 소속된 사용자(GID)가 해당 파일을 쓸 수 있습니다.")
                    flag = True
                if (output[8] == 'w'): # Other User write able check
                    print("     [경고] " + path + j + " : 다른 모든 사용자가 해당 파일을 쓸 수 있습니다.")
                    flag = True
                output = output.split("\"")
                if (output[0].find("root")==-1) : # File Owner check
                    if (output[0].find(i)==-1) :
                        print("     [경고] " + path + j + " : 파일의 소유권(UID)이 '" + i + "'계정이 아닙니다.")
                        flag = True
 
    if (flag==False):
        print("     [검사 결과] 안전합니다.\n")
        return False
    else:
        print("     [검사 결과] 보안이 필요합니다.\n")
        return True

def U14_report():
    print("조치 방법")
    print("     'chmod og-w [파일명]'으로 소유자외 다른 유저의 파일 실행을 막을 수 있습니다.")
    print("     'chown [소유자] [파일명]'으로 소유자를 변경할 수 있습니다.")

if (U14("root")) or (U14("user")) :
    U14_report()
