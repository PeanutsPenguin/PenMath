#pragma once 

#define VECTOR4_CAST
#include "Vector/Vector4/Vector4.hpp"

#if defined(MAT4_INITIALIZER)
#include <initializer_list>
#endif

#if defined(MAT4_DEBUG)
#include <ostream>
#endif

namespace PenMath
{
	class Mat3;

	/// <summary>
	/// Mat4 is an array of 4 Vector4 (file Vector/Vector4/Vector4.hpp is included)
	/// </summary>
	class Mat4
	{
	public:
#pragma region CONSTRUCTORS
		Mat4(void) = default;

		Mat4(const Mat4&) = default;

		Mat4(Mat4&&) = default;

		~Mat4(void) = default;

		Mat4(float value);

		Mat4(const Vector4f a, const Vector4f b, const Vector4f c, const Vector4f d);

#if defined(MAT4_INITIALIZER)
		Mat4(std::initializer_list<float> values)
		{
			size_t index = 0;
			for (auto& element : values)
			{
				for (int jindex = 0; jindex < 4; ++jindex)
					this->m_matrix[index][jindex] = std::move(element);

				++index;
			}
		}
#endif
#pragma endregion

#pragma region BASIC_MATRIX4
		/// <summary>
		/// Returns a Mat4 full of 0
		/// </summary>
		static Mat4 zero(void);

		/// <summary>
		/// Returns a Mat4 with 1 on the trace
		/// </summary>
		static Mat4 identity(void);
#pragma endregion

#pragma region OPERATORS
		Mat4& operator=(const Mat4&) = default;															//Operator equal with any other 4 by 4 matrix

		bool operator!=(const Mat4&) const = default;													//Operator == with any other 4 by 4 matrix

		bool operator==(const Mat4&) const = default;													//Operator == with any other 4 by 4 matrix

		Mat4& operator=(Mat4&&) = default;																//Move operator equal fir any ither 4 by 4 matrix

		Vector4f& operator[](size_t index) noexcept { return this->m_matrix[index]; }					//operator [] to get a specified number in the matrix

		const Vector4f& operator[](size_t index) const noexcept { return this->m_matrix[index]; }		//const operator [] to get a specified number in the matrix

		Mat4 operator*(const Mat4& rhs) const;															//Operator * with any other matrix that has 4 rows

		Mat4& operator*=(const Mat4& rhs);																//Operator *= with any other 4 by 4 matrix

		Mat4 operator*(float rhs) const;																//operator * with a constant value

		Mat4& operator*=(float rhs);																	//Operator *= with a constant value

		Mat4 operator+(const Mat4& rhs) const;															//Operator + with any other 4 by 4 matrix

		Mat4& operator+=(const Mat4& rhs);																//Operator += with any ther 4 by 4 matrix

		Mat4 operator-(const Mat4& rhs) const;															//Operator - with any other 4 by 4 matrix

		Mat4& operator-=(const Mat4& rhs);																//Operator -= with any other 4 by 4 matrix
#pragma endregion

#pragma region FUNCTION
		/// <summary>
		/// Change the matrix in an identity matrix
		/// </summary>
		Mat4& toIdentity(void);

		/// <summary>
		/// Fill the matrix with 0
		/// </summary>
		Mat4& empty(void);

		/// <summary>
		/// Return the transpose matrix (inverse rows and columns)
		/// </summary>
		Mat4 getTranspose(void) const;

		/// <summary>
		/// Change the matrix into its transpose matrix (inverse rows and columns)
		/// </summary>
		Mat4& toTranspose(void);

		/// <summary>
		/// Get the determinant of the matrix
		/// </summary>
		float getDeterminant(void) const;

		/// <summary>
		/// Get the minor matrix with specified column and rows
		/// </summary>
		/// <param name="row">Index of the row of the wanted minor</param>
		/// <param name="column">Index of the column of the wanted minor</param>
		/// <returns>The minor matrix</returns>
		Mat3 getMinor(size_t row, size_t column) const;

