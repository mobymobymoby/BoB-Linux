### create_mkdir 함수가 제대로 작동하지 않는 문제 발견 : 해결
- /home/[사용자 계정 이름] 디렉토리가 존재하지 않을 때 발생
- mkdir -p 명령어로 변경하여 하위 디렉토리를 생성하게 함

### fbterm은 루트 권한으로만 실행 가능 : 해결
- /dev/fb0을 chown을 이용해 변경하면 됨
  - chown [계정 이름] /dev/fb0
  - 하지만 이 방법에서는 keymap 관련 오류 뜸
    - keymap 오류 해결
      - ```setcap cap_sys_tty_config+ep /usr/bin/fbterm```
      - ```getcap /usr/bin/fbterm```

- sudo를 이용한 방법 : fbterm 실행 시 쉘이 루트 권한으로 됨
  - bashrc를 이용
  - ALL=NOPASSWD: /usr/bin/fbterm으로 바로 변경
  - su [유저 이름]으로 변경
  
### 초기 스냅샷에서 fbterm 설치시 권한 오류 : 해결
- 원인 파악 : 해상도 설정이 되어있는 스냅샷에서는 오류뜨지 않음
  - 해상도 설정을 해줘야 fbterm을 사용 가능!
