#pragma once 

#include "Vector/Vector2/Vector2.hpp"	//This include "Arithmetic.h"

#if defined(INIALIZER_LIST)
	#include <initializer_list>
	#include <stdexcept>
#endif // INIALIZER_LIST

#if defined(MAT2_DEBUG)
	#include <ostream>
#endif // Print



namespace PenMath
{
	/// <summary>
	/// Class for MAtrix 2x2, this class will include "Vector2.hpp" wich include "Arithmetic.h"
	/// </summary>
	class Mat2 
	{
	public:
#pragma region CONSTRUCTORS
		Mat2(void) = default;					//Default Mat2 constructor 

		Mat2(const Mat2&) = default;			//Default copy constructor

		Mat2(Mat2&&) = default;					//Default move constructor

		~Mat2(void) = default;					//Default destructor

		/// <summary>
		/// Create a matrix with a specific value on the diagonal
		/// </summary>
		/// <param name="value">The value on the diagonal</param>
		explicit Mat2(float value);				

		/// <summary>
		/// Create a matrix with specified value in parameters
		/// </summary>
		/// <param name="a">First Row or Column depanding on the choice</param>
		/// <param name="b">Second Row or Column depanding on the choice</param>
		Mat2(const Vector2f& a, const Vector2f& b);

#if defined(INIALIZER_LIST)
		Mat2(std::initializer_list<float> initList);
#endif // INIALIZER_LIST

#pragma endregion
		
#pragma region FUNCTION
		/// <summary>
		/// Replace the trace of the matrix by one
		/// </summary>
		Mat2& toIdentity(void);	

		/// <summary>
		/// Replace all values in the matrix by 0
		/// </summary>
		Mat2& empty(void);

		/// <summary>
		/// Return the transpose of the matrix
		/// </summary>
		/// <returns>The transpose of the matrix/returns>
		Mat2 getTranspose(void);

		/// <summary>
		/// Change the matrix to its transpose
		/// </summary>
		Mat2& toTranspose(void);

		/// <summary>
		/// Return the determinant of the matrix
		/// </summary>
		/// <returns>Determinant of the matrix</returns>
		float getDeterminant(void) const;		
#pragma endregion

#pragma region STATIC_FUNC

		/// <summary>
		/// Returns a Matrix filled by 0
		/// </summary>
		static Mat2 zero(void);

		/// <summary>
		/// Returns a Matrix filled by 0
		/// </summary>
		static Mat2 identity(void);
#pragma endregion

#pragma region OPERATORS
		Vector2f& operator[](size_t index) noexcept { return this->m_matrix[index]; }					//Operator to access matrix

		const Vector2f& operator[](size_t index) const noexcept { return this->m_matrix[index]; }		//Operator const to access matrix

		bool operator==(const Mat2& toCompare) const;		//Operator to compare Mat2

		bool operator!=(const Mat2& toCompare) const;		//Operator to compare Mat2

		Mat2& operator=(const Mat2& equal) = default;		//Operator to give matrix values

		Mat2& operator=(Mat2&& equal) = default;			//Operator to move matrix values

		Mat2 operator*(const Mat2& toMultiply) const;		//Operator const to multiply matrix with another

		Mat2& operator*=(const Mat2& toMultiply);			//Operator to multiply matrix with another and take values

		Mat2 operator*(const float value) const;			//Operator const to multiply matrix with a float

		Mat2& operator*=(const float value);				//Operator to multiply matrix with a float and take values

		Mat2 operator+(const Mat2& rhs) const;				//Operator const to add matrix with another

		Mat2& operator+=(const Mat2& rhs);					//Operator to add matrix with another and take values

		Mat2 operator-(const Mat2& rhs) const;				//Operator const to substract matrix with another

		Mat2& operator-=(const Mat2& rhs);					//Operator to substract matrix with another and take values
#pragma endregion


	private:
		Vector2f m_matrix[2];
		bool m_rowMajor = false;
	};

#if defined(MAT2_DEBUG)
	std::ostream& operator<<(std::ostream& os, const Mat2& matrix)		//Operator << to print a matrix in the console
	{
		os << "Matrix 2x2 :" << '\n';

		for (size_t index = 0; index < 2; ++index)
		{
			for (size_t jindex = 0; jindex < 2; ++jindex)
				os << matrix[index][jindex] << '\t';

			os << '\n';
		}

		return os;
	}
#endif
}