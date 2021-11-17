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
    /**
     *  * \addtogroup Environment
     *  Window related functions, The window hosts the doodle.
     *  @{
     */

    /**
     * \brief Create a default window.
     *
     * Creates a window in the middle of the screen, roughly 75% the width & height of the monitor.
     *
     * \return True if window was create, false otherwise
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window();
     *
     *         using namespace std::string_literals;
     *         const std::string text = "("s + std::to_string(Width) + ","s + std::to_string(Height) + ")"s;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x9E1F33FF});
     *             draw_text(text, 0, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * On a 1920x1080 monitor:
     * \image html images\environment\window\create_window_1.png
     */
    bool create_window() noexcept;
    /**
     * \brief Create a default window with a custom window title
     * \param title custom title for the window
     * \return True if window was create, false otherwise
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window("Orange Window");
     *
     *         using namespace std::string_literals;
     *         const std::string text = "("s + std::to_string(Width) + ","s + std::to_string(Height) + ")"s;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xC75023FF});
     *             draw_text(text, 0, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * On a 1920x1080 monitor:
     * \image html images\environment\window\create_window_2.png
     */
    bool create_window(const std::string& title) noexcept;
    /**
     * \brief Create a window with a desired screen size.
     * \param desired_width how wide you'd like the screen space to be
     * \param desired_height how tall you'd like the screen space to be
     * \return True if window was create, false otherwise
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *
     *         using namespace std::string_literals;
     *         const std::string text = "("s + std::to_string(Width) + ","s + std::to_string(Height) + ")"s;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xF69C40FF});
     *             draw_text(text, -Width / 2.0f + 70, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\create_window_3.png
     */
    bool create_window(int desired_width, int desired_height) noexcept;
    /**
     * \brief Create a window with a custom window title and a desired screen size.
     * \param title custom title for the window
     * \param desired_width how wide you'd like the screen space to be
     * \param desired_height how tall you'd like the screen space to be
     * \return True if window was create, false otherwise
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window("Jungle Green Window", 480, 360);
     *
     *         using namespace std::string_literals;
     *         const std::string text = "("s + std::to_string(Width) + ","s + std::to_string(Height) + ")"s;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x2A9D9BFF});
     *             draw_text(text, -Width / 2.0f + 70, 0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\create_window_4.png
     */
    bool create_window(const std::string& title, int desired_width, int desired_height) noexcept;

    /**
     * \brief Is the window closed?
     *
     * Should be used to drive the applications main loop. If the user closes the window through the operating system
     * then you need to end your loop.
     *
     * \return true if the window closed, false if it is still open
     *
     * \code
     *    #include <doodle/doodle.hpp>
     *    #include <string>
     *    using namespace doodle;
     *    int main(void)
     *    {
     *        create_window(480, 360);
     *        while (!is_window_closed())
     *        {
     *            update_window();
     *            clear_background(HexColor{0xD7CF9CFF});
     *            draw_text("Winter Hazel", -Width / 2.0f + 20, 0);
     *        }
     *        return 0;
     *    }
     * \endcode
     * \image html images\environment\window\is_window_closed.gif
     */
    bool is_window_closed() noexcept;

    /**
     * \brief Update the doodle application.
     *
     * This needs to be called once every frame of the main loop. This is where events and drawing logic is updated.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         set_fill_color(HexColor{0xe1aa2dff});
     *         while (!is_window_closed())
     *         {
     *             update_window(); // update mouse, keyboard, window, graphics, etc...
     *             clear_background(HexColor{0x3f965bff});
     *             const auto mouseX = static_cast<float>(get_mouse_x());
     *             const auto mouseY = static_cast<float>(get_mouse_y());
     *             draw_ellipse(mouseX, mouseY, 32.0f);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\update_window.gif
     */
    void update_window() noexcept;

    /**
     * \brief Programmatically close the window.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         bool  closing   = false;
     *         float countDown = 2.0f;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xE27E75FF});
     *             if (!closing)
     *             {
     *                 draw_text("Hi", 0, 0);
     *                 if (KeyIsPressed && Key == KeyboardButtons::Escape)
     *                 {
     *                     closing = true;
     *                 }
     *             }
     *             else
     *             {
     *                 draw_text("Bye!", 0, 0);
     *                 countDown -= DeltaTime;
     *                 if (countDown < 0)
     *                     close_window();
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\close_window.gif
     */
    void close_window() noexcept;

    /**
     * \brief Set a new title for the window
     * \param new_title a new title for the window
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <sstream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         float frameTime  = 0;
     *         float frameCount = 0;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             frameTime += DeltaTime;
     *             frameCount += 1.0f;
     *
     *             if (frameTime > 0.5f)
     *             {
     *                 const auto fps = frameCount / frameTime;
     *                 frameCount     = 0;
     *                 frameTime      = 0;
     *                 std::stringstream ss;
     *                 ss << "doodle [fps=" << fps << "]";
     *                 set_window_title(ss.str());
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\set_window_title.gif
     */
    void set_window_title(const std::string& new_title) noexcept;
    /**
     * \brief Is the window a fullscreen window?
     * \return true if the window is fullscreen, false if it is windowed
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <sstream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(640, 480);
     *         set_callback_key_released([](KeyboardButtons button)
     *         {
     *             if(button == KeyboardButtons::F)
     *                 toggle_full_screen();
     *             else if(button == KeyboardButtons::Escape)
     *                 close_window();
     *         });
     *         std::stringstream ss;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x614A86FF});
     *             ss.clear();
     *             ss.str("");
     *             ss << "fullscreen: " << std::boolalpha << is_full_screen();
     *             draw_text(ss.str(), -280,0);
     *
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\fullscreen.gif
     */
    bool is_full_screen() noexcept;
    /**
     * \brief Switch back and forth between fullscreen and windowed mode.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <sstream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(640, 480);
     *         set_callback_key_released([](KeyboardButtons button)
     *         {
     *             if(button == KeyboardButtons::F)
     *                 toggle_full_screen();
     *             else if(button == KeyboardButtons::Escape)
     *                 close_window();
     *         });
     *         std::stringstream ss;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x614A86FF});
     *             ss.clear();
     *             ss.str("");
     *             ss << "fullscreen: " << std::boolalpha << is_full_screen();
     *             draw_text(ss.str(), -280,0);
     *
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\fullscreen.gif
     */
    void toggle_full_screen() noexcept;
    /**
     * \brief Confirms if the window a doodle program is in is "focused," meaning that the doodle will accept mouse or
     * keyboard input. This variable is "true" if the window is focused and "false" if not.
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
     *             if (WindowIsFocused)
     *             {
     *                 clear_background(HexColor{0xD7A5860A});
     *                 set_window_title("doodle - focused");
     *             }
     *             else
     *             {
     *                 clear_background(0, 10);
     *                 set_window_title("doodle - not focused");
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\globals\WindowIsFocused.gif
     */
    extern bool WindowIsFocused;
    /**
     * \brief The provided callback function is called whenever the window is resized by the user.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in two integers. Something like
     * \code void windowResized(int new_width, int new_height); \endcode
     *
     * \param callback what to call when the window is resized
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <sstream>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(640, 480);
     *         std::stringstream ss;
     *         set_callback_window_resized([&ss](int new_width, int new_height)
     *         {
     *             ss.clear();
     *             ss.str("");
     *             ss << "(" << new_width << ", " << new_height << ")";
     *         });
     *
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0x969EC2FF});
     *             draw_text(ss.str(), -280,0);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\set_callback_window_resized.gif
     */
    void set_callback_window_resized(std::function<void(int, int)>&& callback) noexcept;
    /**
     * \brief The provided callback function will be called when the user uses the OS to close the window.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in nothing. Something like
     * \code void windowClosed(); \endcode
     *
     * \param callback what to call when the window will close
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <iostream>
     *     using namespace doodle;
     *     void windowClosed() { std::cerr << "Shutdown!\n"; }
     *     int  main(void)
     *     {
     *         create_window(640, 480);
     *         set_callback_window_closed(&windowClosed);
     *         std::cout << "Start\n";
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(HexColor{0xedd884ff});
     *         }
     *         return 0;
     *     }
     * \endcode
     *
     * Prints the following:
     * \code
     *     Start
     *     Shutdown!
     * \endcode
     */
    void set_callback_window_closed(std::function<void(void)>&& callback) noexcept;
    /**
     * \brief THe provided callback function will be called when the window gains or loses focus.
     *
     * It takes in a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) with a signature of
     * something that returns nothing and takes in a boolean. Something like
     * \code void windowFocusChanged(bool is_focused); \endcode
     *
     * \param callback what to call when the window has lost or gained focus
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         Color4ub clearColor = HexColor{0xD7A5860A};
     *         set_callback_window_focus_changed([&](bool is_focused) {
     *             if (is_focused)
     *             {
     *                 clearColor = HexColor{0xD7A5860A};
     *                 set_window_title("doodle - focused");
     *             }
     *             else
     *             {
     *                 clearColor = Color4ub{0, 10};
     *                 set_window_title("doodle - not focused");
     *             }
     *         });
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(clearColor);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\window\set_callback_window_focus_changed.gif
     */
    void set_callback_window_focus_changed(std::function<void(bool)>&& callback) noexcept;

    /**
     * \brief This function will allow you to hide or show the mouse cursor.
     * \param show_it should the cursor be visible or not
     * \code
     * #include <doodle/doodle.hpp>
     * using namespace doodle;
     *
     * void on_key_released(KeyboardButtons button)
     * {
     *     if (button == KeyboardButtons::Escape)
     *         show_cursor(false);
     *     if (button == KeyboardButtons::Space)
     *         show_cursor();
     * }
     *
     * int main(void)
     * {
     *     create_window(480, 360);
     *
     *     while (!is_window_closed())
     *     {
     *         update_window();
     *         clear_background(HexColor{0xf7fcfdaa});
     *     }
     *     return 0;
     * }
     * \endcode
     * \image html images\environment\window\show_cursor.gif
     */
    void show_cursor(bool show_it = true) noexcept;

}


