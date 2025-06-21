#pragma once 

#include <Vector/Vector3/Vector3.h>
#include <initializer_list>

namespace PenMath
{
	class Matrix2;

	/// <summary>
	/// Matrix is composed by 3 Vector3f (file Vector/Vector3.h is included)
	/// Row Major Matrix
	/// </summary>
	struct Matrix3
	{
		#pragma region CONSTRUCTORS
		Matrix3(void) = default;										//Default Matrix3 constructor 

		Matrix3(const Matrix3&) = default;								//Default Matrix3 copy constructor

		Matrix3(Matrix3&&) = default;									//Default Matrix3 move constructor 

		~Matrix3(void) = default;										//Default Matrix3 destructor

		explicit Matrix3(float v);										//Matrix3 constructor with a constant number in diagonal

		Matrix3(const Vector3f&, const Vector3f&, const Vector3f&);		//Matrix3 constructor with 3 vector in parameters to initialize the entire matrix

		Matrix3(std::initializer_list<float>);							//Initialize values with an array of float 

		#pragma endregion

		#pragma region OPERATOR

		Vector3f&		operator[](size_t index) noexcept; 			//Operator [] to get a a specified row in the matrix 

		const Vector3f& operator[](size_t index) const noexcept; 	//const operator [] to get a specified row in the matrix

		bool			operator==(const Matrix3&) const;			//Operator == to check if the matrix is equal to another

		bool			operator!= (const Matrix3&) const;			//Operator != to check if the matrix is different than another

		Matrix3&		operator=(const Matrix3&) = default;		//Default operator equal with another Matrix3

		Matrix3&		operator=(Matrix3&&) = default;				//Default move operator equal with another Matrix3

		Matrix3			operator*(const Matrix3&) const;			//Operator * with any Matrix3

		Matrix3&		operator*=(const Matrix3&);					//Operator *= with another Matrix3

		Matrix3			operator*(float) const;						//Operator * with a constant number 

		Matrix3&		operator*=(float);							//Opeartor *= with a constant number

		Matrix3			operator+(const Matrix3&) const;			//Operator + with another Matrix3

		Matrix3&		operator+=(const Matrix3&);					//Operator += with another Matrix3

		Matrix3			operator+(float) const;						//Operator * with a constant number 

		Matrix3&		operator+=(float);							//Opeartor *= with a constant number

		Matrix3			operator-(const Matrix3&) const;			//Operator - with another Matrix3

		Matrix3&		operator-=(const Matrix3&);					//Operator -= with another Matrix3

		Matrix3			operator-(float) const;						//Operator - with a constant number 

		Matrix3&		operator-=(float);							//Opeartor -= with a constant number

		Matrix3			operator/(const Matrix3&) const;			//Operator / with another Matrix3

		Matrix3&		operator/=(const Matrix3&);					//Operator /= with another Matrix3

		Matrix3			operator/(float) const;						//Operator / with a constant number 

		Matrix3&		operator/=(float);							//Opeartor /= with a constant number

		#pragma endregion

		#pragma region FUNC

		/// <summary>
		/// Transform the matrix into an identity matrix
		/// </summary>
		void	toIdentity(void);

		/// <summary>
		/// Fill the matrix with 0
		/// </summary>
		void	empty(void);													

		/// <summary>
		/// Transforms the matrix into its transpose matrix (invert rows and columns)
		/// </summary>
		void	toTranspose(void);

		/// <summary>
		/// Get the determinant of the matrix
		/// </summary>
		float		getDeterminant(void) const;

		/// <summary>
		/// Returns the minor matrix
		/// </summary>
		Matrix2		getMinor(void) const;

		Matrix3		GetMinorsDeterminant(void) const;								//Get a matrix with every determinant of minors matrix 

		Matrix3		GetCofactors(void) const;										//Get the determinant of the minor matrix

		Matrix3		GetInverse(void) const;											//Get the inverse matrix (AB and BA are equals)

		#pragma endregion
	
	private:
		Vector3f m_matrix[3];
	};	
}
