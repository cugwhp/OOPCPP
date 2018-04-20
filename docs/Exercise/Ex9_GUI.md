# 实习（九）GUI

## 实习目的
- 了解GUI程序的基本原理，尤其是消息、事件的理解
- 掌握基本的GUI程序开发过程
- 掌握GUI绘制图形的基本过程
- 巩固流操作
- 巩固STL容器的用法
	
## 实习题目

### 题目：参照课上DrawShape的例子，开发一个简易的图形绘制GUI程序。

#### 功能要求：
	1. 读取/保存Shape文件
	2. 在视图上显示Shape
	3. 查询Shape面积和周长
	4. 画Shape，并可保存至文件（选做）
	5. 删除Shape（选做） 
	
#### 实现步骤
##### Step 1：用向导生成MFC应用程序
> 新建工程 -> MFC应用程序 -> 单文档模式 -> Finish

##### Step 2：创建一系列Shape类
- 参照以往的例子，创建Shape、Circel、Rectangle、Triangle.
- 注意继承关系，预留Draw(), GetArea(), GetPerimter()虚接口
- 为IO重载<<, >>操作符

##### Step 3：定义数据结构单元
- 定义vector<Shape*>	vecShapePt; 
- 维护好形状列表的new和delete工作

##### Step 4：改写打开文件消息处理消息
- 跟踪调试，ID_FILE_OPEN消息的处理入口及读文件的函数；
- 在读文件函数部分，实现从文件流一行一行读取Shape参数，并new Shape对象

##### Step 5：完成Shape的绘制
- 在C××View::OnDraw(CDC* pDC) 里加入相应的绘制代码

##### Step 6：查询Shape属性（面积和周长）-- 选做
- 增加一个菜单项ID_SHAPE_QUERY_AREA_PERIMETER, 菜单名：形状面积与周长
- 双击菜单，新增消息处理函数OnShapeQueryAreaPerimeter()
- 在C××View中新增标志位变量 long	m_lOperFlag; 初始化为:m_lOperFlag=0
- 在OnShapeQueryAreaPerimeter（）里增加m_lOperFlag |= 0x0001;
- 新增WM_LBUTTONUP的消息处理函数，在OnLButtonUp()函数里处理相应的结果。
- 查询的细节流程：1）查询当前鼠标所在位置的shape；2）调用该Shape的GetArea()和GetPerimeter()函数获得面积和周长；3）弹出对话框显示面积和周长。

##### Step 7：画Shape（选做）
- 画图形，以三角形为例：
- 设置当前状态为画三角形；
- 按下鼠标，鼠标抬起时记录一个点；
- 重复上述操作，绘制第二个点和第三个点；
- 鼠标右键结束绘制。

##### Step 8：删除Shape（选做）
- 删除图形，流程
- 设置状态为删除图形
- 按下鼠标，鼠标抬起时判断当前鼠标位置所在的图形对象
- 删除当前图形对象
