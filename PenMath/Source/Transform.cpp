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

Transform PenMath::Transform::combine(const Transform& otherTransform) const
{
    Transform result;

    result.position = otherTransform.rotation.rotate(this->position) * otherTransform.scale + otherTransform.position;
    result.rotation = this->rotation * otherTransform.rotation;
    result.scale = this->scale * otherTransform.scale;

    return result;
}

