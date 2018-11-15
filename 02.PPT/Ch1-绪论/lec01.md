第二章 The overview of C++ language
===

本章简要介绍C++语言的基础内容：C++程序的组成和结构、输出输出、注释、控制流和类简介等最基本的内容。本章的目的是为了展现简单的C++程序的全貌，对程序的结构有所了解。通过本章的学习，学生需要具备编写、编译及运行简单程序的能力。

# 1. 编写一个简单的C++程序
每个C++程序都包含一个或多个函数（function），其中一个必须命名为**main**。main函数是程序的入口，操作系统通过调用main来运行程序。最为简单的main函数什么也不做，只是返回操作系统一个值：
```c++
int main()
{
    return 0;
}
```
## 1.1 函数的组成
从main函数中可以看出，函数的组成包含4个部分：
- ①返回类型-return type，此处是int；
- ②函数名-function name，此处是main；
- ③形参列表-parameter list，是()里的内容，此处是空；
- ④函数体 - function body，即{ }所包含的语句。

|   小结   |内容                                                              |
| ---- | ------------------------------------------------------------ |
| Note | return 语句的分号。在C++中，大多数语句以“;"结束。它们很容易被忽略，如果忘记了书写";"，会导致莫名其妙的变异错误。 |
|重要概念|类型是程序设计最基本的概念之一。一种类型不仅定义了数据元素的内容，还定义了这类数据上可以进行的运算。程序所处理的数据都保存在变量中，而每个变量都有自己的类型。|

## 1.2 编译、运行程序
编译程序我们通常会借助于IDE (Integrated Development Environment)，来编译、调试和分析程序。IDE是一组用于生产程序的工具包的集成系统，学会使用IDE可以提高编程效率。
除了使用软件界面来编译和调试程序，通过命令行也可以完成源代码的编译和运行。
Compiler 也是有多个不同的版本，如：Visual Studio有自带的编译器，GNU GCC是一个开源的编译器。二者均可以编译C++源代码，但二者的编译结果不可以混用。

## 1.3 Exercise
- Ex1：查阅你所使用的编译器文档，确定它所使用的文件命名约定。如何运行程序
- Ex2：改写程序，让它返回-1.返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

# 2. 输入输出
我们知道，程序即为执行某些任务的指令集。事实上，程序有指令集（源代码）组成，但就如烹饪，没有食材徒有工艺可不行。那什么是程序的食材呢，那就是-数据。从这个类比可以看出，程序就是将输入到程序的食材（数据），经过加工，变成菜肴的过程。因此程序有时也被称为：程序=数据结构+算法。
那么数据从何而来呢？比如遥感卫星就是一种获取数据的绝佳方式。那么对于计算机而言，数据从何而来呢？一方面数据来自于文件，由各种传感器和人为创建的数据；另一个途径，来源于我们面前的鼠标和键盘，即输入设备。
对于简单的程序，我们如果要从输入设备获取数据，应该怎么办呢？此时，我们需要借助于C++系统库-iostream。iostream包含两个基础的类型istream和ostream，分别为输入流和输出流。
标准的输入输出对象有4个。
- cin 是istream类型的对象，被称之为标准输入-standard input
- cout 是ostream类型的对象，被称之为标准输出 - standard output
- cerr 是ostream类型的对象，用于输出erro，被称为标准错误 - standard error
- clog 是ostream类型的对象，用于输出日志

## 2.1 IO Example
我们想做一个加法运算的程序，用户输入两个整数a和b，程序输出a+b的结果。
```c++
#include <iostream>
int main()
{
    std::cout << "Input 2 int Numbers: "
    int	v1, v2;
    std::cin >> v1 >> v2;
    std::cout << v1+v2 << std::endl;
    return 0;
}
```
## 2.2 Exercise
- Ex3: 编写程序，在标准输出上打印Hello, World。
- Ex4 编写程序使用乘法运算符"*"，来打印两个数的积。
- Ex5:解释下吗程序片段是否合法 std::cout << "The sum of " << v1;
         << " and " << v2;
         << " is " << v1 + v2 << std::endl;
         
```c++
#include <iostream>
int main()
{
    std::cout << "Hello World." << std::endl;
    return 0;
}
```



## 3. 注释(comments)
注释可以帮助人类读者理解程序。注释通常用于概述算法、说明变量的用途或者解释晦涩难懂的代码段。编译器会忽略注释，因此注释不会对程序的行为和性能有任何影响。
错误的注释比完全没有注释更为糟糕，因为它会误导读者。因此，当你修改了代码时，也不要忘记同时更新注释！
- 当行注释 //
- 界定符对注释 /* 和 */
```c++
/******************************************************************************
 * $Id: gdal.h 23431 2011-11-27 15:02:24Z rouault $
 *
 * Project:  GDAL Core
 * Purpose:  GDAL Core C/Public declarations.
 * Author:   Frank Warmerdam, warmerdam@pobox.com
 *
 ******************************************************************************
 * Copyright (c) 1998, 2002 Frank Warmerdam
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/
 
/*! Pixel data types */
typedef enum {
    /*! Unknown or unspecified type */ 		    GDT_Unknown = 0,
    /*! Eight bit unsigned integer */           GDT_Byte = 1,
    /*! Sixteen bit unsigned integer */         GDT_UInt16 = 2,
    /*! Sixteen bit signed integer */           GDT_Int16 = 3,
    /*! Thirty two bit unsigned integer */      GDT_UInt32 = 4,
    /*! Thirty two bit signed integer */        GDT_Int32 = 5,
    /*! Thirty two bit floating point */        GDT_Float32 = 6,
    /*! Sixty four bit floating point */        GDT_Float64 = 7,
    /*! Complex Int16 */                        GDT_CInt16 = 8,
    /*! Complex Int32 */                        GDT_CInt32 = 9,
    /*! Complex Float32 */                      GDT_CFloat32 = 10,
    /*! Complex Float64 */                      GDT_CFloat64 = 11,
    GDT_TypeCount = 12          /* maximum type # + 1 */
} GDALDataType; 
```
> from gdal.h

