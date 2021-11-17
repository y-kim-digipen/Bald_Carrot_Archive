/*--------------------------------------------------------------*
  Copyright (C) 2019 Rudy Castan

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `License.md' for details.
*--------------------------------------------------------------*/
#pragma once

#include <filesystem>


namespace doodle
{
    class Color4ub;
    class Image;

    /**
     *  * \addtogroup Image
     *  Texture class to store a 2D array of colors on the Graphics Card
     *  @{
     */
    /**
     * \class Texture texture.hpp doodle/texture.hpp
     * \brief Manages a Texture image on the Graphics Card. See draw_texture() for learning on how to use it.
     */
    class [[nodiscard]] Texture
    {
    public:
        Texture() = default;

        /**
         * \brief Create a GPU Texture based off of a png file.
         * \param file_path file path to a png file.
         * \return true if the png file was successfully loaded.
         */
        bool LoadFromPNG(const std::filesystem::path& file_path) noexcept;
        /**
         * \brief Create a GPU texture based off of a Image.
         * \param image image to upload to the GPU
         * \return true if the image was successfully loaded
         */
        bool LoadFromImage(const doodle::Image& image) noexcept;
        /**
         * \brief Create a GPU texture based off of 2D array of Color4ub colors.
         * \param image_width width of the array of colors provided
         * \param image_height height of the array of colors provided
         * \param colors pointer to the beginning of 2D array of Color4ub colors
         * \return true of the colors were successfully loaded
         */
        bool LoadFromMemory(int image_width, int image_height, const doodle::Color4ub* colors) noexcept;

        /**
         * \brief Get the width of the texture
         * \return width of the texture
         */
        int GetWidth() const noexcept { return width; }
        /**
         * \brief Get the height of the texture
         * \return height of the texture
         */
        int GetHeight() const noexcept { return height; }
        /**
         * \brief Enable or disable the smooth filter.
         *
         * When the filter is activated, the texture appears smoother so that pixels are less noticeable. However if you
         * want the texture to look exactly the same as its source file, you should leave it disabled. The smooth filter
         * is disabled by default.
         *
         * \param smooth_it True to enable smoothing, false to disable it.
         */
        void SetSmooth(bool smooth_it = true) noexcept;
        /**
         * \brief Tell whether the smooth filter is enabled or not.
         *
         * \return True if smoothing is enabled, false if it is disabled
         */
        bool IsSmooth() const noexcept { return isSmooth; }
        /**
         * \brief Get the handle ID to the GPU texture
         * \return handle of the GPU texture
         */
        unsigned int GetTextureHandle() const noexcept { return textureHandle; }

        ~Texture() noexcept;
        Texture(Texture && other) noexcept;
        Texture& operator=(Texture&& other) noexcept;

    public:
        Texture(const Texture& other) = delete;
        Texture& operator=(const Texture& other) = delete;

    private:
        void DeleteTexture() noexcept;

    private:
        unsigned int textureHandle = 0;
        int          width         = 0;
        int          height        = 0;
        bool         isSmooth      = false;
    };
    /** @} */
}
