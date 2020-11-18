# [U-15] World Writeable 파일 검사
# 2020/11/18 : 노무승
#   1. 매뉴얼 과는 달리 검사 디렉터리를 선정함
#   2. find 명령어 중 2>/dev/null 문구로 권한 에러를 뜨지 않게 함

import subprocess

def U15():
    print("[U-15] World Writeable 파일을 검사합니다. (/home, /tmp, /etc, /var 폴더 대상)")
    temp=""

    list = "/home /tmp /etc /var"
    list = list.split()

    for i in list:
        output = subprocess.getoutput("find " + i + " -type f -perm -2 -exec ls -l {} \; 2>/dev/null")
        if (len(output) != 0) : temp = temp + "\t" + output + "\n"

    if (len(temp)==0):
        print("\t[검사 결과] 안전합니다.\n")
        return False
    else :
        print(temp.rstrip())
        print("\t[검사 결과] 보안이 필요합니다.\n")
        return True

def U15_report():
    print("U-15 조치 방법")
    print("\t1. 'chmod o-w [파일명]'으로 소유자와 그룹 외의 다른 유저의 파일 실행을 막을 수 있습니다.")
    print("\t2. 'rm -rf [파일명]'으로 파일을 삭제할 수 있습니다.")
    print("\t3. 해당 파일의 사용 목적을 확실히 알고 있고, 필요하다면 넘겨도 됨.")

if (U15()) : U15_report()
