#	一、基础知识

##	1.1 Hello World编写

##	1.2 程序注释

##	1.3 变量

变量意义：方便管理内存空间

##	1.4 常量

用于记录程序中不可更改的数据。

定义的方式：

1.#define 宏常量 #define 常量名 常量值 ，通常在文件上方定义

2.const修饰的变量 const 数据类型 常量名=常量值   不可修改

##	1.5 关键字

##	1.6 标识符命名规则

##	1.7 数据类型

###	1.7.1 整型

###	1.7.2 sizeof关键字

可以统计数据类型所占的内存大小

###	1.7.3 实型

单精度float，双精度double，两者的区别在于表示的有效数字的范围不同。

float4个字节，7位有效数字，double，8字节，15-16位有效数字。

默认情况下输出一个小数会显示6位有效数字。

###	1.7.4 字符型

```c++
char ch = 'a'
//可以利用(int)ch来查看其对应的ASCII编码a-97,A-65
```

只占用一个字节，字符型变量并不是直接把字符本身放在内存中存储，而是将其ASCII编码放入。

###	1.7.5 转义字符

用于显示一些不能显示出来的ASCII编码。常用的有\n,\\ \,\t。

###	1.7.6 字符串型

```c++
//c语言风格：char 变量名[]=“字符串值”
//c++语言风格：string 变量名="字符串值"   使用的时候需要添加头文件<string>
```

###	1.7.7 bool类型

true-真，false-假，占一个字节大小。

```c++
bool flag = true;
```

###	1.7.8 数据的输入

用于从键盘获取数据

```c++
int a=0;
cout<<"请给整型变量a赋值：";
cin>>a;
cout<<"整型变量a="<<a<<endl;
```

##	1.8 运算符

###	1.8.1 算术运算符

```c++
+、-、*、/
%取模、++、--
```

两个整数相除结果依然是整数将小数部分去除。

前置+先加后进行其他运算，后置++先运算然后在++；

###	1.8.2 赋值运算符

###	1.8.3 比较运算符

用于表达式的比较，并返回真值或假值。

###	1.8.4 逻辑运算符

```c++
!非
&&与
||或
```

## 2.程序流程控制

顺序结构、选择结构、循环结构

###	2.1 if语句

###	2.2 三目运算符

```c++
表达式1？表达式2：表达式3
```

表达式1成立则返回表达式2，否则返回表达式3

###	2.3 switch语句

###	2.4循环结构

####	2.4.1 while循环

####	2.4.2 do...while循环

####	2.4.3 for循环

####	2.4.4 嵌套循环

###	2.5 跳转语句

```c++
break;
continue;//跳过本次循环为执行的语句，直接执行下一次循环
goto;//可以无条件的跳转代码，跳转到标记处
goto FLAG;
FLAG;
```

##	3. 数组

数组中的数据元素都是相同的数据类型，是由连续的内存位置组成的。

###	3.1 一维数组

```c++
一维数组定义方式：
    1.数据类型 数组名[数组长度];
	2.数据类型 数组名[数组长度]={值1，值2...};
	3.数据类型 数组名[]={值1，值2...}

一维数组名称的用途：
    1.可以统计整个数组在内存中的长度
    2.
    
    可以获取数组在内存中的首地址
```

###	3.2 冒泡排序

```c++
1.比较相邻元素，如果第一个比第二个大，就交换他们两个
2.对每一对相邻的元素做同样的工作，执行完毕后，找到一个最大值
3.重复上述步骤，每次比较次数-1，直到不需要比较
```

###	3.3 二维数组

```c++
二维数组定义方式：
    1.数据类型 数组名[行数][列数]；
    2.数据类型 数组名[行数][列数]={值1，值2...}；
    3.数据类型 数组名[行数][列数]={{值1，值2...},{值3，值4...}};
	4.数据类型 数组名[][列数]={value1,value2,value3...};

二维数组名称的用途：
    1.可以统计整个数组在内存中的长度
    2.可以获取数组在内存中的首地址
```

##	4.函数

将一段经常使用的代码封装起来，减少重复代码。

```c++
函数定义的五个步骤：
    1.返回值类型
    2.函数名
    3.参数列表
    4.函数体语句
    5.return表达式
```

###	4.1 值传递

值传递就是函数调用时实参将数值传递给形参。

值传递时如果形参发生变化并不会影响实参。

###	4.2 函数的声明

告诉编译器函数名称及如何调用函数。函数的实际主体可以单独调用。函数的声明可以多次但是定义只有一次。

###	4.3 函数的分文件编写

让代码结构更简洁。

```c++
分文件编写4个步骤：
    1.创建后缀名为.h的头文件
    2.创建后缀名为.cpp的源文件
    3.在头文件中写函数的声明
    4.在源文件中写函数的定义
```

对于多文件的编写，调试的时候再visual stdio中是直接可以进行的，但是在像visual stdio code中就没办法直接进行编译，因此需要下列步骤：

- **基于g++命令**

  - g++编译**单**文件，生成**带调试信息的可执行文件**，并**调试**。

    ```c++
    g++ -g main.cpp -o my_single_swap
    ```

  - g++编译**多**文件，生成**带调试信息的可执行文件**，并**调试**。

    ```c++
    g++ -g main.cpp swap.cpp -o my_multi_swap
    ```

```
使用g++需要注意一些问题：
1.首先所有的文件应该在同一个文件夹下，并且是vscode的当前工作目录，否则可能会出现找不到的情况
2.使用g++命令只是生成了一个.exe文件，调试还需要在launch.json文件中找到program项中填写你需要调试的文件名称，并将preLaunchTask项注释掉
```



- **基于Cmake**

  - 编写最简单的**CmakeList.txt**

    ```c++
    project(MYSWAP)//指定工程的名字
    add_exeutable(my_cmake_swap,main.cpp swap.cpp)
    然后需要对cmake进行配置，按住shift+ctrl+p，选择cmake configure，然后在里面选择gcc等一会就生成好了一个build文件夹
    然后cd到build文件夹，输入cmake空格..命令
    然后输入mingw32-make.exe(这里直接输入min然后tab补全的是mingw64，需要我进行安装)，然后就会在build文件下生成我指定名称的exe文件，然后在launch.json文件中更改program中的路径即可
    ```

  - 进行**多文件编译**，并**调试**

    ```c++
    mkdir build
    cd build
    # 如果电脑上已经安装了VS，可能会调用微软MSVC编译器，使用（Cmake -G "MinGw Makefiles"..)代替（Cmake）即可
    # 仅第一次使用cmake时使用（cmake -G "MinGW Makefiles"..)后面可使用(cmake..)
    cmake ..
    mingw32-make.exe
    ```

- **配置json**

  - **launch.json**--for debug

  - **tasks.json** -- for build before debug

  - ```
    需要修改的地方：
    1.preLaunchTask取消注释，这样会重新生成新的编译文件，否则就还是原来生成的文件，并且名称需与tasks.json中label相一致
    2.tasks.json文件command命令就当于g++，args命令中就相当于-g ..cpp -o,按照这个格式将其进行填充
    3.将launch.json文件中program命令的路径修改为生成的.exe文件的路径，即可完成
    4.值得注意的一点就是在tasks.json文件中也应当（最好是）cwd到当前目录下，否则就回去寻找你指定的那个路径
    ```

这样的话cmake就相当于白安装了，cmake的目的就是地动画makefile，task和launch，要对应makefile的标签。但是这样还是比较方便的。

##	5. 指针

指针的作用：可以通过指针间接访问内存。

- 内存=编号是从0开始记录的，一般用十六进制数字表示
- 可以利用指针变量保存地址



###	5.1 指针变量的定义和使用

```
数据类型 * 变量名；
可以通过解引用的方式来找到指针的指向内存。 *p
```

###	5.2 指针所占的内存空间

32位操作系统下站4个字节空间，64为占8个字节。

###	5.3 空指针和野指针

空指针：指针变量指向内存中编号为0的空间。用于初始化指针，空指针指向的内存时不可以访问的。

```c++
int * p = NULL;
```

野指针：指针变量指向非法的内存空间

```c++
int * p = (int *)0x1100;//这样做虽然语法上并没有错误，但是会出现访问冲突。
```

##	5.4 const修饰指针

const修饰指针有三种情况：

```
1.const修饰指针--常量指针
2.const修饰常量--指针常量
3.const既修饰指针，又修饰常量
```

####	5.4.1 常量指针

```c++
const int * p = &a;
```

指针的指向可以修改，但是指针指向的值不可以改。

####	5.4.2 指针常量

```c++
int * const p =&a;
```

指针的指向不可以改，指针指向的值可以改。

####	5.4.3 const既修饰指针又修饰常量

```c++
const int * const p = &a;
```

###	5.5 指针和数组

利用指针访问数组。

```c++
int arr[10] = {0,1,2,3,4,5,6,7,8,9};
int * p = arr;//arr就是数组首地址
p++;//让指针往后移动4个字节
```

