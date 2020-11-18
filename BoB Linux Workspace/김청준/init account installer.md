# 배포 후 변경사항
```
- sshd 루트 권한 금지
- ALL ALL(ALL:ALL) ALL과 NOPASSWD가 같이 있으면 NOPASSWD가 무시됨
  - 알고보니 NOPASSWD가 아래에 있으면 무시안됨
```

# 미리 준비해야하는 설정
```
rookie	ALL=/usr/bin/apt
ALL	ALL=/usr/sbin/init
ALL	ALL=/usr/sbin/shutdown
ALL	ALL=/usr/sbin/halt
ALL	ALL=/usr/sbin/reboot
rookie	ALL=NOPASSWD: ALL
ALL	ALL=NOPASSWD: /usr/sbin/init
/etc/bash.bashrc 맨 밑에 fbterm, ./init_accounr1
```


### init_account1
```
#!/bin/sh
trap "echo '\n[경고]\n인터럽트를 발생시키지 마세요.\n'" INT TSTP TERM

printf "BoB Linux에서는 기본 계정인 'rookie'를 제공합니다.\n"
printf "하지만 사용자가 원하는 계정을 생성할 수도 있습니다.\n\n"
printf "새로운 계정 생성시 기본 계정은 삭제됩니다.\n\n"
printf "디버깅 용 : '3'을 입력하면 곧바로 코드가 종료됩니다.(실제 배포에선 삭제될 옵션)\n\n"
while :
do
	printf "기본 계정을 유지하려면 '1'을, 새로운 계정을 생성하려면 '2'를 입력하세요. : "
	read num
	if [ ${num} -eq 1 ] > /dev/null 2>&1 ; then
		sudo sed -i '/init_account/d' /etc/bash.bashrc
		sudo sed -i '/NOPASSWD/d' /etc/sudoers
		rm -f init_account*
		exit
	elif [ ${num} -eq 2 ] > /dev/null 2>&1 ; then
		break
	elif [ ${num} -eq 3 ] > /dev/null 2>&1 ; then
		exit
	else
		printf "잘못된 값을 입력하셨습니다. 다시 입력해주세요.\n\n"
	fi
done

printf "\n새로운 계정 생성 시 'root', 'rookie', 'admin'을 제외한 계정 이름으로 설정해주세요.\n\n"

while :
do
	printf "새로 생성할 계정 이름을 입력하세요 : "
	read name
	if [ "${name}" = "root" -o "${name}" = "rookie" -o "${name}" = "admin" -o "${name}" = "administrator" -o "${name}" = "" ] ; then
		printf "잘못된 값을 입력하셨습니다. 다시 입력해주세요.\n\n"
	else
		break
	fi
done
 
printf "새로 생성할 계정 비밀번호를 입력하세요 : "
read password
sleep 1
printf "\n계정 생성 중입니다\n\n"

(echo $password; echo ${password}) | sudo adduser ${name} > /dev/null 2>&1
sleep 1
printf "BoB Linux를 위한 기타 설정 중입니다.\n\n"
sleep 1
sudo gpasswd -a $name video > /dev/null 2>&1
sudo sed -i "s,\(\User privilege specification\),\1\n${name}\tALL=/usr/bin/apt\n${name}\tALL=NOPASSWD: /usr/sbin/userdel\n${name}\tALL=NOPASSWD: /usr/bin/sed,g" /etc/sudoers

sudo sed -i'' -r -e "/fbterm/i\/home/${name}/init_account2" /etc/bash.bashrc

#sudo sed -i -e "\/home/${name}/init_account2" /etc/bash.bashrc

sudo mv ./init_account2 /home/${name}/
sudo mv ./init_account3 /home/${name}/
sudo mv ./README /home/${name}/

rm -f /home/rookie/init_account1

sudo su - ${name}
```

### init_account2
```
#!/bin/sh

trap "echo '\n[경고]\n인터럽트를 발생시키지 마세요.\n'" INT TSTP TERM

fbterm
name=$(whoami)
sudo sed -i '/init_account/d' /etc/bash.bashrc
sudo sed -i "/font-size/ c\font-size=20" ~/.fbtermrc
sudo sed -i '/rookie/d' /etc/sudoers
rm -f ./init_account2

sudo sed -i'' -r -e "/fbterm/i\/home/${name}/init_account3" /etc/bash.bashrc
printf "설정을 마치기 위해 재부팅을 실행합니다.\n\n"
printf "다시 재부팅이 완료되면 방금 생성한 아이디로 로그인 해주세요.\n\n"
printf "재부팅 이후 모든 설정이 완료된 후에는 영어로 결과 메시지가 출력됩니다.\n"
printf "이후의 도움말을 보려면 홈 디렉토리의 README 파일을 참고하세요.\n\n"
printf "Enter를 입력하면 재부팅이 시작됩니다.\n"
read trash
printf " 3 초후에 종료됩니다.\n\n"
sleep 1
printf " 2 초후에 종료됩니다.\n\n"
sleep 1
printf " 1 초후에 종료됩니다.\n\n"
sleep 1

sudo init 6
```
### init_account3
```
#!/bin/sh
trap "echo '\n[경고]\n인터럽트를 발생시키지 마세요.\n'" INT TSTP TERM
sudo userdel -r rookie > /dev/null 2>&1
sudo sed -i '/init_account/d' /etc/bash.bashrc
sudo sed -i '/NOPASSWD/d' /etc/sudoers
rm -f ./init_account3
clear
printf "Success!\nAll Configures are done.\nIf you press [Enter], start BoB Linux Trainer.\n"
fbterm
trainer
exit
```

sed -i -e "\$aHELLO" /etc/bash.bashrc : 파일의 끝에 추가하는 명령어
