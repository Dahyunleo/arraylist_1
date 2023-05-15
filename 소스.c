#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}
// 리스트 출력
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
		error("위치 오류");
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
	// ArrayListType를 정적으로 생성하고 ArrayListType를
	// 가리키는 포인터를 함수의 매개변수로 전달한다. 
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
//Insrt 하기
	}
	if (sn == 2) {
		if (is_empty(&list)) {
			printf("List is empty");
			print_menu();
			printf("Enter the menu: ");
			scanf(" %d", &sn);
		}
		//delete 하기
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
	insert(&list, 0, 10); print_list(&list); // 0번째 위치에 10 추가
	insert(&list, 0, 20); print_list(&list); // 0번째 위치에 20 추가
	insert(&list, 0, 30); print_list(&list); // 0번째 위치에 30 추가
	
	delete(&list, 0); print_list(&list); // 0번째 항목 삭제
	return 0;
	
}