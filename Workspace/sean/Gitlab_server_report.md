Gitlab은 Github와 비슷하지만 자신의 서버에 설치할 수 있는 서비스이다.

Gitlab.io를 이용해도 되지만 자신의 서버에 연결하고 싶다면 GItlab을 설치하여 자신의 서버를 사용하면 된다.

Gitlab은 프로젝트용으로 사용할 비공개 레포지토리를 무료로 인원 제한 없이 이용할 수 있기 때문에 Gitlab을 이용하고, 각 레포지토리의 크기도 Github보다 커서 좋다.

(Github : 최대 1GB)

---

---

# [제공된 기본 환경]

1. __멘토님 서버의 https(443) 포트가 포트포워딩 되어 있다.__
2. __내부 포트는 443이고, 외부 포트는 21443으로 되어있어서 외부에서 IP 또는 도메인 뒤에 ":21443"이라고 입력하면 자동으로 내부 포트의 443 포트로 연결된다.__
3. __http(80) 포트는 아파치가 돌아가고 있지만, 포트포워딩이 되어 있지 않아 외부에서 접속은 안된다.__
4. __방화벽이 열려있지 않으므로 iptables로 열어야 한다.__
5. __멘토님 서버 ip는 http://boblinux.fossa.kr 이라는 도메인으로 연결되어 있다.__
6. __ubuntu 18.04.01__

---

---

# [Giblab 설치 및 설정]

