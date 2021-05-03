#pragma once
class Vector2 {
public:
	float x = 0.0f, y = 0.0f;

	Vector2() {

	}
	explicit Vector2(float scalar)
		: x(scalar), y(scalar) {
	}
	Vector2(float x, float y)
		: x(x), y(y) {
	}

	Vector2(const Vector2& other)
		: x(other.x), y(other.y) {

	}

	Vector2(Vector2&& other) noexcept
		: x(other.x), y(other.y) {

	}

	~Vector2() {

	}

	Vector2& operator=(const Vector2& other) noexcept {
		if (&other != this) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}

	Vector2& operator=(Vector2&& other) noexcept {
		x = other.x;
		y = other.y;

		return *this;
	}
};