#include "List.h"
#include <iostream>

#define BOLD "\033[1m"
#define RESET "\033[0m"

using namespace std;

/// <summary>
/// ������� ����� �������
/// </summary>
void ClearScreen()
{
    system("cls");
}

/// <summary>
/// ������� ������� ������� Enter ��� �����������
/// </summary>
void PressAnyKeyToContinue()
{
    cout << endl << "������� Enter ��� �����������...";
    cin.ignore(10000, '\n');
    cin.get();
}

/// <summary>
/// ��������� double � �������
/// </summary>
double GetDoubleInput(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cout << "������: �������� ����. ����������, ������� �����." << endl;
        return -1.0;
    }
    return value;
}

/// <summary>
/// ���������� ������� ���� ���������
/// </summary>
void DisplayMenu(List& list)
{
    cout << BOLD << "������������ ������ #2 - ���������� ������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;
    cout << BOLD << "�������� ��������:" << RESET << endl;
    cout << "1. �������� �������" << endl;
    cout << "2. ������� �������" << endl;
    cout << "3. �������� ������� � ������" << endl;
    cout << "4. �������� ����� ������������� ��������" << endl;
    cout << "5. �������� ����� ������������ ���������" << endl;
    cout << "6. ���������� ������" << endl;
    cout << "7. �������� ����� �������� � ������" << endl;
    cout << endl << "�������� �������� > ";
}

/// <summary>
/// ���� ���������� ��������
/// </summary>
/// <param name="list">������ �� ���������� ������</param>
void AddElementMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "���������� ��������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("������� �������� ��� ����������: ");
    if (value != -1.0)
    {
        list.AddElement(value);
        cout << "������� ��������." << endl;
    }
}

/// <summary>
/// ���� �������� ��������
/// </summary>
/// <param name="list">������ �� ���������� ������</param>
void RemoveElementMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "�������� ��������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("������� �������� ��� ��������: ");
    if (value != -1.0)
    {
        list.RemoveElement(value);
    }
}

/// <summary>
/// ���� ������� �������� � ������
/// </summary>
/// <param name="list">������ �� ���������� ������</param>
void InsertAtBeginningMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "������� �������� � ������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("������� �������� ��� ������� � ������: ");
    if (value != -1.0)
    {
        list.InsertAtBeginning(value);
        cout << "������� ��������." << endl;
    }
}

/// <summary>
/// ���� ������� �������� ����� ����������
/// </summary>
/// <param name="list">������ �� ���������� ������</param>
void InsertAfterMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "������� ����� ������������� ��������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;

    double afterValue = GetDoubleInput("������� ��������, ����� �������� ��������: ");
    if (afterValue == -1.0)
    {
        return;
    }

    double newValue = GetDoubleInput("������� ����� ��������: ");
    if (newValue == -1.0)
    {
        return;
    }

    list.InsertAfter(afterValue, newValue);
    cout << "������� ��������." << endl;
}

/// <summary>
/// ���� ������� �������� ����� ���������
/// </summary>
/// <param name="list">������ �� ���������� ������</param>
void InsertBeforeMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "������� ����� ������������ ���������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;

    double beforeValue = GetDoubleInput("������� ��������, ����� ������� ��������: ");
    if (beforeValue == -1.0)
    {
        return;
    }

    double newValue = GetDoubleInput("������� ����� ��������: ");
    if (newValue == -1.0)
    {
        return;
    }

    list.InsertBefore(beforeValue, newValue);
    cout << "������� ��������." << endl;
}

/// <summary>
/// ���� ���������� ������
/// </summary>
/// <param name="list">������ �� ���������� ������</param>
void SortMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "���������� ������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;

    list.Sort();
    cout << "������ ������������." << endl;
    cout << "��������������� ������: ";
    list.PrintList();
    cout << endl;
}

/// <summary>
/// ���� ��������� ������
/// </summary>
/// <param name="list">������ �� ���������� ������</param>
void LinearSearchMenu(List& list)
{
    ClearScreen();
    cout << BOLD << "�������� ����� �������� � ������" << RESET << endl;
    cout << "������� ������: ";
    list.PrintList();
    cout << endl << endl;

    double value = GetDoubleInput("������� �������� ��� ������: ");
    if (value != -1.0)
    {
        int index = list.LinearSearch(value);
        if (index == -1)
        {
            cout << "�������� �� �������." << endl;

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
            cout << "����������� �������. ���������� �����." << endl;
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
            cout << "����������� �������. ���������� �����." << endl;
            PressAnyKeyToContinue();
            break;
        }
    }
}
