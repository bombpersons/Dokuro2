/*
 *
 * SFML backend for Guichan (by Robin Ruaux)
 *
 * Visit: http://guichan.sourceforge.net
 *        http://sfml-dev.org
 *
 * License: (BSD)
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Guichan nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GCN_SFMLGRAPHICS_HPP
#define GCN_SFMLGRAPHICS_HPP

#include "../guichan/color.hpp"
#include "../guichan/graphics.hpp"
#include "../guichan/platform.hpp"

#include "sfmlfont.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

namespace gcn
{
    /**
    * SFML implementation of the Graphics.
    */
    class GCN_EXTENSION_DECLSPEC SFMLGraphics : public Graphics
    {
    public:

        /**
         * Constructor.
         *
         * @param target The SFML RenderWindow target to draw in.
         */
        SFMLGraphics(sf::RenderTarget& target);

        /**
         * Destructor.
         */
        virtual ~SFMLGraphics();

        /**
         * Sets the size of the graphics context.
         *
         * @param width Width of the rectangle.
         * @param height Height of the rectangle.
         */
        virtual void setSize(unsigned int width, unsigned int height);

        /**
         * Draws a custom string to the Guichan context.
         *
         * @param text The string content.
         * @param x The x coordinate of the string.
         * @param y The y coordinate of the string.
         * @param font The SFML font.
         */
        virtual void drawString(const std::string& text, int x, int y, const SFMLFont& font);


        // Inherited from Graphics

        virtual void _beginDraw();

        virtual void _endDraw();

        virtual bool pushClipArea(Rectangle area);

        virtual void popClipArea();


        /**
         * Draws an SFML image to the Guichan context.
         *
         * @param image The SFML image.
         * @param srcX The x source first pixel coordinate.
         * @param srcY The y source first pixel coordinate.
         * @param dstX The x destination first pixel coordinate.
         * @param dstY The y destination first pixel coordinate.
         * @param width The width of the image split.
         * @param height The height of the image split.
         */
        virtual void drawImage(const Image* image, int srcX, int srcY, int dstX, int dstY, int width, int height);

        /**
         * Draws a point to the Guichan context.
         *
         * @param x The x position of the point.
         * @param y The y position of the point.
        */
        virtual void drawPoint(int x, int y);

        /**
         * Draws a line to the Guichan context.
         *
         * @param x1 The x first point position.
         * @param y1 The y first point position.
         * @param x2 The x second point position.
         * @param y2 The y second point position.
         */
        virtual void drawLine(int x1, int y1, int x2, int y2);

        /**
         * Draws a rectangle to the Guichan context.
         *
         * @param rectangle The rectangle coordinates.
         */
        virtual void drawRectangle(const Rectangle& rectangle);

        /**
         * Draws a filled-rectangle to the Guichan context.
         *
         * @param rectangle The filled-rectangle coordinates.
         */
        virtual void fillRectangle(const Rectangle& rectangle);

        /**
         * Sets the color to use for drawables.
         *
         * @param color The color to use.
         */
        virtual void setColor(const Color& color);

        /**
         * Gets the current color.
         *
         * @return The current color.
         */
        virtual const Color& getColor() const;

    protected:

        sf::RenderTarget& mRenderer;
        Color mColor;
        unsigned int mWidth;
        unsigned int mHeight;

    private:

        /**
         * Converts a Guichan color to an SFML color.
         *
         * @param color The Guichan color.
         * @return The SFML color.
         */
        sf::Color convertToSFMLColor(const Color& color) const;

    };
}

#endif // end GCN_SFMLGRAPHICS_HPP
