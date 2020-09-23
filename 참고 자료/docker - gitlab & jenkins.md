### docker 설치
- 설치 확인
  - ```docker --version```
  - 'docker' not found 메시지가 출력된다면 설치되지 않은 상태
- ```sudo apt install docker.io```
  - apt를 이용해 docker를 설치함
  - ```docker --version``` 명령어를 다시 실행하여 도커의 설치 확인
  - Docker version *.*.*, build *의 형식으로 출력되면 완료

### gitlab on docker
- gitlab 제공 문서 참고
  - https://docs.gitlab.com/omnibus/docker/ 
- ```export GITLAB_HOME=/srv/gitlab``` :  환경 변수 설정
  - ```echo $GITLAB_HOME```으로 설정 확인 가능
- gitlab에서 제공하는 docker image 실행 방법은 크게 3가지
  - **docker Engine 사용**
  - docker Compose 사용
  - docker swarm 모드 사용
- 해당 문서에서는 docker Engine을 사용하여 진행함
- 아래의 ```docker run``` 명렁어를 통해 gitlab 이미지 파일을 다운로드 함과 동시에 설치
  - ```docker run``` 명령어는 해당하는 이미지가 없다면, 자동으로 이를 다운로드하여 설치해줌
  - 사전에 별도로 이미지를 다운로드 하고 싶다면 ```docker pull install gitlab/gitlab-ce:latest``` 명령어 사용
  - 호스트네임, 포트 번호 등을 기호에 맞게 설정하여 설치
```
sudo docker run --detach \
  --hostname gitlab.example.com \
  --publish 443:443 --publish 80:80 --publish 22:22 \
  --name gitlab \
  --restart always \
  --volume $GITLAB_HOME/config:/etc/gitlab \
  --volume $GITLAB_HOME/logs:/var/log/gitlab \
  --volume $GITLAB_HOME/data:/var/opt/gitlab \
  gitlab/gitlab-ce:latest
```
ㄴ 맨 아래에 있는 ```gitlab/gitlab-ce:latest``` 부분을 변경하여서 자신이 원하는 이미지를 얻을 수 있음(ex. gitlab/gitlab-ce:lts)

- ```sudo docker logs -f gitlab``` : 초기화 프로세스 확인
  - 백그라운드에서 진행되는 초기화 과정을 확인할 수 있음
  - 5분 정도의 초기화 시간이 필요함
- 깃랩 도커 이미지 구성이 완료 되었다면, ```sudo docker exec -it gitlab /bin/bash```을 입력하여 컨테이너로 접속할 수 있음
- 포트포워딩을 위해 포트를 지정해줌
  - VirtualBox 기준  'NAT 네트워크(NAT 아님)'로 설정
    - VM VirtualBox 관리자에서 도구->환경설정->네트워크->NAT 네트워크 목록 중 해당하는 것->편집->포트포워딩
    - 프로토콜 : TCP / 호스트 IP : 호스트 PC의 IP / 호스트 포트 : 44480(임의로 부여) / 게스트 IP : 가상 머신의 IP(도커의 호스트가 되는 가상머신) / 게스트 포트 : 80
  - 호스트 PC에서 ```HOST IP:44480```을 주소창에 입력하여 gitlab에 접속 가능
  - **취소선은 안해도 되는 것으로 확인**
  - ~~```cd /etc/gitlab```로 이동하여 설정 파일에 접근~~
  - ~~```vim gitlab.rb```으로 설정 파일 변경~~
  - ~~vim 기준 찾기 명령어 '/'와 다음으로 넘기는 'n'을 이용해 'external_url' 부분을 찾음~~
    - ~~주석을 제거하고, ```external_url 'GENERATED_EXTERNAL_URL:포트번호'```으로 변경~~
- 초기 화면에서 새로운 패스워드를 지정해줌 : root의 비밀번호가 될 것임
- 그 이후 root / (방금 설정한 비밀번호)로 sign in
- new project를 이용해 프로젝트를 생성 가능
  - 여기에선 진행을 위해 "BoB Linux Project"라는 이름으로 생성했다고 가정
- 도커의 호스트(VirtualBox로 실행되고 있는 가상머신 리눅스)를 종료하게 되면, 다시 docker를 재실행해주어야 함
  - sudo systemctl start docker -> sudo docker start gitlab

### jenkins on docker with gitlab
- 위의 과정이 완벽히 되었다고 가정함
- 편의상 root로 진행(docker 안이 아닌, 버추어박스 가상머신의 root)
- https://hub.docker.com/ 로 이동하여 jenkins 검색
  - 맨 위에 있는 것은 가장 최신 버전이지만, 불안정할 수 있으므로 2번째 것을 선택
  - lts 버전과 latest 버전을 취사 선택
  - 여기서는 lts 버전으로 진행한다고 가정.
