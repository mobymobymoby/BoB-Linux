# LFS 구축 
## Ubuntu 18.04.4 LTS Desktop 환경
---
### 사전 준비
- 혹시 모를 불상사를 대비하여, 초기 업데이트 모두 완료 및 재부팅
- 우분투가 설치되어 있는 디스크 외에 가상 하드디스크를 하나 생성 
  - 용량은 10~30gb
- root로 로그인하여 ```fdisk /dev/sdb``` : sdb가 디스크 이름으로 가정
 - n -> p -> 1 -> default -> default : 파티션 생성 -> primary -> 1번 파티션 -> 모든 용량 할당
 - a : Bootable flag 부여
 - t -> 83(Linux) : Linux 태그 부여
 - w : 저장(write)
 - sdb1이 생성된 것을 확인
- 우분투 설정 -> power -> Blank Screen : Never
- 우분투 설정 -> privacy -> Screen Lock : Off

### 참고 매뉴얼 : http://www.linuxfromscratch.org/lfs/view/stable/index.html

### 2.2
```
cat > version-check.sh << "EOF"
#!/bin/bash
# Simple script to list version numbers of critical development tools
export LC_ALL=C
bash --version | head -n1 | cut -d" " -f2-4
MYSH=$(readlink -f /bin/sh)
echo "/bin/sh -> $MYSH"
echo $MYSH | grep -q bash || echo "ERROR: /bin/sh does not point to bash"
unset MYSH

echo -n "Binutils: "; ld --version | head -n1 | cut -d" " -f3-
bison --version | head -n1

if [ -h /usr/bin/yacc ]; then
  echo "/usr/bin/yacc -> `readlink -f /usr/bin/yacc`";
elif [ -x /usr/bin/yacc ]; then
  echo yacc is `/usr/bin/yacc --version | head -n1`
else
  echo "yacc not found" 
fi

bzip2 --version 2>&1 < /dev/null | head -n1 | cut -d" " -f1,6-
echo -n "Coreutils: "; chown --version | head -n1 | cut -d")" -f2
diff --version | head -n1
find --version | head -n1
gawk --version | head -n1

if [ -h /usr/bin/awk ]; then
  echo "/usr/bin/awk -> `readlink -f /usr/bin/awk`";
elif [ -x /usr/bin/awk ]; then
  echo awk is `/usr/bin/awk --version | head -n1`
else 
  echo "awk not found" 
fi

gcc --version | head -n1
g++ --version | head -n1
ldd --version | head -n1 | cut -d" " -f2-  # glibc version
grep --version | head -n1
gzip --version | head -n1
cat /proc/version
m4 --version | head -n1
make --version | head -n1
patch --version | head -n1
echo Perl `perl -V:version`
python3 --version
sed --version | head -n1
tar --version | head -n1
makeinfo --version | head -n1  # texinfo version
xz --version | head -n1

echo 'int main(){}' > dummy.c && g++ -o dummy dummy.c
if [ -x dummy ]
  then echo "g++ compilation OK";
  else echo "g++ compilation failed"; fi
rm -f dummy.c dummy
EOF

bash version-check.sh
```
ㄴ 실행 후 'command not fount' 뜬 패키지들 설치
- 보통 '''apt install bison gawk gcc g++ m4 make texinfo'''를 통해 해결 됨 : makeinfo는 texinfo

### 2.5. Creating a File System on the Partition
- ```mkfs -v -t ext4 /dev/sdb1``` or ```mkfs.ext4 /dev/sdb1``` : sdb1이 생성된 파티션으로 가정

### 2.6
- ```export LFS=/mnt/lfs``` : 계정이 변경될 때마다 이를 입력하여 $LFS=/mnt/lfs가 되게 해주어야 함
 - 잘 설정되어있는지는 ```echo $LFS```를 통해 가능. /mnt/lfs가 출력되면 정상
- 여기서부터 /mnt/lfs == $LFS의 의미를 가짐. 혼용된다면 같은 의미로 받아들일것
### 2.7
- ```mkdir -pv $LFS : /mnt/lfs``` 디렉토리를 생성. 
 - -p 옵션은 /lfs 아래의 디렉토리인 /mnt까지 함께 생성
 - -v 옵션은 결과 메시지 출력
- ```mount -v -t ext4 /dev/sdb1 $LFS``` : /dev/sdb1을 /mnt/lfs에 마운트
- grub을 통해 부팅에 성공할 때 까지 한 번도 컴퓨터를 다시 시작해서는 안됨 : Snapshot 이용
  - 만약 컴퓨터를 재시작하면, 파티션을 다시 mount 시켜야 함
  - 다시 시작할 때 마다 LFS 파티션을 자동으로 마운트하려면 호스트 시스템의 /etc/fstab 파일을 수정
    - /dev/sdb1  /mnt/lfs ext4   defaults      1     1 추가

