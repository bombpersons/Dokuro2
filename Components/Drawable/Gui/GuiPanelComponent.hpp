/* 
 * File:   GuiPanelComponent.hpp
 * Author: bombpersons
 *
 * Created on June 22, 2011, 4:38 PM
 */

#ifndef GUIPANELCOMPONENT_HPP
#define	GUIPANELCOMPONENT_HPP

#include "../DrawableComponent.hpp"
#include "../../../GuiChan/guichan.hpp"
#include "../../../GuiChan/sfml.hpp"

namespace Dokuro2 {

    class GuiPanelComponent : public DrawableComponent {
    public:
        GuiPanelComponent();
        virtual ~GuiPanelComponent();
        
        /* Init */
        virtual void Init();
        
        /* Initialize the panel */
        virtual void OnReady(Entity* _entity);
        
        /* Create the widgets on the panel */
        virtual void CreateWidgets();
        
        /* Draw the widgets */
        virtual void Draw(Entity* _entity, float _time);
        
        /* Do the logic */
        virtual void Update(Entity* _entity, float _time);
        
        /* Handle events */
        virtual void HandleEvent(const sf::Event& _event);
        
        /* Set and Gets */
        virtual void SetFont(tr1::shared_ptr<sf::Font> _font);
        
        virtual void SetFontSize(unsigned int _size);
        virtual unsigned int GetFontSize();
        
    protected:
        gcn::Gui gui; // The gui.
        gcn::SFMLGraphics* graphics; // Used to draw graphics by guichan.
        gcn::SFMLImageLoader* imageLoader; // Used to load images by guichan.
        gcn::SFMLInput* input; // Used to get input by guichan.
        gcn::SFMLFont* font; // The font to use. 
        
        unsigned int fontSize; 
    };

}

#endif	/* GUIPANELCOMPONENT_HPP */

