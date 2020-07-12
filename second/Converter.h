#pragma once

//SFML and Box2D are really different than each other
namespace Converter
{
	constexpr double PixelPerMeters = 32.0f;
	constexpr double Pi = 3.14159265358979323846;

	template<typename T>
	T PixelsToMeters(const T& pixels)
	{
		return static_cast<T>(pixels / PixelPerMeters);
	}
	template<typename T>
	T MetersToPixels(const T& meters)
	{
		return static_cast<T>(meters * PixelPerMeters);
	}
	template<typename T>
	constexpr T DegreesToRadians(const T& degress)
	{
		return static_cast<T>(Pi * degress / 180.0f);
	}
	template<typename T>
	constexpr T RadiansToDegrees(const T& radians)
	{
		return static_cast<T>(180.0f * radians / Pi);
	}

}