#pragma once

#include "Vector/Vector3/Vector3.h"
#define QUATERNION_CAST
#include "Quaternion.h"

#include "Matrix/Mat4.h"

namespace PenMath
{
	struct Transform
	{
		PenMath::Vector3f position;
		PenMath::Vector3f scale;
		PenMath::Quaternion rotation;

		_NODISCARD Mat4 toMatrix() const noexcept;

		_NODISCARD Transform inverse() const;

		_NODISCARD Transform combine(const Transform& otherTransform) const;

		_NODISCARD bool operator==(const Transform& rvalue) const noexcept = default;
		_NODISCARD bool operator!=(const Transform& rvalue) const noexcept = default;
	};
}