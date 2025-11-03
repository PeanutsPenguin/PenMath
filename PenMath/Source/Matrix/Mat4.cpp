#include "Matrix/Mat4.h"

#define VECTOR3_CAST
#include "Matrix/Mat3.h"

using namespace PenMath;
#pragma region CONSTRUCTORS
Mat4::Mat4(float value)
{
	for (size_t index = 0; index < 4; ++index)
		for (size_t jindex = 0; jindex < 4; ++jindex)
			if (index == jindex) (*this)[index][jindex] = value;
			else (*this)[index][jindex] = 0.f;
}

Mat4::Mat4(const Vector4f a, const Vector4f b, const Vector4f c, const Vector4f d)
{
	(*this)[0] = a;
	(*this)[1] = b;
	(*this)[2] = c;
	(*this)[3] = d;
}
#pragma endregion

#pragma region BASIC_MATRIX4
Mat4 Mat4::zero(void)
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
		for (size_t jindex = 0; jindex < 4; ++jindex)
			matrix[index][jindex] = 0.f;

	return matrix;
}

Mat4 Mat4::identity(void)
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
		for (size_t jindex = 0; jindex < 4; ++jindex)
			matrix[index][jindex] = std::move((index == jindex) ? 1.f : 0.f);

	return matrix;
}
#pragma endregion

#pragma region OPERATORS
Mat4 Mat4::operator*(const Mat4& rhs) const
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
	{
		for (size_t jindex = 0; jindex < 4; ++jindex)
		{
			matrix[jindex][index] = 0.f;
			for (size_t kindex = 0; kindex < 4; ++kindex)
				matrix[jindex][index] += (*this)[kindex][index] * rhs[jindex][kindex];
		}
	}
	return matrix;
}

Mat4& Mat4::operator*=(const Mat4& rhs)
{
	*this = std::move(this->operator*(rhs));
	return *this;
}

Mat4 Mat4::operator*(float rhs) const
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
	{
		for (size_t jindex = 0; jindex < 4; ++jindex)
		{
			matrix[index][jindex] = (*this)[index][jindex] * rhs;
		}
	}

	return matrix;
}

Mat4& Mat4::operator*=(float rhs)
{
	*this = std::move(this->operator*(rhs));
	return *this;
}

Mat4 Mat4::operator+(const Mat4& rhs) const
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
	{
		for (size_t jindex = 0; jindex < 4; ++jindex)
		{
			matrix[index][jindex] = (*this)[index][jindex] + rhs[index][jindex];
		}
	}

	return matrix;
}

Mat4& Mat4::operator+=(const Mat4& rhs)
{
	*this = std::move(this->operator+(rhs));
	return *this;
}

Mat4 PenMath::Mat4::operator-(const Mat4& rhs) const
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
	{
		for (size_t jindex = 0; jindex < 4; ++jindex)
		{
			matrix[index][jindex] = (*this)[index][jindex] - rhs[index][jindex];
		}
	}

	return matrix;
}

Mat4& Mat4::operator-=(const Mat4& rhs)
{
	*this = std::move(this->operator-(rhs));
	return *this;
}
#pragma endregion

#pragma region FUNCTION
Mat4& Mat4::toIdentity(void)
{
	for (size_t index = 0; index < 4; ++index)
		for (size_t jindex = 0; jindex < 4; ++jindex)
			(*this)[index][jindex] = std::move((index == jindex) ? 1.f : 0.f);

	return *this;
}

Mat4& Mat4::empty(void)
{
	for (size_t index = 0; index < 4; ++index)
		for (size_t jindex = 0; jindex < 4; ++jindex)
			(*this)[index][jindex] = 0.f;

	return *this;
}

Mat4 Mat4::getTranspose(void) const
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
		for (size_t jindex = 0; jindex < 4; ++jindex)
			matrix[jindex][index] = (*this)[index][jindex];

	return matrix;
}

Mat4& Mat4::toTranspose(void)
{
	*this = std::move(this->getTranspose());
	return *this;
}

float Mat4::getDeterminant(void) const
{
	float determinant = 0;

	for (size_t index = 0; index < 4; ++index)
	{
		Mat3 matrix = std::move(this->getMinor(index, 0));
		determinant += ((index) % 2 > 0 ? -1 : 1) * (*this)[index][0] * matrix.getDeterminant();
	}

	return determinant;
}

Mat3 Mat4::getMinor(size_t row, size_t column) const
{
	Mat3 matrix;

	size_t zindex = 0;
	for (size_t index = 0; index < 4; ++index)
	{
		size_t kindex = 0;
		for (size_t jindex = 0; jindex < 4; ++jindex)
		{
			if (index == row || jindex == column) continue;

			matrix[zindex][kindex] = (*this)[index][jindex];
			++kindex;
		}

		if (index != row) ++zindex;
	}

	return matrix;
}

