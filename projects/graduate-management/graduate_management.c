#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_STUDENTS 1000

// 日期结构体
struct Date 
{
    int year;
    int month;
    int day;
};

// 毕业生信息结构体
struct GraduateInfo 
{
    char student_id[20];
    char name[30];
    char gender;
    struct Date birth_date;
    int enrollment_year;
    int graduation_year;
    char education_level[20];
    char major[50];
    char career_direction[30];
    char employer[100];
    char job_major[50];
};

// 核心函数
void Import(struct GraduateInfo graduates[], int *count);
void Scan(struct GraduateInfo graduates[], int count);
void Query_by_num(struct GraduateInfo graduates[], int count);
void Query_by_name(struct GraduateInfo graduates[], int count);
void Add(struct GraduateInfo graduates[], int *count);
void Delete(struct GraduateInfo graduates[], int *count);
void Edit(struct GraduateInfo graduates[], int count);
void Year_statistics(struct GraduateInfo graduates[], int count);
void Education_statistics(struct GraduateInfo graduates[], int count);
void Major_statistics(struct GraduateInfo graduates[], int count);
void Job_statistics(struct GraduateInfo graduates[], int count);
void Work_statistics(struct GraduateInfo graduates[], int count);

//检查函数
int isValidGender(char gender);
int isEmployed(const char *career_direction);
int isValidDate(int year, int month, int day);
int isValidStudentId(const char *student_id);
int isValidEducationLevel(const char* education_level);
int isValidCareerDirection(const char* career_direction);
int checkGraduationAfterEnrollment(int enrollment_year, int graduation_year);
int isStudentIdExist(struct GraduateInfo graduates[], int count, const char *student_id);

// 辅助函数
void waitEnter();
void clearInputBuffer();
void Student_show(struct GraduateInfo *g);
void loadFromFile(struct GraduateInfo graduates[], int *count);
int saveToFile(struct GraduateInfo graduates[], int count);


int main() 
{
    struct GraduateInfo graduates[MAX_STUDENTS];
    int count = 0;
    
    loadFromFile(graduates, &count);

    int choice;
    do 
    {
        system("cls");
        printf("────────────────────────────────────────────\n");
        printf("       信息学院毕业生就业去向管理系统\n");
        printf("────────────────────────────────────────────\n");
        printf("1. 批量导入数据\n");
        printf("2. 浏览所有数据\n");
        printf("3. 查询数据\n");
        printf("4. 增加数据\n");
        printf("5. 删除数据\n");
        printf("6. 修改数据\n");
        printf("7. 统计功能\n");
        printf("0. 退出系统\n");
        printf("────────────────────────────────────────────\n");
        printf("请输入选择: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
            case 1: Import(graduates, &count); break;
            case 2: Scan(graduates, count); break;
            case 3: 
            {
                int sub;
                printf("1. 按学号查询\n");
                printf("2. 按姓名查询\n");
                scanf("%d", &sub);
                if (sub == 1) Query_by_num(graduates, count);
                else if (sub == 2) Query_by_name(graduates, count);
                break;
            }
            case 4: Add(graduates, &count); break;
            case 5: Delete(graduates, &count); break;
            case 6: Edit(graduates, count); break;
            case 7: 
            {
                int sub;
                printf("1. 全院就业率\n");
                printf("2. 不同学历就业率\n");
                printf("3. 不同专业就业率\n");
                printf("4. 就业方向统计\n");
                printf("5. 从事专业统计\n");
                scanf("%d", &sub);
                if (sub == 1) Year_statistics(graduates, count);
                else if (sub == 2) Education_statistics(graduates, count);
                else if (sub == 3) Major_statistics(graduates, count);
                else if (sub == 4) Job_statistics(graduates, count);
                else if (sub == 5) Work_statistics(graduates,count);
                getchar();
                break;
            }
            case 0: printf("感谢使用，再见！\n"); break;
            default: printf("输入无效，请重新输入！\n");
            waitEnter();
            break;
        }
    } while (choice != 0);
    return 0;
}

// 等待用户按回车键
void waitEnter() 
{
    printf("\n按回车键继续...");
    while ((getchar()) != '\n');//等待回车
}

// 清空输入缓冲区
void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);//遇到换行和文件结束符停止
}

// 验证性别输入有效性
int isValidGender(char gender) 
{
    return gender == 'M' || gender == 'F' || gender == 'm' || gender == 'f';
}

// 从文件加载数据
void loadFromFile(struct GraduateInfo graduates[], int *count) 
{
    FILE *dat = fopen("students.dat", "rb");
    if (dat) 
    {
        fread(count, sizeof(int), 1, dat);  // 读取记录总数
        fread(graduates, sizeof(struct GraduateInfo), *count, dat);  // 读取所有记录
        fclose(dat);
    }
}

