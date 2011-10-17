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

#ifndef GCN_SFMLIMAGE_HPP
#define GCN_SFMLIMAGE_HPP

#include "../guichan/color.hpp"
#include "../guichan/platform.hpp"
#include "../guichan/image.hpp"

#include <SFML/Graphics/Texture.hpp>

#include <tr1/memory>
using namespace std;

namespace gcn
{
    /**
    * SFML implementation of Image.
    */
    class GCN_EXTENSION_DECLSPEC SFMLImage : public Image
    {
    public:

        /**
        * Constructor.
        *
        * @param image The SFML image.
        */
        SFMLImage(tr1::shared_ptr<sf::Texture> image);

        /**
        * Destructor.
        */
        virtual ~SFMLImage();


        /**
        * Gets the SFML image used by the implementation.
        *
        * @return the SFML image.
        */
        tr1::shared_ptr<sf::Texture> getImageFromSFML() const;

        // Inherited from Image

        virtual void free();

        virtual int getWidth() const;

        virtual int getHeight() const;

        virtual Color getPixel(int x, int y);

        virtual void putPixel(int x, int y, const Color& color);

        virtual void convertToDisplayFormat();

    protected:

        tr1::shared_ptr<sf::Texture> mImage;

    };
}

#endif // end GCN_SFMLIMAGE_HPP
