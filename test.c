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
			printf("�޷����");
			goto end;
		}
		else
		{
			y->a = str;
			printf("����������:>");
			scanf("%s", &y->a[y->sz].name);
			printf("�������Ա�:>");
			scanf("%s", &y->a[y->sz].sex);
			printf("����������:>");
			scanf("%d", &y->a[y->sz].age);
			printf("���������:>");
			scanf("%s", &y->a[y->sz].number);
			printf("�������ַ:>");
			scanf("%s", &y->a[y->sz].address);
			printf("��ӳɹ�!\n");
			y->sz++;
			goto end;
		}
	}
	printf("����������:>");
	scanf("%s", &y->a[y->sz].name);
	printf("�������Ա�:>");
	scanf("%s", &y->a[y->sz].sex);
	printf("����������:>");
	scanf("%d", &y->a[y->sz].age);
	printf("���������:>");
	scanf("%s", &y->a[y->sz].number);
	printf("�������ַ:>");
	scanf("%s", &y->a[y->sz].address);
	printf("��ӳɹ�!\n");
	y->sz++;
end:;
}
void a2(struct num* y)
{
	int i;
	int s = -1;
	char j[20];
	printf("����������:>");
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
		printf("���޴���\n");
		printf("����������:>");
		goto start1;
	}
	for (i = 0; i < y->sz - s + 1; i++, s++)
	{
		y->a[s] = y->a[s + 1];
	}
	y->sz--;
	printf("ɾ���ɹ���\n");
}
void a3(struct num* y)
{
	int i = 0;
	char j[20];
	int s = -1;
	printf("����������:>");
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
		printf("���޴���\n");
		printf("����������:>");
		goto start;
	}
	printf("���޸�:>\n");
	printf("����������:>");
	scanf("%s", &y->a[s].name);
	printf("�������Ա�:>");
	scanf("%s", &y->a[s].sex);
	printf("����������:>");
	scanf("%d", &y->a[s].age);
	printf("���������:>");
	scanf("%s", &y->a[s].number);
	printf("�������ַ:>");
	scanf("%s", &y->a[s].address);
	printf("�޸ĳɹ�!");
}
void a4(struct num* y)
{
	int i = 0;
	char j[20];
	int s = -1;
	printf("����������:>");
	scanf("%s", &j);
	for (i = 0; i < y->sz; i++)
	{
		if (strcmp(j, y->a[i].name) == 0)
		{
			s = i;
			printf("�ҵ���!\n");
			break;
		}
	}
	if (s == -1)
	{
		printf("���޴���!\n");
	}
}
void a5(struct num* y)
{
	struct people c = { 0 };
	int i;
	for (i = 0; i < y->sz; i++)
	{
		printf("%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "����", "��ַ");
		printf("%-5s\t%-5s\t%-5d\t%-15s\t%-20s\n", y->a[i].name,
			y->a[i].sex,
			y->a[i].age,
			y->a[i].number,
			y->a[i].address);
	}
	char a[20], b[20];
start1:
	printf("�����뽻����1����:>");
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
		printf("���޴���\n");
		printf("����������:>");
		goto start1;
	}
start2:
	printf("�����뽻����2����:>");
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
		printf("���޴���\n");
		printf("����������:>");
		goto start2;
	}
	c = y->a[s1];
	y->a[s1] = y->a[s2];
	y->a[s2] = c;
	printf("�����ɹ�!\n");
}
void a6(struct num* y)
{
	int i;
	for (i = 0; i < y->sz; i++)
	{
		printf("%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "����", "��ַ");
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
				printf("�޷����");
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
		printf("ͨѶ¼\n");
		printf("1.�����ϵ��\n");
		printf("2.ɾ����ϵ��\n");
		printf("3.�޸���ϵ��\n");
		printf("4.������ϵ��\n");
		printf("5.������ϵ��\n");
		printf("6.��ʾȫ����ϵ��\n");
		printf("0.�˳�\n");
		int x;
		printf("������:>");
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
			printf("�������!");
			break;
		}
	}
end:;
	return 0;
}