// 验证学号格式函数
int isValidStudentId(const char *student_id) 
{
    // 1. 检查长度
    if (strlen(student_id) != 8) 
    {
        return 1;  // 长度不是8位
    }
    
    // 2. 检查前两位是否是"21"
    if (student_id[0] != '2' || student_id[1] != '1') 
    {
        return 1;  // 不是21开头
    }
    
    // 3. 检查所有字符都是数字
    for (int i = 0; i < 8; i++) 
    {
        if (student_id[i] < '0' || student_id[i] > '9') 
        {
            return 1;  // 包含非数字字符
        }
    }
    
    return 0;  // 格式正确
}

// 检查学号是否已存在
int isStudentIdExist(struct GraduateInfo graduates[], int count, const char *student_id) 
{
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(graduates[i].student_id, student_id) == 0) 
        {
            return 1;
        }
    }
    return 0;
}

// 验证日期有效性函数
int isValidDate(int year, int month, int day) 
{
    // 1. 基本范围检查
    if (year < 1900 || year > 2100) return 0;
    if (month < 1 || month > 12) return 0;
    
    // 2. 每月天数
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 3. 闰年处理
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        daysInMonth[1] = 29; // 闰年2月29天
    }
    
    // 4. 日期检查
    if (day < 1 || day > daysInMonth[month - 1]) 
    {
        return 0;
    }
    
    return 1;
}

// 验证学历有效性函数
int isValidEducationLevel(const char* education_level) 
{
    const char* valid_levels[] = {"本科生", "硕士研究生", "博士研究生"};
    int valid_count = 3;
    
    for (int i = 0; i < valid_count; i++) 
    {
        if (strcmp(education_level, valid_levels[i]) == 0) 
        {
            return 1; // 有效
        }
    }
    
    return 0; // 无效
}

// 检查毕业年份是否大于入学年份
int checkGraduationAfterEnrollment(int enrollment_year, int graduation_year) 
{
    if (graduation_year<1949)
    {
        return 0; // 不通过：毕业年份小于1949
    }
    if (enrollment_year >2025 ) 
    {
        return 0; // 不通过：入学年份大于2025
    }
    
    if (graduation_year > enrollment_year) 
    {
        return 1; // 通过：毕业年份大于入学年份
    } 
    else 
    {
        return 0; // 不通过：毕业年份不大于入学年份
    }
}

// 验证就业方向有效性函数
int isValidCareerDirection(const char* career_direction) 
{
    // 定义有效的就业方向列表
    const char* valid_directions[] = 
    {
        "直接工作", 
        "公务员", 
        "国内读硕", 
        "出国读硕", 
        "国内读博", 
        "国外读博", 
        "二战", 
        "二学位", 
        "未就业", 
        "其他"
    };
    
    int direction_count = 10;  // 有效方向的数量
    
    // 遍历所有有效方向
    for (int i = 0; i < direction_count; i++) 
    {
        if (strcmp(career_direction, valid_directions[i]) == 0) 
        {
            return 1; // 有效
        }
    }
    
    return 0; // 无效
}

// 保存数据到文件
int saveToFile(struct GraduateInfo graduates[], int count) 
{
    FILE *dat = fopen("students.dat", "wb");//“wb”表示以二进制写入方式打开文件
    if (dat == NULL) 
    {
        return 0;
    }
    
    fwrite(&count, sizeof(int), 1, dat);//先写入记录数
    for (int i = 0; i < count; i++) 
    {
        fwrite(&graduates[i], sizeof(struct GraduateInfo), 1, dat);//写入每条记录
    }
    
    fclose(dat);
    return 1;
} 

// 判断是否为就业状态
int isEmployed(const char *career_direction) 
{
    if (strcmp(career_direction, "二战") == 0 ||
    strcmp(career_direction, "未就业") == 0 ||
    strcmp(career_direction, "其他") == 0) 
    {
        return 0;
    }
    return 1;
}

