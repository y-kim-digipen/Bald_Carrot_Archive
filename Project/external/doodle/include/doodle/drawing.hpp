/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once
#include <doodle/color.hpp>

#include <doodle/image.hpp>
#include <doodle/texture.hpp>
#include <string>

namespace doodle
{
    /**
     *  * \addtogroup Color
     *  Functions to Set Color
     *  @{
     */
    /**
     * \brief Clear the background to black.
     *
     * The clear_background() function sets the color used for the background of the canvas. The default
     * background is black. This function is typically used within draw loop to clear the display window at the
     * beginning of each frame, but it can be used outside the loop to set the background on the first frame of
     * animation or if the background need only be set once.
     *
     * \code
     * #include <cstdlib>
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 360);
     *     clear_background();
     *     const Image results = capture_screenshot_to_image();
     *     results.SaveToPNG(R"(clear_background_1.png)");
     *     std::system(R"(start clear_background_1.png)");
     *     return 0;
     * }
     * \endcode
     *
     * \image html images\color\setting_color\clear_background_1.png
     */
    void clear_background() noexcept;
    /**
     * \brief Clear the background to the specified HexColor
     *
     * The clear_background() function sets the color used for the background of the canvas. The default
     * background is black. This function is typically used within draw loop to clear the display window at the
     * beginning of each frame, but it can be used outside the loop to set the background on the first frame of
     * animation or if the background need only be set once.
     *
     * \param color HexColor to clear the screen to.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         clear_background(HexColor{0x2B61D5FF});
     *         const Image results = capture_screenshot_to_image();
     *         results.SaveToPNG(R"(clear_background_2.png)");
     *         std::system(R"(start background_2.png)");
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\color\setting_color\clear_background_2.png
     */
    void clear_background(HexColor color) noexcept;
    /**
     * \brief Clear the background to the specified Color4ub.
     *
     * The clear_background() function sets the color used for the background of the canvas. The default
     * background is black. This function is typically used within draw loop to clear the display window at the
     * beginning of each frame, but it can be used outside the loop to set the background on the first frame of
     * animation or if the background need only be set once.
     *
     * \param color Color4ub to clear the screen to
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     Color4ub GenerateColor()
     *     {
     *         using ub            = Color4ub::unsigned_byte;
     *         const float control = ElapsedTime / 3.0f;
     *         const float r       = 0.25f + noise(control) * 0.75f;
     *         const float g       = 0.25f + noise(control * 2.0f, control) * 0.75f;
     *         const float b       = 0.25f + noise(control / 2.0f, control / 4.0f, control) * 0.75f;
     *         return Color4ub{static_cast<ub>(r * 255), static_cast<ub>(g * 255), static_cast<ub>(b * 255 )};
     *     }
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(GenerateColor());
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\color\setting_color\clear_background_color4ub.gif
     */
    void clear_background(Color4ub color) noexcept;
    /**
     * \brief Clear the background to a grey color.
     *
     * The clear_background() function sets the color used for the background of the canvas. The default
     * background is black. This function is typically used within draw loop to clear the display window at the
     * beginning of each frame, but it can be used outside the loop to set the background on the first frame of
     * animation or if the background need only be set once.
     *
     * \param grey specifies a value between white and black
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_fill_color(255, 64);
     *         no_outline();
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             using ub       = Color4ub::unsigned_byte;
     *             const ub alpha = static_cast<ub>(255.0f * (std::sin(ElapsedTime) * 0.5f + 0.5f));
     *             clear_background(220, alpha);
     *             draw_ellipse(0, 0, Width / 2.0f);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\color\setting_color\clear_background_grey_alpha.gif
     */
    void clear_background(Color4ub::unsigned_byte grey, Color4ub::unsigned_byte alpha = 255) noexcept;
    /**
     * \brief Clear the background to a specified RGBA color.
     *
     * The clear_background() function sets the color used for the background of the canvas. The default
     * background is black. This function is typically used within draw loop to clear the display window at the
     * beginning of each frame, but it can be used outside the loop to set the background on the first frame of
     * animation or if the background need only be set once.
     *
     * \param red value between 0-255
     * \param green value between 0-255
     * \param blue value between 0-255
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         no_outline();
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(255, 204, 0);
     *             draw_ellipse(0, 0, Width / 2.0f);
     *             using ub       = Color4ub::unsigned_byte;
     *             const ub alpha = static_cast<ub>(255.0f * (std::cos(ElapsedTime * 2.0f) * 0.5f + 0.5f));
     *             clear_background(0, 0, 255, alpha);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\color\setting_color\clear_background_rgba.gif
     */
    void clear_background(Color4ub::unsigned_byte red, Color4ub::unsigned_byte green, Color4ub::unsigned_byte blue,
                          Color4ub::unsigned_byte alpha = 255) noexcept;

