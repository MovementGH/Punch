#ifndef Menu_hpp
#define Menu_hpp
#include <SFML/Graphics.hpp>
#include "MenuManager.hpp"

class MenuManager;
class Menu {

public:

    Menu(MenuManager* Manager);
    
    virtual void onGainFocus();
    virtual void onLoseFocus();
    virtual void onEvent(sf::Event& event);
    virtual void onExit();
    
    virtual void resize(sf::Vector2u size);
    virtual void update(sf::Time delta);
    virtual void render();

    sf::Sprite getSprite();

protected:

    MenuManager* m_Manager;

    sf::RenderTexture m_Texture;
    sf::Sprite m_Sprite;

};

#endif