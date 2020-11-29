#!/usr/bin/env python3
#3.25 ftp 서비스 확인

import subprocess
def U_62(): 
    print("[U-62] ftp 서비스 확인")
    out = subprocess.getoutput('ps -ef | grep ftp & ps -ef | egrep "vsftpd|proftp"')
    
    if ('ftp' in out) or ('vsftpd' in out) or ('proftp' in out) :
        print("\t[검사 결과] 보안 조치가 필요합니다.")
        report = True

    else : 
        print("\t[검사 결과] 안전합니다.")
        report = False
###########################################################################################
    if (report) :
        print("[U-62] 조치 방법")
        print("\t1. 서비스 활성화 여부를 확인합니다.")
        print("\t\t#ps -ef | egrep \"vsftpd|proftpd\"")
        print("\t2. vsftp 또는 ProFTP 서비스 데몬을 중지합니다.")
        print("\t\t#service vsftpd(proftp) stop")
        print("\t\t또는 /etc/rc.d/init.d/vsftpd(proftp) stop")
        print("\t\t또는 kill -i [PID]")

U_62()