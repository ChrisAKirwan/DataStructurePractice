#include "matrices.h"


void TestMatrices()
{
	std::cout << "Testing Diagonal Matrix:" << std::endl;
	TestDiagonalMatrix();
	std::cout << std::endl << std::endl;

	std::cout << "Testing Lower-Triangle Matrix:" << std::endl;
	TestLowerTriangleMatrix();
	std::cout << std::endl << std::endl;

    std::cout << "Testing Upper-Triangle Matrix:" << std::endl;
    TestUpperTriangleMatrix();
    std::cout << std::endl << std::endl;

    std::cout << "Testing Symmetric Matrix:" << std::endl;
    TestSymmetricMatrix();
    std::cout << std::endl << std::endl;

	std::cout << "Testing Tri-Band Matrix:" << std::endl;
	TestTriBandMatrix();
	std::cout << std::endl << std::endl;

	std::cout << "Testing Toeplitz Matrix:" << std::endl;
	TestToeplitzMatrix();
	std::cout << std::endl << std::endl;
}


// Diagonal Matrix:
int M_Diagonal::get(int i, int j) const
{
	if (isInBounds(i, j))
	{
		if (i == j)
			return Arr[i];

		return 0;
	}

    return -1;
}

void M_Diagonal::set(int i, int j, int val)
{
	if (isInBounds(i, j) && i == j)
		Arr[i] = val;
}

void TestDiagonalMatrix()
{
    const int m1[4][4] =
	{
		{ 1, 0, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 3, 0 },
		{ 0, 0, 0, 4 }
	};

	const int m2[4][4] =
	{
		{ 1, 1, 1, 1 },
		{ 2, 2, 2, 2 },
		{ 3, 3, 3, 3 },
		{ 4, 4, 4, 4 }
	};

    int size = 4;
    M_Diagonal a(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a.set(i, j, m1[i][j]);

    std::cout << "Diagonal 4x4 Matrix:" << std::endl;
    std::cout << a << std::endl;
	a.display_array();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m2[i][j]);

	std::cout << "Non-Standard Conversion To Diagonal 4x4 Matrix:" << std::endl;
	std::cout << a << std::endl;
	a.display_array();
}


// Lower Triangle Matrix:
int M_LowerTriangular::get(int i, int j) const
{
    if (isInBounds(i, j))
    {
        if (i >= j)
        {
            // Row-Major
            int idx = (i * (i + 1) / 2) + j;
            return Arr[idx];
        }

		return 0;
    }

    return -1;
}

void M_LowerTriangular::set(int i, int j, int val)
{
	if (isInBounds(i, j))
	{
		if (i >= j)
		{
			// Row-Major
			int idx = (i * (i + 1) / 2) + j;
			Arr[idx] = val;
		}
	}
}

void TestLowerTriangleMatrix()
{
	const int m1[4][4] =
	{
		{ 1, 0, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 3, 3, 3, 0 },
		{ 4, 4, 4, 4 }
	};

	const int m2[4][4] =
	{
		{ 1, 1, 1, 1 },
		{ 2, 2, 2, 2 },
		{ 3, 3, 3, 3 },
		{ 4, 4, 4, 4 }
	};

	int size = 4;
	M_LowerTriangular a(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m1[i][j]);

	std::cout << "Lower-Triangular 4x4 Matrix:" << std::endl;
	std::cout << a << std::endl;
	a.display_array();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m2[i][j]);

	std::cout << "Non-Standard Conversion To Lower-Triangular 4x4 Matrix:" << std::endl;
	std::cout << a << std::endl;
	a.display_array();
}


// Upper Triangle Matrix:
int M_UpperTriangular::get(int i, int j) const
{
	if (isInBounds(i, j))
	{
		if (i <= j)
		{
			// Column-Major
			int idx = (j * (j + 1) / 2) + i;
			return Arr[idx];
		}

		return 0;
	}

	return -1;
}

void M_UpperTriangular::set(int i, int j, int val)
{
	if (isInBounds(i, j))
	{
		if (i <= j)
		{
			// Column-Major
			int idx = (j * (j + 1) / 2) + i;
			Arr[idx] = val;
		}
	}
}

void TestUpperTriangleMatrix()
{
	const int m[4][4] =
	{
		{ 1, 1, 1, 1 },
		{ 0, 2, 2, 2 },
		{ 0, 0, 3, 3 },
		{ 0, 0, 0, 4 }
	};

	const int m2[4][4] =
	{
		{ 1, 1, 1, 1 },
		{ 2, 2, 2, 2 },
		{ 3, 3, 3, 3 },
		{ 4, 4, 4, 4 }
	};

	int size = 4;
    M_UpperTriangular a(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m[i][j]);

	std::cout << "Upper-Triangular 4x4 Matrix:" << std::endl;
	std::cout << a << std::endl;
	a.display_array();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m2[i][j]);

	std::cout << "Non-Standard Conversion To Upper-Triangular 4x4 Matrix:" << std::endl;
	std::cout << a << std::endl;
	a.display_array();
}


