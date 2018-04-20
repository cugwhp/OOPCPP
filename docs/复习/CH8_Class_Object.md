# 第8章   类和对象的创建

## 【内容提要】

本章是介绍类和对象的定义、创建的相关内容，这一章围绕对象的生、死与实现来展开。

**①类和对象的关系以及区别**：类和对象的理解要深入，要比较起来看。类是抽象的，对象是具体的；类是模具，对象是由模具生产出来的构件；类是设计阶段的产物，对象是实现阶段的物品。

**②构造函数和析构函数：**类的构造函数和析构函数关系到对象的生死。构造函数有：默认构造函数、拷贝构造函数；析构函数要注意虚函数。****

**③对象数组和对象指针：**理解清楚，构建对象数组是需要有默认构造函数的；定义对象指针变量是会调用对象的构造函数的。****

**④static****变量：**类的static变量属于类，而不是属于某个具体的对象，是所有类对象共有。同理，static成员函数，亦只可以访问类的static变量，而无法访问对象的成员变量。

**⑤友元函数：**破坏类的封装性的声明，记住声明为friend友元，仅仅只是注册而已，并非声明这个函数。

**⑥inline****函数：**inline函数是采用一种源码展开的编译模式，可以提高效率，但会增大程序的体量。一般而言，被频繁调用的3-5句简单函数（不包含循环）可以定义为inline。

 

##【重点与难点】

### 8.1 类和对象

#### 8.1.1 类的定义

类实质上是用户自定义的一种特殊的数据类型，它不仅包含相关的数据，还包含能对这些数据进行处理的函数，同时，这些数据具有隐蔽性和封装性。类中包含的数据和函数统称为成员，数据称为数据成员，函数称为成员函数，它们都有自己的访问权限。类定义一般分为两部分，即说明部分和实现部分。说明部分用于说明该类中的成员，实现部分用于对成员函数进行定义。 

- 类定义格式：
```c++
class 类名
{
	private:
     私有数据成员和成员函数

	protected:
     保护数据成员和成员函数

	public:
    公有数据成员和成员函数
};
```

- 各成员函数的实现
类成员的访问控制

类成员有三种不访问权限：私有（private）、保护（protected）、公有（public）。

私有成员只能被本类的成员函数访问及其友元访问。当声明中未指定访问控制时，系统默认该成员为私有成员。

保护成员一般情况下与私有成员的含义相同，在类的继承和派生中与私有成员有不同的含义，保护成员可被本类或派生类的成员函数访问，但不能被外部函数访问。

公有成员可以被程序中的任何函数访问，它提供了外部程序与类的接口功能。

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  类的数据成员与成员函数

​    类定义中声明数据成员的数据类型和名称，不能在类内说明数据成员的同时为其赋初值，只有在类的对象定义以后才能给数据成员赋初值。

对于成员函数可以在类内定义，也可以在类内给出函数原型，然后在类外对成员函数进行定义。成员函数在类内说明原型，在类外给出定义时其定义格式如下：

返回类型 类名::函数名(参数表)

​    {//函数体

​    }

在所定义的函数名前必须加上类名，以表示该函数属于哪个类。类名与函数名之间必须加上作用域运算符∷。

注意：如果在类的内部定义成员函数，该成员函数即被声明为内联函数。也可以在类中声明，在类外将该成员函数定义为内联函数。只要在定义前加关键字inline，以显示定义该成员函数为内联函数。这种函数一般是小的、频繁使用的函数。

内联函数的声明有显式声明和隐式声明两种形式。

隐式声明：直接将成员函数定义在类内部 

显示声明：将内联函数定义在类外，其声明的形式与在类外定义成员函数的形式类似，但为了使成员函数起到内联函数的作用，在函数声明前要加关键字inline，以显式地声明这是一个内联函数  

8.1.2 对象的定义和使用

对象的定义

类定义只是定义了一种新的数据类型，只有定义了类的实例即类的对象以后系统才会为该对象分配存储空间。对象定义可以在类定义的同时直接完成，即在类定义的最后“}”后直接跟对象名列表；也可以在类定义后要使用该对象时定义。

