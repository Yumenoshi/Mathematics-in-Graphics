#include "Macierz.h"

class Przeksztalcenia {
public:
	Macierz macierzSkalowania(float values[],int wymiar = 3)
	{
		Macierz wynik;
		if (wymiar == 3) {
			wynik =Macierz();
			wynik.getTable()[0][0] = values[0];
			wynik.getTable()[1][1] = values[1];
			wynik.getTable()[2][2] = 1.0f;
			
		}else 
		if (wymiar == 4) {
			wynik = Macierz(4);
			wynik.getTable()[0][0] = values[0];
			wynik.getTable()[1][1] = values[1];
			wynik.getTable()[2][2] = values[2];
			wynik.getTable()[3][3] = 1.0f;
			
		}
		return wynik;
	}
	Macierz macierzSkalowania(float x, float y)
	{
		float a[2] = { x,y };
		return macierzSkalowania(a,3);
	}
	Macierz macierzSkalowania(float x, float y, float z)
	{
		float a[3] = { x,y,z };
		return macierzSkalowania(a,4);
	}
	Macierz macierzSkalowania(float x, int wymiar = 3) 
	{
		Macierz wynik;
		if (wymiar == 3) {
			float a[2] = { x,x };
			wynik = macierzSkalowania(a, wymiar);
		}
		else if(wymiar==4){
			float a[3] = { x,x,x };
			wynik = macierzSkalowania(a, wymiar);
		}
		return wynik;
	}
	Macierz macierzObrotu3x3(float kat) {
		Macierz wynik;
		wynik = Macierz(3);
		wynik.getTable()[0][0] = cos(kat);
		wynik.getTable()[0][1] = -1 * sin(kat);
		wynik.getTable()[1][0] = sin(kat);
		wynik.getTable()[1][1] = cos(kat);
		wynik.getTable()[2][2] = 1.0f;
		return wynik;
	}
	Macierz macierzObrotu4x4(float kat,char axis) 
	{
		Macierz wynik;
		wynik = Macierz(4);
		if (axis == 'x') {
			wynik.getTable()[0][0] = 1.0f;
			wynik.getTable()[1][1] = cos(kat);
			wynik.getTable()[1][2] = -1 * sin(kat);
			wynik.getTable()[2][1] = sin(kat);
			wynik.getTable()[2][2] = cos(kat);
			wynik.getTable()[3][3] = 1.0f;
		}
		else if (axis == 'y') {
			wynik.getTable()[1][1] = 1.0f;
			wynik.getTable()[0][0] = cos(kat);
			wynik.getTable()[2][0] = -1 * sin(kat);
			wynik.getTable()[0][2] = sin(kat);
			wynik.getTable()[2][2] = cos(kat);
			wynik.getTable()[3][3] = 1.0f;
		}
		else if (axis == 'z') {
			wynik.getTable()[2][2] = 1.0f;
			wynik.getTable()[0][0] = cos(kat);
			wynik.getTable()[0][1] = -1 * sin(kat);
			wynik.getTable()[1][2] = sin(kat);
			wynik.getTable()[1][1] = cos(kat);
			wynik.getTable()[3][3] = 1.0f;
		}
		return wynik;
	}
	Macierz macierzTranslacji(float values[], int wymiar = 3)
	{
		Macierz wynik;
		if (wymiar == 3) {
			wynik = Macierz();
			wynik.getTable()[0][0] = 1.0f;
			wynik.getTable()[1][1] = 1.0f;
			wynik.getTable()[2][2] = 1.0f;
			wynik.getTable()[0][2] = values[0];
			wynik.getTable()[1][2] = values[1];

		}
		else
			if (wymiar == 4) {
				wynik = Macierz(4);
				wynik.getTable()[0][0] = 1.0f;
				wynik.getTable()[1][1] = 1.0f;
				wynik.getTable()[2][2] = 1.0f;
				wynik.getTable()[3][3] = 1.0f;
				wynik.getTable()[0][3] = values[0];
				wynik.getTable()[1][3] = values[1];
				wynik.getTable()[2][3] = values[2];

			}
		return wynik;
	}
	Macierz macierzTranslacji(float x, float y)
	{
		float a[2] = { x,y };
		return macierzTranslacji(a, 3);
	}
	Macierz macierzTranslacji(float x, float y, float z)
	{
		float a[3] = { x,y,z };
		return macierzTranslacji(a, 4);
	}
	Macierz macierzTranslacji(float x, int wymiar = 3)
	{
		Macierz wynik;
		if (wymiar == 3) {
			float a[2] = { x,x };
			wynik = macierzTranslacji(a, wymiar);
		}
		else if (wymiar == 4) {
			float a[3] = { x,x,x };
			wynik = macierzTranslacji(a, wymiar);
		}
		return wynik;
	}

};