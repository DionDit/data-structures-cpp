#pragma once

/// <summary>
/// Класс DynamicArray представляет динамический массив для хранения элементов типа double.
/// Массив автоматически изменяет свой размер при добавлении или удалении элементов.
/// </summary>
class DynamicArray
{
private:
    /// <summary>
    /// Текущее количество элементов в массиве
    /// </summary>
    int _size;

    /// <summary>
    /// Текущая емкость массива
    /// </summary>
    int _capacity;

    /// <summary>
    /// Указатель на динамически выделенный массив элементов
    /// </summary>
    double* _array;

    /// <summary>
    /// Коэффициент роста массива
    /// </summary>
    int _growthFactor = 2;

    /// <summary>
    /// Начальная емкость массива по умолчанию
    /// </summary>
    int _initCapacity = 4;

    /// <summary>
    /// Изменяет емкость массива на указанное значение.
    /// </summary>
    void Resize(int newCapacity);

    /// <summary>
    /// Проверяет, является ли индекс допустимым для текущего массива.
    /// </summary>
    bool IsValidIndex(int index);

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    DynamicArray();

    /// <summary>
    /// Конструктор с заданной начальной емкостью.
    /// </summary>
    DynamicArray(int initCapacity);

    /// <summary>
    /// Деструктор.
    /// </summary>
    ~DynamicArray();

    /// <summary>
    /// Возвращает текущее количество элементов в массиве.
    /// </summary>
    int GetSize();

    /// <summary>
    /// Возвращает текущую емкость массива.
    /// </summary>
    int GetCapacity();

    /// <summary>
    /// Возвращает указатель на внутренний массив.
    /// </summary>
    double* GetArray();

    /// <summary>
    /// Возвращает элемент массива по указанному индексу.
    /// </summary>
    double GetElement(int index);

    /// <summary>
    /// Добавляет элемент в массив по указанному индексу.
    /// </summary>
    void AddElement(int index, double value);

    /// <summary>
    /// Удаляет элемент из массива по указанному индексу.
    /// </summary>
    void RemoveByIndex(int index);

    /// <summary>
    /// Удаляет первый найденный элемент с указанным значением.
    /// </summary>
    void RemoveByValue(double value);

    /// <summary>
    /// Вставляет элемент в начало массива.
    /// </summary>
    void InsertValueAtBeginning(double value);

    /// <summary>
    /// Вставляет элемент в конец массива.
    /// </summary>
    void InsertValueAtEnd(double value);

    /// <summary>
    /// Вставляет новый элемент после элемента с указанным значением.
    /// </summary>
    void InsertAfterValue(double afterValue, double newValue);

    /// <summary>
    /// Выполняет линейный поиск элемента в массиве.
    /// </summary>
    int LinearSearch(double value);

    /// <summary>
    /// Выполняет бинарный поиск элемента в отсортированном массиве.
    /// </summary>
    int BinarySearch(double value);

    /// <summary>
    /// Сортирует массив методом Шелла.
    /// </summary>
    void SortArray();

    /// <summary>
    /// Выводит содержимое массива в консоль.
    /// </summary>
    void PrintArray();
};