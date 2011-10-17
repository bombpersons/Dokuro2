/* 
 * File:   GuiPanelComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 22, 2011, 4:38 PM
 */

#include "GuiPanelComponent.hpp"
#include "../../../Entity.hpp"

namespace Dokuro2 {

    GuiPanelComponent::GuiPanelComponent() {
        AddName("GuiPanelComponent");
        Init();
    }
    
    GuiPanelComponent::~GuiPanelComponent() {
        // Free memory
        if (graphics)
            delete graphics;
        if (imageLoader) {
            delete imageLoader;
            gcn::Image::setImageLoader(NULL);
        }
        if (input)
            delete input;
    }
    
    /* ------------------------------- Init --------------------------------- */
    void GuiPanelComponent::Init() {
        graphics = NULL;
        imageLoader = NULL;
        input = NULL;
        font = NULL;
        
        fontSize = 20;
    }
    
    /* -------------------------- OnReady ----------------------------------- */
    void GuiPanelComponent::OnReady(Entity* _entity) {
        DrawableComponent::OnReady(_entity);
        
        // Initialize guichan
        graphics = new gcn::SFMLGraphics(*_entity->GetRenderTarget());
        imageLoader = new gcn::SFMLImageLoader();
        input = new gcn::SFMLInput();
        
        gui.setGraphics(graphics);
        gui.setInput(input);
        gcn::Image::setImageLoader(imageLoader);
        
        // Call the create widgets function
        if (font)
            gcn::Widget::setGlobalFont(font);
        CreateWidgets();
    }
    
    /* -------------------------- Create widgets ---------------------------- */
    void GuiPanelComponent::CreateWidgets() {
    }
    
    /* --------------------------- Draw ------------------------------------- */
    void GuiPanelComponent::Draw(Entity* _entity, float _time) {
        DrawableComponent::Draw(_entity, _time);
        
        try {
            gui.draw();
        } catch (gcn::Exception e) {
            Tracer::Trace(Level::Bad) << "GuiChan Exception - " << e.getMessage() << endl;
        }
    }
    
    /* -------------------------- Update ------------------------------------ */
    void GuiPanelComponent::Update(Entity* _entity, float _time) {
        DrawableComponent::Update(_entity, _time);
        
        try {
            gui.logic();
        } catch (gcn::Exception e) {
            Tracer::Trace(Level::Bad) << "GuiChan Exception - " << e.getMessage() << endl;
        }        
    }
    
    /* -------------------------- Handle Event ------------------------------ */
    void GuiPanelComponent::HandleEvent(const sf::Event& _event) {
        DrawableComponent::HandleEvent(_event);
        
        input->pushEvent(_event, *parent);
    }
    
    /* -------------------------- SetFont ----------------------------------- */
    void GuiPanelComponent::SetFont(tr1::shared_ptr<sf::Font> _font) {
        if (font)
            delete font;
        
        font = new gcn::SFMLFont(_font, fontSize);
    }
    
    /* --------------------------- Set font size ---------------------------- */
    void GuiPanelComponent::SetFontSize(unsigned int _size) {
        if (!font) {
            Tracer::Trace(Level::Bad) << "No font has been loaded!" << endl;
            return;
        }
        
        font->setFontSize(_size);
        fontSize = _size;
    }
    
    /* ---------------------------- Get font size --------------------------- */
    unsigned int GuiPanelComponent::GetFontSize() {
        if (!font) {
            Tracer::Trace(Level::Bad) << "No font has been loaded!" << endl;
            return fontSize;
        }
        
        return font->getHeight();
    }
}