// 从文本文件批量导入数据
void Import(struct GraduateInfo graduates[], int *count) 
{
    system("cls");
    printf("═════════════════════════════════════════════\n");
    printf("           批量导入数据\n");
    printf("═════════════════════════════════════════════\n\n");
    
    FILE *txt = fopen("students.txt", "r");//以只读方式打开文本文件
    if (txt == NULL) 
    {
        printf("文件打开失败！\n");
        waitEnter();
        return;
    }
    
    char line[501];
    int imported = 0;
    int skipped = 0;
    int invalid = 0;
    
    while (fgets(line, sizeof(line), txt)) 
    {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) continue;
        
        struct GraduateInfo g;
        //格式化读取txt文件内容，
        int parsed = sscanf(line, "%[^,],%[^,],%c,%d-%d-%d,%d,%d,%[^,],%[^,],%[^,],%[^,],%[^,]",
                            g.student_id, g.name, &g.gender,
                            &g.birth_date.year, &g.birth_date.month, &g.birth_date.day,
                            &g.enrollment_year, &g.graduation_year,
                            g.education_level, g.major, g.career_direction,
                            g.employer, g.job_major);
        
        if (parsed == 13) //成功解析13个字段
        {
            // 应用所有检查函数
            int valid = 1;
            
            if (isStudentIdExist(graduates, *count, g.student_id)) 
            {
                printf("学号 %s 已存在，跳过\n", g.student_id);
                skipped++;
                valid = 0;
            }
            else if (isValidStudentId(g.student_id)) 
            {
                printf("学号 %s 格式错误，跳过\n", g.student_id);
                invalid++;
                valid = 0;
            }
            else if (!isValidGender(g.gender)) 
            {
                printf("学生 %s 性别 %c 无效，跳过\n", g.student_id, g.gender);
                invalid++;
                valid = 0;
            }
            else if (!isValidDate(g.birth_date.year, g.birth_date.month, g.birth_date.day)) 
            {
                printf("学生 %s 出生日期无效，跳过\n", g.student_id);
                invalid++;
                valid = 0;
            }
            else if (!checkGraduationAfterEnrollment(g.enrollment_year, g.graduation_year)) 
            {
                printf("学生 %s 入学/毕业年份无效，跳过\n", g.student_id);
                invalid++;
                valid = 0;
            }
            else if (!isValidEducationLevel(g.education_level)) 
            {
                printf("学生 %s 学历 %s 无效，跳过\n", g.student_id, g.education_level);
                invalid++;
                valid = 0;
            }
            else if (!isValidCareerDirection(g.career_direction)) 
            {
                printf("学生 %s 就业方向 %s 无效，跳过\n", g.student_id, g.career_direction);
                invalid++;
                valid = 0;
            }
            
            if (valid) 
            {
                graduates[*count] = g;
                (*count)++;//增加记录数
                imported++;
                printf("导入：%s - %s\n", g.student_id, g.name);
            }
        } 
        else 
        {
            printf("格式错误：%s\n", line);
            skipped++;
        }
    }

    fclose(txt);

    if (imported > 0) 
    {
        if (saveToFile(graduates, *count)) 
        {
            printf("\n══════════════════════════════════════════\n");
            printf("导入完成！\n");
            printf("成功导入：%d 条\n", imported);
            printf("跳过：%d 条\n", skipped);
            printf("无效数据：%d 条\n", invalid);
            printf("当前总数：%d 条\n", *count);
            printf("════════════════════════════════════════════\n");
        }
    } 
    else 
    {
        printf("没有导入任何数据。\n");
    }

    waitEnter();
}

// 显示单条毕业生详细信息
void Student_show(struct GraduateInfo *g) 
{
    printf("┌────────────────────────────────────────────────┐\n");
    printf("│ 学号: %-16s   姓名: %-16s│\n", g->student_id, g->name);
    printf("│ 性别: %-16c   出生: %04d-%02d-%02d      │\n", g->gender, g->birth_date.year, g->birth_date.month, g->birth_date.day);
    printf("│ 入学: %-16d   毕业: %-16d│\n", g->enrollment_year, g->graduation_year);
    printf("│ 专业: %-38s   │\n", g->major);
    printf("│ 方向: %-16s   学历: %-16s│\n", g->career_direction,g->education_level);
    printf("│ 单位: %-16s   从事: %-16s│\n",  g->employer,g->job_major);
    printf("└────────────────────────────────────────────────┘\n");
}

// 浏览所有毕业生信息
void Scan(struct GraduateInfo graduates[], int count) 
{
    system("cls");
    printf("═════════════════════════════════════════════\n");
    printf("           所有毕业生信息\n");
    printf("═════════════════════════════════════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前没有数据。\n");
        waitEnter();
        return;
    }
    
    printf("共有 %d 名学生：\n\n", count);
    
    for (int i = 0; i < count; i++) 
    {
        printf("【第 %d 条记录】\n", i + 1);
        Student_show(&graduates[i]);
        printf("\n");
        
        if ((i + 1) % 3 == 0 && i + 1 < count) 
        {
            printf("--- 按回车继续 ---\n");
            getchar();
        }
    }
    waitEnter();
}

// 按学号查询毕业生信息
void Query_by_num(struct GraduateInfo graduates[], int count) 
{
    system("cls");
    printf("═══════════════════════════════════════════\n");
    printf("             按学号查询\n");
    printf("═══════════════════════════════════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前没有数据。\n");
        waitEnter();
        return;
    }
    
    char search_id[20];
    printf("请输入学号: ");
    scanf("%s", search_id);
    clearInputBuffer();
    
    int found = 0;
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(graduates[i].student_id, search_id) == 0) 
        {
            printf("\n找到学生信息：\n\n");
            Student_show(&graduates[i]);
            found = 1;
            break;
        }
    }
    
    if (!found) 
    {
        printf("\n未找到学号为 %s 的学生。\n", search_id);
    }
    
    waitEnter();
}

