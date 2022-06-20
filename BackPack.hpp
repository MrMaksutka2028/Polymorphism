#include "iostream"

class Backpack {
public:
	Backpack();
	Backpack(int size);

	int size() const;
	void push_back(int el);
	void resize(int size);

private:
	int _size = 0;
	int _capacity = 0;
	int *_data;
};