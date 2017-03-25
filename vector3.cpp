#include "vector3.h"

template <class T>
Vector3<T> Vector3<T>::operator-(Vector3<T> other)
{
	Vector3 result;

	result.x = this->x - other.x;
	result.y = this->y - other.y;
	result.z = this->z - other.z;

	return result;
}

template <class T>
Vector3<T> Vector3<T>::operator+(Vector3<T> other)
{
	Vector3<T> result;

	result.x = this->x + other.x;
	result.y = this->y + other.y;
	result.z = this->z + other.z;
	result.z = this->z + other.z;

	return result;
}

template <class T>
Vector3<T> Vector3<T>::operator/(T other)
{
	Vector3<T> result;

	result.x = this->x / other;
	result.y = this->y / other;
	result.z = this->z / other;

	return result;
}

template <class T>
Vector3<T> Vector3<T>::operator*(T other)
{
	Vector3<T> result;

	result.x = this->x * other;
	result.y = this->y * other;
	result.z = this->z * other;

	return result;
}

template <class T>
Vector3<T> Vector3<T>::cross(Vector3<T> vector_1, Vector3<T> vector_2)
{
	Vector3<T> result;

	result.x = vector_1.y * vector_2.z - vector_2.y* vector_1.z;
	result.y = vector_1.z * vector_2.x - vector_2.z* vector_1.x;
	result.z = vector_1.x * vector_2.y - vector_2.x* vector_1.y;

	return result;
}

template <class T>
T Vector3<T>::dot(Vector3<T> vector_1, Vector3<T> vector_2)
{
	return vector_1.x * vector_2.x + vector_1.y * vector_2.y + vector_1.z * vector_2.z;
}
