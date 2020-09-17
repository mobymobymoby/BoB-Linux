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

### 5.3~5.6, 6.1~6.18까지 동일하게 진행
- 6.7.1 : ```make DESTDIR=$LFS install``` 명령어 시 warning 발생
 - libtool: warning: remember to run 'libtool --finish /usr/lib'
 - libtool: warning: 'libmagic.la' has not been installed in '/usr/lib'
 - 이 두개의 경고가 떠도 진행되므로, 무시하고 진행
- 6.16 : ```make DESTDIR=$LFS install``` 명령어 시 warning 발생
 - libtool: warning: '../../src/liblzma/liblzma.la' has not been installed in '/usr/lib'
 - libtool: warning: '../../src/liblzma/liblzma.la' has not been installed in '/usr/lib'
 - 이 경고 시 진행이 되는지는 다시 확인

### 7.1
- 7.1~7.4까지는 lfs에서 logout하여 root에서 진행
- 꼭 echo $LFS를 확인하여 환경변수가 잘 설정되었는지 확인

### 7.2
```
chown -R root:root $LFS/{usr,lib,var,etc,bin,sbin,tools}
case $(uname -m) in
  x86_64) chown -R root:root $LFS/lib64 ;;
esac
```
ㄴ Root user로 실행

### 7.3
- ```mkdir -pv $LFS/{dev,proc,sys,run}``` : 파일시스템이 마운트 될 디렉토리 생성
- ```mknod -m 600 $LFS/dev/console c 5 1```
- ```mknod -m 666 $LFS/dev/null c 1 3``` 
ㄴ 커널이 시스템을 부팅할 때 사용될 장치 노드
- ```mount -v --bind /dev $LFS/dev``` : /dev를 $LFS/dev에 마운트함
```
mount -v --bind /dev/pts $LFS/dev/pts
mount -vt proc proc $LFS/proc
mount -vt sysfs sysfs $LFS/sys
mount -vt tmpfs tmpfs $LFS/run
```
ㄴ 가상 커널 파일 시스템 마운트
```
if [ -h $LFS/dev/shm ]; then
  mkdir -pv $LFS/$(readlink $LFS/dev/shm)
fi
```
ㄴ 일부 시스템을 위한 if

### 7.4
```
chroot "$LFS" /usr/bin/env -i   \
    HOME=/root                  \
    TERM="$TERM"                \
    PS1='(lfs chroot) \u:\w\$ ' \
    PATH=/bin:/usr/bin:/sbin:/usr/sbin \
    /bin/bash --login +h
```
ㄴ 다음을 실행하여 chroot로 진행. **다시 부팅 전까지 앞으로 쭉 chroot로 진행됨**

### 7.5
- ```mkdir -pv /{boot,home,mnt,opt,srv}``` : 루트에 다양한 디렉토리 생성
```
mkdir -pv /etc/{opt,sysconfig}
mkdir -pv /lib/firmware
mkdir -pv /media/{floppy,cdrom}
mkdir -pv /usr/{,local/}{bin,include,lib,sbin,src}
mkdir -pv /usr/{,local/}share/{color,dict,doc,info,locale,man}
mkdir -pv /usr/{,local/}share/{misc,terminfo,zoneinfo}
mkdir -pv /usr/{,local/}share/man/man{1..8}
mkdir -pv /var/{cache,local,log,mail,opt,spool}
mkdir -pv /var/lib/{color,misc,locate}

ln -sfv /run /var/run
ln -sfv /run/lock /var/lock

install -dv -m 0750 /root
install -dv -m 1777 /tmp /var/tmp
```
ㄴ 하위 디렉토리 생성

