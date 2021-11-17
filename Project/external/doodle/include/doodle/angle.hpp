/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once


namespace doodle
{
    /**
     *  * \defgroup Angles Angles
     *  Constants for common angles measured in radians. Also contains some helper functions related to angles.
     *  @{
     */
    /**
     * \brief \f$\pi\f$
     *
     * PI is a mathematical constant with the value 3.14159265358979323846. It is the ratio of the circumference of a
     * circle to its diameter. It is useful in combination with the trigonometric functions sin() and cos().
     * \code
     *     float x = std::cos(PI);
     *     float y = std::sin(PI);
     * \endcode
     */
    constexpr float PI = 3.1415926535897932384626433832795f;
    /**
     * \brief \f$\frac{\pi}{2}\f$
     *
     * HALF_PI is a mathematical constant with the value 1.57079632679489661923. It is half the ratio of the
     * circumference of a circle to its diameter. It is useful in combination with the trigonometric functions sin() and
     * cos().
     * \code
     *     float x = std::cos(HALF_PI);
     *     float y = std::sin(HALF_PI);
     * \endcode
     */
    constexpr float HALF_PI = PI / 2.0f;
    /**
     * \brief \f$\frac{\pi}{4}\f$
     *
     * QUARTER_PI is a mathematical constant with the value 0.7853982. It is one quarter the ratio of the circumference
     * of a circle to its diameter. It is useful in combination with the trigonometric functions sin() and cos().
     * \code
     *     float x = std::cos(QUARTER_PI);
     *     float y = std::sin(QUARTER_PI);
     * \endcode
     */
    constexpr float QUARTER_PI = PI / 4.0f;
    /**
     * \brief \f$2\pi\f$
     *
     * TWO_PI is a mathematical constant with the value 6.28318530717958647693. It is twice the ratio of the
     * circumference of a circle to its diameter. It is useful in combination with the trigonometric functions sin() and
     * cos().
     * \code
     *     float x = std::cos(TWO_PI);
     *     float y = std::sin(TWO_PI);
     * \endcode
     */
    constexpr float TWO_PI = 2.0f * PI;

    /**
     * \brief Converts a degree measurement to its corresponding value in radians. Radians and degrees are two ways of
     * measuring the same thing. There are 360 degrees in a circle and \f$2\pi\f$ radians in a circle. For example,
     * \f$90^{\circ}=\frac{\pi}{2}=1.5707964\f$.
     *
     * \param angle_in_degrees an angle measured in degrees
     *
     * \code
     *     constexpr float theta = to_radians(45.0f);
     *     std::cout << 45.0f << " degrees is " << theta << " radians\n";
     *     // prints: 45 degrees is 0.785398 radians
     * \endcode
     * \return the corresponding angle measured in radians
     */
    constexpr float to_radians(float angle_in_degrees) noexcept { return angle_in_degrees * PI / 180.0f; }
    /**
     * \brief Converts a radian measurement to its corresponding value in degrees. Radians and degrees are two ways of
     * measuring the same thing. There are 360 degrees in a circle and \f$2\pi\f$ radians in a circle. For example,
     * \f$90^{\circ}=\frac{\pi}{2}=1.5707964\f$.
     *
     * \param angle_in_radians an angle measured in radians
     *
     * \code
     *     constexpr float theta = to_degrees(QUARTER_PI);
     *     std::cout << QUARTER_PI << " radians is " << theta << " degrees\n";
     *     // prints: 0.785398 radians is 45 degrees
     * \endcode
     * \return the corresponding angle measured in degrees
     */
    constexpr float to_degrees(float angle_in_radians) noexcept { return angle_in_radians * 180.0f / PI; }

    /** @} */
}
