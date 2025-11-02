#include "Matrix/Mat2.h"

namespace PenMath
{
#pragma region CONSTRUCTORS
	Mat2::Mat2(float value)
	{
		for (size_t i = 0; i < 2; ++i) 
		{
			for (size_t j = 0; j < 2; ++j) 
			{
				if (i == j)
					m_matrix[i][j] = value;
				else
					m_matrix[i][j] = 0;
			}
		}
	}

	Mat2::Mat2(const Vector2f& a, const Vector2f& b) 
	{
		this->m_matrix[0] = a;
		this->m_matrix[1] = b;
	}

#if defined(INIALIZER_LIST)
	Mat2::Mat2(std::initializer_list<float> initList)
	{
		if (initList.size() != 2 * 2) {
			throw std::invalid_argument("Invalid initializer list dimensions");
		}

		size_t index = 0;
		for (auto& element : initList)
		{
			for (int jindex = 0; jindex < 2; ++jindex)
				this->m_matrix[index][jindex] = std::move(element);

			++index;
		}
	}

#endif
#pragma endregion

#pragma region FUNCTION
	Mat2& Mat2::toIdentity(void)
	{
		for (size_t i = 0; i < 2; ++i)
		{
			for (size_t j = 0; j < 2; ++j)
			{
				if (i == j)
					m_matrix[i][j] = 1;
				else
					m_matrix[i][j] = 0;
			}
		}

		return *this;
	}

	Mat2& Mat2::empty(void)
	{
		for (size_t i = 0; i < 2; ++i)
			for (size_t j = 0; j < 2; ++j)
				m_matrix[i][j] = 0;

		return *this;
	}

	Mat2 Mat2::getTranspose(void)
	{
		Mat2 result;

		for (size_t index = 0; index < 2; ++index)
			for (size_t jindex = 0; jindex < 2; ++jindex)
				result[jindex][index] = (*this)[index][jindex];

		return result;
	}

	Mat2& Mat2::toTranspose(void)
	{
		*this = std::move(this->getTranspose());

		return *this;
	}

	float Mat2::getDeterminant(void) const
	{
		return ((*this)[0][0] * (*this)[1][1]) - ((*this)[0][1] * (*this)[1][0]);
	}


#pragma endregion

#pragma region STATIC_FUNC

	Mat2 Mat2::zero(void) 
	{
		Mat2 result;

		for (size_t index = 0; index < 2; ++index)
			for (size_t jindex = 0; jindex < 2; ++jindex)
				result[index][jindex] = 0;

		return result;
	}

	Mat2 Mat2::identity(void)
	{
		Mat2 result;

		for (size_t index = 0; index < 2; ++index)
			for (size_t jindex = 0; jindex < 2; ++jindex)
				result[index][jindex] = std::move((index == jindex) ? 1 : 0);

		return result;
	}
#pragma endregion


#pragma region OPERATORS
	bool PenMath::Mat2::operator==(const Mat2& toCompare) const
	{
		return this->m_matrix[0] == toCompare.m_matrix[0] && this->m_matrix[1] == toCompare.m_matrix[1];
	}

	bool PenMath::Mat2::operator!=(const Mat2& toCompare) const
	{
		return this->m_matrix[0] != toCompare.m_matrix[0] || this->m_matrix[1] != toCompare.m_matrix[1];
	}

	Mat2 Mat2::operator*(const Mat2& toMultiply) const
	{
		Mat2 result;

		for (size_t index = 0; index < 2; ++index)
		{
			for (size_t jindex = 0; jindex < 2; ++jindex)
			{
				result[jindex][index] = 0;

				for (size_t kindex = 0; kindex < 2; ++kindex)
					result[jindex][index] += (*this)[kindex][index] * toMultiply[jindex][kindex];
			}
		}

		return result;
	}

	Mat2& Mat2::operator*=(const Mat2& toMultiply) 
	{
		*this = std::move(this->operator*(toMultiply));
		return *this;
	}

	Mat2 Mat2::operator*(const float value) const
	{
		Mat2 result = *this;

		for (size_t index = 0; index < 2; ++index)
			result[index] *= value;

		return result;
	}

	Mat2& Mat2::operator*=(const float value)
	{
		*this = std::move(this->operator*(value));
		return *this;
	}

	Mat2 Mat2::operator+(const Mat2& toAdd) const
	{
		Mat2 result = *this;

		for (size_t index = 0; index < 2; ++index)
			result[index] += toAdd[index];

		return result;
	}

	Mat2& Mat2::operator+=(const Mat2& toAdd)
	{
		*this = std::move(this->operator+(toAdd));
		return *this;
	}

	Mat2 Mat2::operator-(const Mat2& toSubstract) const
	{
		Mat2 result = *this;

		for (size_t index = 0; index < 2; ++index)
			result[index] -= toSubstract[index];

		return result;
	}

	Mat2& Mat2::operator-=(const Mat2& toSubstract)
	{
		*this = std::move(this->operator-(toSubstract));
		return *this;
	}

#pragma endregion

}

