#!/usr/bin/env python3
#3.30 SNMP 서비스 구동 점검

import subprocess
def U_67(): 
    print("[U-67] SNMP 서비스 구동 점검")
    out = subprocess.getoutput('ps -ef | grep snmp')

    if 'snmp' in out :
        print("[검사 결과] 보안 조치가 필요합니다.")
        report = True

    else : 
        print("[검사 결과] 안전합니다.")
        report = False
###########################################################################################
    if (report) :
        print("[U-67] 조치 방법")
        print("\t1. \"ps -ef | grep snmp\"로 구동중인 snmp를 검색합니다.")
        print("\t\troot 2028    1  0  Nov 24 ?        0:00  /usr/sbin/snmpdm")
        print("\t2. snmp를 사용하지 않을 시 서비스를 중지합니다.")
        print("\t\t#service snmpd stop")

U_67()