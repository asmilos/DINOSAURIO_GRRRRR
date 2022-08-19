#pragma once
#include"Level.h"
#include"Platform.h"


/* El estado 2*/
class Level2 : public Level
{
public:
	Level2() {
		label = "level 2";
		txr_background.loadFromFile("Images/nivel02.jpg");
	}

	void setPlayersPosition(std::vector<Player>& players) {
		for (Player& p : players) {
			p.SetPosition({ -600.0f, 500.0f });
		}
	}

	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/base_dino_dia.png", Vector2f(1400.0f, 200.0f), Vector2f(0.0f, 600.0f)));

		//salto1
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(100.0f, 50.0f), Vector2f(200.0f, 450.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(100.0f, 50.0f), Vector2f(450.0f, 440.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(70.0f, 50.0f), Vector2f(600.0f, 400.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(70.0f, 50.0f), Vector2f(750.0f, 360.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(70.0f, 50.0f), Vector2f(900.0f, 320.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(750.0f, 240.0f)));

		//salto2
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(570.0f, 220.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(390.0f, 200.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(390.0f, 200.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(210.0f, 180.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(30.0f, 160.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(-150.0f, 140.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(10.0f, 10.0f), Vector2f(-320.0f, 120.0f)));
		//salto final
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(200.0f, 100.0f), Vector2f(-600.0f, 300.0f)));
		


		return platforms;
	}
	std::vector<Spike> GetSpikes() {
		//Primera zona

		spikes.push_back(Spike("Images/pua_01.png", Vector2f(30.0f, 30.0f), Vector2f(-300.0f, 488.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(30.0f, 30.0f), Vector2f(-200.0f, 488.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(30.0f, 30.0f), Vector2f(-100.0f, 488.0f)));

		spikes.push_back(Spike("Images/pua_01.png", Vector2f(30.0f, 30.0f), Vector2f(0.0f, 488.0f)));

		//salto1
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(250.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(300.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(350.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(400.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(450.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(500.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(550.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(600.0f, 482.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(650.0f, 482.0f)));

		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(800.0f, 370.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(850.0f, 370.0f)));
		return spikes;
	}

	std::vector<Door> GetDoors() {
		doors.push_back(Door("Images/puerta_dino.png", Vector2f(80.0f, 80.0f), Vector2f(-650.0f, 220.0f)));
		return doors;
	}
};