# Hust-minic-compiler

A minic-compiler based on mini-c language, the framework of this repo is based on HUST Dr.Zhu's work.

The compile runnig on ubuntu 22.04 with flex 2.6.4 & bison 3.8.2 env, gcc 11.3.0 (gcc3.4.0 is required), GNU Make 4.3

To get flex & bison, please use

```
sudo apt-get install flex
sudo apt-get install bison
```

To use the new version of bison and use the [-Wcounterexamples], you need to update your linux version to 22.04, otherwise you can't use the newest tool which can list the conflict example.

The generated code can run on MARS, a java based MIPS Simulator, you can download MARS on http://courses.missouristate.edu/kenvollmar/mars

To run this simulator, you need to have java enviornment, which you can use 

```
sudo apt-get install default-jre
```

to run this silmulator, use

```
java -jar Mars4_5.jar
```

> _Notice_<br>
    I change the running platform to QTspim as the MARS can't support float immediate number. Which is not good enough for float design. <br>
    To get QTspim, please see: http://pages.cs.wisc.edu/~larus/spim.html a GUI version is prefered to get.

current finished:

- add `for loop` display and `for loop` object code
- add logical operation in expression like `a = a < b`
- add semantic error type not match
- float calculate
- NOT calculate and NOT float calculate
- if-else-then fixed
- array dec / array call ast finished 2023.1.8
- oneline comment finished using lex.l
- read()/write() function can be called immediately
- int array finished (float also satisfied)
- `break` / `continue` finished
- `++` `--` calculate(they should only work for INT)
- `&&` `||` operator use in calculation(INT and FLOAT)
- use ID to judge if the number is INT or FLOAT

TODO:
- struct expression
- type error in function return
- *= += /= -= 
- %
- ir optimization
- reg optimization
