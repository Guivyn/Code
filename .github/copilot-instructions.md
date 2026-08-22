# Copilot Instructions - C/C++ 算法学习项目

## 项目概述

这是一个 C/C++ 算法学习和竞赛编程练习项目,包含:

- **算法核心**: `algorithms/` 目录(KMP、DP、二分、Dijkstra 等经典模板)
- **竞赛题解**: `competitive/` 目录(语义命名的 Codeforces 练习)
- **课程作业**: `courses/cpp-oop/`(C++ 类/模板/STL)与 `courses/c-basics/`(C 基础)
- **大型项目**: `projects/graduate-management/graduate_management.c`(毕业生管理系统)
- **趣味作品**: `playground/`(p5.js 生成艺术)

---

## ? 快速参考

### 编译和运行

```bash
# VS Code 内置构建 (Ctrl+Shift+B)
# 使用 MinGW GCC,输出 .exe 到源文件所在目录

# 手动编译 (PowerShell)
gcc -g file.c -o file.exe                 # C 文件
g++ -g file.cpp -o file.exe               # C++ 文件
g++ -g file.cpp -o output/file.exe        # 指定输出目录

# 运行程序 (如有中文输出问题)
chcp 65001; .\file.exe                    # 切换编码后运行
```

### C++ 竞赛代码模板

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    // TODO: 实现逻辑

    return 0;
}
```

### C 代码模板 (大型项目)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    // 字段定义
} DataType;

int main(){
    // 实现逻辑
    return 0;
}
```

---

## 代码约定

### 头文件选择

| 场景             | 推荐                                    | 说明           |
| ---------------- | --------------------------------------- | -------------- |
| C++ 竞赛快速开发 | `#include <bits/stdc++.h>`              | 包含所有标准库 |
| C++ 标准项目     | 显式包含 (`<iostream>`, `<vector>`)     | 更清晰,更专业  |
| C 代码           | `<stdio.h>`, `<stdlib.h>`, `<string.h>` | 根据需要选择   |

### 命名规范

- **文件命名**:
  - 统一使用英文小写蛇形命名: `kmp.cpp`, `star_rail_time.cpp`
  - 算法题按主题归档到 `algorithms/` 子目录
  - 竞赛题放在 `competitive/`,按内容语义命名
  - 课程作业用 `workNN_内容.cpp` 两位编号(如 `work01_circle.cpp`)
  - 大型项目放 `projects/<项目名>/` 目录
- **变量/函数**: 小写蛇形 `student_id`, `is_valid_date()`
- **常量**: 大写 `MAX_STUDENTS = 1000010`

### 输入/输出和数据结构

- **C++ I/O**: `cin`/`cout` (竞赛快速)
- **C I/O**: `scanf`/`printf` (格式化可靠)
- **数组索引**: 竞赛算法常用 **1-based** (如 `algorithms/strings/kmp.cpp`)
- **STL 容器**: `vector`, `queue`, `stack`, `set`, `map`
- **大数组**: `const int N = 1000010;` 声明

---

## ? 关键文件指南

### 核心算法实现

- `algorithms/strings/kmp.cpp`: 字符串匹配,详细中文注释,1-based 索引
- `algorithms/dp/yanghui_triangle.cpp`: 杨辉三角,二维动态数组示例
- `algorithms/data-structures/rails_stack.cpp`: 栈的实际应用(铁轨,UVa 514)

### 大型项目

- `projects/graduate-management/graduate_management.c`: 毕业生信息管理系统
  - 模块: `Import`, `Scan`, `Query`, `Add`, `Delete`, `Edit`
  - 数据结构: `struct GraduateInfo`, `struct Date`
  - 验证函数: `isValidGender()`, `isValidDate()`, `isValidStudentId()`

### 竞赛题目

- `competitive/` 目录: 语义命名,如 `circle_game.cpp`, `parity_optimization.cpp`

---

## ? 编码和编译故障排除

### 中文输出乱码

**症状**: 代码中文显示为 "瀛﹀彿" 等乱码
**原因**: UTF-8 字节被误解为 GBK (Windows CP936)

