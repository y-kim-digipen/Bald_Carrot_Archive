/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once
#include <doodle/color.hpp>

#include <filesystem>
#include <vector>

namespace doodle
{
    /**
     * \addtogroup Image
     *  Image class to store a 2D array of colors
     *  @{
     */
    /**
     * \class Image image.hpp doodle/image.hpp
     * \brief Image class to store a 2D array of RGBA colors.
     *
     * The Image class is useful for creating images programmatically. It is also useful for loading and creating PNG
     * files.
     *
     * \code
     *     #include <cmath>
     *     #include <doodle/doodle.hpp>
     *     using namespace doodle;
     *     int main(void)
     *     {
     *         create_window(480, 320);
     *         set_texture_mode(RectMode::Center);
     *         Image noiseImage{};
     *         Texture texture{};
     *         noiseImage.ResizeToPixelWidthHeight(Width, Height);
     *         while (!is_window_closed())
     *         {
     *             update_window();
     *             for (int column = 0; column < noiseImage.GetWidth(); ++column)
     *             {
     *                 for (int row = 0; row < noiseImage.GetHeight(); ++row)
     *                 {
     *                     const auto c    = 255.0f * noise(column * 0.02f, row * 0.02f, ElapsedTime / 4.0f);
     *                     const auto grey = static_cast<Color4ub::unsigned_byte>(std::lround(c));
     *                     noiseImage.SetPixel(column, row, Color4ub{grey});
     *                 }
     *             }
     *             if (const bool loaded = texture.LoadFromImage(noiseImage); loaded)
     *             {
     *                 draw_texture(texture, 0, 0);
     *             }
     *         }
     *         return 0;
     *     }
     * \endcode
     * \image html images\image\creatingimages\ImageClass.gif
     */
    class [[nodiscard]] Image
    {
    public:
        /**
         * \brief Resize the image to a desired resolution.
         * \param pixel_width how wide to make this image
         * \param pixel_height how tall to make this image
         */
        void ResizeToPixelWidthHeight(int pixel_width, int pixel_height) noexcept;
        /**
         * \brief Create an Image based off of a png file.
         * \param file_path file path to a png file.
         * \return true if the png file was successfully loaded.
         */
        bool LoadFromPNG(const std::filesystem::path& file_path) noexcept;
        /**
         * \brief Save the Image as a PNG file.
         *
         * You should not be giving a directory and you will need to add the png extension yourself.
         *
         * \param file_path file path to save the image file to.
         */
        void SaveToPNG(const std::filesystem::path& file_path) const noexcept;

        /**
         * \brief Return the width of the image
         * \return width of the Image
         */
        int GetWidth() const noexcept;
        /**
         * \brief Return the height of the image
         * \return height of the Image
         */
        int GetHeight() const noexcept;

        /**
         * \brief Set a pixel color at a specific point in the image.
         * \param column where horizontally to set a pixel
         * \param row where vertically to set a pixel
         * \param color the color to write to the pixel
         */
        void SetPixel(int column, int row, Color4ub color) noexcept;
        /**
         * \brief Return a writable pointer to the beginning of all of the pixels
         * \return writable pointer to the pixels
         */
        Color4ub* GetPixelsPointer() noexcept;
        /**
         * \brief Return a readable pointer to the beginning of all of the pixels
         * \return readable pointer to the pixels
         */
        const Color4ub* GetPixelsPointer() const noexcept;
        /**
         * \brief Get the size of all of the pixels in bytes
         * \return size of the pixels in bytes
         */
        int GetPixelsBufferBytesSize() const noexcept;
        /**
         * \brief Flip the image vertically.
         */
        void FlipVertically() noexcept;

    private:
        int                   width  = 0;
        int                   height = 0;
        std::vector<Color4ub> pixels{};

        static const int ChannelsPerColor = 4;
    };
    /** @} */
}
