#pragma once
#include <iostream>

namespace Miit::Vector
{
	class Vector final
	{
	public:

		/*
		@brief Инициализация нового экземпляра типа vector с помощью initializer_list
		@param list Лист с помощью которго будет создан vector
		*/
		Vector(const std::initializer_list<int> list);

		/*
		@brief Удаляет, чистит память после вектора
		*/
		~Vector();

		/*
		@brief Получение колличества элементов в векторе
		@return Колличество элементов в векторе
		*/
		int getSize() const;

		/*
		@brief Добавление в вектор нового элемента
		@param Элемент
		*/
		void addElement(int value);

		/*
		@brief Удаление элемента из вектора по индексу элемента
		@param index Индекс элемента
		*/
		void deleteI(int index);

		/*
		@brief Получение индекса элемента в векторе
		@param value Элемент который мы ищем
		@return Индекс элемента в векторе, вернет -1, если элемента в векторе нет
		*/
		int findI(int value) const;

		/*
		@brief Проверка на отсутствие элементов в векторе
		@return true если элементов нет и false если они есть
		*/
		bool isEmpty() const;

		/*
		@brief Перегрузка оператора квадратных скобок
		@param index Индекс элемента в векторе
		@return Элемент из вектора по заданному индексу
		*/
		int& operator[](int index);

		/*
		@brief Перегрузка оператора копирования
		@param Vector Вектор который будет скопирован
		@return Скопированный Vector
		*/
		Vector& operator=(const Vector& vector);

		/*
		@brief Перегрузка оператора перемещения
		@param Vector Вектор для перемещения
		@return Вектор
		*/
		Vector& operator=(Vector&& vector) noexcept;

		/*
		@brief Перегрузка конструктора перемещения
		@param vector Вектор для перемещния
		*/
		Vector(const Vector& vector);

		/*
		@brief Перегрузка конструктора копирования
		@param vector Вектор для копирования
		*/
		Vector(Vector&& vector) noexcept;

		/*
		@brief Перегрузка оператора вывода
		@param os Поток вывода
		@param vector Вектор для вывода
		*/
		friend std::ostream& operator<<(std::ostream& os, Vector& vector) noexcept;

		/*
		@brief Перегрузка оператора равно
		@param rha Первый аргумент для сравнения
		@param lha Второй аргумент для сравнения
		@return false - если равны, true - если не равны
		*/
		friend bool operator==(const Vector& rha, const Vector& lha) noexcept;

		/*
		@brief Перегрузка оператора не равно
		@param rha Первый аргумент для сравнения
		@param lha Второй аргумент для сравнения
		@return true - если равны, false - если не равны
		*/
		friend bool operator!=(const Vector& rha, const Vector& lha) noexcept;

		/*
		@brief Преобразование объета в строку
		@return Строка из объекта
		*/
		std::string toString() const noexcept;

	private:
		size_t size;
		int* array;

	};
};
