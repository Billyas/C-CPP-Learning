#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX 1000
int k = 0;

//结构体类型
typedef struct
{
    char name[20];   //姓名
    char sex[5];     //性别
    char classs[20]; //班级
    int number;      //学号
    int age;         //年龄
    int dorm;        //宿舍号
    int year;        //年份
    int month;       //月份
} students;

//创建学生宿舍信息
int establish(students stu[])
{
    int i, x;
    for (i = 0; i < 1000; i++)
    {
        system("cls");
        printf("\n\n                 录入学生信息  (最多%d个)\n", MAX);
        printf("               ----------------------------\n");

        printf("\n                     第%d个学生", k + 1);
        printf("\n 请输入学生的学号:");
        scanf("%d", &stu[k].number);
        printf("\n 请输入学生的姓名:");
        scanf("%s", stu[k].name);
        printf("\n 请输入学生的性别:");
        scanf("%s", stu[k].sex);
        printf("\n 请输入学生的年龄:");
        scanf("%d", &stu[k].age);
        printf("\n 请输入学生的班级:");
        scanf("%s", stu[k].classs);
        printf("\n 请输入学生入住时间(如:2017 9):");
        while ((scanf("%d %d", &stu[k].year, &stu[k].month)) != EOF)
        {
            if (stu[k].year < 1000 || stu[k].year > 9999 || stu[k].month > 12 || stu[k].month < 1) //限定输入范围
            {
                printf("对不起，输入错误，请重新输入:");
            }
            else
                break;
        }
        printf("\n 请输入学生的宿舍号:");
        scanf("%d", &stu[k++].dorm);
        printf("\n 请按 1 键返回主菜单或按 0 键继续创建：");
        scanf("%d", &x);
        if (x != 0)
            break;
    }
    return k;
}

//显示学生宿舍信息
void display(students stu[])
{

    int i;
    for (i = 0; i < k; i++)
    {
        printf("学号：%d  姓名：%s  性别：%s  年龄：%d  班级：%s  宿舍号: %d  入住时间：%d/%d\n", stu[i].number, stu[i].name, stu[i].sex, stu[i].age, stu[i].classs, stu[i].dorm, stu[i].year, stu[i].month);
    }
    printf("按任意键返回主菜单!");
    getch();
    system("cls");
    return;
}

//查询学生宿舍信息
void query(students stu[])
{
    int i, m = 0;
    int number;
    printf("\n\n      请输入您要查找的学生的学号: ");
    scanf("%d", &number);
    printf("     正在查询，请稍后.....\n");
    Sleep(1000);
    for (i = 0; i < k; i++)
    {
        if (number == stu[i].number)
        {
            printf("\n\n学号：%d  姓名：%s  性别：%s  年龄：%d  班级：%s  宿舍号: %d  入住时间：%d/%d\n", stu[i].number, stu[i].name, stu[i].sex, stu[i].age, stu[i].classs, stu[i].dorm, stu[i].year, stu[i].month);
            m = 1;
        }
    }
    if (m == 0)
    {
        printf("对不起，此学生信息不存在!\n");
    }
    printf("按任意键返回主菜单!");
    getch();
    system("cls");
    return;
}

//修改学生信息
void modify(students stu[])
{
    int number, i, choose, m = 0;
    system("cls");
    printf("\n\n\n      请输入您要修改的学生的学号：");
    scanf("%d", &number);
    printf("      正在查询，请稍后.....\n");
    Sleep(1000);
    for (i = 0; i < k; i++)
    {
        if (number == stu[i].number)
        {
            printf("\n\n学号：%d  姓名：%s  性别：%s  年龄：%d  班级：%s  宿舍号: %d  入住时间：%d/%d\n", stu[i].number, stu[i].name, stu[i].sex, stu[i].age, stu[i].classs, stu[i].dorm, stu[i].year, stu[i].month);

            printf("\n\n     ********请输入您想要修改的数据********\n\n");
            printf("                1. 学号\n");
            printf("                2. 姓名\n");
            printf("                3. 性别\n");
            printf("                4. 年龄\n");
            printf("                5. 班级\n");
            printf("                6. 宿舍号\n");
            printf("                7. 入住时间\n\n");
            printf("                请选择(1-7):");

            while ((scanf("%d", &choose)) != EOF)
            {
                if (choose < 1 || choose > 7)
                {
                    printf("对不起，输入错误，请重新输入：");
                }
                else
                {
                    switch (choose)
                    {
                    case 1:
                    {
                        printf("\n   请输入你改的新学号：");
                        scanf("%d", &stu[i].number);
                        break;
                    }
                    case 2:
                    {
                        printf("\n   请输入你改的新姓名：");
                        scanf("%s", stu[i].name);
                        break;
                    }
                    case 3:
                    {
                        printf("\n   请输入你改的新性别：");
                        scanf("%s", stu[i].sex);
                        break;
                    }
                    case 4:
                    {
                        printf("\n   请输入你改的新年龄：");
                        scanf("%d", &stu[i].age);
                        break;
                    }
                    case 5:
                    {
                        printf("\n   请输入你改的新班级：");
                        scanf("%s", stu[i].classs);
                        break;
                    }
                    case 6:
                    {
                        printf("\n   请输入你改的新宿舍：");
                        scanf("%d", &stu[i].dorm);
                        break;
                    }
                    case 7:
                    {
                        printf("\n   请输入你改的新入住时间：");
                        scanf("%d %d", &stu[i].year, &stu[i].month);
                        break;
                    }
                    }
                    printf("修改成功!");
                    Sleep(500);
                    printf("\n\n学号：%d  姓名：%s  性别：%s  年龄：%d  班级：%s  宿舍号: %d  入住时间：%d/%d\n", stu[i].number, stu[i].name, stu[i].sex, stu[i].age, stu[i].classs, stu[i].dorm, stu[i].year, stu[i].month);
                    m = 1;
                    break;
                }
            }
        }
    }
    if (m == 0)
    {
        printf("对不起，此学生信息不存在!\n");
    }
    printf("按任意键返回主菜单!");
    getch();
    return;
}

