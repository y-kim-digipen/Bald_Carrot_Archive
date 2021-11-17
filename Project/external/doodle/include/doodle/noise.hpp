/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once


namespace doodle
{
    /**
     * \addtogroup Utility
     *  Helper functions to get noise values.
     *  @{
     */

    /**
     * \brief Returns the Perlin noise value at specified coordinates.
     *
     * Perlin noise is a random sequence generator producing a more natural ordered, harmonic succession of numbers
     * compared to the standard random() function. It was invented by Ken Perlin in the 1980s and been used since in
     * graphical applications to produce procedural textures, natural motion, shapes, terrains etc.
     *
     * The main difference to the random() function is that Perlin noise is defined in an infinite n-dimensional space
     * where each pair of coordinates corresponds to a fixed semi-random value (fixed only for the lifespan of the
     * program; see the seed_noise() function). doodle can compute 1D, 2D and 3D noise, depending on the number of
     * coordinates given. The resulting value will always be between 0.0 and 1.0. The noise value can be animated by
     * moving through the noise space as demonstrated in the example above. The 2nd and 3rd dimension can also be
     * interpreted as time.
     *
     * A way to adjust the character of the resulting sequence is the scale of the input coordinates. As the function
     * works within an infinite space the value of the coordinates doesn't matter as such, only the distance between
     * successive coordinates does (eg. when using noise() within a loop). As a general rule the smaller the difference
     * between coordinates, the smoother the resulting noise sequence will be. Steps of 0.005-0.03 work best for most
     * applications, but this will differ depending on use.
     *
     * \param x x-coordinate in noise space
     * \param y y-coordinate in noise space
     * \param z z-coordinate in noise space
     * \return Perlin noise value (between 0 and 1) at specified coordinates
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         constexpr float noiseScale = 0.035f;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *
     *             clear_background(0);
     *             const auto mouseX = static_cast<float>(get_mouse_x());
     *             const auto mouseY = static_cast<float>(get_mouse_y());
     *             for (int x = 0; x < Width; ++x)
     *             {
     *                 const float noiseValue = noise((mouseX + x) * noiseScale, mouseY * noiseScale);
     *                 const auto  grey       = static_cast<Color4ub::unsigned_byte>(noiseValue * 255.0f);
     *                 set_outline_color(grey);
     *                 draw_line(x * 1.0f, mouseY - noiseValue * 80.0f, x * 1.0f, Height * 1.0f);
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\utility\noise.gif
     */
    float noise(float x, float y = 0.0f, float z = 0.0f) noexcept;
    /**
     * \brief Sets the seed value for noise().
     *
     * By default, noise() produces different results each time the program is run. Set the value parameter to a
     * constant to return the same pseudo-random numbers each time the software is run.
     *
     * \param new_seed The seed value
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_frame_of_reference(LeftHanded_OriginTopLeft);
     *         no_outline();
     *         set_fill_color(255, 128);
     *         constexpr float noiseScale = 0.35599f;
     *         seed_noise(13374269651);
     *         using floats = std::vector<float>;
     *         floats xValues, yValues;
     *         for (int i = 0; i < 10; ++i)
     *         {
     *             const auto fx = noise(i * noiseScale);
     *             const auto fy = noise(0, i * noiseScale);
     *             std::cout << fx << ", " << fy << "\n";
     *             xValues.push_back(60.0f + Width * 0.5f * fx);
     *             yValues.push_back(60.0f + Height * 0.5f * fy);
     *         }
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             for (floats::size_type i = 0; i < xValues.size(); ++i)
     *             {
     *                 draw_ellipse(xValues[i], yValues[i], 16.0f);
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\utility\seed_noise.png
     * Prints the following:
     * \code
     * 0.623153, 0.623153
     * 0.658371, 0.443496
     * 0.682836, 0.34331
     * 0.54437, 0.33238
     * 0.692192, 0.350942
     * 0.361594, 0.444189
     * 0.382214, 0.394488
     * 0.533032, 0.33581
     * 0.819142, 0.375306
     * 0.750284, 0.347514
     * \endcode
     */
    void seed_noise(unsigned long long new_seed) noexcept;

    /**
     * \brief Adjusts the character and level of detail produced by the Perlin noise function.
     *
     * Similar to harmonics in physics, noise is computed over several octaves. Lower octaves contribute more to the
     * output signal and as such define the overall intensity of the noise, whereas higher octaves create finer grained
     * details in the noise sequence.
     *
     * By default, noise is computed over 4 octaves with each octave contributing exactly half than its predecessor,
     * starting at 50% strength for the 1st octave. This falloff amount can be changed by adding an additional function
     * parameter. Eg. a falloff factor of 0.75 means each octave will now have 75% impact (25% less) of the previous
     * lower octave. Any value between 0.0 and 1.0 is valid, however note that values greater than 0.5 might result in
     * greater than 1.0 values returned by noise().
     *
     * By changing these parameters, the signal created by the noise() function can be adapted to fit very specific
     * needs and characteristics.
     *
     * \param perlin_octaves number of octaves to be used by the noise. default is 4
     * \param amplitude_falloff falloff factor for each octave. default is 0.5
     *
     * \code
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 320);
     *     set_texture_mode(RectMode::Center);
     *     Image           noiseImage{};
     *     Texture         texture{};
     *     constexpr float noiseScale = 0.02f;
     *     noiseImage.ResizeToPixelWidthHeight(Width, Height);
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         const float mouseX = static_cast<float>(get_mouse_x());
     *         const float mouseY = static_cast<float>(get_mouse_y());
     *         for (int column = 0; column < noiseImage.GetWidth() / 2; ++column)
     *         {
     *             for (int row = 0; row < noiseImage.GetHeight(); ++row)
     *             {
     *                 set_noise_detail(2, 0.2f);
     *                 float noiseValue = noise((mouseX + column) * noiseScale, (mouseY + row) * noiseScale);
     *                 auto  grey       = static_cast<Color4ub::unsigned_byte>(noiseValue * 255);
     *                 noiseImage.SetPixel(column, row, Color4ub{grey});
     *
     *                 set_noise_detail(8, 0.65f);
     *                 noiseValue = noise((mouseX + column + Width / 2.0f) * noiseScale, (mouseY + row) * noiseScale);
     *                 // because the falloff is > 0.5, we may get noise values > 1, so we need to clamp our values
     *                 grey = static_cast<Color4ub::unsigned_byte>(std::clamp(noiseValue * 255, 0.0f, 255.0f));
     *                 noiseImage.SetPixel(column + Width / 2, row, Color4ub{grey});
     *             }
     *         }
     *         if (const bool loaded = texture.LoadFromImage(noiseImage); loaded)
     *         {
     *             draw_texture(texture, 0, 0);
     *         }
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\utility\set_noise_detail.gif
     */
    void set_noise_detail(int perlin_octaves, float amplitude_falloff) noexcept;
    /** @} */
}
