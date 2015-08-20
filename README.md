# KGB Debugger #

KGB Debugger is a powerful, modular, general-purpose debugger to help fix memory leaks, perform profiling and optimizations via static analysis and runtime monitoring.

## Philosophy ##

Many (open source) hackers are proud if they achieve large amounts of code, because they believe the more lines of code they’ve written, the more progress they have made. The more progress they have made, the more skilled they are. This is simply a delusion.

Most hackers actually don’t care much about code quality. Thus, if they get something working which seems to solve a problem, they stick with it. If this kind of software development is applied to the same source code throughout its entire life-cycle, we’re left with large amounts of code, a totally screwed code structure, and a flawed system design. This is because of a lack of conceptual clarity and integrity in the development process.

Code complexity is the mother of bloated, hard to use, and totally inconsistent software. With complex code, problems are solved in suboptimal ways, valuable resources are endlessly tied up, performance slows to a halt, and vulnerabilities become a commonplace. The only solution is to scrap the entire project and rewrite it from scratch.

The bad news: quality rewrites rarely happen, because hackers are proud of large amounts of code. They think they understand the complexity in the code, thus there’s no need to rewrite it. They think of themselves as masterminds, understanding what others can never hope to grasp. To these types, complex software is the ideal.

Ingenious ideas are simple. Ingenious software is simple. Simplicity is the heart of the Unix philosophy. The more code lines you have removed, the more progress you have made. As the number of lines of code in your software shrinks, the more skilled you have become and the less your software sucks.

## Usage ##

KGB comes by default with three modules: kgb-analyze, kgb-optimize, kgb-mem.

#### kgb-analyze ###

This module performs static code analysis and tries to locate and fix common programming and memory errors.
Execute it in a directory; it will locate source files recursively.
It can understand many programming languages: C, C++, Java, Objective-C, C#, Scala, Ruby, PHP, Swift, Visual Basic, Perl, and many others.

Usage: kgb-analyze dirname

### kgb-optimize ###

This module optimizes compiled executables and bytecode by detecting and removing unneeded code sections.

Usage: kgb-optimize filename

### kgb-mem ###

This module analyzes memory usage of a program. Outputs a graph of memory errors.

Usage: kgb-mem filename

## License ##

The MIT License (MIT)

Copyright (c) 2015 Rei <https://github.com/sovietspaceship>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

***THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.***
