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

#include "sfmlimage.hpp"

#include <guichan/exception.hpp>

namespace gcn
{
    SFMLImage::SFMLImage(tr1::shared_ptr<sf::Texture> image)
        : mImage(image)
    {
        mImage->SetSmooth(false);
        //mImage->CreateMaskFromColor(sf::Color(255, 0, 255));
    }

    SFMLImage::~SFMLImage()
    {

    }

    tr1::shared_ptr<sf::Texture> SFMLImage::getImageFromSFML() const
    {
        return mImage;
    }

    void SFMLImage::free()
    {

    }

    int SFMLImage::getWidth() const
    {
        return mImage->GetWidth();
    }

    int SFMLImage::getHeight() const
    {
        return mImage->GetHeight();
    }

    Color SFMLImage::getPixel(int x, int y)
    {
        const sf::Color& c = mImage->CopyToImage().GetPixel(x, y);

        return Color(c.r, c.g, c.b, c.a);
    }

    void SFMLImage::putPixel(int x, int y, const Color& color)
    {
        sf::Color col(color.r, color.g, color.b, color.a);
        sf::Image image = mImage->CopyToImage();
        image.SetPixel(x, y, col);
        mImage->LoadFromImage(image);
    }

    void SFMLImage::convertToDisplayFormat()
    {
        mImage->Bind();
    }

}
