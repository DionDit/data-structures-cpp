#pragma once

/// <summary>
/// Класс ListItem представляет узел двусвязного списка.
/// </summary>
class ListItem {
public:
    /// <summary>
    /// Данные узла
    /// </summary>
    double data;

    /// <summary>
    /// Указатель на предыдущий узел
    /// </summary>
    ListItem* prev;

    /// <summary>
    /// Указатель на следующий узел
    /// </summary>
    ListItem* next;

    /// <summary>
    /// Конструктор узла с заданным значением.
    /// Инициализирует prev и next как nullptr.
    /// </summary>
    /// <param name="val">Значение для данных</param>
    ListItem(double val);
};
