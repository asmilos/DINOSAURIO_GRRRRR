#pragma once
#include"Level.h"
#include"Platform.h"

/* El estado 3*/
class Level3 : public Level
{
public:
	Level3() {
		label = "level 3";
		txr_background.loadFromFile("Images/nivel03.jpg");
	}

	void setPlayersPosition(std::vector<Player>& players) {
		for (Player& p : players) {
			p.SetPosition({ 400.0f, -500.0f });
		}
	}

	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/base_dino_dia.png", Vector2f(300.0f, 80.0f), Vector2f(400.0f, -300.0f)));
		//izq
		platforms.push_back(Platform("Images/bloque_02_dino.png", Vector2f(80.0f, 60.0f), Vector2f(50.0f, -250.0f)));
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 40.0f), Vector2f(50.0f, -50.0f)));

		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(40.0f, 40.0f), Vector2f(200.0f, -50.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(40.0f, 40.0f), Vector2f(300.0f, -50.0f)));

		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 40.0f), Vector2f(300.0f, 600.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 40.0f), Vector2f(100.0f, 700.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(30.0f, 20.0f), Vector2f(-100.0f, 800.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(-300.0f, 900.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(-200.0f, 1100.0f)));

		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(-50.0f, 1100.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(50.0f, 1030.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(150.0f, 960.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(250.0f, 890.0f)));

		//derecha
		platforms.push_back(Platform("Images/bloque_02_dino.png", Vector2f(80.0f, 60.0f), Vector2f(750.0f, -250.0f)));
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 40.0f), Vector2f(750.0f, -50.0f)));

		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(40.0f, 40.0f), Vector2f(600.0f, -50.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(40.0f, 40.0f), Vector2f(500.0f, -50.0f)));

		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 40.0f), Vector2f(500.0f, 600.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 40.0f), Vector2f(700.0f, 700.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(30.0f, 20.0f), Vector2f(900.0f, 800.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(1100.0f, 900.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(1000.0f, 1100.0f)));

		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(850.0f, 1100.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(750.0f, 1030.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(650.0f, 960.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(20.0f, 20.0f), Vector2f(550.0f, 890.0f)));


		//puerta
		platforms.push_back(Platform("Images/bloque_02_dino.png", Vector2f(100.0f, 30.0f), Vector2f(400.0f, 800.0f)));
		platforms.push_back(Platform("Images/puerta_dino.png", Vector2f(80.0f, 80.0f), Vector2f(400.0f, 750.0f)));
		//puerta real
		platforms.push_back(Platform("Images/bloque_02_dino.png", Vector2f(100.0f, 30.0f), Vector2f(400.0f, 2400.0f)));
		
		return platforms;
	}

	std::vector<Spike> GetSpikes() {
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 70.0f), Vector2f(200.0f, -250.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 70.0f), Vector2f(160.0f, -250.0f)));

		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 70.0f), Vector2f(600.0f, -250.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 70.0f), Vector2f(640.0f, -250.0f)));

		//izq
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(40.0f, 70.0f), Vector2f(200.0f, 650.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(40.0f, 70.0f), Vector2f(0.0f, 750.0f)));
		//der
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(40.0f, 70.0f), Vector2f(600.0f, 650.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(40.0f, 70.0f), Vector2f(800.0f, 750.0f)));
		//medio
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(100.0f, 100.0f), Vector2f(400.0f, 600.0f)));
		//bordeabajo
		for (float i = -200;i <= 1000;i += 50) {
			spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(i, 2500.0f)));
		}
		
		return spikes;
	}

	std::vector<Door> GetDoors() {
		doors.push_back(Door("Images/puerta_dino.png", Vector2f(80.0f, 80.0f), Vector2f(400.0f, 2350.0f)));

		return doors;
	}
};
