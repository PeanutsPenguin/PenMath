#pragma once 

#include "Vector/Vector2/Vector2.hpp"	//This include "Arithmetic.h"

#if defined(INIALIZER_LIST)
	#include <initializer_list>
	#include <stdexcept>
#endif // INIALIZER_LIST



namespace PenMath
{
	/// <summary>
	/// Class for MAtrix 2x2, this class will include "Vector2.hpp" wich include "Arithmetic.h"
	/// </summary>
	class Mat2 
	{
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
		Mat2(const Vector2& a, const Vector2& b);

#if defined(INIALIZER_LIST)
		Mat2(std::initializer_list<float> initList);
#endif // INIALIZER_LIST

#pragma endregion
		

#pragma region FUNCTION
		Mat2& toIdentity();

		Mat2& clear();

		Mat2 getTranspose();

		Mat2& toTranspose();

		float getDeterminant();
#pragma endregion


#pragma region STATIC_FUNC
#pragma endregion




	private:
		Vector2 m_matrix[2];
		bool m_rowMajor = false;
	};
}