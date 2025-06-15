#include <Angle/Radian.h>

#include <Angle/Degree.h>
#include <Trigonometry.h>
#include <Arithmetic.h>

using namespace PenMath;

#pragma region CONSTRUCTORS
Radian::Radian(float value) : m_value(value) {}

Radian::Radian(const Radian& cpy) : m_value(cpy.m_value) {}
#pragma endregion

#pragma region IN_CLASS_OPERATORS

Radian Radian::operator-() const
{
	return Radian(-this->m_value);
}

PenMath::Radian::operator Degree() const
{
	return Degree(this->degree());
}

Radian Radian::operator+(const Radian& deg)
{
	return Radian(this->m_value + deg.m_value);
}

Radian& Radian::operator+=(const Radian& deg)
{
	this->m_value += deg.m_value;
	return *this;
}

Radian Radian::operator+(float value)
{
	return Radian(this->m_value + value);
}

Radian& Radian::operator+=(float value)
{
	this->m_value += value;
	return *this;
}

Radian Radian::operator-(const Radian& deg)
{
	return Radian(this->m_value - deg.m_value);
}

Radian& Radian::operator-=(const Radian& deg)
{
	this->m_value -= deg.m_value;
	return *this;
}

Radian Radian::operator-(float value)
{
	return Radian(this->m_value - value);
}

Radian& Radian::operator-=(float value)
{
	this->m_value -= value;
	return *this;
}

Radian Radian::operator*(const Radian& deg)
{
	return Radian(this->m_value * deg.m_value);
}

Radian& Radian::operator*=(const Radian& deg)
{
	this->m_value *= deg.m_value;
	return *this;
}

Radian Radian::operator*(float value)
{
	return Radian(this->m_value * value);
}

Radian& Radian::operator*=(float value)
{
	this->m_value *= value;
	return *this;
}

Radian Radian::operator/(const Radian& deg)
{
	return Radian(this->m_value / deg.m_value);
}

Radian& Radian::operator/=(const Radian& deg)
{
	this->m_value /= deg.m_value;
	return *this;
}

Radian Radian::operator/(float value)
{
	return Radian(this->m_value / value);
}

Radian& Radian::operator/=(float value)
{
	this->m_value /= value;
	return *this;
}

#pragma endregion

#pragma region FUNC

void Radian::wrap(bool range)
{
	this->m_value = this->wrappedValue(range);
}

float Radian::wrappedValue(bool range) const
{
	float result = 0;

	/* Checking if a m_value is already in the wanted range */
	if ((range && m_value >= (-1 * c_pi) && m_value < c_pi)
		|| (!range && m_value >= 0 && m_value < 2 * c_pi))
		return m_value;


	if (m_value >= 0)
	{
		result = fmod(m_value, c_2pi);
	}
	else
	{
		result = c_2pi + fmod(m_value, c_2pi);
	}

	if (range && result >= c_pi)
	{
		result -= c_2pi;
	}

	return result;
}

float Radian::raw() const
{
	return this->m_value;
}

float Radian::degree() const
{
	return this->m_value * 180 / c_pi;
}

#pragma endregion

#pragma region OUT_CLASS_OPERATORS

bool PenMath::operator==(Radian radA, Radian radB)
{
	if (radA.wrappedValue() == radB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator==(Radian rad, float value)
{
	if (rad.wrappedValue() == value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator==(float value, Radian rad)
{
	if (rad.wrappedValue() == value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(Radian radA, Radian radB)
{
	if (radA.wrappedValue() != radB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(Radian rad, float value)
{
	if (rad.wrappedValue() != value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(float value, Radian rad)
{
	if (rad.wrappedValue() != value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(Radian radA, Radian radB)
{
	if (radA.wrappedValue() > radB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(Radian rad, float value)
{
	if (rad.wrappedValue() > value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(float value, Radian rad)
{
	if (rad.wrappedValue() > value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(Radian radA, Radian radB)
{
	if (radA.wrappedValue() >= radB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(Radian rad, float value)
{
	if (rad.wrappedValue() >= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(float value, Radian rad)
{
	if (rad.wrappedValue() >= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(Radian radA, Radian radB)
{
	if (radA.wrappedValue() < radB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(Radian rad, float value)
{
	if (rad.wrappedValue() < value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(float value, Radian rad)
{
	if (rad.wrappedValue() < value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(Radian radA, Radian radB)
{
	if (radA.wrappedValue() <= radB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(Radian rad, float value)
{
	if (rad.wrappedValue() <= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(float value, Radian rad)
{
	if (rad.wrappedValue() <= value)
	{
		return true;
	}
	return false;
}

#pragma endregion