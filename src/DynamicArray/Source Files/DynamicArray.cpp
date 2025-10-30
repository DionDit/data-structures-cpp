#include <iostream>
#include "../Header Files/DynamicArray.h"

using namespace std;

#pragma region Constructors
/// <summary>
/// ����������� �� ���������. ������� ������ � ��������� ��������.
/// </summary>
DynamicArray::DynamicArray()
{
	_size = 0;
	_capacity = _initCapacity;
	_array = new double[_capacity];
}

/// <summary>
/// ����������� � �������� ��������� ��������.
/// </summary>
/// <param name="initCapacity">��������� ������� �������</param>
DynamicArray::DynamicArray(int initCapacity)
{
	_size = 0;
	_capacity = initCapacity;

	if (initCapacity <= 0)
	{
		_capacity = _initCapacity;
	}

	_array = new double[_capacity];
}

/// <summary>
/// ����������. ����������� ������, ���������� ��� ������.
/// </summary>
DynamicArray::~DynamicArray()
{
	delete[] _array;
}
#pragma endregion

#pragma region Supporting methods
/// <summary>
/// �������� ������� ������� �� ��������� ��������.
/// </summary>
/// <param name="newCapacity">����� ������� �������</param>
void DynamicArray::Resize(int newCapacity)
{
	if (newCapacity <= 0)
	{
		cout << "Error: New capacity must be positive. Current capacity: " << _capacity << endl;
		return;
	}

	if (newCapacity < _size)
	{
		cout << "Error: New capacity (" << newCapacity
			 << ") cannot be less than current size (" << _size
			 << "). Current capacity: " << _capacity << endl;
		return;
	}

	if (newCapacity == _capacity)
	{
		cout << "Info: New capacity equals current capacity ("
			 << _capacity << "). No resize needed." << endl;
		return;
	}

	double* array = new double[newCapacity];

	for (int i = 0; i < _size; i++)
	{
		array[i] = _array[i];
	}

	delete[] _array;

	_array = array;
	_capacity = newCapacity;

	cout << "Array resized successfully. New capacity: " << _capacity << endl;
}

/// <summary>
/// ���������, �������� �� ������ ���������� ��� �������� �������.
/// </summary>
/// <param name="index">������ ��� ��������</param>
/// <returns>
/// true - ���� ������ ���������
/// false - ���� ������ ������� �� ������� �������
/// </returns>
bool DynamicArray::IsValidIndex(int index)
{
	return index >= 0 && index <= _size;
}

/// <summary>
/// ������� ���������� ������� � �������.
/// ������ ������: [�������1], [�������2], [�������3]
/// </summary>
void DynamicArray::PrintArray()
{
	if (_size == 0)
	{
		cout << "Error: Array is empty" << endl;
		return;
	}

	for (int i = 0; i < _size; i++)
	{
		cout << "[" << _array[i] << "]";
		if (i < _size - 1)
		{
			cout << ", ";
		}
	}
}
#pragma endregion

#pragma region Getters
/// <summary>
/// ���������� ������� ���������� ��������� � �������.
/// </summary>
/// <returns>���������� ��������� � �������</returns>
int DynamicArray::GetSize()
{
	return _size;
}

/// <summary>
/// ���������� ������� ������� �������.
/// ������� - ������������ ���������� ��������� ��� �������.
/// </summary>
/// <returns>������� �������</returns>
int DynamicArray::GetCapacity()
{
	return _capacity;
}

/// <summary>
/// ���������� ��������� �� ���������� ������.
/// </summary>
/// <returns>��������� �� ������ ���������</returns>
double* DynamicArray::GetArray()
{
	return _array;
}

/// <summary>
/// ���������� ������� ������� �� ���������� �������.
/// </summary>
/// <param name="index">������ �������� (�� 0 �� Size-1)</param>
/// <returns>
/// �������� �������� �� ���������� �������
/// -1 - ���� ������ ����������
/// </returns>
double DynamicArray::GetElement(int index)
{
	if (!IsValidIndex(index))
	{
		cout << "Error: Index out of range" << endl;
		return -1;
	}

	return _array[index];
}
#pragma endregion

#pragma region Array operations
/// <summary>
/// ��������� ������� � ������ �� ���������� �������.
/// ��� ������������� ����������� ������� �������.
/// </summary>
/// <param name="index">������� ��� �������</param>
/// <param name="value">�������� �������� ��� �������</param>
void DynamicArray::AddElement(int index, double value)
{
	if (!IsValidIndex(index))
	{
		cout << "Error: Index out of range" << endl;
		return;
	}

	if (_size == _capacity)
	{
		Resize(_capacity * _growthFactor);
	}

	for (int i = _size; i > index; i--)
	{
		_array[i] = _array[i - 1];
	}

	_array[index] = value;
	_size++;
}