- ```docker pull jenkins/jenkins:latest``` : jenkins latest 이미지를 다운로드 받음
  - ```docker images``` 명령어를 통해 이미지가 잘 다운로드 받아졌는지 확인 가능
  - 정상적으로 따라왔다면, 위의 과정에서 설치한 gitlab과 jenkins(TAG : lts)의 이미지가 존재할 것임
- ```docker run -d -p 48080:8080 -p 50000:50000 -v /jenkins:/var/jenkins_home --name jenkins -u root jenkins/jenkins:latest```
  - 임의로 48080(변경 가능)라는 포트 번호를 할당함. 48080으로 접속하면 8080으로 포워딩 됨
  - 뒤의 포트번호는 slave 포트 번호로 추정
  - \-v 옵션을 통해 젠킨스 내부를 도커를 돌리는 호스트(버추어박스를 통한 가상머신 리눅스)에 공개함
  - \-u 옵션을 통해 계정을 root로 설정
  - 사실 위에서 docker pull을 통해 이미지를 다운로드 받지 않아도, 이 명령어를 실행하면 저절로 다운로드 받아짐
- ```docker ps``` 명령어를 통해 컨테이너가 잘 실행되고 있는지 확인할 수 있음
  - STATUS 열이 "UP (시간)"으로 되어있다면 성공
- 포트포워딩 설정
  - gitlab을 도커에 올릴 때의 과정과 동일하며, 호스트 포트 번호 48080로, 게스트 포트 번호를 8080으로 해주면 됨
- ```HOST IP:48080```을 주소창에 입력하여 접속. 단 여기서 HOST IP는 가상머신을 돌리고 있는 호스트임
  - 초기 비밀번호를 입력하는 창이 뜸
  - ```docker exec -it jenkins /bin/bash```을 통해 jenkins 컨테이너에 접속
  - /var/jenkins_home/secrets/ 디렉토리로 이동하여 ```cat initialAdminPassword```으로 초기 비밀번호 확인 후 로그인
- "install suggested plugins"를 선택하여 플러그인을 설치함 : 5분 정도 소요
- 몇 개의 항목은 설치가 안될 수 있음
  - Workspace Cleanup / Pipeline / Email Extension 3개가 설치 안된 것을 확인
- continue를 통해 진행하고, "Create First Admin User"에서는 skip and continue as admin으로 징행
  - 추후 admin의 패스워드를 바꿔주어야 함
- Instance Configuration에서는 자동으로 설정된 URL로 하고, Save and Finish
- '설정' 탭으로 가서 Password를 바꾸어줌
  - 바꾼 비밀번호로 재 로그인
- 'jenkins 관리' 탭 -> '플러그인 관리' -> gitlab 플러그인 체크 -> 플러그인 다운로드 후 재시작 -> "설치가 끝나고 실행중인 작업이 없으면 Jenkins 재시작" 체크
- "새로운 item" 탭
  - item 이름 정함
  - Freestyle Project 
  - 소스 코드 관리 : git -> 
  - Repository URL : 깃랩의 프로젝트 주소 
  - 크레덴셜 add -> jenkins 선택 -> username : gitlab의 아이디(root) / password : gitlab의 비밀번호 -> credential에서 추가된 것으로 바꾸기 -> 빨간 글씨 사라짐
  - Build when a change is pushed to GitLab 선택
    - URL 주소가 나와있는데, 이를 따로 메모 http://61.74.24.208:48080/project/test
  - 아래에 "고급" 클릭 -> Secret token에서 Generate 후 발생한 키를 메모 2cdcbc4ee73c3fd6c04df4e8b4818d0d
    - URL 주소와 시크릿 토큰을 이용함
- 저장
- gitlab으로 이동
  - Settings -> Webhooks 탭
  - URL : 위에서 나온 URL 주소 입력
  - Secret token : 위에서 나온 Secert token 입력 
  - Add webhook
- 아무 것이나 커밋해보면 젠킨스에서 이것이 기록되는 것을 확인 가능
  - 시간 동기화 : 사용자 설정 -> User Defined Time Zone을 Asia/Seoul로 변경



### Reference
- https://docs.gitlab.com/omnibus/docker/ 
- https://devyurim.github.io/development%20environment/docker/2018/06/27/docker-1.html
- https://wiserloner.tistory.com/171




  

