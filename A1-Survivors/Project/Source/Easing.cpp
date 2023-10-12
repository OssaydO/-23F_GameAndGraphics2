#include "Easing.h"
#include <math.h>

float Linear::Interpolation(float value)
{
    return value;
}

float Quadratic::In(float value)
{
    return value * value;
}

float Quadratic::Out(float value)
{
    return value * (2.0f - value);
}

float Quadratic::InOut(float value)
{
    if (value < 0.5)
    {
        return 2 * value * value;
    }
    else
    {
        return (-2 * value * value) + (4 * value) - 1;
    }
}

float Cubic::In(float value)
{
    return value * value * value;
}

float Cubic::Out(float value)
{
    float f = (value - 1.0f);
    return f * f * f + 1.0f;
}

float Cubic::InOut(float value)
{
    if (value < 0.5f)
    {
        return 4.0f * value * value * value;
    }
    else
    {
        float f = ((2.0f * value) - 2.0f);
        return 0.5f * f * f * f + 1.0f;
    }
}

float Quartic::In(float value)
{
    return value * value * value * value;
}

float Quartic::Out(float value)
{
    float f = (value - 1.0f);
    return f * f * f * (1.0f - value) + 1.0f;
}

float Quartic::InOut(float value)
{
    if (value < 0.5f)
    {
        return 8.0f * value * value * value * value;
    }
    else
    {
        float f = (value - 1.0f);
        return -8.0f * f * f * f * f + 1.0f;
    }
}


float Quintic::In(float value)
{
    return value * value * value * value * value;
}

float Quintic::Out(float value)
{
    float f = (value - 1.0f);
    return f * f * f * f * f + 1.0f;
}

float Quintic::InOut(float value)
{
    if (value < 0.5f)
    {
        return 16.0f * value * value * value * value * value;
    }
    else
    {
        float f = ((2.0f * value) - 2.0f);
        return  0.5f * f * f * f * f * f + 1.0f;
    }
}

float Sinusoidal::In(float value)
{
    return sinf((value - 1) * (float)M_PI_2) + 1;
}

float Sinusoidal::Out(float value)
{
    return sinf(value * (float)M_PI_2);
}

float Sinusoidal::InOut(float value)
{
    return 0.5f * (1.0f - cosf(value * (float)M_PI));
}

float Exponential::In(float value)
{
    return (value == 0.0f) ? value : powf(2, 10 * (value - 1));
}

float Exponential::Out(float value)
{
    return (value == 1.0f) ? value : 1.0f - powf(2, -10 * value);
}

float Exponential::InOut(float value)
{
    if (value == 0.0f || value == 1.0f) return value;

    if (value < 0.5f)
    {
        return 0.5f * powf(2, (20 * value) - 10);
    }
    else
    {
        return -0.5f * powf(2, (-20 * value) + 10) + 1;
    }
}

float Circular::In(float value)
{
    return 1.0f - sqrtf(1 - (value * value));
}

float Circular::Out(float value)
{
    return sqrtf((2.0f - value) * value);
}

float Circular::InOut(float value)
{
    if (value < 0.5f)
    {
        return 0.5f * (1.0f - sqrtf(1.0f - 4.0f * (value * value)));
    }
    else
    {
        return 0.5f * (sqrtf(-((2.0f * value) - 3.0f) * ((2.0f * value) - 1.0f)) + 1.0f);
    }
}

float Elastic::In(float value)
{
    return sinf(13.0f * (float)M_PI_2 * value) * powf(2, 10 * (value - 1.0f));
}

float Elastic::Out(float value)
{
    return sinf(-13.0f * (float)M_PI_2 * (value + 1.0f)) * powf(2, -10 * value) + 1.0f;
}

float Elastic::InOut(float value)
{
    if (value < 0.5f)
    {
        return 0.5f * sinf(13.0f * (float)M_PI_2 * (2.0f * value)) * powf(2, 10 * ((2.0f * value) - 1.0f));
    }
    else
    {
        return 0.5f * (sinf(-13.0f * (float)M_PI_2 * ((2.0f * value - 1.0f) + 1.0f)) * powf(2, -10 * (2.0f * value - 1.0f)) + 2.0f);
    }
}

float Back::In(float value)
{
    return value * value * value - value * sinf(value * (float)M_PI);
}

float Back::Out(float value)
{
    float f = (1.0f - value);
    return 1.0f - (f * f * f - f * sinf(f * (float)M_PI));
}

float Back::InOut(float value)
{
    if (value < 0.5f)
    {
        float f = 2.0f * value;
        return 0.5f * (f * f * f - f * sinf(f * (float)M_PI));
    }
    else
    {
        float f = (1.0f - (2.0f * value - 1.0f));
        return 0.5f * (1.0f - (f * f * f - f * sinf(f * (float)M_PI))) + 0.5f;
    }
}

float Bounce::In(float value)
{
    return 1.0f - Bounce::Out(1.0f - value);
}

float Bounce::Out(float value)
{
    if (value < 4.0f / 11.0f)
    {
        return (121.0f * value * value) / 16.0f;
    }
    else if (value < 8.0f / 11.0f)
    {
        return (363.0f / 40.0f * value * value) - (99.0f / 10.0f * value) + 17.0f / 5.0f;
    }
    else if (value < 9.0f / 10.0f)
    {
        return (4356.0f / 361.0f * value * value) - (35442.0f / 1805.0f * value) + 16061.0f / 1805.0f;
    }
    else
    {
        return (54.0f / 5.0f * value * value) - (513.0f / 25.0f * value) + 268.0f / 25.0f;
    }
}

float Bounce::InOut(float value)
{
    if (value < 0.5f)
    {
        return 0.5f * Bounce::In(value * 2.0f);
    }
    else
    {
        return 0.5f * Bounce::Out(value * 2.0f - 1.0f) + 0.5f;
    }
}
