### made by Anna Lee
<h3> 1. Docker </h3>

도커란 <br>
리눅스의 응용 프로그램들을 소프트웨어 컨테이너 안에 배치시키는 일을 자동화하는 오픈 소스 프로젝트(가상화 플랫폼)

 - 컨테이너<br>
 : 격리된 공간에서 프로세스가 동작하는 기술<br>
 소프트웨어의 실행에 필요한 모든 것을 포함하는 완전한 파일시스템 안에 소프트웨어를 감싼 것<br>
 코드, 런타임, 시스템 도구, 시스템 라이브러리 등 서버에 설치되는 것들을 포함 함<br>
 컨테이너는 실행중인 환경에 관계없이 언제나 동일하게 실행될 것을 보증<br>

 - 이미지<br>
 : 컨테이너 실행에 필요한 파일과 설정값을 포함한 것, 상태값을 가지지 않고 변하지 않음<br>
 같은 이미지에서 여러개의 컨테이너 생성 가능<br>
 이미지 파일을 이용해 실행한 것을 컨테이너라고 볼 수 있음<br>

도커 주요 명령어<br>
 - 이미지 다운로드
```
docker pull [OPTIONS] NAME[:TAG|@DIGEST]
ex) docker pull ubuntu:18.04
```
 - 컨테이너 생성
```
docker run [OPTIONS] IMAGE[:TAG|@DIGEST] [COMMAND] [ARG...]
ex) docker run ubuntu:18.04 /bin/bash (ubuntu:18.04 이미지가 없는 경우 자동으로 다운로드 됨)
```
 - 실행한 컨테이너 목록 확인
```
docker ps -a
```
 - 컨테이너 시작/종료
```
docker start [PID]
docker stop [PID]
```
컨테이너 안에 들어갔을 때 빠져나올 경우 exit명령어 사용
 - 컨테이너 삭제
```
docker rm [PID]
```


<br>
<h3> 2. Gitlab </h3>

깃랩이란<br>
GitLab Inc에서 개발한 위키와 이슈추적 기능을 갖춘 웹 기반의 데브옵스(개발+운영) 시스템<br>
깃 저장소와 이슈 추적 기능을 갖춘 유일한 단일 어플리케이션의 데브옵스 솔루션<br>
설치형 버전관리 시스템으로 자신의 서버에 직접 Gitlab을 설치해서 사용할 수 있고, gitlab.com에서 서버 없이도 클라우드(유료-10명 이내의 프로젝트는 무료)에서 설치하여 사용 가능<br>
깃허브와 마찬가지로 'git clone 주소' 명령으로 레포지토리를 클론하여 사용할 수 있음<br>

 - 원격 저장소<br>
 : 비공개 저장소를 참여 인원과 관계없이 무제한으로 생성 가능<br>
 무료 사용자 기준 저장소 최대 용량은 10GB<br>
 원격 저장소의 url을 제공<br>

 - Wiki<br>
 : 일반인에게 보여줄 프로젝트의 지식 문서를 작성(문서화)<br>

 - 이슈 추적<br>
 : 기능 구현 및 추가, 버그 관리 등의 프로젝트 관리<br>
 변경 이력을 이슈로 확인할 수 있음<br>

 - 지속적인 통합 관리<br>
 : 작은 단위의 작업을 모아 (특정 시점이 아닌)지속적으로 통합 및 빌드과정을 수행<br>

 - 버전관리 시스템<br>
 : 소프트웨어를 제작하면서 발생하는 변화들 (수정.개선 등)을 기록하는 SW<br>
    - git<br>
 : 분산형 버전관리 시스템인 git을 사용
 clone, commit, add, push, pull 등의 명령을 이용

깃허브와 차이?<br>
 - Github : 공개적으로 관리하는 소스코드, 누구나 개선 제안 가능<br>
 - Gitlab : 개인 또는 조직이 내부 관리, 코드를 비공개로 유지하고 변경사항 배포 가능<br>

깃랩 사용
 - <b>git 사용법에 대해 알아야 함</b>
 - https://gitlab.com 회원가입
 - https://git-scm.com/ 에서 깃을 설치하여 git 명령 사용 가능
 - https://bitnami.com/stack/gitlab 에서 gitlab을 내려받을 수 있음

- 관리자<br>
: gitlab의 관리자 도구는 웹페이지 형식<br>
기본 사용자이름은 admin@local.host, 암호는 5iveL!fe
- 사용자<br>
: 한 사람당 하나의 계정을 가짐<br>
네임스페이스 단위를 이용해 프로젝트를 묶음<br>
ex) jane 사용자가 project라는 프로젝트를 진행 중이라면 프로젝트의 URL은 http://server/jane/project
- 그룹<br>
: 누가 어떤 프로젝트에 어떻게 접근할지에 대한 권한 데이터의 모음<br>
사용자처럼 프로젝트 네임스페이스가 있음<br>
ex) +training+라는 그룹이 +materials+라는 프로젝트를 가지고 있으면 URL은 http://server/training/materials
- 프로젝트<br>
: 하나의 Git 저장소 개념<br>
프로젝트마다 공개 수준을 지정할 수 있음<br>
    - Private - 프로젝트 소유자가 허락한 사람들만 접근 가능<br>
    - Internal - 로그인한 사용자에게만 보임<br>
    - Public - 모든 사람이 볼 수 있음<br>
 - 프로젝트 생성<br>
 : 프로젝트의 이름, 프로젝트 네임스페이스, 공개 수준을 입력 후 생성<br>
 로컬 Git 저장소와 연결하여 리모트 저장소를 등록<br>
 로컬 저장소가 없다면 clone 명령으로 복제<br>
 ```
 git remote add gitlab https://server/namespace/project.git
 ``` 
 ```
 git clone https://server/namespace/project.git
 ```
 - 협업<br>
    - 프로젝트 설정 페이지에서 "Members" 섹션에 같이 일할 사용자를 추가하여 Push 권한을 줄 수 있음<br>
    - "Developer" 이상의 권한의 사용자는 저장소에 Push 하거나 브랜치를 만들 수 있음<br>
    - Merge 요청을 하도록 해서 통제권을 유지한 채로 협업하는 방법도 있음
    

<br><br><br><br>
[참고]<br>
도커<br>
https://velog.io/@swhybein/Docker-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B0
https://ko.wikipedia.org/wiki/%EB%8F%84%EC%BB%A4_(%EC%86%8C%ED%94%84%ED%8A%B8%EC%9B%A8%EC%96%B4)
<br>깃랩<br>
https://opentutorials.org/module/567/4933
https://subicura.com/2017/01/19/docker-guide-for-beginners-1.html
https://en.wikipedia.org/wiki/GitLab
https://kkangeva.tistory.com/36
https://git-scm.com/book/ko/v2/Git-%EC%84%9C%EB%B2%84-GitLab
