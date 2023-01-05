# Hust-minic-compiler

A minic-compiler based on mini-c language, the framework of this repo is based on hust Dr.Zhu's work.

The compile runnig on ubuntu 20.04 with flex & bison env.

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