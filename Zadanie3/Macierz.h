#pragma once

#include <iostream>
#include <math.h>
#include <iomanip>

class Macierz
{
private:
	float ** table;
	int length;
	void remakeTable(int length);
	void fillTable(float value);
	void odwracanie(float **& A, int & n);



public:
	    Macierz(int length = 3);
		Macierz(float value, int length = 3);
		Macierz(float table[3][3]);

		Macierz(float table[4][4]);

		Macierz operator=(const Macierz other);

		Macierz operator+(const Macierz other);

		Macierz operator+=(const Macierz other);

		Macierz operator-(const Macierz other);

		Macierz operator-=(const Macierz other);

		Macierz operator*(const int other);

		Macierz operator*=(const int other);
		Macierz operator*(const float other);

		Macierz operator*=(const float other);
		Macierz operator*(const Macierz other);
		Macierz operator*=(const Macierz other);
		friend std::ostream& operator<<(std::ostream& os, const Macierz& dt);
		float getValue(int x, int y);

		void getValue(int x, int y, float value);

		float ** getTable();
		void identityfyMatrix();
		void transpose();

		float det(float ** a, int n = 3);


		Macierz inverseMatrix();
};