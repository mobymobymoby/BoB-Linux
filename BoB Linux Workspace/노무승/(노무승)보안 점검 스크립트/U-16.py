# [U-16] /dev 디렉터리 불필요 파일 검사
# 2020/11/18 : 노무승
#   1. find 명령어 중 2>/dev/null 문구로 권한 에러를 뜨지 않게 함
#   2. 조치 방법에 mv 명령어 추가

import subprocess

def U16():
    print("[U-16] /dev 디렉터리에서 불필요한 파일을 검사합니다.")
    output = subprocess.getoutput("find /dev -type f -exec ls -al {} \; 2>/dev/null")
    output = output.split("\n")

    if (output == ['']) : # Nothing
        print("\t[검사 결과] 안전합니다.\n")
        return False
    else : # Detect
        for i in output :
            if (i[0]=="-") :
                print("\t" + i)
        print("\t[검사 결과] 보안이 필요합니다.\n")
        return True
        
def U16_report():
    print("[U-16] 조치 방법")
    print("\t1. 중요한 파일이면 'mv [파일명] [디렉터리]'로 파일을 옮기십시오.")
    print("\t2. 'rm -rf [파일명]'으로 /dev 디렉터리에 존재하는 쓸데없는 파일을 삭제하십시오.")

if(U16()) : U16_report()
