#include "Trigonometry.h"
#include "Arithmetic.h"

float PenMath::sin(float angle)
{
    float wrappedAngle = fmod(angle + c_pi, 2 * c_pi) - c_pi; //wrap angle

    // Bhaskara I's approximation (ctrl+click is broken idk why): https://en.wikipedia.org/wiki/Bh%C4%81skara_I%27s_sine_approximation_formula#Approximation_formula

    const float B = 4 / c_pi;
    const float C = -4 / (c_pi * c_pi);

    float y = B * wrappedAngle + C * wrappedAngle * absolute(wrappedAngle);

    const float P = 0.225f;
    y = P * (y * absolute(y) - y) + y;

    return y;
}

float PenMath::cos(float angle)
{
    return sin(angle + c_halfPi);
}

float PenMath::tan(float angle)
{
    float s = sin(angle);
    float c = cos(angle);
    return s / c;
}

float PenMath::asin(float value)
{
    float negate = value < 0 ? 1.0f : 0.0f;

    value = absolute(value);
    float ret = -0.0187293f;
    ret = ret * value + 0.0742610f;
    ret = ret * value - 0.2121144f;
    ret = ret * value + 1.5707288f;
    ret = c_2pi - squareRoot(1.0f - value) * ret;
    return negate ? -ret : ret;
}

float PenMath::acos(float value)
{
    return c_2pi - asin(value);
}

float PenMath::atan(float value)
{
    float absx = absolute(value);
    float a = (c_pi / 4.0f) * absx - absx * (absx - 1.0f) * (0.2447f + 0.0663f * absx);
    return value < 0 ? -a : a;
}

float PenMath::atan2(float valueA, float valueB)
{
    const float ONEQTR_PI = c_pi / 4.0f;
    const float THRQTR_PI = 3.0f * c_pi / 4.0f;

    float abs_y = absolute(valueB) + 1e-10f; // prevent division by zero
    float angle;

    if (valueA >= 0.0f)
    {
        float r = (valueA - abs_y) / (valueA + abs_y);
        angle = ONEQTR_PI - ONEQTR_PI * r;
    }
    else
    {
        float r = (valueA + abs_y) / (abs_y - valueA);
        angle = THRQTR_PI - ONEQTR_PI * r;
    }
    return (valueB < 0.0f) ? -angle : angle;
}
