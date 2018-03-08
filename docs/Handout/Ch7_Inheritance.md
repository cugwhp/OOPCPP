# Chapter 7 Object Oriented Programming
```
面向对象技术的3个关键点是：数据抽象、继承和多态。继承是一种重要的面向对象对象复用技术，多态是面向对象的关键思想。
```

## 7.1 OOP Overview
- 1. 继承 Inheritance
    通过继承我们对类与类之间的关系建模，共享公共的部分，仅仅特化本质上不同的内容。派生类（derived class）能够继承基类（base class）定义的数据成员和函数成员，派生类可以增加自己的成员，也可以重载已有的接口。我们常常将因继承相关联类的构成，称之为继承层次（inheritance hierarchy）。
- 2. 动态绑定 Dynamic binding

## 7.2 Base class & Derived class
### 7.2.1 Definition base class
```c++
// Person with name and age
#include <string>
#include <iostream>
using namespace std;
class Person{
    public:
        Person(string strName="", int nAge=0):
        m_strName(strName),m_nAge(nAge){}
        virtual ~Person(){}
        string  GetName() const {return m_strName; }
        int GetAge() const { return m_nAge; }
        void Print(ostream& os);	//Print Name & Age to os
    private:
        string  m_strName;	//Name
    protected:
        int     m_nAge;		//Age
};
```
1. 基类成员函数
2. 访问控制和继承

### 7.2.2 Protected成员
> 类设计与受保护成员
> 如果没有继承，类只有两类用户：类本身（内部）和该类的用户（外部），即private-内部使用，public-外部使用（当然内部也可使用）。
> 当有了继承之后，就遇到一类情况：希望派生类能访问基类的某些成员，但仍不可以访问private成员，因为private成员被视作基类的隐私，不希望被派生类可见。此时，就增加了一个介于private和public权限之间的protected。protected的权限是介于隐私和公开之间，允许继承者可见，而公众不可见的权限。
> 当某个类充当基类时，其成员设计为public的标准并无改变：接口函数应该public，而数据成员一般为非public。禁止派生类访问的成员应该设为private。提供给派生类实现所需的成员函数或变量应设为protected。

#### Exercise
- 1. protected 与 private 的区别。
- 2. 基类的public、protected、private在三种继承方式下的访问权限是？

### 7.2.3 派生类
派生类的语法形式为：
```c++
class derived-class : access-label base-class
// access-label is public, protected or private.
```
1. 定义派生类
```c++
#include "Person.h"
class Student : public Person{
    public:
        Student(string strName="", int nAge=0, unsigned long ulID=0, int nScore=0) : Person(strName, nAge), m_ulID(ulID), m_nScore(nScore){}
        virtual ~Student(){}
        unsigned long   GetID() const { return m_ulID; }
        int GetScore() const { return m_nScore; }
        void Print(ostream& os);
    protected:
        unsigned long   m_ulID;
    private:
        int     m_nScore;
};
```
2. 派生类对象包含基类对象作为子对象

3. 派生类中的函数可以使用基类的成员
```c++
void Student::Print(ostream& os)
{
  os << "Name： " << GetName() << endl;
  os << "Age:   " << GetAge() << endl;
  os << "ID:    " << m_ulID << endl;
  os << "Score:	" << m_nScore << endl;
}
```
4. 用作基类的类必须是已定义的

5. 用派生类做基类
```c++
class Base();
class D1 : public Base();
class D2 : public D1();
```
6. 派生类的声明无需包含派生列表

#### Exercise
1.下面声明中哪些是错误的？
```c++
class Base {};
(a) class Derived : public Derived {};
(b) class Derived : Base {};
(c) class Derived : private Base {};
(d) class Derived : public Base;
(e) class Derived inherits Base {};
```