// 按姓名查询毕业生信息
void Query_by_name(struct GraduateInfo graduates[], int count) 
{
    system("cls");
    printf("═══════════════ 按姓名查询 ═══════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }
    
    char search_name[30];
    printf("请输入要查询的姓名: ");
    scanf("%s", search_name);
    clearInputBuffer();
    
    int found = 0;
    int found_indexes[1001];
    int found_count = 0;
    
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(graduates[i].name, search_name) == 0) 
        {
            found_indexes[found_count++] = i;
            found = 1;
        }
    }
    
    if (found) 
    {
        printf("\n找到 %d 条姓名匹配的记录：\n\n", found_count);
        for (int i = 0; i < found_count; i++) 
        {
            printf("【第 %d 条记录】\n", i + 1);
            Student_show(&graduates[found_indexes[i]]);
            printf("\n");
        }
    } 
    else 
    {
        printf("\n未找到姓名为 %s 的毕业生信息\n", search_name);
    }
    
    waitEnter();
}

// 添加新的毕业生记录
void Add(struct GraduateInfo graduates[], int *count) 
{
    system("cls");
    printf("═══════════════ 增加毕业生记录 ═══════════════\n\n");
    
    if (*count >= 1001) // 最大记录数检查
    {
        printf("错误：已达到最大记录数 (%d)，无法添加新记录\n", 1000);
        waitEnter();
        return;
    }
    
    struct GraduateInfo new_graduate;
    
    /// 输入学号并查重
    while (1) 
    {
        printf("请输入学号 (格式: 2100xxxx): ");
        scanf("%s", new_graduate.student_id);
        clearInputBuffer();
        if (isValidStudentId(new_graduate.student_id))//验证学号格式
        {
            printf("学号格式错误，请重新输入！\n");
            continue;
        }
        if (isStudentIdExist(graduates, *count, new_graduate.student_id)) // 查重
        {
            printf("学号已存在，请重新输入！\n");
        } 
        else break;
    }
    printf("请输入姓名: ");
    scanf("%s", new_graduate.name);
    clearInputBuffer();
    
    // 输入性别
    while (1) 
    {
        printf("请输入性别 (M/F): ");
        scanf("%c", &new_graduate.gender);
        clearInputBuffer();
        
        if (isValidGender(new_graduate.gender)) 
        {
            break;
        } 
        else 
        {
            printf("性别输入无效，请重新输入！\n");
        }
    }
    
    while (1) 
    {
        printf("请输入出生日期 (YYYY-MM-DD): ");
        
        // 假设用户会输入正确格式
        scanf("%d-%d-%d", &new_graduate.birth_date.year,
                            &new_graduate.birth_date.month,
                            &new_graduate.birth_date.day);
        clearInputBuffer();
        
        // 日期检查函数会处理无效值
        if (isValidDate(new_graduate.birth_date.year,
                        new_graduate.birth_date.month,
                        new_graduate.birth_date.day)) 
        {
            break;
        } 
        else 
        {
            printf("日期无效，请重新输入！\n");
        }
    }  
    
    while (1) 
    {
        printf("请输入入学年份: ");
        scanf("%d", &new_graduate.enrollment_year);
        clearInputBuffer();
        
        printf("请输入毕业年份: ");
        scanf("%d", &new_graduate.graduation_year);
        clearInputBuffer();

        if (checkGraduationAfterEnrollment(new_graduate.enrollment_year, new_graduate.graduation_year))
        {
            break;
        }
        else 
        {
            printf("\n错误：毕业年份必须大于入学年份且年份有效！\n");
            printf("入学年份应≤2025，毕业年份应≥1949\n");
        }
    }

    while (1) 
    {
        printf("请输入毕业学历 (本科生/硕士研究生/博士研究生): ");
        scanf("%s", new_graduate.education_level);
        clearInputBuffer();
        
        if (isValidEducationLevel(new_graduate.education_level))
        {
            break;
        }
        else 
        {
            printf("学历无效，请重新输入！\n");
        }
    }
    
    printf("请输入毕业专业: ");
    scanf("%s", new_graduate.major);
    clearInputBuffer();
    
    while (1) 
    {
        printf("请输入就业方向 (直接工作/公务员/国内读硕/出国读硕/国内读博/国外读博/二战/二学位/未就业/其他): ");
        scanf("%s", new_graduate.career_direction);
        clearInputBuffer();
        
        if (isValidCareerDirection(new_graduate.career_direction))
        {
            break;
        }
        else 
        {
            printf("就业方向无效，请重新输入！\n");
        }
    }
    
    printf("请输入就业或升学单位: ");
    scanf("%s", new_graduate.employer);
    clearInputBuffer();
    
    printf("请输入从事专业: ");
    scanf("%s", new_graduate.job_major);
    clearInputBuffer();
    
    // 确认信息
    printf("\n════════════════════════════════════════\n");
    printf("请确认新增信息：\n\n");
    Student_show(&new_graduate);
    
    printf("\n确认添加此记录吗？(Y/N): ");
    char confirm;
    scanf("%c", &confirm);
    clearInputBuffer();
    
    if (confirm == 'Y' || confirm == 'y') 
    {
        graduates[*count] = new_graduate;
        (*count)++;// 增加记录数
        
        if (saveToFile(graduates, *count)) 
        {
            printf("\n记录添加成功！\n");
        } else 
        {
            printf("\n记录添加失败！\n");
        }
    } 
    else 
    {
        printf("\n已取消添加操作。\n");
    }
    
    waitEnter();
}