格式：类名对象名（参数列表）；

说明：可以同时定义多个对象，之间用逗号隔开。

对象成员的引用

​    格式：

对象名.数据成员；

对象名.成员函数（实参表）；

说明：

①在引用成员时要注意访问权限的控制问题。

​    ②对于指向对象的指针在引用其成员时不能使用“.”运算符。其格式为：

对象名->数据成员；

对象名->成员函数（实参表）；

 

8.2 构造函数和析构函数

8.2.1 构造函数 

构造函数是一种特殊的成员函数，被声明为公有成员，其作用是为类的对象分配内存空间，进行初始化。

关于构造函数有以下几点说明：

①构造函数的名字必须与类的名字相同。

②构造函数没有返回值，不能定义返回类型，包括void型在内。

③对象定义时，编译系统会自动地调用构造函数完成对象内存空间的分配和初始化工作。

④构造函数是类的成员函数，具有一般成员函数的所有性质，可访问类的所有成员，可以是内联函数，可带有参数表，可带有默认的形参值，还可重载。

⑤如果没有定义构造函数，编译系统就自动生成一个缺省的构造函数，这个缺省的构造函数不带任何参数，仅给对象开辟存储空间，不完成对数据成员赋初值。此时数据成员的值是随机的。系统自动生成的构造函数的形式为：

类名∷类名()

{

}

8.2.2 析构函数 

析构函数也是一种特殊的成员函数，也被声明为公有成员，其作用是释放分配给对象的内存空间，并做一些善后工作。 

①关于析构函数有以下几点说明：

②析构函数的名字必须是  ~类名。

③析构函数没有参数、没有返回值、不能重载。

④当对象撤销时，系统会自动调用析构函数完成内存空间的释放和善后工作。

⑤如果没有定义析构函数，系统会自动生成一个缺省的空析构函数。完成善后工作，其形式为：

类名::~类名()

{

}

对于构造函数和析构函数常见用法是在构造函数中用new动态申请空间，在析构函数中用delete释放内存空间。

8.2.3 拷贝构造函数

拷贝构造函数是一个特殊的构造函数，其作用是用一个已经存在的对象初始化本类的新对象。每个类都有一个拷贝构造函数，它可以是根据用户的需要自定义，也可以由系统自动生成。拷贝构造函数名与类名相同，但参数是本类对象的引用。拷贝构造函数没有返回值。

定义拷贝构造函数的格式为：

​    类名(类名&对象名)

​    {

​       //函数体

​    }

其中，对象名是用来初始化另一个对象的对象的引用。

 

构造函数只在对象被创建时自动调用，而拷贝构造函数在下列三种情况下会被自动调用：

①用一个对象去初始化本类的另一个对象时。

②函数的形参是类的对象，在进行形参和实参的结合时。

③函数的返回值是类的对象，函数执行完返回时。  

 

8.2.4 对象成员

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  定义对象成员

当用一个类的对象作为另一个类的成员时，该成员称为对象成员。声明对象成员的一般格式为：

​       class 类名{

类名1  对象成员名1；//需要此类在前面已经定义或声明。

．．．

}；

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  对象成员的初始化

在类中有对象成员时，创建本类的对象则本类的构造函数要调用其对象成员所在类的构造函数，并采用成员初始化列表对对象成员进行初始化。这种类的构造函数的定义格式为：

类名∷类名(参数总表)：对象成员1(形参表)，．．．，对象成员ｎ(形参表)

{  

//构造函数体  

}

 

说明：

对象成员的构造函数的调用顺序由对象成员在类中的声明顺序决定，与成员初始化列表中的顺序无关。析构函数的调用顺序正好与构造函数的调用顺序相反。

 

8.3对象数组与对象指针

8.3.1 对象数组

​       对象数组是指数组中的每个元素都是一个类的对象。当然这些对象属于同一个类。

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  定义一维对象数组的一般格式为：

类名 数组名[常量表达式]；

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  对象数组的引用

由于对象数组的元素是对象，只能访问其公有成员。引用格式为：

数组名[下标]．公有成员

