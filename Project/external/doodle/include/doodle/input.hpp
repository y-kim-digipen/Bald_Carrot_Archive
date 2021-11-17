/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once

#include <doodle/eventhook.hpp>

#include <functional>
#include <string>

namespace doodle
{
    enum class MouseButtons
    {
        None,
        Left,
        Middle,
        Right,
        Count
    };

    enum class KeyboardButtons
    {
        None,
        Escape,
        Space,
        Left,
        Up,
        Right,
        Down,
        _0,
        _1,
        _2,
        _3,
        _4,
        _5,
        _6,
        _7,
        _8,
        _9,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        NumPad_0,
        NumPad_1,
        NumPad_2,
        NumPad_3,
        NumPad_4,
        NumPad_5,
        NumPad_6,
        NumPad_7,
        NumPad_8,
        NumPad_9,
        Count
    };


    /**
     * \addtogroup Utility
     *  Helper functions to convert the input enums to strings.
     *  @{
     */
    /**
     * \brief Convert MouseButtons enum to std::string
     * \param button mouse button
     * \return The name of the button as a std::string
     */
    const std::string& to_string(MouseButtons button) noexcept;
    /**
     * \brief Convert KeboardButtons enum to std::string
     * \param button keyboard button
     * \return The name of the button as a std::string
     */
    const std::string& to_string(KeyboardButtons button) noexcept;
    /**
     * \brief Convert MouseButtons enum to std::wstring
     * \param button mouse button
     * \return The name of the button as a std::wstring
     */
    const std::wstring& to_wstring(MouseButtons button) noexcept;
    /**
     * \brief Convert KeboardButtons enum to std::wstring
     * \param button keyboard button
     * \return The name of the button as a std::wstring
     */
    const std::wstring& to_wstring(KeyboardButtons button) noexcept;
    /** @} */

    /**
     *  * \addtogroup Events
     *  global variables related to input Events
     *  @{
     */
    /**
     * \brief The boolean system variable MouseIsPressed is true if the mouse is pressed and false if not.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_rectangle_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(237, 34, 93);
     *             set_fill_color(0);
     *             set_frame_of_reference(RightHanded_OriginCenter);
     *             if (MouseIsPressed)
     *             {
     *                 draw_ellipse(0, 0, Width / 2.0f, Height / 2.0f);
     *             }
     *             else
     *             {
     *                 draw_rectangle(0, 0, Width / 2.0f, Height / 2.0f);
     *             }
     *             set_fill_color(255);
     *             set_frame_of_reference(RightHanded_OriginBottomLeft);
     *             using namespace std::string_literals;
     *             draw_text("Pressed: "s + ((MouseIsPressed) ? "true"s : "false"s), 5, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\events\mouse\MouseIsPressed.gif
     */
    extern bool MouseIsPressed;
    /**
     * \brief The boolean system variable KeyIsPressed is true if any key is pressed and false if no keys are pressed.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_rectangle_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             set_fill_color(0);
     *             set_frame_of_reference(RightHanded_OriginCenter);
     *             if (KeyIsPressed)
     *             {
     *                 set_fill_color(0);
     *             }
     *             else
     *             {
     *                 set_fill_color(255);
     *             }
     *             draw_rectangle(0, 0, Width / 2.0f, Height / 2.0f);
     *             set_fill_color(255);
     *             set_frame_of_reference(RightHanded_OriginBottomLeft);
     *             using namespace std::string_literals;
     *             draw_text("Pressed: "s + ((KeyIsPressed) ? "true"s : "false"s), 5, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\events\keyboard\KeyIsPressed.gif
     */
    extern bool KeyIsPressed;
    /**
     * \brief The system variable key always contains the value of the most recent key on the keyboard that was typed.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_fill_color(245, 123, 158);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             draw_text(to_string(Key), -60.0f, -30.0f);
     *             if (not KeyIsPressed and Key == KeyboardButtons::Escape)
     *                 close_window();
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\events\keyboard\Key.gif
     */
    extern KeyboardButtons Key;
    /**
     * \brief doodle automatically tracks if the mouse button is pressed and which button is pressed. The value of
     * the system variable MouseButton is either LEFT, RIGHT, or CENTER depending on which button was pressed last.
     *
     * \code
     *     #include <cmath>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_fill_color(0);
     *         set_rectangle_mode(RectMode::Center);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(237, 34, 93);
     *             switch (MouseButton)
     *             {
     *                 case MouseButtons::Left: draw_ellipse(0, 0, Width / 2.0f, Height / 2.0f); break;
     *                 case MouseButtons::Middle:
     *                 {
     *                     const float length = 0.5f * std::sqrt(static_cast<float>(Width * Width) / 4.0f +
     *                                                           static_cast<float>(Height * Height) / 4.0f);
     *                     draw_triangle(0, length, -0.866f * length, -0.5f * length, 0.866f * length, -0.5f * length);
     *                 }
     *                 break;
     *                 case MouseButtons::Right: draw_rectangle(0, 0, Width / 2.0f, Height / 2.0f); break;
     *                 default: break;
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * \image html images\events\mouse\MouseButton.gif
     */
    extern MouseButtons MouseButton;
    /** @} */
    /**
     * \addtogroup Events
     *  You can register callback functions so you can immediately respond to input events. Also provides helper
     * functions to get the mouse position.
     *  @{
     */
    /**
     * \brief Get the mouse's X position relative to the currently set doodle::FrameOfReference
     * \return the current horizontal position of the mouse, relative to the currently set doodle::FrameOfReference
     *
     * \code
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 360);
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         clear_background(244, 248, 252);
     *         const float mouseX = static_cast<float>(get_mouse_x());
     *         draw_line(mouseX, Height / 2.0f, mouseX, -Height / 2.0f);
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\events\mouse\get_mouse_x.gif
     */
    int get_mouse_x() noexcept;