		/// <summary>
		/// Returns a matrix with every determinant of minors matrix 
		/// </summary>
		Mat4 getMinorsDeterminant(void) const;

		/// <summary>
		///	Get the Co-factors matrix (Replace element of the matrix by its cofactor)
		/// </summary>
		/// <returns>The cofactors matrix</returns>
		Mat4 getCofactors(void) const;

		/// <summary>
		///	Get the inverse matrix (AB and BA are equals)
		/// </summary>
		/// <returns>The inverse matrix</returns>
		Mat4 getInverse(void) const;
#pragma endregion

#pragma region STATIC_FUNC
		/// <summary>
		///	Return a translate matrix with a specified vector 3 (for axis)
		/// </summary>
		/// <param name="translator">Translator for each axis</param>
		/// <returns>A translate matrix</returns>
		static Mat4 translate(const Vector3f& translator);

		/// <summary>
		/// Return a rotate matrix with the given Vector3 (angles in radians, only ONE axis at the time)
		/// </summary>
		/// <param name="rotator">Values of the rotate (give only ONE axis)</param>
		/// <returns>A rotate Matrix</returns>
		static Mat4 rotate(const Vector3f& rotator);

		/// <summary>
		/// Return a scale matrix with the given Vector2
		/// </summary>
		/// <param name="scalor">Values of the scale</param>
		/// <returns>A scale Matrix</returns>
		static Mat4 scale(const Vector3f& scalor);

		/// <summary>
		/// Return a perspective matrix with a specified fov, near and far
		/// </summary>
		/// <param name="fov">Wanted FOV (field Of View)</param>
		/// <param name="aspect">Wanted aspect</param>
		/// <param name="near">Wanted near</param>
		/// <param name="far">Wanted far</param>
		/// <returns>The perspective Mat4</returns>
		static Mat4 Perspective(float fov, float aspect, float near, float far);

		/// <summary>
		/// Return a LookAt matrix (most use is for Camera)
		/// </summary>
		/// <param name="eye">Direction of looking</param>
		/// <param name="center">Position of the camera</param>
		/// <param name="up">Up direction</param>
		/// <returns>A LookAt Mat4 matrix</returns>
		static Mat4 LookAt(const Vector3f& eye, const Vector3f& center, const Vector3f& up);								//Return a lookAt matrix useful for Camera

		/// <summary>
		/// Create and returns an orthogonal Matrix with the wanted values
		/// </summary>
		/// <param name="left">Left coordinate</param>
		/// <param name="right">Right Coordinate</param>
		/// <param name="bottom">Bottom coordinate</param>
		/// <param name="top">Top coordinate</param>
		/// <returns>A Orthogonal matrix</returns>
		static Mat4 Ortho(float left, float right, float bottom, float top);

		/// <summary>
		/// Create and returns an orthogonal Matrix with the wanted values
		/// </summary>
		/// <param name="left">Left coordinate</param>
		/// <param name="right">Right Coordinate</param>
		/// <param name="bottom">Bottom coordinate</param>
		/// <param name="top">Top coordinate</param>
		/// <param name="far">Wanted far</param>
		/// <param name="near">Wanted near</param>
		/// <returns>A Orthogonal matrix</returns>
		static Mat4 Ortho(float left, float right, float bottom, float top, float near, float far);
#pragma endregion

	private:
		Vector4f m_matrix[4];
	};

	Vector4f operator*(const Vector4f& vec, const Mat4& mat);		//Operator * with a vector 4

#if defined(MAT4_DEBUG)
	std::ostream& operator<<(std::ostream& os, const Mat4& matrix)		//Operator << to print a matrix in the console
	{
		os << "Matrix 4x4 :" << '\n';

		for (size_t index = 0; index < 4; ++index)
		{
			for (size_t jindex = 0; jindex < 4; ++jindex)
				os << matrix[index][jindex] << '\t';

			os << '\n';
		}

		return os;
	}
#endif
}

