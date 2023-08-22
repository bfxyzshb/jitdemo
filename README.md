jitdemo 即时编译jit原理demo
=======

Demo programs for my blog entry "Hello, JIT World!"
# compile
- lua ./third_party/dynasm/dynasm.lua jit2.dasc > jit2.h
- lua ./third_party/dynasm/dynasm.lua jit3.dasc > jit3.h
- make
# run
- ./jit2 42;echo $?
  - 输出:42
- ./jit3 "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."
  - 输出:Hello World!