/**
 *  * \addtogroup Environment
 *  Window related functions, The window hosts the doodle.
 *  @{
 */
/**
 * \brief The declaration of the optional on_window_resized function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called when the window resizes.
 *
 * \param new_width  Width of the new window resolution
 * \param new_height Height of the new window resolution
 *
 * \code
 * #include <doodle/doodle.hpp>
 * #include <sstream>
 * using namespace doodle;
 *
 * std::stringstream ss;
 *
 * int main(void)
 * {
 *     create_window(640, 480);
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         clear_background(HexColor{0x969EC2FF});
 *         draw_text(ss.str(), -280, 0);
 *     }
 *     return 0;
 * }
 *
 * void on_window_resized(int new_width, int new_height)
 * {
 *     ss.clear();
 *     ss.str("");
 *     ss << "(" << new_width << ", " << new_height << ")";
 * }
 * \endcode
 * \image html images\environment\window\set_callback_window_resized.gif
 */
EVENT_HOOK void on_window_resized(int new_width, int new_height);
/**
 * \brief The declaration of the optional on_window_closed function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called when the window closes.
 *
 * \code
 * #include <doodle/doodle.hpp>
 * #include <iostream>
 * using namespace doodle;
 *
 * void on_window_closed() { std::cerr << "Shutdown!\n"; }
 *
 * int  main(void)
 * {
 *     create_window(640, 480);
 *     std::cout << "Start\n";
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         clear_background(HexColor{0xedd884ff});
 *     }
 *     return 0;
 * }
 * \endcode
 *
 * Prints the following:
 * \code
 *     Start
 *     Shutdown!
 * \endcode
 *
 */
EVENT_HOOK void on_window_closed();
/**
 * \brief The declaration of the optional on_window_focus_changed function to implement in your doodle program.
 *
 * If you define the function definition of this function then it will be called when the window changes it's focus.
 *
 * \param is_focused true when window has focus and false otherwise
 *
 * \code
 * #include <doodle/doodle.hpp>
 * using namespace doodle;
 *
 * Color4ub clearColor = HexColor{0xD7A5860A};
 *
 * int main(void)
 * {
 *     create_window(480, 320);
 *     while (!is_window_closed())
 *     {
 *         update_window();
 *         clear_background(clearColor);
 *     }
 *     return 0;
 * }
 *
 * void on_window_focus_changed(bool is_focused)
 * {
 *     if (is_focused)
 *     {
 *         clearColor = HexColor{0xD7A5860A};
 *         set_window_title("doodle - focused");
 *     }
 *     else
 *     {
 *         clearColor = Color4ub{0, 10};
 *         set_window_title("doodle - not focused");
 *     }
 * }
 * \endcode
 * \image html images\environment\window\set_callback_window_focus_changed.gif
 *
 */
EVENT_HOOK void on_window_focus_changed(bool is_focused);
/** @} */
