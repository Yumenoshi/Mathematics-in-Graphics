#include <iostream>
#include <math.h>

class Macierz {
private:
	float ** table;
	int length;
	void remakeTable(int length) {
		this->length = length;
		float** table = new float*[length];
		for (int i = 0; i < length; ++i)
			table[i] = new float[length];
	}

public:
	Macierz(int length = 3) {
		remakeTable(length);
	}
	Macierz(float value,int length=3) {
		remakeTable(length);

	}
	Macierz(float table[3][3]) {
		length = 3;
		float** table = new float*[length];
		for (int i = 0; i < length; ++i) {
			this->table[i] = new float[length];
			for (int j = 0; j < length;j++) {
				this->table[i][j] = table[i][j];
			}
		}

	}

	Macierz(float table[4][4]) {
		length = 4;
		float** table = new float*[length];
		for (int i = 0; i < length; ++i) {
			this->table[i] = new float[length];
			for (int j = 0; j < length;j++) {
				this->table[i][j] = table[i][j];
			}
		}

	}

	Macierz operator=(const Macierz other) {
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

	Macierz operator+(const Macierz other) {
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

	Macierz operator+=(const Macierz other) {
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

	Macierz operator-(const Macierz other) {
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

	Macierz operator-=(const Macierz other) {
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

	Macierz operator*(const int other) {
		Macierz nowy = Macierz(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				nowy.table[i][j] = this->table[i][j] * other;
			}
		}
		return nowy;
	}

	Macierz operator*=(const int other) {
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				this->table[i][j] *= other;
			}
		}
		return *this;
	}
	Macierz operator*(const float other) {
		Macierz nowy = Macierz(length);
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				nowy.table[i][j] = this->table[i][j] * other;
			}
		}
		return nowy;
	}

	Macierz operator*=(const float other) {
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				this->table[i][j] *= other;
			}
		}
		return *this;
	}
	Macierz operator*(const Macierz other) {
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
	Macierz operator*=(const Macierz other) {
		Macierz nowy = Macierz(length);
		nowy = *this * other;
		*this = nowy;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const Macierz& dt)
	{
		for (i = 0; i < dt->length; i++)
		{
			for (j = 0; j < dt->length; j++)
				os << dt->table[i][j] << "  ";
			os << "\n";
		}
		return os;
	}
	float getValue(int x, int y) {
		if (x > length || y > length) {
			throw "Out of Bounds of Martix";
		}
		return this->table[x][y];
	}
	
	void getValue(int x, int y,float value) {
		if (x > length || y > length) {
			throw "Out of Bounds of Martix";
		}
		this->table[x][y] = value;
	}
	
	float ** getTable() {
		return this->table;
	}
	void identityfyMatrix() {//zrób macierz jednostkow¹
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
	void transpose() {//Macierz transponowana
		Macierz nowy = Macierz(length);
		for (int i = 0; i < length; ++i)
			for (int j = 0; j < length; ++j)
			{
				nowy.table[j][i] = this->table[i][j];
			}
		*this = nowy;
	}

	float det(float ** a,int n=3) {//Wyznacznik macierzy
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

	//??????
	/*Macierz inverseMatrix() {//Obracanie macierzy
		Macierz nowy = Macierz(this->length);
		float det = this->det(this->getTable,length);
		if (det == 0)
			throw "Wyznacznik równy zero, macierz osobliwa, obracanie niemo¿liwe";
		float a = 1 / det;
		for (int i = 0;i < length;i++) {
			for (int j = 0;j < length;j++) {
				//nowy.table[i][j]=1/det*
			}
		}

		return nowy;
	}*/
};