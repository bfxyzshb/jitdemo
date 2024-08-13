jit是将热点代码翻译成机器码，加速程序运行
=======
jitdemo 即时编译jit原理demo,帮助理解跨平台语言代码（java python lua等）怎么转成机器码（注意不是字节码）运行原理
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
