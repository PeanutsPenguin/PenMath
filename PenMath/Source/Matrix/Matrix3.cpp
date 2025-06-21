#include "Matrix/Matrix3.h"

using namespace PenMath;

#pragma region CONSTRUCTORS

Matrix3::Matrix3(float value)
{
	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			if (index == jindex) 
				this->m_matrix[index][jindex] = value;
			else 
				this->m_matrix[index][jindex] = 0;
}

Matrix3::Matrix3(const Vector3f& vecA, const Vector3f& vecB, const Vector3f& vecC)
{
	this->m_matrix[0] = vecA;
	this->m_matrix[1] = vecB;
	this->m_matrix[2] = vecC;
}

Matrix3::Matrix3(std::initializer_list<float> values)
{
	int valuesIndex = 0;
	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
		{
			this->m_matrix[index][jindex] = *values.begin() + valuesIndex;
			valuesIndex++;
		}
}


#pragma endregion

#pragma region OPERATORS

Vector3f& Matrix3::operator[](size_t index) noexcept
{
	return this->m_matrix[index];
}

const Vector3f& PenMath::Matrix3::operator[](size_t index) const noexcept
{
	return this->m_matrix[index];
}

bool Matrix3::operator==(const Matrix3& toCompare) const
{
	return  this->m_matrix[0] == toCompare.m_matrix[0] && 
			this->m_matrix[1] == toCompare.m_matrix[1] && 
			this->m_matrix[2] == toCompare.m_matrix[2];
}

bool Matrix3::operator!=(const Matrix3& toCompare) const
{
	return  this->m_matrix[0] != toCompare.m_matrix[0] ||
			this->m_matrix[1] != toCompare.m_matrix[1] ||
			this->m_matrix[2] != toCompare.m_matrix[2];
}

Matrix3 Matrix3::operator*(const Matrix3& mat) const
{
	Matrix3 matrix;

	for (size_t index = 0; index < 3; ++index)
	{
		for (size_t jindex = 0; jindex < 3; ++jindex)
		{
			matrix[jindex][index] = 0;
			for (size_t kindex = 0; kindex < 3; ++kindex)
				matrix[jindex][index] += this->m_matrix[kindex][index] * mat[jindex][kindex];
		}
	}
	return matrix;
}

Matrix3& Matrix3::operator*=(const Matrix3& mat)
{
	*this = std::move(this->operator*(mat));
	return *this;
}

Matrix3 Matrix3::operator*(float value) const
{
	Matrix3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] *= value;

	return matrix;
}

Matrix3& Matrix3::operator*=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] *= value;

	return *this;
}

Matrix3 Matrix3::operator+(const Matrix3& mat) const
{
	Matrix3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] += mat[index];

	return matrix;
}

Matrix3& Matrix3::operator+=(const Matrix3& mat)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] += mat[index];

	return *this;
}

Matrix3 Matrix3::operator+(float value) const
{
	Matrix3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] += value;

	return matrix;
}

Matrix3& Matrix3::operator+=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] += value;

	return *this;
}

Matrix3 Matrix3::operator-(const Matrix3& mat) const
{
	Matrix3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] -= mat[index];

	return matrix;
}

Matrix3& Matrix3::operator-=(const Matrix3& mat)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] -= mat[index];

	return *this;
}

Matrix3 Matrix3::operator-(float value) const
{
	Matrix3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] -= value;

	return matrix;
}

Matrix3& Matrix3::operator-=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] -= value;

	return *this;
}

Matrix3 Matrix3::operator/(const Matrix3& mat) const
{
	Matrix3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] /= mat[index];

	return matrix;
}

Matrix3& Matrix3::operator/=(const Matrix3& mat)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] /= mat[index];

	return *this;
}

Matrix3 Matrix3::operator/(float value) const
{
	Matrix3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] /= value;

	return matrix;
}

Matrix3& Matrix3::operator/=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] /= value;

	return *this;
}

#pragma endregion

#pragma region FUNC

void Matrix3::toIdentity(void)
{
	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			this->m_matrix[index][jindex] = (index == jindex) ? 1 : 0;
}

void Matrix3::empty(void)
{
	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			this->m_matrix[index][jindex] = 0;
}

void Matrix3::toTranspose(void)
{
	Matrix3 matrix;

	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			matrix[jindex][index] = this->m_matrix[index][jindex];

	*this = matrix;
}

float Matrix3::getDeterminant(void) const
{
	return (
		+ (this->m_matrix[0][0] * this->m_matrix[1][1] * this->m_matrix[2][2])
		+ (this->m_matrix[0][1] * this->m_matrix[1][2] * this->m_matrix[2][0])
		+ (this->m_matrix[0][2] * this->m_matrix[1][0] * this->m_matrix[2][1])
		- (this->m_matrix[0][0] * this->m_matrix[1][2] * this->m_matrix[2][1])
		- (this->m_matrix[0][1] * this->m_matrix[1][0] * this->m_matrix[2][2])
		- (this->m_matrix[0][2] * this->m_matrix[1][1] * this->m_matrix[2][0])
		);
}

#pragma endregion