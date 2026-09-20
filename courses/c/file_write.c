#include <stdio.h>

int main() {
    FILE *fp;
    char ch;
    
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("无法创建文件!\n");
        return 1;
    }
    
    printf("请输入字符，以#结束:\n");
    while ((ch = getchar()) != '#') {
        fputc(ch, fp);
    }
    
    fclose(fp);
    printf("字符已保存到文件!\n");
    
    return 0;
}