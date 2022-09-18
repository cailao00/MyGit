|这个作业属于哪个课程|[网络工程4班](https://bbs.csdn.net/forums/gdut-ryuezh)|
|---|---|
|这个作业要求在哪里|[个人项目，论文查重](https://bbs.csdn.net/topics/608092799)|
|本次作业的目标|完成个人编程|

@[toc](目录)
# 1.Github
[Github仓库地址](https://github.com/cailao00/MyGit)

# 2.PSP

|PSP2.1|Personal Software Process Stages|预估耗时(分钟)|实际耗时（分钟）|
|---|---|---|---|
|Planning|计划|120|120|
|Estimate|估计这个任务需要多少时间|120|120|
|Development|开发|360|300|
|Analysis|需求分析 (包括学习新技术)|300|300|
|Design Spec|生成设计文档|60|60|
|Design Review|设计复审|30|30|
|Coding Standard|代码规范 (为目前的开发制定合适的规范)|30|15|
|Design|具体设计|60|60|
|Coding|具体编码|300|300|
|Code Review|代码复审|30|10|
|Test|测试（自我测试，修改代码，提交修改）|30|30|
|Reporting|报告|60|40|
|Test Report|测试报告|30|30|
|Size Measurement|计算工作量|60|30|
|Postmortem & Process Improvement Plan|事后总结, 并提出过程改进计划|60|40|
|Total|合计|1650|1485|

# 3.计算模块接口的设计与实现过程
### 3.1流程图
![图片](https://img-blog.csdnimg.cn/d1cff529663c4679bf263f967bfd4c03.png#pic_center)
### 3.2算法实现
使用动态规划算法，求出最大公共子序列，根据子序列的字符数目，以判断是否查重。
举个例子，对字符串asdf 与 adfsd进行比较。
![在这里插入图片描述](https://img-blog.csdnimg.cn/b54adfd4c35841bc9cef15114d68b78b.png#pic_center)

使用二维数组（num[]MAXSIZE[MAXSIZE]）来存放对比后的状态值，横向代表i、纵向代表j，把每一个状态即dp[i][j] 看做 s1 … si 和 t1 … tj 的LCS(最大公共子序列)的长度，s1 … s(i+1) 和 t1 … t(j+1) 对应的公共子列长度可能是：
当s(i+1) == t(j+1),在 s1 … si 和 t1 … tj 的公共子列末尾追加上s(i+1) 。
否则则可能是 s1 … si 和 t1 … t(j+1) 的公共子列或者 s1 … s(i+1) 和 t1 … tj 的公共子列最大值。
对应的公式如下图：
![在这里插入图片描述](https://img-blog.csdnimg.cn/666c1e1b4ffe470ca19b54639203d378.png#pic_center)
# 4.计算模块接口部分的性能分析
覆盖率
![在这里插入图片描述](https://img-blog.csdnimg.cn/0f90e7418f974a97ad176b029b5a2914.png#pic_center)
CPU使用
![在这里插入图片描述](https://img-blog.csdnimg.cn/db938c06ee3e44c0b483ebec704b4c88.png#pic_center)

内存使用
![在这里插入图片描述](https://img-blog.csdnimg.cn/fefc697e347745d28072e75bddb7715f.png#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/55596d3914804b4baa533f2383ffeb3c.png#pic_center)
# 5.计算模块部分单元测试展示
测试1
![在这里插入图片描述](https://img-blog.csdnimg.cn/8b2cc9a77c24469890fcf28ac1a8f239.png#pic_center)
测试2
![在这里插入图片描述](https://img-blog.csdnimg.cn/8d1890264ba74de0afed5393151ed4ac.png#pic_center)
测试3
![在这里插入图片描述](https://img-blog.csdnimg.cn/d95efbb8454a48c5a30c77cd4c9090b8.png#pic_center)
测试4
![在这里插入图片描述](https://img-blog.csdnimg.cn/2218e9472fda412cae5653b9cdab4ca1.png#pic_center)
测试5
![在这里插入图片描述](https://img-blog.csdnimg.cn/f878e5b76b564806b0f55b4bed19d655.png#pic_center)
测试6
![在这里插入图片描述](https://img-blog.csdnimg.cn/2e9906c70e22476e926ea98c99402089.png#pic_center)
测试7
![在这里插入图片描述](https://img-blog.csdnimg.cn/a78eeb6e0d134db09cdc16d2e6f79c70.png#pic_center)
测试8
![在这里插入图片描述](https://img-blog.csdnimg.cn/a0342b2672b346efb9d00f46bc424b38.png#pic_center)
测试9
![在这里插入图片描述](https://img-blog.csdnimg.cn/8e6d7f33edd94b7389c7bf2b91b7966e.png#pic_center)
测试10
![在这里插入图片描述](https://img-blog.csdnimg.cn/c001df2dc33342a4b6e593159aca4884.png#pic_center)

# 6.异常模块
![在这里插入图片描述](https://img-blog.csdnimg.cn/e694c9b938304e7a85648c91e93db5ab.png#pic_center)








