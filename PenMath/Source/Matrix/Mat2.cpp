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

	Mat2::Mat2(const Vector2& a, const Vector2& b) 
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
	Mat2& Mat2::toIdentity()
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

	Mat2& Mat2::clear()
	{
		for (size_t i = 0; i < 2; ++i)
			for (size_t j = 0; j < 2; ++j)
				m_matrix[i][j] = 0;

		return *this;
	}

	Mat2 Mat2::getTranspose()
	{
		Mat2 result;

		for (size_t index = 0; index < 2; ++index)
			for (size_t jindex = 0; jindex < 2; ++jindex)
				result[jindex][index] = (*this)[index][jindex];

		return result;
	}

	Mat2& Mat2::toTranspose()
	{
		*this = std::move(this->getTranspose());

		return *this;
	}

	float Mat2::getDeterminant()
	{
		return ((*this)[0][0] * (*this)[1][1]) - ((*this)[0][1] * (*this)[1][0]);
	}


#pragma endregion

}

