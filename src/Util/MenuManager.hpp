#ifndef MenuManager_hpp
#define MenuManager_hpp
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "AssetManager.hpp"

class Menu;
class MenuManager {

public:

    MenuManager(sf::RenderWindow& window);

    void run();

    void pushMenu(Menu* menu);
    void popMenu();

    Menu* getForegroundMenu();
    AssetManager* getAssets();

protected:

    std::vector<Menu*> m_Menus;
    AssetManager m_Assets;

    sf::RenderWindow& m_Window;

};

#endif