###	5.6 指针和函数

利用指针做函数参数可以修改实参的值。

###	5.7 指针、数组、函数

封装函数，利用冒泡排序，实现对整型数组的升序排序。

```c++
void bubbleSort(int * arr,int len){// int * arr也可以写成int arr[]
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
```

##	6. 结构体

结构体用于用户自定义的数据类型，允许用户存储不同的数据类型。

###	6.1 结构体的定义和使用

```
struct 结构体名 {结构体成员列表};
用过结构体创建变量的方式有三种：
1.struct 结构体名
2.struct 结构体名 变量名 = {成员值1，成员值2...}
3.定义结构体时顺便创建变量
```

```c++
struct Student{
    string name;
    int age;
    int score;
}s3;

struct Student s1;//struct关键字可以省略，创建变量时
s1.name="张三";//通过.访问结构体中变量中的属性
struct Student s2={...};
```

###	6.2 结构体数组

将自定义的结构体放入到数组中方便维护。

```
struct 结构体名 数组名[元素个数]={{}，{}，...}
```

###	6.3 结构体指针

通过指针访问结构体中的成员

- 利用操作符->可以通过结构体指针访问结构体属性

```c++
struct Student{
    string name;
    int age;
    int score;
};

struct Student s={"张三",18,100};
student * p = &s;
cout<<"姓名"<<p->name<<endl;
```

###	6.4 结构体嵌套结构体

结构体的成员可以是另一个结构体。

###	6.5 结构体做函数参数

将结构体作为参数向函数中传递。

传递方式：

​				1.值传递

​				2.地址传递

```c++
void swap(struct s1);
void swap(struct *s2);
```

###	6.6 结构体中const使用场景

使用const来防止误操作。

将函数中的形参改为指针，可以减少内存空间，而且不会赋复制新的副本。

##	7. 实例1——通信管理系统

###	7.1 系统需求

通讯录是一个可以记录情人、好友信息的工具。

利用c++实现一个通讯管理功能。

系统中需要实现的功能如下：

- 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
- 显示联系人：显示通讯录中所有联系人的信息
- 删除联系人：按照姓名进行删除指定联系人
- 查找联系人：按照姓名查看指定联系人信息
- 修改联系人：按照姓名重新修改指定联系人
- 清空联系人：清空通讯录中所有信息
- 退出通讯录：退出当前使用的通讯录



###	7.2 创建项目

创建项目步骤：

- 创建新项目
- 添加文件



###	7.3 菜单功能

功能描述：用户选择功能的界面

步骤：

- 封装函数显示该界面 如void showMenu()
- 在main函数中调用封装好的函数



###	7.4 退出功能

功能描述：退出通讯录系统

思路：根据用户不用的选择进入不用的功能，可以选择switch分支结构，对整个架构进行搭建



当用户选择0时，执行退出，选择其他先不做操作，也不会退出程序。

###	7.5 添加联系人

功能描述：实现添加联系人功能，联系人上限为1000人，联系人信息包括（姓名、性别、年龄、联系电话、家庭住址）



添加联系人实现步骤：

- 设计联系人结构体
- 设计通讯录结构体
- main函数中创建通讯录
- 封装添加联系人函数
- 测试添加联系人功能



```c++
在使用vscode的过程中出现了一些问题和解决方案：
    1.使用system("cls")命令导致teminal无法运行，并且无法清屏
    2.因此将其调成cmd输出，将launch.json文件中的externalConsole改为true，即可改为cmd输出，但是这样输出的是一堆乱码，原因是源码是用UTF-8进行编码的，而cmd窗口默认的中文使用gbk编码，因此出现了乱码
    3.解决方法就是引入头文件#include <windows.h>//SetConsoleOutputCP函数所在库函数，让cmd程序的编码更为utf-8
    4.然后在主函数中添加SetConsoleOutputCP(65001);即可正常输出。
```

###	7.6 显示联系人

功能描述：显示通讯录中已有的联系人信息

实现步骤：

- 封装显示联系人函数
- 测试显示联系人功能



###	7.7 删除联系人

功能描述：按照姓名进行删除指定联系人

删除联系人步骤：

- 封装检测联系人是否存在
- 封装删除联系人函数
- 测试删除联系人功能



####	7.7.1 封装检测联系人是否存在

设计思路：

删除联系人前，我们需要先判断用户输入的联系人是否存在，如果存在删除，不存在提示用户没有要删除的联系人。因此可以将其封装到一个函数中去，如果存在，则返回联系人在通讯录中的位置，不存在返回-1。

```
值得注意的问题是case语句中如果有一大段代码，则会报错，因此需要用大括号将代码段括起来。
```

####	7.7.2 封装删除联系人函数

根据用户输入的联系人判断该通讯录中是否含有此人

查找到并进行删除，并提示删除成功

查不到提示查无此人

###	7.8 查找联系人

功能描述：按照姓名查看指定联系人信息

查找联系人实现步骤：

- 封装查找联系人函数
- 测试查找指定联系人



###	7.9 修改联系人

功能描述：按照姓名重新修改指定联系人

###	7.10 清空联系人

只需要将通讯录中人的数量改为0即可，做到逻辑上的清零。

#	二、核心编程

本阶段主要针对c++面向对象编程技术。

##	1内存分区模型

c++程序在执行时，会将内存方向大致分为4个区域：

- 代码区：存放函数体的二进制代码，由操作系统进行管理
- 全局区：存放全局变量和静态变量以及常量
- 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
- 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收。



###	1.1 程序运行前

在程序编译后，生成了.exe可执行文件，未执行该程序前分为两个区域：

**代码区**：

​	存放cpu执行的机器指令

​	代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

​	代码区是**只读**的，使其只读的原因是防止程序意外修改了它的指令

**全局区**：

​	全局变量和静态变量（static）存放与此

​	全局区还包括了常量区，字符串常量和其他常量也存放与此

​	该区域的数据在程序结束之后由操作系统进行释放

总结：

- c++在程序运行前分为全局区和代码区
- 代码区的特点是共享和只读
- 全局区中存放全局变量、静态变量、常量
- 常量区中存放const修饰的全局常量和字符串常量



###	1.2 程序运行后

**栈区**：

​	由编译器自动分配释放，存放函数的参数值，局部变量等

​	注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

**堆区**：

​	由程序员分配释放，若程序员不释放，程序结束时由操作系统回收

​	在c++中主要利用new在堆区开辟内存

###	1.3 new操作符

c++利用new操作符在堆区开辟数据

堆区开辟的额数据由程序员手动开辟，手动释放，释放利用操作符delete

语法：new 数据类型

利用new创建的数据，会返回该数据对应的类型的指针（地址）。

```c++
int * func(){
    int *a=new int(10);
    return a;
}
void test01(){
	int *p=func();
    delete p;
}
void test02(){
    int * arr = new int[10];//10代表数组有10个元素
    for(int i=0;i<10;i++){
        arr[i]=i+100;
    }
    delete[] arr;//需要加上[]才是释放一个数组
}
```

##	2 引用

###	2.1 引用的基本使用

作用：给变量起别名

语法：数据类型 &别名 = 原名

```c++
int &b=a;
b=20;
cout<<a<<endl;//此时a=20,实际上是访问同一块内存
```

###	2.2 引用注意事项

- 引用必须初始化
- 引用在初始化后不可以改变



###	2.3 引用做函数参数

作用：函数传参时，可以利用引用的技术让形参修饰实参

有点：可以简化指针修改实参

###	2.4 引用做函数返回值

作用：引用是可以作为函数的返回值存在的

注意：不要返回局部变量引用

用法：函数调用做为左值

###	2.5 引用的本质

引用本质是在c++内部实现是一个指针常量

###	2.6 常量的引用

作用：常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加const修饰形参，防止形参改变实参

##	3 函数提高

###	3.1 函数默认参数

在c++中，函数的形参列表中的形参是可以有默认值的。

语法：返回值类型 函数名 （参数 = 默认值）{}

注意事项：

1.如果一个位置已经有了默认参数，那么从这个位置往后，从左往右都必须有默认值

2.如果函数声明已经有了默认参数，函数实现就不能有默认参数

###	3.2 函数占位参数

c++函数的形参列表里可以有占位参数，用来做占位，调用函数是必须填补该位置

语法：返回值类型 函数名 （数据类型）{}

占位参数还可以有默认参数

###	3.3 函数重载

作用：函数名可以相同提高复用性

函数重载满足条件：

- 同一个作用域下
- 函数名称相同
- 函数参数类型不同或者个数不同或者顺序不同

函数的返回值不可以作为函数重载的条件



注意事项：

引用作为重载条件

函数重载碰到函数默认参数



##	4 类和对象

c++面向对象的三大特性为：封装、继承、多态

具有相同性质的对象，我们可以抽象为类

###		4.1 封装

封装的意义：

