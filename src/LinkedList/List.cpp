#include "List.h"
#include <iostream>

using namespace std;

/// <summary>
/// Конструктор
/// </summary>
List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/// <summary>
/// Деструктор
/// </summary>
List::~List() 
{
    ListItem* current = head;
    while (current != nullptr) 
    {
        ListItem* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/// <summary>
/// Размер списка
/// </summary>
int List::GetSize() 
{
    return size;
}

/// <summary>
/// Проверяет, пуст ли список
/// </summary>
bool List::IsEmpty() 
{
    return size == 0;
}

/// <summary>
/// Добавление элемента в конец
/// </summary>
void List::AddElement(double value) 
{
    ListItem* newItem = new ListItem(value);
    if (IsEmpty()) 
    {
        head = tail = newItem;
    }
    else 
    {
        tail->next = newItem;
        newItem->prev = tail;
        tail = newItem;
    }
    size++;
}

/// <summary>
/// Удаление всех элементов с заданным значением
/// </summary>
/// inheritdoc
void List::RemoveElement(double value) 
{
    if (IsEmpty()) 
    {
        cout << "Ошибка: список пуст, удаление невозможно." << endl;
        return;
    }

    int count = 0;

    for (ListItem* current = head; current != nullptr;) 
    {
        ListItem* next = current->next;
        if (current->data == value) 
        {
            if (current->prev != nullptr) 
            {
                current->prev->next = current->next;
            }
            else 
            {
                head = current->next;
            }

            if (current->next != nullptr) 
            {
                current->next->prev = current->prev;
            }
            else 
            {
                tail = current->prev;
            }
            delete current;
            size--;
            count++;
        }
        current = next;
    }

    if (count > 0) 
    {
        cout << "Удалено " << count << " элементов со значением " << value << "." << endl;
    }
    else 
    {
        cout << "Ошибка: значение " << value << " не найдено." << endl;
    }
}

/// <summary>
/// Вставка элемента в начало
/// </summary>
void List::InsertAtBeginning(double value) 
{
    ListItem* newItem = new ListItem(value);
    if (IsEmpty()) 
    {
        head = tail = newItem;
    }
    else 
    {
        newItem->next = head;
        head->prev = newItem;
        head = newItem;
    }
    size++;
}

/// <summary>
/// Вставляет элемент после первого найденного элемента
/// </summary>
void List::InsertAfter(double afterValue, double newValue) 
{
    if (IsEmpty()) 
    {
        cout << "Ошибка: список пуст, вставка невозможна." << endl;
        return;
    }

    for (ListItem* current = head; current != nullptr; current = current->next) 
    {
        if (current->data == afterValue) 
        {
            ListItem* newItem = new ListItem(newValue);

            newItem->prev = current;
            newItem->next = current->next;

            if (current->next != nullptr) 
            {
                current->next->prev = newItem;
            }
            else 
            {
                tail = newItem;
            }

            current->next = newItem;
            size++;
            return;
        }
    }

    cout << "Ошибка: значение не найдено." << endl;
}

/// <summary>
/// Вставляет элемент перед первым найденным элементов
/// </summary>
void List::InsertBefore(double beforeValue, double newValue) 
{
    if (IsEmpty()) 
    {
        cout << "Ошибка: список пуст, вставка невозможна." << endl;
        return;
    }

    for (ListItem* current = head; current != nullptr; current = current->next) 
    {
        if (current->data == beforeValue) 
        {
            ListItem* newItem = new ListItem(newValue);

            newItem->next = current;
            newItem->prev = current->prev;

            if (current->prev != nullptr) {

                current->prev->next = newItem;
            }
            else 
            {
                head = newItem;
            }

            current->prev = newItem;
            size++;
            return;
        }
    }
    cout << "Ошибка: значение не найдено." << endl;
}

/// <summary>
/// Сортировка
/// </summary>
void List::Sort() 
{
    if (size < 2) 
    {
        return;
    }

    for (int pass = 0; pass < size - 1; pass++) 
    {
        for (ListItem* current = head; current->next != nullptr; current = current->next) 
        {
            if (current->data > current->next->data) 
            {
                double temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }
    }
}


/// <summary>
/// Линейный поиск всех вхождений
/// </summary>
int List::LinearSearch(double value)
{
    if (IsEmpty())
    {
        cout << "Список пуст." << endl;
        return -1;
    }

    int foundCount = 0;
    int position = 0;

    cout << "Найденные позиции: ";

    for (ListItem* current = head; current != nullptr; current = current->next)
    {
        if (current->data == value)
        {
            cout << position + 1;
            foundCount++;

            if (current->next != nullptr) 
            {
                cout << ", ";
            }
        }
        position++;
    }

    if (foundCount == 0) 
    {
        cout << "не найдены";
    }

    cout << endl;
    return foundCount;
}

/// <summary>
/// Вывод списка
/// </summary>
void List::PrintList() 
{
    if (IsEmpty()) 
    {
        cout << "Список пуст." << endl;
        return;
    }

    ListItem* current = head;
    while (current != nullptr) 
    {
        cout << "[" << current->data << "]";
        if (current->next != nullptr) 
        {
            cout << " - ";
        }
        current = current->next;
    }
    cout << endl;
}