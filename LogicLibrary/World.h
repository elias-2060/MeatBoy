//
// Created by elias on 24/11/2022.
//

#ifndef MEATBOY_WORLD_H
#include "../GameRepresentation/State.h"
#include "AbstractWindow.h"
#include "Camera.h"
#include "GoalModel.h"
#include "PlayerModel.h"
#include "Stopwatch.h"
#include "WallModel.h"
#include "shared_mutex"
#include <fstream>
#include <memory>
#define MEATBOY_WORLD_H

enum SuccessEnum { ImportAborted, PartialImport, Success };

class AbstractFactory;
/// bevat alle entities, elke level heeft zijn eigen world
class World {
private:
	shared_ptr<PlayerModel> playerModel;
	shared_ptr<GoalModel> goalModel;
	vector<shared_ptr<WallModel>> walls;
	AbstractWindow& window;
	AbstractFactory& factory;
	Camera camera;
	shared_ptr<Stopwatch> stopwatch = stopwatch->getStopwatch();
	bool isPlaying;
	bool nextLevel;

public:
	World(AbstractWindow& window, AbstractFactory& factory);
	/// initialiseerd de world door de gegeven input file, aan de hand van de
	/// xml parser
	SuccessEnum init(const char* inputFile);
	/// maakt een player aan in de world
	void createPlayer(float x, float y);
	/// maakt een goal aan in de world
	void createGoal(float x, float y);
	/// maakt een wall aan in de world en add het in de vector met walls
	void createWall(float x, float y, float wi, float h);
	/// updates all entities en checkt voor collision met de entities
	bool updateEntities();
	/// runt de game loop
	void runGameLoop();
	/// update all de observers van de walls, zodat ze op de screen worden laten
	/// zien
	void updateAllWalls();
	/// kijkt of de gegeven string in uppercase is
	bool isUpper(string& word);
	/// set de camera op automatic
	void setAutomaticCamera(bool c);
	/// returned of we naar de next level moeten gaan of niet
	bool getNextLevel();
	/// returned de camera
	Camera& getCamera();
	/// returned de stopwatch
	shared_ptr<Stopwatch> getStopwatch();
};

#endif // MEATBOY_WORLD_H