### 3.1
- ```mkdir -v $LFS/sources``` : /mnt/lfs/sources 디렉토리 생성
- ```chmod -v a+wt $LFS/sources``` : 쓰기 가능, Sticky 부여
- ```wget http://www.linuxfromscratch.org/lfs/view/stable/wget-list``` : 다양한 패키지의 다운로드 주소가 들어 있는 wget-list를 다운로드
- ```wget --input-file=wget-list --continue --directory-prefix=$LFS/sources``` : wget-list에 있는 패키지를 $LFS/sources에 다운로드
- ```cd $LFS/sources```
- ```wget http://www.linuxfromscratch.org/lfs/view/stable/md5sums``` : wget-list로 다운받은 패키지들을 체크섬
```
pushd $LFS/sources
  md5sum -c md5sums
popd
```
- 체크섬 실행

### 4.2
```
mkdir -pv $LFS/{bin,etc,lib,sbin,usr,var}
case $(uname -m) in
  x86_64) mkdir -pv $LFS/lib64 ;;
esac
```
ㄴ 필요한 디렉토리 레이아웃 생성
- ```mkdir -pv $LFS/tools``` tools 디렉토리 생성

### 4.3
```
groupadd lfs
useradd -s /bin/bash -g lfs -m -k /dev/null lfs
```
ㄴ 'lfs' 계정 추가
- ```passwd lfs``` : lfs 계정 패스워드 설정
```
chown -v lfs $LFS/{usr,lib,var,etc,bin,sbin,tools}
case $(uname -m) in
  x86_64) chown -v lfs $LFS/lib64 ;;
esac
```
ㄴ lfs에게 $LFS 디렉토리의 전체 엑세스 권한 부여
- ```chown -v lfs $LFS/sources``` : $LFS/sources에 대한 소유권 부여
- ```su - lfs``` : lfs로 유저 변경
- **```export LFS=/mnt/lfs``` 재실행** 후 echo $LFS로 확인
### 4.4 : lfs 유저로 진행
```
cat > ~/.bash_profile << "EOF"
exec env -i HOME=$HOME TERM=$TERM PS1='\u:\w\$ ' /bin/bash
EOF
```
ㄴ 배쉬 쉘에 대한 파일을 만들어 줌
```
cat > ~/.bashrc << "EOF"
set +h
umask 022
LFS=/mnt/lfs
LC_ALL=POSIX
LFS_TGT=$(uname -m)-lfs-linux-gnu
PATH=/usr/bin
if [ ! -L /bin ]; then PATH=/bin:$PATH; fi
PATH=$LFS/tools/bin:$PATH
export LFS LC_ALL LFS_TGT PATH
EOF
```
ㄴ bashrc 설정
- ```source ~/.bash_profile``` : 계정 프로필 소싱

### 4.5
- ```export MAKEFLAGS='-j4'``` : make를 할 때 자동으로 -j4 옵션으로 실행
- ```make -j4``` : make 관련 명령어에 붙여 여러 프로세서(코어)를 사용하게 함
 - 명시적으로 -j4 외의 옵션이 달려있는 패키지 외엔 -j4 옵션을 붙여서 빌드하는 것이 좋음
 
### 패키지 빌드 지침 
- 반드시 ```echo $LFS```를 통해 ```export LFS=/mnt/lfs```로 되어 있는지 확인
 - 계정 전환 시 반드시 확인
- 모든 패키지 컴파일은 /mnt/lfs/sources에서 이루어짐
- tar를 통해 해당하는 패키지의 압축을 푼 후 해당 패키지의 이름을 가진 디렉토리로 이동
- 하나의 패키지 빌드가 끝나면 다시 $LFS/sources로 이동하여 rm -rf를 통해 방금 작업한 디렉토리 전체를 삭제해줌
- 중간에 계정 전환이 여러 번 이루어지므로, 이를 유의하여 진행
 - 잘못된 계정으로 빌드 시 Snapshot을 통해 다시 진행해야함

### 5.2
- 5.2~5.6은 패키지 빌드 지침에 따라 진행
- 여기서는 예시를 위해 5.2 빌드 과정을 명시하였음
 - ```tar -xvf binutils-2.35.tar.xz```를 통해 binutils 패키지를 빌드할 준비를 함
 - ```cd binutils-2.35``` : 패키지 빌드를 위해 경로 이동
```
mkdir -v build
cd       build
```
ㄴ 빌드를 위한 디렉토리인 'build' 디렉토리를 생성 후 이동
```
../configure --prefix=$LFS/tools       \
             --with-sysroot=$LFS        \
             --target=$LFS_TGT          \
             --disable-nls              \
             --disable-werror
```
ㄴ make 전의 환경 설정. 앞으로의 컴파일은 대부분 환경 설정 -> make -> make install의 순서로 이루어질 것임
 - ```make``` : make를 통해 패키지를 컴파일 함
 - ```make install``` : 패키지를 설치함
 - ```cd $LFS/sources``` : $LFS/sources 경로로 이동하여 다음 빌드를 준비
 - ```rm -rf binutils-2.35``` : 방금 빌드가 이루어진 디렉토리를 삭제함. 나중에 다시 빌드할때는 tar를 통해 다시 압축해제 후 진행

### 5.3~5.6 / 6.1~6.18까지 동일하게 진행
- 6.7.1 : ```make DESTDIR=$LFS install``` 명령어 시 warning 발생
 - libtool: warning: remember to run 'libtool --finish /usr/lib'
 - libtool: warning: 'libmagic.la' has not been installed in '/usr/lib'
 - 이 두개의 경고가 떠도 진행되므로, 무시하고 진행
 