    /**
     * \brief Get the mouse's Y position relative to the currently set doodle::FrameOfReference
     * \return the current vertical position of the mouse, relative to the currently set doodle::FrameOfReference
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(244, 248, 252);
     *             const float mouseY = static_cast<float>(get_mouse_y());
     *             draw_line(-Width / 2.0f, mouseY, Width / 2.0f, mouseY);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\events\mouse\get_mouse_y.gif
     */
    int get_mouse_y() noexcept;
    /**
     * \brief Get the previous mouse's X position relative to the currently set doodle::FrameOfReference
     *
     * \return the previous horizontal position of the mouse, relative to the currently set doodle::FrameOfReference
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <thread>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(244, 248, 252);
     *             const auto mouseX     = static_cast<float>(get_mouse_x());
     *             const auto mouseY     = static_cast<float>(get_mouse_y());
     *             const auto prevMouseX = static_cast<float>(get_previous_mouse_x());
     *             const auto prevMouseY = static_cast<float>(get_previous_mouse_y());
     *             draw_line(mouseX, mouseY, prevMouseX, prevMouseY);
     *
     *             // slow down framte rate to make it more visible
     *             using namespace std::chrono_literals;
     *             std::this_thread::sleep_for(100ms);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\events\mouse\get_previous_mouse_x.gif
     */
    int get_previous_mouse_x() noexcept;
    /**
     * \brief Get the previous mouse's Y position relative to the currently set doodle::FrameOfReference
     * \return Get the previous mouse's Y position relative to the currently set doodle::FrameOfReference
     *
     * \code
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 360);
     *     set_fill_color(0);
     *     set_rectangle_mode(RectMode::Center);
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         clear_background(237, 34, 93);
     *         draw_line(-Width / 2.0f + 20, get_mouse_y() * 1.0f, Width / 2.0f - 20.0f, get_previous_mouse_y() * 1.0f);
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\events\mouse\get_previous_mouse_y.gif
     */
    int get_previous_mouse_y() noexcept;
    /**
     * \brief The provided callback function is called once every time a key is pressed.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in a doodle::KeyboardButtons. Something like
     * \code void keyPressed(doodle::KeyboardButtons button); \endcode
     *
     * \param callback what to call when a key is pressed
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     void keyPressed(KeyboardButtons button);
     *     int  main(void)
     *     {
     *         create_window(480, 360);
     *         clear_background(220);
     *         set_frame_of_reference(RightHanded_OriginBottomLeft);
     *         set_callback_key_pressed(&keyPressed);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *         }
     *         return 0;
     *     }
     *     void keyPressed(KeyboardButtons button)
     *     {
     *         if (button < KeyboardButtons::A || button > KeyboardButtons::Z)
     *         {
     *             clear_background(220); // if it's not a letter clear the screen
     *             return;
     *         }
     *         const auto r = static_cast<Color4ub::unsigned_byte>(random(0, 256));
     *         const auto g = static_cast<Color4ub::unsigned_byte>(random(0, 256));
     *         const auto b = static_cast<Color4ub::unsigned_byte>(random(0, 256));
     *         set_fill_color(r, g, b);
     *         const float rectWidth = Width / 4.0f;
     *         const float key       = (static_cast<float>(button) - static_cast<float>(KeyboardButtons::A));
     *         const float x         = key / (25.0f) * (Width - rectWidth);
     *         draw_rectangle(x, 0, rectWidth, Height * 1.0f);
     *     }
     * \endcode
     * \image html images\events\keyboard\set_callback_key_pressed.gif
     */
    void set_callback_key_pressed(std::function<void(KeyboardButtons)>&& callback) noexcept;
    /**
     * \brief The provided callback function is called once every time a key is released.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in a doodle::KeyboardButtons. Something like
     * \code void keyReleased(doodle::KeyboardButtons button); \endcode
     *
     * \param callback what to call when a key is released
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     class Logic
     *     {
     *         Color4ub::unsigned_byte grey{};
     *
     *     public:
     *         void Setup() noexcept
     *         {
     *             create_window(480, 360);
     *             set_rectangle_mode(RectMode::Center);
     *             grey = 0;
     *             set_callback_key_released([this](KeyboardButtons b) { OnKeyReleased(b); });
     *         }
     *         void Run() const noexcept
     *         {
     *             while (!is_window_closed())
     *             {
     *                 update_window();
     *                 Draw();
     *             }
     *         }
     *         void Draw() const noexcept
     *         {
     *             clear_background(220);
     *             set_fill_color(grey);
     *             draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
     *         }
     *         void OnKeyReleased(KeyboardButtons button) noexcept
     *         {
     *             if (grey == 0)
     *                 grey = 255;
     *             else
     *                 grey = 0;
     *             if (button == KeyboardButtons::Escape)
     *                 close_window();
     *         }
     *     };
     *     int main(void)
     *     {
     *         Logic logic{};
     *         logic.Setup();
     *         logic.Run();
     *         return 0;
     *     }
     * \endcode
     * \image html images\events\keyboard\set_callback_key_released.gif
     */
    void set_callback_key_released(std::function<void(KeyboardButtons)>&& callback) noexcept;
    /**
     * \brief The provided callback function is called every time the mouse moves.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in a two integers. Something like
     * \code void mouseMoved(int mouse_x, int mouse_y); \endcode
     *
     * \param callback what to call when the mouse moves
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     class Logic
     *     {
     *         float                   angle{0.0f};
     *         Color4ub::unsigned_byte grey{0};
     *         float                   x{0.0f};
     *         float                   y{0.0f};
     *
     *     public:
     *         void Setup() noexcept
     *         {
     *             create_window(480, 360);
     *             set_rectangle_mode(RectMode::Center);
     *             set_callback_mouse_moved([this](int x, int y) { OnMouseMoved(x, y); });
     *         }
     *         void Run() const noexcept
     *         {
     *             while (!is_window_closed())
     *             {
     *                 update_window();
     *                 Draw();
     *             }
     *         }
     *         void Draw() const noexcept
     *         {
     *             clear_background(220);
     *             set_fill_color(grey);
     *             draw_rectangle(x, y, Width * 0.4f, Height * 0.4f);
     *         }
     *         void OnMouseMoved(int mouse_x, int mouse_y) noexcept
     *         {
     *             angle += to_radians(3.0f);
     *             grey = static_cast<Color4ub::unsigned_byte>(255 * (std::sin(angle) * 0.5f + 0.5f));
     *             x    = static_cast<float>(mouse_x);
     *             y    = static_cast<float>(mouse_y);
     *         }
     *     };
     *     int main(void)
     *     {
     *         Logic logic{};
     *         logic.Setup();
     *         logic.Run();
     *         return 0;
     *     }
     * \endcode
     * \image html images\events\keyboard\set_callback_mouse_moved.gif
     */
    void set_callback_mouse_moved(std::function<void(int, int)>&& callback) noexcept;
    /**
     * \brief The provided callback is called whenever a mouse button is pressed.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in a doodle::MouseButtons. Something like
     * \code void mousePressed(doodle::MouseButtons button); \endcode
     *
     * \param callback what to call when the mouse is pressed
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     class Logic
     *     {
     *         float x{0.0f};
     *         float y{0.0f};
     *         bool  shouldFollowMouse = false;
     *
     *     public:
     *         void Setup() noexcept
     *         {
     *             create_window(480, 360);
     *             set_callback_mouse_pressed([this](MouseButtons b) { OnMousePressed(b); });
     *             set_callback_mouse_released([this](MouseButtons b) { OnMouseReleased(b); });
     *         }
     *         void Run() noexcept
     *         {
     *             while (!is_window_closed())
     *             {
     *                 update_window();
     *                 if (shouldFollowMouse)
     *                 {
     *                     const float easing = 3.0f * DeltaTime;
     *                     x += easing * (static_cast<float>(get_mouse_x()) - x);
     *                     y += easing * (static_cast<float>(get_mouse_y()) - y);
     *                 }
     *                 Draw();
     *             }
     *         }
     *         void Draw() const noexcept
     *         {
     *             clear_background(237, 34, 93);
     *             draw_ellipse(x, y, Width * 0.1f);
     *         }
     *         void OnMousePressed(MouseButtons button) noexcept
     *         {
     *             if (button == MouseButtons::Left)
     *                 shouldFollowMouse = true;
     *         }
     *         void OnMouseReleased(MouseButtons button) noexcept
     *         {
     *             if (button == MouseButtons::Left)
     *                 shouldFollowMouse = false;
     *         }
     *     };
     *     int main(void)
     *     {
     *         Logic logic{};
     *         logic.Setup();
     *         logic.Run();
     *         return 0;
     *     }
     * \endcode
     * \image html images\events\keyboard\set_callback_mouse_pressed.gif
     */
    void set_callback_mouse_pressed(std::function<void(MouseButtons)>&& callback) noexcept;
    /**
     * \brief The provided callback is called whenever a mouse button is released.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in a doodle::MouseButtons. Something like
     * \code void mouseReleased(doodle::MouseButtons button); \endcode
     *
     * \param callback what to call when the mouse is released
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     class Logic
     *     {
     *         float x{0.0f};
     *         float y{0.0f};
     *         bool  shouldFollowMouse = false;
     *
     *     public:
     *         void Setup() noexcept
     *         {
     *             create_window(480, 360);
     *             set_callback_mouse_pressed([this](MouseButtons b) { OnMousePressed(b); });
     *             set_callback_mouse_released([this](MouseButtons b) { OnMouseReleased(b); });
     *         }
     *         void Run() noexcept
     *         {
     *             while (!is_window_closed())
     *             {
     *                 update_window();
     *                 if (shouldFollowMouse)
     *                 {
     *                     const float easing = 3.0f * DeltaTime;
     *                     x += easing * (static_cast<float>(get_mouse_x()) - x);
     *                     y += easing * (static_cast<float>(get_mouse_y()) - y);
     *                 }
     *                 Draw();
     *             }
     *         }
     *         void Draw() const noexcept
     *         {
     *             clear_background(237, 34, 93);
     *             draw_ellipse(x, y, Width * 0.1f);
     *         }
     *         void OnMousePressed(MouseButtons button) noexcept
     *         {
     *             if (button == MouseButtons::Left)
     *                 shouldFollowMouse = true;
     *         }
     *         void OnMouseReleased(MouseButtons button) noexcept
     *         {
     *             if (button == MouseButtons::Left)
     *                 shouldFollowMouse = false;
     *         }
     *     };
     *     int main(void)
     *     {
     *         Logic logic{};
     *         logic.Setup();
     *         logic.Run();
     *         return 0;
     *     }
     * \endcode
     * \image html images\events\keyboard\set_callback_mouse_pressed.gif
     */
    void set_callback_mouse_released(std::function<void(MouseButtons)>&& callback) noexcept;
    /**
     * \briefThe provided callback is called whenever the mouse wheel is scrolled.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in an integer. Something like
     * \code void mouseWheel(int scroll_amount); \endcode
     *
     * \param callback what to call when the mouse wheel is scrolled
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     class Logic
     *     {
     *         float y{0.0f};
     *
     *     public:
     *         void Setup() noexcept
     *         {
     *             create_window(480, 360);
     *             set_fill_color(HexColor{0xc8d3d8ff});
     *             set_callback_mouse_wheel([this](int s) { OnMouseWheel(s); });
     *         }
     *         void Run() const noexcept
     *         {
     *             while (!is_window_closed())
     *             {
     *                 update_window();
     *                 Draw();
     *             }
     *         }
     *         void Draw() const noexcept
     *         {
     *             clear_background(HexColor{0xf7fcfdff});
     *             draw_ellipse(0, y, Width * 0.3f);
     *         }
     *         void OnMouseWheel(int scroll_amount) noexcept { y += static_cast<float>(scroll_amount)*2.0f; }
     *     };
     *     int main(void)
     *     {
     *         Logic logic{};
     *         logic.Setup();
     *         logic.Run();
     *         return 0;
     *     }
     * \endcode
     * \image html images\events\keyboard\set_callback_mouse_wheel.gif
     */
    void set_callback_mouse_wheel(std::function<void(int)>&& callback) noexcept;
    /** @} */
}

