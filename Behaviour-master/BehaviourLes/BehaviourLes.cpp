// BehaviourLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <vector>
#include <vector>
#include <string>
#include "Character.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

double delay = 0.5;
double previousFrameTime = 0.0;
int maxWidth = 1000;
std::vector<std::string> scene;
bool running = true;
int main()
{
	//Characters aanmaken
	Character player(Character::AvailableBehaviours::IDLE, 20, "E");
	Character enemy(Character::AvailableBehaviours::CHASE, 5, "C", &player);

	//Game mechanics activeren
	player.SetTarget(&enemy);
	player.Setbehaviour(Character::AvailableBehaviours::EVADE);

	//alle spelers in een lijst
	std::vector<Character*> characters{ &player, &enemy };

	//een scene van 100 breed aanmaken
	scene.resize(100);

	//deze scene vullen met _
	
	previousFrameTime = clock();
	//de game zelf
	while (running) {
		//een eigen timer
		if ((clock() - previousFrameTime) / CLOCKS_PER_SEC >= delay) {
			std::fill(scene.begin(), scene.end(), "_");
			system("cls");
			//std::cout << "[" << clock() << "] updating" << std::endl;
			for (Character* aCharacter : characters) {
				scene.at(aCharacter->Update()) = aCharacter->GetIcon();
			}
			for (std::string s : scene) {
				std::cout << s;
			}


			previousFrameTime = clock();
		}
		if (characters.at(0)->GetPosition() == characters.at(1)->GetPosition()) {
			std::cout << "\nGAME OVER\nPress ENTER to quit" << std::endl;
			running = false;
		}
	}
	std::cin.get();
}


