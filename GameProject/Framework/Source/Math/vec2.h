#pragma once

namespace fw {

class vec2
{
public:
	vec2() {}
	vec2(float nx, float ny) : x(nx), y(ny) {}

	vec2 operator+(vec2 o) { return vec2( x + o.x, y + o.y ); }
	vec2 operator-(vec2 o) { return vec2( x - o.x, y - o.y ); }

	vec2 operator*(float o) { return vec2( x * o, y * o ); }
	vec2 operator/(float o) { return vec2( x / o, y / o ); }

	void operator+=(vec2 o) { x += o.x; y += o.y; }
	void operator-=(vec2 o) { x -= o.x; y -= o.y; }

	void operator*=(float o) { x *= o; y *= o; }
	void operator/=(float o) { x /= o; y /= o; }

public:
	float x = 0;
	float y = 0;
};

} // namespace fw
