#pragma once
#include <iostream>

template <class T>
class Vector
{
private:
	T* arr;
	int capacity;
	int current;

public:
	// Constructors/Destructor
	Vector()
	{
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

	Vector(int n)
	{
		arr = new T[n];
		capacity = n;
		current = 0;
	}

	~Vector()
	{ 
		std::cout << "destructor()!!! " << *this << std::endl;
		delete[] arr; 
	}

	// Overloads
	Vector<T>& operator=(const Vector<T>& other) noexcept
	{
		resize(other.size());
		for (int i = 0; i < other.size(); i++)
			arr[i] = other.at(i);

		current = other.size();

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector<T>& obj)
	{
		os << "Size: " << obj.size() << ". Capacity: " << obj.max_size() << std::endl;
		os << "Contents: " << "[ ";
		for (int i = 0; i < obj.size(); i++)
			os << obj.at(i) << ", ";
		os << "]" << std::endl;

		return os;
	}

	T& operator[](int i) { return arr[i]; }

	// Member Functions:
	int size() const { return current; }
	int max_size() const { return capacity; }
	T at(int n) const { if (n >= 0 && n < current) return arr[n]; return arr[0]; }
	T front() const { return arr[0]; }
	T back() const { return arr[current - 1]; }
	void clear() { current = 0; resize(1); }

	void resize(int n)
	{
		// Check if we need to reduce size.
		if (capacity > n)
		{
			// Cannot reduce - return.
			if (capacity - capacity / 2 < n)
				return;

			// Logarithmically reduce until fit
			while (capacity - capacity / 2 > n)
				capacity -= capacity / 2;
		}

		if (capacity == 1)
			capacity = 2;
		else
		{
			while (capacity <= n)
				capacity += capacity / 2;
		}

		if (current > capacity)
			current = capacity;

		T* newArr = new T[capacity];
		for (int i = 0; i < current; i++)
			newArr[i] = arr[i];

		delete[] arr;
		arr = newArr;
	}

	void shrink_to_fit()
	{
		if (capacity == current)
			return;

		capacity = current;

		T* newArr = new T[capacity];
		for (int i = 0; i < capacity; i++)
			newArr[i] = arr[i];

		delete[] arr;
		arr = newArr;
	}

	void assign(int n, T val)
	{
		if (n >= 0 && n < current)
			arr[n] = val;
	}

	void push_back(T val)
	{
		if (current == capacity)
			resize(capacity + 1);

		arr[current] = val;
		current++;
	}

	void pop_back()
	{
		if (current)
			current--;

		resize(current);
	}

	void insert(int pos, T val)
	{
		if (pos >= 0 && pos < current)
		{
			if (current == capacity)
				resize(current);

			for (int i = current; i > pos; i--)
				arr[i] = arr[i - 1];

			arr[pos] = val;
			current++;
		}
	}

	void erase(int pos)
	{
		if (pos >= 0 && pos < current)
		{
			for (int i = pos + 1; i < current; i++)
				arr[i - 1] = arr[i];

			current--;
			resize(current);
		}
	}

	void erase(int start, int end)
	{
		if ((start >= 0 && start < end) && end < current)
		{
			for (int i = start, j = end + 1; j < current; i++, j++)
				arr[i] = arr[j];

			current -= (end + 1) - start;
			resize(current);
		}
	}

	void swap(Vector<T>& x)
	{
		if (capacity < x.size())
			resize(x.size());

		if (x.max_size() < current)
			x.resize(current);

		T temp;

		if (current > x.size())
		{
			for (int i = 0; i < x.size(); i++)
			{
				temp = x.at(i);
				x.assign(i, arr[i]);
				arr[i] = temp;
			}

			int newSize = x.size();
			for (int i = x.size(); i < current; i++)
				x.push_back(arr[i]);

			current = newSize;
		}
		else
		{
			for (int i = 0; i < current; i++)
			{
				temp = arr[i];
				arr[i] = x.at(i);
				x.assign(i, temp);
			}

			for (int i = current; i < x.size(); i++)
				push_back(x.at(i));
		}

		resize(current);
		x.resize(x.size());
	}
};