#include "List.h"
#include <iostream>

#define BOLD "\033[1m"
#define RESET "\033[0m"

using namespace std;

/// <summary>
/// Очищает экран консоли
/// </summary>
void ClearScreen()
{
    system("cls");
}

/// <summary>
/// Ожидает нажатия клавиши Enter для продолжения
/// </summary>
void PressAnyKeyToContinue()
{
    cout << endl << "Нажмите Enter для продолжения...";
    cin.ignore(10000, '\n');
    cin.get();
}

/// <summary>
/// Считывние double с консоли
/// </summary>
double GetDoubleInput(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cout << "Ошибка: Неверный ввод. Пожалуйста, введите число." << endl;
        return -1.0;
    }
    return value;
}

/// <summary>
/// Отображает главное меню программы
/// </summary>
void DisplayMenu(List& list)
{
    cout << BOLD << "Лабораторная работа #2 - Двусвязный список" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;
    cout << BOLD << "Выберите действие:" << RESET << endl;
    cout << "1. Добавить элемент" << endl;
    cout << "2. Удалить элемент" << endl;
    cout << "3. Вставить элемент в начало" << endl;
    cout << "4. Вставить после определенного элемента" << endl;
    cout << "5. Вставить перед определенным элементом" << endl;
    cout << "6. Сортировка списка" << endl;
    cout << "7. Линейный поиск элемента в списке" << endl;
    cout << endl << "Выберите действие > ";
}

/// <summary>
/// Меню добавления элемента
/// </summary>
/// <param name="list">Ссылка на двусвязный список</param>
void AddElementMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "Добавление элемента" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("Введите значение для добавления: ");
    if (value != -1.0)
    {
        list.AddElement(value);
        cout << "Элемент добавлен." << endl;
    }
}

/// <summary>
/// Меню удаления элемента
/// </summary>
/// <param name="list">Ссылка на двусвязный список</param>
void RemoveElementMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "Удаление элемента" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("Введите значение для удаления: ");
    if (value != -1.0)
    {
        list.RemoveElement(value);
    }
}

/// <summary>
/// Меню вставки элемента в начало
/// </summary>
/// <param name="list">Ссылка на двусвязный список</param>
void InsertAtBeginningMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "Вставка элемента в начало" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("Введите значение для вставки в начало: ");
    if (value != -1.0)
    {
        list.InsertAtBeginning(value);
        cout << "Элемент вставлен." << endl;
    }
}

/// <summary>
/// Меню вставки элемента после указанного
/// </summary>
/// <param name="list">Ссылка на двусвязный список</param>
void InsertAfterMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "Вставка после определенного элемента" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;

    double afterValue = GetDoubleInput("Введите значение, после которого вставить: ");
    if (afterValue == -1.0)
    {
        return;
    }

    double newValue = GetDoubleInput("Введите новое значение: ");
    if (newValue == -1.0)
    {
        return;
    }

    list.InsertAfter(afterValue, newValue);
    cout << "Элемент вставлен." << endl;
}

/// <summary>
/// Меню вставки элемента перед указанным
/// </summary>
/// <param name="list">Ссылка на двусвязный список</param>
void InsertBeforeMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "Вставка перед определенным элементом" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;

    double beforeValue = GetDoubleInput("Введите значение, перед которым вставить: ");
    if (beforeValue == -1.0)
    {
        return;
    }

    double newValue = GetDoubleInput("Введите новое значение: ");
    if (newValue == -1.0)
    {
        return;
    }

    list.InsertBefore(beforeValue, newValue);
    cout << "Элемент вставлен." << endl;
}

/// <summary>
/// Меню сортировки списка
/// </summary>
/// <param name="list">Ссылка на двусвязный список</param>
void SortMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "Сортировка списка" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;

    list.Sort();
    cout << "Список отсортирован." << endl;
    cout << "Отсортированный список: ";
    list.PrintList();
    cout << endl;
}

/// <summary>
/// Меню линейного поиска
/// </summary>
/// <param name="list">Ссылка на двусвязный список</param>
void LinearSearchMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "Линейный поиск элемента в списке" << RESET << endl;
    cout << "Текущий список: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("Введите значение для поиска: ");
    if (value != -1.0)
    {
        int index = list.LinearSearch(value);
        if (index == -1)
        {
            cout << "Значение не найдено." << endl;

        }
    }
}

int main()
{
    List list;
    setlocale(LC_ALL, "Ru");

    list.AddElement(1.0);
    list.AddElement(32.0);
    list.AddElement(8.0);
    list.AddElement(255.0);

    int choice;

    while (true)
    {
        ClearScreen();
        DisplayMenu(list);

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            PressAnyKeyToContinue();
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
            AddElementMenu(list);
            PressAnyKeyToContinue();
            break;
        case 2:
            RemoveElementMenu(list);
            PressAnyKeyToContinue();
            break;
        case 3:
            InsertAtBeginningMenu(list);
            PressAnyKeyToContinue();
            break;
        case 4:
            InsertAfterMenu(list);
            PressAnyKeyToContinue();
            break;
        case 5:
            InsertBeforeMenu(list);
            PressAnyKeyToContinue();
            break;
        case 6:
            SortMenu(list);
            PressAnyKeyToContinue();
            break;
        case 7:
            LinearSearchMenu(list);
            PressAnyKeyToContinue();
            break;
        default:
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            PressAnyKeyToContinue();
            break;
        }
    }
}
