#### 网络设备    

```
物理层: 转发器 集线器hub 中继器
数据链路层: 网桥 以太网交换机
网络层: 路由器 网关
```

#### 协议数据单元PDU --OSI参考模型对等层次之间传送的数据单位   P31

```
物理层的PDU是数据位（Bit)           通过物理媒介，双绞线、同轴电缆、光缆、无线信道
数据链路层的PDU是数据帧（Frame)     逻辑链路控制LLC 媒体接入控制MAC
网络层的PDU是数据报 Datagram  或IP数据包 分组 或包
传输层的PDU是数据段（Segment)  或报文段 TCP传输控制协议  UDP用户数据包协议的PDU为用户数据报
其他更高层次的PDU是数据（Data)
```

#### OSI七层协议体系结构图 TCP/IP体系结构

![image-20210618152327441](C:\Users\XiaoFang\AppData\Roaming\Typora\typora-user-images\image-20210618152327441.png)

#### TCP三次招手四次挥手

```
建立连接：SYN=1,seq=x ->   
					   <-SYN=1,ACK=1,seq=y,ack=x+1     
		ACK=1,seq=x+1,ack=y+1->
连接释放: FIN=1,seq=u->
					 <-ACK=1,seq=v,ack=u+1  
			      	 <-FIN=1,ACK=1,seq=w,ack=u+1
		 ACK=1,seq=u+1,ack=w+1->
```

#### 应用层协议    dns -> (Domain Name System)  考五个翻译  VPN(Virtual Private Network)

|    应用    |  名字转换   |       文件传送       |  路由选择协议   |       网络管理       | 远程文件服务器  |  IP电话  | 流式多媒体通信 |        多播        |       电子邮件       |    远程终端接入    |       万维网       |    文件传送     |
| :--------: | :---------: | :------------------: | :-------------: | :------------------: | :-------------: | :------: | :------------: | :----------------: | :------------------: | :----------------: | :----------------: | :-------------: |
| 应用层协议 | DNS域名系统 | TFTP简单文件传送协议 | RIP路由选择协议 | SNMP简单网络管理协议 | NFS网络文件系统 | 专用协议 |    专用协议    | IGMP网际组管理协议 | SMTP简单邮件传送协议 | TELNET远程终端协议 | HTTP超文本传送协议 | FTP文件传送协议 |
| 运输层协议 |     UDP     |         UDP          |       UDP       |         UDP          |       UDP       |   UDP    |      UDP       |        UDP         |         TCP          |        TCP         |        TCP         |       TCP       |



|  应用程序  | FTP  | TELNET | SMTP | DNS  | TFTP | HTTP | SNMP | SNMP(trap) | HTTPS |
| :--------: | :--: | :----: | :--: | :--: | :--: | :--: | :--: | :--------: | :---: |
| 熟知端口号 |  21  |   23   |  25  |  53  |  69  |  80  | 161  |    162     |  443  |

#### 网际校验和算法  IP数据包 首部校验和

```
TCP和UDP都使用16比特的Internet Checksum算法做差错控制，使用8比特的简化算法计算下面比特串的校验码。网际校验和算法
反码算术运算求和->取反码->首部校验和
```

```
二进制，有符号数，首位为1的是负数，首位为0的是正数。(规定） 
无符号数没有正负之分，所以也没有首位的限制。(规定) 
```

![image-20210618154814863](C:\Users\XiaoFang\AppData\Roaming\Typora\typora-user-images\image-20210618154814863.png)

### RIP   距离向量算法

```
路由器收到相邻路由器（其地址为 X）的一个 RIP 报文：
(1) 先修改此 RIP 报文中的所有项目：把“下一跳”字段中的地址都改为 X，并把所有的“距离”字段的值加 1。
(2) 对修改后的 RIP 报文中的每一个项目，重复以下步骤：
     若项目中的目的网络不在路由表中，则把该项目加到路由表中。
         否则
             若下一跳字段给出的路由器地址是同样的，则把收到的项目替换原路由表中的项目。
                否则 
                    若收到项目中的距离小于路由表中的距离，则进行更新，
	     否则，什么也不做。
(3) 若 3 分钟还没有收到相邻路由器的更新路由表，则把此相邻路由器记为不可达路由器，即将距离置为 16（表示不可达）。
(4) 返回。
```

