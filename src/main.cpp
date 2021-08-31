#include "Util/MenuManager.hpp"
#include "Menus/MainMenu.hpp"

int main(int argc, char **argv) {
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(1920,1080), "Punch", sf::Style::Default);
    Window.setVerticalSyncEnabled(true);

    MenuManager Manager(Window);
    Manager.pushMenu(new MainMenu(&Manager));
    Manager.run();
}