/**
 *  * \addtogroup Events
 *  global variables related to input Events
 *  @{
 */
/**
 * \brief The declaration of the optional on_key_pressed function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called when a keyboard button is pressed.
 *
 * \param button which button is being pressed
 *
 * \code
 * #include <doodle/doodle.hpp>
 * using namespace doodle;
 *
 * int  main(void)
 * {
 *     create_window(480, 360);
 *     clear_background(220);
 *     set_frame_of_reference(RightHanded_OriginBottomLeft);
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *     }
 *     return 0;
 * }
 *
 * void on_key_pressed(KeyboardButtons button)
 * {
 *     if (button < KeyboardButtons::A || button > KeyboardButtons::Z)
 *     {
 *         clear_background(220); // if it's not a letter clear the screen
 *         return;
 *     }
 *     const auto r = static_cast<Color4ub::unsigned_byte>(random(0, 256));
 *     const auto g = static_cast<Color4ub::unsigned_byte>(random(0, 256));
 *     const auto b = static_cast<Color4ub::unsigned_byte>(random(0, 256));
 *     set_fill_color(r, g, b);
 *     const float rectWidth = Width / 4.0f;
 *     const float key       = (static_cast<float>(button) - static_cast<float>(KeyboardButtons::A));
 *     const float x         = key / (25.0f) * (Width - rectWidth);
 *     draw_rectangle(x, 0, rectWidth, Height * 1.0f);
 * }
 * \endcode
 *
 * \image html images\events\keyboard\set_callback_key_pressed.gif
 *
 */
