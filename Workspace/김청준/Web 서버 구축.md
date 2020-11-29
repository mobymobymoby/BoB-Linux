#nginx 설정
- 멘토님 서버에서는 /etc/nginx/sites-available/default를 수정하여 진행
  - /etc/nginx/sites-enabled/default는 /etc/nginx/sites-available/default에 심볼릭 링크임
  - /etc/nginx/sites-available/default 에서 listen 부분의 '80'을 '443'으로 바꿔줌
  - IP 또는 boblinux.fossa.kr:21443으로 접속 가능
 
- 디렉토리 리스팅
  - /etc/nginx/sites-available/default 수정
    - location / { } 부분에 아래의 내용 추가
```
root /var/www/html/files; 
autoindex on;
```
  - 이렇게 하면 boblinux.fossa.kr:21443 접속시 /var/www/html/files의 파일 목록이 출력
  - 만약 해당 디렉토리에 index.html이 있다면, 디렉토리 리스팅 대신 index.html의 내용이 출력
  
- 디렉토리 리스팅을 통하지 않고도 파일 링크 가능
  - 하이퍼 링크를 이용하면 됨
  - ```<a href="[파일 이름]"> [텍스트] </a>```
  - 사진도 비슷한 방법으로 링크 가능
