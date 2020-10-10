### unminimize
- unminimize를 하여 여러 패키지를 설치
### 아카이브 변경
- ```vim /etc/apt/sources.list``` 
- ```:%s/archive.ubuntu.com/mirror.kakao.com``` : archive.ubuntu.com은 기본 아카이브 설정에 따라 달라질 수 있음
- 아카이브 변경을 하지 않아도 되지만, 시간이 매우 오래 걸리게 됨
- ```apt update```와 ```apt upgrade```를 해줌
### X-Window(Gnome) 설치
- apt install xorg gnome-core gnome-system-tools
- 진행사항이 84% 정도 되면 언어를 선택하게 됨 - 31(English US) - 1 선택
### 사용자 계정 추가
- 초기 사용자 계정이 있어야 로그인이 가능함
- ```adduser [유저 이름]```으로 계정 생성