Mat4 Mat4::getMinorsDeterminant(void) const
{
	Mat4 matrix;

	for (size_t index = 0; index < 4; ++index)
	{
		for (size_t jindex = 0; jindex < 4; ++jindex)
		{
			matrix[index][jindex] = this->getMinor(index, jindex).getDeterminant();
		}
	}

	return matrix;
}

Mat4 Mat4::getCofactors(void) const
{
	Mat4 matrix = std::move(this->getMinorsDeterminant());

	for (size_t index = 0; index < 4; ++index)
	{
		for (size_t jindex = 0; jindex < 4; ++jindex)
		{
			matrix[index][jindex] *= ((index + jindex) % 2 > 0 ? -1 : 1);
		}
	}

	return matrix;
}

Mat4 Mat4::getInverse(void) const
{
	Mat4 matrix = this->getCofactors().toTranspose();
	matrix *= (1 / this->getDeterminant());

	return matrix;
}
#pragma endregion

#pragma region STATIC_FUNC
Mat4 Mat4::translate(const Vector3f& translator)
{
	Mat4 matrix = Mat4::identity();
	matrix[3][0] = translator[0];
	matrix[3][1] = translator[1];
	matrix[3][2] = translator[2];

	return matrix;
}

Mat4 Mat4::rotate(const Vector3f& rotator)
{
	Mat4 rotate = Mat4::identity();
	Mat4 matrix = Mat4::identity();

	float c = cos(rotator[0]);
	float s = sin(rotator[0]);

	matrix[1][1] = c;
	matrix[2][2] = c;

	matrix[1][2] = s;
	matrix[2][1] = -s;

	rotate *= matrix;

	matrix.toIdentity();

	c = cos(rotator[1]);
	s = sin(rotator[1]);

	matrix[0][0] = c;
	matrix[2][2] = c;

	matrix[0][2] = -s;
	matrix[2][0] = s;

	rotate *= matrix;

	matrix.toIdentity();

	c = cos(rotator[2]);
	s = sin(rotator[2]);

	matrix[0][0] = c;
	matrix[1][1] = c;

	matrix[0][1] = s;
	matrix[1][0] = -s;

	rotate *= matrix;
	return rotate;
}

Mat4 Mat4::scale(const Vector3f& scalor)
{
	Mat4 matrix = Mat4::identity();
	matrix[0][0] = scalor[0];
	matrix[1][1] = scalor[1];
	matrix[2][2] = scalor[2];

	return matrix;
}

Mat4 Mat4::Perspective(float fov, float aspect, float near, float far)
{
	Mat4 matrix = Mat4::zero();

	const float S = tan(fov / 2.f);

	matrix[0][0] = 1.f / (aspect * S);
	matrix[1][1] = 1.f / (S);
	matrix[2][2] = -(far + near) / (far - near);
	matrix[2][3] = -1.f;
	matrix[3][2] = -(2.f * far * near) / (far - near);

	return matrix;
}

Mat4 Mat4::LookAt(const Vector3f& eye, const Vector3f& center, const Vector3f& up)
{
	Mat4 mat = Mat4::identity();

	Vector3f f = Vector3f::normal(center - eye);

	Vector3f s = Vector3f::normal(Vector3f::cross(up, f));

	Vector3f u = Vector3f::cross(f, s);

	mat[0][0] = s.x;
	mat[1][0] = s.y;
	mat[2][0] = s.z;

	mat[0][1] = u.x;
	mat[1][1] = u.y;
	mat[2][1] = u.z;

	mat[0][2] = f.x;
	mat[1][2] = f.y;
	mat[2][2] = f.z;

	mat[3][0] = -Vector3f::dot(s, eye);
	mat[3][1] = -Vector3f::dot(u, eye);
	mat[3][2] = -Vector3f::dot(f, eye);

	return mat;
}

Mat4 Mat4::Ortho(float left, float right, float bottom, float top)
{
	Mat4 mat = Mat4::identity();

	mat[0][0] = 2.f / (right - left);
	mat[1][1] = 2.f / (top - bottom);
	mat[2][2] = -1.f;
	mat[3][0] = -(right + left) / (right - left);
	mat[3][1] = -(top + bottom) / (top - bottom);

	return mat;
}

Mat4 Mat4::Ortho(float left, float right, float bottom, float top, float far, float near)
{
	Mat4 mat = Mat4::identity();

	mat[0][0] = 2.f / (right - left);
	mat[1][1] = 2.f / (top - bottom);
	mat[2][2] = 2.f / (far - near);
	mat[3][0] = -(right + left) / (right - left);
	mat[3][1] = -(top + bottom) / (top - bottom);
	mat[3][2] = -(far + near) / (far - near);

	return mat;
}
#pragma endregion

Vector4f operator*(const Vector4f& vec, const Mat4& mat)
{
	Vector4f vector;

	for (size_t index = 0; index < 4; ++index)
	{
		vector[index] = 0.f;
		for (size_t kindex = 0; kindex < 4; ++kindex)
			vector[index] += mat[kindex][index] * vec[kindex];
	}

	return vector;
}
