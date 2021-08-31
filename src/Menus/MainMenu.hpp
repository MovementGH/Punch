#ifndef MainMenu_hpp
#define MainMenu_hpp
#include <SFML/Graphics.hpp>
#include "../Util/Menu.hpp"

class MainMenu : public Menu {
    
public:
    
    MainMenu(MenuManager* Manager);

    virtual void resize(sf::Vector2u size) override;
    virtual void update(sf::Time delta) override;
    virtual void render() override;

protected:

    sf::RectangleShape m_Rect;
    sf::Text m_Text;
};

#endif