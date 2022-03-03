# OcrLiteOnnxLibTest

### Project下载

* 整合好源码和依赖库的完整工程项目，可以在Release中下载
* 可到Q群共享内下载: Project_OcrLiteOnnxLibTest.7z
* Q群号码参考主项目：https://github.com/DayBreak-u/chineseocr_lite

### 介绍

* 本项目为OcrLiteOnnx 动态运行库的调用范例。

### 依赖项下载

1. 下载opencv，[下载地址](https://github.com/RapidAI/OpenCVBuilder/releases)

* OpenCV静态库：opencv-(版本号)-平台.7z，
* 把压缩包解压到opencv-static目录，windows平台需要注意目录层次，解压后目录结构如下
* windows平台请选择vs2017版本(也可以用于vs2019编译)
* 程序版本v1.6.0需要opencv 4.5.4

```
opencv-static
├── OpenCVWrapperConfig.cmake
├── linux
├── macos
├── windows-x64
└── windows-x86
```

2. 下载OcrLib，[下载地址](https://github.com/benjaminwan/OcrLiteOnnx/releases)

* 文件名：平台-clib-.7z，
* 把压缩包解压到OcrLib目录，windows平台需要注意目录层次，解压后目录结构如下

```
OcrLib
├── Darwin-CLIB
│ ├── OcrLibConfig.cmake
│ ├── include
│ └── lib
├── Linux-CLIB
│ ├── OcrLibConfig.cmake
│ ├── include
│ └── lib
├── OcrLibWrapper.cmake
├── win-CLIB-Win32
│ ├── OcrLibConfig.cmake
│ ├── bin
│ ├── include
│ └── lib
└── win-CLIB-x64
    ├── OcrLibConfig.cmake
    ├── bin
    ├── include
    └── lib
```

### 编译环境

1. Windows 10 x64 + vs2019 + cmake(请自行安装)
2. macOS 10.15
3. Linux Ubuntu 1804 x64

### Windows编译说明

* windows双击build.bat，Linux&Mac ./build.sh
* 选择编译选项
* 按照编译完成的提示运行run-test脚本查看测试结果

### 注意事项for windows

* 如果是直接从github点击"download zip"按钮下载的代码，文件默认格式是Linux的
* 此时，需要把工程内的所有bat文件用UE等文本编辑器改为windows格式
