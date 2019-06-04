#include "Macierz.h"


	void Macierz::remakeTable(int length) {
		this->length = length;
		table = new float*[length];
		for (int i = 0; i < length; ++i)
			table[i] = new float[length];
	}
	void Macierz::fillTable(float value) {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				table[i][j] = value;
			}
		}
	}
	void Macierz::odwracanie(float **& A, int & n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n; j < n; j++)
			{
				A[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			A[i][n + i] = 1;
		}
		for (int s = 0; s < n; s++)
		{
			float c;
			c = A[s][s];
			A[s][s] = A[s][s] - 1;
			for (int j = s; j < 2 * n; j++)
			{
				float d;
				d = A[s][j] / c;
				for (int i = 0; i < n; i++)
				{
					A[i][j] = A[i][j] - d * A[i][s];
				}
			}
		}

	}


	Macierz::Macierz(int length) {
		remakeTable(length);
		fillTable(0.0);
	}
	Macierz::Macierz(float value,int length) {
		remakeTable(length);
		fillTable(value);
	}
	Macierz::Macierz(float table[3][3]) {
		length = 3;
		this->table = new float*[length];
		for (int i = 0; i < length; ++i) {
			this->table[i] = new float[length];
			for (int j = 0; j < length;j++) {
				this->table[i][j] = table[i][j];
			}
		}

	}

	Macierz::Macierz(float table[4][4]) {
		length = 4;
		this->table = new float*[length];
		for (int i = 0; i < length; ++i) {
			this->table[i] = new float[length];
			for (int j = 0; j < length;j++) {
				this->table[i][j] = table[i][j];
			}
		}

	}

	Macierz Macierz::operator=(const Macierz other) {
		if (this != &other) {
			for (int i = 0;i < length;i++) {
				delete this->table[i];
			}
			delete this->table;
			this->length = other.length;
			remakeTable(length);
			for (int i = 0;i < length;i++) {
				for (int j = 0;j < length;j++) {
					this->table[i][j] = other.table[i][j];
				}
			}
		}
		return *this;
	}

	Macierz Macierz::operator+(const Macierz other) {
		if (this->length != other.length)
		{
			throw "Matrixes have diffrent length";
		}

		Macierz nowy = Macierz(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				nowy.table[i][j] =this->table[i][j]+ other.table[i][j];
			}
		}
		return nowy;
	}

	Macierz Macierz::operator+=(const Macierz other) {
		if (this->length != other.length)
		{
			throw "Matrixes have diffrent length";
		}
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				this->table[i][j] += other.table[i][j];
			}
		}
		return *this;
	}

	Macierz Macierz::operator-(const Macierz other) {
		if (this->length != other.length)
		{
			throw "Matrixes have diffrent length";
		}

		Macierz nowy = Macierz(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				nowy.table[i][j] = this->table[i][j] - other.table[i][j];
			}
		}
		return nowy;
	}

	Macierz Macierz::operator-=(const Macierz other) {
		if (this->length != other.length)
		{
			throw "Matrixes have diffrent length";
		}
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				this->table[i][j] -= other.table[i][j];
			}
		}
		return *this;
	}

	Macierz Macierz::operator*(const int other) {
		Macierz nowy = Macierz(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				nowy.table[i][j] = this->table[i][j] * other;
			}
		}
		return nowy;
	}

	Macierz Macierz::operator*=(const int other) {
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				this->table[i][j] *= other;
			}
		}
		return *this;
	}
	Macierz Macierz::operator*(const float other) {
		Macierz nowy = Macierz(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				nowy.table[i][j] = this->table[i][j] * other;
			}
		}
		return nowy;
	}

	Macierz Macierz::operator*=(const float other) {
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				this->table[i][j] *= other;
			}
		}
		return *this;
	}
	Macierz Macierz::operator*(const Macierz other) {
		if (this->length != other.length)
		{
			throw "Matrixes have diffrent length";
		}
		Macierz nowy = Macierz(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				nowy.table[i][j] = 0;
				for (int z = 0;z < length;z++) {
					nowy.table[i][j] += this->table[i][z] * other.table[z][j];
				}
			}
		}
		return nowy;
	}
	Macierz Macierz::operator*=(const Macierz other) {
		Macierz nowy = Macierz(length);
		nowy = *this * other;
		*this = nowy;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Macierz& dt)
	{
		for (int i = 0; i < dt.length; i++)
		{
			for (int j = 0; j < dt.length; j++)
				os <<std::setw(5)<< dt.table[i][j]<<std::setw(5);
			os << "\n";
		}
		return os;
	}
	float Macierz::getValue(int x, int y) {
		if (x > length || y > length) {
			throw "Out of Bounds of Martix";
		}
		return this->table[x][y];
	}
	
	void Macierz::getValue(int x, int y,float value) {
		if (x > length || y > length) {
			throw "Out of Bounds of Martix";
		}
		this->table[x][y] = value;
	}
	
	float ** Macierz::getTable() {
		return this->table;
	}
	void Macierz::identityfyMatrix() {//zrób macierz jednostkow¹
		for (int i = 0;i < length;i++) {
			delete this->table[i];
		}
		delete this->table;
		remakeTable(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				if (i == j)
					this->table[i][j] = 1;
				else
					this->table[i][j] = 0;
			}
		}
	}
	void Macierz::transpose() {//Macierz transponowana
		Macierz nowy = Macierz(length);
		for (int i = 0; i < length; ++i)
			for (int j = 0; j < length; ++j)
			{
				nowy.table[j][i] = this->table[i][j];
			}
		*this = nowy;
	}

	float Macierz::det(float ** a,int n) {//Wyznacznik macierzy
		float det = 0;
		float ** submatrix = new float*[n];
		for (int i = 0; i < n; ++i)
			submatrix[i] = new float[n];
		if (n == 2)
			return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
		else {
			for (int x = 0; x < n; x++) {
				int subi = 0;
				for (int i = 1; i < n; i++) {
					int subj = 0;
					for (int j = 0; j < n; j++) {
						if (j == x)
							continue;
						submatrix[subi][subj] = a[i][j];
						subj++;
					}
					subi++;
				}
				det = det + (pow(-1, x) * a[0][x] * this->det(submatrix, n - 1));
			}
		}
		return det;
	}


	Macierz Macierz::inverseMatrix() {//Odwracanie macierzy
		Macierz nowy = Macierz(this->length);
		odwracanie(this->table, this->length);
		return nowy;
	}
