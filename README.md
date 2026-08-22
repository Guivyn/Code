# Code 学习代码库

按主题归档整理的 C/C++/Python 学习代码。根目录只保留配置文件，代码全部按分类存放。

## 目录结构

```
algorithms/                 核心算法与经典题（复习重点）
├── strings/                KMP、字典、递归解析等字符串算法
├── data-structures/        栈、队列、优先队列经典题（UVa 514/10935/136 等）
├── dp/                     动态规划：硬币、斐波那契、期望 DP、杨辉三角
├── math/                   GCD、前缀和、水仙花数
├── search/                 二分、DFS、洪水填充
├── sort/                   排序题
└── graph/                  Dijkstra

competitive/                竞赛题解（保留有复习价值的题）
                            circle_game.cpp、parity_optimization.cpp、
                            star_rail_time.cpp 等，按内容语义命名

courses/                    课程作业
├── cpp-oop/                C++ 类、继承、模板、运算符重载、STL（work01~work61）
└── c-basics/               C 语言基础：排序、字符串、文件操作等

projects/
└── graduate-management/    课程设计：毕业生信息管理系统（原 ##Keshe.c）

playground/                 趣味实验与作品（p5.js 生成艺术等）
                            ascii_staircase.html、eyecard.html、
                            kinetic_topology.html
```

## 复习优先级

- **第一优先**：`algorithms/` 下的经典题和模板（KMP、二分、DP、Dijkstra、栈/队列题）。
- **第二优先**：`competitive/` 中有思路的题，文件名已按内容语义命名，方便回顾。
- **课程向**：`courses/` 保留的是 OOP 与 C 基础练习，适合期末复习；`projects/` 是完整项目，可当设计范例。

## 命名约定

- 文件名统一小写加下划线（snake_case），英文语义命名。
- 竞赛题按内容语义命名，如 `parity_optimization.cpp`、`star_rail_time.cpp`。
- 课程作业用 `workNN_内容.cpp` 两位编号。
