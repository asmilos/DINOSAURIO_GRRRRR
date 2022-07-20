#include "MenuScene.h"

MenuScene::MenuScene(){}
MenuScene::MenuScene(RenderWindow * window, int & opc) 
: Scene(window) {
    this->opc = &opc;
    tempOpc = 1;

    texture = new Texture;
    texture->loadFromFile("menu-background.jpg");
    background.setTexture(texture);
    background.setSize({ 800,600 });

    txt_pointer = new Texture;
    txt_pointer->loadFromFile("pointer.png");

    spt_pointer = new Sprite(*txt_pointer);
    ptrPosition = { 120,110 };
    spt_pointer->setPosition(ptrPosition);
}

MenuScene::~MenuScene() {

}

void MenuScene::loop() {
    events();
	window->clear();
    window->draw(background);
    window->draw(*spt_pointer);
	window->display();
}

void MenuScene::events() {
    while (window->pollEvent(*event))
    {
        switch (event->type)
        {
        case Event::Closed:
            window->close();
            break;
        case Event::KeyPressed:
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                ptrPosition.y -= 65;
                tempOpc--;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Down)) {
                ptrPosition.y += 65;
                tempOpc++;
            }

            if (ptrPosition.y < 110) {
                ptrPosition.y = 305;
                tempOpc = 4;
            }

            else if (ptrPosition.y > 305) {
                ptrPosition.y = 110;
                tempOpc = 1;
            }

            spt_pointer->setPosition(ptrPosition);

            if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                *opc = tempOpc;
            }
        }
    }
}