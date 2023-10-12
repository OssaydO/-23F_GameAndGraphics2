#pragma once

#include <functional>

using EasingFunction = std::function<float(float)>;

//Linear ease
struct Linear
{
    static float Interpolation(float value);
};

//Quadratic ease (in, out, inOut)
struct Quadratic
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Cubic ease (in, out, inOut)
struct Cubic
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Quartic ease (in, out, inOut)
struct Quartic
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Quintic ease (in, out, inOut)
struct Quintic
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Sinusoidal ease (in, out, inOut)
struct Sinusoidal
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Exponential ease (in, out, inOut)
struct Exponential
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Circular ease (in, out, inOut)
struct Circular
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Elastic ease (in, out, inOut)
struct Elastic
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Back ease (in, out, inOut)
struct Back
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};

//Bounce ease (in, out, inOut)
struct Bounce
{
    static float In(float value);
    static float Out(float value);
    static float InOut(float value);
};
