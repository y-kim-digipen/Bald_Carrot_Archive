/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once


namespace doodle
{
    /**
     *  \addtogroup Environment
     *  global variables related to the state of the doodle
     *  @{
     */
    /**
     * \brief The system variable FrameCount contains the number of frames that have been displayed since the program
     * started. The first call to update_window() will set the value to 1 and subsequent calls increment the value.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <string>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(220);
     *             draw_text(std::to_string((FrameCount)), -60.0f, 0.0f);
     *         }
     *
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\globals\FrameCount.gif
     */
    extern int FrameCount;
    /**
     * \brief The system variable DeltaTime contains the time difference between the beginning of the previous frame and
     * the beginning of the current frame in seconds.
     *
     * This variable is useful for creating time sensitive animation or physics calculation that should stay constant
     * regardless of frame rate.
     *
     * \code
     *     #include <doodle/doodle.hpp>
     *     #include <thread>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 360);
     *         float           x = -Width / 2.0f;
     *         Color4ub        rectangleColor{255, 0, 0};
     *         bool            increaseDeltaTime = false;
     *         constexpr float pixerlsPerSecond  = 200.0f;
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(200);
     *             draw_text("dt: " + std::to_string(static_cast<int>(DeltaTime * 1000)) + "ms", -Width / 2.0f + 30.0f,
     *                       -Height / 2.0f + 80.0f);
     *             // Regardless of the length of DeltaTime we will move the rectangle across the screen in the same
     *             // amount of time
     *             x += DeltaTime * pixerlsPerSecond;
     *             if (x >= Width / 2.0f)
     *             {
     *                 if (increaseDeltaTime)
     *                 {
     *                     increaseDeltaTime   = false;
     *                     rectangleColor.red  = 255;
     *                     rectangleColor.blue = 0;
     *                 }
     *                 else
     *                 {
     *                     increaseDeltaTime   = true;
     *                     rectangleColor.red  = 0;
     *                     rectangleColor.blue = 255;
     *                 }
     *                 x = -Width / 2.0f;
     *             }
     *             set_fill_color(rectangleColor);
     *             draw_rectangle(x, Height / 8.0f, 80.0f);
     *             if (increaseDeltaTime)
     *             {
     *                 using namespace std::chrono_literals;
     *                 std::this_thread::sleep_for(100ms); // 100 milliseconds
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\globals\DeltaTime.gif
     */
    extern float DeltaTime;
    /**
     * \brief Returns the number of seconds since starting the program. This information is often used for timing events
     * and animation sequences.
     *
     * \code
     *     #include <doodle/doodle.hpp> using namespace doodle; int main(void)
     *     {
     *         create_window(480, 360);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             clear_background(200);
     *             draw_text("Seconds:\n\t" + std::to_string(ElapsedTime) + "s", -Width / 2.0f + 30.0f, Height / 16.0f);
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\environment\globals\ElapsedTime.gif
     */
    extern float ElapsedTime;
    /**
     * \brief System variable that stores the width of the drawing canvas. This value is set by the **desired_width**
     * parameter of the create_window() function. For example, the function call create_window(320, 240) sets the width
     * variable to the value 320.
     *
     * \code
     * #include <doodle/doodle.hpp>
     * #include <iostream>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 360);
     *     std::cout << Width << ", " << Height << "\n";
     *     // prints: 480, 360
     *     return 0;
     * }
     * \endcode
     */
    extern int Width;
    /**
     * \brief System variable that stores the height of the drawing canvas. This value is set by the **desired_height**
     * parameter of the create_window() function. For example, the function call create_window(320, 240) sets the height
     * variable to the value 240.
     *
     * \code
     * #include <doodle/doodle.hpp>
     * #include <iostream>
     * using namespace doodle;
     * int main(void)
     * {
     *     create_window(480, 360);
     *     std::cout << Width << ", " << Height << "\n";
     *     // prints: 480, 360
     *     return 0;
     * }
     * \endcode
     */
    extern int Height;
    /** @} */
}
