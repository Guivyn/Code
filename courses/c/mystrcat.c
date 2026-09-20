#include <stdio.h>

void mystrcat(char *s1, char *s2, char *new_s)
{
    int len1 = 0, len2 = 0;
    
    while (s1[len1]) 
    {
        len1++;
    }
    while (s2[len2]) 
    {
        len2++;
    }
    
    int j = 0;  
    
    for (int i = 0; i < len1; i++) {
        new_s[j++] = s1[i];
        new_s[j++] = s2[len2 - 1 - i];
    }
    
    new_s[j] = '\0';
}

int main()
{
    char str1[] = "abcd";
    char str2[] = "1234";
    char result[20] = {0};
    
    mystrcat(str1, str2, result);
    
    printf("s1   = %s\n", str1);
    printf("s2   = %s\n", str2);
    printf("结果 = %s\n", result);
    
    return 0;
}