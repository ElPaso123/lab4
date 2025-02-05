﻿#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "string.h"

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;
int n = 0;

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	if (data < r->data)
		CreateTree(r, r->right, data);
	if (data == r->data)
		
		

	return root;
}

void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf("  ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}


struct Node* find(struct Node* root, int data) {
	if (root->data == data)
	{
		printf("Элемент найден\n");
	}
	else if (root->data > data && root->right != NULL)
	{
		find(root->right, data);
	}
	else if (root->data < data && root->left != NULL)
	{
		find(root->left, data);
	}
	else printf("Нет\n");
	return 0;
}

int count(struct Node* root, int data, int cnt) {
	if (root->data == data) cnt++;

	if (root->data >= data && root->right != NULL) cnt = count(root->right, data, cnt);
	else if (root->left != NULL) cnt = count(root->left, data, cnt);
	else return cnt;
}

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	int num = 0;
	root = NULL;
	n = 0;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);
	printf("Введите число которое нужно найти:");
	scanf_s("%d", &num);
	find(root, num);
	n = count(root, num, n);
	printf("Кол-во элементов %d равно %d\n", num, n);


	scanf_s("%d", &D);
	return 0;
}