### 7.6
- ```ln -sv /proc/self/mounts /etc/mtab```
- ```echo "127.0.0.1 localhost $(hostname)" > /etc/hosts```
```
cat > /etc/passwd << "EOF"
root:x:0:0:root:/root:/bin/bash
bin:x:1:1:bin:/dev/null:/bin/false
daemon:x:6:6:Daemon User:/dev/null:/bin/false
messagebus:x:18:18:D-Bus Message Daemon User:/var/run/dbus:/bin/false
nobody:x:99:99:Unprivileged User:/dev/null:/bin/false
EOF
```
ㄴ passwd 파일 생성
```
cat > /etc/group << "EOF"
root:x:0:
bin:x:1:daemon
sys:x:2:
kmem:x:3:
tape:x:4:
tty:x:5:
daemon:x:6:
floppy:x:7:
disk:x:8:
lp:x:9:
dialout:x:10:
audio:x:11:
video:x:12:
utmp:x:13:
usb:x:14:
cdrom:x:15:
adm:x:16:
messagebus:x:18:
input:x:24:
mail:x:34:
kvm:x:61:
wheel:x:97:
nogroup:x:99:
users:x:999:
EOF
``` 
ㄴ group 파일 생성

```
echo "tester:x:$(ls -n $(tty) | cut -d" " -f3):101::/home/tester:/bin/bash" >> /etc/passwd
echo "tester:x:101:" >> /etc/group
install -o tester -d /home/tester
```
ㄴ 테스터 계정 생성
- ```exec /bin/bash --login +h``` : I have no name -> root로 표시됨
```
touch /var/log/{btmp,lastlog,faillog,wtmp}
chgrp -v utmp /var/log/lastlog
chmod -v 664  /var/log/lastlog
chmod -v 600  /var/log/btmp
```
ㄴ 여러 로그인과 관련된 로그 기록

### 7.7~7.13
- 빌드 진행(chroot로)
 - 7.13 make install에서 libtool과 관련된 warning 다수 발생
 - 영향 없는지는 확인 필요
### 7.14 
- ```find /usr/{lib,libexec} -name \*.la -delete``` : libtool 관련 파일 제거
- ```rm -rf /usr/share/{info,man,doc}/*``` : 임시 도구의 문서 제거
- **중요 : 7.14 아래에 있는 것들은 백업을 위한 명령어들인데, 이것을 하기 위해서는 chroot 환경에서 나가야 함**
 - 하지만 스냅샷을 이용해 진행하므로, chroot에서 빠져나가지 않고 무시하여 챕터 8로 진행함
 - 8.3으로 이동하여 다시 패키지 설치

### 8.3~8.75
- 앞에서와 같이 진행해주면 됨. 단 chroot 상태에서 진행해야함
- 또한 몇 개의 패키지는 오류가 뜨는 경우가 있으나, 그냥 진행하여도 되는 경우가 있음. 보통 매뉴얼에서 명시됨
 - 하지만 어떤 패키지는 뜬금 없이 오류가 뜨는데, 다시 make와 make test(check)를 해주면 오류가 사라질 것임
 - 명시되지 않은 오류가 남아있다면 반드시 해결하고 갈 것. 이후에 큰 문제를 일으킬 수 있음
### 8.8 make check시 

```
Summary of test results:
      3 FAIL
   4233 PASS
     28 UNSUPPORTED
     17 XFAIL
      2 XPASS
make[1]: *** [Makefile:633: tests] Error 1
make[1]: Leaving directory '/sources/glibc-2.32'
make: *** [Makefile:9: check] Error 2

```

### 8.26 su tester -c "PATH=$PATH make -k check" 결과