// 删除毕业生记录
void Delete(struct GraduateInfo graduates[], int *count) 
{
    system("cls");
    printf("═══════════════ 删除毕业生记录 ═══════════════\n\n");
    
    if (*count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }
    
    char search_key[30];
    printf("请输入要删除的学号或姓名: ");
    scanf("%s", search_key);
    clearInputBuffer();
    
    int found_indexes[1001];
    int found_count = 0;
    
    for (int i = 0; i < *count; i++) 
    {
        if (strcmp(graduates[i].student_id, search_key) == 0 || 
            strcmp(graduates[i].name, search_key) == 0) 
            {
            found_indexes[found_count++] = i;
            }
    }
    
    if (found_count == 0) 
    {
        printf("\n未找到匹配的毕业生信息\n");
        waitEnter();
        return;
    }
    
    printf("\n找到 %d 条匹配记录：\n\n", found_count);
    for (int i = 0; i < found_count; i++) 
    {
        printf("【第 %d 条记录】\n", i + 1);
        Student_show(&graduates[found_indexes[i]]);
        printf("\n");
    }
    
    // 如果找到多条记录，要求指定学号
    if (found_count > 1) 
    {
        printf("\n找到多条匹配记录，请输入要删除的学号: ");
        char specific_id[20];
        scanf("%s", specific_id);
        clearInputBuffer();
        
        found_count = 0;
        for (int i = 0; i < *count; i++) 
        {
            if (strcmp(graduates[i].student_id, specific_id) == 0) //匹配指定学号
            {
                found_indexes[found_count++] = i;
                break;
            }
        }
        
        if (found_count == 0) 
        {
            printf("\n未找到学号为 %s 的记录\n", specific_id);
            waitEnter();
            return;
        }
    }
    
    printf("\n确认删除这条记录吗？(Y/N): ");
    char confirm;
    scanf("%c", &confirm);
    clearInputBuffer();
    
    if (confirm == 'Y' || confirm == 'y') 
    {
        int delete_index = found_indexes[0];
        
        printf("\n要删除的记录：\n\n");
        Student_show(&graduates[delete_index]);
        
        // 删除记录（移动数组元素）
        for (int i = delete_index; i < *count - 1; i++) 
        {
            graduates[i] = graduates[i + 1];
        }
        (*count)--;
        
        if (saveToFile(graduates, *count)) 
        {
            printf("\n记录删除成功！\n");
        } 
        else 
        {
            printf("\n记录删除失败！\n");
        }
    }
    else 
    {
        printf("\n已取消删除操作。\n");
    }
    
    waitEnter();
}

