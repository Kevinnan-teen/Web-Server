# 轻量 Web 服务器
## 1、介绍
基于 Linux 的 Web 服务器，支持 GET、HEAD 方法处理静态资源。服务端并发模式使用epoll 和线程池实现 Reactor 事件处理模式。

## 2、开发环境
- 操作系统: Ubuntu 20.04 LTS
- 编译器: g++ 9.3
- 版本控制: git
- 自动化构建: cmake
- 编辑器: vscode
- 压测工具: [WebBench](https://github.com/EZLippi/WebBench)

## 3、使用方法
```
mkdir build
cd build
cmake .. && make
./webserver [-p port] [-t thread_numbers]  [-r website_root_path] [-d daemon_run]
```

## 4、核心技术
- 使用 epoll、边缘触发（ET）、非阻塞 IO 处理并发请求；

- 使用线程池提高并发度，降低频繁创建线程的开销；

- 基于 priority_queue 实现最小堆管理定时器，关闭超时请求；

- 使用 RAII 手法封装互斥器、条件变量等线程同步机制，实现资源自动管理；

- 使用 shared_ptr、weak_ptr 管理指针，防止内存泄漏；


## 5、性能测试
### 测试工具
- [WebBench](https://github.com/EZLippi/WebBench)

### 测试用例
#### 
4 个工作线程，端口设置为8000(`./webserver -t 4 -p 8000`)

页面大小: 541 bytes/page

wenbench设置: 1000客户端、连接60s、短连接、HTTP1.1（`./webbench -t 60 -c 1000 -2 --get http://localhost:8000/`）

空闲时线程CPU占用情况：
![](https://cdn.jsdelivr.net/gh/Kevinnan-teen/CDN/image-20210817102938869.png)

测试时线程CPU占用:
![](https://cdn.jsdelivr.net/gh/Kevinnan-teen/CDN/image-20210817103008711.png)

测试结果：

![](https://cdn.jsdelivr.net/gh/Kevinnan-teen/CDN/image-20210817102718587.png)
