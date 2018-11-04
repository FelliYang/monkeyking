//猴王问题求解
#include<stdio.h>
#include<stdlib.h>

//define数据结构
//------------****-----------使用链表的情况
typedef struct node {
	struct node * front;
	int number;
	struct node * next;
}monkey,*monkey_roll;
//------------------使用数组的情况
typedef struct node2 {
	int front;
	int number;
	int next;
}monkey2,*monkey_roll2;

void find_king(int, int);
void find_king2(int, int);


int main(void)
{
	int m, n;
	printf("please input n and m;\n");
	scanf("%d%d", &n, &m);
	find_king(n, m);
	find_king2(n, m);
	getchar();
	getchar();
	return 0;

}

void find_king(int n, int m)
{
	if (n == 1) 
	{
		printf("猴王是1");
		return;
	}
	else if (n == 2)
	{
		if (m % 2 == 0)
			printf("猴王是1");
		else printf("猴王是2");
		return;
	}
	else {
		monkey_roll L;
		int remain = n;
		L = (monkey_roll)malloc(n * sizeof(monkey));
		monkey_roll first = L;
		//初始化这个双链表
		for (int i = 1; i < remain - 1; i++)
		{
			L[i].front = &L[i - 1];
			L[i].next = &L[i + 1];
			L[i].number = i + 1;

		}
		L[0].front = &L[remain - 1];
		L[0].next = &L[1];
		L[remain - 1].next = &L[0];
		L[remain - 1].front = &L[remain - 2];
		L[0].number = 1;
		L[remain - 1].number = remain;
		//初始化位循环双链表

		while (remain != 2)
		{
			for (int j = 0; j < m - 2; j++)
			{
				L = L->next;
			}
			monkey_roll p = L->next;
			L->next = p->next;
			p->next->front = L;
			remain--;
			L = L->next;
		}
		if (m % 2 == 0)
			printf("猴王是%d\n", L->number);
		else printf("猴王是%d\n", L->next->number);
		free(first);
	}
}
void find_king2(int n, int m)
{
	if (n == 1)
	{
		printf("猴王是1");
		return;
	}
	else if (n == 2)
	{
		if (m % 2 == 0)
			printf("猴王是1");
		else printf("猴王是2");
		return;
	}
	else {
		monkey_roll2 L;
		int remain = n;
		int account = 0;
		L = (monkey_roll2)malloc(n * sizeof(monkey));
		monkey_roll2 first = L;
		//初始化数组
		for (int i = 0; i < remain; i++)
		{
			L[i].number = i + 1;
		}
		for (int i = 1; i < remain - 1; i++)
		{
			L[i].front = L[i - 1].number;
			L[i].next = L[i + 1].number;
		}
		L[0].front = n;
		L[0].next = 2;
		L[remain - 1].front = n - 1;
		L[remain - 1].next = 1;
		//
		//for (int i = 0; i < remain; i++)
		{
		}
		while (remain != 2)
		{
			for (int j = 0; j < m - 2; j++)
			{
				L = &first[L->next - 1];
			}
			monkey_roll2 p = &first[L->next - 1];
			first[p->front - 1].next = p->next;
			first[p->next - 1].front = p->front;
			remain--;
			L = &first[L->next - 1];
		}
		if (m % 2 == 0)
			printf("猴王是%d", L->number);
		else printf("猴王是%d", first[L->next - 1].number);
		free(first);
	}

}

