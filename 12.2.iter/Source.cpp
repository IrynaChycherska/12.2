#include <iostream>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
int Count(Elem*& first)
{
	Elem* tmp = first->link->link; // 1
	delete first->link; // 2
	first->link = tmp; // 3
	int k = 0;
	while (first != NULL)
	{
		k++;
		first = first->link;
	}
	return k;
}

int main()
{
	Elem* first = NULL,
		* last = NULL;
	// ��������� �����
	for (int i = 1; i <= 10; i++)
		enqueue(first, last, i);
	// ��������� �� ���� ��������
	while (first != NULL)
		cout << dequeue(first, last) << " ";
	cout << Count(first) << endl;
	cout << endl;
	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

Info dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}