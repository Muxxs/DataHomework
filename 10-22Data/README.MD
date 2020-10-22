
## 实现循环队列基本操作：
- 初始化队列：Status InitQueue(SqQueue &Q)
- 建立顺序队列：Status CreateQueue(SqQueue &Q)
- 入队：Status EnQueue(SqQueue &Q,QElemType e)
- 出队：Status	DeQueue(SqQueue &Q,QElemType &e)
- 判断队列是否为空：Status QueueEmpty(SqQueue Q)
- 获取队头元素：Status GetHead(SqQueue Q,SElemType &e)
- 获取队列长度：Status QueueLength(SqQueue Q)
- 清空队列：Status ClearQueue(SqQueue &Q)
- 遍历队列：Status QueueTraverse(SqQueue Q)
- 销毁队列：Status DestroyQueue(SqQueue &Q)

## 主函数实现如下功能：
- 创建队列：2，34，56，54
- 入队：78，34，23
- 输出队列
- 两次出队
- 输出队列元素
- 输出队首元素
- 输出队列
