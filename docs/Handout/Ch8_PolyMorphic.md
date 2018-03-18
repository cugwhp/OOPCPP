# Chapter 8 Polymorphic
```
多态是面向对象设计领域最为重要的一个概念，没有多态就没有面向对象缤纷五彩的世界，也少了很多变幻莫测。
```

## 7.1 Polymorphic Overview
- ​

### 7.1.1 class vs. instance
从类的定义说起：
class Base 的定义包含成员变量、构造函数、析构函数。
```c++
class Base {
public:
    Base();
    ~Base();
protected:
	int		m;
};

Base	b;
cout << sizeof(b) << endl;	//sizeof(b) = 4?
```

//