EVENT_HOOK void on_key_pressed(doodle::KeyboardButtons button);
/**
 * \brief The declaration of the optional on_key_released function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called when a keyboard button is released.
 *
 * \param button which button was released
 *
 * \code
 * #include <doodle/doodle.hpp>
 * using namespace doodle;
 *
 * Color4ub::unsigned_byte grey{0};
 *
 * void on_key_released(KeyboardButtons button)
 * {
 *     if (grey == 0)
 *         grey = 255;
 *     else
 *         grey = 0;
 *     if (button == KeyboardButtons::Escape)
 *         close_window();
 * }
 *
 * int main(void)
 * {
 *     create_window(480, 360);
 *     set_rectangle_mode(RectMode::Center);
 *     grey = 0;
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         clear_background(220);
 *         set_fill_color(grey);
 *         draw_rectangle(0, 0, Width * 0.6f, Height * 0.6f);
 *     }
 *     return 0;
 * }
 * \endcode
 * \image html images\events\keyboard\set_callback_key_released.gif
 */
EVENT_HOOK void on_key_released(doodle::KeyboardButtons button);
/**
 * \brief The declaration of the optional on_mouse_moved function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called whenever the mouse moves to a new
 * position.
 *
 * \param mouse_x mouse x position relative to the current doodle::FrameOfReference
 * \param mouse_y mouse y position relative to the current doodle::FrameOfReference
 *
 * \code
 * #include <doodle/doodle.hpp>
 * using namespace doodle;
 *
 * float                   angle{0.0f};
 * Color4ub::unsigned_byte grey{0};
 * float                   x{0.0f};
 * float                   y{0.0f};
 *
 * void on_mouse_moved(int mouse_x, int mouse_y)
 * {
 *     angle += to_radians(3.0f);
 *     grey = static_cast<Color4ub::unsigned_byte>(255 * (std::sin(angle) * 0.5f + 0.5f));
 *     x    = static_cast<float>(mouse_x);
 *     y    = static_cast<float>(mouse_y);
 * }
 *
 * int main(void)
 * {
 *     create_window(480, 360);
 *     set_rectangle_mode(RectMode::Center);
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         clear_background(220);
 *         set_fill_color(grey);
 *         draw_rectangle(x, y, Width * 0.4f, Height * 0.4f);
 *     }
 *     return 0;
 * }
 * \endcode
 * \image html images\events\keyboard\set_callback_mouse_moved.gif
 */
