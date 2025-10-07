#pragma once

/// <summary>
/// ����� DynamicArray ������������ ������������ ������ ��� �������� ��������� ���� double.
/// ������ ������������� �������� ���� ������ ��� ���������� ��� �������� ���������.
/// </summary>
class DynamicArray
{
private:
    /// <summary>
    /// ������� ���������� ��������� � �������
    /// </summary>
    int _size;

    /// <summary>
    /// ������� ������� �������
    /// </summary>
    int _capacity;

    /// <summary>
    /// ��������� �� ����������� ���������� ������ ���������
    /// </summary>
    double* _array;

    /// <summary>
    /// ����������� ����� �������
    /// </summary>
    int _growthFactor = 2;

    /// <summary>
    /// ��������� ������� ������� �� ���������
    /// </summary>
    int _initCapacity = 4;

    /// <summary>
    /// �������� ������� ������� �� ��������� ��������.
    /// </summary>
    void Resize(int newCapacity);

    /// <summary>
    /// ���������, �������� �� ������ ���������� ��� �������� �������.
    /// </summary>
    bool IsValidIndex(int index);

public:
    /// <summary>
    /// ����������� �� ���������.
    /// </summary>
    DynamicArray();

    /// <summary>
    /// ����������� � �������� ��������� ��������.
    /// </summary>
    DynamicArray(int initCapacity);

    /// <summary>
    /// ����������.
    /// </summary>
    ~DynamicArray();

    /// <summary>
    /// ���������� ������� ���������� ��������� � �������.
    /// </summary>
    int GetSize();

    /// <summary>
    /// ���������� ������� ������� �������.
    /// </summary>
    int GetCapacity();

    /// <summary>
    /// ���������� ��������� �� ���������� ������.
    /// </summary>
    double* GetArray();

    /// <summary>
    /// ���������� ������� ������� �� ���������� �������.
    /// </summary>
    double GetElement(int index);

    /// <summary>
    /// ��������� ������� � ������ �� ���������� �������.
    /// </summary>
    void AddElement(int index, double value);

    /// <summary>
    /// ������� ������� �� ������� �� ���������� �������.
    /// </summary>
    void RemoveByIndex(int index);

    /// <summary>
    /// ������� ������ ��������� ������� � ��������� ���������.
    /// </summary>
    void RemoveByValue(double value);

    /// <summary>
    /// ��������� ������� � ������ �������.
    /// </summary>
    void InsertValueAtBeginning(double value);

    /// <summary>
    /// ��������� ������� � ����� �������.
    /// </summary>
    void InsertValueAtEnd(double value);

    /// <summary>
    /// ��������� ����� ������� ����� �������� � ��������� ���������.
    /// </summary>
    void InsertAfterValue(double afterValue, double newValue);

    /// <summary>
    /// ��������� �������� ����� �������� � �������.
    /// </summary>
    int LinearSearch(double value);

    /// <summary>
    /// ��������� �������� ����� �������� � ��������������� �������.
    /// </summary>
    int BinarySearch(double value);

    /// <summary>
    /// ��������� ������ ������� �����.
    /// </summary>
    void SortArray();

    /// <summary>
    /// ������� ���������� ������� � �������.
    /// </summary>
    void PrintArray();
};