### 数据链路层    网络设配器

```
点对点信道PPP 一对一的点对点通信方式  只支持全双工链路
封装成帧 首尾SOH EOT
透明传输 字节填充
差错检测 CRC
```

```
广播信道 一对多的广播通信方式
CSMA/CD 半双工通信 争用期 碰撞窗口 截断二进制指数退避算法 k=Min[重传次数，10]  64字节的概念
共享通信媒体资源: 静态划分信道 频分复用FDM 时分复用TDM 波分复用WDM 码分复用CDM 码分多址CDMA 
				动态媒体接入控制（多点接入）: 随机接入（碰撞） 受控接入（轮询 探询
```

C/S客户服务器方式、P2P对等连接方式

### TCP的拥塞控制方法：慢开始、拥塞避免、快重传、快恢复

```
cwnd拥塞窗口 传输轮次 ssthresh慢开始门限 rwnd通知窗口 AIMD加法增大乘法减小  cwnd<=rwnd
拥塞的判断  重传定时器超时  收到三个重复的ACK
```

![image-20210618104930389](C:\Users\XiaoFang\AppData\Roaming\Typora\typora-user-images\image-20210618104930389.png)

![image-20210618105026088](C:\Users\XiaoFang\AppData\Roaming\Typora\typora-user-images\image-20210618105026088.png)

### 超时重传时间的选择 TCP采用了一种自适应算法

    RTO=RTTs+4xRTTD
    RTTs=(1-a)x(旧的RTTs)+ax(RTT样本)    a=0.125 RTT为报文段的往返时间，RTTs是加权往返时间
    RTTD=(1-b)x(旧的RTTD)+bx|RTTs-新的RTT样本|   b=0.25 RTTD是RTTs的偏差的加权平均值
    如果都当做是超时重传的确认，那么RTT会被计算小，如果都当做是发送端的确认，则RTT会偏大
    在计算加权平均RTTs时，只要报文段重传了，就不采用其往返时间样本，但是这样超时重传时间就不会被更新，
    所以最终做法是新的重传时间设为旧的重传时间的二倍。

### CSMA/CD 载波监听多点接入/冲突检测

```
先听后发 边听边发 冲突停止 随机重发   半双工
曼彻斯特编码 1前高后低0前低后高 频带宽度比原始的基带信号增加了一倍
尽最大努力的交付 即不可靠的交付 CRC校验
电磁波在1km电缆的传播时延是5us
争用期(碰撞窗口) 
截断二进制指数退避算法 确认碰撞后重传的时机   64字节
k=Min[重传次数，10] 从[0,1,···,(2^k-1)]随机取一个数r,r*争用期
以太网在发送数据时，如果在争用期(共发送了64字节)没有发生碰撞，那么后续发送的数据就一定不会发生冲突
强化碰撞 32bit/48bit的人为干扰信号 帧间最小间隔96bit
在T时间内尝试重发，若继续碰撞，则在2T时间内尝试重发，直到发送成功或达到时间上限或重试次数。与固定时间随机重发相比，指数避
退能适应网络的拥堵程度，拥堵程度轻，重发时间段，拥堵程度重，重发时间长。而固定时间段内重发，其重发的时间期望是固定的。
```

### ARP

```
从网络层使用的 IP 地址，解析出在数据链路层使用的硬件地址。
每一个主机都设有一个 ARP 高速缓存 (ARP cache)，里面有所在的局域网上的各主机和路由器的 IP 地址到硬件地址的映射表。
< IP address；MAC address；TTL >
广播 单播相应分组
```

### 连续ARQ协议

```
累计确认 
Go-bakc-N 回退N
选择重传下 只需传丢失的数据
```

### 简单电子邮件协议SMTP (Simple Mail Transfer Protocol)