// 修改毕业生记录
void Edit(struct GraduateInfo graduates[], int count) 
{
    system("cls");
    printf("═══════════════ 修改毕业生记录 ═══════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }
    
    char search_id[20];
    printf("请输入要修改的学号: ");
    scanf("%s", search_id);
    clearInputBuffer();
    
    int found_index = -1;
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(graduates[i].student_id, search_id) == 0) 
        {
            found_index = i;
            break;
        }
    }
    
    if (found_index == -1) 
    {
        printf("\n未找到学号为 %s 的毕业生信息\n", search_id);
        waitEnter();
        return;
    }
    
    printf("\n原记录信息：\n\n");
    Student_show(&graduates[found_index]);
    
    printf("\n═════════════════════════════════════\n");
    printf("请选择要修改的项目：\n");
    printf("1. 姓名\n");
    printf("2. 性别\n");
    printf("3. 出生日期\n");
    printf("4. 入学年份\n");
    printf("5. 毕业年份\n");
    printf("6. 毕业学历\n");
    printf("7. 毕业专业\n");
    printf("8. 就业方向\n");
    printf("9. 就业或升学单位\n");
    printf("10. 从事专业\n");
    printf("0. 取消修改\n");
    printf("═════════════════════════════════════\n");
    printf("请输入选择: ");
    
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();
    
    if (choice < 1 || choice > 10) 
    {
        printf("\n已取消修改操作。\n");
        waitEnter();
        return;
    }
    
    switch (choice) 
    {
        case 1:
            printf("请输入新姓名: ");
            scanf("%s", graduates[found_index].name);
            clearInputBuffer();
            break;
            
        case 2:
            while (1) 
            {
                printf("请输入新性别 (M/F): ");
                scanf("%c", &graduates[found_index].gender);
                clearInputBuffer();
                if (isValidGender(graduates[found_index].gender)) 
                
                {
                    break;
                } 
                else 
                {
                    printf("性别输入无效，请重新输入！\n");
                }
            }
            break;
            
        case 3:
            while (1) 
            {
                printf("请输入新出生日期 (YYYY-MM-DD): ");
                
                int result = scanf("%d-%d-%d", &graduates[found_index].birth_date.year,
                                                    &graduates[found_index].birth_date.month,
                                                    &graduates[found_index].birth_date.day);
                clearInputBuffer();
                
                if (result != 3) 
                {
                    printf("错误：日期格式不正确！请输入数字，如：2000-05-15\n");
                    continue;
                }
                
                if (isValidDate(graduates[found_index].birth_date.year,
                                graduates[found_index].birth_date.month,
                                graduates[found_index].birth_date.day)) 
                {
                    break; // 日期有效，退出循环
                } else {
                    printf("日期无效，请重新输入！\n");
                }
            }
            break;
            
        case 4:
            printf("请输入新入学年份: ");
            scanf("%d", &graduates[found_index].enrollment_year);
            clearInputBuffer();
            
            // 检查入学年份和毕业年份的关系
            if (!checkGraduationAfterEnrollment(graduates[found_index].enrollment_year, 
                                                graduates[found_index].graduation_year)) 
            {
                printf("警告：入学年份修改后可能导致入学/毕业年份关系无效！\n");
            }
            break;
            
        case 5:
            printf("请输入新毕业年份: ");
            scanf("%d", &graduates[found_index].graduation_year);
            clearInputBuffer();
            
            // 检查入学年份和毕业年份的关系
            if (!checkGraduationAfterEnrollment(graduates[found_index].enrollment_year, 
                                                graduates[found_index].graduation_year)) 
            {
                printf("警告：毕业年份修改后可能导致入学/毕业年份关系无效！\n");
            }
            break;
            
        case 6:
            while (1) 
            {
                printf("请输入新毕业学历: ");
                scanf("%s", graduates[found_index].education_level);
                clearInputBuffer();
                
                if (isValidEducationLevel(graduates[found_index].education_level)) 
                {
                    break;
                }
                else 
                {
                    printf("学历无效，请重新输入！\n");
                }
            }
            break;
            
        case 7:
            printf("请输入新毕业专业: ");
            scanf("%s", graduates[found_index].major);
            clearInputBuffer();
            break;
            
        case 8:
            while (1) 
            {
                printf("请输入新就业方向: ");
                scanf("%s", graduates[found_index].career_direction);
                clearInputBuffer();
                
                if (isValidCareerDirection(graduates[found_index].career_direction)) 
                {
                    break;
                }
                else 
                {
                    printf("就业方向无效，请重新输入！\n");
                }
            }
            break;
            
        case 9:
            printf("请输入新就业或升学单位: ");
            scanf("%s", graduates[found_index].employer);
            clearInputBuffer();
            break;
            
        case 10:
            printf("请输入新从事专业: ");
            scanf("%s", graduates[found_index].job_major);
            clearInputBuffer();
            break;
    }
    
    if (saveToFile(graduates, count)) 
    {
        printf("\n修改成功！\n");
    } 
    else 
    {
        printf("\n修改失败！\n");
    }
    waitEnter();
}