- 注释界定符不能嵌套
- 单行注释中的任何内容都会被忽略

```c++
```

## 4. 控制流
语句一般是按顺序执行的，即语句块的第一条语句首先执行，然后是第二条语句，以此类推。但同时，我们在处理不同的问题时，还需要用到循环和分支的控制语句。
## 4.1 While语句
写一段程序，计算1到10之间的这10个数之和：
```c++
#include <iostream>
int main()
{
    int	sum = 0;
    int	val = 1;
    while(val <= 10)
    {
    	sum += val;
    	++val;
    }
    std::cout << "Sum of 1 t0 10 inclusive is "
              << sum << std::endl;
    return 0;
}
```
## 4.2 for语句
```c++
#include <iostream>
int main()
{
    int	sum = 0;
    for (int val=1; val<=10; ++val)
    {
    	sum += val;
    }
    std::cout << "Sum of 1 t0 10 inclusive is "
              << sum << std::endl;
    return 0;
}
```

## 4.3 do...while语句
```c++
#include <iostream>
int main()
{
    int	sum = 0;
    int	val = 1;
    do
    {
    	sum += val;
    	++val;
    }while(val<=10);
    std::cout << "Sum of 1 t0 10 inclusive is "
              << sum << std::endl;
    return 0;
}
```

## 4.4 读取数量不定的输入数据
```c++
#include <iostream>
int main()
{
    int	sum = 0;
    int	value = 0;
    // 读取文件直到遇到文件尾，计算所有读入值的和
    while (std::cin >> value)
        sum += value;	//等价于 sum = sum + value;
    std::cout << " Sum is: " << sum << std::endl;
    return 0;
}
```
## 4.5 if语句
条件语句是用于执行一个判断，只有条件为真时，其包含的语句才会执行。如：输入一组数，输出最小的一个数。
```c++
#include <iostream>
int main()
{
    int	minVal;
    int	val;
    std::cin >> minVal;
    while(std::cin >> val)
    {
        if (val < minVal)
        {
            minVal = val;
        }
    }
    std::cout << "Minimum is: " << minVal << endl;
    return 0;
}
```
> 将程序扩充为，同时输出最小值和最大值。

#5. class
为什么会有class出现呢？class解决了什么问题呢？这个问题我们得从软件设计的思想说起。在前面的程序示例中，我们学习了几个简单的程序代码。我们有没有发觉，若是对于一个比较复杂的程序，代码行数增多后，都写在一个main函数中，会显得难以阅读。正如写文章一般，当你是一个初学者的时候，写了一小段文字，一目了然。但当你写了一篇数页的长篇之后，仍然作为一段就显得有点晦涩难懂了。这个时候，我们就需要分段，一段表达一个单独的意思，将文章划分为若干块，这样便于阅读和写作。对于程序也一样，冗长的程序，没有人能看的顺畅，看了前面忘后面，因此，程序也需要分段，那么如何分段呢，这个时候就采用函数来分段。一个函数犹如一段话，表达某个功能，并用 { 和 } 包含起来。那么当程序功能越来越复杂，函数的数量成千上万的时候，怎么办呢？还是很复杂。这个时候，我们就需要考虑，将某些同类的函数进行分组，构成一个更大的集合，这个集合的名字就是类-class。此处需要注意的是，class内的函数都是围绕某个特点的功能集展开的，比如：iostream就是一个类，它就包含了一系列的输入、输出、格式化等函数，与之无关的是不会放置其中的。
前面我们是从软件发展的角度来分析了class出现的趋势。而事实上，class的设计者可能不是这么考虑的。class是包含了数据和一组行为的集合体，这是从class包含的内容出发的。但class也有其弊端，有如Linus就十分不愿意使用C++，觉得C++有如高射炮打蚊子，我本来是要打一只蚊子，你不是拿个简易的拍子过来，而是创建了一个重量级的高射炮对象，尽管我只是用来打蚊子，也需要一个高射炮对象，不然，对不起，这只蚊子没法打。这也是过度class带来的性能损耗。
接下来，我们以Student场景而言，来分析class的内容。我们定义一个Student类，用于存放学号、姓名、考分，学分绩点等。除了这些data之外，我们可能需要某些行为（方法），如：计算平均分、计算学分绩点等。
```c++
class Student{
private:
    string	strName;
    string	strID;
    float	fGPA;
    int		scores[10];
public:
    string Name();
    string ID();
    float GPA();
    float mean();
}
```

## 6.Projects
- 1. 写一个判断闰年的程序，输入一个年份，程序判断是否为闰年，输出ture or false的标识。
- 2. 在（1）的基础上，用户能循环输入年份，判断是否为闰年，直到输入年份为负数时，程序终止。
- 3. 试着将判断闰年的语句，封装为一个函数isLeap，在主程序中来调用，实现（2）的功能；
- 4. 输入年月日，输出所属的星期；
- 5. 输入年月，输出 当月的日历；
```c++
#include <iostream>
int main()
{
    std::cout << "Input a Year: ";
    int		nYear;
    std::cin >> nYear;
    if ((nYear%4==0 && nYear%100!=0) || nYear%400==0)
        std::cout << nYear << " is leap year!";
    else
        std::cout << nYear << " is not leaap year!"
    return 0;
}
```
