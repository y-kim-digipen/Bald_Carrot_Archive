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
     *  Helper functions to get random numbers.
     *  @{
     */

    /**
     * \brief Sets the seed value for random().
     *
     * By default, random() produces different results each time the program is run. Set the seed parameter to a
     * constant to return the same pseudo-random numbers each time the software is run.
     *
     * \param seed the seed value
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         seed_random(13374269);
     *         for (int x = 0; x < Width; ++x)
     *         {
     *             const auto grey = static_cast<Color4ub::unsigned_byte>(random(256));
     *             set_outline_color(grey);
     *             draw_line(x * 1.0f, 0.0f, x * 1.0f, Height * 1.0f);
     *         }
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\utility\seed_random.png
     */
    void seed_random(unsigned int seed) noexcept;
    /**
     * \brief Return a random floating-point number within the range [min,max)
     * \param min_inclusive the inclusive lower bound or the minimum value to be returned
     * \param max_exclusive the exclusive upper bound or the maximum value but won't be returned.
     * \return random number
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         float           trauma    = 1.0f;
     *         constexpr float MaxAngle  = QUARTER_PI / 2.0f;
     *         constexpr float MaxOffset = 50.0f;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xFCF4EFFF});
     *
     *             if (KeyIsPressed)
     *             {
     *                 trauma += 0.05f;
     *                 trauma = std::clamp(trauma, 0.0f, 1.0f);
     *             }
     *             const float shake = trauma * trauma;
     *
     *             set_frame_of_reference(RightHanded_OriginBottomLeft);
     *             set_fill_color(HexColor{0xA0C7BADD});
     *             draw_rectangle(0, 0, 32.0f, 2.0f + trauma * Height);
     *             set_fill_color(HexColor{0xD9E4CEDD});
     *             draw_rectangle(32.0f, 0, 32.0f, 2.0f + shake * Height);
     *
     *             if (trauma > 0)
     *             {
     *                 const float offsetX = MaxOffset * shake * random(-1.0f, 1.0f);
     *                 const float offsetY = MaxOffset * shake * random(-1.0f, 1.0f);
     *                 const float angle   = MaxAngle * shake * random(-1.0f, 1.0f);
     *                 apply_translate(offsetX, offsetY);
     *                 apply_rotate(angle);
     *                 trauma -= DeltaTime;
     *                 trauma = std::clamp(trauma, 0.0f, 1.0f);
     *             }
     *
     *             set_frame_of_reference(RightHanded_OriginCenter);
     *             set_fill_color(HexColor{0x5FA8B9FF});
     *             draw_ellipse(-50.0f, 50.0f, 32.0f);
     *             draw_ellipse(50.0f, 50.0f, 32.0f);
     *             set_fill_color(HexColor{0x1A344DFF});
     *             draw_ellipse(0.0f, -100.0f, 50.0f, 100.0f);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\utility\random_1_min_max_float.gif
     */
    float random(float min_inclusive, float max_exclusive) noexcept;
    /**
     * \brief Return a random floating-point number within the range [0,max)
     *
     * It is the same as calling \code random(0.0f,max_exclusive); \endcode
     *
     * \param max_exclusive the exclusive upper bound or the maximum value but won't be returned.
     * \return random number
     *
     * \code
     *     #include <cmath>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     void DrawRandomLineOnCircle() noexcept
     *     {
     *         // 1st random point on circle
     *         const float angle1 = random(TWO_PI);
     *         const float x1     = 200.0f * std::cos(angle1);
     *         const float y1     = 200.0f * std::sin(angle1);
     *
     *         // 2nd random point on circle
     *         const float angle2 = random(TWO_PI);
     *         const float x2     = 200.0f * std::cos(angle2);
     *         const float y2     = 200.0f * std::sin(angle2);
     *
     *         draw_line(x1, y1, x2, y2);
     *     }
     *     int main(void)
     *     {
     *         create_window(400, 400);
     *         clear_background(255);
     *         set_outline_color(0, 25);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             DrawRandomLineOnCircle();
     *             DrawRandomLineOnCircle();
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\utility\random_2_max_float.gif
     */
    float random(float max_exclusive) noexcept;
    /**
     * \brief Return a random floating-point number within the range [0,1)
     *
     * It is the same as calling \code random(0.0f,1.0f); \endcode
     *
     * \return random number between 0 and 1
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         constexpr float thickness = 30.0f;
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         for (int i = 0; i < 10; ++i)
     *         {
     *             const float x = random() * (Width - thickness) + thickness;
     *             const float y = random() * (Height - thickness) + thickness;
     *             draw_ellipse(x, y, thickness);
     *         }
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\utility\random_3_normalized_float.png
     */
    float random() noexcept;
    /**
     * \brief Return a random integer number within the range [min,max)
     *
     * \param min_inclusive the inclusive lower bound or the minimum value to be returned
     * \param max_exclusive the exclusive upper bound or the maximum value but won't be returned.
     * \return random number
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         clear_background(220);
     *         for (int i = 0; i < Height; ++i)
     *         {
     *             const int  r = random(-Width / 2, Width / 2);
     *             const auto y = static_cast<float>(i);
     *             draw_line(Width / 2.0f, y, Width / 2.0f + r, y);
     *         }
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\utility\random_4_minmax_int.png
     */
    int random(int min_inclusive, int max_exclusive) noexcept;
    /**
     * \brief Return a random integer number within the range [0,max)
     *
     * It is the same as calling \code random(0,max_exclusive); \endcode
     *
     * \param max_exclusive the exclusive upper bound or the maximum value but won't be returned.
     * \return random number
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         clear_background(220);
     *         for (int i = 0; i < Height; ++i)
     *         {
     *             const auto grey = static_cast<Color4ub::unsigned_byte>(random(50));
     *             set_outline_color(5 * grey);
     *             const auto y = static_cast<float>(i);
     *             draw_line(0, y, 10.0f + grey * (Width / 50.0f), y);
     *         }
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\utility\random_5_max_int.png
     */
    int random(int max_exclusive) noexcept;
    /** @} */
}