EVENT_HOOK void on_mouse_moved(int mouse_x, int mouse_y);
/**
 * \brief The declaration of the optional on_mouse_pressed function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called whenever a mouse button is pressed.
 *
 * \param button which button is being pressed
 *
 * \code
 * #include <doodle/doodle.hpp>
 * using namespace doodle;
 *
 * bool shouldFollowMouse = false;
 *
 * void on_mouse_pressed(MouseButtons button)
 * {
 *     if (button == MouseButtons::Left)
 *         shouldFollowMouse = true;
 * }
 *
 * void on_mouse_released(MouseButtons button)
 * {
 *     if (button == MouseButtons::Left)
 *         shouldFollowMouse = false;
 * }
 *
 * int main(void)
 * {
 *     float x{0.0f};
 *     float y{0.0f};
 *     create_window(480, 360);
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         if (shouldFollowMouse)
 *         {
 *             const float easing = 3.0f * DeltaTime;
 *             x += easing * (static_cast<float>(get_mouse_x()) - x);
 *             y += easing * (static_cast<float>(get_mouse_y()) - y);
 *         }
 *         clear_background(237, 34, 93);
 *         draw_ellipse(x, y, Width * 0.1f);
 *     }
 *     return 0;
 * }
 * \endcode
 * \image html images\events\keyboard\set_callback_mouse_pressed.gif
 *
 */
