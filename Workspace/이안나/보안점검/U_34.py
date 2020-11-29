#!/usr/bin/env python3
#3.16 DNS Zone Transfer 설정

import subprocess
def U_34(): 
    print("[U-34] DNS Zone Transfer 설정")
    report = False
    out = subprocess.getoutput('ps -ef | grep named | grep -v "grep"')

    if 'named' in out :
        out = subprocess.getoutput('cat /etc/bind/named.conf');
        if 'allow-transfer"' in out :
            report = True

        if 'xfrents' in out :
            report = True

        if (report) :
            print("\t[검사 결과] 보안 조치가 필요합니다.")
        else :
            print("\t[검사 결과] 안전합니다.")
            

    #DNS서비스를 사용하지 않으면 점검을 수행하지 않음
    else : 
        print("\t[검사 결과] 안전합니다. : DNS 서비스가 사용중이지 않음")
        report = False
###########################################################################################
    if (report) :
        print("[U-34] 조치 방법")
        print("\tDNS 서비스 사용 시 제시된 파일의 DNS 설정을 아래의 보안설정방법에 따라 수정합니다.")
        print("\tBIND8 DNS 설정(named.conf) 수정 예")
        print("\t\tOptions {")
        print("\t\t\tallow-transfer (zone 파일 전송을 허용하고자 하는 IP;);")
        print("\t\t}; \n")
        print("\tBIND4.9 DNS 설정(named.conf) 수정 예")
        print("\t\tOptions")
        print("\t\t\txfrnets 허용하고자 하는 IP\n")
        print("\tDNS서비스를 사용하지 않는 경우")
        print("\t\tDNS 서비스를 사용하지 않는 경우에는 서비스 데몬을 중지합니다.")
        print("\t\t")

U_34()