// 统计某一年份就业率
void Year_statistics(struct GraduateInfo graduates[], int count) 
{
    system("cls");
    printf("═══════════════ 统计某一年份就业率 ═══════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }
    
    int year;
    printf("请输入要统计的年份: ");
    scanf("%d", &year);
    clearInputBuffer();
    
    int total = 0;
    int employed = 0;
    
    for (int i = 0; i < count; i++) 
    {
        if (graduates[i].graduation_year == year) 
        {
            total++;
            if (isEmployed(graduates[i].career_direction))
            {
                employed++;
            }
        }
    }
    
    printf("\n════════════════════════════════════════\n");
    printf("%d年毕业生就业情况统计：\n\n", year);
    printf("毕业生总数：%d人\n", total);
    printf("就业人数：%d人\n", employed);
    
    if (total > 0) 
    {
        double employment_rate = (double)employed / total * 100;
        printf("就业率：%.2f%%\n", employment_rate);
        printf("未就业率：%.2f%%\n", 100 - employment_rate);
    } 
    else 
    {
        printf("该年份无毕业生记录\n");
    }
    printf("════════════════════════════════════════\n");
    waitEnter();
}

// 统计某一年份不同学历就业率
void Education_statistics(struct GraduateInfo graduates[], int count) 
{
    system("cls");
    printf("═══════════════ 统计某一年份不同学历就业率 ═══════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }
    
    int year;
    printf("请输入要统计的年份: ");
    scanf("%d", &year);
    clearInputBuffer();
    
    struct EducationStat 
    {
        char level[20];
        int total;
        int employed;
    } stats[3] = {{"本科生", 0, 0}, {"硕士研究生", 0, 0}, {"博士研究生", 0, 0}};
    
    for (int i = 0; i < count; i++) 
    {
        if (graduates[i].graduation_year == year) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (strcmp(graduates[i].education_level, stats[j].level) == 0) 
                {
                    stats[j].total++;
                    if (isEmployed(graduates[i].career_direction)) 
                    {
                        stats[j].employed++;
                    }
                    break;
                }
            }
        }
    }
    
    printf("\n════════════════════════════════════════\n");
    printf("%d年不同学历就业情况统计：\n\n", year);
    printf("学历类别      总人数  就业人数  就业率\n");
    printf("───────────────────────────────────────\n");
    
    int total_all = 0;
    int employed_all = 0;
    
    for (int i = 0; i < 3; i++) 
    {
        if (stats[i].total > 0) 
        {
            double rate = (double)stats[i].employed / stats[i].total * 100;//计算就业率
            printf("%-12s %6d %8d %8.2f%%\n", stats[i].level, stats[i].total, stats[i].employed, rate);
            total_all += stats[i].total;//累计总人数
            employed_all += stats[i].employed;//累计就业人数
        }
    }
    
    if (total_all > 0) // 总人数大于0时显示总计
    {
        printf("───────────────────────────────────────\n");
        double rate_all = (double)employed_all / total_all * 100;
        printf("%-12s %6d %8d %8.2f%%\n", "总计", total_all, employed_all, rate_all);
    } 
    else 
    {
        printf("\n该年份无毕业生记录\n");
    }
    printf("════════════════════════════════════════\n");
    waitEnter();
}

