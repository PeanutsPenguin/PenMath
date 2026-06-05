#include "Transform.h"
#include "Matrix/Mat3.h"

using namespace PenMath;

Mat4 Transform::toMatrix() const noexcept
{
    return PenMath::Mat4::translate(position) *
        PenMath::Quaternion::Rotation(rotation) *
        PenMath::Mat4::scale(scale);
}

Transform Transform::inverse() const
{
    Transform result;

    result.scale = Vector3f{1, 1, 1} / this->scale;
    result.rotation = Quaternion::conjugate(this->rotation);
    result.position = result.rotation.rotate(-this->position);
    result.position /= this->scale;

    return result;
}

Transform Transform::combine(const Transform& otherTransform) const
{
    Transform result;

    result.position = otherTransform.rotation.rotate(this->position) * otherTransform.scale + otherTransform.position;
    result.rotation = this->rotation * otherTransform.rotation;
    result.scale = this->scale * otherTransform.scale;

    return result;
}

Vector3f Transform::getForward() const
{
    return PenMath::Vector3f(
        2.0f * (this->rotation.x * this->rotation.z + this->rotation.w * this->rotation.y),         //x
        2.0f * (this->rotation.y * this->rotation.z - this->rotation.w * this->rotation.x),         //y
        1.0f - 2.0f * (this->rotation.x * this->rotation.x + this->rotation.y * this->rotation.y)   //z
    );
}

Vector3f Transform::getUp() const
{
	return PenMath::Vector3f(
		2.0f * (this->rotation.x * this->rotation.y - this->rotation.w * this->rotation.z),         //x
		1.0f - 2.0f * (this->rotation.x * this->rotation.x + this->rotation.z * this->rotation.z),  //y
		2.0f * (this->rotation.y * this->rotation.z + this->rotation.w * this->rotation.x)          //z
	);
}

Vector3f Transform::getRight() const
{
	return PenMath::Vector3f(
		1.0f - 2.0f * (this->rotation.y * this->rotation.y + this->rotation.z * this->rotation.z),  //x
		2.0f * (this->rotation.x * this->rotation.y + this->rotation.w * this->rotation.z),         //y
		2.0f * (this->rotation.x * this->rotation.z - this->rotation.w * this->rotation.y)          //z
	);
}