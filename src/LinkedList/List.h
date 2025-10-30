#pragma once
#include "ListItem.h"

/// <summary>
/// Класс List реализует двусвязный список для элементов типа double.
/// </summary>
class List {
private:
    /// <summary>
    /// Голова списка
    /// </summary>
    ListItem* head;

    /// <summary>
    /// Хвост списка
    /// </summary>
    ListItem* tail;

    /// <summary>
    /// Размер списка
    /// </summary>
    int size;

public:
    /// <summary>
    /// Конструктор без аргументов
    /// </summary>
    List();

    /// <summary>
    /// Деструктор
    /// </summary>
    ~List();

    /// <summary>
    /// Размер списка
    /// </summary>
    int GetSize();

    /// <summary>
    /// Проверяет, пуст ли список
    /// </summary>
    bool IsEmpty();

    /// <summary>
    /// Добавление элемента в конец списка
    /// </summary>
    /// <param name="value">Значение для добавления</param>
    void AddElement(double value);

    /// <summary>
    /// Удаление элемента по значению
    /// </summary>
    /// <param name="value">Значение для удаления</param>
    void RemoveElement(double value);

    /// <summary>
    /// Вставка элемента в начало списка
    /// </summary>
    /// <param name="value">Значение для вставки</param>
    void InsertAtBeginning(double value);

    /// <summary>
    /// Вставка элемента после первого найденного по значению
    /// </summary>
    /// <param name="afterValue">Значение, после которого вставить</param>
    /// <param name="newValue">Новое значение</param>
    void InsertAfter(double afterValue, double newValue);

    /// <summary>
    /// Вставляет элемент перед первым найденным по значению
    /// </summary>
    /// <param name="beforeValue">Значение, перед которым вставить</param>
    /// <param name="newValue">Новое значение</param>
    void InsertBefore(double beforeValue, double newValue);

    /// <summary>
    /// Сортировка 
    /// </summary>
    void Sort();

    /// <summary>
    /// Линейный поиск по значению
    /// </summary>
    /// <param name="value">Значение для поиска</param>
    int LinearSearch(double value);

    /// <summary>
    /// Вывод списка
    /// </summary>
    void PrintList();
};