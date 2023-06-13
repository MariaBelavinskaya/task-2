#include "Vector.h"
#include <iostream>
#include <sstream>

Miit::Vector::Vector::Vector(const std::initializer_list<int> list)
	:size(list.size())
{
	this->array = new int[this->size];
	std::copy(list.begin(), list.end(), this->array);
}

Miit::Vector::Vector::~Vector()
{
	delete[] this->array;
}

int Miit::Vector::Vector::getSize() const
{
	return this->size;
}

bool Miit::Vector::Vector::isEmpty() const
{
	return this->size == 0;
}

Miit::Vector::Vector& Miit::Vector::Vector::operator=(const Vector& vector)
{
	if (vector == *this) 
	{
		return *this;
	}
	if (!this->isEmpty())
	{
		delete[] this->array;
		this->array = nullptr;
		this->size = 0;
	}
	this->array = new int[this->size];
	std::copy(vector.array, vector.array + vector.size, this->array);
	return *this;
}

Miit::Vector::Vector& Miit::Vector::Vector::operator=(Vector&& vector) noexcept
{
	std::swap(vector.array, this->array);
	std::swap(vector.size, this->size);
	return *this;
}

Miit::Vector::Vector::Vector(const Vector& vector)
	:size(vector.getSize()), array(nullptr)
{
	std::copy(vector.array, vector.array + vector.getSize(), this->array);
}

Miit::Vector::Vector::Vector(Vector&& vector) noexcept
	:size(0), array(nullptr)
{
	std::swap(vector.array, this->array);
	std::swap(vector.size, this->size);
}

int& Miit::Vector::Vector::operator[](int index)
{
	if (this->isEmpty() || index >= this->size or index < 0)
	{
		throw std::out_of_range("Incorrect Index");
	}
	return this->array[index];
}

void Miit::Vector::Vector::deleteI(int index)
{
	if (this->size == 0 or index < 0 or index >= this->size)
	{
		throw std::out_of_range("Incorrect Index");
	}
	int* vector1 = new int[this->size - 1];
	int now = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if (i != index)
		{
			vector1[now] = this->array[i];
			now++;
		}
	}
	delete[] this->array;
	this->array = vector1;
	this->size--;
}

int Miit::Vector::Vector::findI(int value) const
{
	if (this->isEmpty())
	{
		return -1;
	}

	int index = 0;
	while ((index < this->size) && this->array[index] != value)
	{
		index++;
	}
	if (index == this->size)
	{
		return -1;
	}
	else
	{
		return index;
	}
}

std::string Miit::Vector::Vector::toString() const noexcept
{
	std::stringstream sstring;
	for (size_t i = 0; i < this->size; i++)
	{
		sstring << this->array[i] << " ";
	}
	return sstring.str();
}

std::ostream& Miit::Vector::operator<<(std::ostream& os, Vector& vector) noexcept
{
	return os << vector.toString();
}

bool Miit::Vector::operator==(const Vector& rha, const Vector& lha) noexcept
{
	return (rha.toString() == lha.toString());
}

bool Miit::Vector::operator!=(const Vector& rha, const Vector& lha) noexcept
{
	return !(rha == lha);
}