//删除学生信息
void deletee(students stu[])
{

    char name1[20];
    int i, j, m = 0;

    printf("请输入学生姓名：");
    scanf("%s", name1);
    printf("\n");
    printf("正在查找是否存在此学生信息.....\n");
    Sleep(1000);
    for (i = 0; i < k; i++)
    {
        if (strcmp(stu[i].name, name1) == 0)
        {
            m = 1;
            printf("已找到此学生信息!\n删除中....\n");
            Sleep(2000);
            for (j = i; j < k; j++)
            {
                strcpy(stu[j].name, stu[j + 1].name);
                strcpy(stu[j].sex, stu[j + 1].sex);
                strcpy(stu[j].classs, stu[j + 1].classs);
                stu[j].age = stu[j + 1].age;
                stu[j].dorm = stu[j + 1].dorm;
                stu[j].number = stu[j + 1].number;
                stu[j].year = stu[j + 1].year;
                stu[j].month = stu[j + 1].month;
            }
            k--;
            printf("删除成功!\n");
        }
    }
    if (m == 0)
    {
        printf("此学生信息不存在!\n");
    }
    printf("按任意键返回主菜单!");
    getch();
    system("cls");
    return;
}

//保存学生住宿信息
void preservation(students stu[])
{
    int i;
    FILE *fp;

    if ((fp = fopen("学生宿舍信息.txt", "w")) == NULL)
    {
        printf("未发现学生宿舍信息!\n");
        printf("按任意键返回...\n");
        getch();
        system("cls");
        return;
    }
    else
    {
        for (i = 0; i < k; i++)
        {
            fprintf(fp, "\n\n学号：%d  姓名：%s  性别：%s  年龄：%d  班级：%s  宿舍号: %d  入住时间：%d/%d\n", stu[i].number, stu[i].name, stu[i].sex, stu[i].age, stu[i].classs, stu[i].dorm, stu[i].year, stu[i].month);
        }
        fclose(fp);
        printf("正在保存文件....\n");
        Sleep(1000);
        printf("文件保存成功!\n");
        printf("按任意键返回...\n");
        getch();
        system("cls");
        return;
    }
}
//读取学生住宿信息
void read(students stu[])
{
    FILE *fp;
    char ch;
    if ((fp = fopen("学生宿舍信息.txt", "r")) == NULL)
    {
        printf("文件无法打开!\n");
        exit(0);
    }
    printf("正在读入文件...\n");
    Sleep(1000);
    printf("文件读入成功!\n");
    ch = fgetc(fp);
    while (!feof(fp))
    {
        putchar(ch);
        ch = fgetc(fp);
    }
    printf("\n");
    fclose(fp);
    printf("按任意键返回...\n");
    getch();
    system("cls");
    return;
}

void title()
{
    printf(" \n\n\n                   **********************************\n");
    printf("                   *                                *\n");
    printf("                   *                                *\n");
    printf("                   *                                *\n");
    printf("                   *  欢迎进入学生宿舍信息管理系统  *\n");
    printf("                   *                                *\n");
    printf("                   *                                *\n");
    printf("                   *                                *\n");
    printf("                   **********************************\n");
    printf("\n                   按任意键进入系统！\n");
    getchar();
}

void start()
{
    students stu[20];
    int choose, k;
    while (choose != 0)
    {
        system("cls");
        printf("\n\n\n               ********学生宿舍信息管理系统********\n\n");
        printf("                      1. 创建学生宿舍信息\n\n");
        printf("                      2. 显示学生宿舍信息\n\n");
        printf("                      3. 查询学生宿舍信息\n\n");
        printf("                      4. 修改学生宿舍信息\n\n");
        printf("                      5. 删除学生宿舍信息\n\n");
        printf("                      6. 保存学生宿舍信息\n\n");
        printf("                      7. 读取学生宿舍信息\n\n");
        printf("                      0. 退出系统\n\n");
        printf("                       请选择（0-7）:");

        while ((scanf("%d", &choose)) != EOF)
        {
            if (choose < 0 || choose > 7)
            {
                printf("对不起，输入错误，请重新输入：");
            }
            else
            {
                switch (choose)
                {
                case 1:
                    k = establish(stu);
                    break; //创建学生宿舍信息
                case 2:
                    display(stu);
                    break; //显示学生宿舍信息
                case 3:
                    query(stu);
                    break; //查询学生宿舍信息
                case 4:
                    modify(stu);
                    break; //修改学生宿舍信息
                case 5:
                    deletee(stu);
                    break; //删除学生宿舍信息
                case 6:
                    preservation(stu);
                    break; //保存学生宿舍信息
                case 7:
                    read(stu);
                    break; //读取学生宿舍信息
                case 0:
                    break;
                }
                break;
            }
        }
    }
}
int main()
{
    title();
    start();
    system("pause");
    return 0;
}