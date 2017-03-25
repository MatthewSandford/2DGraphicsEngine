#pragma once

#include <math.h>

//General purpose vector3 class

template <class T> class Vector3
{
public:

	Vector3() : x(0), y(0), z(0) {};								
	Vector3(T x, T y, T z) : x(x), y(y), z(z) {};					
	~Vector3() {};													

	Vector3<T>  operator-(Vector3<T>  other);						
	Vector3<T>  operator+(Vector3<T>  other);						
	Vector3<T>  operator/(T other);									
	Vector3<T>  operator*(T other);									
	
	static Vector3<T> cross(Vector3<T> vector_1, Vector3<T> v2);	
	static T dot(Vector3<T>  vector_1, Vector3<T>  v2);				

	T x, y, z;	

protected:

private:

};
