#!/usr/bin/env python3
#5.2 정책에 따른 시스템 로깅 설정

import subprocess
def U_73(): 
    print("[U-73] 정책에 따른 시스템 로깅 설정")
    report = True

    print("\t[검사 결과] 보안 사고 발생 시 원인과 각종 침해 사실에 대한 확인을 위해\n\t로그 기록 정책을 수립하고 보안정책에 따라 로그를 기록해야 합니다.")

###########################################################################################
    if (report) :
        print("[U-73] 조치 방법")
        print("\t로그 기록 정책을 수립하고, 정책에 따라 rsyslog.conf 파일을 설정합니다.")
        print("\t1. vi 편집기를 이용하여 \"/etc/rsyslog.conf\"파일을 엽니다.")
        print("\t\t#vi /etc/rsyslog.conf")
        print("\t2. 아래와 같이 수정하거나, 새로 삽입합니다.")
        print("\n\t------------------------------------------------------------")
        print("\t*.info;mail.none;;authpriv.none;cron.none\t/var/log/messages")
        print("\tauthpriv.*\t\t/var/log/secure")
        print("\tmail.*\t\t\t/var/log/maillog")
        print("\tcron.*\t\t\t/var/log/cron")
        print("\t*.alert\t\t\t/dev/console")
        print("\t*.emerg\t\t\t*")
        print("\t------------------------------------------------------------")
        print("\n\t3. 위와 같이 설정한 후 syslog 데몬을 재시작합니다.")
        print("\t\t#ps -ef | grep syslogd")
        print("\t\t#kill -HUP [PID]")

U_73()