/// <summary>
/// ������� ������� �� ������� �� ���������� �������.
/// ��� ������������� ��������� ������� ������� ��� ����������� ������.
/// </summary>
/// <param name="index">������ ���������� ��������</param>
void DynamicArray::RemoveByIndex(int index)
{
	if (!IsValidIndex(index))
	{
		cout << "Error: Index out of range" << endl;
		return;
	}

	for (int i = index; i < _size - 1; i++)
	{
		_array[i] = _array[i + 1];
	}

	_size--;
	cout << "Element removed successfully." << endl;

	if (_size > 0 && _size <= _capacity / (_growthFactor * 2))
	{
		int newCapacity = _capacity / _growthFactor;
		if (newCapacity < _initCapacity)
		{
			newCapacity = _initCapacity;
		}
		Resize(newCapacity);
	}
}

/// <summary>
/// ������� ������ ��������� ������� � ��������� ���������.
/// ����� �������������� � ������ �������.
/// </summary>
/// <param name="value">�������� ��� ��������</param>
void DynamicArray::RemoveByValue(double value)
{
	int count = 0;
	for (int i = 0; i < _size; i++)
	{
		if (_array[i] == value)
		{
			RemoveByIndex(i);
			count++;
		}
	}
	if (count != 0)
	{
		cout << "Info: " << count << " elements removed successfully";
	}
	else
	{
		cout << "Error: Value not found in array" << endl;
	}
}

/// <summary>
/// ��������� ������� � ������ �������.
/// </summary>
/// <param name="value">�������� �������� ��� �������</param>
void DynamicArray::InsertValueAtBeginning(double value)
{
	AddElement(0, value);
}

/// <summary>
/// ��������� ������� � ����� �������.
/// </summary>
/// <param name="value">�������� �������� ��� �������</param>
void DynamicArray::InsertValueAtEnd(double value)
{
	AddElement(_size, value);
}

/// <summary>
/// ��������� ����� ������� ����� ������� ���������� �������� � ��������� ���������.
/// ���� �������� �� �������, ������� ��������� �� ������.
/// </summary>
/// <param name="afterValue">��������, ����� �������� ����� �������� ����� �������</param>
/// <param name="newValue">����� �������� ��� �������</param>
void DynamicArray::InsertAfterValue(double afterValue, double newValue)
{
	for (int i = 0; i < _size; i++)
	{
		if (_array[i] == afterValue)
		{
			AddElement(i + 1, newValue);
			return;
		}
	}
	cout << "Error: Value not found in array" << endl;
}
#pragma endregion

#pragma region Search and sort
/// <summary>
/// ��������� �������� ����� �������� � �������.
/// ����� �������������� ��������������� � ������ �������.
/// </summary>
/// <param name="value">�������� ��� ������</param>
/// <returns>
/// ������ ������� ���������� ��������
/// -1 - ���� ������� �� ������
/// </returns>
int DynamicArray::LinearSearch(double value)
{
	int count = 0;
	for (int i = 0; i < _size; i++)
	{
		if (_array[i] == value)
		{
			count++;
			cout << "Value found at index: " << ++i << endl;
		}
	}
	if (count == 0)
	{
		return -1;
	}
}

/// <summary>
/// ��������� �������� ����� �������� � ��������������� �������.
/// ������ ������ ���� ������������ ����� ������� ����� ������.
/// </summary>
/// <param name="value">�������� ��� ������</param>
/// <returns>
/// ������ ���������� ��������
/// -1 - ���� ������� �� ������ ��� ������ �� ������������
/// </returns>
void DynamicArray::BinarySearch(double value)
{
	int left = 0;
	int right = _size - 1;
	bool found = false;

	while (left <= right)
	{
		int middleIndex = left + (right - left) / 2;

		if (_array[middleIndex] == value)
		{
			cout << "Value found at index: " << ++middleIndex << endl;
			found = true;
			break;
		}
		else if (_array[middleIndex] < value)
		{
			left = middleIndex + 1;
		}
		else
		{
			right = middleIndex - 1;
		}
	}
	if (!found)
	{
		cout << "Value not found in array." << endl;
	}

}

/// <summary>
/// ��������� ������ ������� �����.
/// </summary>
void DynamicArray::SortArray()
{
	int interval = _size / 2;

	while (interval >= 1)
	{
		for (int currentIndex = interval; currentIndex < _size; currentIndex++)
		{
			int compareIndex = currentIndex;
			while ((compareIndex >= interval) && (_array[compareIndex - interval] > _array[compareIndex]))
			{
				double temp = _array[compareIndex];
				_array[compareIndex] = _array[compareIndex - interval];
				_array[compareIndex - interval] = temp;
				compareIndex -= interval;
			}
		}
		interval /= 2;
	}
}
#pragma endregion