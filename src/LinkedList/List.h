#pragma once
#include "ListItem.h"

/// <summary>
/// ����� List ��������� ���������� ������ ��� ��������� ���� double.
/// </summary>
class List {
private:
    /// <summary>
    /// ������ ������
    /// </summary>
    ListItem* head;

    /// <summary>
    /// ����� ������
    /// </summary>
    ListItem* tail;

    /// <summary>
    /// ������ ������
    /// </summary>
    int size;

public:
    /// <summary>
    /// ����������� ��� ����������
    /// </summary>
    List();

    /// <summary>
    /// ����������
    /// </summary>
    ~List();

    /// <summary>
    /// ������ ������
    /// </summary>
    int GetSize();

    /// <summary>
    /// ���������, ���� �� ������
    /// </summary>
    bool IsEmpty();

    /// <summary>
    /// ���������� �������� � ����� ������
    /// </summary>
    /// <param name="value">�������� ��� ����������</param>
    void AddElement(double value);

    /// <summary>
    /// �������� �������� �� ��������
    /// </summary>
    /// <param name="value">�������� ��� ��������</param>
    void RemoveElement(double value);

    /// <summary>
    /// ������� �������� � ������ ������
    /// </summary>
    /// <param name="value">�������� ��� �������</param>
    void InsertAtBeginning(double value);

    /// <summary>
    /// ������� �������� ����� ������� ���������� �� ��������
    /// </summary>
    /// <param name="afterValue">��������, ����� �������� ��������</param>
    /// <param name="newValue">����� ��������</param>
    void InsertAfter(double afterValue, double newValue);

    /// <summary>
    /// ��������� ������� ����� ������ ��������� �� ��������
    /// </summary>
    /// <param name="beforeValue">��������, ����� ������� ��������</param>
    /// <param name="newValue">����� ��������</param>
    void InsertBefore(double beforeValue, double newValue);

    /// <summary>
    /// ���������� 
    /// </summary>
    void Sort();

    /// <summary>
    /// �������� ����� �� ��������
    /// </summary>
    /// <param name="value">�������� ��� ������</param>
    int LinearSearch(double value);

    /// <summary>
    /// ����� ������
    /// </summary>
    void PrintList();
};