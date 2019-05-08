#include <iostream>
#include <math.h>

class Wektor {
private:
	float x, y, z, w;

public:
	//zadanie
	Wektor(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = 0.0;
	}
	Wektor() {
		Wektor(0.0, 0.0, 0.0);
	}
	Wektor(float value) {
		//???
	}

	Wektor(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	Wektor(float table[]) {
		Wektor(table[0], table[1], table[2], table[3]);
	}

	Wektor operator=(const Wektor other) {
		if (this != &other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
		}
		return *this;
	}

	Wektor operator+(const Wektor other) {
		Wektor nowy = Wektor(this->x + other.x, 
			this->y + other.y, 
			this->z + other.z, 
			this->w + other.w);
		return nowy;
	}

	Wektor operator+=(const Wektor other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
		return *this;
	}
	
	Wektor operator-(const Wektor other) {
		Wektor nowy = Wektor(this->x - other.x,
			this->y - other.y,
			this->z - other.z,
			this->w - other.w);
		return nowy;
	}

	Wektor operator-=(const Wektor other) {
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
		return *this;
	}

	Wektor operator*(const int other) {
		Wektor nowy = Wektor(this->x * other,
			this->y * other,
			this->z * other,
			this->w * other);
		return nowy;
	}

	Wektor operator*=(const int other) {
			this->x * other;
			this->y * other;
			this->z * other;
			this->w * other;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const Wektor& dt)
	{
		os << "x:" << dt.x << " " << "y:" << dt.y << " " << "z:" << dt.z << " " << "w:" << dt.w;
		return os;
	}
	float getX() {
		return this->x;
	}
	float getY() {
		return this->y;
	}
	float getZ() {
		return this->z;
	}
	float getW() {
		return this->w;
	}
	void setX(float value) {
		this->x = value;
	}
	void setY(float value) {
		this->y = value;
	}
	void setZ(float value) {
		this->z = value;
	}
	void setW(float value) {
		this->w = value;
	}
	Wektor normalize() {
		float length = getLength();
		Wektor nowy(x / length, y / length, z / length);
		return nowy;
	}
	Wektor crossProduct(const Wektor other) {//Iloczny wektorowy
		Wektor nowy = Wektor(y*other.z-z*other.y,z*other.x-x*other.z,x*other.y -y*other.x);
		return nowy;
	}
	float dotProduct(const Wektor other) {//Iloczyn skalarny
		float wynik = x * other.x + y * other.y + z * other.z;
		return wynik;
	}
	float getLength() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	//w³asne
	float operator[](int x) {
		switch (x)
		{
		case 0:
		return x;
		case 1:
		return y;
		case 2:
		return z;
		case 3:
		return w;
		default:
			break;
		}
	}
};