// 统计某一年份不同专业就业率
void Major_statistics(struct GraduateInfo graduates[], int count)
{
    system("cls");
    printf("═══════════════ 统计某一年份不同专业就业率 ═══════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }
    
    int year;
    printf("请输入要统计的年份: ");
    scanf("%d", &year);
    clearInputBuffer();
    
    #define MAX_MAJORS 20
    struct MajorStat 
    {
        char major[50];
        int total;
        int employed;
    } stats[MAX_MAJORS];
    
    int stat_count = 0;
    
    for (int i = 0; i < MAX_MAJORS; i++) 
    {
        stats[i].major[0] = '\0';
        stats[i].total = 0;
        stats[i].employed = 0;
    }
    
    for (int i = 0; i < count; i++) 
    {
        if (graduates[i].graduation_year == year) 
        {
            int found = 0;
            
            for (int j = 0; j < stat_count; j++) 
            {
                if (strcmp(graduates[i].major, stats[j].major) == 0) 
                {
                    stats[j].total++;
                    if (isEmployed(graduates[i].career_direction)) 
                    {
                        stats[j].employed++;
                    }
                    found = 1;
                    break;
                }
            }
            
            if (!found && stat_count < MAX_MAJORS) 
            {
                strcpy(stats[stat_count].major, graduates[i].major);
                stats[stat_count].total = 1;
                stats[stat_count].employed = isEmployed(graduates[i].career_direction) ? 1 : 0;
                stat_count++;
            }
        }
    }
    
    printf("\n════════════════════════════════════════\n");
    printf("%d年不同专业就业情况统计：\n\n", year);
    printf("专业名称                  总人数  就业人数  就业率\n");
    printf("─────────────────────────────────────────────────\n");
    
    int total_all = 0;
    int employed_all = 0;
    
    for (int i = 0; i < stat_count; i++) 
    {
        if (stats[i].total > 0) 
        {
            double rate = (double)stats[i].employed / stats[i].total * 100;
            printf("%-25s %6d %8d %8.2f%%\n", stats[i].major, stats[i].total, stats[i].employed, rate);
            total_all += stats[i].total;
            employed_all += stats[i].employed;
        }
    }
    
    if (total_all > 0) 
    {
        printf("─────────────────────────────────────────────────\n");
        double rate_all = (double)employed_all / total_all * 100;
        printf("%-25s %6d %8d %8.2f%%\n", "总计", total_all, employed_all, rate_all);
    } 
    else 
    {
        printf("\n该年份无毕业生记录\n");
    }
    printf("════════════════════════════════════════\n");
    waitEnter();
}

// 统计某一年份不同就业方向人数和比例
void Job_statistics(struct GraduateInfo graduates[], int count) 
{
    system("cls");
    printf("════════════════════ 统计某一年份不同就业方向人数和比例 ════════════════════\n\n");
    
    if (count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }
    
    int year;
    printf("请输入要统计的年份: ");
    scanf("%d", &year);
    clearInputBuffer();
    
    char *career_types[] = {"直接工作", "公务员", "国内读硕", "出国读硕","国内读博", "国外读博", "二战", "二学位", "未就业", "其他"};
    int type_count = 10;
    
    int career_stats[10] = {0};
    int total = 0;
    
    for (int i = 0; i < count; i++) 
    {
        if (graduates[i].graduation_year == year) 
        {
            total++;
            for (int j = 0; j < type_count; j++) 
            {
                if (strcmp(graduates[i].career_direction, career_types[j]) == 0) 
                {
                    career_stats[j]++;//对应就业方向计数+1
                    break;
                }
            }
        }
    }
    
    printf("\n════════════════════════════════════════════════\n");
    printf("%d年不同就业方向统计：\n\n", year);
    printf("就业方向        人数      比例\n");
    printf("──────────────────────────────────────\n");
    
    for (int i = 0; i < type_count; i++) 
    {
        if (career_stats[i] > 0 || i < 8) 
        {
            double percentage = total > 0 ? (double)career_stats[i] / total * 100 : 0;
            printf("%-12s %6d %10.2f%%\n", career_types[i], career_stats[i], percentage);
        }
    }
    
    printf("──────────────────────────────────────\n");
    printf("%-12s %6d %10.2f%%\n", "总计", total, 100.0);
    printf("════════════════════════════════════════════════\n");
    waitEnter();
}

void Work_statistics(struct GraduateInfo graduates[], int count)
{
    system("cls");
    printf("═══════════════ 统计某一年份从事专业人数和比例 ═══════════════\n\n");

    if (count == 0) 
    {
        printf("当前系统无毕业生信息！\n");
        waitEnter();
        return;
    }

    int year;
    printf("请输入要统计的年份: ");
    scanf("%d", &year);
    clearInputBuffer();

    #define MAX_JOBS 50  // 最大从事专业种类数
    char job_majors[MAX_JOBS][50];  // 存储不同的从事专业
    int job_counts[MAX_JOBS] = {0};  // 对应专业的计数
    int job_type_count = 0;  // 实际专业种类数
    int total = 0;  // 该年份总人数

    // 初始化数组
    for (int i = 0; i < MAX_JOBS; i++) 
    {
        job_majors[i][0] = '\0';
    }

    // 遍历所有毕业生，统计该年份的从事专业
    for (int i = 0; i < count; i++) 
    {
        if (graduates[i].graduation_year == year && strlen(graduates[i].job_major) > 0) // 有填写从事专业
        {
            total++;
            int found = 0;
            
            // 检查这个专业是否已经存在于统计数组中
            for (int j = 0; j < job_type_count; j++) 
            {
                if (strcmp(graduates[i].job_major, job_majors[j]) == 0) 
                {
                    job_counts[j]++;  // 专业已存在，计数+1
                    found = 1;
                    break;
                }
            }
            
            // 如果是新的专业，添加到数组中
            if (!found && job_type_count < MAX_JOBS) 
            {
                strcpy(job_majors[job_type_count], graduates[i].job_major);
                job_counts[job_type_count] = 1;
                job_type_count++;
            }
        }
    }

    printf("\n════════════════════════════════════════════════\n");
    printf("%d年毕业生从事专业统计：\n\n", year);
    
    if (total == 0) 
    {
        printf("该年份无毕业生记录！\n");
    }
    else if (job_type_count == 0) 
    {
        printf("该年份毕业生均未填写从事专业信息！\n");
    }
    else 
    {
        printf("从事专业                      人数      比例\n");
        printf("────────────────────────────────────────────────\n");
        
        // 冒泡排序
        for (int i = 0; i < job_type_count - 1; i++) 
        {
            for (int j = 0; j < job_type_count - i - 1; j++) 
            {
                if (job_counts[j] < job_counts[j + 1]) 
                {
                    // 交换计数
                    int temp_count = job_counts[j];
                    job_counts[j] = job_counts[j + 1];
                    job_counts[j + 1] = temp_count;
                    
                    // 交换专业名称
                    char temp_name[50];
                    strcpy(temp_name, job_majors[j]);
                    strcpy(job_majors[j], job_majors[j + 1]);
                    strcpy(job_majors[j + 1], temp_name);
                }
            }
        }
        
        // 输出统计结果
        int displayed_total = 0;
        for (int i = 0; i < job_type_count; i++) 
        {
            if (job_counts[i] > 0) 
            {
                double percentage = (double)job_counts[i] / total * 100;//计算比例
                printf("%-30s %6d %10.2f%%\n", job_majors[i], job_counts[i], percentage);
                displayed_total += job_counts[i];//累计已显示人数
            }
        }
        
        // 如果有未填写从事专业的情况
        if (displayed_total < total) 
        {
            int unspecified_count = total - displayed_total;//计算未填写人数
            double percentage = (double)unspecified_count / total * 100;
            printf("%-30s %6d %10.2f%%\n", "(未填写/未知)", unspecified_count, percentage);
        }
        
        printf("────────────────────────────────────────────────\n");
        printf("%-30s %6d %10.2f%%\n", "总计", total, 100.0);
    }
    
    printf("════════════════════════════════════════════════\n");
    waitEnter();
}