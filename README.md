# RandomHeartMazeGenerator
随机心形迷宫生成器C++版

源码见main.cpp

直接运行main.exe可见效果

具体实现为使用程序生成心形的01阵列
使用数组存储这样的01阵列
然后对1为边界的区域使用迷宫生成算法
数组信息用int值进行存储

0为不需打印处 1为边界 2，3为交替可出现通道处  若初始定为2则3为被2与2之间激活的通道 反之亦然

4，5为已激活打印通道 6为已激活打印边界 7为已打印墙壁 8为入口与出口处 9为将要补足打印的墙壁（由于7的构造是根据4，5的四周来的，所以需要补足）

main函数是完整的程序，直接运行即可

heartGenerator函数是用于生成心形雏形
可以针对其做相应改动使其弧线更加平滑

再把相应的改动矩阵放入main函数中

或是直接改动main函数矩阵亦可
