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
cmake .. && make
./webserver [-p port] [-t thread_numbers]  [-r website_root_path] [-d daemon_run]
```

## 4、核心技术
- 使用 epoll、边缘触发（ET）、非阻塞 IO 处理并发请求；

- 使用线程池提高并发度，降低频繁创建线程的开销；

- 基于 priority_queue 实现最小堆管理定时器，关闭超时请求；

- 使用 RAII 手法封装互斥器、条件变量等线程同步机制，实现资源自动管理；

- 使用 shared_ptr、weak_ptr 管理指针，防止内存泄漏；

