#pragma once
#include"Level.h"
#include"Platform.h"
#include"Spike.h"

/* El estado 1 */
class Level1 : public Level
{
public:
	Level1() {
		label = "level 1";
		txr_background.loadFromFile("Images/fondo_dino_dia.png");
	}

	void setPlayersPosition(std::vector<Player>& players) {
		for (Player& p : players) {
			p.SetPosition({ 50.0f, 500.0f });
		}
	}

	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/base_dino_dia.png", Vector2f(1200.0f, 200.0f), Vector2f(0.0f, 600.0f)));
		platforms.push_back(Platform("Images/base_dino_dia.png", Vector2f(500.0f, 200.0f), Vector2f(960.0f, 600.0f)));


		platforms.push_back(Platform("Images/bloque_02_dino.png", Vector2f(100.0f, 50.0f), Vector2f(900.0f, 450.0f)));
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 50.0f), Vector2f(1090.0f, 370.0f)));
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 50.0f), Vector2f(1280.0f, 290.0f)));

		//saltos arriba
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 50.0f), Vector2f(1490.0f, 290.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 30.0f), Vector2f(1640.0f, 290.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 30.0f), Vector2f(1790.0f, 290.0f)));

		//saltos abajo
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(100.0f, 50.0f), Vector2f(1400.0f, 600.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 30.0f), Vector2f(1600.0f, 600.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 30.0f), Vector2f(1700.0f, 520.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 30.0f), Vector2f(1800.0f, 440.0f)));
		platforms.push_back(Platform("Images/bloque_03_dino.png", Vector2f(50.0f, 30.0f), Vector2f(1900.0f, 360.0f)));



		//salto final
		platforms.push_back(Platform("Images/bloque_01_dino.png", Vector2f(300.0f, 200.0f), Vector2f(2250.0f, 680.0f)));


		return platforms;
	}

	std::vector<Spike> GetSpikes() {
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(630.0f, 680.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(680.0f, 680.0f)));

		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(1240.0f, 680.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(1290.0f, 680.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(1340.0f, 680.0f)));

		//saltos arriba
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(1390.0f, 290.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(1590.0f, 290.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 40.0f), Vector2f(1720.0f, 290.0f)));

		//saltos abajo
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(1550.0f, 680.0f)));
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(1500.0f, 680.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 40.0f), Vector2f(1660.0f, 590.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 40.0f), Vector2f(1760.0f, 510.0f)));
		spikes.push_back(Spike("Images/pua_01.png", Vector2f(40.0f, 40.0f), Vector2f(1860.0f, 430.0f)));

		//bordeabajo
		for (float i = -200; i <= 3000; i += 50) {
			spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(i, 1000.0f)));
		}
		return spikes;
	}

	std::vector<Door> GetDoors() {

		// puerta
		doors.push_back(Door("Images/puerta_dino.png", Vector2f(80.0f, 80.0f), Vector2f(2250.0f, 557.0f)));
		return doors;
	}
};


