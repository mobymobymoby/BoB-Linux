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
- 



  

