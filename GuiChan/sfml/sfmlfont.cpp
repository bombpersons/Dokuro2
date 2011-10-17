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

#include "sfmlfont.hpp"

#include <guichan/exception.hpp>
#include "sfmlgraphics.hpp"

#include <SFML/Graphics/Text.hpp>

namespace gcn
{
    SFMLFont::SFMLFont(tr1::shared_ptr<sf::Font> font, unsigned int size)
    {
        mFont = font;
        mSize = size;
    }

    int SFMLFont::getWidth(const std::string& text) const
    {
        sf::Text str(text, *mFont.get(), mSize);
        return (str.GetRect().Width);
    }

    int SFMLFont::getHeight() const
    {
        return (mSize);
    }

    const sf::Font& SFMLFont::getFont() const
    {
        return (*mFont.get());
    }

    void SFMLFont::drawString(Graphics* graphics, const std::string& text, int x, int y)
    {
        SFMLGraphics* const sfmlgraphics = dynamic_cast<SFMLGraphics*>(graphics);

        if (!sfmlgraphics)
        {
            throw GCN_EXCEPTION("Graphics is not of type SFMLGraphics");
        }
        sfmlgraphics->drawString(text, x, y, *this);
    }
    
    void SFMLFont::setFontSize(unsigned int _size) {
        mSize = _size;
    }
}
