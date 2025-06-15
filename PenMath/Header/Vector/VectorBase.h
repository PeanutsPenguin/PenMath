#pragma once

#include <type_traits>

namespace PenMath
{
	template<size_t size, typename _Type,  typename = typename std::enable_if<std::is_arithmetic<_Type>::value, _Type>::type>
	struct Vector;
}