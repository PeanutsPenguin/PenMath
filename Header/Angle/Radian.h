#pragma once 

namespace PenMath
{
	class Degree;

	class Radian
	{
	public:
#pragma region CONSTRUCTORS
		Radian() = default;					//Default constructor (value set to 0)

		explicit Radian(float value);		//Explicit so no implicit conversion from float to angle 

		Radian(const Radian&);				//Cpy constructors 

		~Radian() = default;				//Default destructors 
#pragma endregion

#pragma region IN_CLASS_OPERATORS
		Radian	operator-() const;

		operator Degree() const;			//Conversion operator to Degree

		Radian	operator+(const Radian&);	//Operator + with another Radian

		Radian& operator+=(const Radian&);	//Operator += with another Radian

		Radian	operator+(float);			//Operator + with a float

		Radian& operator+=(float);			//Operator += with a float

		Radian	operator-(const Radian&);	//Operator - with another Radian

		Radian& operator-=(const Radian&);	//Operator -= with another Radian

		Radian	operator-(float);			//Operator - with a float

		Radian& operator-=(float);			//Operator -= with a float

		Radian	operator*(const Radian&);	//Operator * with another Radian

		Radian& operator*=(const Radian&);	//Operator *= with another Radian

		Radian	operator*(float);			//Operator * with a float

		Radian& operator*=(float);			//Operator *= with a float

		Radian	operator/(const Radian&);	//Operator / with another Radian

		Radian& operator/=(const Radian&);	//Operator /= with another Radian

		Radian	operator/(float);			//Operator / with a float

		Radian& operator/=(float);			//Operator /= with a float

#pragma endregion
	
#pragma region FUNC
		/// <summary>Wraps the radian to wanted range.<para />
		/// true -> limits value to range [-pi, pi[ <para />
		/// false -> limits value to range [0, 2pi[</summary>
		void wrap(bool range = false);

		/// <summary>Return the wrapped value of the radian to wanted range.<para />
		/// true -> limits value to range [-pi, pi[ <para />
		/// false -> limits value to range [0, 2pi[</summary>
		float wrappedValue(bool range = true) const;

		/// <summary>
		/// Return the float value of the angle
		/// </summary>
		float raw() const;

		/// <summary>
		/// Return the degree value (float) of the radian
		/// </summary>
		float degree() const;
#pragma endregion

	private:
		float m_value = 0;
	};

#pragma region OUT_CLASS_OPERATORS

	bool	operator==(Radian, Radian);		//Operator == with Radian/Radian

	bool	operator==(Radian, float);		//Operator == with Radian/float

	bool	operator==(float, Radian);		//Operator == with float/Radian

	bool	operator!=(Radian, Radian);		//Operator != with Radian/Radian

	bool	operator!=(Radian, float);		//Operator != with Radian/float

	bool	operator!=(float, Radian);		//Operator != with float/Radian

	bool	operator>(Radian, Radian);		//Operator > with Radian/Radian

	bool	operator>(Radian, float);		//Operator > with Radian/float

	bool	operator>(float, Radian);		//Operator > with float/Radian

	bool	operator>=(Radian, Radian);		//Operator >= with Radian/Radian

	bool	operator>=(Radian, float);		//Operator >= with Radian/float

	bool	operator>=(float, Radian);		//Operator >= with float/Radian

	bool	operator<(Radian, Radian);		//Operator < with Radian/Radian

	bool	operator<(Radian, float);		//Operator < with Radian/float

	bool	operator<(float, Radian);		//Operator < with float/Radian

	bool	operator<=(Radian, Radian);		//Operator <= with Radian/Radian

	bool	operator<=(Radian, float);		//Operator <= with Radian/float

	bool	operator<=(float, Radian);		//Operator <= with float/Radian

#pragma endregion
}