```
SMTP:用于用户代理向邮件服务器发送邮件或邮件服务器之间发送邮件
POP3/IMAP:用于用户代理从邮件服务器读取邮件
HTTP:用于用户代理向邮件服务器发送邮件件用户代理从邮件服务器读取邮件
```

### 远程终端协议TELNET

```
Telnet、HTTP和SMTP都是基于文本的应用层协议，在打开正确的端口后，如果文本消息符合HTTP标准或SMTP标准，就可以与网页服务器
或SMTP服务器进行通信，当然服务器返回的信息也是基于文本的。
```

### SSL

```
SSL协议位于 TCP/IP协议与各种应用层协议之间，为数据通讯提供安全支持。SSL协议可分为两层： SSL记录协议
（SSL Record Protocol）：它建立在可靠的传输协议（如TCP）之上，为高层协议提供数据封装、压缩、加密等基本功能的支持。 
SSL握手协议（SSL Handshake Protocol）：它建立在SSL记录协议之上，用于在实际的数据传输开始前，通讯双方进行身份认证、
协商加密算法、交换加密 密钥等。
```

### DNS Domain Name System

```
顶级域名:国家顶级域名nTLD 通用顶级域名gTLD 基础结构域名arpa->反向域名
我国的二级域名: 1.类别域名:ac com edu gov mil net org 2.行政区域名
解析:本地域名服务器 递归查询 根域名服务器 迭代查询
```

#### 以太网前同步码

```
插8字节+以太网MAC帧=物理层
前同步码 10交替码 作用是使接收端的适配器在接受MAC帧时能够迅速调整其时钟频率，使它和发送端的时钟同步 实现位同步
帧开始定界符 10101011 前六位和前同步码一样 最后两个连续的1使告诉接收端适配器，MAC帧的信息即将到来
```

#### Modbus

```
master/slave方式
主站用两种模式向从站发出Modbus请求，分别为单播模式（1-247地址）和广播模式   广播 必须使写命令 地址0
两种传输模式: RTU ASCII
RTU模式：每个8 Bit字节包含两个4 Bit的十六进制字符,其优点是在同样的波特率下,可比ASCII方式传送更多的数据,
但是每个信息必须以连续的数据流传输。
ASCII模式：信息中的每个8 Bit字节需2个ASCII字符,其优点是准许字符的传输间隔达到1 s而不产生错误;
01读线圈 03读保持寄存器 05写单个线圈 06写单个寄存器 15写多个线圈 16写多个寄存器
```

![image-20210618195704916](C:\Users\XiaoFang\AppData\Roaming\Typora\typora-user-images\image-20210618195704916.png)

​	![image-20210618195714460](C:\Users\XiaoFang\AppData\Roaming\Typora\typora-user-images\image-20210618195714460.png)

#### CAN

```
特点:多主方式工作，不分主从；采用非破坏性总线仲裁技术，按优先级发送
不归零编码，显性0，隐形1
```

## 毒性反转

```
当路由器从一个接口学习到一条去往某个网络时，它就会通过这个接口通告一条该网络不可达的路由（路由毒化）
即你已经告诉过我一次，我告诉你不用再告诉我了，避免环路
```

#### CRC

```
理论上可以证明循环冗余校验码的检错能力有以下特点：
(1)可检测出所有奇数位错。
(2)可检测出所有双比特的错。
(3)可检测出所有小于、等于校验位长度的突发错。
```

#### 速率

```
数据的传送速率，bit/s bps bit per second
kbps 10^3 Mbps 10^6 Gbps 10^9 
```



### 概念、小知识

