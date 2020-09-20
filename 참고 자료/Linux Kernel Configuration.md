## .config - Linux/x86 5.8.10 Kernel Configuration
===
### Overview
This interface lets you select features and parameters for the build.
Features can either be built-in, modularized, or ignored. Parameters must be entered in as decimal or hexadecimal numbers or text.

*Menu items beginning with following braces represent features that*
  [ ] can be built in or removed
  < > can be built in, modularized or removed
  { } can be built in or modularized (selected by other feature)
  - - are selected by other feature,
while *, M or whitespace inside braces means to build in, build as a module or to exclude the feature respectively

To change any of these features, highlight it with the cursor keys and press <Y> to build it in, <M> to make it a module or  <N> to remove it.  You may also press the <Space Bar> to cycle through the available options (i.e. Y->N->M->Y).
