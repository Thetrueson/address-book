#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct people
{
	char name[20];
	char sex[20];
	int age;
	char number[20];
	char address[20];
};
struct num
{
	struct people* a;
	int sz;
};
void a1(struct num* y)
{
	if (y->sz >= 3)
	{
		struct people* str = (struct people*)realloc(y->a, (y->sz + 1) * sizeof(struct people));
		if (str == NULL)
		{
			printf("无法添加");
			goto end;
		}
		else
		{
			y->a = str;
			printf("请输入姓名:>");
			scanf("%s", &y->a[y->sz].name);
			printf("请输入性别:>");
			scanf("%s", &y->a[y->sz].sex);
			printf("请输入年龄:>");
			scanf("%d", &y->a[y->sz].age);
			printf("请输入号码:>");
			scanf("%s", &y->a[y->sz].number);
			printf("请输入地址:>");
			scanf("%s", &y->a[y->sz].address);
			printf("添加成功!\n");
			y->sz++;
			goto end;
		}
	}
	printf("请输入姓名:>");
	scanf("%s", &y->a[y->sz].name);
	printf("请输入性别:>");
	scanf("%s", &y->a[y->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &y->a[y->sz].age);
	printf("请输入号码:>");
	scanf("%s", &y->a[y->sz].number);
	printf("请输入地址:>");
	scanf("%s", &y->a[y->sz].address);
	printf("添加成功!\n");
	y->sz++;
end:;
}
void a2(struct num* y)
{
	int i;
	int s = -1;
	char j[20];
	printf("请输入姓名:>");
start1:
	scanf("%s", &j);
	for (i = 0; i < y->sz; i++)
	{
		if (strcmp(j, y->a[i].name) == 0)
		{
			s = i;
			break;
		}
	}
	if (s == -1)
	{
		printf("查无此人\n");
		printf("请重新输入:>");
		goto start1;
	}
	for (i = 0; i < y->sz - s + 1; i++, s++)
	{
		y->a[s] = y->a[s + 1];
	}
	y->sz--;
	printf("删除成功！\n");
}
void a3(struct num* y)
{
	int i = 0;
	char j[20];
	int s = -1;
	printf("请输入姓名:>");
start:
	scanf("%s", &j);
	for (i = 0; i < y->sz; i++)
	{
		if (strcmp(j, y->a[i].name) == 0)
		{
			s = i;
			break;
		}
	}
	if (s == -1)
	{
		printf("查无此人\n");
		printf("请重新输入:>");
		goto start;
	}
	printf("请修改:>\n");
	printf("请输入姓名:>");
	scanf("%s", &y->a[s].name);
	printf("请输入性别:>");
	scanf("%s", &y->a[s].sex);
	printf("请输入年龄:>");
	scanf("%d", &y->a[s].age);
	printf("请输入号码:>");
	scanf("%s", &y->a[s].number);
	printf("请输入地址:>");
	scanf("%s", &y->a[s].address);
	printf("修改成功!");
}
void a4(struct num* y)
{
	int i = 0;
	char j[20];
	int s = -1;
	printf("请输入姓名:>");
	scanf("%s", &j);
	for (i = 0; i < y->sz; i++)
	{
		if (strcmp(j, y->a[i].name) == 0)
		{
			s = i;
			printf("找到了!\n");
			break;
		}
	}
	if (s == -1)
	{
		printf("查无此人!\n");
	}
}
void a5(struct num* y)
{
	struct people c = { 0 };
	int i;
	for (i = 0; i < y->sz; i++)
	{
		printf("%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "性别", "年龄", "号码", "地址");
		printf("%-5s\t%-5s\t%-5d\t%-15s\t%-20s\n", y->a[i].name,
			y->a[i].sex,
			y->a[i].age,
			y->a[i].number,
			y->a[i].address);
	}
	char a[20], b[20];
start1:
	printf("请输入交换人1姓名:>");
	scanf("%s", &a);
	int s1 = -1;
	for (i = 0; i < y->sz; i++)
	{
		if (strcmp(a, y->a[i].name) == 0)
		{
			s1 = i;
			break;
		}
	}
	if (s1 == -1)
	{
		printf("查无此人\n");
		printf("请重新输入:>");
		goto start1;
	}
start2:
	printf("请输入交换人2姓名:>");
	scanf("%s", &b);
	int s2 = -1;
	for (i = 0; i < y->sz; i++)
	{
		if (strcmp(b, y->a[i].name) == 0)
		{
			s2 = i;
			break;
		}
	}
	if (s2 == -1)
	{
		printf("查无此人\n");
		printf("请重新输入:>");
		goto start2;
	}
	c = y->a[s1];
	y->a[s1] = y->a[s2];
	y->a[s2] = c;
	printf("交换成功!\n");
}
void a6(struct num* y)
{
	int i;
	for (i = 0; i < y->sz; i++)
	{
		printf("%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "性别", "年龄", "号码", "地址");
		printf("%-5s\t%-5s\t%-5d\t%-15s\t%-20s\n", y->a[i].name,
			y->a[i].sex,
			y->a[i].age,
			y->a[i].number,
			y->a[i].address);
	}
}
void end(struct num* y)
{
	FILE* c = fopen("test.txt", "a");
	if (c == NULL)
	{
		perror(fopen);
		return;
	}
	int i = 0;
	for (i = 0; i < y->sz; i++)
	{
		fwrite(&y->a[i], sizeof(struct people), 1, c);
	}
	fclose(c);
	c = NULL;
	free(y->a);
	y->a = NULL;
}
int main(void)
{
	int sz = 0;
	struct people* a = (struct people*)calloc(3, sizeof(struct people));
	struct num b = { a, sz };
	FILE* e = fopen("test.txt", "w");
	fclose(e);
	e = NULL;
	FILE* d = fopen("test.txt", "r");
	if (d == NULL)
	{
		perror(fopen);
		return 1;
	}
	struct people per = { 0 };
	while (fread(&per, sizeof(struct people), 1, d))
	{
		if (b.sz >= 3)
		{
			struct people* ste = (struct people*)realloc(b.a, ((b.sz) + 1) * sizeof(struct people));
			if (ste == NULL)
			{
				printf("无法添加");
				goto end;
			}
			b.a = ste;
		}
		b.a[b.sz] = per;
		b.sz++;
	}
	fclose(d);
	d = NULL;
	while (1)
	{
		printf("通讯录\n");
		printf("1.添加联系人\n");
		printf("2.删除联系人\n");
		printf("3.修改联系人\n");
		printf("4.查找联系人\n");
		printf("5.排列联系人\n");
		printf("6.显示全部联系人\n");
		printf("0.退出\n");
		int x;
		printf("请输入:>");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			a1(&b);
			break;
		case 2:
			a2(&b);
			break;
		case 3:
			a3(&b);
			break;
		case 4:
			a4(&b);
			break;
		case 5:
			a5(&b);
			break;
		case 6:
			a6(&b);
			break;
		case 0:
			end(&b);
			goto end;
			break;
		default:
			printf("输入错误!");
			break;
		}
	}
end:;
	return 0;
}