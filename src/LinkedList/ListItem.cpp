#include "ListItem.h"

/// <summary>
/// Конструктор узла.
/// </summary>
ListItem::ListItem(double val)
{
	data = val;
	prev = nullptr;
	next = nullptr;
}
