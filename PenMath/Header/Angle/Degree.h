#pragma once 

namespace PenMath
{
	class Radian;

	class Degree
	{
	public:
#pragma region CONSTRUCTORS
		Degree() = default;					//Default constructor (value set to 0)

		explicit Degree(float value);		//Explicit so no implicit conversion from float to angle 

		Degree(const Degree&);				//Cpy constructors 

		~Degree() = default;				//Default destructors 
#pragma endregion

#pragma region IN_CLASS_OPERATORS
		Degree	operator-() const;

		//operator Radian() const;			//Uncomment when Radian will be created 

		Degree	operator+(const Degree&);	//Operator + with another Degree

		Degree&	operator+=(const Degree&);	//Operator += with another Degree

		Degree	operator+(float);			//Operator + with a float

		Degree&	operator+=(float);			//Operator += with a float

		Degree	operator-(const Degree&);	//Operator - with another Degree

		Degree&	operator-=(const Degree&);	//Operator -= with another Degree

		Degree	operator-(float);			//Operator - with a float

		Degree&	operator-=(float);			//Operator -= with a float

		Degree	operator*(const Degree&);	//Operator * with another Degree

		Degree&	operator*=(const Degree&);	//Operator *= with another Degree

		Degree	operator*(float);			//Operator * with a float

		Degree&	operator*=(float);			//Operator *= with a float

		Degree	operator/(const Degree&);	//Operator / with another Degree

		Degree&	operator/=(const Degree&);	//Operator /= with another Degree

		Degree	operator/(float);			//Operator / with a float

		Degree&	operator/=(float);			//Operator /= with a float

#pragma endregion

#pragma region FUNC
		/// <summary>Wraps the degree to wanted range.<para />
		/// true -> limits value to range [-180, 180[ <para />
		/// false -> limits value to range [0, 360[</summary>
		void wrap(bool range = false);

		/// <summary>Return the wrapped value of the degree to wanted range.<para />
		/// true -> limits value to range [-180, 180[ <para />
		/// false -> limits value to range [0, 360[</summary>
		float wrappedValue(bool range = false) const;

		/// <summary>
		/// Return the float value of the angle
		/// </summary>
		float raw() const;

		/// <summary>
		/// Return the radian value (float) of the degree
		/// </summary>
		float radian() const;
#pragma endregion
	
	private:
		float m_value = 0;
	};

#pragma region OUT_CLASS_OPERATORS

	bool	operator==(Degree, Degree);		//Operator == with Degree/Degree

	bool	operator==(Degree, float);		//Operator == with Degree/float

	bool	operator==(float, Degree);		//Operator == with float/Degree

	bool	operator!=(Degree, Degree);		//Operator != with Degree/Degree

	bool	operator!=(Degree, float);		//Operator != with Degree/float

	bool	operator!=(float, Degree);		//Operator != with float/Degree

	bool	operator>(Degree, Degree);		//Operator > with Degree/Degree

	bool	operator>(Degree, float);		//Operator > with Degree/float

	bool	operator>(float, Degree);		//Operator > with float/Degree

	bool	operator>=(Degree, Degree);		//Operator >= with Degree/Degree

	bool	operator>=(Degree, float);		//Operator >= with Degree/float

	bool	operator>=(float, Degree);		//Operator >= with float/Degree

	bool	operator<(Degree, Degree);		//Operator < with Degree/Degree

	bool	operator<(Degree, float);		//Operator < with Degree/float

	bool	operator<(float, Degree);		//Operator < with float/Degree

	bool	operator<=(Degree, Degree);		//Operator <= with Degree/Degree

	bool	operator<=(Degree, float);		//Operator <= with Degree/float

	bool	operator<=(float, Degree);		//Operator <= with float/Degree

#pragma endregion

}