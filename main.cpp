#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* root;
int count = 0;
int level = 0;

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	int c = -1;
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
	if (data == r->data) {
		printf("Это значение уже есть в дереве\n");
		printf("1 - всё равно добавить, 2 - продолжить : ");
		scanf("%d", &c);
		if (c == 1)
			;
		else
			return NULL;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

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
		printf("\t");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}


void search(struct Node* r, int num) {
	
	if (root == NULL) {
		printf("Дерева нет");
		return;
	}

	if (r != NULL) {

		if (num == r->data) {
			count++;
			return;
		}

		if (num <= r->data) {
			level++;
			search(r->right, num);
		}
		else {
			level++;
			search(r->left, num);
		}
	}
	return;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int D, start = 1;
	int n;
	root = NULL;
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

	printf("Введите значение для поиска: ");
	scanf("%d", &n);

	search(root, n);

	printf("Число %d найдено %d раз   ур - %d\n", n, count, level);
	system("pause");
	return 0;
}
