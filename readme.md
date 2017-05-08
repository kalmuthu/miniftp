这里主要实现的是后端，客户端可以用leapftp3.0

目前实现的功能：登陆校验、空闲断开、连接数限制、断点续传、断点下载、空闲断开、删除创建文件、创建删除目录、重命名、目录切换

用到的技术：select模型超时检测，多进程模型处理数据连接和命令连接，主被动模式处理NAT影响，自定义nobody进程和服务进程间通信协议，ALARM信号实现空闲断开，封装writen/readn解决TCP粘包。双 Hash表解决ip最大连接数，开链法解决Hash冲突，内存池管理哈希节点内存。
		
整个项目主要有三个模块组成：ftp协议解析模块、内部协议解析模块、进程间通信模块
```
tree /f
└─ftp
    ├─miniftpd.conf					//配置文件
    ├─.h
    │      ftpproto.h                                   //ftp协议解析
    │      hash.h				        //哈希表
    │      memorypool.h					//内存池
    │	   parseconf.h					//载入配置文件
    │      priparent.h					//内部协议解析
    │      prisock.h					//内部进程通信
    │      str.h					//字符串操作封装
    │      sysutil.h					//系统操作封装
    │      tunable.h					//配置参数
    └─.cpp
            ftpproto.cpp            
            hash.cpp        
            memorypool.cpp            
            parseconf.cpp                 
            priparent.cpp
            prisock.cpp          
            str.cpp
            sysutil.cpp                
            tunable.cpp            
            main.cpp
```
```
 客户端服务端通信模型 

client                                  |       server
【客户端】<-------->【用户界面】        	|
                         |              |
                         |              |
                         |              |
                    【ftp协议解释器】<----|---->【服务器协议解释器】
                         |              |
                         |              |
                         |              |
【文件系统】<----->【用户数据传输进程】<-----|---->【服务器数据传输进程】<---->【文件系统】
  -------------------------------------------------------------------------------------------------------------------------- 
                                        
 ftp服务端内部通信模型

ftp服务进程                                      |               nobody进程
                                                |
【数据传输模块】<---->【FTP协议解析器】<--【进程间通信模块】->【内部协议解析器】
                            |                   |    
                            |                   |
                       【接入模块】               |
                            |                   |
                            |                   |
                          【客户端】              |    
                                                |
		
```
# 使用流程 #
## 启动FTP
在客户端，通过交互式的用户界面，客户从终端上输入启动FTP的用户交互式命令

## 建立控制连接 ##
客户端 TCP协议层根据用户命令给出的服务器IP地址，向服务器提供FTP服务的21端口（该端口是TCP协议层用来传输FTP命令的端口）发出主动建立连接的请求。服务器收到请求后，通过3次握手，就在进行FTP命令处理的用户协议解释器进程和服务器协议加湿器进程之间建立了一条TCP连接。

## 建立数据连接 ##
当客户通过交互式的用户界面，向FTP服务器发出要下载服务器的某一文件的命令时，该命令被送到用户协议解释器。

## 关闭FTP ##
当客户端发出退出命令时，控制连接被关闭，FTP服务结束