**解决方案**:

```powershell
# 编译前切换 PowerShell 编码
chcp 65001

# 然后编译并运行
g++ -g file.cpp -o file.exe
.\file.exe
```

**验证**: 对比原始文件的 UTF-8 字节与 GBK 解码,确认一致性

### VS Code 设置检查

- 确认 `.vscode/settings.json` 中: `"files.encoding": "utf8"`
- 编译器设置已加载 `-fdiagnostics-color=always`

### 构建失败

- **MinGW 路径问题**: 检查 tasks.json 中的编译器路径是否正确
- **输出目录不存在**: 手动创建 `output/` 目录或指定为当前目录

---

## ? 开发建议

### 调试和测试

- 所有文件都用 `-g` 编译支持 GDB 调试
- 竞赛题目可通过标准输入直接测试
- 大型项目优先使用 `printf` 调试(C 代码)

### 代码审查

- 确保中英文注释一致
- 1-based 索引仅用于竞赛算法,避免在标准项目中混用
- C++ 竞赛代码使用 `using namespace std;`,标准项目使用命名空间限定

### 维护原则

- **学习和练习用途**: 不强调生产级错误处理
- **中文字符**: 确保编辑器支持 UTF-8 编码
- **注释**: 可混合使用中英文,优先用中文解释算法思路

---

## AI 代理说明 / AGENTS — AI 助手使用说明

目的：为 AI 编码代理提供快速上手的可操作信息（构建、约定、关键文件、常见陷阱）。内容遵循“简明且可链接”的原则，详见代码库中的相应文件。

### 快速命令

- 默认构建（VS Code）：按 `Ctrl+Shift+B`，使用任务 `C/C++: gcc.exe 生成活动文件`，编译器路径示例：`C:/Program Files (x86)/.../mingw64/bin/gcc.exe`。
- 手动编译：`gcc -g file.c -o file.exe` 或 `g++ -g file.cpp -o file.exe`。
- 中文输出修复（Windows）：先运行 `chcp 65001`，然后执行可执行文件。

### 约定与命名

- 统一英文 snake_case 文件名，按主题归档：`algorithms/`、`competitive/`、`courses/`、`projects/`、`playground/`。
- 竞赛题按内容语义命名（如 `competitive/star_rail_time.cpp`），不再使用 `cf_` 前缀。
- 课程作业：`courses/cpp-oop/workNN_内容.cpp` 两位编号。
- 大型项目：`projects/<项目名>/` 目录。

### 关键文件（快速导航）

- [Code/projects/graduate-management/graduate_management.c](Code/projects/graduate-management/graduate_management.c) — 毕业生管理系统（大型，含输入验证、数据模块）。
- [Code/algorithms/strings/kmp.cpp](Code/algorithms/strings/kmp.cpp) — 字符串匹配模板（1-based 索引）。
- [Code/algorithms/math/prefix_sum.cpp](Code/algorithms/math/prefix_sum.cpp), [Code/algorithms/dp/yanghui_triangle.cpp](Code/algorithms/dp/yanghui_triangle.cpp) — 其它常用模板。

### 环境/陷阱

- 文件编码：工作区应为 UTF-8；Windows 下输出可能需 `chcp 65001` 避免中文乱码。
- 编译器路径可能位于非标准位置（示例为 Steam 下的 MinGW），CI 或不同机器上可能需调整任务配置。
- C++ 标准/兼容性：代码中可能采用较新扩展（例如 gnu++23），在旧编译器上会有兼容性问题。

### 建议的后续自定义（可选）

1. 一个技能/脚本：自动运行默认构建并收集编译器错误（便于自动修复建议）。
2. 一个快速测试脚本：为常见题目运行样例输入并比较输出。
3. 一个“编码约定”检查器：提醒 1-based/0-based 索引使用差异、Windows 中文输出编码处理。

——
如果需要，可以把这些内容进一步拆成独立技能（如“编译/运行”或“编码约定”），或把本说明拆成独立的 `AGENTS.md` 保留为辅助导航。
