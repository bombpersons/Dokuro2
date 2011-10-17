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

#include "sfmlgraphics.hpp"

#include <guichan/exception.hpp>
#include <guichan/image.hpp>

#include "sfmlimage.hpp"

#include <SFML/Graphics.hpp>

#include <GL/gl.h>

namespace gcn
{
    SFMLGraphics::SFMLGraphics(sf::RenderTarget& target)
        : mRenderer(target), mWidth(target.GetWidth()), mHeight(target.GetHeight())
    {

    }

    SFMLGraphics::~SFMLGraphics()
    {

    }

    void SFMLGraphics::_beginDraw()
    {
        pushClipArea(Rectangle(0, 0, mWidth, mHeight));
        glEnable(GL_SCISSOR_TEST);
    }

    void SFMLGraphics::_endDraw()
    {
        glDisable(GL_SCISSOR_TEST);
        popClipArea();
    }

    bool SFMLGraphics::pushClipArea(Rectangle area)
    {
        bool result = Graphics::pushClipArea(area);

        glScissor(mClipStack.top().x,
                  mHeight - mClipStack.top().y - mClipStack.top().height,
                  mClipStack.top().width,
                  mClipStack.top().height);

        return (result);
    }

    void SFMLGraphics::popClipArea()
    {
        Graphics::popClipArea();

        if (mClipStack.empty())
        {
            return;
        }
        glScissor(mClipStack.top().x,
                  mHeight - mClipStack.top().y - mClipStack.top().height,
                  mClipStack.top().width,
                  mClipStack.top().height);
    }

    void SFMLGraphics::setSize(unsigned int width, unsigned int height)
    {
        mWidth = width;
        mHeight = height;
    }

    void SFMLGraphics::setColor(const Color& color)
    {
        mColor = color;
    }

    const Color& SFMLGraphics::getColor() const
    {
        return mColor;
    }

    sf::Color SFMLGraphics::convertToSFMLColor(const Color& color) const
    {
        return sf::Color(color.r, color.g, color.b, color.a);
    }

    void SFMLGraphics::drawImage(const Image* image, int srcX, int srcY, int dstX, int dstY, int width, int height)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const SFMLImage* srcImage = dynamic_cast<const SFMLImage*>(image);

        if (!srcImage)
        {
            throw GCN_EXCEPTION("Trying to draw an image of unknown format, must be an SFMLImage.");
    	}

        const ClipRectangle& top = mClipStack.top();

        sf::Sprite spr(*srcImage->getImageFromSFML().get());
        spr.SetPosition(sf::Vector2f(dstX + top.xOffset, dstY + top.yOffset));
        spr.SetSubRect(sf::IntRect(srcX, srcY, srcX + width, srcY + height));

        mRenderer.Draw(spr);
    }

    void SFMLGraphics::drawPoint(int x, int y)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        sf::Shape Point;
        Point.AddPoint(x + top.xOffset, y + top.yOffset, convertToSFMLColor(mColor));

        mRenderer.Draw(Point);
    }

    void SFMLGraphics::drawLine(int x1, int y1, int x2, int y2)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        sf::Shape Line = sf::Shape::Line(x1 + top.xOffset + 0.375f,
                                         y1 + top.yOffset + 0.375f,
                                         x2 + top.xOffset + 0.625f,
                                         y2 + top.yOffset + 0.625f,
                                         1.00f, convertToSFMLColor(mColor));

        mRenderer.Draw(Line);
    }

    void SFMLGraphics::drawRectangle(const Rectangle& rectangle)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();
        const sf::Color color = convertToSFMLColor(mColor);

        sf::Shape Rect = sf::Shape::Rectangle(rectangle.x + top.xOffset + 1.0f,
                                              rectangle.y + top.yOffset + 1.0f,
                                              rectangle.width - 1.0f,
                                              rectangle.height - 1.0f,
                                              color, 1.0f, color);
        Rect.EnableFill(false);

        mRenderer.Draw(Rect);
    }

    void SFMLGraphics::fillRectangle(const Rectangle& rectangle)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw funtion outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();

        sf::Shape Rect = sf::Shape::Rectangle(rectangle.x + top.xOffset,
                                              rectangle.y + top.yOffset,
                                              rectangle.width,
                                              rectangle.height,
                                              convertToSFMLColor(mColor));

        mRenderer.Draw(Rect);
    }

    void SFMLGraphics::drawString(const std::string& text, int x, int y, const SFMLFont& font)
    {
        if (mClipStack.empty())
        {
            throw GCN_EXCEPTION("Clip stack is empty, perhaps you called a draw function outside of _beginDraw() and _endDraw()?");
        }

        const ClipRectangle& top = mClipStack.top();
        const sf::Font& sffont = font.getFont();

        sf::Text str(text.c_str(), sffont, font.getHeight());
        str.SetPosition(sf::Vector2f(top.xOffset + x, top.yOffset + y - font.getHeight() / 4 + 1.0f));
        str.SetColor(convertToSFMLColor(mColor));

        mRenderer.Draw(str);
    }

}
