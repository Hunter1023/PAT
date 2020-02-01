## PAT(Programming Ability Test)  

## 目录
1. [编程语言的选择](https://github.com/Hunter1023/PAT-Practice#编程语言的选择)
2. [如何高效地做题](https://github.com/Hunter1023/PAT-Practice#如何高效地做题)
3. [解题干货](/tips.md)
4. [乙级题解](https://github.com/Hunter1023/PAT-Practice#乙级题解)
---

## 编程语言的选择

​        考题会限定程序的运行时间上限，因此需要**选择尽可能快的编程语言**。由于Java的执行比较慢，用来做OJ题容易遇到超时问题，因此常用 C语言 或 C++，**C语言的输入输出语句比C++的要快很多**，**C++中有一些特性和功能非常好用**（例如 变量可以随时定义、拥有标准模板库STL等）。

​        由于**C++语法向下兼容C语言**，因此一般**选择C++做题**，**主体上使用C语言的语法，混用部分C++的语法**。

##### 使用Java写OJ题的劣势：

PAT的负责人陈越老师在知乎上有这样一个对PAT考试的回答：

>Java在编译运行的时间上肯定比C慢了很多。但是只要不用Scanner读大规模的数据，应该还好啦。因为题目的时间上限是用C标程的时间放大3~5倍，再另加100毫秒给Java启动，这样来定的。

然而真题中就是有大规模数据的案例，那么，Java中可以采用什么方式代替Scanner读取控制台的输入？  
方法之一是采用`BufferedReader`，**亲测部分试题有效**。  

>参考网站：[Scanner究竟有多慢](https://www.cpe.ku.ac.th/~jim/java-io.html)

---

## 如何高效地做题

1. 一般来说，可以**按照算法专题进行集中性的题目训练**，这样可以一次性地对某个算法进行较为深入且细致的训练；
2. 如果在做一道题时暂时没有想法，可以先跳过
3. 做题时可以适当**总结相似题目的解题方法**

而随意乱做或是**按题号从小到大刷题不是一个好选择**，无法形成完整的知识体系。

---

## 乙级题解

![AC](https://i.loli.net/2020/02/01/ThqsFQmxu5dV4RG.png)



| 标号                              | 标题                     | 答案                                                         | 解题关键                                                     |
| --------------------------------- | ------------------------ | :----------------------------------------------------------- | ------------------------------------------------------------ |
| [1001](/BasicLevel/真题/1001.md)  | 害死人不偿命的(3n+1)猜想 | - [C](/BasicLevel/C/1001.c)<br />- [C++](/BasicLevel/C++/1001.cpp)<br />- [Java](/BasicLevel/Java/1001.java) | \                                                            |
| [1002](/BasicLevel/真题/1002.md)  | 写出这个数               | - [C](/BasicLevel/C/1002.c)<br />- [Java](/BasicLevel/Java/1002.java) | 各位数字之和的范围；<br />**正序输出**每一位数字的拼音       |
| [1003](/BasicLevel/真题/1003.md)  | 我要通过！               | - [C](/BasicLevel/C/1003.c)<br />- [Java](/BasicLevel/Java/1003.java) | 正确归纳答案正确的条件                                       |
| [1004](/BasicLevel/真题/1004.md)  | 成绩排名                 | - [C](/BasicLevel/C/1004.c)<br />- [Java](/BasicLevel/Java/1004.java) | \                                                            |
| [1005](/BasicLevel/真题/1005.md)  | 继续(3n+1)猜想           | - [C](/BasicLevel/C/1005.c)<br />- [Java](/BasicLevel/Java/1005.java) | 筛选关键数字的方式                                           |
| [1006](/BasicLevel/真题/1006.md)  | 换个格式输出整数         | - [C](/BasicLevel/C/1006.c)<br />- [Java](/BasicLevel/Java/1006.java) | \                                                            |
| [1007](/BasicLevel/真题/1007.md)  | 素数对猜想               | - [C](/BasicLevel/C/1007.c)<br />- [Java](/BasicLevel/Java/1007.java) | 素数对的筛选方式；<br />素数的判断方法                       |
| [1008](/BasicLevel/真题/1008.md)  | 数组元素循环右移问题     | - [C](/BasicLevel/C/1008.c)<br />- [Java](/BasicLevel/Java/1008.java) | **元素循环右移的高效移动方式**                               |
| [1009](/BasicLevel/真题/1009.md)  | 说反话                   | - [C](/BasicLevel/C/1009.c)<br />- [Java](/BasicLevel/Java/1009.java) | **句子颠倒，单词本身不颠倒**                                 |
| [1010](/BasicLevel/真题/1010.md)  | 一元多项式求导           | - [C](/BasicLevel/C/1010.c)<br />- [Java](/BasicLevel/Java/1010.java) | 指数为0的项的处理                                            |
| [1011](/BasicLevel/真题/1011.md)  | A+B和C                   | - [C](/BasicLevel/C/1011.c)<br />- [Java](/BasicLevel/Java/1011.java) | 输入的数值范围                                               |
| [1012](/BasicLevel/真题/1012.md)  | 数字分类                 | - [C](/BasicLevel/C/1012.c)<br />- [Java](/BasicLevel/Java/1012.java) | 有条不紊地整理                                               |
| [1013](/BasicLevel/真题/1013.md)  | 数素数                   | - [C](/BasicLevel/C/1013.c)<br />- [Java](/BasicLevel/Java/1013.java) | \                                                            |
| [1014](/BasicLevel/真题/1014.md)  | 福尔摩斯的约会           | - [C](/BasicLevel/C/1014.c)<br />- [Java](/BasicLevel/Java/1014.java) | **正确归纳**解码方式                                         |
| [1015](/BasicLevel/真题/1015.md)  | 德才论                   | - [C](/BasicLevel/C/1015.c)                                  | 成绩的分类                                                   |
| [1016](/BasicLevel/真题/1016.md)  | 部分A+B                  | - [C](/BasicLevel/C/1016.c)                                  | 输入数字的取值范围                                           |
| [1017](/BasicLevel/真题/1017.md)  | A除以B                   | - [C](/BasicLevel/C/1017.c)                                  | 将除法的特点转换为计算机语言                                 |
| [1018](/BasicLevel/真题/1018.md)  | 锤子剪刀布               | - [C](/BasicLevel/C/1018.c)                                  | `%c`读取字符要注意回车的处理                                 |
| [1019](/BasicLevel/真题/1019.md)  | 数字黑洞                 | - [C](/BasicLevel/C/1019.c)                                  | 若输入数字为6174                                             |
| [1020](/BasicLevel/真题/1020.md)  | 月饼                     | - [C](/BasicLevel/C/1020.c)                                  | 若全部库存仍无法满足需求                                     |
| [1021](/BasicLevel/真题/1021.md)  | 个位数统计               | - [C](/BasicLevel/C/1021.c)                                  | \                                                            |
| [1022](/BasicLevel/真题/1022.md)  | D进制的A+B               | - [C](/BasicLevel/C/1022.c)                                  | A + B = 0                                                    |
| [1023](/BasicLevel/真题/1023.md)  | 组个最小数               | - [C](/BasicLevel/C/1023.c)                                  | \                                                            |
| [1024](/BasicLevel/真题/1024.md)  | 科学计数法               | - [C](/BasicLevel/C/1024.c)                                  | **小数点的输出**                                             |
| [1025](/BasicLevel/真题/1025.md)  | 反转链表                 | - [C](/BasicLevel/C/1025.c)                                  | **可能存在无效节点**                                         |
| [1026](/BasicLevel/真题/1026.md)  | 程序运行时间             | - [C](/BasicLevel/C/1026.c)                                  | 四舍五入                                                     |
| [1027](/BasicLevel/真题/1027.md)  | 打印沙漏                 | - [C](/BasicLevel/C/1027.c)                                  | 沙漏高度和符号数量的关系                                     |
| [1028](/BasicLevel/真题/1028.md)  | 人口普查                 | - [C](/BasicLevel/C/1028.c)                                  | **不合理年龄的判断方式**                                     |
| [1029](/BasicLevel/真题/1029.md)  | 旧键盘                   | - [C](/BasicLevel/C/1029.c)                                  | 坏键的判断方式                                               |
| [1030](/BasicLevel/真题/1030.md)  | 完美数列                 | - [C](/BasicLevel/C/1030.c)                                  | 高效地判断完美数列                                           |
| [1031](/BasicLevel/真题/1031.md)  | 查验身份证               | - [C](/BasicLevel/C/1031.c)                                  | \                                                            |
| [1032](/BasicLevel/真题/1032.md)  | 挖掘机技术哪家强         | - [C](/BasicLevel/C/1032.c)                                  | 统计各学校总分的方式                                         |
| [1033](/BasicLevel/真题/1033.md)  | 旧键盘打字               | - [C](/BasicLevel/C/1033.c)                                  | 运行超时                                                     |
| [1034](/BasicLevel/真题/1034.md)  | 有理数四则运算           | - [C](/BasicLevel/C/1034.c)                                  | **合理解耦**                                                 |
| [1035](/BasicLevel/真题/1035.md)  | 插入与归并               | - [C](/BasicLevel/C/1035.c)                                  | ![Basic1035](/images/Basic1035.jpg)                          |
| [1036](/BasicLevel/真题/1036.md)  | 跟奥巴马一起编程         | - [C](/BasicLevel/C/1036.c)                                  | 四舍五入                                                     |
| [1037](/BasicLevel/真题/1037.md)  | 在霍格沃茨找零钱         | - [C](/BasicLevel/C/1037.c)                                  | 进制换算                                                     |
| [1038](/BasicLevel/真题/1038.md)  | 统计同成绩学生           | - [C](/BasicLevel/C/1038.c)                                  | 找准解题角度                                                 |
| [1039](/BasicLevel/真题/1039.md)  | 到底买不买               | - [C](/BasicLevel/C/1039.c)                                  | **对珠子的判断方式**                                         |
| [1040](/BasicLevel/真题/1040.md)  | 有几个PAT                | - [C](/BasicLevel/C/1040.c)                                  | **A前有P，后有T才能形成PAT**                                 |
| [1041](/BasicLevel/真题/1041.md)  | 考试座位号               | - [C](/BasicLevel/C/1041.c)                                  | \                                                            |
| [1042](/BasicLevel/真题/1042.md)  | 字符统计                 | - [C](/BasicLevel/C/1042.c)                                  | 确认好筛选条件                                               |
| [1043](/BasicLevel/真题/1043.md)  | 输出PATest               | - [C](/BasicLevel/C/1043.c)                                  | \                                                            |
| [1044](/BasicLevel/真题/1044.md)  | 火星数字                 | - [C](/BasicLevel/C/1044.c)                                  | 火星文表达的特点                                             |
| [1045](/BasicLevel/真题/1045.md)  | 快速排序                 | - [C](/BasicLevel/C/1045.c)                                  | ![Basic1045](/images/Basic1045.jpg)                          |
| [1046](/BasicLevel/真题/1046.md)  | 划拳                     | - [C](/BasicLevel/C/1046.c)                                  | \                                                            |
| [1047](/BasicLevel/真题/1047.md)  | 编程团体赛               | - [C](/BasicLevel/C/1047.c)                                  | \                                                            |
| [1048](/BasicLevel/真题/1048.md)  | 数字加密                 | - [C](/BasicLevel/C/1048.c)                                  | **高位补0使数字位数一致**                                    |
| [1049](/BasicLevel/真题/1049.md)  | 数列的片段和             | - [C](/BasicLevel/C/1049.c)                                  | **整型大小溢出**                                             |
| [1050](/BasicLevel/真题/1050.md)  | 螺旋矩阵                 | - [C](/BasicLevel/C/1050.c)                                  | ![Basic1050](/images/Basic1050.jpg)                          |
| [1051](/BasicLevel/真题/1051.md)  | 复数乘法                 | - [C](/BasicLevel/C/1051.c)                                  | 格式化输出的保留小数                                         |
| [1052](/BasicLevel/真题/1052.md)  | 卖个萌                   | - [C](/BasicLevel/C/1052.c)                                  | **正则表达式读取字符**                                       |
| [1053](/BasicLevel/真题/1053.md)  | 住房空置率               | - [C](/BasicLevel/C/1053.c)                                  | 注意整数和浮点数的转换                                       |
| [1054](/BasicLevel/真题/1054.md)  | 求平均值                 | - [C](/BasicLevel/C/1054.c)                                  | ![Basic1054](/images/Basic1054.jpg)                          |
| [1055](/BasicLevel/真题/1055.md)  | 集体照                   | - [C](/BasicLevel/C/1055.c)                                  | ![Basic1055](/images/Basic1055.jpg)                          |
| [1056](/BasicLevel/真题/1056.md)  | 组合数的和               | - [C](/BasicLevel/C/1056.c)                                  | 时间复杂度的优化                                             |
| [1057](/BasicLevel/真题/1057.md)  | 数零壹                   | - [C](/BasicLevel/C/1057.c)                                  | \                                                            |
| [1058](/BasicLevel/真题/1058.md)  | 选择题                   | - [C](/BasicLevel/C/1058.c)                                  | **输入的读取**                                               |
| [1059](/BasicLevel/真题/1059.md)  | C语言竞赛                | - [C](/BasicLevel/C/1059.c)                                  | \                                                            |
| [1060](/BasicLevel/真题/1060.md)  | 爱丁顿数                 | - [C](/BasicLevel/C/1060.c)                                  | **简化爱丁顿数的获取**                                       |
| [1061](/BasicLevel/真题/1061.md)  | 判断题                   | - [C](/BasicLevel/C/1061.c)                                  | \                                                            |
| [1062](/BasicLevel/真题/1062.md)  | 最简分数                 | - [C](/BasicLevel/C/1062.c)                                  | 分数范围的确定                                               |
| [1063](/BasicLevel/真题/1063.md)  | 计算谱半径               | - [C](/BasicLevel/C/1063.c)                                  | \                                                            |
| [1064](/BasicLevel/真题/1064.md)  | 朋友数                   | - [C](/BasicLevel/C/1064.c)                                  | 构建高效的数组                                               |
| [1065](/BasicLevel/真题/1065.md)  | 单身狗                   | - [C](/BasicLevel/C/1065.c)                                  | ![Basic1065](/images/Basic1065.jpg)                          |
| [1066](/BasicLevel/真题/1066.md)  | 图像过滤                 | - [C](/BasicLevel/C/1066.c)                                  | \                                                            |
| [1067](/BasicLevel/真题/1067.md)  | 试密码                   | - [C](/BasicLevel/C/1067.c)                                  | **输入的读取**                                               |
| [1068](/BasicLevel/真题/1068.md)  | 万绿丛中一点红           | - [C](/BasicLevel/C/1068.c)                                  | ![Basic1068](/images/Basic1068.jpg)                          |
| [1069](/BasicLevel/真题/1069.md)  | 微博转发抽奖             | - [C](/BasicLevel/C/1069.c)                                  | \                                                            |
| [1070](/BasicLevel/真题/1070.md)  | 结绳                     | - [C](/BasicLevel/C/1070.c)                                  | 向下取整                                                     |
| [1071](/BasicLevel/真题/10071.md) | 小赌怡情                 | - [C](/BasicLevel/C/1071.c)                                  | 输出的句子间隔                                               |
| [1072](/BasicLevel/真题/1072.md)  | 开学寄语                 | - [C](/BasicLevel/C/1072.c)                                  | \                                                            |
| [1073](/BasicLevel/真题/1073.md)  | 多选题常见计分法         | - [C](/BasicLevel/C/1073.c)                                  | **如何将漏选选项作为错误处理**                               |
| [1074](/BasicLevel/真题/1074.md)  | 宇宙无敌加法器           | - [C](/BasicLevel/C/1074.c)                                  | **不同位数数字的相加**                                       |
| [1075](/BasicLevel/真题/1075.md)  | 链表元素分类             | - [C](/BasicLevel/C/1075.c)                                  | ![Basic1075](/images/Basic1075.jpg)                          |
| [1076](/BasicLevel/真题/1076.md)  | Wifi密码                 | - [C](/BasicLevel/C/1076.c)                                  | 选项输入顺序随机                                             |
| [1077](/BasicLevel/真题/1077.md)  | 互评成绩计算             | - [C](/BasicLevel/C/1077.c)                                  | 去掉无效评分、最高分和最低分                                 |
| [1078](/BasicLevel/真题/1078.md)  | 字符串压缩与解压         | - [C](/BasicLevel/C/1078.c)                                  | \                                                            |
| [1079](/BasicLevel/真题/1079.md)  | 延迟的回文数             | - [C](/BasicLevel/C/1079.c)                                  | **回文数的本质**                                             |
| [1080](/BasicLevel/真题/1080.md)  | MOOC期终成绩             | - [C](/BasicLevel/C/1080.c)                                  | **时间复杂度**                                               |
| [1081](/BasicLevel/真题/1081.md)  | 检查密码                 | - [C](/BasicLevel/C/1081.c)                                  | 输入内容可能含有空格                                         |
| [1082](/BasicLevel/真题/1082.md)  | 射击比赛                 | - [C](/BasicLevel/C/1082.c)                                  | \                                                            |
| [1083](/BasicLevel/真题/1083.md)  | 是否存在相等的差         | - [C](/BasicLevel/C/1083.c)                                  | \                                                            |
| [1084](/BasicLevel/真题/1084.md)  | 外观数列                 | - [C](/BasicLevel/C/1084.c)                                  | 数组大小的定义                                               |
| [1085](/BasicLevel/真题/1085.md)  | PAT单位排行              | - [C](/BasicLevel/C/1085.c)                                  | \                                                            |
| 1086                              | 就不告诉你               | - [C](/BasicLevel/C/1086.c)                                  | 倒着输出的**第一个数必须非零**                               |
| 1087                              | 有多少不同的值           | - [C](/BasicLevel/C/1087.c)                                  | 算式 ⌊n/2⌋+⌊n/3⌋+⌊n/5⌋**单调不减**                           |
| 1088                              | 三人行                   | - [C](/BasicLevel/C/1088.c)                                  | 丙的成绩允许为小数；<br />绝对值函数：int abs(int i)         |
| 1089                              | 狼人杀-简单版            | - [C](/BasicLevel/C/1089.c)                                  | 通过枚举法**假设狼人**<br />需要**至少能记录3个说谎者**的数组，以排除错误假设 |
| 1090                              | 危险品装箱               | - [C](/BasicLevel/C/1090.c)                                  | **遍历不相容物品清单**，查找货品清单中是否存在不相容物品     |
| 1091                              | N-自守数                 | - [C](/BasicLevel/C/1091.c)                                  | 确定K的位数                                                  |
| 1092                              | 最好吃的月饼             | - [C](/BasicLevel/C/1092.c)                                  |                                                              |
| 1093                              | 字符串A+B                | - [C](/BasicLevel/C/1093.c)                                  | 字符转换为对应码值<br />getchar() / putchar 输入输出字符     |
| 1094                              | 谷歌的招聘               | - [C](/BasicLevel/C/1094.c)                                  | 复制字符串前n位函数 strncpy<br />字符串转为int整数函数 atoi(str)<br />存储K位数的字符串必须初始化 |
| 1095                              | 解码PAT准考证            | - [C](/BasicLevel/C/1095.c)                                  | **从字符串读取格式化输入 sscanf**<br />类型3输出的**简便**方法 |
