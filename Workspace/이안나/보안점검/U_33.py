#!/usr/bin/env python3
#3.15 DNS 보안 버전 패치

import subprocess
def U_33(): 
    print("[U-33] DNS 보안 버전 패치")
    out = subprocess.getoutput('ps -ef | grep named')

    if 'named' in out :
        print("\t[검사 결과] 보안 조치가 필요합니다.")
        report = True

    #DNS서비스를 사용하지 않으면 점검을 수행하지 않음
    else : 
        print("\t[검사 결과] 안전합니다.")
        report = False
###########################################################################################
    if (report) :
        print("[U-33] 조치 방법")
        print("\t1. BIND는 거의 모든 버전이 취약한 상태로, 최신 버전으로 업데이트가 요구됩니다.")
        print("\t2. 취약점 관련 버전을 사용하는 시스템에서는 버전 업그레이드가 필요합니다.")
        print("\t현재 설치 되어있는 BIND의 버전은 다음과 같습니다.\n")
        subprocess.call('named -v', shell=True)
        print("\n\t만약 설치된 BIND가 최신 버전이 아닌 경우, \n\t최신 버전의 BIND는 아래 사이트에서 다운로드를 할 수 있습니다.")
        print("\thttp://www.isc.org/downloads")
        print("\n\t<BIND 8에 대한 취약점 정보 사이트>")
        print("\thttps://kb.isc.org/article/AA-00959/0/BIND-8-Security-Vulerabillity-Matrix.html")
        print("\t<BIND 9에 대한 취약점 정보 사이트>")
        print("\thttps://kb.isc.org/article/AA-00913/0/BIND-9-Security-Vulerabillity-Matrix.html")

U_33()