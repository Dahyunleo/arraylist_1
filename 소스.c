#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element; // �׸��� ����
typedef struct {
	element array[MAX_LIST_SIZE]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L)
{
	L->size = 0;
}
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// ����Ʈ�� ���� �� ������ 1�� ��ȯ
// �׷��� ������ 1�� ��ȯ
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}
// ����Ʈ ���
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
element delete(ArrayListType* L, int pos)
{
	element item;
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}
int print_menu() {
	
	printf("Menu\n");
	printf("(1) Insert\n");
	printf("(2) Delete\n");
	printf("(3) Print\n");
	printf("(0) Exit\n");
	
	
}
int main(void)
{
	// ArrayListType�� �������� �����ϰ� ArrayListType��
	// ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�. 
	//print_menu();//
	ArrayListType list;
	int sn;
	int a, b;
	print_menu();
	printf("Enter the menu: ");
	scanf(" %d", &sn);
	
	if (sn == 1) {
		if (is_full(&list))
		{
			printf("List is full");
			print_menu();
			printf("Enter the menu: ");
			scanf(" %d", &sn);
		}
		printf("Enter the number and position:");
		scanf("%d, %d", &a, &b);
//Insrt �ϱ�
	}
	if (sn == 2) {
		if (is_empty(&list)) {
			printf("List is empty");
			print_menu();
			printf("Enter the menu: ");
			scanf(" %d", &sn);
		}
		//delete �ϱ�
	}
	if (sn > 3 || sn < 0) {
		printf("Invalid Menu. Please select again");
		print_menu();
		printf("Enter the menu: ");
		scanf(" %d", &sn);
	}
	if (sn == 0) {
		printf("Exit the program.\n");
	}
	init(&list);
	insert(&list, 0, 10); print_list(&list); // 0��° ��ġ�� 10 �߰�
	insert(&list, 0, 20); print_list(&list); // 0��° ��ġ�� 20 �߰�
	insert(&list, 0, 30); print_list(&list); // 0��° ��ġ�� 30 �߰�
	
	delete(&list, 0); print_list(&list); // 0��° �׸� ����
	return 0;
	
}