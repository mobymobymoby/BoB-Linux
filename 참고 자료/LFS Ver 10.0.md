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

### 2.5. Creating a File System on the Partition
- ```mkfs -v -t ext4 /dev/sdb1``` or ```mkfs.ext4 /dev/sdb1``` : sdb1이 생성된 파티션으로 가정

### 2.6
- ```export LFS=/mnt/lfs``` : 계정이 변경될 때마다 이를 입력하여 $LFS=/mnt/lfs가 되게 해주어야 함
 - 잘 설정되어있는지는 ```echo $LFS```를 통해 가능. /mnt/lfs가 출력되면 정상
 
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
- ```wget http://www.linuxfromscratch.org/lfs/view/stable/md5sums``` : wget-list로 다운받은 패키지들을 체크섬
```
pushd $LFS/sources
  md5sum -c md5sums
popd
```
