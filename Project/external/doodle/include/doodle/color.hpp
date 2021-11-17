/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once


namespace doodle
{
    /**
     *  * \addtogroup Color
     *  Classes to represent colors.
     *  @{
     */

    /**
     * \class Color4ub color.hpp doodle/color.hpp
     * \brief Color4ub is a color represented with four unsigned bytes.
     *
     * It has the red, green, blue, and alpha color channels in the range of 0 to 255, where 255 is full intensity of
     * the color channel, 128 is roughly half intensity and 0 is no intensity of the color channel. The alpha channel
     * doesn't contribute light intensity but is used to define transparency. The alpha value also uses the range 0 to
     * 255 to set the amount of transparency. The value 0 defines the color as entirely transparent (it won't display),
     * the value 255 is entirely opaque, and the values between these extremes cause the colors to mix on the screen.
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(100, 100);
     *         set_outline_width(3.0f);
     *         Color4ub squareColor{100, 50, 150};
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(255);
     *             no_fill();
     *             set_outline_color(0);
     *             draw_ellipse(0, 0, 80.f);
     *             squareColor.alpha = static_cast<Color4ub::unsigned_byte>(128 + 128.0f * std::sin(ElapsedTime));
     *             set_fill_color(squareColor);
     *             no_outline();
     *             draw_rectangle(-Width / 2.0f + 13, -Height / 2.0f + 13, Width - 26.0f, Height - 26.0f);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\Color4ub_Example.gif
     */
    class [[nodiscard]] Color4ub
    {
    public:
        /**
         * \brief Each color channel can be represented with an unsigned byte, so this is an alias to communicate that.
         */
        using unsigned_byte = unsigned char;

        unsigned_byte red   = 0;
        unsigned_byte green = 0;
        unsigned_byte blue  = 0;
        unsigned_byte alpha = 255;

    public:
        /**
         * \brief The default color is black with full opacity.
         * \code
         *     #include <doodle/doodle.hpp>
         *     using namespace doodle;
         *     int main(void)
         *     {
         *         create_window(100, 100);
         *         no_outline();
         *         while (!is_window_closed())
         *         {
         *             update_window();
         *             clear_background(220);
         *             set_fill_color(Color4ub{}); // default is black color
         *             draw_ellipse(0, 0, 35);
         *         }
         *         return 0;
         *     }
         * \endcode
         * \image html images\color\Color4ub_Ctor_Default.png
         */
        constexpr Color4ub() noexcept = default;
        /**
         * \brief Note that if only one value is provided to Color4ub, it will be interpreted as a grayscale value. Add
         * a second value, and it will be used for alpha transparency.
         *
         * \param grey number specifying value between white and black
         * \param alpha alpha value relative to color range 0-255
         *
         * \code
         *     #include <doodle/doodle.hpp>
         *     using namespace doodle;
         *     int main(void)
         *     {
         *         create_window(100, 100);
         *         no_outline();
         *         while (!is_window_closed())
         *         {
         *             update_window();
         *             clear_background(Color4ub{220});
         *             set_fill_color(Color4ub{255});
         *             draw_rectangle(-20, -20, 35, 35);
         *             set_fill_color(Color4ub{100, 128});
         *             draw_rectangle(0, 0, 35, 35);
         *         }
         *         return 0;
         *     }
         * \endcode
         * \image html images\color\Color4ub_Ctor_Grey.png
         */
        explicit constexpr Color4ub(unsigned_byte grey, unsigned_byte alpha = 255) noexcept
            : red(grey), green(grey), blue(grey), alpha(alpha)
        {
        }
        /**
         * \brief When three values are specified, they are interpreted as RGB. Adding a fourth value applies
         * alpha transparency.
         *
         * \param red red value relative to the color range 0-255
         * \param green value relative to the color range 0-255
         * \param blue value relative to the color range 0-255
         * \param alpha alpha value relative to color range 0-255
         *
         * \code
         *     #include <doodle/doodle.hpp>
         *     using namespace doodle;
         *     int main(void)
         *     {
         *         create_window(100, 100);
         *         no_outline();
         *         constexpr Color4ub yellow{255, 204, 0};
         *         constexpr Color4ub transparent_green{220, 236, 165, 120};
         *         while (!is_window_closed())
         *         {
         *             update_window();
         *             clear_background(220);
         *             set_fill_color(yellow);
         *             draw_ellipse(-20, 20, 80);
         *             set_fill_color(transparent_green);
         *             draw_ellipse(15, -15, 80);
         *         }
         *         return 0;
         *     }
         * \endcode
         * \image html images\color\Color4ub_Ctor_RGBA.png
         */
        constexpr Color4ub(unsigned_byte red, unsigned_byte green, unsigned_byte blue,
                           unsigned_byte alpha = 255) noexcept
            : red(red), green(green), blue(blue), alpha(alpha)
        {
        }
    };

