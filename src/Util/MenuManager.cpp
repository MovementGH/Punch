#include "MenuManager.hpp"

MenuManager::MenuManager(sf::RenderWindow& window) :
    m_Window(window) {
    
}

void MenuManager::run() {

    sf::Clock FrameClock;
    while(m_Window.isOpen()) {

        sf::Event Event;
        while(m_Window.pollEvent(Event)) {

            if(Event.type == sf::Event::Closed) {
                while(m_Menus.size()) {
                    popMenu();
                }
                m_Window.close();
            }

            if(Event.type == sf::Event::LostFocus) {
                getForegroundMenu()->onLoseFocus();
            }

            if(Event.type == sf::Event::GainedFocus) {
                getForegroundMenu()->onGainFocus();
            }

            if(Event.type==sf::Event::Resized) {

                sf::View View({0, 0, (float)Event.size.width, (float)Event.size.height});
                m_Window.setView(View);
                
                for(auto & Menu : m_Menus)
                    Menu->resize({Event.size.width, Event.size.height});
                
            }

            if(m_Menus.size())
                getForegroundMenu()->onEvent(Event);

        }

        sf::Time Delta = FrameClock.restart();

        m_Window.clear();
        for(auto & Menu : m_Menus) {
            if(Menu == getForegroundMenu()) {
                Menu->update(Delta);
                m_Window.draw(Menu->getSprite());
            }
        }
        m_Window.display();

    }

}

void MenuManager::pushMenu(Menu* menu) {
    if(m_Menus.size()) {
        getForegroundMenu()->onLoseFocus();
    }

    menu->resize(m_Window.getSize());
    m_Menus.push_back(menu);
}

void MenuManager::popMenu() {
    getForegroundMenu()->onExit();
    delete getForegroundMenu();
    m_Menus.pop_back();
}

Menu* MenuManager::getForegroundMenu() {
    return m_Menus[m_Menus.size() - 1];
}

AssetManager* MenuManager::getAssets() {
    return &m_Assets;
}