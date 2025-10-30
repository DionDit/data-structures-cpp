#include <iostream>
#include "../Header Files/DynamicArray.h"

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
    cout << endl << "Press Enter to continue...";
    cin.ignore(10000, '\n');
    cin.get();
}

/// <summary>
/// Получает целочисленный ввод от пользователя
/// </summary>
/// <param name="prompt">Сообщение для пользователя</param>
/// <returns>Введенное число или -1 при ошибке</returns>
int GetIntegerInput(string prompt) 
{
    int value;
    cout << prompt;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cout << "Error: Invalid input. Please enter a number." << endl;
        return -1;
    }
    return value;
}
double GetDoubleInput(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cout << "Error: Invalid input. Please enter a number." << endl;
        return -1;
    }
    return value;
}

/// <summary>
/// Отображает главное меню программы
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void DisplayMenu(DynamicArray& array) 
{
    cout << BOLD << "Laboratory Work #1 - Dynamic Array" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;
    cout << BOLD << "Select the action you want to do:" << BOLD << endl;
    cout << "1. Remove an element by index from an array" << endl;
    cout << "2. Remove an element by value from an array" << endl;
    cout << "3. Insert an element at the beginning" << endl;
    cout << "4. Insert an element at the end" << endl;
    cout << "5. Insert after a certain element" << endl;
    cout << "6. Sort array" << endl;
    cout << "7. Linear search for an element in an array" << endl;
    cout << "8. Binary search for an element in an array" << endl;
    cout << endl << "Select action > ";
}

/// <summary>
/// Меню удаления элемента по индексу
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void RemoveByIndexMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Remove Element by Index" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    int index = GetIntegerInput("Enter index to remove: ");

    if (index != -1) 
    {
        array.RemoveByIndex(--index);
    }
}

/// <summary>
/// Меню удаления элемента по значению
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void RemoveByValueMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Remove Element by Value" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    double value = GetDoubleInput("Enter value to remove: ");

    if (value != -1) 
    {
        array.RemoveByValue(value);
    }
}

/// <summary>
/// Меню вставки элемента в начало массива
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void InsertAtBeginningMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Insert Element at Beginning" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    double value = GetDoubleInput("Enter value to insert at beginning: ");

    if (value != -1) 
    {
        array.InsertValueAtBeginning(value);
        cout << "Element inserted successfully." << endl;
    }
}

/// <summary>
/// Меню вставки элемента в конец массива
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void InsertAtEndMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Insert Element at End" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    double value = GetDoubleInput("Enter value to insert at end: ");
    if (value != -1) 
    {
        array.InsertValueAtEnd(value);
        cout << "Element inserted successfully." << endl;
    }
}

/// <summary>
/// Меню вставки элемента после указанного значения
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void InsertAfterValueMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Insert After Value" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    double afterValue = GetDoubleInput("Enter value after which to insert: ");
    if (afterValue == -1) 
    {
        return;
    }

    double newValue = GetDoubleInput("Enter new value to insert: ");
    if (newValue == -1)
    {
        return;
    }

    array.InsertAfterValue(afterValue, newValue);
}

/// <summary>
/// Меню сортировки массива
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void SortArrayMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Sort Array" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    array.SortArray();
    cout << "Array sorted successfully." << endl;
    cout << "Sorted array: ";
    array.PrintArray();
    cout << endl;
}

/// <summary>
/// Меню линейного поиска элемента
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void LinearSearchMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Linear Search" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    double value = GetDoubleInput("Enter value to search: ");
    if (value != -1) 
    {
        int index = array.LinearSearch(value);
        if (index == -1) 
        {
            cout << "Value not found in array." << endl;
        }
    }
}

/// <summary>
/// Меню бинарного поиска элемента
/// </summary>
/// <param name="array">Ссылка на динамический массив</param>
void BinarySearchMenu(DynamicArray& array) 
{
    ClearScreen();
    cout << BOLD << "Binary Search" << RESET << endl;
    cout << "Current array: ";
    array.PrintArray();
    cout << endl << endl;

    SortArrayMenu(array);


    double value = GetDoubleInput("Enter value to search: ");
    if (value != -1)
    {
        array.BinarySearch(value);
    }
}


int main() 
{
    DynamicArray array;

    array.InsertValueAtEnd(1.5);
    array.InsertValueAtEnd(32);
    array.InsertValueAtEnd(8);
    array.InsertValueAtEnd(1.5);
    array.InsertValueAtEnd(255);
    array.InsertValueAtEnd(8);


    int choice;

    while (true) 
    {
        ClearScreen();
        DisplayMenu(array);

        cin >> choice;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Unknown command. Try entering the command again." << endl;
            PressAnyKeyToContinue();
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice)
        {
            case 1:
                RemoveByIndexMenu(array);
                PressAnyKeyToContinue();
                break;
            case 2:
                RemoveByValueMenu(array);
                PressAnyKeyToContinue();
                break;
            case 3:
                InsertAtBeginningMenu(array);
                PressAnyKeyToContinue();
                break;
            case 4:
                InsertAtEndMenu(array);
                PressAnyKeyToContinue();
                break;
            case 5:
                InsertAfterValueMenu(array);
                PressAnyKeyToContinue();
                break;
            case 6:
                SortArrayMenu(array);
                PressAnyKeyToContinue();
                break;
            case 7:
                LinearSearchMenu(array);
                PressAnyKeyToContinue();
                break;
            case 8:
                BinarySearchMenu(array);
                PressAnyKeyToContinue();
                break;
            default:
                cout << "Unknown command. Try entering the command again." << endl;
                PressAnyKeyToContinue();
                break;
        }
    }
}

//Вариант 6:
// int Factorial(int n)
// {
//     if (n == 0)
//        {
//           return 1;
//        }
//     else
//        {
//           return n * Factorial(n - 1);
//        }
// }
//T(n) = O(n) => из-за n рекурсивных вызовов который О(1)
//M(n) = O(n) => из-за глубины стека вызовов n