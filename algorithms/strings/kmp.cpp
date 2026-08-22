#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

// s : 主串（要被搜索的文本）  
// p : 模式串（要找的字符串）
// ne[] : KMP 的 next 数组（国内最常见叫法）
char s[N], p[N];
int ne[N];

int main() {
    int n, m;
    
    // ==================== 1. 输入 ====================
    scanf("%d", &n);           // 主串长度
    scanf("%s", s + 1);        // 主串从下标 1 开始存（1-based）
    scanf("%d", &m);           // 模式串长度
    scanf("%s", p + 1);        // 模式串从下标 1 开始存

    // ==================== 2. 预处理：计算模式串 p 的 next 数组 ====================
    ne[1] = 0;                 // 第一个字符失配只能跳到“之前”，长度为 0
    int j = 0;                 // j 表示当前已匹配的长度（也是 next 值）

    for (int i = 2; i <= m; i++) {           // 从第2个字符开始计算 next
        while (j > 0 && p[i] != p[j + 1]) {  // 失配：当前字符对不上
            j = ne[j];                       // 回退到上一个 border
        }
        if (p[i] == p[j + 1]) {              // 匹配上了
            j++;                             // 匹配长度 +1
        }
        ne[i] = j;                           // 记录：p[1...i] 的最长公共前后缀长度
    }

    // ==================== 3. KMP 匹配过程 ====================
    vector<int> ans;           // 存所有匹配成功的起始位置（1-based）
    j = 0;                     // 模式串指针重新从 0 开始

    for (int i = 1; i <= n; i++) {           // 遍历主串每一个字符
        while (j > 0 && s[i] != p[j + 1]) {  // 失配
            j = ne[j];                       // 模式串指针回退
        }
        if (s[i] == p[j + 1]) {              // 当前字符匹配
            j++;                             // 继续匹配下一个
        }
        if (j == m) {                        // 完整匹配了一个模式串
            ans.push_back(i - m + 1);        // 记录起始位置（1-based）
            j = ne[j];                       // 关键！继续找下一个可能的重叠匹配
        }
    }

    // ==================== 4. 输出结果 ====================
    if (ans.empty()) {
        printf("Not Found\n");
    } else {
        printf("%d\n", (int)ans.size());
        for (int pos : ans) {
            printf("%d ", pos);
        }
        printf("\n");
    }

    return 0;
}