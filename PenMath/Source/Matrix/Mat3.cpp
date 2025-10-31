#include "Matrix/Mat3.h"

#define VECTOR2_CAST
#include "Matrix/Mat2.h"

using namespace PenMath;

#pragma region CONSTRUCTORS

Mat3::Mat3(float value)
{
	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			if (index == jindex) 
				this->m_matrix[index][jindex] = value;
			else 
				this->m_matrix[index][jindex] = 0;
}

Mat3::Mat3(const Vector3f& vecA, const Vector3f& vecB, const Vector3f& vecC)
{
	this->m_matrix[0] = vecA;
	this->m_matrix[1] = vecB;
	this->m_matrix[2] = vecC;
}

#pragma endregion

#pragma region BASIC_MATRIX3
Mat3 Mat3::zero(void) 
{
	Mat3 matrix;

	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			matrix[index][jindex] = 0;

	return matrix;
}

Mat3 Mat3::identity(void)
{
	Mat3 matrix;

	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			matrix[index][jindex] = std::move((index == jindex) ? 1 : 0);

	return matrix;
}
#pragma endregion

#pragma region OPERATORS

Vector3f& Mat3::operator[](size_t index) noexcept
{
	return this->m_matrix[index];
}

const Vector3f& PenMath::Mat3::operator[](size_t index) const noexcept
{
	return this->m_matrix[index];
}

bool Mat3::operator==(const Mat3& toCompare) const
{
	return  this->m_matrix[0] == toCompare.m_matrix[0] && 
			this->m_matrix[1] == toCompare.m_matrix[1] && 
			this->m_matrix[2] == toCompare.m_matrix[2];
}

bool Mat3::operator!=(const Mat3& toCompare) const
{
	return  this->m_matrix[0] != toCompare.m_matrix[0] ||
			this->m_matrix[1] != toCompare.m_matrix[1] ||
			this->m_matrix[2] != toCompare.m_matrix[2];
}

Mat3 Mat3::operator*(const Mat3& mat) const
{
	Mat3 matrix;

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

Mat3& Mat3::operator*=(const Mat3& mat)
{
	*this = std::move(this->operator*(mat));
	return *this;
}

Mat3 Mat3::operator*(float value) const
{
	Mat3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] *= value;

	return matrix;
}

Mat3& Mat3::operator*=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] *= value;

	return *this;
}

Mat3 Mat3::operator+(const Mat3& mat) const
{
	Mat3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] += mat[index];

	return matrix;
}

Mat3& Mat3::operator+=(const Mat3& mat)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] += mat[index];

	return *this;
}

Mat3 Mat3::operator+(float value) const
{
	Mat3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] += value;

	return matrix;
}

Mat3& Mat3::operator+=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] += value;

	return *this;
}

Mat3 Mat3::operator-(const Mat3& mat) const
{
	Mat3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] -= mat[index];

	return matrix;
}

Mat3& Mat3::operator-=(const Mat3& mat)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] -= mat[index];

	return *this;
}

Mat3 Mat3::operator-(float value) const
{
	Mat3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] -= value;

	return matrix;
}

Mat3& Mat3::operator-=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] -= value;

	return *this;
}

Mat3 Mat3::operator/(const Mat3& mat) const
{
	Mat3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] /= mat[index];

	return matrix;
}

Mat3& Mat3::operator/=(const Mat3& mat)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] /= mat[index];

	return *this;
}

Mat3 Mat3::operator/(float value) const
{
	Mat3 matrix = *this;

	for (size_t index = 0; index < 3; ++index)
		matrix[index] /= value;

	return matrix;
}

Mat3& Mat3::operator/=(float value)
{
	for (size_t index = 0; index < 3; ++index)
		this->m_matrix[index] /= value;

	return *this;
}

#pragma endregion

#pragma region FUNC

void Mat3::toIdentity(void)
{
	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			this->m_matrix[index][jindex] = (index == jindex) ? 1 : 0;
}

void Mat3::empty(void)
{
	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			this->m_matrix[index][jindex] = 0;
}

Mat3& Mat3::toTranspose(void)
{
	*this = std::move(this->getTranspose());
	return *this;
}

Mat3 Mat3::getTranspose(void)
{
	Mat3 matrix;

	for (size_t index = 0; index < 3; ++index)
		for (size_t jindex = 0; jindex < 3; ++jindex)
			matrix[jindex][index] = this->m_matrix[index][jindex];

	return matrix;
}

float Mat3::getDeterminant(void) const
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

Mat2 PenMath::Mat3::getMinor(size_t row, size_t column) const
{
	Mat2 matrix;

	size_t zindex = 0;
	for (size_t index = 0; index < 3; ++index)
	{
		size_t kindex = 0;
		for (size_t jindex = 0; jindex < 3; ++jindex)
		{
			if (index == row || jindex == column) continue;

			matrix[zindex][kindex] = (*this)[index][jindex];
			++kindex;
		}

		if (index != row) ++zindex;
	}

	return matrix;
}

Mat3 PenMath::Mat3::getMinorsDeterminant(void) const
{
	Mat3 matrix;

	for (size_t index = 0; index < 3; ++index)
	{
		for (size_t jindex = 0; jindex < 3; ++jindex)
		{
			matrix[index][jindex] = this->getMinor(index, jindex).getDeterminant();
		}
	}

	return matrix;
}

Mat3 PenMath::Mat3::getCofactors(void) const
{
	Mat3 matrix = std::move(this->getMinorsDeterminant());

	for (size_t index = 0; index < 3; ++index)
	{
		for (size_t jindex = 0; jindex < 3; ++jindex)
		{
			matrix[index][jindex] *= ((index + jindex) % 2 > 0 ? -1 : 1);
		}
	}

	return matrix;
}

Mat3 PenMath::Mat3::getInverse(void) const
{
	Mat3 matrix = this->getCofactors().toTranspose();
	matrix *= (1 / this->getDeterminant());

	return matrix;
}
#pragma endregion

#pragma region STATIC_FUNC
Mat3 PenMath::Mat3::translate(const Vector2f& translator)
{
	Mat3 matrix = Mat3::identity();
	matrix[0][2] = translator[0];
	matrix[1][2] = translator[1];

	return matrix;
}

Mat3 PenMath::Mat3::rotate(const Vector2f& rotator)
{
	Mat3 rotate = Mat3::identity();
	Mat3 matrix = Mat3::identity();

	matrix[1][1] = std::cosf(rotator[0]);
	matrix[2][2] = std::cosf(rotator[0]);

	matrix[2][1] = std::sinf(rotator[0]);
	matrix[1][2] = -std::sinf(rotator[0]);

	rotate *= matrix;

	matrix.toIdentity();

	matrix[0][0] = std::cosf(rotator[1]);
	matrix[2][2] = std::cosf(rotator[1]);

	matrix[0][2] = -std::sinf(rotator[1]);
	matrix[2][0] = std::sinf(rotator[1]);

	rotate *= matrix;
	return rotate;
}

Mat3 PenMath::Mat3::scale(const Vector2f& scalor)
{
	Mat3 matrix = Mat3::identity();
	matrix[0][0] = scalor[0];
	matrix[2][2] = scalor[1];

	return matrix;
}
#pragma endregion
