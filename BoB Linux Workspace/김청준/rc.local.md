### rc.local 활성화
- rc.local이 etc 디렉토리에 존재하는지 확인
```
cd /etc
find *rc.local*
```
- 파일이 존재하지 않으면 rc.local 파일을 생성한다<br>
```vim /etc/rc.local```
- 다음 내용 삽입
```
#! /bin/sh

exit 0
```
- 실행 파일로 변경<br>
```chmod +x /etc/rc.local```
- rc-local.service 파일 수정<br>
```vim /lib/systemd/system/rc-local.service```
- 맨 아래에 다음 문구 추가
```
[Install]
WantedBy=multi-user.target
```
- systemctl을 이용해 rc.local을 활성화 시킨다<br>
```systemctl enable rc-local.service```
- rc.local 서비스를 시작<br>
```systemctl start rc-local.service```
- rc.local의 상태 확인<br>
```systemctl status rc-local.service```
- active가 확인되면 성공.
- 이후에는 /etc/rc.local 파일에 실행할 명령어를 추가하면 된다