```
各种网络在物理层互连时要求 数据传输率和链路协议都相同
在路由器互联的多个局域网中，各局域网之间 数据链路层协议和物理层协议都可以不相同
将IP地址转换为物理地址的协议是ARP。RARP
IP分组中采用了CRC校验算法
TCP报头信息和UDP报头信息中都包含下列哪项信息  源和目的
在连续ARQ (Automatic Repeat Request)协议中，当滑动窗口序号位数为n，则发送窗口最大尺寸为____。???
从源向目的传送数据段的过程中，TCP使用什么机制提供流量控制？	窗口大小
tcp与udp端口相互独立 封装时包头信息不一样 任意帧在网络上可以区分出是UDP包还是TCP包所以即使IP地址和端口相同不会导致冲突
在停止等待协议算法中，使用帧序号的目的是 处理重复帧
将流量控制用于TCP数据传输的原因是什么？防止传入数据耗尽接收方资源
Web浏览器向远端的侦听标准端口的Web服务器发出的请求中，源端口号无法确定
Web浏览器向远端的侦听标准端口的Web服务器发出的请求后，在服务器响应的TCP报头中，源端口号80
IP层配套使用的三个协议：地址解析协议ARP,网际控制报文协议ICMP,网际组管理协议IGMP
CAN总线使用的数据编码是不归零码
以太网发送的数据都使用曼彻斯特编码的信号
CAN的正常位时间由同步段、传播时间段、相位缓冲段1和相位缓冲段2这4个时间段组成，1次采样时其采样点位于。相位缓冲段1的终点
CAN总线帧结构：数据帧（Data Frame）远程帧（Remote Frame）出错帧（Error Fram）超载帧（Overload Frame）
以太网使用哪种媒体访问控制协议?CSMA/CD.载波侦听多路访问/冲突检测
网际控制报文协议ICMP的应用，ping，测试两台主机的连通性，应用层直接使用网络层ICMP，没有通过运输层的TCP或UDP
traceroute/tracert，跟踪分组路径
OSI参考模型将网络自下而上分为物理层、链路层;数据链路层、网络层;网际层、传输层;运输层、会话层、表示层和应用层。
计算机网络应用层两种体系结构分别是：客户服务器结构;CS;CS结构和点对点结构;P2P;P2P结构。
通信按照数据交换方式分类，可以分为____、____和____三种。电路交换 报文交换 分组交换
我们将发送端数字信号变换成____信号的过程称之为____，反之则称为解调。模拟 调制
计算机网络中常用的三种有线传输媒体是____、____、____。同轴电缆  双绞线   光纤
采用固定划分的主流的信道多路访问技术有____、____和____三种。频分复用;频分;FDMA 时分复用;时分;TDMA 码分复用;码分;CDMA
以太网端到端的往返延时2τ称为____，又称为碰撞窗口，因发送时间短于碰撞窗口，长度小于____字节的帧都是无效的。争用期 64
局域网常用的拓扑结构有____、____和____三种，传统的以太网就是采用其中的____结构。总线型;总线;总线形  星形;星型;环形;环型
星形;星型;环形;环型   总线型;总线;总线形
网络层向上只提供简单灵活的、无连接的、尽最大努力交付的数据报服务
TCP协议利用IP协议不可靠的数据报为__应用层__提供可靠的数据传输服务
数据交换方式使用存储转发技术的是。 分组交换  报文交换  虚电路交换  C、 电路交换 
ASK 调幅 FSK 调频 PSK调相 NRZ 不归零码
在常用的传输介质中，____的带宽最宽，信号传输衰减最小，抗干扰能力最强。光纤
通信系统必须具备的三个基本要素是____。信源、通信媒体、信宿
IEEE802.3——以太网        IEEE802.11——无线局域网
载波监听多路访问/冲突检测的原理可以概括为先听后发、边发边听、冲突停发、随机重发。
虚拟局域网只是局域网给用户提供的一种服务，并不是一种新型局域网
以太网交换机通过查看数据帧中的源地址来学习主机和端口的对应关系。 以太网交换机的自学习功能
```

**一个IPv4分组的分片中，MF位是0，HLEN是10，总长度为200，分片偏移值是300。请问该分片第一个字节和最后一个字节在原分组中的位置分别是：____和____。**第1空:2400 第2空:2559     DF=0可以分片，MF=1还有分片MF=0没有分片了。HLEN首部长度

**22、在路由器的转发表中，每一个CIDR地址都对应一个子网。（5.0）** 

