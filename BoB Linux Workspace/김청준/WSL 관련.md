### WSL : 윈도우에서 바로 리눅스 사용 가능
- 여러 이미지를 Microsoft Store에서 다운로드 가능
  - Ubuntu-20.04 LTS
- WSL 전용 이미지 파일을 만드는 작업이 있는 것 같음. 하지만 매우 복잡
  - 만약 WSL 전용 배포이미지를 내놓는다면?
    - 마이크로소프트 스토어에서 제공하는 공식 우분투 이미지를 이용
    - 그 우분투에 트레이너 내장
    - 그 후에 wsl 이미지 내보내기를 이용해 배포
    - 하지만, 우리가 작업하는 ova파일을 불러올 수 있는 방법을 찾지 못했으므로, 보안 점검은 불가

- WSL 가져오기 / 내보내기
```wsl --list --all``` 모든 wsl 이미지 리스트 보기<br\>
```wsl --import <Name of the distro> <Fill path to save the backup .tar file>``` : wsl 이미지 가져오기<br\>
```wsl --export <Name of the distro> <Fill path to save the backup .tar file>``` : wsl 이미지 내보내기<br\>