```
skipping test framework tests, CHECK_TEST_FRAMEWORK is not defined

		=== gcc Summary ===

# of expected passes		112898
# of unexpected failures	7
# of expected failures		550
# of unsupported tests		1393
/sources/gcc-10.2.0/build/gcc/xgcc  version 10.2.0 (GCC) 

Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/x86_64/abi/callabi/callabi.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/x86_64/abi/ms-sysv/ms-sysv.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/xstormy16/xstormy16.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/xtensa/xtensa.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.test-framework/test-framework.exp ...
skipping test framework tests, CHECK_TEST_FRAMEWORK is not defined

		=== gcc Summary ===

# of expected passes		10200
# of expected failures		55
# of unsupported tests		190
/sources/gcc-10.2.0/build/gcc/xgcc  version 10.2.0 (GCC) 

Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/xstormy16/xstormy16.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/xtensa/xtensa.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.test-framework/test-framework.exp ...
skipping test framework tests, CHECK_TEST_FRAMEWORK is not defined

		=== gcc Summary ===

# of expected passes		17635
# of expected failures		57
# of unsupported tests		521
/sources/gcc-10.2.0/build/gcc/xgcc  version 10.2.0 (GCC) 

Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/xstormy16/xstormy16.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.target/xtensa/xtensa.exp ...
Running /sources/gcc-10.2.0/gcc/testsuite/gcc.test-framework/test-framework.exp ...
skipping test framework tests, CHECK_TEST_FRAMEWORK is not defined

		=== gcc Summary ===

# of expected passes		8555
# of expected failures		33
# of unsupported tests		117
/sources/gcc-10.2.0/build/gcc/xgcc  version 10.2.0 (GCC) 

make[3]: Leaving directory '/sources/gcc-10.2.0/build/gcc'
make[2]: Leaving directory '/sources/gcc-10.2.0/build/gcc'
make[1]: Target 'check-host' not remade because of errors.
make[1]: Leaving directory '/sources/gcc-10.2.0/build'
make: *** [Makefile:2350: do-check] Error 2
make: Target 'check' not remade because of errors.
(lfs chroot) root:/sources/gcc-10.2.0/build# 
```