    static_assert(sizeof(Color4ub) == 4,
                  "Color4ub should be the same as 4 bytes, so we can easily treat it as an RGBA int.");

    /**
     * \class HexColor color.hpp doodle/color.hpp
     * \brief This is a helper class to easily represent an RGBA color as an int with hexadecimal notation.
     */
    class [[nodiscard]] HexColor
    {
    public:
        unsigned rgba = 0x000000ff;

        /**
         * \brief The default color is black with full opacity.
         * \code
         *     #include <doodle/doodle.hpp>
         *     using namespace doodle;
         *     int main(void)
         *     {
         *         create_window(100, 100);
         *         no_outline();
         *         while (!is_window_closed())
         *         {
         *             update_window();
         *             clear_background(220);
         *             set_fill_color(HexColor{}); // default is black color
         *             draw_ellipse(0, 0, 35);
         *         }
         *         return 0;
         *     }
         * \endcode
         * \image html images\color\Color4ub_Ctor_Default.png
         */
        constexpr HexColor() noexcept = default;
        /**
         * \brief Implicitly convert from an unsigned int into a Hex Color.
         *
         * \param hex unsigned number to read as RGBA
         *
         * \code
         *     #include <doodle/doodle.hpp>
         *     using namespace doodle;
         *     int main(void)
         *     {
         *         create_window(100, 100);
         *         no_outline();
         *         constexpr unsigned r   = 0xff0000ff;
         *         constexpr HexColor red = r;
         *         while (!is_window_closed())
         *         {
         *             update_window();
         *             clear_background(220);
         *             set_fill_color(red);
         *             draw_ellipse(0, 0, 35);
         *         }
         *         return 0;
         *     }
         * \endcode
         * \image html images\color\HexColor_Ctor_Unsigned.png
         */
        constexpr HexColor(unsigned hex) noexcept : rgba(hex) {}
        /**
         * \brief Implicitly convert from an int into a Hex Color
         *
         * \param hex int number to read as RGBA
         *
         * \code
         *     #include <doodle/doodle.hpp>
         *     using namespace doodle;
         *     int main(void)
         *     {
         *         create_window(100, 100);
         *         no_outline();
         *         constexpr int      g     = 0x00ff00ff;
         *         constexpr HexColor green = g;
         *         while (!is_window_closed())
         *         {
         *             update_window();
         *             clear_background(220);
         *             set_fill_color(green);
         *             draw_ellipse(0, 0, 35);
         *         }
         *         return 0;
         *     }
         * \endcode
         * \image html images\color\HexColor_Ctor_Int.png
         */
        constexpr HexColor(int hex) noexcept : rgba(unsigned(hex)) {}
        /**
         * \brief Implicitly convert from a HexColor to a Color4ub.
         *
         * This is really the reason why this class exists. This allows us to implicitly specify an RGBA color with a
         * single int and store it as a Color4ub.
         * \code
         *     #include <doodle/doodle.hpp>
         *     using namespace doodle;
         *     void SetMyColor(Color4ub color) noexcept
         *     {
         *         set_fill_color(color);
         *         set_outline_color(0);
         *     }
         *     int main(void)
         *     {
         *         create_window(100, 100);
         *         while (!is_window_closed())
         *         {
         *             update_window();
         *             clear_background(220);
         *             SetMyColor(HexColor{0x0000ffff}); // implicitly convert from HexColor to Color4ub
         *             draw_ellipse(-25, 25, 40);
         *             SetMyColor(HexColor{0xaaed5fff});
         *             draw_rectangle(0, -40, 40);
         *         }
         *         return 0;
         *     }
         * \endcode
         * \image html images\color\HexColor_to_Color4ub.png
         */
        constexpr operator Color4ub() const noexcept
        {
            return Color4ub{static_cast<Color4ub::unsigned_byte>((rgba & 0xff000000) >> 24),
                            static_cast<Color4ub::unsigned_byte>((rgba & 0x00ff0000) >> 16),
                            static_cast<Color4ub::unsigned_byte>((rgba & 0x0000ff00) >> 8),
                            static_cast<Color4ub::unsigned_byte>((rgba & 0x000000ff) >> 0)};
        }
    };
    /** @} */
}
