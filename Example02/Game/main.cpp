#include <iostream>

#include "IComponent.h"
#include "Sprite.h"

template<IsComponent C>
void draw(const C& component){
	component.Draw();
}

int main() {

	std::cout << "Hello 2GD!\n";

	Sprite s;
	draw(s);

	return 0;
}