正确答案： 错误    CIDR消除了传统的ABC地址以及划分子网的概念，把网络前缀都相同的连续的ip地址组成一个"CIDR地址块"。

**在计算机网络中，网桥____。**只隔离冲突，但不隔离广播 

**下列哪种措施无法提高工业以太网的实时性？**XXX增强信号强度 B、 采用全双工交换机 C、 减小网络负荷 D、 提高通信速率 

**44**  **、以下关于以太网协议争用期和指数退避算法的说明，错误的是____。（5.0）** 

A、 以太网距离最远的两个节点传输延迟的两倍为争用期 

B、 争用期内没有检测到碰撞，则帧的发送剩余时间内不会再发生碰撞 

C、 假设基本退避时间为τ，则第4次重传需要退避15τ的时间   

D、 即使多次重传都发生了碰撞，节点还是有可能不退避而立刻发送数据帧 

正确答案： C     15t这里是0-15随机抽一个值

双绞线传输介质是把两根导线绞在一起，这样可以减少____。信号之间的相互串扰

**22、下列关于曼彻斯特编码的叙述中，正确的是____。（5.0）** 

A、 为确保收发同步，将每个信号的起始边界作为时钟信号 

B、 将数字信号高电平与低电平不断交替的编码 

C、 每位中间不跳变时表示信号取值为1 

D、 码元1是在前一个间隔为高电平而后一个间隔为低电平，码元0正好相反 

正确答案： D 

**23、下列说法中不对的是____。（5.0）** 

A、 可以同时双向传输信号的通信方式称为全双工通信方式 

B、 在数字通信信道上，直接传送基带信号的方法称为频带传输 

C、 TCP/IP参考模型共分为四层，最底层为网络接口层，最高层是应用层

D、 类型不同的网络只要使用TCP/IP协议都可以互连成网

正确答案： B      直接传送基带信号的方法称为基带传输

**51、关于曼彻斯特编码的描述，正确的是____。（5.0）** 

A、 每个信号起始边界作为时钟信号有利于同步 

B、 将时钟与数据取值都包含在信号中 

C、 这种模拟信号的编码机制特别适合传输声音 

D、 每位的中间不跳变表示信号的取值为0 

正确答案： B 

**61、计算机在局域网络上的硬件地址也可以称为MAC地址，这是因为____。（5.0）** 

A、 硬件地址是传输数据时，在传输媒介访问控制层用到的地址









#### HTTP

```x
1xx 表示通知消息，如请求收到了或正在进行处理
2xx 表示成功，如接受了或知道了
3xx 表示重定向，如要完成请求还必须采取进一步的行动
4xx 表示客户的差错，如请求中有错误的语法或不能完成
5xx 表示服务器的差错，如服务器失效无法完成请求
HTTP/1.1 202 Accepted 接受
HTTP/1.1 400 Bad Request 错误的请求
HTTP/1.1 404 Not Found 找不到
```

#### NAT网络地址转换

```
```

#### 信道利用率

```
以太网:a = t/T0   Smax = T0/(T0+t) 30%重载
TCP:U = TD / (TD+RTT++TA)
```

**(4)****、给出网络中时延(latency)的组成部分，并简单解释其来源。** 

答案：发送时延，传播时延，处理时延，排队时延。 



```
```



```
URL Uniform Resource Locator
HTTPS HyperText Transfer Protocol over SecureSocket Layer
VPN Virtual Private Network
DNS Domain Name System
SMTP Simple Mail Transfer Protocol
UDP User Datagram Protocol
TCP Transmission Control Protocol
```



```
IP Internet Protocol 
ARP Address Resolution Protocol
RARP Reverse Address Resolution Protocol
ICMP Internet Control Message Protocol网际控制报文协议
NAT Network Address Translation
IGP Interior Gateway Protocol
EGP External Gateway Protocol
RIP Routing Information Protocol
DNS Domain Name System
WWW World Wide Web
VPN Virtual Private Network
HTTP HyperText Transfer Protocol
HTML HyperText Markup Languge
FTP File Transfer Protocol
TFTP Trivial File Transfer Protocol
```