EVENT_HOOK void on_mouse_pressed(doodle::MouseButtons button);
/**
 * \brief The declaration of the optional on_mouse_released function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called whenever a mouse button was
 * released.
 *
 * \param button which button was released
 *
 * \code
 * #include <doodle/doodle.hpp>
 * using namespace doodle;
 *
 * bool shouldFollowMouse = false;
 *
 * void on_mouse_pressed(MouseButtons button)
 * {
 *     if (button == MouseButtons::Left)
 *         shouldFollowMouse = true;
 * }
 *
 * void on_mouse_released(MouseButtons button)
 * {
 *     if (button == MouseButtons::Left)
 *         shouldFollowMouse = false;
 * }
 *
 * int main(void)
 * {
 *     float x{0.0f};
 *     float y{0.0f};
 *     create_window(480, 360);
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         if (shouldFollowMouse)
 *         {
 *             const float easing = 3.0f * DeltaTime;
 *             x += easing * (static_cast<float>(get_mouse_x()) - x);
 *             y += easing * (static_cast<float>(get_mouse_y()) - y);
 *         }
 *         clear_background(237, 34, 93);
 *         draw_ellipse(x, y, Width * 0.1f);
 *     }
 *     return 0;
 * }
 * \endcode
 * \image html images\events\keyboard\set_callback_mouse_pressed.gif
 *
 */
EVENT_HOOK void on_mouse_released(doodle::MouseButtons button);
/**
 * \brief The declaration of the optional on_mouse_wheel function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called whenever the mouse wheel scrolls.
 *
 * \param scroll_amount Positive for scroll up and negative for scroll down.
 *
 * \code
 * #include <doodle/doodle.hpp>
 * using namespace doodle;
 *
 * float y{0.0f};
 *
 * void on_mouse_wheel(int scroll_amount) { y += static_cast<float>(scroll_amount) * 2.0f; }
 *
 * int main(void)
 * {
 *     create_window(480, 360);
 *     set_fill_color(HexColor{0xc8d3d8ff});
 *
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         clear_background(HexColor{0xf7fcfdff});
 *         draw_ellipse(0, y, Width * 0.3f);
 *     }
 *     return 0;
 * }
 * \endcode
 * \image html images\events\keyboard\set_callback_mouse_wheel.gif
 */
EVENT_HOOK void on_mouse_wheel(int scroll_amount);
/** @} */
