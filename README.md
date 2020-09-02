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

# 2020.8.31
## 18：57
**更新1.1:** 完成游戏界面
## 22：35
**更新1.2：** 
1. 完成图片加载  
2. 完成随机数构造
3. 完成随机选择红黑夜  

# 2020.9.1
## 16：53
**更新1.3：**
1. 完成投票功能  
2. 基本完成游戏流程  
~~已知bug：发言顺序错误~~
## 20：05
**更新：1.3.1**
1. 添加红黑夜图片
2. 修复bug  
3. ~~**出现bug：无法正常判定游戏结束**~~

# 2020.9.2
## 9：22
**更新：**  
完成除界面美化外其他功能  

