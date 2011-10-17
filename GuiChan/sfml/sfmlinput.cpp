/*
 *
 * Created by Robin Ruaux - 08/05/09
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

#include "sfmlinput.hpp"

#include <guichan/exception.hpp>
#include <SFML/Graphics/Matrix3.hpp>

namespace gcn
{
    SFMLInput::SFMLInput()
    {

    }

    void SFMLInput::pushEvent(const sf::Event& event, Entity& _entity)
    {
        KeyInput	keyInput;
        MouseInput	mouseInput;
        
        switch (event.Type)
        {
            case sf::Event::TextEntered:
            {
                keyInput.setKey(Key(event.Text.Unicode));
                keyInput.setType(KeyInput::PRESSED);

                mKeyInputQueue.push(keyInput);
                break;
            }

            case sf::Event::KeyPressed:
            {
                int value = convertKeyValue(event.Key.Code);

                if (value != -1)
                {
                    keyInput.setKey(Key(value));
                    keyInput.setType(KeyInput::PRESSED);
                    keyInput.setControlPressed(event.Key.Control);
                    keyInput.setShiftPressed(event.Key.Shift);
                    keyInput.setAltPressed(event.Key.Alt);

                    mKeyInputQueue.push(keyInput);
                }
                break;
            }

            case sf::Event::KeyReleased:
            {
                int value = convertKeyValue(event.Key.Code);

                if (value != -1)
                {
                    keyInput.setKey(Key(value));
                    keyInput.setType(KeyInput::RELEASED);
                    keyInput.setControlPressed(event.Key.Control);
                    keyInput.setShiftPressed(event.Key.Shift);
                    keyInput.setAltPressed(event.Key.Alt);
                    
                    mKeyInputQueue.push(keyInput);
                }
                break;
            }

            case sf::Event::MouseButtonPressed:
            {
                mouseInput.setX(sf::Mouse::GetPosition(*_entity.GetRootWindow()).x);
                mouseInput.setY(sf::Mouse::GetPosition(*_entity.GetRootWindow()).y);
                mouseInput.setButton(convertMouseButton(event.MouseButton.Button));
                mouseInput.setType(MouseInput::PRESSED);

                mMouseInputQueue.push(mouseInput);
                break;
            }

            case sf::Event::MouseButtonReleased:
            {
                mouseInput.setX(sf::Mouse::GetPosition(*_entity.GetRootWindow()).x);
                mouseInput.setY(sf::Mouse::GetPosition(*_entity.GetRootWindow()).y);
                mouseInput.setButton(convertMouseButton(event.MouseButton.Button));
                mouseInput.setType(MouseInput::RELEASED);

                mMouseInputQueue.push(mouseInput);
                break;
            }

            case sf::Event::MouseMoved:
            {
                mouseInput.setX(sf::Mouse::GetPosition(*_entity.GetRootWindow()).x);
                mouseInput.setY(sf::Mouse::GetPosition(*_entity.GetRootWindow()).y);
                mouseInput.setButton(MouseInput::EMPTY);
                mouseInput.setType(MouseInput::MOVED);

                mMouseInputQueue.push(mouseInput);
                break;
            }

            default:
            {
                break;
            }
        }

    }

    bool SFMLInput::isKeyQueueEmpty()
    {
        return mKeyInputQueue.empty();
    }

    KeyInput SFMLInput::dequeueKeyInput()
    {
        if (mKeyInputQueue.empty())
        {
            throw GCN_EXCEPTION("The KeyInput queue is empty.");
        }

        KeyInput keyInput = mKeyInputQueue.front();
        mKeyInputQueue.pop();

        return keyInput;
    }

    bool SFMLInput::isMouseQueueEmpty()
    {
        return mMouseInputQueue.empty();
    }

    MouseInput SFMLInput::dequeueMouseInput()
    {
        if (mMouseInputQueue.empty())
        {
            throw GCN_EXCEPTION("The MouseInput queue is empty.");
        }

        MouseInput mouseInput = mMouseInputQueue.front();
        mMouseInputQueue.pop();

        return mouseInput;
    }

    int	SFMLInput::convertMouseButton(sf::Mouse::Button button)
    {
        switch (button)
        {
            case sf::Mouse::Left:
                return MouseInput::LEFT;
            break;

            case sf::Mouse::Right:
                return MouseInput::RIGHT;
            break;

            case sf::Mouse::Middle:
                return MouseInput::MIDDLE;
            break;

            default:
                return MouseInput::EMPTY;
            break;
        }
    }


    int	SFMLInput::convertKeyValue(sf::Keyboard::Key code)
    {
        int value = -1;

        switch (code)
        {
            case sf::Keyboard::LAlt:
                value = Key::LEFT_ALT;
            break;

            case sf::Keyboard::RAlt:
                value = Key::RIGHT_ALT;
            break;

            case sf::Keyboard::LShift:
                value = Key::LEFT_SHIFT;
            break;

            case sf::Keyboard::RShift:
                value = Key::RIGHT_SHIFT;
            break;

            case sf::Keyboard::LControl:
                value = Key::LEFT_CONTROL;
            break;

            case sf::Keyboard::RControl:
                value = Key::RIGHT_CONTROL;
            break;

            case sf::Keyboard::Pause:
                value = Key::PAUSE;
            break;

            case sf::Keyboard::Delete:
                value = Key::DELETE;
            break;

            case sf::Keyboard::Back:
                value = Key::BACKSPACE;
            break;

            case sf::Keyboard::Insert:
                value = Key::INSERT;
            break;

            case sf::Keyboard::Home:
                value = Key::HOME;
            break;

            case sf::Keyboard::End:
                value = Key::END;
            break;

            case sf::Keyboard::PageUp:
                value = Key::PAGE_UP;
            break;

            case sf::Keyboard::PageDown:
                value = Key::PAGE_DOWN;
            break;

            case sf::Keyboard::F1:
                value = Key::F1;
            break;

            case sf::Keyboard::F2:
                value = Key::F2;
            break;

            case sf::Keyboard::F3:
                value = Key::F3;
            break;

            case sf::Keyboard::F4:
                value = Key::F4;
            break;

            case sf::Keyboard::F5:
                value = Key::F5;
            break;

            case sf::Keyboard::F6:
                value = Key::F6;
            break;

            case sf::Keyboard::F7:
                value = Key::F7;
            break;

            case sf::Keyboard::F8:
                value = Key::F8;
            break;

            case sf::Keyboard::F9:
                value = Key::F9;
            break;

            case sf::Keyboard::F10:
                value = Key::F10;
            break;

            case sf::Keyboard::F11:
                value = Key::F11;
            break;

            case sf::Keyboard::F12:
                value = Key::F12;
            break;

            case sf::Keyboard::F13:
                value = Key::F13;
            break;

            case sf::Keyboard::F14:
                value = Key::F14;
            break;

            case sf::Keyboard::F15:
                value = Key::F15;
            break;

            case sf::Keyboard::Up:
                value = Key::UP;
            break;

            case sf::Keyboard::Down:
                value = Key::DOWN;
            break;

            case sf::Keyboard::Left:
                value = Key::LEFT;
            break;

            case sf::Keyboard::Right:
                value = Key::RIGHT;
            break;

            case sf::Keyboard::Return:
                value = Key::ENTER;
            break;

            default:
                value = -1;
            break;
        }

        return (value);
    }

}
