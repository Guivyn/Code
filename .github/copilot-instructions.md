# Copilot Instructions - C/C++ 算法学习项目

## 项目概述

这是一个 C/C++ 算法学习和竞赛编程练习项目,包含:

- **Codeforces 题目**: `cf_*.cpp` (各种难度的题目)
- **算法模板**: KMP.cpp, Range_sum.cpp 等经典算法实现
- **课程作业**: `##Keshe.c` (1485行毕业生管理系统), `ch*.c` 系列
- **基础练习**: 杨辉三角、斐波那契数列、排序算法等

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
  - 英文题目: 蛇形 `cf_div2_a.cpp`, `Range_sum.cpp`
  - 中文题目: 中文 `卡片游戏.cpp`, `安迪的第一个字典.cpp`
  - 课程作业: `#开头` (`#2121212.c`, `#31321321.c`)
  - 大型课设: `##开头` (`##Keshe.c` - 毕业生管理系统)
- **变量/函数**: 小写蛇形 `student_id`, `is_valid_date()`
- **常量**: 大写 `MAX_STUDENTS = 1000010`

### 输入/输出和数据结构

- **C++ I/O**: `cin`/`cout` (竞赛快速)
- **C I/O**: `scanf`/`printf` (格式化可靠)
- **数组索引**: 竞赛算法常用 **1-based** (如 KMP.cpp)
- **STL 容器**: `vector`, `queue`, `stack`, `set`, `map`
- **大数组**: `const int N = 1000010;` 声明

---

## ? 关键文件指南

### 核心算法实现

- **KMP.cpp**: 字符串匹配,详细中文注释,1-based 索引
- **Yang_hui.cpp**: 杨辉三角,二维动态数组示例
- **铁轨.cpp**: 栈的实际应用

### 大型项目

- **##Keshe.c** (1485行): 毕业生信息管理系统
  - 模块: `Import`, `Scan`, `Query`, `Add`, `Delete`, `Edit`
  - 数据结构: `struct GraduateInfo`, `struct Date`
  - 验证函数: `isValidGender()`, `isValidDate()`, `isValidStudentId()`

### 竞赛题目

- `cf_div*.cpp`: Codeforces Division 2/3/4
- `cf_ed_div2_*.cpp`: Educational Codeforces Round

---

## ? 编码和编译故障排除

### 中文文件名或输出乱码

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

- Codeforces 题：以 `cf_` 或 `cf_div*`、`cf_ed_` 等前缀命名（示例见项目文件）。
- 中文题目：直接使用中文文件名（项目以 UTF-8 保存）。
- 课程作业/大型项目：使用 `#` 或 `##` 前缀（例如 [Code/##Keshe.c](Code/##Keshe.c)）。
- 练习与模板：`work*.cpp` 系列、`KMP.cpp`、`Range_sum.cpp` 等。

### 关键文件（快速导航）

- [Code/##Keshe.c](Code/##Keshe.c) — 毕业生管理系统（大型，含输入验证、数据模块）。
- [Code/KMP.cpp](Code/KMP.cpp) — 字符串匹配模板（1-based 索引）。
- [Code/Range_sum.cpp](Code/Range_sum.cpp), [Code/Yang_hui.cpp](Code/Yang_hui.cpp) — 其它常用模板。

### 环境/陷阱

- 文件编码：工作区应为 UTF-8；Windows 下输出可能需 `chcp 65001` 避免中文乱码。
- 编译器路径可能位于非标准位置（示例为 Steam 下的 MinGW），CI 或不同机器上可能需调整任务配置。
- C++ 标准/兼容性：代码中可能采用较新扩展（例如 gnu++23），在旧编译器上会有兼容性问题。

### 建议的后续自定义（可选）

1. 一个技能/脚本：自动运行默认构建并收集编译器错误（便于自动修复建议）。
2. 一个快速测试脚本：为常见题目运行样例输入并比较输出。
3. 一个“编码约定”检查器：提醒 1-based/0-based 索引使用差异、中文文件名处理。

——
如果需要，我可以把这些内容进一步拆成独立技能（如“编译/运行”或“编码约定”），或把 `Code/AGENTS.md` 的单独文件保留为辅助导航。
