//
// Created by elias on 24/11/2022.
//
#include "World.h"
#include "../parser/tinyxml.h"
#include "AbstractFactory.h"

World::World(AbstractWindow& window, AbstractFactory& factory)
	: window(window)
	, factory(factory)
	, camera(Camera(window.getWindowWidth(), window.getWindowHeight())) {
	isPlaying = false;
	nextLevel = false;
}
SuccessEnum World::init(const char* inputFile) {
	SuccessEnum endResult = Success;
	TiXmlDocument doc;
	ofstream errStream;
	if(!doc.LoadFile(inputFile)) {
		errStream << "XML IMPORT ABORTED: " << doc.ErrorDesc() << endl;
		return endResult;
	}
	TiXmlElement* root = doc.FirstChildElement();
	if(root == nullptr) {
		errStream << "XML PARTIAL IMPORT: Failed to load file: No root element." << std::endl;
		endResult = PartialImport;
		doc.Clear();
		return endResult;
	}
	for(TiXmlElement* elem = root->FirstChildElement(); elem != nullptr;
		elem = elem->NextSiblingElement()) {
		string container = elem->Value();
		string testRoot = root->Value();
		if(testRoot == "root") {
			errStream << "XML PARTIAL IMPORT: container naam moet in uppercase!" << std::endl;
			endResult = PartialImport;
			return endResult;
		}
		if(testRoot != "ROOT") {
			errStream << "XML PARTIAL IMPORT: Een xml bestand moet een ROOT bevatten!" << std::endl;
			endResult = PartialImport;
			return endResult;
		}
		if(!isUpper(container)) {
			errStream << "XML PARTIAL IMPORT: container naam moet in uppercase!" << std::endl;
			endResult = PartialImport;
			return endResult;
		}
		string test = root->FirstChildElement()->Value();
		if(test != "PLAYER") {
			errStream << "XML PARTIAL IMPORT: Een simulatie moet een PLAYER bevatten!" << std::endl;
			endResult = PartialImport;
			return endResult;
		}
		if(container == "PLAYER") {
			bool heeftPositieX = false;
			bool heeftPositieY = false;
			float positieX;
			float positieY;
			for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;
				j = j->NextSiblingElement()) {
				string elemName = j->Value();
				if(elemName == "positieX") {
					heeftPositieX = true;
					positieX = stof(j->GetText());
				} else if(elemName == "positieY") {
					heeftPositieY = true;
					positieY = stof(j->GetText());
				} else {
					errStream << "XML PARTIAL IMPORT: Onherkenbaar element naam" << std::endl;
					endResult = PartialImport;
					return endResult;
				}
			}
			if(!heeftPositieX) {
				errStream << "XML PARTIAL IMPORT: PLAYER bevat geen element X "
							 "positie!"
						  << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			if(!heeftPositieY) {
				errStream << "XML PARTIAL IMPORT: PLAYER bevat geen element Y "
							 "positie!"
						  << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			createPlayer(positieX, positieY);
		} else if(container == "GOAL") {
			bool heeftPositieX = false;
			bool heeftPositieY = false;
			float positieX;
			float positieY;
			for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;
				j = j->NextSiblingElement()) {
				string elemName = j->Value();
				if(elemName == "positieX") {
					heeftPositieX = true;
					positieX = stof(j->GetText());
				} else if(elemName == "positieY") {
					heeftPositieY = true;
					positieY = stof(j->GetText());
				} else {
					errStream << "XML PARTIAL IMPORT: Onherkenbaar element naam" << std::endl;
					endResult = PartialImport;
					return endResult;
				}
			}
			if(!heeftPositieX) {
				errStream << "XML PARTIAL IMPORT: GOAL bevat geen element X positie!" << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			if(!heeftPositieY) {
				errStream << "XML PARTIAL IMPORT: GOAL bevat geen element Y positie!" << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			createGoal(positieX, positieY);
		} else if(container == "WALL") {
			bool heeftPositieX = false;
			bool heeftPositieY = false;
			bool heeftWidth = false;
			bool heeftHeight = false;
			float positieX;
			float positieY;
			float width;
			float height;
			for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;
				j = j->NextSiblingElement()) {
				string elemName = j->Value();
				if(elemName == "positieX") {
					heeftPositieX = true;
					positieX = stof(j->GetText());
				} else if(elemName == "positieY") {
					heeftPositieY = true;
					positieY = stof(j->GetText());
				} else if(elemName == "width") {
					heeftWidth = true;
					width = stof(j->GetText());
				} else if(elemName == "height") {
					heeftHeight = true;
					height = stof(j->GetText());
				} else {
					errStream << "XML PARTIAL IMPORT: Onherkenbaar element naam" << std::endl;
					endResult = PartialImport;
					return endResult;
				}
			}
			if(!heeftPositieX) {
				errStream << "XML PARTIAL IMPORT: WALL bevat geen element X positie!" << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			if(!heeftPositieY) {
				errStream << "XML PARTIAL IMPORT: WALL bevat geen element Y positie!" << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			if(!heeftWidth) {
				errStream << "XML PARTIAL IMPORT: WALL bevat geen element width!" << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			if(!heeftHeight) {
				errStream << "XML PARTIAL IMPORT: WALL bevat geen element height!" << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			createWall(positieX, positieY, width, height);
		} else if(container == "CAMERA") {
			bool heeftAutomatic = false;
			string automatic;
			for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;
				j = j->NextSiblingElement()) {
				string elemName = j->Value();
				if(elemName == "automatic") {
					heeftAutomatic = true;
					automatic = j->GetText();
				} else {
					errStream << "XML PARTIAL IMPORT: Onherkenbaar element naam" << std::endl;
					endResult = PartialImport;
					return endResult;
				}
			}
			if(!heeftAutomatic) {
				errStream << "XML PARTIAL IMPORT: CAMERA bevat geen element "
							 "automatic!"
						  << std::endl;
				endResult = PartialImport;
				return endResult;
			}
			if(automatic == "on")
				setAutomaticCamera(true);
			else if(automatic == "off")
				setAutomaticCamera(false);
		} else {
			errStream << "XML PARTIAL IMPORT: Onherkenbaar container naam" << std::endl;
			endResult = PartialImport;
			return endResult;
		}
	}
	doc.Clear();
	return endResult;
}

void World::setAutomaticCamera(bool c) {
	camera.setIsAutomatic(c);
}

bool World::isUpper(string& word) {
	for(auto& c : word)
		if(!std::isupper(static_cast<unsigned char>(c)))
			return false;
	return true;
}

void World::createPlayer(float x, float y) {
	playerModel = factory.createPlayer(*this, x, y);
}

void World::createWall(float x, float y, float wi, float h) {
	shared_ptr<WallModel> wall = factory.createWall(*this, x, y, wi, h);
	walls.push_back(wall);
}

bool World::updateEntities() {
	stopwatch->nextFrame();
	playerModel->checkDrag();
	playerModel->checkCollisionWalls(walls);
	if(playerModel->checkCollision(*playerModel, *goalModel)) {
		nextLevel = true;
		return false;
	}
	playerModel->checkJump();
	/// update observers
	playerModel->updateObserver();
	goalModel->updateObserver();
	updateAllWalls();

	/// als de player boven 80% van de screen height komt, dan move ik de screen
	/// nr boven met het verschil
	if(playerModel->getPositionY() >= camera.getCameraHeight() + camera.getWindowHeight() * 0.8) {
		float heightDIff = abs((camera.getCameraHeight() + camera.getWindowHeight() * 0.8) -
							   playerModel->getPositionY());
		camera.addCameraHeight(heightDIff);
	}
	/// als de player onder de current screen height komt, dan heeft de player
	/// verloren en restart ik het level
	if(playerModel->getPositionY() + playerModel->getHeight() < camera.getCameraHeight()) {
		return false;
	}

	/// check for keyboard input
	char key[4] = {-1, -1, -1, -1};
	window.checkKeyboardInput(key);
	if(key[0] == 'A' && !playerModel->getIsMovingRight() && !playerModel->getCollisionLeft()) {
		playerModel->move(-1, 0);
		playerModel->setAddDrag(false);
		playerModel->setIsMovingLeft(true);
		if(playerModel->getCollisionRight())
			playerModel->setCollisionRight(false);
	}
	if(key[1] == 'D' && !playerModel->getIsMovingLeft() && !playerModel->getCollisionRight()) {
		playerModel->move(1, 0);
		playerModel->setAddDrag(false);
		playerModel->setIsMovingRight(true);
		if(playerModel->getCollisionLeft())
			playerModel->setCollisionLeft(false);
	}
	if(key[2] == 'S' &&
	   (playerModel->getPositionY() == playerModel->getGroundHeight() or
		playerModel->getCollisionRight() or playerModel->getCollisionLeft()) &&
	   !playerModel->getIsJumping()) {
		if((playerModel->getCollisionRight() &&
			(playerModel->getCollisionBottom() or playerModel->getPositionY() == 0)) or
		   (playerModel->getCollisionLeft() &&
			(playerModel->getCollisionBottom() or playerModel->getPositionY() == 0)))
			playerModel->move(0, 1);

		else if(playerModel->getCollisionRight()) {
			playerModel->resetVel();
			playerModel->setCollisionRight(false);
			playerModel->move(-17, 1);
		} else if(playerModel->getCollisionLeft()) {
			playerModel->resetVel();
			playerModel->setCollisionLeft(false);
			playerModel->move(17, 1);
		} else
			playerModel->move(0, 1);
		playerModel->setIsJumping(true);
		playerModel->setIsStillJumping(true);
		playerModel->setGroundHeight(0);
		playerModel->setCollisionBottom(false);
	}
	/// als ik op escape druk dan laat ik de menuState zien
	if(key[3] == 'E')
		return false;
	char release[3] = {-1, -1, -1};
	window.checkEvent(release);
	if(release[0] == 'D') {
		playerModel->resetVel();
		if(playerModel->getIsStillJumping())
			playerModel->setAddDrag(true);
		playerModel->setIsMovingRight(false);
	}
	if(release[1] == 'A') {
		playerModel->resetVel();
		if(playerModel->getIsStillJumping())
			playerModel->setAddDrag(true);
		playerModel->setIsMovingLeft(false);
	}
	if(release[2] == 'S') {
		playerModel->setIsJumping(false);
	}
	/// als de camera automatic is dn move ik de camera elke keer naar boven
	if(camera.getIsAutomatic() && playerModel->getPositionY() != 0) {
		camera.addCameraHeight(0.6);
	}
	return true;
}

void World::runGameLoop() {
	isPlaying = true;
	while(this->isPlaying and this->window.isOpen()) {
		window.clear();
		window.drawBackground();
		isPlaying = updateEntities();
		window.display();
	}
}

void World::updateAllWalls() {
	for(auto& wall : walls) {
		wall->updateObserver();
	}
}

Camera& World::getCamera() {
	return camera;
}

shared_ptr<Stopwatch> World::getStopwatch() {
	return stopwatch;
}

void World::createGoal(float x, float y) {
	goalModel = factory.createGoal(*this, x, y);
}

bool World::getNextLevel() {
	return nextLevel;
}