    /**
     * \brief Sets the color used to fill shapes to the specified HexColor.
     *
     * For example, if you run set_fill_color(HexColor{0xffaaeeff}), all shapes drawn after the fill command will be
     * filled with the color pink. The color space is RGBA, with each value in the range from 0 to 255.
     *
     * \param color HexColor to apply
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_rectangle_mode(RectMode::Center);
     *         clear_background(220);
     *         set_fill_color(HexColor{0xffaaeeff}); // pink
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(set_fill_color_1_hexcolor.png)");
     *         std::system(R"(start set_fill_color_1_hexcolor.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\set_fill_color_1_hexcolor.png
     */
    void set_fill_color(HexColor color) noexcept;
    /**
     * \brief Sets the color used to fill shapes to the specified Color4ub.
     *
     * For example, if you run set_fill_color(Color4ub{0,255,0,64}), all shapes drawn after the fill command will be
     * filled with a translucent green color. The color space is RGBA, with each value in the range from 0 to 255.
     *
     * \param color Color4ub to apply
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_rectangle_mode(RectMode::Center);
     *         clear_background(220);
     *         set_fill_color(Color4ub{0, 255, 0, 64}); // see-through green
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         draw_rectangle(0, -Width / 4.0f, Width * 0.2f, Height * 0.2f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(set_fill_color_2_color4ub.png)");
     *         std::system(R"(start set_fill_color_2_color4ub.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\set_fill_color_2_color4ub.png
     */
    void set_fill_color(Color4ub color) noexcept;
    /**
     * \brief Sets the color used to fill shapes to a grey.
     *
     * For example, if you run set_fill_color(51), all shapes drawn after the fill command will be filled with the color
     * dark dark grey. The color space is RGBA, with each value in the range from 0 to 255.
     *
     * \param grey specifies a value between white and black
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_rectangle_mode(RectMode::Center);
     *         clear_background(220);
     *         set_fill_color(51);
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(set_fill_color_3_grey.png)");
     *         std::system(R"(start set_fill_color_3_grey.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\set_fill_color_3_grey.png
     */
    void set_fill_color(Color4ub::unsigned_byte grey, Color4ub::unsigned_byte alpha = 255) noexcept;
    /**
     * \brief Sets the color used to fill shapes to the specified RGBA values.
     *
     * For example, if you run set_fill_color(138,43,226), all shapes drawn after the fill command will be filled with
     * the color purple. The color space is RGBA, with each value in the range from 0 to 255.
     *
     * \param red value between 0-255
     * \param green value between 0-255
     * \param blue value between 0-255
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_rectangle_mode(RectMode::Center);
     *         clear_background(220);
     *         set_fill_color(138, 43, 226);
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         draw_rectangle(0, -Width / 4.0f, Width * 0.2f, Height * 0.2f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(set_fill_color_4_rgba.png)");
     *         std::system(R"(start set_fill_color_4_rgba.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\set_fill_color_4_rgba.png
     */
    void set_fill_color(Color4ub::unsigned_byte red, Color4ub::unsigned_byte green, Color4ub::unsigned_byte blue,
                        Color4ub::unsigned_byte alpha = 255) noexcept;
    /**
     * \brief Disables filling geometry.
     *
     * If both no_outline() and no_fill() are called, nothing will be drawn to the screen.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_rectangle_mode(RectMode::Center);
     *         clear_background(220);
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         no_fill();
     *         draw_rectangle(10, 20, Width * 0.6f, Height * 0.6f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(no_fill.png)");
     *         std::system(R"(start no_fill.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\no_fill.png
     */
    void no_fill() noexcept;
    /**
     * \brief Set the outline and lines of shapes to the specified HexColor.
     *
     * Sets the color used to draw lines and borders around shapes. The color space is RGBA, with each value in the
     * range from 0 to 255.
     *
     * \param color HexColor to apply
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(100, 100);
     *         set_rectangle_mode(RectMode::Center);
     *         set_outline_width(4.0f);
     *         clear_background(220);
     *         set_outline_color(HexColor{0x2B61D5FF});
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(set_outline_color_1_hexcolor.png)");
     *         std::system(R"(start set_outline_color_1_hexcolor.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\set_outline_color_1_hexcolor.png
     */
    void set_outline_color(HexColor color) noexcept;
    /**
     * \brief Set the outline and lines of shapes to the specified Color4ub.
     *
     * Sets the color used to draw lines and borders around shapes. The color space is RGBA, with each value in the
     * range from 0 to 255.
     *
     * \param color Color4ub to apply
     *
     * \code
     * #include <cstdlib>
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(200, 200);
     *     set_rectangle_mode(RectMode::Center);
     *     set_outline_width(20.0f);
     *     clear_background(220);
     *     set_outline_color(Color4ub{0, 255, 0, 64}); // see-through green
     *     draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *     draw_rectangle(0, -Width / 4.0f, Width * 0.2f, Height * 0.2f);
     *     const Image results = capture_screenshot_to_image();
     *     close_window();
     *     results.SaveToPNG(R"(set_outline_color_2_color4ub.png)");
     *     std::system(R"(start set_outline_color_2_color4ub.png)");
     *     return 0;
     * }
     * \endcode
     * \image html images\color\setting_color\set_outline_color_2_color4ub.png
     */
    void set_outline_color(Color4ub color) noexcept;
    /**
     * \brief Set the outline and lines of shapes to a grey color.
     *
     * Sets the color used to draw lines and borders around shapes. The color space is RGBA, with each value in the
     * range from 0 to 255.
     *
     * \param grey specifies a value between white and black
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(200, 200);
     *         set_rectangle_mode(RectMode::Center);
     *         set_outline_width(20.0f);
     *         clear_background(51, 65, 80);
     *         set_outline_color(220);
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(set_outline_color_3_grey.png)");
     *         std::system(R"(start set_outline_color_3_grey.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\set_outline_color_3_grey.png
     */
    void set_outline_color(Color4ub::unsigned_byte grey, Color4ub::unsigned_byte alpha = 255) noexcept;
    /**
     * \brief Set the outline and lines of shapes to an RGBA color.
     *
     * Sets the color used to draw lines and borders around shapes. The color space is RGBA, with each value in the
     * range from 0 to 255.
     *
     * \param red value between 0-255
     * \param green value between 0-255
     * \param blue value between 0-255
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(200, 200);
     *         set_rectangle_mode(RectMode::Center);
     *         clear_background(220);
     *         set_outline_color(138, 43, 226);
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         draw_rectangle(0, -Width / 4.0f, Width * 0.2f, Height * 0.2f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(set_outline_color_4_rgba.png)");
     *         std::system(R"(start set_outline_color_4_rgba.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\set_outline_color_4_rgba.png
     */
    void set_outline_color(Color4ub::unsigned_byte red, Color4ub::unsigned_byte green, Color4ub::unsigned_byte blue,
                           Color4ub::unsigned_byte alpha = 255) noexcept;
    /**
     * \brief Disables drawing the outline.
     *
     * If both no_outline() and no_fill() are called, nothing will be drawn to the screen.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(200, 200);
     *         set_rectangle_mode(RectMode::Center);
     *         clear_background(220);
     *         no_outline();
     *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         const Image results = capture_screenshot_to_image();
     *         close_window();
     *         results.SaveToPNG(R"(no_outline.png)");
     *         std::system(R"(start no_outline.png)");
     *         return 0;
     *     }
     * \endcode
     * \image html images\color\setting_color\no_outline.png
     */
    void no_outline();
    /** @} */

    /**
     *  * \addtogroup Shape
     *  2D Primitive shape drawing and Attributes about the shapes.
     *  @{
     */

