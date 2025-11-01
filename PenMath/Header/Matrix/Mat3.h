#pragma once 

#define VECTOR3_CAST
#include <Vector/Vector3/Vector3.h>

#if defined(MAT3_INITIALIZER)
	#include <initializer_list>
#endif

#if defined(MAT3_DEBUG)
	#include <ostream>
#endif

namespace PenMath
{
	class Mat2;

	/// <summary>
	/// Matrix is composed by 3 Vector3f (file Vector/Vector3.h is included)
	/// Row Major Matrix
	/// </summary>
	class Mat3
	{
	public:
#pragma region CONSTRUCTORS
		Mat3(void) = default;											//Default Matrix3 constructor 

		Mat3(const Mat3&) = default;									//Default Matrix3 copy constructor

		Mat3(Mat3&&) = default;											//Default Matrix3 move constructor 

		~Mat3(void) = default;											//Default Matrix3 destructor

		explicit Mat3(float v);											//Matrix3 constructor with a constant number in diagonal

		Mat3(const Vector3f&, const Vector3f&, const Vector3f&);		//Matrix3 constructor with 3 vector in parameters to initialize the entire matrix

#if defined(MAT3_INITIALIZER)
		Mat3(std::initializer_list<float> values)							//Initialize values with an array of float 
		{
			int valuesIndex = 0;
			for (size_t index = 0; index < 3; ++index)
				for (size_t jindex = 0; jindex < 3; ++jindex)
				{
					if (values.size() > valuesIndex)
					{
						this->m_matrix[index][jindex] = *(values.begin() + valuesIndex);
						valuesIndex++;
					}
					else
						this->m_matrix[index][jindex] = 0;
				}
		}
#endif
		#pragma endregion

#pragma region BASIC_MATRIX3
		static Mat3 zero(void);

		static Mat3 identity(void);

#pragma endregion

#pragma region OPERATOR

		Vector3f&		operator[](size_t index) noexcept; 				//Operator [] to get a a specified row in the matrix 

		const Vector3f& operator[](size_t index) const noexcept; 		//const operator [] to get a specified row in the matrix

		bool			operator==(const Mat3&) const;					//Operator == to check if the matrix is equal to another

		bool			operator!= (const Mat3&) const;					//Operator != to check if the matrix is different than another

		Mat3&			operator=(const Mat3&) = default;				//Default operator equal with another Matrix3

		Mat3&			operator=(Mat3&&) = default;					//Default move operator equal with another Matrix3

		Mat3			operator*(const Mat3&) const;					//Operator * with any Matrix3

		Mat3&			operator*=(const Mat3&);						//Operator *= with another Matrix3

		Mat3			operator*(float) const;							//Operator * with a constant number 

		Mat3&			operator*=(float);								//Opeartor *= with a constant number

		Mat3			operator+(const Mat3&) const;					//Operator + with another Matrix3

		Mat3&			operator+=(const Mat3&);						//Operator += with another Matrix3

		Mat3			operator+(float) const;							//Operator * with a constant number 

		Mat3&			operator+=(float);								//Opeartor *= with a constant number

		Mat3			operator-(const Mat3&) const;					//Operator - with another Matrix3

		Mat3&			operator-=(const Mat3&);						//Operator -= with another Matrix3

		Mat3			operator-(float) const;							//Operator - with a constant number 

		Mat3&			operator-=(float);								//Opeartor -= with a constant number

		Mat3			operator/(const Mat3&) const;					//Operator / with another Matrix3

		Mat3&			operator/=(const Mat3&);						//Operator /= with another Matrix3

		Mat3			operator/(float) const;							//Operator / with a constant number 

		Mat3&			operator/=(float);								//Opeartor /= with a constant number

		#pragma endregion

#pragma region FUNC

		/// <summary>
		/// Transform the matrix into an identity matrix
		/// </summary>
		void		toIdentity(void);

		/// <summary>
		/// Fill the matrix with 0
		/// </summary>
		void		empty(void);													

		/// <summary>
		/// Transforms the matrix into its transpose matrix (invert rows and columns)
		/// </summary>
		Mat3&		toTranspose(void);

		/// <summary>
		/// Returns the transpose Matrix
		/// </summary>
		Mat3		getTranspose(void);

		/// <summary>
		/// Get the determinant of the matrix
		/// </summary>
		float		getDeterminant(void) const;

		/// <summary>
		/// Get the minor of the matrix
		/// </summary>
		/// <param name="row">Index of the row of the wanted minor</param>
		/// <param name="column">Index of the column of the wanted minor</param>
		/// <returns>The minor matrix</returns>
		Mat2		getMinor(size_t row, size_t column) const;

		/// <summary>
		/// Returns a matrix with every determinant of minors matrix 
		/// </summary>
		Mat3		getMinorsDeterminant(void) const;			

		/// <summary>
		///	Get the Co-factors matrix (Replace element of the matrix by its cofactor)
		/// </summary>
		/// <returns>The minor matrix</returns>
		Mat3		getCofactors(void) const;									

		/// <summary>
		///	Get the inverse matrix (AB and BA are equals)
		/// </summary>
		/// <returns>The inverse matrix</returns>
		Mat3		getInverse(void) const;											
	#pragma endregion
	
#pragma region STATIC_FUNC
		/// <summary>
		/// Return a translate matrix with the given Vector2
		/// </summary>
		/// <param name="translator">Values of the translate</param>
		/// <returns>A translate Matrix</returns>
		static Mat3 translate(const Vector2f& translator);

		/// <summary>
		/// Return a rotate matrix with the given Vector2
		/// </summary>
		/// <param name="rotator">Values of the rotate</param>
		/// <returns>A rotate Matrix</returns>
		static Mat3 rotate(const Vector2f& rotator);

		/// <summary>
		/// Return a scale matrix with the given Vector2
		/// </summary>
		/// <param name="scalor">Values of the scale</param>
		/// <returns>A scale Matrix</returns>
		static Mat3 scale(const Vector2f& scalor);
#pragma endregion
	private:
		Vector3f m_matrix[3];
	};

#if defined(MAT3_DEBUG)
	std::ostream& operator<<(std::ostream& os, const Mat3& matrix)		//Operator << to print a matrix in the console
	{
		os << "Matrix 3x3 :" << '\n';

		for (size_t index = 0; index < 3; ++index)
		{
			for (size_t jindex = 0; jindex < 3; ++jindex)
				os << matrix[index][jindex] << '\t';

			os << '\n';
		}

		return os;
	}
#endif

}
