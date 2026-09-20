# Code 学习与实践代码库

按领域整理的 C、C++、Python、Go 以及 HTML/JavaScript 学习代码。仓库重点是算法练习、课程代码、竞赛题解和小型项目。

## 目录结构

```text
algorithms/                 经典算法与数据结构练习
├── data-structures/        栈、队列、双端队列等
├── dp/                     动态规划
├── graph/                  图算法
├── math/                   数学与数值基础
├── search/                 搜索算法
├── sort/                   排序算法
└── strings/                字符串算法

competitive/                竞赛题解
├── codeforces/             Codeforces 题目归档入口
│   └── misc/               暂未细分的题目
└── *.cpp                   当前保留的通用竞赛练习

courses/                    课程学习代码
├── c/                      C 语言基础与数据结构课程
│   └── book-management/    图书管理练习
│       ├── array/          数组版
│       └── linked-list/    链表版
└── cpp/                    C++ 面向对象、模板和 STL 课程作业

projects/                   独立项目与可运行实验
├── course/                 课程设计项目
│   └── graduate_management.c
├── ascii_staircase.html    ASCII 阶梯互动实验
├── eyecard.html            眼睛跟随卡片实验
└── kinetic_topology.html   动力学拓扑可视化实验

go/                         Go 入门实验
└── test.go
```

## 内容优先级

- **第一优先**：`algorithms/`，用于复习和积累算法模板。
- **第二优先**：`courses/c/` 与 `courses/cpp/`，保存课程练习和学习过程。
- **第三优先**：`projects/`，包括毕业生信息管理系统和互动实验。
- **第四优先**：`competitive/`，按题目或比赛背景保留竞赛代码，不强行按算法重分类。
- **实验性内容**：`go/` 当前是 Go 入门代码，后续可以继续扩展为独立 Go 项目。

## 图书管理练习

`courses/c/book-management/` 使用数组和链表分别实现图书数据操作。两个子目录中的源文件都是独立练习程序，可以单独编译和运行；详细说明见其中的 `README.md`。

## 命名约定

- C、C++、Python 和 Go 源文件优先使用小写蛇形命名，例如 `prefix_sum.cpp`、`graduate_management.c`。
- 课程作业保留 `workNN_内容.cpp` 的编号形式，便于对应原课程顺序。
- 目录使用语义化名称；复合目录统一使用短横线，例如 `data-structures`、`book-management`、`linked-list`。
- 竞赛题按题目语义命名，不强制使用统一的比赛编号前缀。

## 编译说明

仓库中的多数源文件都是独立练习，不依赖统一构建系统。编译时选择具体源文件即可；编译产生的可执行文件应放入被 Git 忽略的临时目录，不要与源码混放。
