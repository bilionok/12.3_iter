#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info; 

struct Elem
{
	Elem* next;
	Elem* prev;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void print(Elem* L);
void process(Elem* L, Info value);

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // забезпечення відображення кирилиці в консолі

	Elem* first = NULL,
		* last = NULL; 

	Info num;
	for (int i = 1; i <= 10; i++) {
		num = 1 + rand() % 10; 
		enqueue(first, last, num); 
	}
	cout << "Оригінальний список: " << endl << endl;
	print(first); // вивід черги
	cout << endl;

	Info info;
	cout << "Введіть значення інформаційного поля, яке буде продубльовано в списку: "; cin >> info;
	cout << endl;
	process(first, info); 

	print(first);

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void print(Elem* L) // функція виведення списку
{
	while (L != NULL) 
	{
		cout << L->info << " "; 
		L = L->next; 
	}
	cout << endl;
}

void process(Elem* L, Info value) // функція опрацювання списку
{
	while (L != NULL) 
	{
		if (L->info == value) 
		{
			Elem* tmp = new Elem;  
			tmp->info = value;  
			tmp->next = L->next; 
			L->next = tmp; 
			L = L->next; 
		}
		L = L->next; 
	}
}