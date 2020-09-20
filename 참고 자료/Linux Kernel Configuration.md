## .config - Linux/x86 5.8.10 Kernel Configuration
===
### Overview
This interface lets you select features and parameters for the build.
이 인터페이스를 통해 빌드의 기능과 매개 변수를 선택할 수 있다. 
Features can either be built-in, modularized, or ignored. Parameters must be entered in as decimal or hexadecimal numbers or text.
기능은 내장, 모듈화 또는 무시될 수 있다. 매개변수는 소수 또는 16진수 숫자 또는 텍스트로 입력해야 한다.

Menu items beginning with following braces represent features that
다음 괄호로 시작하는 메뉴 항목은 이하의 기능을 나타낸다.
  [ ] can be built in or removed
  내장 또는 제거할 수 있다.
  < > can be built in, modularized or removed
  내장 또는 모듈화 또는 제거할 수 있다. (tristate)
  { } can be built in or modularized (selected by other feature)
  내장 또는 모듈화 가능하다.(다른 기능에 의해 선택됨)
  - - are selected by other feature,
  다른 기능에 의해 선택되었다.
while \*, M or whitespace inside braces means to build in, build as a module or to exclude the feature respectively
반면 Brace 내부의 \*, M 또는 공백은 각각 빌드, 모듈로 빌드 또는 기능을 제외하는 것을 의미한다.

To change any of these features, highlight it with the cursor keys and press <Y> to build it in, <M> to make it a module or  <N> to remove it.  You may also press the <Space Bar> to cycle through the available options (i.e. Y->N->M->Y).
이러한 기능을 변경하려면 커서 키로 강조 표시하고, <Y>를 눌러 내장하고, <M>을 눌러 모듈로 만들거나, <N>을 눌러 제거한다. 사용 가능한 옵션(예: Y->N->M->Y)을 순환하기 위해 <스페이스 바>를 누를 수도 있다.
