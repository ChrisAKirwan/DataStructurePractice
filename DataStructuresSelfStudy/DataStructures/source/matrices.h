#pragma once
#include <iostream>

// Test Func Declarations:
void TestMatrices();
void TestDiagonalMatrix();
void TestLowerTriangleMatrix();
void TestUpperTriangleMatrix();
void TestSymmetricMatrix();
void TestTriBandMatrix();
void TestToeplitzMatrix();

// Diagonal Matrix
class M_Diagonal
{
public:
	M_Diagonal() : dimensions(2), Arr(new int[2]) {}
	M_Diagonal(int size) : dimensions(size), Arr(new int[size]) {};
	~M_Diagonal() { delete[] Arr; }

private:
	int* Arr;
	int dimensions;

public:
	// Display Override
	friend std::ostream& operator<<(std::ostream& os, const M_Diagonal& obj)
	{
		os << "[";
		for (int i = 0; i < obj.size(); i++)
		{
			if (i > 0)
				os << " ";

			for (int j = 0; j < obj.size(); j++)
			{
				os << obj.get(i, j);

				if (i == j && i == obj.size() - 1)
					os << "]";
				else
					os << ", ";
			}
			os << std::endl;
		}

		return os;
	}

	// Methods
	int size() const { return dimensions; }
	int get(int i, int j) const;
	void set(int i, int j, int val);

	void display_array() const
	{
		std::cout << "[";
		for (int i = 0; i < dimensions; i++)
		{
			std::cout << Arr[i];

			if (i == dimensions - 1)
				std::cout << "]";
			else
				std::cout << ", ";
		}
		std::cout << std::endl;
	}

private:
	// Helper Methods
	bool isInBounds(int i, int j) const
	{ 
		if (i >= 0 && i < dimensions &&
			j >= 0 && j < dimensions)
			return true;

		return false;
	}
};

class M_LowerTriangular
{
public:
	M_LowerTriangular() : dimensions(2), Arr(new int[2 * (2 + 1) / 2]) {}
	M_LowerTriangular(int size): dimensions(size), Arr(new int[size * (size + 1) / 2]) {}
	~M_LowerTriangular() { delete[] Arr; }

private:
	int* Arr;
	int dimensions;

public:
	// Display Override
	friend std::ostream& operator<<(std::ostream& os, const M_LowerTriangular& obj)
	{
		os << "[";
		for (int i = 0; i < obj.size(); i++)
		{
			if (i > 0)
				os << " ";

			for (int j = 0; j < obj.size(); j++)
			{
				os << obj.get(i, j);

				if (i == j && i == obj.size() - 1)
					os << "]";
				else
					os << ", ";
			}
			os << std::endl;
		}

		return os;
	}

	// Methods
	int size() const { return dimensions; }
	int get(int i, int j) const;
	void set(int i, int j, int val);

	void display_array() const
	{
		std::cout << "[";
		int arrSize = dimensions * (dimensions + 1) / 2;
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << Arr[i];

			if (i == arrSize - 1)
				std::cout << "]";
			else
				std::cout << ", ";
		}
		std::cout << std::endl;
	}

private:
	// Helper Methods
	bool isInBounds(int i, int j) const
	{
		if (i >= 0 && i < dimensions &&
			j >= 0 && j < dimensions)
			return true;

		return false;
	}
};

class M_UpperTriangular
{
public:
	M_UpperTriangular() : dimensions(2), Arr(new int[2 * (2 + 1) / 2]) {}
	M_UpperTriangular(int size) : dimensions(size), Arr(new int[size * (size + 1) / 2]) {}
	~M_UpperTriangular() { delete[] Arr; }

private:
	int* Arr;
	int dimensions;

public:
	// Display Override
	friend std::ostream& operator<<(std::ostream& os, const M_UpperTriangular& obj)
	{
		os << "[";
		for (int i = 0; i < obj.size(); i++)
		{
			if (i > 0)
				os << " ";

			for (int j = 0; j < obj.size(); j++)
			{
				os << obj.get(i, j);

				if (i == j && i == obj.size() - 1)
					os << "]";
				else
					os << ", ";
			}
			os << std::endl;
		}

		return os;
	}

	// Methods
	int size() const { return dimensions; }
	int get(int i, int j) const;
	void set(int i, int j, int val);

