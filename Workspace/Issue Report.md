### create_mkdir 함수가 제대로 작동하지 않는 문제 발견 : 해결
- /home/[사용자 계정 이름] 디렉토리가 존재하지 않을 때 발생
- mkdir -p 명령어로 변경하여 하위 디렉토리를 생성하게 함

### fbterm은 루트 권한으로만 실행 가능 : 해결
- /dev/fb0을 chown을 이용해 변경하면 됨
  - chown [계정 이름] /dev/fb0 : 재부팅 후 fb0의 권한이 원래대로 돌아옴
    - 해결 : video 그룹에 [계정 이름]을 추가
      - ```gpasswd -a [계정 이름] video```
      
  - 하지만 이 방법에서는 keymap 관련 오류 뜸
    - keymap 오류 해결(root로 실행)
      - ```setcap cap_sys_tty_config+ep /usr/bin/fbterm```
      - ```getcap /usr/bin/fbterm```

- sudo를 이용한 방법 : fbterm 실행 시 쉘이 루트 권한으로 됨
  - bashrc를 이용
  - ALL=NOPASSWD: /usr/bin/fbterm으로 바로 변경
  - su [유저 이름]으로 변경
  
### 초기 스냅샷에서 fbterm 설치시 권한 오류 : 해결
- 원인 파악 : 해상도 설정이 되어있는 스냅샷에서는 오류뜨지 않음
  - 해상도 설정을 해줘야 fbterm을 사용 가능!

### adduser로 추가한 일반 유저는 shutdown, init 등이 불가능
- sudo를 이용해야 할듯 함
  - NOPASSWD 옵션으로 사용

### /etc/profile과 /etc/bash.bashrc
- profile은 로그인 시에만 적용(su에는 미적용)
- bash.bashrc는 su를 통해서 쉘이 변경될 때도 적용(su에도 적용)

### /etc/bash.bashrc에 ./trainer 적용시 
- exit를 통해 fbterm을 나가면 무한루프 발생

### 트레이닝 진행 중에 명령어 실습 부분에서 Ctrl + d를 입력하면 무한루프

### /usr/bin을 사용하지 말고, /usr/local/bin을 이용하기
- 업데이트에 의해 삭제되거나 할 수 있다고 함

### 유저 이름 표시 오류 : WSL 이용시, su 이후 발생 [해결]
- "getlogin()" 함수가 제대로 작동하지 않아서 발생
- 원격으로 접속된 것에 대해 유저명을 (null)로 반환
- su 이전의 유저로 이름 반환

- 해결법 : getlogin()함수를 cuserid() 함수로 대체(사용 X : 레거시 함수)
  - 별도의 char 형 배열을 두어 curserid의 매개 변수로 넘기면 그 배열에 유저의 이름이 저장
    - cuserid 함수는 레거시 함수임 : 다른 방법 사용
    
 - 해결법2 : passwd 구조체 이용 (채택)
 ```
 struct passwd *pwd;
 pwd = getpwuid(getuid());
 printf("%s\n", pwd->pw_name);
 ```
 ㄴ 다음과 같이 사용하면, su에 관계 없이 현재 로그인 되어 있는 유저의 이름을 반환
 
 - create_dir 함수와 run_command 함수에 적용 완료(20201122)
  
### 부팅시 메시지 삭제
- grub2를 설치
- /boot/grub/grub.cfg에서 ro 다음에 vga=0x317 추가
- linux, initrd 뒤에 16붙이기 