    /**
     * \brief Draws an ellipse (oval) to the screen.
     *
     * An ellipse with equal width and height is a circle. By default, the first two parameters set the location, and
     * the third and fourth parameters set the shape's width and height. If no height is specified, the value of width
     * is used for both the width and height. The origin may be changed with the set_ellipse_mode() function. By default
     * the (x,y) location is in the center of the ellipse.
     *
     * \param x x-coordinate of the ellipse.
     * \param y y-coordinate of the ellipse.
     * \param width width of the ellipse.
     * \param height height of the ellipse.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xBF8679FF});
     *             set_fill_color(HexColor{0x8C2B2EFF});
     *             // opaque and wide ellipse
     *             draw_ellipse(0, 0, Width * 0.8f, Height * 0.6f);
     *             set_fill_color(HexColor{0xDDD3D680});
     *             // translucent circle
     *             draw_ellipse(0, 0, Width * 0.6f);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\2dprimitives\draw_ellipse.png
     */
    void draw_ellipse(float x, float y, float width, float height = 0) noexcept;
    /**
     * \brief Draws a line (a direct path between two points) to the screen.
     *
     * To color a line, use the set_outline_color() function. A line cannot be filled, therefore the set_fill_color()
     * function will not affect the color of a line. Lines are drawn with a width of one pixel by default, but this can
     * be changed with the set_outline_width() function.
     *
     * \param x1 the x-coordinate of the first point
     * \param y1 the y-coordinate of the first point
     * \param x2 the x-coordinate of the second point
     * \param y2 the y-coordinate of the second point
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(200);
     *             set_outline_color(0);
     *             const float top    = Height - 30.0f;
     *             const float bottom = 30.0f;
     *             const float left   = 30.0f;
     *             const float right  = Width - 30.0f;
     *             draw_line(left, top, right, top);
     *             set_outline_color(126);
     *             draw_line(right, top, right, bottom);
     *             set_outline_color(255);
     *             draw_line(left, bottom, right, bottom);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\2dprimitives\draw_line.png
     */
    void draw_line(float x1, float y1, float x2, float y2) noexcept;
    /**
     * \brief Draw a quad.
     *
     * A quad is a quadrilateral, a four sided polygon. It is similar to a rectangle, but the angles between its edges
     * are not constrained to ninety degrees. The first pair of parameters (x1,y1) sets the first vertex and the
     * subsequent pairs should proceed clockwise or counter-clockwise around the defined shape.
     *
     * \param x1 the x-coordinate of the first point
     * \param y1 the y-coordinate of the first point
     * \param x2 the x-coordinate of the second point
     * \param y2 the y-coordinate of the second point
     * \param x3 the x-coordinate of the third point
     * \param y3 the y-coordinate of the third point
     * \param x4 the x-coordinate of the fourth point
     * \param y4 the y-coordinate of the forth point
     *
     * \code
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 320);
     *     set_frame_of_reference(LeftHanded_OriginTopLeft);
     *     set_outline_color(HexColor{0xAD4A3BFF});
     *     set_fill_color(HexColor{0xEBE3C0FF});
     *     set_outline_width(3.0f);
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         clear_background(HexColor{0x457648FF});
     *         draw_quad(152, 124, 344, 80, 276, 252, 120, 304);
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\shapes\2dprimitives\draw_quad.png
     */
    void draw_quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) noexcept;
    /**
     * \brief Draws a rectangle to the screen.
     *
     * A rectangle is a four-sided shape with every angle at ninety degrees. By default, the first two parameters set
     * the location of a corner, the third sets the width, and the fourth sets the height. The way these parameters are
     * interpreted, however, may be changed with the set_rectangle_mode() function. If the height is omitted then the
     * height will be set to the width, thus creating a square.
     *
     * \param x x-coordinate of the rectangle.
     * \param y y-coordinate of the rectangle.
     * \param width width of the rectangle.
     * \param height height of the rectangle.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x9EA2B8FF});
     *             set_fill_color(HexColor{0x7E5873FF});
     *             // opaque and wide rectangle
     *             float left = Width * -0.4f, bottom = Height * -0.3f;
     *             draw_rectangle(left, bottom, Width * 0.8f, Height * 0.6f);
     *             set_fill_color(HexColor{0x372F4A80});
     *             // translucent square
     *             left = Width * -0.3f, bottom = Width * -0.3f;
     *             draw_rectangle(left, bottom, Width * 0.6f);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\2dprimitives\draw_rectangle.png
     */
    void draw_rectangle(float x, float y, float width, float height = 0) noexcept;
    /**
     * \brief Draw a triangle to the screen.
     *
     * A triangle is a plane created by connecting three points. The first two arguments specify the first point, the
     * middle two arguments specify the second point, and the last two arguments specify the third point.
     *
     * \param x1 the x-coordinate of the first point
     * \param y1 the y-coordinate of the first point
     * \param x2 the x-coordinate of the second point
     * \param y2 the y-coordinate of the second point
     * \param x3 the x-coordinate of the third point
     * \param y3 the y-coordinate of the third point
     *
     * \code
     * #include <cmath>
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 320);
     *     set_fill_color(HexColor{0xE5C8B4FF});
     *     set_outline_color(HexColor{0x483524FF});
     *     set_outline_width(3.0f);
     *     float offset = 0.0f;
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         clear_background(HexColor{0xA47B56FF});
     *         const float angle1 = offset + TWO_PI / 3.0f + to_radians(60.0f) * noise(ElapsedTime, 2.0f);
     *         const float angle2 = offset + 2.0f * TWO_PI/3.0f + to_radians(30.0f) * noise(ElapsedTime/2.0f, 40.0f);
     *         const float angle3 = offset + TWO_PI + to_radians(80.0f) * noise(ElapsedTime, 200.0f);
     *         offset += 0.25f * QUARTER_PI * DeltaTime;
     *         apply_scale(Height / 3.0f);
     *         draw_triangle(cos(angle1), sin(angle1), cos(angle2), sin(angle2), cos(angle3), sin(angle3));
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\shapes\2dprimitives\draw_triangle.gif
     */
    void draw_triangle(float x1, float y1, float x2, float y2, float x3, float y3) noexcept;

    /**
     * \brief With set_ellipse_mode(), modifies the location from which ellipses are drawn by changing the way in which
     * parameters given to draw_ellipse() are interpreted.
     */
    enum class EllipseMode
    {
        /**
         * \brief Interprets the first two parameters of draw_ellipse() as the shape's center point
         */
        Center,
        /**
         * \brief Interprets the first two parameters of draw_ellipse() as the upper-left or bottom-left corner of the
         * shape in a left handed doodle::FrameOfReference and right handed doodle::FrameOfReference respectively
         */
        Corner
    };
    /**
     * \brief Modifies the location from which ellipses are drawn by changing the way in which parameters given to
     * draw_ellipse() are interpreted.
     *
     * The default mode is EllipseMode::CENTER, which interprets the first two parameters of draw_ellipse() as the
     * shape's center point, while the third and fourth parameters are its width and height.
     *
     * EllipseMode::CORNER
     * interprets the first two parameters of draw_ellipse() as the upper-left or bottom-left corner of the shape in a
     * left handed doodle::FrameOfReference and right handed doodle::FrameOfReference respectively, while the third and
     * fourth
     * parameters are its width and height.
     *
     * \param mode either CENTER or CORNER
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_outline_color(HexColor{0x483524FF});
     *         set_outline_width(3.0f);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             const float circle_width = Width * 0.3f;
     *             clear_background(HexColor{0xA47B56FF});
     *             set_ellipse_mode(EllipseMode::Center);
     *             set_fill_color(255);
     *             draw_ellipse(0, 0, circle_width);
     *             set_ellipse_mode(EllipseMode::Corner);
     *             set_fill_color(120);
     *             draw_ellipse(0, 0, circle_width);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\attributes\set_ellipse_mode.png
     */
    void set_ellipse_mode(EllipseMode mode) noexcept;
    /**
     * \brief With set_rectangle_mode(), modifies the location from which rectangles are drawn by changing the way in
     * which parameters given to draw_rectangle() are interpreted.
     */
    enum class RectMode
    {
        /**
         * \brief The default mode is RectMode::CORNER, which interprets the first two parameters of draw_rectangle() as
         * the upper-left or bottom-left corner of the shape in a left handed doodle::FrameOfReference and right handed
         * doodle::FrameOfReference respectively
         */
        Corner,
        /**
         * \brief RectMode::CENTER interprets the first two parameters of draw_rectangle() as the shape's center point.
         */
        Center
    };
    /**
     * \brief Modifies the location from which rectangles are drawn by changing the way in which parameters given to
     * draw_rectangle() are interpreted.
     *
     * The default mode is RectMode::CORNER, which interprets the first two parameters of draw_rectangle() as upper-left
     * or bottom-left corner of the shape in a left handed doodle::FrameOfReference and right handed
     * doodle::FrameOfReference respectively, while the third and fourth parameters are its width and height.
     *
     * RectMode::CENTER interprets the first two parameters of draw_rectangle() as the shape's center point, while the
     * third and fourth parameters are its width and height.
     *
     * \param mode either CORNER or CENTER
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_outline_color(HexColor{0xE7C0ABFF});
     *         set_outline_width(3.0f);
     *         set_frame_of_reference(LeftHanded_OriginTopLeft);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             const float shape_width = Width * 0.4f;
     *             clear_background(HexColor{0xAC7476FF});
     *             set_rectangle_mode(RectMode::Center);
     *             set_fill_color(255);
     *             draw_rectangle(shape_width / 2, shape_width / 2, shape_width);
     *             set_rectangle_mode(RectMode::Corner);
     *             set_fill_color(120);
     *             draw_rectangle(shape_width / 2, shape_width / 2, shape_width);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\shapes\attributes\set_rectangle_mode.png
     */
    void set_rectangle_mode(RectMode mode) noexcept;
    /**
     * \brief Used to define the coordinate system you would like to reference.
     *
     * \image html images\shapes\attributes\set_frame_of_reference.gif
     */
    enum FrameOfReference
    {
        /**
         * \brief The Origin (0,0) is always in the center of the screen. Positive x goes to the right and Positive y
         * goes up. This is the default reference frame.
         *
         * \verbatim
           W = Width, H = Height
                      (W/2,H/2)
                +--------o
                |        |
                |  0,0   |
                |        |
                o--------+
           (-W/2,-H/2)
           \endverbatim
         */
        RightHanded_OriginCenter,
        /**
         * \brief The Origin (0,0) is always in the bottom left of the screen. Positive x goes to the right and Positive
         * y goes up.
         *
         * \verbatim
           W = Width, H = Height
                       (W,H)
                +--------o
                |        |
                |        |
                |        |
                o--------+
              (0,0)
           \endverbatim
         */
        RightHanded_OriginBottomLeft,
        /**
         * \brief The Origin (0,0) is always in the top left of the screen. Positive x goes to the right and Positive y
         * goes down.
         *
         * \verbatim
           W = Width, H = Height
              (0,0)
                o--------+
                |        |
                |        |
                |        |
                +--------o
                       (W,H)
           \endverbatim
         */
        LeftHanded_OriginTopLeft
    };
    /**
     * \brief Change the coordinate system you would like to use when describing your primitives.
     *
     * \param frame_of_reference The coordinate system you would like to use.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         constexpr int   gridSize = 50;
     *         constexpr float x1 = 10, y1 = 10;   // left
     *         constexpr float x2 = 210, y2 = 10;  // right
     *         constexpr float x3 = 110, y3 = 140; // top
     *
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xD7A586ff});
     *             // Red
     *             set_fill_color(255, 0, 0);
     *             set_frame_of_reference(RightHanded_OriginCenter);
     *             draw_triangle(x1, y1, x2, y2, x3, y3);
     *
     *             // green
     *             set_fill_color(0, 255, 0);
     *             set_frame_of_reference(RightHanded_OriginBottomLeft);
     *             draw_triangle(x1, y1, x2, y2, x3, y3);
     *
     *             // blue
     *             set_fill_color(0, 0, 255);
     *             set_frame_of_reference(LeftHanded_OriginTopLeft);
     *             draw_triangle(x1, y1, x2, y2, x3, y3);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\attributes\set_frame_of_reference.png
     */
    void set_frame_of_reference(FrameOfReference frame_of_reference) noexcept;
    /**
     * \brief Draws all geometry with smooth (anti-aliased) edges.
     *
     * Note that smooth_drawing() is active by default in; no_smoothing() can be used to disable smoothing of geometry,
     * images, and fonts.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_outline_color(HexColor{0xE7C0ABFF});
     *         set_outline_width(3.0f);
     *         set_frame_of_reference(RightHanded_OriginCenter);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             const float shape_width = Width * 0.4f;
     *             const float shape_height = Height * 0.4f;
     *             clear_background(HexColor{0xAC7476FF});
     *             smooth_drawing();
     *             draw_ellipse(-Width/4.0f, 0, shape_width, shape_height);
     *             no_smoothing();
     *             draw_ellipse(Width/4.0f, 0, shape_width, shape_height);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\attributes\smooth_drawing.png
     */
    void smooth_drawing() noexcept;
    /**
     * \brief Draws all geometry with jagged (aliased) edges.
     *
     * Note that smooth_drawing() is active by default in; no_smoothing() can be used to disable smoothing of geometry,
     * images, and fonts.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_outline_color(HexColor{0xE7C0ABFF});
     *         set_outline_width(5.0f);
     *         set_rectangle_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             const float shape_width  = Width * 0.4f;
     *             const float shape_height = Height * 0.4f;
     *             clear_background(HexColor{0xAC7476FF});
     *             smooth_drawing();
     *             draw_rectangle(-Width / 4.0f, 0, shape_width, shape_height);
     *             no_smoothing();
     *             draw_rectangle(Width / 4.0f, 0, shape_width, shape_height);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\attributes\no_smoothing.png
     */
    void no_smoothing() noexcept;
    /**
     * \brief Sets the width of the outline used for lines and the border around shapes. All widths are set in units of
     * pixels.
     *
     * \param line_width how thick to make lines
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(250, 200);
     *         set_outline_color(HexColor{0x471623FF});
     *
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xBB8F99FF});
     *             const float top = Height / 3.0f, bottom = -top, center = 0;
     *             const float left = -Width / 2.0f + 20, right = Width / 2.0f - 20;
     *
     *             set_outline_width(1.0f);
     *             draw_line(left, top, right, top);
     *             set_outline_width(5.0f);
     *             draw_line(left, center, right, center);
     *             set_outline_width(10.0f);
     *             draw_line(left, bottom, right, bottom);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\attributes\set_outline_width.png
     */
    void set_outline_width(float line_width) noexcept;

    /**
     * \brief The push_settings() function saves the current drawing style settings and transformations, while
     * pop_settings() restores these settings.
     *
     * Note that these functions are always used together. They allow you to change the style and transformation
     * settings and later return to what you had. When a new state is started with push_settings(), it builds on the
     * current style and transform information. The push_settings() and pop_settings() functions can be embedded to
     * provide more control.
     *
     * push_settings() stores information related to the current transformation (apply_scale(), apply_rotate(),
     * apply_translate(), apply_matrix()) state and style settings controlled by the following functions:
     * set_fill_color(), no_fill(), set_outline_color(), no_outline(), set_ellipse_mode(), set_rectangle_mode(),
     * smooth_drawing(), no_smoothing(), set_outline_width(), set_tint_color(), no_tint(), set_texture_mode(),
     * set_font(), set_frame_of_reference()
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         float           thetaOffset       = 0.0f;
     *         constexpr float radiansPerSecond  = QUARTER_PI / 2.0f;
     *         constexpr int   outerCircleSlices = 32;
     *         constexpr int   innerCircleSlices = 12;
     *         constexpr float outerIncrement    = TWO_PI / outerCircleSlices;
     *         constexpr float innerIncrement    = TWO_PI / innerCircleSlices;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(255, 128);
     *             // Loop from 0 to 360 degrees (2*PI radians)
     *             for (int i = 0; i < outerCircleSlices; ++i)
     *             {
     *                 // Push, rotate and draw a line
     *                 // The transformation state is saved at the beginning of each cycle through the for loop and
     *                 // restored at the end. Try commenting out these lines to see the difference!
     *                 push_settings();
     *                 apply_rotate(thetaOffset + i * outerIncrement);
     *                 draw_line(0, 0, 100, 0);
     *
     *                 // draw a "flower" of lines at the end of the ith parent line
     *                 for (int j = 0; j < innerCircleSlices; ++j)
     *                 {
     *                     // Push, translate, rotate and draw a line!
     *                     push_settings();
     *                     apply_translate(100, 0);
     *                     apply_rotate(-thetaOffset - j * innerIncrement);
     *                     draw_line(0, 0, 50, 0);
     *                     // We're done with the inside loop, pop!
     *                     pop_settings();
     *                 }
     *                 // We're done with the outside loop, pop!
     *                 pop_settings();
     *             }
     *             thetaOffset += radiansPerSecond * DeltaTime;
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\attributes\push_settings.gif
     */
    void push_settings() noexcept;
    /**
     * \brief The pop_settings() function restores to the previous style settings and transformations, while
     * push_settings() saves a new set these settings.
     *
     * Note that these functions are always used together. They allow you to change the style and transformation
     * settings and later return to what you had. When a new state is started with push_settings(), it builds on the
     * current style and transform information. The push_settings() and pop_settings() functions can be embedded to
     * provide more control.
     *
     * push_settings() stores information related to the current transformation (apply_scale(), apply_rotate(),
     * apply_translate(), apply_matrix()) state and style settings controlled by the following functions:
     * set_fill_color(), no_fill(), set_outline_color(), no_outline(), set_ellipse_mode(), set_rectangle_mode(),
     * smooth_drawing(), no_smoothing(), set_outline_width(), set_tint_color(), no_tint(), set_texture_mode(),
     * set_font(), set_frame_of_reference()
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xBB8F99FF});
     *             const float center = 0;
     *             const float left = -3.0f * Width / 8.0f, left_middle = -Width / 8.0f;
     *             const float right_middle = -left_middle, right = -left;
     *             const float shape_width = Width / 3.0f;
     *
     *             draw_ellipse(left, center, shape_width); // Left circle
     *
     *             push_settings(); // Start a new drawing state
     *             set_outline_width(10.0f);
     *             set_fill_color(204, 153, 0);
     *             draw_ellipse(left_middle, center, shape_width); // Left-middle circle
     *
     *             push_settings(); // Start another new drawing state
     *             set_outline_color(0, 102, 153);
     *             draw_ellipse(right_middle, center, shape_width); // Right-middle circle
     *             pop_settings();                                  // Restore previous state
     *
     *             pop_settings(); // Restore original state
     *
     *             draw_ellipse(right, center, shape_width); // Right circle
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\shapes\attributes\pop_settings.png
     */
    void pop_settings() noexcept;
    /** @} */

    /**
     *  * \addtogroup Typography
     *  Functions for drawing text using Distance Field Text Rendering.
     *  You can generate a Distance Field Bitmap Font using the [Hiero
     * tool](https://github.com/libgdx/libgdx/wiki/Hiero) [Here is a video](https://youtu.be/d8cfgcJR9Tk) that explains
     * Distance Field Text Rendering and how to generate the font with Hiero.
     *  @{
     */
    /**
     * \brief Draws wide character based text to the screen.
     *
     * Using wide characters allows us to draw characters not just for the English language but for other languages like
     * Korean too.
     *
     * A default font will be used unless a font is set with the set_font() function and a default size will be used
     * unless a font is set with set_font_size(). Change the color of the text with the set_fill_color() function.
     * Change the color of the backdrop with the set_outline_color() function.
     *
     * \param str the text to be displayed
     * \param x x-coordinate of text
     * \param y y-coordinate of text
     *
     * The following example built the distance field bitmap font with the [Hiero
     * tool](https://github.com/libgdx/libgdx/wiki/Hiero). Here is the [Hiero Setting
     * File](images\typography\examplefonts\Gaegu.hiero) configured to build with the [Gaegu
     * Font](https://fonts.google.com/specimen/Gaegu). This generated the relevant [Gaegu.fnt
     * file](images\typography\examplefonts\Gaegu.fnt) and it's partner [Gaegu.png
     * file](images\typography\examplefonts\Gaegu.png).
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         const int fontID = create_distance_field_bitmap_font("Gaegu.fnt");
     *         set_font(fontID);
     *         set_font_size(48);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         set_font_fade_out_interval(0.45f, 0.55f);
     *         set_font_backdrop_fade_out_interval(0.6f, 1.0f);
     *         constexpr float    x = 100;
     *         float              y{};
     *         constexpr float    upDistance  = 80;
     *         const std::wstring helloString = LR"(안녕하세요!)";
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             y = -20;
     *             clear_background(HexColor{0xD7A586ff});
     *             set_outline_color(255);
     *             set_fill_color(0);
     *             draw_text(helloString, x, y += upDistance);
     *             set_outline_color(0, 102, 153);
     *             set_fill_color(255);
     *             draw_text(helloString, x, y += upDistance);
     *             set_outline_color(255, 151);
     *             set_fill_color(0, 102, 153, 151);
     *             draw_text(helloString, x, y += upDistance);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\typography\draw_text_1_wstring.png
     */
    void draw_text(const std::wstring& str, float x, float y) noexcept;
    /**
     * \brief Draws text to the screen.
     *
     * A default font will be used unless a font is set with the set_font() function and a default size will be used
     * unless a font is set with set_font_size(). Change the color of the text with the set_fill_color() function.
     * Change the color of the backdrop with the set_outline_color() function.
     *
     * \param str the text to be displayed
     * \param x x-coordinate of text
     * \param y y-coordinate of text
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         constexpr float   x           = 100;
     *         float             y           = 0;
     *         constexpr float   upDistance  = 80;
     *         const std::string helloString = R"(Hello!)";
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             y = -20;
     *             clear_background(HexColor{0xD7A586ff});
     *             set_outline_color(255);
     *             set_fill_color(0);
     *             draw_text(helloString, x, y += upDistance);
     *             set_outline_color(0, 102, 153);
     *             set_fill_color(255);
     *             draw_text(helloString, x, y += upDistance);
     *             set_outline_color(255, 151);
     *             set_fill_color(0, 102, 153, 151);
     *             draw_text(helloString, x, y += upDistance);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\typography\draw_text_2_string.png
     */
    void draw_text(const std::string& str, float x, float y) noexcept;
    /**
     * \brief Given a file path to a *.fnt file it will create a distance field bitmap font.
     *
     * It will parse that file to get all of the Bitmap information and create doodle::Texture instances of all the PNG
     * files listed. It assumes that the PNG files are in the same folder directory as the provided *.fnt file. It will
     * return a positive value on success and a negative value if it failed to parse the *.fnt file for whatever reason.
     *
     * The default font, provided with doodle has a font ID of \f$0\f$ and is specified by doodle::DEFAULT_FONT_ID.
     *
     * The original bitmap font file definition comes from [AngleCode's
     * BMFont](http://www.angelcode.com/products/bmfont/). However BMFont does not generate distance field bitmap fonts,
     * so the suggested tool to use is the [Hiero tool](https://github.com/libgdx/libgdx/wiki/Hiero). Hiero can create
     * distance field bitmap fonts and save it in the AngelCode file format. [Here is a
     * video](https://youtu.be/d8cfgcJR9Tk) that explains Distance Field Text Rendering and how to generate the font
     * with Hiero.
     *
     * \param fnt_filepath Path to a fnt file in the BMFont text file format.
     * \return ID for the created font. Use this ID to actively select and use this font.
     *
     * The following example built the distance field bitmap font with the [Hiero
     * tool](https://github.com/libgdx/libgdx/wiki/Hiero). Here is the [Hiero Setting
     * File](images\typography\examplefonts\Gaegu.hiero) configured to build with the [Gaegu
     * Font](https://fonts.google.com/specimen/Gaegu). This generated the relevant [Gaegu.fnt
     * file](images\typography\examplefonts\Gaegu.fnt) and it's partner [Gaegu.png
     * file](images\typography\examplefonts\Gaegu.png).
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         const int fontID = create_distance_field_bitmap_font("Gaegu.fnt");
     *         set_font(fontID);
     *         set_font_size(70);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         set_font_fade_out_interval(0.45f, 0.55f);
     *         set_font_backdrop_fade_out_interval(0.6f, 1.0f);
     *         constexpr float    x           = 60;
     *         const float        y           = Height / 2.0f - 50;
     *         const std::wstring helloString = LR"(안녕하세요!)";
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xFEF7F0FF});
     *             set_outline_color(HexColor{0x606783FF});
     *             set_fill_color(HexColor{0x6BCED8FF});
     *             draw_text(helloString, x, y);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\typography\create_distance_field_bitmap_font.png
     */
    int create_distance_field_bitmap_font(const std::filesystem::path& fnt_filepath) noexcept;
    /**
     * \brief Holds the ID value for the provided font that comes with doodle. \sa set_font()
     */
    constexpr int DEFAULT_FONT_ID = 0;
    /**
     * \brief Changes the font type to be used when drawing text.
     *
     * The default font provided with doodle is defined by doodle::DEFAULT_FONT_ID.
     *
     * \param font_id ID of a font that was previsouly created with create_distance_field_bitmap_font().
     *
     * The following example built the distance field bitmap font with the [Hiero
     * tool](https://github.com/libgdx/libgdx/wiki/Hiero). Here is the [Hiero Setting
     * File](images\typography\examplefonts\Gaegu.hiero) configured to build with the [Gaegu
     * Font](https://fonts.google.com/specimen/Gaegu). This generated the relevant [Gaegu.fnt
     * file](images\typography\examplefonts\Gaegu.fnt) and it's partner [Gaegu.png
     * file](images\typography\examplefonts\Gaegu.png).
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         const int GaeguFontID = create_distance_field_bitmap_font("Gaegu.fnt");
     *
     *         set_font_size(54);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *
     *         constexpr float x = 100;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xFEF7F0FF});
     *             float y = Height / 2.0f;
     *
     *             set_font(GaeguFontID);
     *             set_outline_color(HexColor{0x313846ff});
     *             set_fill_color(HexColor{0x6BCED8FF});
     *             set_font_fade_out_interval(0.45f, 0.55f);
     *             set_font_backdrop_fade_out_interval(0.6f, 1.0f);
     *             draw_text(LR"(안녕하세요!)", x, y);
     *
     *             y -= 70;
     *             set_font(DEFAULT_FONT_ID);
     *             set_outline_color(HexColor{0x606783FF});
     *             set_fill_color(HexColor{0x6BCED8FF});
     *             set_font_fade_out_interval(0.48f, 0.55f);
     *             set_font_backdrop_fade_out_interval(0.55f, 0.9f);
     *             draw_text("\tHello!", x, y);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\typography\set_font.png
     */
    void set_font(int font_id) noexcept;
    /**
     * \brief Sets the current font size. This size will be used in all subsequent calls to the draw_text() function.
     * \param font_size the desired font size
     *
     * \code
     *     #include <cmath>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_font_size(12.0f + 68.0f * (std::sin(ElapsedTime) * 0.5f + 0.5f));
     *             draw_text("doodle", -Width / 4.0f, -Height / 8.0f);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\typography\set_font_size.gif
     */
    void set_font_size(float font_size) noexcept;
    /**
     * \brief Defines the distance interval to draw font characters and how to fade them out from opaque to translucent.
     *
     * The inside_distance defines the distance that is considered completely inside a font character. The
     * outside_distance defines the distance that is considered completely outside a font character. The distance value
     * that are in between theses two values will be smoothed out.
     *
     * The distance is measured in a normalized space, so must be between [0,1]. Values outside of this will be clamped.
     * If the given outside_distance is less than the inside_distance it will be replaced to match the inside_distance.
     *
     * ![Illustration of the normalized space with the letter S](images\typography\explain\fadout_intervals.png)
     *
     * In this example the inside_distance is 0.5 and the outside_distance is 0.6. Anything inside 0.5 is considered
     * completely inside the letter and will be colored opaquely. Anything outside 0.6 is considered completely outside
     * and will be colored transparently.
     *
     * \param inside_distance The normalized distance the defines what is completely **inside** a character font.
     * Clamped to [0,1].
     * \param outside_distance The normalized distance the defines what is completely **outside** a
     * character font. Clamped to [0,1].
     *
     * \code
     *     #include <cmath>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         no_outline();
     *         const auto oscillate = [](float t) { return (std::sin(t) * 0.5f + 0.5f); };
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(0);
     *
     *             float inside_distance             = oscillate(ElapsedTime) * 0.7f;
     *             float completely_outside_distance = 1.0f;
     *             set_font_fade_out_interval(inside_distance, completely_outside_distance);
     *             draw_text("doodle", -Width / 4.0f, 3.0f * Height / 16.0f);
     *
     *             inside_distance             = 0.5f;
     *             completely_outside_distance = inside_distance + 0.5f * oscillate(ElapsedTime * 2);
     *             set_font_fade_out_interval(inside_distance, completely_outside_distance);
     *             draw_text("doodle", -Width / 4.0f, -Height / 8.0f);
     *
     *
     *             inside_distance             = oscillate(ElapsedTime);
     *             completely_outside_distance = inside_distance + (1 - inside_distance) * oscillate(ElapsedTime * 2);
     *             set_font_fade_out_interval(inside_distance, completely_outside_distance);
     *             draw_text("doodle", -Width / 4.0f, -3.0f * Height / 8.0f);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\typography\set_font_fade_out_interval.gif
     */
    void set_font_fade_out_interval(float inside_distance, float outside_distance) noexcept;
    /**
     * \brief Defines the distance interval to draw the backdrop of font characters and how to fade them out from opaque
     * to translucent.
     *
     * The inside_distance defines the distance that is considered completely inside a font character. The
     * outside_distance defines the distance that is considered completely outside a font character. The distance value
     * that are in between theses two values will be smoothed out. It is the same logic as set_font_fade_out_interval(),
     * however this will draw the character based off of the outline color and will be behind the fill colored part.
     *
     * The distance is measured in a normalized space, so must be between [0,1]. Values outside of this will be clamped.
     * If the given outside_distance is less than the inside_distance it will be replaced to match the inside_distance.
     *
     * ![Illustration of the normalized space with the letter S](images\typography\explain\fadout_intervals.png)
     *
     * In this example the inside_distance is 0.5 and the outside_distance is 0.6. Anything inside 0.5 is considered
     * completely inside the letter and will be colored opaquely. Anything outside 0.6 is considered completely outside
     * and will be colored transparently.
     *
     * \param inside_distance The normalized distance the defines what is completely **inside** a character font for the
     * backdrop. Clamped to [0,1].
     * \param outside_distance The normalized distance the defines what is completely **outside** a character font for
     * the backdrop. Clamped to [0,1].
     *
     * \code
     * #include <cmath>
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 320);
     *     const auto oscillate = [](float t) { return (std::sin(t) * 0.5f + 0.5f); };
     *     set_font_fade_out_interval(0.5f, 0.6f);
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         clear_background(220);
     *         // cycle between 0.4-0.7 for inside distance
     *         const float inside_distance = 0.4f + 0.3f * oscillate(ElapsedTime);
     *         // oscillate within the remaining distance
     *         const float completely_outside_distance = inside_distance +
     *                                        (1 - inside_distance) * oscillate(ElapsedTime * 2);
     *         set_font_backdrop_fade_out_interval(inside_distance, completely_outside_distance);
     *         draw_text("doodle", -Width / 4.0f, -Height / 8.0f);
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\typography\set_font_backdrop_fade_out_interval.gif
     */
    void set_font_backdrop_fade_out_interval(float inside_distance, float outside_distance) noexcept;
    /**
     * \brief Repositions the backdrop of the font characters. Useful for creating a custom drop shadow effect.
     *
     * The distance to offset the backdrop is measured in texels relative to the image defining the Bitmap Font. The
     * texel coordinate system is left handed where the origin is the very top left and positive y goes down.
     *
     * \param texel_x How far to horizontally offset the backdrop character in texels
     * \param texel_y How far to vertically offset the backdrop character in texels
     *
     * \code
     * #include <cmath>
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 320);
     *     const auto oscillate = [](float t) { return (std::sin(t) * 0.5f + 0.5f); };
     *
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         clear_background(220);
     *         const float texels_length = 1.0f + 2.0f * oscillate(ElapsedTime * 2.0f);
     *         set_font_backdrop_offset(std::sin(ElapsedTime * 4) * texels_length, std::cos(ElapsedTime * 4) *
     *                                                                                          texels_length);
     *         draw_text("doodle", -Width / 4.0f, -Height / 8.0f);
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\typography\set_font_backdrop_offset.gif
     */
    void set_font_backdrop_offset(float texel_x, float texel_y) noexcept;
    /** @} */


    /**
     *  * \addtogroup Image
     *  Functions for drawing images and taking a screenshot.
     *  @{
     */
    /**
     * \brief Captures a screenshot of the whole screen.
     *
     * \return The screenshot is saved into an Image object, which can be used to save it to a file if desired.
     *
     * \code
     *     #include <cstdlib>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *        create_window(480, 360);
     *        clear_background(HexColor{0x1E4155FF});
     *        set_outline_width(2.0f);
     *
     *        set_fill_color(HexColor{0x149EBCFF});
     *        draw_ellipse(-Width / 4.0f, -Height / 4.0f, 100, 60);
     *
     *        set_fill_color(HexColor{0xFDEED8Ff});
     *        set_rectangle_mode(RectMode::Center);
     *        draw_rectangle(Width / 4.0f, -Height / 4.0f, 100, 60);
     *
     *        set_fill_color(HexColor{0xE74F32FF});
     *        draw_triangle(50, 50, 200, 70, 150, 100);
     *
     *        set_fill_color(HexColor{0xC82733FF});
     *        draw_quad(-50, 25, -230, 70, -150, 160, -60, 140);
     *
     *        const Image results = capture_screenshot_to_image();
     *        results.SaveToPNG(R"(capture_screenshot_to_image.png)");
     *        std::system(R"(start capture_screenshot_to_image.png)");
     *        return 0;
     *     }
     * \endcode
     * \image html images\image\creatingimages\capture_screenshot_to_image.png
     */
    Image capture_screenshot_to_image();

    /**
     * \brief Captures a screenshot of a subsection of the screen.
     *
     * Useful if you only want to save a portion of the screen.
     *
     * The coordinates you give are assumed to be in the RightHanded_OriginBottomLeft frame of reference.
     *
     * \param left_x x-coordinate for the left part of the box containing the screenshot
     * \param bottom_y y-coordinate for the bottom part of the box containing the screenshot
     * \param pixels_width width of the box containing the screenshot
     * \param pixels_height height of the box containing the screenshot
     * \return The screenshot is saved into an Image object, which can be used to save it to a file if desired.
     *
     * \code
     * #include <cstdlib>
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 360);
     *     clear_background(HexColor{0x1E4155FF});
     *     set_outline_width(2.0f);
     *
     *     set_fill_color(HexColor{0x149EBCFF});
     *     draw_ellipse(-Width / 4.0f, -Height / 4.0f, 100, 60);
     *
     *     set_fill_color(HexColor{0xFDEED8Ff});
     *     set_rectangle_mode(RectMode::Center);
     *     draw_rectangle(Width / 4.0f, -Height / 4.0f, 100, 60);
     *
     *     set_fill_color(HexColor{0xE74F32FF});
     *     draw_triangle(50, 50, 200, 70, 150, 100);
     *
     *     set_fill_color(HexColor{0xC82733FF});
     *     draw_quad(-50, 25, -230, 70, -150, 160, -60, 140);
     *
     *     // take a screenshot of only the right half of the screen
     *     const int   left           = Width / 2;
     *     const int   bottom         = 0;
     *     const int   capture_width  = Width / 2;
     *     const int   capture_height = Height;
     *     const Image results        = capture_screenshot_to_image(left, bottom, capture_width, capture_height);
     *     results.SaveToPNG(R"(capture_screenshot_to_image_2_subsection.png)");
     *     std::system(R"(start capture_screenshot_to_image_2_subsection.png)");
     *     return 0;
     * }
     * \endcode
     * \image html images\image\creatingimages\capture_screenshot_to_image_2_subsection.png
     */
    Image capture_screenshot_to_image(int left_x, int bottom_y, int pixels_width, int pixels_height) noexcept;

    /**
     * \brief Draw an entire texture to the screen.
     *
     * The width and height of the image will be based off of the texture width and texture height.
     *
     * \param texture texture object to draw
     * \param x x-coordinate of the rectangle to draw the image.
     * \param y y-coordinate of the rectangle to draw the image.
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x3546530A});
     *             draw_texture(orangeHero, 0, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\draw_texture_1.png
     */
    void draw_texture(const Texture& texture, float x, float y) noexcept;
    /**
     * \brief Draw an entire texture to the screen and resize it to a custom size.
     * \param texture texture object to draw
     * \param x x-coordinate of the rectangle to draw the image.
     * \param y y-coordinate of the rectangle to draw the image.
     * \param width how wide to draw the image
     * \param height how tall to draw the image
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x3546530A});
     *             draw_texture(orangeHero, 0, 0, 64, 128);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\draw_texture_2.png
     */
    void draw_texture(const Texture& texture, float x, float y, float width, float height) noexcept;
    /**
     * \brief Draw a subsection of the texture to the screen.
     *
     * The subsection is defined is defined by the box
     *
     * \verbatim
      Texture
        (0,0)
          +---------------------------------------------------------------------+
          |                                                                     |
          |(texel_x,texel_y)                                                    |
          |        o--------------------------------+                           |
          |        |                                |                           |
          |        |                                |                           |
          |        |                                |                           |
          |        |                                |                           |
          |        |                                |                           |
          |        +--------------------------------o                           |
          |                           (texel_x+width,texel_y+height)            |
          |                                                                     |
          |                                                                     |
          |                                                                     |
          +---------------------------------------------------------------------+
                                                                  (texture_width,texture_height)
       \endverbatim
     *
     * \param texture
     * \param texture texture object to draw
     * \param x x-coordinate of the rectangle to draw the image.
     * \param y y-coordinate of the rectangle to draw the image.
     * \param width how wide to draw the image
     * \param height how tall to draw the image
     * \param texel_x Horizontally, where in texture to start reading colors from the texture. 0 is the far left and
     * texture width is the far right. \param texel_y Vertically, where in texture to start reading colors from the
     * texture. 0 is the far top and texture height is the far bottom.
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x3546530A});
     *             draw_texture(orangeHero, 0, 0, 16, 16, 8, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\draw_texture_3.png
     */
    void draw_texture(const Texture& texture, float x, float y, float width, float height, int texel_x,
                      int texel_y) noexcept;
    /**
     * \brief Draw a subsection of the texture to the screen.
     *
     * The subsection is defined is defined by the box
     *
     * \verbatim
      Texture
    (0,0)
      +---------------------------------------------------------------------+
      |                                                                     |
      |(texel_x,texel_y)                                                    |
      |        o--------------------------------+                           |
      |        |                                |                           |
      |        |                                |                           |
      |        |                                |                           |
      |        |                                |                           |
      |        |                                |                           |
      |        +--------------------------------o                           |
      |                     (texel_x+texel_width,texel_y+texel_height)      |
      |                                                                     |
      |                                                                     |
      |                                                                     |
      +---------------------------------------------------------------------+
                                                              (texture_width,texture_height)
       \endverbatim
     *
     * \param texture
     * \param texture texture object to draw
     * \param x x-coordinate of the rectangle to draw the image.
     * \param y y-coordinate of the rectangle to draw the image.
     * \param width how wide to draw the image
     * \param height how tall to draw the image
     * \param texel_x Horizontally, where in texture to start reading colors from the texture. 0 is the far left and
     * texture width is the far right.
     * \param texel_y Vertically, where in texture to start reading colors from the
     * texture. 0 is the far top and texture height is the far bottom.
     * \param texel_width width of texture subsection to read the colors from
     * \param texel_height height of texture subcetion to read the colors from
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x3546530A});
     *             draw_texture(orangeHero, 0, 0, 128, 128, 8, 0, 16, 16);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\draw_texture_4.png
     */
    void draw_texture(const Texture& texture, float x, float y, float width, float height, int texel_x, int texel_y,
                      int texel_width, int texel_height) noexcept;
    /**
     * \brief Sets the fill value for displaying textures to the specified HexColor.
     *
     * Textures can be tinted to specified colors or made transparent by including an alpha value.
     *
     * \param color HexColor to apply to textures
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_tint_color(HexColor{0xFF4E0080}); //~50% transparent and red
     *             draw_texture(orangeHero, 0, 0, 64, 128);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\set_tint_color_1.png
     */
    void set_tint_color(HexColor color) noexcept;
    /**
     * \brief Sets the fill value for displaying textures to the specified Color4ub.
     *
     * Textures can be tinted to specified colors or made transparent by including an alpha value.
     *
     * \param color Color4ub to apply to textures
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_tint_color(Color4ub{255, 78, 0}); // red
     *             draw_texture(orangeHero, 0, 0, 64, 128);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\set_tint_color_2.png
     */
    void set_tint_color(Color4ub color) noexcept;
    /**
     * \brief Sets the fill value for displaying textures to the specified grey color.
     *
     * Textures can be tinted to specified colors or made transparent by including an alpha value.
     *
     * \param grey specifies a value between white and black
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_tint_color(255,128); // ~50% transparent
     *             draw_texture(orangeHero, 0, 0, 64, 128);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\set_tint_color_3.png
     */
    void set_tint_color(Color4ub::unsigned_byte grey, Color4ub::unsigned_byte alpha = 255) noexcept;
    /**
     * \brief Sets the fill value for displaying textures to the specified RGBA color.
     *
     * Textures can be tinted to specified colors or made transparent by including an alpha value.
     *
     * \param red value between 0-255
     * \param green value between 0-255
     * \param blue value between 0-255
     * \param alpha optional opacity value of the background between 0-255. The default value is 255.
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_tint_color(255,240,0); // yellow
     *             draw_texture(orangeHero, 0, 0, 64, 128);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\set_tint_color_4.png
     */
    void set_tint_color(Color4ub::unsigned_byte red, Color4ub::unsigned_byte green, Color4ub::unsigned_byte blue,
                        Color4ub::unsigned_byte alpha = 255) noexcept;
    /**
     * \brief Removes the current fill value for displaying images and reverts to displaying textures with their
     *        original colors.
     *
     * The following example uses this orange hero image file. ![](orange_hero.png)
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *         set_texture_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_tint_color(0, 153, 204);
     *             draw_texture(orangeHero, -Width / 4.0f, 0, 64, 128);
     *             no_tint();
     *             draw_texture(orangeHero, Width / 4.0f, 0, 64, 128);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\no_tint.png
     */
    void no_tint() noexcept;
    /**
     * \brief Modifies the location from which textures are drawn by changing the way in which parameters given to
     * draw_texture() are interpreted.
     *
     * The default mode is RectMode::CORNER, which interprets the first two parameters of draw_texture() as upper-left
     * or bottom-left corner of the shape in a left handed doodle::FrameOfReference and right handed
     * doodle::FrameOfReference respectively, while the third and fourth parameters are its width and height.
     *
     * RectMode::CENTER interprets the first two parameters of draw_texture() as the shape's center point, while the
     * third and fourth parameters are its width and height.
     *
     * \param mode either CORNER or CENTER
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(240, 180);
     *         Texture        orangeHero;
     *         constexpr auto texture_path = "orange_hero.png";
     *         if (const bool loaded = orangeHero.LoadFromPNG(texture_path); !loaded)
     *         {
     *             std::cerr << "Failed to load " << texture_path << "\n";
     *         }
     *
     *
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_tint_color(0, 153, 204);
     *             set_texture_mode(RectMode::Corner);
     *             draw_texture(orangeHero, 0, 0);
     *             no_tint();
     *             set_texture_mode(RectMode::Center);
     *             draw_texture(orangeHero,0,0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\displayingimages\set_texture_mode.png
     */
    void set_texture_mode(RectMode mode) noexcept;
    /** @} */

    /**
     *  * \addtogroup Transform
     *  Functions for transforming shapes
     *  @{
     */
    /**
     * \brief Uniformly increases or decreases the size of a shape by expanding and contracting vertices.
     *
     * Objects always scale from their relative origin to the coordinate system. Scale values are specified as decimal
     * percentages. For example, the function call apply_scale(2.0) increases the dimension of a shape by 200%.
     *
     * Transformations apply to everything that happens after and subsequent calls to the function multiply the effect.
     * For example, calling apply_scale(2.0) and then apply_scale(1.5) is the same as apply_scale(3.0). The
     * transformation is reset when update_window() is called.
     *
     * \param scale percent to scale the object
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         while (!is_window_closed())
     *         {
     *             update_window(); // resets transformations
     *             clear_background(97, 127, 235);
     *
     *             set_fill_color(245, 170, 101);
     *             draw_rectangle(10, 10, 100, 75); // draw at normal size
     *
     *             apply_scale(3.0f);
     *             set_fill_color(228, 187, 142, 192);
     *             draw_rectangle(10, 10, 100, 75); // draw 3 times bigger
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\transform\apply_scale_1.png
     */
    void apply_scale(float scale) noexcept;
    /**
     * \brief  Increases or decreases the size of a shape by expanding and contracting vertices.
     *
     * Objects always scale from their relative origin to the coordinate system. Scale values are specified as decimal
     * percentages. For example, the function call apply_scale(2.0, 0.5) increases the dimension of a shape horizontally
     * by 200% and vertically bu 50%.
     *
     * Transformations apply to everything that happens after and subsequent calls to the function multiply the effect.
     * For example, calling apply_scale(2.0, 1.0) and then apply_scale(1.5, 2.0) is the same as apply_scale(3.0, 2.0).
     * The transformation is reset when update_window() is called.
     *
     * \param scale_x percentage to scale the object in the x-axis
     * \param scale_y percentage to scale the object in the y-axis
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         while (!is_window_closed())
     *         {
     *             update_window(); // resets transformations
     *             clear_background(97, 127, 235);
     *
     *             set_fill_color(245, 170, 101);
     *             draw_rectangle(10, 10, 100, 75); // draw at normal size
     *
     *             // 4x bigger in the x and 3x bigger in the y
     *             apply_scale(4.0f, 3.0f);
     *             set_fill_color(228, 187, 142, 192);
     *             draw_rectangle(10, 10, 100, 75);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\transform\apply_scale_2.png
     */
    void apply_scale(float scale_x, float scale_y) noexcept;
    /**
     * \brief Rotates a shape the amount specified by the angle in radians.
     *
     * Objects are always rotated around their relative position to the origin. If the doodle::FrameOfReference is
     * right-handed then positive angles rotate counter-clockwise and if it is left-handed then positive angles rotate
     * clockwise. Transformations apply to everything that happens after and subsequent calls to the function
     * accumulates the effect. For example, calling apply_rotate(HALF_PI) and then apply_rotate(HALF_PI) is the same as
     * apply_rotate(PI). All transformations are reset when update_window() is called.
     *
     * Technically, apply_rotate() multiplies the current transformation matrix by a rotation matrix. This function can
     * be further controlled by the push_settings() and pop_settings().
     *
     * \param angle_in_radians the angle of rotation
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         while (!is_window_closed())
     *         {
     *             update_window(); // resets transformations
     *             clear_background(97, 127, 235);
     *
     *             apply_rotate(QUARTER_PI);
     *             set_fill_color(164, 183, 177);
     *             draw_ellipse(0, 0, 100, 40);
     *
     *             set_fill_color(228, 63, 86);
     *             apply_rotate(HALF_PI);
     *             draw_rectangle(10, 10, 100, 75);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\transform\apply_rotate.png
     */
    void apply_rotate(float angle_in_radians) noexcept;
    /**
     * \brief Specifies an amount to displace objects within the display window.
     *
     * The x parameter specifies left/right translation, the y parameter specifies up/down translation.
     *
     * Transformations are cumulative and apply to everything that happens after and subsequent calls to the function
     * accumulates the effect. For example, calling apply_translate(50, 0) and then apply_translate(20, 0) is the same
     * as apply_translate(70, 0). All transformations are reset when update_window() is called. This function can be
     * further controlled by the push_settings() and pop_settings().
     *
     * \param translate_x left/right translation
     * \param translate_y up/down translation
     *
     * \code
     *     #include <cmath>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         no_outline();
     *         set_fill_color(245, 170, 101);
     *         constexpr float shapeWidth = 50;
     *         while (!is_window_closed())
     *         {
     *             update_window(); // resets transformations
     *             clear_background(97, 127, 235, 128);
     *             const float radius = std::sqrt(Width * Width / 9.0f + Height * Height / 9.0f) - shapeWidth;
     *             const float x      = std::cos(ElapsedTime) * radius;
     *             const float y      = std::sin(ElapsedTime) * radius;
     *             apply_translate(x, y);
     *             draw_ellipse(0, 0, shapeWidth);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\transform\apply_translate.gif
     */
    void apply_translate(float translate_x, float translate_y) noexcept;
    /**
     * \brief Multiplies the current matrix by the one specified through the parameters.
     *
     * This is a powerful operation that can perform the equivalent of translate, scale, shear and rotate all at once.
     * You can learn more about transformation matrices on
     * [Wikipedia](https://en.wikipedia.org/wiki/Transformation_matrix).
     *
     * The naming of the arguments here follows the naming of the [WHATWG
     * specification](https://html.spec.whatwg.org/multipage/canvas.html#dom-context-2d-transform) and corresponds to a
     * transformation matrix of the form:
     *
     * \f$ \begin{bmatrix} a & c & e \\ b & d & f \\ 0 & 0 & 1 \end{bmatrix} \f$
     *
     * \param a 1st Column 1 Row
     * \param b 1st Column 2nd Row
     * \param c 2nd Column 1st  Row
     * \param d 2nd Column 2nd Row
     * \param e 3rd Column 1st Row
     * \param f 3rd Column 2nd Row
     *
     * \code
     *     #include <cmath>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_outline_color(228, 63, 86);
     *         set_outline_width(3.0f);
     *         set_fill_color(245, 170, 101);
     *         set_rectangle_mode(RectMode::Center);
     *
     *
     *         while (!is_window_closed())
     *         {
     *             update_window(); // resets transformations
     *             clear_background(97, 127, 235, 128);
     *             const float shapeWidth  = Height / 3.0f;
     *             const float angle       = std::sin(ElapsedTime) * QUARTER_PI;
     *             const float shearFactor = 1.0f / std::tan(HALF_PI - angle);
     *             apply_matrix(1, 0, shearFactor, 1, 0, 0);
     *             draw_rectangle(0, 0, shapeWidth);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\transform\apply_matrix.gif
     */
    void apply_matrix(float a, float b, float c, float d, float e, float f) noexcept;
    /** @} */

}
