#include<stdio.h>

void insertionSortOptimized(int arr[], int n) {
    int i, j, key;

    for (i = n - 1; i > 0; i--) 
    {
        if (arr[i] < arr[i - 1])//冒泡排序实现arr[0]为最小值
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
    }
    
    for (i = 2; i < n; i++) //逻辑在形式上等价为：将新增值从右遍历所有比他大的值，并在已排序元素比他大时将大的数移到后面一格，并插入新增值
    {
        key = arr[i];//设置key
        j = i;//从当前位置开始比较
        
        while (key < arr[j - 1]) 
        {
            arr[j] = arr[j - 1];//操作值右侧的值覆盖到右侧
            j--;//回到上一位，即j-1，从更新后的值开始迭代
        }
        arr[j] = key;// while (key >= arr[j - 1])在找到的位置插入key，即由while函数隐含着key值的前一位不大于key值
    }
}

int main() {
    int num;
    int data[100];
    
    scanf("%d", &num);
    
    int max_value = -1;
    int first_max_index = -1;
    
    for (int i = 0; i < num; i++) 
    {
        scanf("%d", &data[i]);
        if (data[i] > max_value)
        {
            max_value = data[i];
            first_max_index = i;
        }
    }
    
    insertionSortOptimized(data, num);
    
    printf("%d %d", max_value, first_max_index);
    
    return 0;
}