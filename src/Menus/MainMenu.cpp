#include "MainMenu.hpp"

MainMenu::MainMenu(MenuManager *Manager) : Menu(Manager) {
    m_Text.setFont(m_Manager->getAssets()->getAsset<sf::Font>("assets/sansation.ttf"));
    m_Text.setString("Hello World");
}

void MainMenu::resize(sf::Vector2u size) {
    Menu::resize(size);
    m_Text.setOrigin(m_Text.getLocalBounds().width / 2, m_Text.getLocalBounds().height / 2);
    m_Text.setPosition(size.x / 2, size.y / 2);
}

void MainMenu::update(sf::Time delta) {
    render();
}

void MainMenu::render() {
    m_Texture.clear();
    m_Texture.draw(m_Text);
    m_Texture.display();
}