- ../contrib/test_summary 결과
```
(lfs chroot) root:/sources/gcc-10.2.0/build# ../contrib/test_summary
cat <<'EOF' |
LAST_UPDATED: Obtained from git: releases/gcc-10.2.0 revision ee5c3db6c5b2c3332912fb4c9cfa2864569ebd9a

Native configuration is x86_64-pc-linux-gnu

		=== g++ tests ===


Running target unix
FAIL: g++.dg/asan/asan_test.C   -O2  (test for excess errors)
UNRESOLVED: g++.dg/asan/asan_test.C   -O2  compilation failed to produce executable
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C execution test
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C   -O0  execution test
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C   -O1  execution test
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C   -O2  execution test
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C   -O3 -g  execution test
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C   -Os  execution test
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C   -O2 -flto -fno-use-linker-plugin -flto-partition=none  execution test
FAIL: g++.dg/coroutines/torture/co-ret-17-void-ret-coro.C   -O2 -flto -fuse-linker-plugin -fno-fat-lto-objects  execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C   -O0  execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C   -O1  execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C   -O2  execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C   -O3 -g  execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C   -Os  execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C   -O2 -flto -fno-use-linker-plugin -flto-partition=none  execution test
FAIL: g++.dg/coroutines/torture/pr95519-05-gro.C   -O2 -flto -fuse-linker-plugin -fno-fat-lto-objects  execution test

		=== g++ Summary ===

# of expected passes		191448
# of unexpected failures	17
# of expected failures		709
# of unresolved testcases	1
# of unsupported tests		7994
/sources/gcc-10.2.0/build/gcc/xg++  version 10.2.0 (GCC) 

		=== gcc tests ===


Running target unix
FAIL: gcc.dg/asan/pr80166.c   -O0  (test for excess errors)
FAIL: gcc.dg/asan/pr80166.c   -O1  (test for excess errors)
FAIL: gcc.dg/asan/pr80166.c   -O2  (test for excess errors)
FAIL: gcc.dg/asan/pr80166.c   -O3 -g  (test for excess errors)
FAIL: gcc.dg/asan/pr80166.c   -Os  (test for excess errors)
FAIL: gcc.dg/asan/pr80166.c   -O2 -flto -fno-use-linker-plugin -flto-partition=none  (test for excess errors)
FAIL: gcc.dg/asan/pr80166.c   -O2 -flto -fuse-linker-plugin -fno-fat-lto-objects  (test for excess errors)

		=== gcc Summary ===

# of expected passes		149288
# of unexpected failures	7
# of expected failures		695
# of unsupported tests		2221
/sources/gcc-10.2.0/build/gcc/xgcc  version 10.2.0 (GCC) 

		=== libatomic tests ===


Running target unix

		=== libatomic Summary ===

# of expected passes		54
		=== libgomp tests ===


Running target unix

		=== libgomp Summary ===

# of expected passes		2664
# of expected failures		2
# of unsupported tests		302
		=== libitm tests ===


Running target unix

		=== libitm Summary ===

# of expected passes		42
# of expected failures		3
# of unsupported tests		1
		=== libstdc++ tests ===


Running target unix
FAIL: 22_locale/time_get/get_time/char/2.cc execution test
FAIL: 22_locale/time_get/get_time/char/wrapped_env.cc execution test
FAIL: 22_locale/time_get/get_time/char/wrapped_locale.cc execution test
FAIL: 22_locale/time_get/get_time/wchar_t/2.cc execution test
FAIL: 22_locale/time_get/get_time/wchar_t/wrapped_env.cc execution test
FAIL: 22_locale/time_get/get_time/wchar_t/wrapped_locale.cc execution test

		=== libstdc++ Summary ===

# of expected passes		14140
# of unexpected failures	6
# of expected failures		93
# of unsupported tests		390

Compiler version: 10.2.0 (GCC) 
Platform: x86_64-pc-linux-gnu
configure flags: --prefix=/usr LD=ld --enable-languages=c,c++ --disable-multilib --disable-bootstrap --with-system-zlib
EOF
Mail -s "Results for 10.2.0 (GCC) testsuite on x86_64-pc-linux-gnu" gcc-testresults@gcc.gnu.org &&
mv /sources/gcc-10.2.0/build/./gcc/testsuite/g++/g++.sum /sources/gcc-10.2.0/build/./gcc/testsuite/g++/g++.sum.sent &&
mv /sources/gcc-10.2.0/build/./gcc/testsuite/gcc/gcc.sum /sources/gcc-10.2.0/build/./gcc/testsuite/gcc/gcc.sum.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libatomic/testsuite/libatomic.sum /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libatomic/testsuite/libatomic.sum.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libgomp/testsuite/libgomp.sum /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libgomp/testsuite/libgomp.sum.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libitm/testsuite/libitm.sum /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libitm/testsuite/libitm.sum.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libstdc++-v3/testsuite/libstdc++.sum /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libstdc++-v3/testsuite/libstdc++.sum.sent &&
mv /sources/gcc-10.2.0/build/./gcc/testsuite/g++/g++.log /sources/gcc-10.2.0/build/./gcc/testsuite/g++/g++.log.sent &&
mv /sources/gcc-10.2.0/build/./gcc/testsuite/gcc/gcc.log /sources/gcc-10.2.0/build/./gcc/testsuite/gcc/gcc.log.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libatomic/testsuite/libatomic.log /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libatomic/testsuite/libatomic.log.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libgomp/testsuite/libgomp.log /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libgomp/testsuite/libgomp.log.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libitm/testsuite/libitm.log /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libitm/testsuite/libitm.log.sent &&
mv /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libstdc++-v3/testsuite/libstdc++.log /sources/gcc-10.2.0/build/./x86_64-pc-linux-gnu/libstdc++-v3/testsuite/libstdc++.log.sent &&
true
(lfs chroot) root:/sources/gcc-10.2.0/build# 
```

### 8.43
- make test를 하지 않는 것을 추천
 - 시간도 훨씬 오래 걸리고, FAIL이 많이 뜨게 됨(bash와 libtool 관련) : 매뉴얼에 명시되어 있음 
