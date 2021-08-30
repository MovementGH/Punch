#include "Menu.hpp"

Menu::Menu(MenuManager* Manager) :
    m_Manager(Manager) {

}

void Menu::onGainFocus() {

}

void Menu::onLoseFocus() {

}

void Menu::onEvent(sf::Event& event) {

}

void Menu::onExit() {

}

void Menu::resize(sf::Vector2u size) {
    m_Texture.create(size.x, size.y);
    m_Sprite.setTexture(m_Texture.getTexture());
    m_Sprite.setTextureRect({0, 0, (int)size.x, (int)size.y});
}

void Menu::update(sf::Time delta) {

}

void Menu::render() {

}

sf::Sprite Menu::getSprite() {
    return m_Sprite;
}