- 将属性和行为作为一个整体表现生活中的事物
- 将属性和行为加以权限控制



封装的意义一：

在设计类的时候，属性和行为卸载一起，表现事物

语法：class 类名{ 访问权限： 属性/行为}

```c++
#include<iostream>
using namespace std;

const double PI = 3.14;
//设计一个圆类，求圆的周长

class Circle{
    //访问权限
    //公共权限
    public:
        //属性--半径
        int m_r;

        //行为--获取圆的周长
        double calculateZC(){
            return 2*PI*m_r;
        }
};

int main(){

    //通过圆类创建具体的圆（对象）
    //实例化 通过一个类创建对象的过程
    Circle c1;
    c1.m_r=10;
    cout<<"圆的周长为："<<c1.calculateZC()<<endl;

    system("pause");
    return 0;
}
```



类中的属性和行为，同一称为成员

属性   成员属性 成员变量

行为   成员函数 成员方法



封装意义二：

类在设计时，可以将属性和行为放在不同的权限下，加以控制

访问权限有三种：

1.public 公共权限  类内外皆可访问

2.protected 保护权限  类内可以访问 类外不能访问	继承儿子可以访问父亲的内容

3.private 私有权限	类内可以访问 类外不能访问	继承儿子不可以访问父亲的内容

####	4.1.1 struct和class的区别



在c++中struct和class的唯一的区别就是默认的访问权限不同

区别：

- struct默认权限为公共
- class  默认权限为私有



####	4.1.2 成员属性设置为私有

**优点**：

​	1.将所有成员属性设置为私有，可以自己控制读写权限，但可以设置一些public属性来对成员进行读写

​	2.对于写权限，我们可以检测数据的有效性

###	4.2 对象的初始化和清理

c++中每个对象也都有初始设置以及对象销毁前的清楚数据的设置。

####	4.2.1 构造函数和析构函数

对象的初始化和清理也是两个非常重要的安全问题

​	一个对象或者变量没有初始状态，对其使用结果是未知的

​	同样的使用完一个对象或者变量没有及时清理，也会造成一定的安全问题



c++利用构造函数和析构函数解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。

对象的初始化和清理工作是编译器强制我们做的事情，因此我们如果不能提供构造和析构，编译器会提供

编译器提供的构造函数和析构函数是空实现



- 构造函数：主要用于**创建**对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用
- 析构函数：主要用于对象**销毁**前系统自动调用，执行一些清理工作。



**构造函数语法：**类名（）{}

​	1.构造函数，没有返回值也不写void

​	2.函数名称和类名相同

​	3.构造函数可以有参数，因此可以发生重载

​	4.程序在调用对象时会自动调用构造，无须手动调用，而且只会调用一次



**析构函数语法：**~类名 （）{}

​	1.析构函数，没有返回值也不写void

​	2.函数名称和类名相同，在名称前加上符号~

​	3.析构函数不可以有参数，因此不可以发生重载

​	4.程序在对象销毁前自动调用析构，无须手动调用，而且只会调用一次

####	4.2.2 构造函数的分类及调用

两种分类方式：

​	按参数分为：有参构造和无参构造

​	按类型分为：普通构造和拷贝构造

三种调用方式：

​	括号法

​	显示法

​	隐式转换法

####	4.2.3 拷贝构造函数调用时机

c++中拷贝构造函数调用时机通常有三种情况：

- 使用一个已经创建完毕的对象来初始化一个新对象
- 值传递的方式给函数参数传值
- 以值方式返回局部对象



####	4.2.4 构造函数调用规则

默认情况下，c++编译器至少给一个类添加三个函数：
1.默认构造函数（无参，函数体为空）

2.默认析构函数（无参，函数体为空）

3.默认拷贝构造函数，对属性进行值拷贝



构造数调用规则如下：

- 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
- 如果用户定义拷贝构造函数，c++不会提供其他构造函数



####	4.2.5 深拷贝与浅拷贝

深浅拷贝是面试经典问题，也是常见的一个坑。



浅拷贝：简单的赋值拷贝操作，会产生堆区的重复释放问题

深拷贝：在堆区**重新申请空间**，进行拷贝操作



####	4.2.6 初始化列表

c++提供了初始化列表语法，用来初始化属性。

语法：

```c++
构造函数（): 属性1（值1），属性2（值2）...{}
```



####	4.2.7 类对象作为类成员

c++类中的成员可以是另一个类的对象，我们称该成员为对象成员

构造的时候先构造其他类的对象，再构造本类对象。析构的顺序与构造相反。



####	4.2.8 静态成员

静态成员就是在成员变量和成员函数前加上关键字static，成为静态成员

静态成员分为：

- 静态成员变量
  - 所有对象共享同一份数据
  - 在编译阶段分配内存
  - 类内声明，类外初始化
- 静态成员函数
  - 所有成员共享一个函数
  - 静态成员函数智能访问静态成员变量



###	4.3 c++对象模型和this指针

####	4.3.1 成员变量和成员函数分开存储

在c++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上

空对象占用空间为1字节，是为了区分空对象占内存的位置，每个空对象也应该有一个独一无二的内存地址。

####	4.3.2 this指针的概念

上面提到了c++中成员变量和成员函数是分开存储的，每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码。

那么问题就是：这一块代码是如何区分哪个对象调用自己的呢？



c++通过提供特殊的对象指针，this指针，解决上述问题，this指针指向被调用的成员函数所属的对象。



this指针是隐含每一个非静态成员函数内的一种指针

this指针不需要定义直接使用即可



this指针的用途：

- 当形参和成员变量同名时，可以使用this指针来进行区分
- 在类的非静态成员函数中返回对象本身，可以使用return * this

```c++
#include<iostream>
using namespace std;

class Person{
public:
    Person(int age){
        //this指针指向被调用的成员函数所属的对象
        this->age=age;
    }
    Person& PersonAddAge(Person &p){
        this->age+=p.age;
        return *this;//引用返回就是直接可以返回本身，而不用引用就是直接返回一个拷贝数据
    }
    int age;
};
//1.解决名称冲突
void test01(){
    Person p1(18);
    cout<<"p1的年龄："<<p1.age<<endl;
}
void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddAge(p2).PersonAddAge(p1).PersonAddAge(p1);
    cout<<"p2的年龄为："<<p2.age<<endl;
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
```





####	4.3.3 空指针访问成员函数

c++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针



如果用到this指针，需要加以判断保证代码的健壮性

```c++
#include<iostream>
using namespace std;

//空指针调用成员函数
class Person{
public:
    void showClassName(){
        cout<<"this is Person class"<<endl;
    }
    void showPersonAge(){
        if(this==NULL){
            return;
        }
        cout<<"age="<<m_Age<<endl;
    }
    int  m_Age;
};
void test01(){
    Person * p =NULL;
    p->showClassName();
    p->showPersonAge();//传入空指针为空
}
int main(){
    system("pause");
    return 0;
}
```

####	4.3.4 const修饰成员函数

常函数：

- 成员函数后加const后我们称这个函数为常函数
- 常函数内不可以修改成员属性
- 成员属性声明时加关键字mutable后，在常函数总依然可以进行修改



常对象：

- 声明对象前加const称该对象为常对象
- 常对象只能调用常函数



```c++
void show() const//本质其实是修饰this指针
mutable int age;
const Person p;
```

###	4.4 友元

在程序里，有些私有属性，也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的就是让一个函数或者类访问另一个类中私有成员

友元的关键字为 friend

友元的三种实现：

- 全局函数做友元
- 类做友元
- 成员函数做友元



####	4.4.1 全局函数做友元

