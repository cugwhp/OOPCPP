# Qt的安装与配置

为了方便大家使用Qt，我把Qt的下载，使用的资料附于此：

## 1. Qt Download
[最新版本Qt5.10.1](http://download.qt.io/archive/qt/5.10/5.10.1/qt-opensource-windows-x86-5.10.1.exe)

当然，你也可以选择其他适合自己的[版本](http://download.qt.io/archive/qt)

## 2. Qt Setup
Qt安装安装步骤参照<https://blog.csdn.net/liang19890820/article/details/53931813#%E9%85%8D%E7%BD%AE-qt-creator>

## 3.Qt Options
Qt使用有2种，一种是QtCreator，一种是VS插件，这两种方式各有优劣。

- QtCreator的优势是轻便、开源免费；
[Set Qt MinGW](https://blog.csdn.net/liang19890820/article/details/49894691)

- VS的优势是效率高，调试方便。具体设置见：
[Set Qt for VS](https://blog.csdn.net/liang19890820/article/details/49874033)

## 4. Compile GDAL & OpenCV in MinGW
### 4.1 Download source code

- MinGW
在安装Qt的时候，已经顺带安装了，MinGW是一个编译器，跨平台

- [CMake](www.cmake.org)
GUI方式生成各类编译器识别的makefile
Windows 下载地址<https://cmake.org/files/v3.11/cmake-3.11.1-win64-x64.zip>

- OpenCV
从<www.opencv.org>下载

- [GDAL下载](http://download.osgeo.org/gdal)

### 4.2 Environment
设置各类系统变量，参见<https://blog.csdn.net/asklw/article/details/72566428>

### 4.3 Compile
- [Compile GDAL With MinGW](http://trac.osgeo.org/gdal/wiki/BuildingWithMinGW)

- [Compile OpenCV With MinGW](https://blog.csdn.net/asklw/article/details/72566428)
