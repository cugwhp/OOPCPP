# C++课设题目

## 1. 图形绘制

### 功能需求

使用面向对象程序设计思想，编写一个简易的栅格图像矢量化程序，以栅格图像为底图，实现点、线、多边形的绘制功能，并能够存储矢量为文件。具体功能描述如下：

- File
  - Load Image - I：打开栅格图像文件，加载到视图窗口
  - Load Vector - V：打开矢量文件(.vec)，加载到视图窗口，与图像叠加显示
  - New Vector - N：新建矢量文件(.vec)，用于存放矢量文件
  - Save - S：保存绘制结果为矢量文件
- Draw
  - Point - P：绘制点，可设置点的大小与颜色
  - Line - L：绘制线，可设置线的粗细、颜色、样式
  - Polygon - Y：绘制多边形(封闭)，可设置多边形的边界的粗细、颜色和填充色
- Edit
  - Move - M：移动选中矢量的坐标
  - Delete - D：删除选中的矢量对象
  - Modify - O：修改选中矢量的颜色、线宽、样式等

### 实现步骤

#### Day0：[EasyX的安装与使用](D0_EasyX.md)

#### Day1：[搭建程序框架](D1_MainFrame.md)

#### Day2：矢量类的设计与实现

#### Day3-4：矢量类的功能实现

#### Day5：矢量图形的显示

#### Day6：矢量图形的编辑

#### Day7：功能集成

#### Day8：功能测试与报告撰写



### 参考文档

- [EasyX 官网](https://easyx.cn/)
- [EasyX 手册 1中文版](https://docs.easyx.cn/zh-cn/intro)  [2英文版](https://docs.easyx.cn/en-us/tutorials)
- 视频-[C++EasyX图形编程教程](https://www.51zxw.net/List.aspx?cid=802)
- 矢量化

## 2. 图像处理

已有