```c++
#include<iostream>
#include<string>
using namespace std;

class Building{
    friend void goodGay(Building * building);
public:
    Building(){
        m_SittingRoom="客厅";
        m_BedRoom="卧室";
    }
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

void goodGay(Building * building){
    cout<<"全局函数正在访问："<<building->m_SittingRoom<<endl;
    cout<<"全局函数正在访问："<<building->m_BedRoom<<endl;
}

void test01(){
    Building building;
    goodGay(&building);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	4.4.2 类做友元

```c++
#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay{
public:
    GoodGay();
    void visit();//参观函数 访问building中的属性
    Building * building;
};
class Building{
    friend class GoodGay;
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

//类外去写成员函数
Building::Building(){
    m_SittingRoom="客厅";
    m_BedRoom="卧室";
}
GoodGay::GoodGay(){
    //创建建筑物对象
    building = new Building;
}
void GoodGay::visit(){
    cout<<"全局函数正在访问："<<building->m_SittingRoom<<endl;
    cout<<"全局函数正在访问："<<building->m_BedRoom<<endl;
}
void test01(){
    GoodGay gg;
    gg.visit();
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

这里要注意一个问题：就是在GoodGay中使用Building类就必须实现声明，而且如果前面只有事先声明的话就应该在GoodGAY中调用函数时，将函数写在类外，这样才能够很好的进行运行，否则就会出现编译问题。

####	4.4.3 成员函数做友元

```c++
#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay{
public:
    GoodGay();
    void visit();//参观函数 访问building中的属性
    void visit2();//不可以访问
    Building * building;
};
class Building{
    friend void GoodGay::visit();
public:
    Building();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};
//类外去写成员函数
Building::Building(){
    m_SittingRoom="客厅";
    m_BedRoom="卧室";
}
GoodGay::GoodGay(){
    //创建建筑物对象
    building = new Building;
}
void GoodGay::visit(){
    cout<<"全局函数正在访问："<<building->m_SittingRoom<<endl;
    cout<<"全局函数正在访问："<<building->m_BedRoom<<endl;
}
void GoodGay::visit2(){
    cout<<"全局函数正在访问："<<building->m_SittingRoom<<endl;
}
void test01(){
    GoodGay gg;
    gg.visit();
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

###	4.5 运算符重载

运算符重载的概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

####	4.5.1 加号运算符重载

实现两个自定义数据类型相加的运算。operator+编译器默认的符号。

```c++
#include<iostream>
using namespace std;

//加号运算符重载
class Person{
public:
    //1.成员函数重载
    // Person operator+(Person &p){
    //     Person temp;
    //     temp.m_A=this->m_A+p.m_A;
    //     temp.m_B=this->m_B+p.m_B;
    //     return temp;
    // }
    int m_A;
    int m_B;
};
//2.全局函数重载
Person operator+(Person &p1,Person &p){
        Person temp;
        temp.m_A=p1.m_A+p.m_A;
        temp.m_B=p1.m_B+p.m_B;
        return temp;
    }
void test01(){
    Person p1;
    p1.m_A=10;
    p1.m_B=10;
    Person p2;
    p2.m_A=10;
    p2.m_B=10;

    Person p3=p1+p2;
    cout<<"m_A="<<p3.m_A<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	4.5.2 左移运算符重载

可以输出自定义数据类型

```c++
#include<iostream>
using namespace std;

//左移运算符重载
class Person{
public:
    //一般不会使用成员函数做左移运算符，无法保证cout在左边
    int m_A;
    int m_B;
};
ostream & operator<<(ostream &cout,Person &p){
    cout<<p.m_A<<" "<<p.m_B;
    return cout;
}
void test01(){
    Person p;
    p.m_A=10;
    p.m_B=10;
    cout<<p<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	4.5.3 递增运算符重载



####	4.5.4 赋值运算符重载

c++编译器至少给一个类添加四个函数：

​	1.默认构造函数（无参，函数体为空）

​	2.默认析构函数（无参，函数体为空）

​	3.默认拷贝构造函数，对属性进行值拷贝

​	4.赋值运算符operator=，对属性进行值拷贝

如果类中有属性指向堆区，做赋值操作也会出现深浅拷贝的问题

####	4.5.5 关系运算符重载

重载关系运算符，可以让两个自定义类型的对象进行对比操作。

####	4.5.6 函数调用运算符重载

函数调用运算符（）也可以重载

由于重载后使用的方式非常像函数的调用，因此成为仿函数

仿函数没有固定写法，非常灵活。

###	4.6 继承

继承面向对象三大特性之一。

继承得到的新的对象不仅有上一级对象的特性，而且还包含自己的特性。

####	4.6.1 继承的基本语法

减少重复的代码。

语法： class 子类（派生类） ：继承方式  父类（基类）

```c++
class Java : public BasePage{
    
};
```

####	4.6.2 继承方式

继承的方式一共有三种：

- 公共继承
- 保护继承
- 私有继承



####	4.6.3 继承中的对象模型

问题：从父类继承过来的成员，哪些属于子类对象？

在父类中所有非静态成员属性会被子类继承下去。但是父类中的私有属性被编译器隐藏了，因此访问不到，但是被继承下去了。

利用开发人员命令提示工具查看对象模型->条咋混盘符->跳转文件路径 cd 具体路径->查看命名->c1 d1 reportSingleClassLayout类名 文件名



####	4.6.4 继承中构造和析构顺序

子类继承父类后，当创建子类对象，也会调用父类的构造函数。

问题：父类和子类的构造和析构顺序谁先谁后？

顺序如下：

构造父类->构造子类

析构顺序和构造顺序相反。

####	4.6.5 继承同名成员处理方式

问题：当子类与父类出现同名成员，如何通过子类对象，访问到子类或者父类中同名的数据呢？

- 访问子类同名成员 直接访问即可
- 访问父类同名成员 需加作用域

```c++
s.Base::m_A;//访问父类中的成员
s.Base::func();//访问父类中的函数
```

如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数。

####	4.6.6 继承同名静态成员处理方式

问题：继承中同名的静态成员在子类对象上如何进行访问？

静态成员和非静态成员出现同名，处理方式一致。

####	4.6.7 多继承语法

c++允许一个类继承多个类

语法：class 子类 ：继承方式 父类1，继承方式 父类2...

多继承可能会引发父类中有同名成员出现，需要加作用域进行区分

c++实际开发中不建议使用多继承

####	4.6.8 菱形继承

概念：

​	两个派生类继承同一个基类

​	又有某个类同时继承两个派生类

​	这种继承被称为菱形继承或者钻石继承

利用虚继承可以解决菱形继承的问题

继承之前加上关键字virtual变为虚继承

最开始的基类被称为虚基类

vbptr-虚基类指针，指向一个虚基类表

###	4.7 多态

####	4.7.1 多态的基本概念

多态是c++面向对象三大特性之一

多态分为两类：

- 静态多态：函数重载和运算符重载属于静态多态，复用函数名
- 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态的区别：

- 静态多态的函数地址早绑定-编译阶段确定函数地址
- 动态多态的函数地址晚绑定-运行阶段确定函数地址

动态多态满足条件：

- 有继承关系
- 子类重写父类的虚函数

动态多态使用：

- 父类的指针或者引用执行子类对象



####	4.7.2 多态案例1——计算机类

分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

多态的优点：

- 代码组织结构清晰
- 可读性强
- 利于前期和后期的扩展以及维护

```c++
#include<iostream>
#include<string>
using namespace std;

//分别利用普通写法和多态技术实现计算器

//普通写法
class Calculator{
public:
    int getResult(string oper){
        if(oper=="+"){
            return m_Num1+m_Num2;
        }else if(oper=="-"){
            return m_Num1-m_Num2;
        }else if(oper=="*"){
            return m_Num1*m_Num2;
        }//如果想要拓展新的功能需要修改源码
        //在真实的开发中提倡开闭原则
        //开闭原则：对扩展进行开放，对修改进行关闭
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
void test01(){
    Calculator c;
    c.m_Num1=10;
    c.m_Num2=10;
    cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult("+")<<endl;
}
//利用多态实现计算器
//实现计算器抽象类
class AbstractCalculator{
public:
    virtual int getResult(){
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
//加法计算器类
class AddCalculator : public AbstractCalculator{
public:
    int getResult(){
        return m_Num1+m_Num2;
    }
};
//减法计算器类
class SubCalculator : public AbstractCalculator{
public:
    int getResult(){
        return m_Num1-m_Num2;
    }
};
//乘法计算器类
class MulCalculator : public AbstractCalculator{
public:
    int getResult(){
        return m_Num1*m_Num2;
    }
};
void test02(){
    //多态使用条件：父类指针或者引用指向子类对象
    AbstractCalculator * abc= new AddCalculator;
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<abc->m_Num1<<"+"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    //用完需销毁
    delete abc;
    abc=new SubCalculator;
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<abc->m_Num1<<"-"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    //用完需销毁
    delete abc;
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
```



####	4.7.3 纯虚函数和抽象类

在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容。

因此可以将虚函数改为纯虚函数

纯虚函数语法：virtual 返回值类型 函数名 {参数列表} = 0；

当类中有了虚函数，这个类也称为抽象类

抽象类特点：

- 无法实例化对象
- 子类必须重写抽象类中的纯虚函数，否则也属于抽象类



####	4.7.4 多态案例2——制作饮品

制作饮品的大致流程为：煮水——冲泡——导入杯中——加入辅料

利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶

```c++
#include<iostream>
using namespace std;
//多态的案例2——制作饮品
class AbstractDrinking{
public:
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSomething() = 0;
    //制作饮品
    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};
//制作咖啡
class Cafe : public AbstractDrinking{
public:
    //煮水
    virtual void Boil(){
        cout<<"煮农夫山泉"<<endl;
    }
    //冲泡
    virtual void Brew(){
        cout<<"冲泡咖啡"<<endl;
    }
    //倒入杯中
    virtual void PourInCup(){
        cout<<"倒入杯中"<<endl;
    }
    //加入辅料
    virtual void PutSomething(){
        cout<<"加入糖和牛奶"<<endl;
    }
};
//制作咖啡
class Tea : public AbstractDrinking{
public:
    //煮水
    virtual void Boil(){
        cout<<"煮农夫山泉"<<endl;
    }
    //冲泡
    virtual void Brew(){
        cout<<"冲泡茶叶"<<endl;
    }
    //倒入杯中
    virtual void PourInCup(){
        cout<<"倒入杯中"<<endl;
    }
    //加入辅料
    virtual void PutSomething(){
        cout<<"加入柠檬"<<endl;
    }
};
void doWork(AbstractDrinking * abc){
    abc->makeDrink();
    delete abc;
}
void test01(){
    //制作咖啡
    doWork(new Cafe);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	4.7.5 虚析构和纯虚析构

多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为虚析构或者纯虚析构

虚析构和纯虚析构共性：

- 可以解决父类指针释放子类对象
- 都需要具体的函数实现

虚析构和纯虚析构区别：

- 如果是纯虚析构，该类属于抽象类，无法实例化对象

 

##	5.文件操作

程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过文件可以将数据持久化

c++对文件操作需要包含头文件<fstream>



文件类型主要分为两种：

1.文本文件 - 文件以文本的ASCII码形式存储在计算机中

2.二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂他们



操作间的三大类：

1.ofstream： 写操作

2.ifstream： 读操作

3.fstream： 读写操作

###	5.1 文本文件

####	5.1.1 写文件

写文件步骤如下：

1.包含头文件

#include<fstream>

2.创建流对象

ofstream ofs;

3.打开文件

ofs.open("文件路径",打开方式);

4.写数据

ofs<<"写入的数据";

5.关闭文件

ofs.close();

注意：文件打开方式可以配合使用，利用|操作符

例如：用二进制方式写文件ios::binary | ios::out

####	5.1.2 读文件

1.包含头文件

#include<fstream>

2.创建流对象

ifstream ifs;

3.打开文件并判断文件是否打开成功

ifs.open("文件路径",打开方式);

4.读数据

四种读取方式

5.关闭文件

ifs.close();

###	5.2 二进制文件

打开方式需要指定为ios::binary

####	5.2.1 写文件

二进制方式写文件主要利用流对象调用成员函数write

函数原型：ostream& write(const char * buffer,int len);

参数解释：字符指针buffer指向内存中一段存储空间，len 是读写的字节数

####	5.2.2 读文件

二进制方式读文件主要利用流对象调用成员函数read

函数原型：istream & read(char * buffer, int len);

参数解释：字符指针buffer指向内存中一段存储空间，len 是读写的字节数

##	6.实例2-职工管理系统

###	6.1 管理系统需求

用来管理公司内所有员工的信息。

公司内职工主要分为三类：普通员工、经理、老板。显示信息时需要显示职工编号、职工姓名、职工岗位、以及职责

普通员工职责：完成经历教给的任务

经理职责：完成老板教给的任务，并下发任务至员工

老板职责：管理公司所有事物



管理系统中需要实现的功能如下：

- 退出管理程序：退出当前管理系统
- 增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为职工编号、职工姓名、部门编号
- 显示职工信息：显示公司内部所有职员信息
- 删除离职员工：按照编号删除指定的职工
- 修改员工信息：按照编号修改职工个人信息
- 查找职工信息：按照职工的编号或者职工的姓名进行查找相关的人员信息
- 按照编号排序：按照职工编号，进行排序，排序规则由用户指定
- 清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）



###	6.2 创建项目

###	6.3 创建管理类

负责的内容如下：

- 与用户的沟通交流菜单界面
- 对职工增删改查操作
- 与文件的读写交互



####	6.3.1 创建文件

在头文件和源文件的文件夹下分别创建workerManager.h和workerManager.cpp文件

####	6.3.2 头文件实现

在头文件中设计管理类

####	6.3.3 源文件实现

在workManager.cpp中将构造函数和析构函数空补全

###	6.4 菜单功能

功能描述：与用户沟通的界面

####	6.4.1 添加成员函数

在workerManager.h中添加成员函数 void Show_Menu();

####	6.4.2 菜单功能实现

在workerManager.cpp中实现 Show_Menu()函数

####	6.4.3 测试菜单功能实现

###	6.5 退出功能

####	6.5.1 提供功能接口

在main函数中提供分支功能，提供每个功能接口

####	6.5.2 实现退出功能

在workerManager.h中提供退出系统的成员函数 void exitSystem();

在workerManager.cpp中提供具体实现功能

####	6.5.3 测试退出功能

###	6.6 创建职工类

职工的分类为：普通员工，经理，老板

将三种职工抽象到一个类worker中，利用多态管理不同职工种类

职工属性为：职工编号、职工姓名、职工所在部门

职工的行为：岗位信息描述。获取岗位名称

###	6.7 添加职工

功能描述：批量添加职工，并且保存到文件中	

####	6.7.1 功能分析

用户在批量创建的时候会创建不同种类的职工

如果想将所有不用种类的员工都放在一个数组红，可已经所有员工的指针维护到一个数组里面

如果想在程序中维护这个不定长度的数组，可已经数组创建到堆区，并利用Worker **的指针维护

###	6.8 文件交互-写文件

上述功能在程序运行结束之后无法保存数据，因此需要读写操作

###	6.9 文件交互-读文件

将文件内容读取到文件中

因此构造函数初始化数据情况分为三种：

1.第一次使用，文件未创建

2.文件存在，但是数据被用户清空

3.文件存在，并且保存职工的所有数据

###	6.10 显示职工

###	6.11 删除职工

###	6.11 修改职工

按照编号对职工信息进行修改

###	6.12 查找职工

###	6.13 排序

###	6.14清空

需再次确认





#	三、c++提高编程

本阶段主要针对c++泛型编程和STL技术做详细讲解，探讨c++更深层的使用。

##	1 模板

###	1.1 模板的概念

模板就是建立通用的模具，大大提高复用性。

特点：

- 模板不可以直接使用，他只是一个框架
- 模板的通用并不是万能的



###	1.2 函数模板

- c++另一种编程思想称为泛型编程，主要利用的技术就是模板
- c++提供两种模板机制：函数模板和类模板



####	1.2.1 函数模板语法

函数模板作用：

​	建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表

```c++
//语法：
template<typename T>//typename 可以替换成class
//函数声明或定义
```

解释：

template  ---  声明创建模板

typename  --- 表明其后面的符号是一种数据类型，可以用class代替

T  ---  通用的数据类型，名称可以替换，通常为大写字母

####	1.2.2 函数模板注意事项

注意事项：

- 自动类型推导，必须推导出一致的数据类型T才可以使用
- 模板必须要确定出T的数据类型才可以使用



####	1.2.3 函数模板案例

案例描述：

- 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
- 排序规则从大到小，排序算法为选择排序
- 分别利用char数组和int数组进行测试



####	1.2.4 普通函数和函数模板的区别

区别如下：

- 普通函数调用时可以发生自动类型转换（隐式类型转换）
- 函数模板调用时如果利用自动类型推导不会发生隐式类型转换
- 如果利用显示指定类型的方式，可以发生隐式类型转换



####	1.2.5 普通函数和函数模板的调用规则

调用规则如下：

- 如果函数模板和普通函数都可以实现，优先调用普通函数
- 可以通过空模板参数列表来强制调用函数模板              myPrint<>（）
- 函数模板也可以发生重载
- 如果函数模板可以产生更好的匹配，优先调用函数模板



####	1.2.6 模板的局限性

模板的通用性不是万能的。

###	1.3 类模板

####	1.3.1 类模板语法

类模板作用：

- 建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表

语法：

```c++
template<typename T>
类
```

template--声明创建模板

typename--表明其后面的符号是一种数据类型，可以用class代替

T-- 通用数据类型，名称可以替换，通常为大写字母

####	1.3.2 类模板和函数模板区别

主要区别如下：

1.类模板没有自动类型推导的使用方式

2.类模板在模板参数列表中可以有默认参数

####	1.3.3 类模板中成员函数创建时机

- 普通类中的成员函数一开始就可以创建
- 类模板中的成员函数在调用时才创建



####	1.3.4 类模板对象做函数参数

1.指定传入的类型 -- 直接显示对象的数据类型

2.参数化模板 -- 将对象中的参数变为模板进行传递

3.整个类模板化 -- 将这个对象类型模板化进行传递



####	1.3.5 类模板与继承

- 当子类的父类是一个类模板时，子类在声明的时候要指出父类中T的类型
- 如果不指定，编译器无法给子类分配内存
- 如果想灵活指定出父类中T的类型，子类也需要变为类模板



####	1.3.6 类模板成员函数类外实现

```c++
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    类外构造函数实现
}
```



####	1.3.7 类模板分文件编写

问题：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决方式：

- 直接包含.cpp源文件
- 将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制



##	2 STL初识

###	2.1 STL基本概念

- STL（Standard Template Library，标准模板库）
- STL从广义上分为：容器（Container）算法（algorithm）迭代器（iterator）
- 容器和算法之间通过迭代器进行无缝连接
- STL几乎所欲的代码都采用了模板类或者模板函数



###	2.2 STL六大组件

分别为：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

1.容器：各种数据结构，如vector,list,deque,set,map等，用来存放数据

2.算法：各种常用的算法，如sort、find、copy、for_each等

3.迭代器：扮演容器和算法之间的胶合剂

4.仿函数：行为类似函数，可作为算法的某种策略

5.适配器：一种用来修饰容器或者仿函数或迭代器接口的东西

6.空间配置器：负责空间的配置与管理

###	2.3 STL中容器、算法、迭代器

STL容器就是将运用最广泛的数据结构实现出来。

可以分为序列式容器和关联式容器两种：

序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置

关联式容器：二叉树结构，各元素之间没有严格物理上的顺序关系。



算法（Algorithms）分为：质变算法和非质变算法

质变算法：指运算的过程中会更改区间内的元素的内容，例如开呗，替换，删除等

非质变算法：指运算过程中，不会改变区间内的元素内容，例如查找，计数，遍历，寻找极值等



迭代器：提供一种方法，使其能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方法，每个容器都有自己专属的迭代器。

迭代器使用非常类似于指针。

迭代器种类：

| 种类           | 功能                                                     | 支持运算                                |
| -------------- | -------------------------------------------------------- | --------------------------------------- |
| 输入迭代器     | 对数据只读访问                                           | 只读，支持++、==、！=                   |
| 输出迭代器     | 对数据只写访问                                           | 只写，支持++                            |
| 前向迭代器     | 读写操作，并能向前推进迭代器                             | 读写，支持++、==、！=                   |
| 双向迭代器     | 读写操作，并能向前和向后操作                             | 读写、支持++、--                        |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为双向迭代器和随机访问迭代器

###	2.4 容器算法迭代器初识

STL中最常用的容器为Vector，可以理解为数组

#### 2.4.1 vector存放内置数据类型

容器：vector

算法：for_each

迭代器：vector<int>::iterator

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void myPrint(int val){
    cout<<val<<endl;
}
//vector容器存放内置的数据类型
void test01(){
    //创建了一个vector人气
    vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // //通过迭代器访问容器中的数据
    // //起始迭代器，指向容器中的第一个元素
    // vector<int>::iterator itBegin=v.begin();
    // //结束迭代器，指向最后一个元素的下一个位置
    // vector<int>::iterator itEnd=v.end();
    // //1.遍历方式
    // while(itBegin!=itEnd){
    //     cout<<*itBegin<<endl;
    //     itBegin++;
    // }
    // //2.遍历方式
    // for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    //     cout<<*it<<endl;
    // }
    //3.遍历方式,利用STL中提供的遍历算法
    for_each(v.begin(),v.end(),myPrint);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	2.4.2 vector存放自定义数据类型

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<string>

//vector中存放自定义的数据类型
class Person{
public:
    Person(string name,int Age){
        this->m_Name=name;
        this->age=Age;
    }
public:
    string m_Name;
    int age;
};
void test01(){
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //遍历容器中的数据
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        cout<<"姓名："<<(*it).m_Name<<endl;
        cout<<"年龄:"<<(*it).age<<endl;
    }
}
//存放数据类型的指针
void test02(){
    vector<Person*> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    //遍历容器
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++){
        cout<<"姓名"<<(*it)->m_Name<<endl;
        cout<<"年龄"<<(*it)->age<<endl;
    }
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
```

####	2.4.3 vector容器嵌套容器

```c++
#include<iostream>
using namespace std;
#include<vector>

//容器嵌套容器
void test01(){
    vector<vector<int>> v;
    //创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    //向小容器中添加数据
    for(int i=0;i<4;i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    //将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    //通过大容器遍历数据
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
        //(*it)是一个容器
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++){
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

##	3 常用容器

###	3.1 string容器

####	3.1.1 string基本概念

本质：string是c++风格的字符串，而string本质上是一个类

string和char *的区别：

- char *是一个指针
- string是一个类，类内部封装了char *，管理这个字符串，是一个char *型容器

特点：

string类内封装了很多成员方法，例如查找find，拷贝copy，删除delete，替换replace，插入insert

string管理char *所分配的内存，不用担心幅值越界和取值越界等，由类内部负责。

####	3.1.2 string构造函数

构造函数原型：



- string() //创建一个空字符串，例如string str;
- string(const char* s)//使用字符串s初始化
- string(const string & str);//使用一个string对象初始化另一个string对象
- string(int n,char c)//使用n个字符c初始化



####	3.1.3 string赋值操作

功能描述：给string字符串进行赋值

赋值的函数原型：

- string& operator=(const char* s); //char*类型字符串赋值给当前的字符串
- string& operator=(const string &s); //把字符串s赋值给当前的字符串
- string& operator=char c; //字符赋值给当前的字符串
- string& assign(const char *s); //把字符串s赋值给当前字符串
- string& assign(const char *s,int n);//把字符串的前n个字符赋值给当前的字符串
- string& assign(const string &s); //把字符串s赋值给当前字符串
- string& assign(int n,char c);用n个字符c赋给当前字符串



####	3.1.4 string字符串拼接

功能描述：实现在字符串末尾拼接字符串

函数原型：

- string& operator+=(const char* str);//重载+=运算符
- string& operator+=(const char c);//重载+=运算符
- string& operator+=(const string& str);//重载+=运算符
- string& append(const char *s);//把字符串连接到当前字符串结尾
- string& append(const char*s, int n);//将字符串s前n个字符连接到当前字符串末尾
- string& append(const string &s);//同operator+=(const string& str)
- string& append(const string &s,int pos,int n);//字符串s从pos开始的n个字符连接到字符串结尾



####	3.1.5 string查找和替换

查找：查找指定的字符串是否存在

替换：在指定的位置置换字符串

![image-20220426183256684](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220426183256684.png)

####	3.1.6 string字符串比较

比较方式：按照ASCII码进行对比

=返回0

\>返回1

\<返回-1

函数原型：

- int compare(const string &s) const;//与字符串s比较
- int compare(const char *s) const;//与字符串s进行比较



####	3.1.7 string字符存取

- char& operator[](int n);//通过[]方式存取字符
- char& at(int n);//通过at方法存取字符



####	3.1.8 string插入和删除

![image-20220426184708610](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220426184708610.png)

####	3.1.9 string子串

函数原型：

- string substr(int pos=0,int n=npos) const;//返回由pos开始的n个字符组成的字符串



###	3.2 Vector容器

####	3.2.1 vector基本概念

功能：vector数据结构和数组十分相似，也被称为单端数组

vector与普通数组区别：不同之处在于数组是静态空间，而vector可以动态扩展

动态扩展：并不是在源空间之后续接新空间，而是找到更大的内存空间，然后将元数据拷贝新空间，释放原空间。

vector的迭代器是支持随机访问的迭代器。

####	3.2.2 vector构造函数

![image-20220426195526211](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220426195526211.png)

```c++
#include<iostream>
using namespace std;
#include<vector>


void printVector(vector<int>v1){
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
//vector容器构造
void test01(){
    vector<int>v1;//默认构造 无参构造
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);
    //通过区间方式进行构造
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);
    //n个elem方式构造
    vector<int>v3(10,100);
    printVector(v3);
    //拷贝构造
    vector<int>v4(v3);
    printVector(v4);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```



####	3.2.3 vector赋值操作

![image-20220426202258517](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220426202258517.png)

```c++
#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>v1){
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);
    //赋值
    vector<int>v2;
    v2=v1;
    printVector(v2);
    //assign
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);
    //n个elem方式赋值
    vector<int>v4;
    v4.assign(10,100);
    printVector(v4);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	3.2.4 vector容量和大小

![image-20220426203418557](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220426203418557.png)

####	3.2.5 vector插入和删除

![image-20220426203606697](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220426203606697.png)

####	3.2.6 vector数据存取

![image-20220426210402211](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220426210402211.png)

```c++
#include<iostream>
using namespace std;
#include<vector>

void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    //利用[]来访问数组中的元素
    for(int i;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    //利用at方式
    for(int i=0;i<10;i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    //访问第一个元素
    cout<<"第一个元素为："<<v1.front()<<endl;
    //获取最后一个元素
    cout<<"最后一个元素："<<v1.back()<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```



####	3.2.7 vector互换容器

函数原型：

​	swap(vec);//将vec与本身元素互换

####	3.2.8 vector预留空间

减少vector在动态扩展容量时的扩展次数。

函数原型：reserve（int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

###	3.3 deque容器

####	3.3.1 deque容器基本概念

功能：双端数组，可以对头端进行插入删除操作

deque和vector的区别：

- vector对于头部的插入删除效率低，数据量越大，效率越低
- deque相对而言，对头部的插入删除速度比vector快
- vector访问元素的速度会比deque快，这和两者内部实现有关

deque内部工作原理：

deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间。

![image-20220427103728542](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427103728542.png)

deque容器的迭代器也是支持随机访问的。

####	3.3.2 deque构造函数



![image-20220427104022615](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427104022615.png)

####	3.3.3 deque赋值操作

![image-20220427104127492](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427104127492.png)



####	3.3.4 deque大小操作

![image-20220427104234493](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427104234493.png)

####	3.3.5 deque插入和删除



![image-20220427104344352](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427104344352.png)

####	3.3.6 deque数据存取



![image-20220427104521961](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427104521961.png)



####	3.3.7 deque排序

算法：

sort(iterator beg,iterator end);//对beg和end区间内元素进行排序

```c++
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void printDeque(const deque<int>&d){
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
//deque排序
void test01(){
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(500);
    d.push_back(200);
    d.push_back(300);
    printDeque(d);
    //排序,sort默认升序排列
    //vector容器也可以支持sort排序
    sort(d.begin(),d.end());
    printDeque(d);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

###	3.4 案例评委打分

####	3.4.1 案例描述

有五名选手，ABCDE，10名选手分别对每一名选手打分，去掉最高分，去掉最低分，取平均分

####	3.4.2 实现步骤

1. 创建五名选手，放到vector中
2. 遍历vector容器，取出每一位选手，执行for循环，可以把10个评委打分存到deque容器中
3. sort算法对deque容器中分数进行排序，去掉最高分和最低分
4. deque容器遍历一遍，累加总分
5. 获取平均分



```c++
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>


class Person{
public:
    Person(string name,int score){
        this->m_Name=name;
        this->m_Score=score;
    }
    string m_Name;
    int m_Score;
};
void createPerson(vector<Person>&v){
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++){
        string name="player:";
        name+=nameSeed[i];
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }
}
void setScore(vector<Person>&v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        //将评委的分数放入deque容器中
        deque<int>d;
        for(int i=0;i<10;i++){
            int score = rand()%41+60;
            d.push_back(score);
        }
        // cout<<it->m_Name<<" 打分："<<endl;
        // for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
        //     cout<<*dit<<" ";
        // }
        // cout<<endl;
        sort(d.begin(),d.end());
        d.pop_back();
        d.pop_front();
        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
            sum+=*dit;
        }
        int avg=sum/d.size();
        it->m_Score=avg;
    }
}
void showScore(vector<Person>&v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        cout<<it->m_Name<<" score:"<<it->m_Score<<endl;
    }
}
int main(){
    //随机数种子
    srand((unsigned int)time(NULL));
    //1.创建五名选手
    vector<Person>v;//存放选手容器
    createPerson(v);
    //2.给5名选手打分
    setScore(v);
    //3.显示最后得分
    showScore(v);
    system("pause");
    return 0;
}
```

###	3.5 stack容器

####	3.5.1 stack基本概念

概念：stack是一种先进后出（first in last out,FILO)的数据结构，他只有一个出口。栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为。

栈中入数据叫入栈，出数据叫出栈。

####	3.5.2 stack常用接口

![image-20220427193014221](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220427193014221.png)



```c++
#include<iostream>
using namespace std;
#include<stack>

//栈stack接口
void test01(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    //只要栈不为空,就查看栈顶，并且执行出栈操作
    while(!s.empty()){
        //查看栈顶元素
        cout<<"栈顶元素："<<s.top()<<endl;
        s.pop();
    }
    cout<<"栈的大小："<<s.size()<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```



###	3.6 queue容器

####	3.6.1 queue基本概念

概念：是一种先进先出（First In First Out,FIFO)的数据结构，他有两个出口。

队列容器允许从一端新增元素，从另一端移除元素。

队列中只有对头和队尾才能被外界使用，因此队列不允许有遍历行为。

队列中进数据叫入队push，出数据叫pop

![image-20220427194625844](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220427194625844.png)



####	3.6.2 queue常用接口

```c++
#include<iostream>
using namespace std;
#include<queue>
#include<string>

class Person{
public:
    Person(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};
void test01(){
    queue<Person>q;
    Person p1("唐僧",30);
    Person p2("孙悟空",1000);
    Person p3("猪八戒",900);
    Person p4("沙僧",80);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    while(!q.empty()){
        cout<<"队头元素：-----"<<q.front().m_Name<<" 年龄："<<q.front().m_Age<<endl;
        cout<<"队尾元素：-----"<<q.back().m_Name<<" 年龄："<<q.back().m_Age<<endl;
        q.pop();
    }
    cout<<"队列大小："<<q.size()<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```



###	3.7 list容器

####	3.7.1 list基本概念

功能：将数据进行链式存储

链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针连接实现的。

链表的组成：链表由一系列结点组成

结点的组成：一个是存储数据元素的数据域，另一个书存储下一个结点地址的指针域

STL中的链表是一个双向循环链表

优点：采用动态存储分配，不会造成内存浪费和溢出；链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素。

缺点：链表灵活，但是空间和时间额外消耗较大

list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

####	3.7.2 list构造函数

![image-20220429094805131](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220429094805131.png)

```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>&L){
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
    //区间方法构造
    list<int>L2(L1.begin(),L1.end());
    printList(L2);
    //拷贝构造
    list<int>L3(L2);
    printList(L3);
    //n个elem
    list<int>L4(10,1000);
    printList(L4);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	3.7.3 list赋值和交换

![image-20220429095831030](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220429095831030.png)



```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>L){
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
    list<int>L2;
    L2=L1;
    printList(L2);

    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    printList(L3);

    list<int>L4;
    L4.assign(10,100);
    printList(L4);
}
void test02(){
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    
    list<int>L2;
    L2.assign(10,100);
    cout<<"交换前："<<endl;
    printList(L1);
    printList(L2);
    L1.swap(L2);
    cout<<"交换后："<<endl;
    printList(L1);
    printList(L2);
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
```



####	3.7.4 list大小操作

![image-20220429100729951](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220429100729951.png)

####	3.7.5 list插入和删除



![image-20220429100821940](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220429100821940.png)



```c++
#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>L){
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    list<int>L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);
    printList(L);
    L.pop_back();//尾删
    printList(L);
    L.pop_front();//头删
    printList(L);
    L.insert(L.begin(),1000);//在某一位置插入
    printList(L);
    L.erase(L.begin());//删除
    printList(L);
    L.push_back(10000);
    printList(L);
    L.remove(10000);//移除
    printList(L);
    L.clear();//清空
    printList(L);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	3.7.6 list 数据存取

函数原型：

- front();//返回第一个元素
- back();//返回最后一个元素



####	3.7.7 list反转和排序

- reverse();//反转链表
- sort();//链表排序



####	3.7.8 排序案例

案例描述：将person自定义数据类型进行排序，person中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序



```c++
#include<iostream>
using namespace std;
#include<list>
#include<string>

class Person{
public:
    Person(string name,int age,int height){
        this->m_Name=name;
        this->m_Age=age;
        this->m_Height=height;
    }
    string m_Name;
    int m_Age;
    int m_Height;
};

void printList(const list<Person>L){
    for(list<Person>::const_iterator it=L.begin();it!=L.end();it++){
        cout<<"姓名："<<(*it).m_Name;
        cout<<" 年龄："<<(*it).m_Age;
        cout<<" 身高："<<(*it).m_Height<<endl;
    }
}
bool comparePerson(Person &p1,Person &p2){
    if(p1.m_Age==p2.m_Age){
        return p1.m_Height>p2.m_Height;
    }
    return p1.m_Age<p2.m_Age;
}
void test01(){
    Person p1("1",2,2);
    Person p2("2",1,3);
    Person p3("3",1,5);
    list<Person>L;
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    cout<<"----------"<<"排序前："<<"----------"<<endl;
    printList(L);
    L.sort(comparePerson);
    cout<<"----------"<<"排序后："<<"----------"<<endl;
    printList(L);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

总结：

- 对于自定义数据类型，必须指定排序规则，否则编译器不知道如何排序
- 高级排序只是在排序规则上在进行一次逻辑规则制定，并不复杂





###	3.8 set/multiset容器

####	3.8.1 set基本概念

简介：所有的元素会在插入时自动被排序

本质： set/multiset属于关联式容器，底层结构是用二叉树实现

set和multiset区别：

- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素



####	3.8.2 set构造和赋值



![image-20220429205432532](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220429205432532.png)



```c++
#include<iostream>
using namespace std;
#include<set>

void printSet(set<int>s){
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    set<int>s1;
    s1.insert(10);//只有这一种方式
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    printSet(s1);//所有元素在被插入的时候会自动排序
    //拷贝构造
    set<int>s2(s1);
    printSet(s2);
    set<int>s3;
    s3=s2;
    printSet(s3);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	3.8.3 set大小和交换

函数原型：

- size();//返回容器中元素的数目
- empty();//判断容器是否为空
- swap(st);//交换两个集合容器



####	3.8.4 set插入和删除

函数原型：

![image-20220429210352971](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220429210352971.png)



####	3.8.5 set查找和统计

函数原型：

- find(key);//查找key是否存在，若存在返回该键的元素的迭代器；若不存在，返回set.end()
- count(key);//统计key元素的个数



####	3.8.6 set和multiset区别

- set不可以重复插入数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据



####	3.8.7 pair对组创建

功能描述：成对出现的数据，利用对组可以返回两个数据

创建方式：

- pair<type,type> p (value1,value2);
- pair<type,type> p =make_pair(value1,value2);



####	3.8.8 set容器排序

学习目标：set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：利用仿函数，可以改变排序规则。

```c++
#include<iostream>
using namespace std;
#include<set>
class MyCompare{
public:
    bool operator()(int v1,int v2){
        return v1>v2;
    }
};
void test01(){
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);
    for(set<int>::iterator it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //指定排序规则为从大到小
    set<int,MyCompare>s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);
    for(set<int,MyCompare>::iterator it=s2.begin();it!=s2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

###	3.9 map/nultimap容器

####	3.9.1 map基本概念

简介：

- map中所有元素都是pair
- pair的第一个元素是键值（key），起到索引的作用，第二个元素为value（实值）
- 所有元素都会根据元素的键值自动排序

本质：

- map/multimap属于关联式容器，底层结构是用二叉树实现的

优点：

- 可以根据key值快速的找到value值

map和multimap的区别：

- map不允许容器有重复的key值元素
- multimap允许容器中有重复的key值元素



#### 3.9.2 map构造和赋值

```c++
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<"key="<<(*it).first<<" value="<<it->second<<endl;
    }
    cout<<endl;
}
void test01(){
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));//按照key进行排序
    printMap(m);
    map<int,int>m2(m);
    printMap(m2);
    map<int,int> m3;
    m3=m2;
    printMap(m3);
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	3.9.3 map大小和交换

- size();//返回容器中元素的数目
- empty();//判断容器是否为空
- swap();//交换两个集合容器



####	3.9.4 map插入和删除

![image-20220506214234505](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220506214234505.png)

####	3.9.5 map查找和统计



![image-20220506214433675](C:\Users\11321\AppData\Roaming\Typora\typora-user-images\image-20220506214433675.png)



###	3.10 员工分组

####	3.10.1 案例描述

- 公司招聘10名员工（ABCDEFGHI），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有：姓名 工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入 key（部门编号）value（员工）
- 分部门显示员工信息



####	3.10.2 实现步骤

1. 创建10名员工，放到vector中
2. 遍历vector容器，取出每个员工，进行随机分组
3. 分组后，将员工部门编号作为key，具体员工为value，放入到multimap容器中
4. 分部门显示员工信息



```c++
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2
class Worker{
public:
    string m_Name;
    int m_Salary;
};
void createWorker(vector<Worker>&v){
    string nameSeed="ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        Worker worker;
        worker.m_Name="员工";
        worker.m_Name+=nameSeed[i];
        worker.m_Salary=rand()%10000+10000;
        v.push_back(worker);
    }
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&m){
    for(vector<Worker>::iterator it=v.begin();it!=v.end();it++){
        int deptId=rand()%3;
        m.insert(make_pair(deptId,*it));
    }
}
void showWorkerByGroup(multimap<int,Worker>m){
    cout<<"策划部门："<<endl;
    multimap<int,Worker>::iterator pos=m.find(CEHUA);
    int count=m.count(CEHUA);
    int index=0;
    for(;pos!=m.end()&&index<count;pos++,index++){
        cout<<"姓名："<<pos->second.m_Name<<" 工资："<<pos->second.m_Salary<<endl;
    }
    cout<<"---------------------"<<endl;
    cout<<"美术部门："<<endl;
    pos=m.find(MEISHU);
    count=m.count(MEISHU);
    index=0;
    for(;pos!=m.end()&&index<count;pos++,index++){
        cout<<"姓名："<<pos->second.m_Name<<" 工资："<<pos->second.m_Salary<<endl;
    }
    cout<<"---------------------"<<endl;
    cout<<"研发部门："<<endl;
    pos=m.find(YANFA);
    count=m.count(YANFA);
    index=0;
    for(;pos!=m.end()&&index<count;pos++,index++){
        cout<<"姓名："<<pos->second.m_Name<<" 工资："<<pos->second.m_Salary<<endl;
    }
}
int main(){
    srand((unsigned int)time(NULL));
    //1.创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);
    //2.员工分组
    multimap<int,Worker>mWorker;
    setGroup(vWorker,mWorker);
    //3.分组显示员工
    showWorkerByGroup(mWorker);
    system("pause");
    return 0;
}
```

##	4 STL函数对象

###	4.1 函数对象

####	4.1.1 函数对象概念

概念：

- 重载函数调用操作符的类，其对象常称之为函数对象
- 函数对象使用重载的（）时，行为类似函数调用，也叫仿函数

本质：

函数对象（仿函数）时一个类，不是一个函数



####	4.1.2 函数对象使用

特点：

- 函数对象在使用时，可以像普通函数那样调用可以有参数，可以有返回值
- 函数对象超过普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递

```c++
#include<iostream>
using namespace std;
#include<string>

class MyAdd{
public:
    int operator()(int v1,int v2){
        return v1+v2;
    }
};
void test01(){
    MyAdd myadd;
    cout<<myadd(10,10)<<endl;
}
class MyPrint{
public:
    MyPrint(){
        this->count=0;
    }
    void operator()(string test){
        cout<<test<<endl;
        this->count++;
    }
    int count;
};
void test02(){
    MyPrint myprint;
    myprint("hello world!");
    cout<<"myPrint调用的次数为："<<myprint.count<<endl;
}
void doPrint(MyPrint &mp,string test){
    mp(test);
}
void test03(){
    MyPrint myprint;
    doPrint(myprint,"hello c++");
}
int main(){
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}
```

### 4.2 谓词

####	4.2.1 谓词概念

概念：

- 返回bool类型的仿函数称为谓词
- 如果operator（）接受一个参数，那么叫做一元谓词
- 如果接受两个参数，叫做二元谓词



####	4.2.2 一元谓词

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    //GreaterFive()匿名函数对象
    vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());
    if(it==v.end()){
        cout<<"未找到"<<endl;
    }else{
        cout<<"找到了大于5的数字为： "<<*it<<endl;
    }
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	4.2.3 二元谓词

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class MyCompare{
public:
    bool operator()(int val1,int val2){
        return val1>val2;
    }
};
void test01(){
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //改变算法策略
    sort(v.begin(),v.end(),MyCompare());
    cout<<"------------------"<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

###	4.3 内建函数对象

####	4.3.1 内建函数对象意义

STL内建了一些函数对象，使用内建函数对象需要引入头文件#include<functional>

####	4.3.2 算术仿函数

```c++
#include<iostream>
using namespace std;
#include<functional>

//negate 一元仿函数 取反
void test01(){
    negate<int>n;
    cout<<n(50)<<endl;
}
//plus 二元仿函数 加法
void test02(){
    plus<int>p;
    cout<<p(10,20)<<endl;
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
```

####	4.3.3关系仿函数

实现关系对比

```c++
#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>

class MyCompare{
public:
    bool operator()(int val1,int val2){
        return val1>val2;
    }
};
//大于 greater
void test01(){
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // sort(v.begin(),v.end(),MyCompare());
    // cout<<"-----------"<<endl;
    // for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    sort(v.begin(),v.end(),greater<int>());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
} 
```

####	4.3.4 逻辑仿函数

实现逻辑运算

```c++
#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>

//逻辑非 logical_not
void test01(){
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for(vector<bool>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"-----------"<<endl;
    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

##	5 STL - 常用算法

概述：

- 算法主要是由头文件<algorithm>、<funtional>、<numeric>组成
- <algorithm>是所有STL头文件中最大的一个，设计到比较、查找、交换、遍历操作、复制、修改等
- <numeric>体积很小，只包括几个在序列上卖弄进行简单数学运算的模板函数
- <funtional>定义了一些模板类，用以声明函数对象



###	5.1 常用遍历算法

####	5.1.1 for_each

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void print01(int val){
    cout<<val<<" ";
}
class print02{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
```

####	5.1.2 transform

搬运到另一个容器中

```c++
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Transform{
public:
    int operator()(int v){
        return v;
    }
};
class MyPrint{
public:
    void operator()(int v){
        cout<<v<<" ";
    }
};
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>vTarget;
    vTarget.resize(v.size());
    transform(v.begin(),v.end(),vTarget.begin(),Transform());
    for_each(vTarget.begin(),vTarget.end(),MyPrint());
    cout<<endl;

}
int main(){
    test01();
    system("pause");
    return 0;
}
```

###	5.2 常用查找算法

####	5.2.1 find

查找制定元素找到返回制定元素的迭代器，找不到返回结束迭代器end()

####	5.2.2 find_if

按条件查找元素

find_if(iterator beg, iterator end,_Pred);