// Symmetric Matrix:
void TestSymmetricMatrix()
{
	const int m1[4][4] =
	{
		{ 1, 1, 1, 1 },
		{ 1, 2, 2, 2 },
		{ 1, 2, 3, 3 },
		{ 1, 2, 3, 4 }
	};

	const int m2[4][4] =
	{
		{ 1, 2, 3, 4 },
		{ 2, 2, 3, 4 },
		{ 3, 3, 3, 4 },
		{ 4, 4, 4, 4 }
	};

	int size = 4;
	M_Symmetric a(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m1[i][j]);

	std::cout << "Symmetric 4x4 Matrix (1/2):" << std::endl;
	std::cout << a << std::endl;
	a.display_array();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m2[i][j]);

	std::cout << "Symmetric 4x4 Matrix (2/2):" << std::endl;
	std::cout << a << std::endl;
	a.display_array();
}


// Tri-Band Matrix:
int M_TriBand::get(int i, int j) const
{
	if (isInBounds(i, j))
	{
		if (i - j == 1)
		{
			// Lower Diagonal
			return Arr[i - 1];
		}
		
		if (i - j == 0)
		{
			// Center Diagonal
			return Arr[dimensions - 1 + i];
		}

		if (i - j == -1)
		{
			// Upper Diagonal
			return Arr[2 * dimensions - 1 + i];
		}

		return 0;
	}

	return -1;
}

void M_TriBand::set(int i, int j, int val)
{
	if (isInBounds(i, j))
	{
		if (i - j == 1)
		{
			// Lower Diagonal
			Arr[i - 1] = val;
		}

		if (i - j == 0)
		{
			// Center Diagonal
			Arr[dimensions - 1 + i] = val;
		}

		if (i - j == -1)
		{
			// Upper Diagonal
			Arr[2 * dimensions - 1 + i] = val;
		}
	}
}

void TestTriBandMatrix()
{
	const int m[4][4] =
	{
		{ 2, 3, 0, 0 },
		{ 1, 2, 3, 0 },
		{ 0, 1, 2, 3 },
		{ 0, 0, 1, 2 }
	};

	const int m2[4][4] =
	{
		{ 2, 3, 5, 5 },
		{ 1, 2, 3, 5 },
		{ 5, 1, 2, 3 },
		{ 5, 5, 1, 2 }
	};

	int size = 4;
	M_TriBand a(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m[i][j]);

	std::cout << "Tri-Band 4x4 Matrix:" << std::endl;
	std::cout << a << std::endl;
	a.display_array();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m2[i][j]);

	std::cout << "Non-Standard Conversion To Tri-Band 4x4 Matrix:" << std::endl;
	std::cout << a << std::endl;
	a.display_array();
}


// Toeplitz Matrix:
int M_Toeplitz::get(int i, int j) const
{
	if (isInBounds(i, j))
	{
		if (i <= j)
		{
			// Upper Triangle 
			return Arr[j - i];
		}
		else
		{
			// Lower Triangle (but not center diagonal)
			return Arr[dimensions - 1 + (i - j)];
		}
	}

	return -1;
}

void M_Toeplitz::set(int i, int j, int val)
{
	if (isInBounds(i, j))
	{
		if (i <= j)
		{
			// Upper Triangle
			Arr[j - i] = val;
		}
		else
		{
			// Lower Triangle (but not center diagonal)
			Arr[dimensions - 1 + (i - j)] = val;
		}
	}
}

void TestToeplitzMatrix()
{
	const int m[4][4] =
	{
		{ 2, 3, 4, 5 },
		{ 1, 2, 3, 4 },
		{ 6, 1, 2, 3 },
		{ 7, 6, 1, 2 }
	};

	const int m2[4][4] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 1, 2, 3 },
		{ 6, 5, 1, 2 },
		{ 7, 6, 5, 1 }
	};

	int size = 4;
	M_Toeplitz a(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m[i][j]);

	std::cout << "Toeplitz 4x4 Matrix (1/2):" << std::endl;
	std::cout << a << std::endl;
	a.display_array();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			a.set(i, j, m2[i][j]);

	std::cout << "Toeplitz 4x4 Matrix (2/2):" << std::endl;
	std::cout << a << std::endl;
	a.display_array();
}