8.3.2 对象指针

​       对象指针就是对象在内存中的首地址。指向类类型的指针变量用于存放对象指针。其定义格式为：

​       <类名> * <指针变量名>;

说明：

​              可以在定义的同时对该指针变量进行初始化即用“&对象名”的形式取出对象首地址赋给该变量，也可以在使用该指针变量时再对它赋值。

 

8.4 静态成员

静态成员是指类中用关键字static说明的那些成员。静态成员仍然服从访问控制。

8.4.1静态数据成员

​       静态数据成员是指类中用关键字static说明的那些数据成员。静态数据成员属于类而不属于某个对象。它实现同类对象之间的数据共享。

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  在类中声明静态数据成员时，必须加static说明。

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  对静态数据成员初始化只能在类外进行，一般在在类声明与main()之间的位置。

格式为：

​              数据类型类名∷静态数据成员名=值；

![*](file:///C:\Users\Apple\AppData\Local\Temp\msohtmlclip1\01\clip_image001.png)  对静态数据成员的引用可以有两种形式：

类名∷静态数据成员 

对象名．静态数据成员

8.4.2静态成员函数

静态成员函数是指类中用关键字static说明的那些成员函数。可以用静态成员函数在未建立任何对象之前去处理静态数据成员。静态成员函数只能直接引用该类的静态数据成员和静态成员函数，不能直接引用非静态数据成员。

   调用静态的两种形式：

类名∷静态函数名();  或  对象名．静态函数名(); 

 

8.5 友元

C++引入了友元实现了在类的外部访问类的私有成员的功能。这样，即不放弃私有数据的安全性，又可在类的外部访问类的私有成员。但一定程度上说友元破坏了类的封装性，在使用友元时一定要慎重。友元关系是单向的，也是不能传递的。

8.5.1 友元函数

​       一个普通函数作为某个类的友元时即为友元函数。在该函数中可以访问其由friend声明语句所在的类的对象的私有成员和公有成员。在类中作如下声明，则说明该函数不是本类的成员函数，而是友元函数。

friend 函数类型 友元函数名(参数表);

友元函数的定义可以在类内也可以在类外，在类外定义时不需要加类名和普通函数定义没有区别。通常友元函数的定义在类外进行。

友元函数不是类的成员，因而不能直接引用对象成员的名字，也不能通过this指针引用对象的成员，必须通过作为入口参数传递进来的对象名或对象指针来引用该对象的成员。为此，友元函数一般都带有一个该类的入口参数。

8.5.2 友元成员函数

​       某个类的成员函数作为另一个类的友元即为友元成员函数。通过友元成员函数，可以访问由friend声明语句所在的类的对象的私有成员和公有成员。

当一个类A的成员函数作为另一个类B的友元函数时，在类B中的声明格式为：

​       friend 函数类型成员函数所在类类名::函数名（参数表）；

8.5.3 友类

​       当一个类作为另一个类的友元时即为友类。若类A是类B的友类，则类A中的所有成员函数都是类B的友元成员函数，所以可以通过对象名访问B的私有成员和公有成员。

当类A为类B的友类时，在类B中的声明格式为：

firiend class <友元类名>; 或 friend <友元类名>;

 

## 【典型例题】

例题1．下列程序段是否有错，若有错请改错。

\#include<iostream.h>

classpoint---------------------------------------------①

{

​       private:

​              int x,y;

​       public:

​              void setpoint(int,int);--------------------②

};

int point::setpoint(int xx, int yy)  ----------------③

{  

​       x=xx;--------------------------------------------- ④

​       y=yy;--------------------------------------------- ⑤

​       return1;------------------------------------------ ⑥

}

void main()

{

​       point p1;------------------------------------------------------------------------------ ⑦

​       p1.setpoint(2,4);--------------------------------------------------------------------- ⑧

​    cout<<”坐标为：(”<<p1.x<<”,”<<p1.y<<”)”<<endl;------------------------- ⑨

}

解答：

这里⑨错误，不能在类定义以外直接访问类的私有成员。要得该点的两个坐标，应该在类中定义获取私有成员x,y的公有成员函数，使得可以在类外通过类的公有成员函数对其私有成员进行间接访问。所以程序应改为：

class point

{

​       private:

​              int x,y;

​       public:

​              void setpoint(int, int);    //声明成员函数setpoint()的函数原型

​              **int getx();      //****声明成员函数getx()****的函数原型**

**              int gety();       //****声明成员函数gety****的函数原型**

};

void point::setpoint(int xx, int yy)       //定义成员函数setpoint()

{  

​       x=xx;

​       y=yy;

}

**int point ::getx()   //****定义成员函数getx()**

**{      return x;}**

**int point ::gety()   //****定义成员函数gety**

**{      return y;}**

 

例题2．在下列函数原型中，可以作为类student的构造函数的说明的是（  ）。

(a)voidstudent(int age);      (b)int student();      (c)student(int)const;      (d)student(int);

解答：

本题主要考查对构造函数的特点的掌握。构造函数的名字必须与类的名字相同。构造函数没有返回值，不能定义返回类型，包括void型在内。构造函数可以是内联函数，可带有参数表，可带有默认的形参值，还可重载。选项a、b均有返回值类型，不能作为构造函数。选项c为常成员函数，构造函数不能为常成员函数。答案为：d

 

例题3．下列说法正确的是（  ）。

(a)   可以定义修改对象数据成员的const成员函数。

(b)   不允许任何成员函数调用const对象，除非该成员函数也声明为const。

(c)   const对象可以调用非const成员函数。

(d)   const成员函数可以调用本类的非const成员函数。

解答：

c++编译器不允许任何成员函数调用const对象，除非该成员函数本身也声明为const。声明const的成员函数不能修改对象，因为编译器不允许其修改对象。对const对象调用非const成员函数是个语法错误。定义调用同一类实例的非const成员函数的const成员函数是个语法错误。答案为：b

 

例题4．运行下列程序后，”constructing A!” 和” destructingA!”分别输出几次（  ）。

\#include<iostream.h>

class A

{

​       int x;

public:

​       A()

​       {cout<<"constructing A!"<<endl;}

​       ~A()

​       {cout<<""<<endl;}

};

void main()

{

​       A a[2];

​       A *p=new A;

​       delete p;

}

(a)2次，2次      (b)3次，3次      (c)1次，3次      (d)3次，1次

解答：

本题主要考查在什么情况下系统会调用构造函数与析构函数。在主函数中定义了一个对象数组，其中有两个元素，该数组中的每个元素都是一个类的对象，所以这里会调用2次构造函数；new A时创建一个A类的对象，所以也会调用构造函数，因此一共调用3次构造函数。deletep;会撤消new运算分配的空间，它会调用1次析构函数。主函数结束时要释放数组所占空间，会调用2次析构函数，因此析构函数也调用了3次。答案为：b

 

例题5．运行下列程序的结果为__________________________。

\#include<iostream.h>

\#include<string.h>

class course

{

​       int id;

​       char name[50];

public:

​       course(intcsid,char *csname)

​       {

​              cout<<"constructingcourse!"<<endl;

​              id=csid;

​              strcpy(name,csname);

​       }

​       ~course()

​       {

​              cout<<"destructingcourse!"<<endl;

​       }

​       int getid()

​       {return id;}

​       char* getname()

​       {

​              returnname;

​       }

};

class student

{

​       char name[10];

​       int age;

​       course c1;

public:

​       student(char*sname,int sage,int cid,char *cname):c1(cid,cname)

​       {

​              cout<<"constructingstudent!"<<endl;

​              strcpy(name,sname);

​              age=sage;

​       }

​       ~student()

​       {

​              cout<<"destructingstudent!"<<endl;

​       }

​       void prints()

​       {

​              cout<<"name:"<<name<<endl

​                     <<"age:"<<age<<endl

​                     <<"courseid:"<<c1.getid()<<endl

​                     <<"coursename:"<<c1.getname()<<endl;

​       }

};

 

void main()

{

​       studentst1("tom",23,1,"c++ programming language");

​       st1.prints();

}

解答：

本题主要考查在为含有对象成员的类创建对象时，构造函数的调用顺序，对象成员的初始化问题以及对象撤消时调用析构函数的顺序。对于本程序，在主函数中创建student类的对象则调用其构造函数student()，该构造启动时，首先为数据成员分配空间，然后根据在类中声明的对象成员的顺序依次调用其构造函数，在这里调用course类的构造函数，最后才执行自己的构造函数的函数体。析构函数以调用构造函数相反的顺序被调用。

答案为：

constructingcourse!

constructingstudent!

name:tom

age:23

course id:1

coursename:c++ programming language

destructingstudent!

destructingcourse!

 

例题6．运行下列程序输出结果为_____________________。

\#include<iostream.h>

class A{

public:

​       A(int X){cout<<"ok!";}

​       A(){}

};

int main()

{

​       A a[3],a1(3);

​       return 0;

}

解答：

本题主要考查对重载构造函数的理解。这里创建对象数组时，对数组的每一个元素都将调用一次构造函数，如果没有显式给出数组元素的初值，则调用缺省构造函数。而创建对象a1时带有一个整型参数，所以调用以整型作为参数的构造函数，它输出ok！。所以，本题答案为：ok！

 

例题7．运行下列程序结果为________________________。

\#include<iostream.h>

const doublePI=3.14159;

class circle

{

​       double r;

​       

public:

​       static int num;

​       circle(double);

​       circle(circle &);

​       double getr();

};

circle::circle(doublei)

{

​       r=i;

}

circle::circle(circle &c)

{

​       num++;

​       cout<<"第"<<num<<"次调用拷贝构造函数！"<<endl;

  r=c.r*num;

}

double circle::getr()

{

​       returnr;

}

double getradius(circle c3)

{

​       return c3.getr();

}

circle fun1()

{

​       circle c4(5);return c4;

}

intcircle::num=0;

void main()

{

​       circle c1(1);

​       cout<<"c1:"<<c1.getr()<<endl;

​    circle c2(c1);

   cout<<"c2:"<<c2.getr()<<endl;

​    cout<<"c3:"<<getradius(c1)<<endl;

​       circle c4(1);

​       c4=fun1();

​       cout<<"c4:"<<c4.getr()<<endl;

}

 

解答：

本题主要考查在什么情况下会调用拷贝构造函数。构造函数只在对象被创建时自动调用，而拷贝构造函数在下列三种情况下会被自动调用：

①用一个对象去初始化本类的另一个对象时。

②函数的形参是类的对象，在进行形参和实参的结合时。

③函数的返回值是类的对象，函数执行完返回时。  

本题答案为：

c1:1

第1次调用拷贝构造函数！

c2:1

第2次调用拷贝构造函数！

c3:2

第3次调用拷贝构造函数！

c4:15

 

例题8．读程序写结果或者程序填空。

\#include<iostream.h>

class A

{

​       const int i;

​       int &j;

public:

​       A(int& var):i(10),j(var)

​       {}

​       void show()

​       {

​              cout<<"i:"<<i<<endl

​                     <<"j:"<<j<<endl;

​       }

};

void main()

{

​       int x=1;

​       A a1(x);

​       a1.show();

}

解答：

本题主要考查对符号常量和引用的理解。常量是不能被赋值的，一旦初始化后，其值就永不改变，引用变量也是不可重新指派的，初始化后，其值就固定不变了。

结果为：

i:10

j:1

 

例题9．运行下列程序结果为__________________。

\#include<iostream.h>

class Obj{

​       static int i;

public:

​       Obj(){i++;}

​       ~Obj(){i--;}

​       static int getVal(){return i;}

};

int Obj::i=0;

void f (){Objob2;cout<<ob2.getVal();}

int main(){

​       Obj ob1;

​       f();

​       Obj*ob3=newObj;cout<<ob3->getVal();

​       delete ob3;cout<<Obj::getVal();

​       return 0;

}

解答：

本题主要考查对静态数据成员的理解。在主函数中创建对象ob1则调用该类的构造函数，使得静态数据成员加1，为1；接着调用函数f()，在函数中创建对象ob2，这时再次调用构造函数，使得静态成员的值为2，ob2.getVal()返回静态数据成员i的值，即输出2。函数f（）结束，则ob2的生存期结束，自动调用其析构函数使静态数据成员i的值变为1。接着在主函数中用new运算符动态分配存储空间，又一次调用构造函数使i加1，所以再次输出时i的值为2。最后用delete释放ob3所指的对象空间，则会调用析构函数使i的值减1，因此输出i的值为1。本题答案为：221

 

例题10．若类A是类B的友元，类B是类C的友元，则下列说法正确的是（  ）。

(a)类B是类C的友元            (b)类A是类C的友元

(c)类A，B，C互为友元          (d)以上说法都不对

解答：

本题考查对友元关系的理解。友元关系是单向的，也是不能传递的。答案为：a

 

例题11．当输入为2  3时，下列程序输出“两个数的和为：5”。请将程序补充完整。

\#include<iostream.h>

class num

{

​       int x,y;

public:

​       num(int=0,int=0);

​       _________①____________

};

num::num(intx,int y)

{

​       _________②____________

​    

   _________③____________

}

int sum(num& n)

{

​       return n.x+n.y;

}

void main()

{

​       int i,j;

​       cout<<"请输入两个数："<<endl;

​       cin>>i>>j;

​       ________④__________//定义对象num1

​       cout<<"两数的和为："<<sum(num1)<<endl;

}

解答：

本题主要考查友元的应用以及对不同作用域变量的引用方法。

答案为：①friend int sum(num&);②num::x=x;③num::y=y;④num num1(i,j);

 

## 【习题】

一、选择题

1．下列各项中不能用于声明类的成员访问控制权限的关键字是（  ）。

(a)private     (b)protected      (c)public      (d)static

2．下列关于构造函数的说法错误的是（  ）。

(a)构造函数的名字必须与类的名字相同。

(b)构造函数可以定义为void类型。

(c)构造函数可以重载、可以带有默认参数。

(d)构造函数可以由用户自定义也可以由系统自动生成。

3．有如下类声明：

class student

{

int age;

char *name; 

};

则student类的成员age是（  ）。

(a)公有数据成员       (b)私有数据成员      (c)保护数据成员       (d)私有成员函数

4．有如下类定义

\#include<iostream.h>

class point

{

int x,y;

public:

point():x(0),y(0){}

point(int x1,int y1=0):x(x1),y(y1){}

};

若执行语句

point a(2),b[3],*c;

则point类的构造函数被调用的次数是（  ）。

(a)2次      (b)3次      (c)4次      (d)5次

5．在下列哪种情况下不会调用拷贝构造函数（  ）。

(a)用一个对象去初始化本类的另一个对象时。

(b)函数的形参是类的对象，在进行形参和实参的结合时。

(c)函数的返回值是类的对象，函数执行完返回时。  

(d)将类的一个对象赋值给另一个本类的对象时。

6．下列关于友元的描述错误的是（  ）。

(a)   友元关系是单向的且不可传递

(b)   在友元函数中可以通过this指针直接引用对象的私有成员。

(c)   友元可以是一个普通函数也可以是一个类。

(d)   通过友元可以实现在类的外部对类的私有成员的访问。

7．有如下程序

\#include<iostream>

usingnamespace std;

class AA{

​       int n;

public:

​       AA(int k):n(k){ }

​       int get( ){ return n;}

​       int get( )const{ return n+1;}

};

int main( )

{

​       AA a(5);

​       const AA b(6);

​       cout<<a.get( )<<b.get( );

​       return 0;

}

运行该程序结果为（  ）。

(a)56        (b)57        (c)67        (d)66

8．有如下程序：

\#include<iostream.h>

class Test {

public:

Test( ) {n+=2; }

~Test( ) {n-=3; }

static intgetNum( ) { return n; }

private:

static int n;

};

int Test::n =1;

int main( )

{

Test* p = newTest;

delete p;

cout <<"n=" << Test::getNum( ) << endl;

return 0;

}

执行后的输出结果是（）。

(a)   n=0       (b)n=1      (c)n=2       (d)n=3

9．下列程序的运行结果为（  ）。

\#include<iostream.h>

class A

{

public:

​       static int num;

​       A& fun()

​       {

​              num++;

​              return *this;

​       }

};

int A::num=0;

void g(A& a)

{

​       cout<<a.fun().num<<endl;

}

void main()

{

​       A a1;

​       g(a1);

}

(a)0      (b)1      (c)2     (d)3

10．运行下列程序结果为____________________。

\#include<iostream>

\#include<iomanip>

usingnamespace std;

classMyClass{

public:

​       MyClass(){cout<<'A';}

​       MyClass(char c){cout<<c;}

​       ~MyClass(){cout<<'B';}

};

int main(){

​       MyClass p1,*p2;

​       p2=new MyClass('X');

​       delete p2;

​       return 0;

}　　

执行这个程序幕上将显示输出______。

(a)ABX       (b)ABXB       (c)AXB       (d)AXBB

 

二、填空题

1．类的成员包括________成员和成员________。

2．释放对象所占的内存空间并完成善后处理工作的是___________函数。

3．拷贝构造函数以______________作为参数。

4．用指向对象的指针引用对象成员使用操作符__________。 

5．当一个对象生成以后，系统就为这个对象定义了一个__________，它指向这个对象的地址。

6．在类中声明静态成员的关键字是___________。

7．非成员函数应声明为类的____________函数才能访问这个类的private成员。

8．C++建立和初始化对象的过程由_______________完成。

9．对于常量数据成员和引用数据成员的初始化只能通过________________来完成。

10．在类中说明的具有类类型的成员称为_________________。

11．下列为类的定义语句，是否有错，若有错请改正。

class circle--------------------------------------------①

{

​       doubler=3;---------------------------------------②

public:--------------------------------------------------③

​       circle(double i)----------------------------------④

​       {

​              r=i;------------------------------------------⑤

​       }

​       double area();//面积-----------------------------⑥

​    double prm();//周长-----------------------------⑦

​       void printarea(double);-------------------------⑧

void printprm(double); -------------------------

}--------------------------------------------------------⑩

//成员函数的实现

 

12．下列程序输出结果为0,1.请将程序补充完整。

\#include<iostream.h>

class A{

​       int num;

public:

​       A():num(0){}

​       voidset(int num)

​       {________①___________}//给A的数据成员num赋值

​       intget()

{_________②__­_________}//获得数据成员num的值

};

int main()

{

​       A a;

​       cout<<a.get()<<”,”;

​       a.set(1);

​       cout<<a.get()<<endl;

​       return 0;

} 

13．下列程序输出：2，33.4，tom。请将程序补充完整。

\#include<iostream.h>

\#include<string.h>

class A

{

​       int i;

​    float j;

​    char c[20];

public:

​    A(int x, float y, char ch[]):i(x),j(y)

​    {  

​              ________①__________   //初始化成员c赋值

​       }

​       void printA()

​       {

​              ________②___________//输出三个私有数据成员

​       }

};

void main()

{

​       A a(2,33.4,"tom");

​       a.printA();

}

14．下列程序的输出结果为

　Object id=0

　Object id=1

　请将程序补充完整。

\#include<iostream.h>

class Point 

{

public: 

​       Point(int xx=0, int yy=0) {X=xx; Y=yy;countP++; } 

​       Point( ) { countP--; }

​       int GetX( ) {return X;}

​       int GetY( ) {return Y;}

​       static void GetC( ) {cout<<"Object id="<<countP<<endl;} 

private: 

​       int X,Y;

​       static int countP; 

};

__________________//静态数据成员的初始化

int main( ) 

{

​       Point::GetC( );

​       Point A(4,5); 

​       A.GetC( ); 

​       return 0;

}

\15. 插入排序算法的主要思想是：每次从未排序序列中取出一个数据，插入到已排序序列中的正确位置，InsertSort类的成员函数sort()实现了插入排序算法，请将画线处缺失的部分补充完整。

\#include<iostream.h>

classInsertSort{

public:

​       InsertSort(int*a0,intn0):a(a0),n(n0){}//a是数组首地址，n是数组元素个数

​       void sort()

​       {//此函数假设已排序序列初始化状态只包含a[0]，未排序序列初始为a[1]…a[n-1]

​              for (int i=1;i<n;++i)

​              {

​                     int j,t;

​                     for(_______________;j>0;--j)

​                     {

​                            if(t>a[j-1])break;

​                            a[j]=a[j-1];

​                     }

​                     a[j]=t;

​              }

​       }

protected:

​       int*a,n;//指针a用于存放数组首地址，n用于存放数组元素个数

};

 

三、编程题    

\1. 自定义一个正方体类，它具有私有成员x，表示正方体的每个面的正方形的边长。提供构造函数以及计算正方体的体积和表面积的公有成员函数，并编制主函数，对正方体类进行使用：说明正方体类对象，输入棱长，计算其体积和表面积并显示结果。

 

\2. 设计一个时间类Time，包括3个数据成员，时（hour）、分（minute）、秒（second），以及成员函数用于设置和读取时、分、秒，并按上午、下午各12小时或按24小时输出时间。

 

【参考答案】

一、选择题

1．d

2．b

3．b

4．c

5．d

6．b

7．b

8．a

9．b

10．d

二、填空题

1．数据、函数

2．析构

3．本类对象的引用

4．->

5．this指针

6．static

7．友元

8．类的构造函数

9．成员初始化列表

10．对象成员

11．②⑩ 改正如下：

②double r;

⑩末尾加分号。

12．①A::num=num; ②return num;

13．                                          

①strcpy(c,ch);

②cout<<i<<","<<j<<","<<c<<endl;

14．intPoint::countP=0;

15.  j=i,t=a[i]



三、编程题

1.参考程序如下：

\#include<iostream.h>

\#include<math.h>

class cube

{

​       double x;

public:

​       cube(double xx)

​       {

​              x=xx;

​       }

​       double volume();

​       double sarea();

​       

}; 

doublecube::volume()

{

​       return pow(x,3);

}

doublecube::sarea()

{

​       return pow(x,2)*6;

}

void main()

{

​       double a;

​       cout<<"请输入棱长：";

​       cin>>a;

​       cubec(a);

​       cout<<"该正方体的体积为："<<c.volume()<<endl

​              <<"该正方体的表面积为："<<c.sarea()<<endl;

}

2.参考程序如下：

\#include<iostream.h>

class Time

{

​       int hour;

​       int minute;

​       int second;

public:

​       int sethour(int);

​       int setminute(int);

​       int setsecond(int);

​       int gethour();

​       int getminute();

​       int getsecond();

​       void show12();

​       void show24();

};

intTime::sethour(int h)

{

​       if(h>=24||h<0)

​              return 0;  

​       else

​       {

​              hour=h;

​              return 1;

​       }

}

intTime::setminute(int m)

{

​       if(m>=60||m<0)

​              return 0;

​       else

​       {

​              minute=m;

​              return 1;

​       }

}

intTime::setsecond(int s)

{

​       if(s>=60||s<0)

​              return 0;

​       else

​       {

​              second=s;

​              return 1;

​       }

}

intTime::gethour(){return hour;}

intTime::getminute(){return minute;}

intTime::getsecond(){return second;}

 

voidTime::show12()

{

​       if(hour==12)

​              cout<<hour<<":"<<minute<<":"<<second<<"AM"<<endl;

​       else

​              cout<<hour%12<<":"<<minute<<":"<<second

​                 <<((hour<12&&hour>=0)?"AM":"PM")<<endl;

}

voidTime::show24()

{

​       cout<<hour<<":"<<minute<<":"<<second<<endl;

}

 

void main()

{

​       int h,m,s;

​       cin>>h>>m>>s;

​       Time t;

​       if(t.sethour(h)==0||t.setminute(m)==0||t.setsecond(s)==0)

​       {

​              cout<<"输入时间错误！";

​              return;

​       }

​       t.show12();

​       t.show24();

 

}