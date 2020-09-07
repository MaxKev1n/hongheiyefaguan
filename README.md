# 红黑夜法官
C++个人课程设计
游戏规则：（基本要求）  
设定玩家人数：n  
若玩家人数为偶数，则红牌身份与黑牌身份各占一半；若为奇数，则红牌身份多1；  
使用指定范围的随机数构造方法，依次构造出1-n之间不重复的随机数，按照出现的随机数给该玩家发身份，该玩家的身份随机但总体满足规则2的人数分配。  
第一天，从1-n号玩家顺序发言，需要显示当前发言玩家位置。一轮发言后从1-n号顺序投票选举村长，得票最多的玩家当选村长，若总人数为偶数，村长拥有1.5票，总人数为奇数，村长拥有0.5票。（票数后续讲解作用）  
白天：村长决定从村长左边或者右边开始发言的顺序，发言顺序构成为k-1~ 村长k ~k+1的回环，（DOS下需要显示当前发言人的位置，若该发言人已经死亡要宣布，其余界面能够可视化存亡情况与发言位置。使用鼠标或者键盘切换下一个人发言。）最后从1-n号玩家进行匿名投票，得票最多的人被放逐出游戏，并且显示身份，若村长被放逐则要移交下一任村长。  
夜晚：随机进入红夜或黑夜，所有玩家可以自由睁眼。红夜时：睁眼的红牌为偶数则第二天村长拥有1票；黑夜时：睁眼的黑牌为偶数则第二天村长拥有1票  
游戏结束：所有的红牌或者所有的黑牌被放逐。  
（1）使用DOS实现可视化游戏进程；（到此60起评）  
（2）自动添加提示游戏进程：进入黑夜，进入红夜，天亮了，某某玩家被放逐身份为X等。  
（到此70起评）  
（3）MFC或QT界面友好可视化；（到此80起评）  
（4）优秀的数据结构能够使得判断身份与投票功能更加便捷，请大家根据不同的功能使用不同的数据结构存储游戏数据。（到此85起评）  
# Change Log
## V1.1(2020/08/31 18：57)
* 完成游戏界面
## V1.2(2020/08/31 22：35)
* 完成图片加载  
* 完成随机数构造
* 完成随机选择红黑夜  
## V1.3(2020/09/01 16：53)
* 完成投票功能 
* 基本完成游戏流程  
* ~~**已知bug：发言顺序错误**~~
## V1.3.1(2020/09/01 20：05)
* 添加红黑夜图片
* 修复bug  
* ~~**出现bug：无法正常判定游戏结束**~~
## V1.3.2(2020/09/02 09：22)
* 完成除界面美化外其他功能  
* 修复1.3.1bug
* ~~**出现bug：村长移交出现问题**~~
## V1.3.3(2020/09/02 18：29)
* 修复bug
* 界面更新  
* ~~**出现bug：末位玩家选为村长时闪退**~~
## V1.4.0(2020/09/03 09：30)
* 完成界面美化
* 修复bug
## V1.4.1(2020/09/03 12：12)
* 增加票数相同重新发言投票功能
## V2.0.0(2020/09/06 19：20)
* 无bug版
* 删除多余变量
## V2.0.1(2020/09/07 10：26)
* 实现文件输入输出
* 实现存档删除功能
* ~~**已知bug:使用读档时会导致闪退**~~
## V2.0.2(2020/09/07 11：45)
* **调试过程中，调试器提示:*****Signal name: SIGSEGV - Signal meaning: Segmentation Fault***  
* 经过调试，发现player类的QImage使用了指针，读档时并未new QImage导致指针丢失而发生错误
## VFinal Project(2020/09/07 11：52)
* **完成最终文件**