[https://teamlab.github.io/jekyllDecent/blog/tutorials/나만의-Git-서버-Gitlab-구축](https://teamlab.github.io/jekyllDecent/blog/tutorials/%EB%82%98%EB%A7%8C%EC%9D%98-Git-%EC%84%9C%EB%B2%84-Gitlab-%EA%B5%AC%EC%B6%95)


//기본적인 패키지 설치

1.

    sudo apt-get install curl openssh-server ca-certificates
    - postfix는 메일 발신 관련이여서 이용하지 않을 것이기에 설치하지 않았으므로 총 3개의 패키지만 설치.
    - 만약 설치한다면, 설치 중 나오는 옵션은 No configuration으로 설정.
    - sudo dpkg-reconfigure postfix 명령으로 변경 가능.


//gitlab 패키지 프로그램 저장소 추가

2.

    $curl -sS [https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh](https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh) | sudo bash

- 약간의 시간이 걸릴 수 있음.


//저장소 목록 업데이트

3.

    sudo apt-get update


//gitlab community edition 설치

4.

    sudo apt-get install gitlab-ce

- 설치가 완료되면 노란 별 기호로 Gitlab 로고가 보임.


// Gitlab 초기 설정

5.

    sudo gitlab-ctl reconfigure

- Gitlab을 구성하는 gitlab.rb라는 루비 파일로 초기 설정.
- /etc/gitlab/gitlab.rb


//url과 nginx등 Gitlab과 관련된 설정

6.

    sudo vi /etc/gitlab/gitlab-rb

- url과 업로드 크기를 변경함.
- 위의 블로그에서는 gitlab_workhorse와 unicorn['port'] 부분을 바꾸라고 했지만 이 두 곳을 블로그에서 하라는 대로 같은 port로 했는데 내부 포트 충돌인 502 에러 코드 반환됨.
- 다른 port로 해도 502 에러 코드 반환됨.
- 총 변경한 것은 2개

![url](https://user-images.githubusercontent.com/68282265/101453175-41ec6b00-3972-11eb-93d2-fcd82db4ec94.jpeg)

![nginx_clinet_max_body_size](https://user-images.githubusercontent.com/68282265/101453276-72340980-3972-11eb-9a12-7db7b7629436.jpeg)



//gitlab 적용 및 재시작

7.

    sudo gitlab-ctl reconfigure

8.

    sudo gitlab-ctl restart

- 7번의 명령은 파일을 조금이라도 수정하였다면 수행해주어야 적용됨.


//gitlab 상태 확인.

9.

    sudo gitlab-ctl status

- 필수적인 명령은 아니지만 상태 확인을 할 때 쓰는 명령.


//https 방화벽 오픈

10.

    sudo iptables -A INPUT -p tcp -m tcp —sport 443 -j ACCEPT

    sudo iptables -A OUTPUT -p tcp -m tcp —dport 443 -j ACCEPT

![iptables](https://user-images.githubusercontent.com/68282265/101453352-8c6de780-3972-11eb-97f8-1143865c87d4.png)


//접속 후 확인

11. https://boblinux.fossa.kr:21443이라고 입력하면 접속 완료.

- Gitlab 공식 사이트가 아닌, boblinux Gitlab 서버에서 계정 등록을 하고, boblinux Gitlab 관리자 계정으로 접속하여 아래의 절차대로 진행하면 가입 완료.
(자세한 건 아래의 사진 참고)
    1. 왼쪽 상단의 스패너 아이콘이나, more 메뉴에서 Admin Area 메뉴를 들어간다.
    2. 들어가면 가운데 열 아래에 Latest users가 보인다.
    3. Latest users에서 보이는 사용자 이름을 클릭하여 들어간다.
    4. 오른쪽에 approve ~버튼을 누르면 승인이 되고, 가입 완료된다.

![boblinux_gitlab_server_1](https://user-images.githubusercontent.com/68282265/101453377-9859a980-3972-11eb-85a7-be5de40e82df.jpeg)

![boblinux_gitlab_server_2](https://user-images.githubusercontent.com/68282265/101453436-ac9da680-3972-11eb-92b1-a97d8674c1fe.jpeg)

![boblinux_gitlab_server_3](https://user-images.githubusercontent.com/68282265/101453440-ae676a00-3972-11eb-90b1-10dfea5c5c0a.jpeg)

![boblinux_gitlab_server_4](https://user-images.githubusercontent.com/68282265/101453443-af989700-3972-11eb-9bc4-69c206a7e4ff.jpeg)


// Gitlab 서버에 있는 레포지토리 clone

12.

    git clone [https://boblinux.fossa.kr:2144](https://boblinux.fossa.kr:2144)3/blackmoon/bob-linux.git

- 만약 ssl 관련 오류가 뜨면서 clone이 안된다면 아래의 명령어를 입력 후 clone 진행.
- git config --global http.sslVerify false


[//Gitlab](//gitlab) 삭제

[https://am-learning.tistory.com/160](https://am-learning.tistory.com/160)

13. 

        sudo gitlab-ctl uninstall
        
        sudo gitlab-ctl cleanse

        sudo gitlab-ctl remove-accounts

        sudo dpkg -P gitlab-ce || sudo yum -y remove gitlab-ce

- 데비안이면 앞의 명령이, 레드햇이면 뒤의 명령이 실행.

        sudo rm /opt/gitlab

        sudo rm /var/opt/gitlab

        sudo rm /etc/gitlab

        sudo rm /var/log/gitlab

---

---

# [Gitlab 페이지에 ssl 적용]

[https://yjunyoung.tistory.com/entry/8-Gitlab-SSL-적용](https://yjunyoung.tistory.com/entry/8-Gitlab-SSL-%EC%A0%81%EC%9A%A9)

[https://lunightstory.tistory.com/6](https://lunightstory.tistory.com/6)

//openssl 설치 여부

1. 
        
        openssl version
    - openssl이 설치되어 있지 않다면 설치 필요.

       ![openssl_version](https://user-images.githubusercontent.com/68282265/101453516-cd65fc00-3972-11eb-8e5a-8ebe6e1aa105.png)


//개인키 생성

2.

    opensslgenrsa -des3 -out boblinux_server.key 2048


//인증서 요청 생성

3.

    openssl req -new -key boblinux_server.key -out boblinux_server.csr

Country Name ( 국가코드) [] : KR

State or Province Name ( 지역 ) [] : Seoul

Locality Name ( 시/군/구 ) [] : Geumcheon

Organization Name ( 회사명 ) [] : BoB

Organizational Unit Name ( 부서명 ) [] : blackmoon

Common Name ( 서비스도메인명 ) [] : boblinux.fossa.kr

Email Address [] : 

- 이 다음 항목은 전부 enter 입력


// 개인키 암호를 제거

4.

    cp boblinux_server.key boblinux_server.key.org

5.
   
    openssl rsa -in boblinux_server.key.org -out boblinux_server.key


//인증서 생성

6.
        
        openssl x509 -req -days 3650 -in boblinux_server.csr -signkey boblinux_server.key -out boblinux_server.crt

//생성 확인

7.
        
        cat boblinux_server.key | head -3

8. 
        
        cat boblinux_server.crt | head -3

![openssl_1](https://user-images.githubusercontent.com/68282265/101453607-f4bcc900-3972-11eb-8ed3-09ed5cd4c592.PNG)


//key 파일과 crt 파일의 이름을 도메인 이름으로 바꿔서 복사.

9.

        mv boblinux_server.key boblinux.fossa.kr.key

10.

        mv boblinux_server.crt boblinux.fossa.kr.crt


//디렉토리 생성 후 인증서 파일 두개 복사

11.

        sudo mkdir -p /etc/gitlab/ssl

12.
        
        sudo chmod 700 /etc/gitlab/ssl

13.
        
        sudo cp boblinux.fossa.kr.crt /etc/gitlab/ssl/

14.
        
        sudo cp boblinux.fossa.kr.key /etc/gitlab/ssl/

![openssl_2](https://user-images.githubusercontent.com/68282265/101453610-f5555f80-3972-11eb-98be-8227a783497d.png)

//gitlab 설정 적용 및 재시작

15.

    sudo gitlab-ctl reconfigure

16.

    sudo gitlab-ctl restart


//접속 확인

17. https://boblinux.fossa.kr:21443

---

---

# [Issues]

1. __/etc/gitlab/gitlab.rb 파일의 http_to_https의 값을 true로 바꿨는데 502 반환.__
2. __certbot(let's encrypt)를 이용하려 했지만, let's encrypt는 http(80) 포트를 기반으로 접속 여부를 확인하여 생성하는데 현재 서버의 http(80) 포트는 포트포워딩이 안되어 있어서 외부에서 접속이 불가능하므로 방화벽 오류가 뜨기 때문에 생성 불가.__
3. __서버에 80포트는 아파치 웹 서비스가 사용 중이여서, 아파치를 끄고 진행함.__


# [참고 블로그]

1. [https://docs.gitlab.com/omnibus/settings/nginx.html#redirect-http-requests-to-https](https://docs.gitlab.com/omnibus/settings/nginx.html#redirect-http-requests-to-https)
2. [https://docs.gitlab.com/omnibus/settings/ssl.html](https://docs.gitlab.com/omnibus/settings/ssl.html)
3. [https://mitny.github.io/articles/2019-01/LetsEncrypt](https://mitny.github.io/articles/2019-01/LetsEncrypt)
4. [https://oofbird.tistory.com/39](https://oofbird.tistory.com/39)
5. [https://linux.systemv.pe.kr/gitlab-패스워드-리셋하기/](https://linux.systemv.pe.kr/gitlab-%ED%8C%A8%EC%8A%A4%EC%9B%8C%EB%93%9C-%EB%A6%AC%EC%85%8B%ED%95%98%EA%B8%B0/)
6. [http://wiki.webnori.com/display/cicd/Gitlab+SSH](http://wiki.webnori.com/display/cicd/Gitlab+SSH)