	void display_array() const
	{
		std::cout << "[";
		int arrSize = dimensions * (dimensions + 1) / 2;
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << Arr[i];

			if (i == arrSize - 1)
				std::cout << "]";
			else
				std::cout << ", ";
		}
		std::cout << std::endl;
	}

private:
	// Helper Methods
	bool isInBounds(int i, int j) const
	{
		if (i >= 0 && i < dimensions &&
			j >= 0 && j < dimensions)
			return true;

		return false;
	}
};

class M_Symmetric
{
public:
	M_Symmetric() : Arr(2) {}
	M_Symmetric(int size) : Arr(size) {}

private:
	M_LowerTriangular Arr;

public:
	// Display Override
	friend std::ostream& operator<<(std::ostream& os, const M_Symmetric& obj)
	{
		os << "[";
		for (int i = 0; i < obj.size(); i++)
		{
			if (i > 0)
				os << " ";

			for (int j = 0; j < obj.size(); j++)
			{
				if (i < j)
					os << obj.get(j, i);
				else
					os << obj.get(i, j);

				if (i == j && i == obj.size() - 1)
					os << "]";
				else
					os << ", ";
			}
			os << std::endl;
		}

		return os;
	}

	// Methods
	int size() const { return Arr.size(); }
	int get(int i, int j) const { return Arr.get(i, j); }
	void set(int i, int j, int val) { Arr.set(i, j, val); }

	void display_array() const { Arr.display_array(); }

private:
	// Helper Methods
	bool isInBounds(int i, int j) const
	{
		if (i >= 0 && i < Arr.size() &&
			j >= 0 && j < Arr.size())
			return true;

		return false;
	}
};

class M_TriBand
{
public:
	M_TriBand() : dimensions(2), Arr(new int[3 * 2 - 2]) {}
	M_TriBand(int size) : dimensions(size), Arr(new int[3 * size - 2]) {}
	~M_TriBand() { delete[] Arr; }

private:
	int* Arr;
	int dimensions;

public:
	// Display Override
	friend std::ostream& operator<<(std::ostream& os, const M_TriBand& obj)
	{
		os << "[";
		for (int i = 0; i < obj.size(); i++)
		{
			if (i > 0)
				os << " ";

			for (int j = 0; j < obj.size(); j++)
			{
				os << obj.get(i, j);

				if (i == j && i == obj.size() - 1)
					os << "]";
				else
					os << ", ";
			}
			os << std::endl;
		}

		return os;
	}

	// Methods
	int size() const { return dimensions; }
	int get(int i, int j) const;
	void set(int i, int j, int val);

	void display_array() const
	{
		std::cout << "[";
		int arrSize = 3 * dimensions - 2;
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << Arr[i];

			if (i == arrSize - 1)
				std::cout << "]";
			else
				std::cout << ", ";
		}
		std::cout << std::endl;
	}

private:
	// Helper Methods
	bool isInBounds(int i, int j) const
	{
		if (i >= 0 && i < dimensions &&
			j >= 0 && j < dimensions)
			return true;

		return false;
	}
};

class M_Toeplitz
{
public:
	M_Toeplitz() : dimensions(2), Arr(new int[2 + 2 - 1]) {}
	M_Toeplitz(int size) : dimensions(size), Arr(new int[size + size - 1]) {}
	~M_Toeplitz() { delete[] Arr; }

private:
	int* Arr;
	int dimensions;

public:
	// Display Override
	friend std::ostream& operator<<(std::ostream& os, const M_Toeplitz& obj)
	{
		os << "[";
		for (int i = 0; i < obj.size(); i++)
		{
			if (i > 0)
				os << " ";

			for (int j = 0; j < obj.size(); j++)
			{
				os << obj.get(i, j);

				if (i == j && i == obj.size() - 1)
					os << "]";
				else
					os << ", ";
			}
			os << std::endl;
		}

		return os;
	}

	// Methods
	int size() const { return dimensions; }
	int get(int i, int j) const;
	void set(int i, int j, int val);

	void display_array() const
	{
		std::cout << "[";
		int arrSize = dimensions + dimensions - 1;
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << Arr[i];

			if (i == arrSize - 1)
				std::cout << "]";
			else
				std::cout << ", ";
		}
		std::cout << std::endl;
	}

private:
	// Helper Methods
	bool isInBounds(int i, int j) const
	{
		if (i >= 0 && i < dimensions &&
			j >= 0 && j < dimensions)
			return true;

		return false;
	}
};