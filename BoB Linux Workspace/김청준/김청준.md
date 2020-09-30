### ssh 설치
```apt install ssh```
- ssh가 설치됨. 하지만 root 계정으로 로그인하기 위해서는 /etc/ssh/sshd_config에서 주석처리 되어 있는 PermitRootLogin을 yes로 바꿔줌

### 커널 빌드
```apt install build-essential libncurses5 libncurses5-dev bin86 kernel-package libssl-dev bison flex libelf-dev```
- 우선, 커널 빌드를 위한 여러가지 패키지를 준비함 
```links kernel.org``` 
- kernel.org에서 원하는 커널 버전을 탐색
```tar -xvf linux-커널버전```
- 커널을 /usr/src에 다운로드 받은 후 압축 해제
- make menuconfig로 원하는 커널 설정을 추가하거나 뺌
```make-kpkg --J 4 --initrd --revision=1.0 kernel_image```
- 커널을 빌드하여 .deb 파일 형식으로 생성함
```dpkg -i (생성된 deb 파일)```
- 생성된 파일을 dpkg를 통해 인스톨함

- /boot 디렉토리에 가면 방금 빌드된 커널이 존재함
- /boot/grub/grub.cfg에서 linux 다음에 있는 버전을 방금 빌드한 버전으로 바꿔줌

 
