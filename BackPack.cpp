#include <iostream>
#include "BackPack.hpp"

Backpack::Backpack() {
	_size = 0;
	_capacity = 0;
	_data = nullptr;
}
Backpack::Backpack(int size) {
	_size = size;
	_capacity = _size;
	if (_size != 0)
		_data = new int[_size];
	else
		_data = 0;
}

int Backpack::size() const {
	return _size;
}
void Backpack::push_back(int el) {
	resize(_size + 1);
	_data[_size - 1] = el;
}
void Backpack::resize(int size) {
	if (size > _capacity)
	{
		int new_capacity = size;
		int* new_data = new int[new_capacity];
		for (int i = 0; i < _size; i++)
			new_data[i] = _data[i];
		delete[] _data;
		_data = new_data;
		_capacity = new_capacity;
	}
	_size = size;
}