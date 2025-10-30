#pragma once

/// <summary>
/// ����� ListItem ������������ ���� ����������� ������.
/// </summary>
class ListItem {
public:
    /// <summary>
    /// ������ ����
    /// </summary>
    double data;

    /// <summary>
    /// ��������� �� ���������� ����
    /// </summary>
    ListItem* prev;

    /// <summary>
    /// ��������� �� ��������� ����
    /// </summary>
    ListItem* next;

    /// <summary>
    /// ����������� ���� � �������� ���������.
    /// �������������� prev � next ��� nullptr.
    /// </summary>
    /// <param name="val">�������� ��� ������</param>
    ListItem(double val);
};
