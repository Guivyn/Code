#include <stdio.h>

struct Student
{ 
    int num; 
    char name[20]; 
    float score; 
};

int main()
{ 
    struct Student stu[5] = {
        {10101, "Zhang", 78},
        {10102, "Wang", 85},
        {10103, "Li", 92},
        {10104, "Zhao", 65},
        {10105, "Qian", 88}
    };
    
    // 选择排序：按成绩降序排列
    int i, j, k;
    struct Student temp;
    
    for(i = 0; i < 4; i++)  // n-1轮比较
    {
        k = i;  // 记录当前最高成绩的位置
        for(j = i + 1; j < 5; j++)
        {
            if(stu[j].score > stu[k].score)
                k = j;  // 更新最高成绩的位置
        }
        
        // 交换位置
        if(k != i)
        {
            temp = stu[i];
            stu[i] = stu[k];
            stu[k] = temp;
        }
    }
    
    // 输出排序结果
    printf("学号\t姓名\t成绩\n");
    printf("-------------------\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t%s\t%.1f\n", stu[i].num, stu[i].name, stu[i].score);
    }
    
    return 0;
}