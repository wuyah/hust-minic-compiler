# Hust-minic-compiler

A minic-compiler based on mini-c language, the framework of this repo is based on HUST Dr.Zhu's work.

The compile runnig on ubuntu 20.04 with flex & bison env, gcc 9.4.0 (gcc3.4.0 is required).

To get flex & bison, please use

```
sudo apt-get install flex
sudo apt-get install bison
```

The generated code run on MARS, a java based MIPS Simulator, you can download MARS on http://courses.missouristate.edu/kenvollmar/mars

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
- add logical operation in expression like `a = a<b`
- add semantic error type not match

TODO:
- float calculate
- NOT DPLUS DMINUS calculate
- array expression
- struct expression

