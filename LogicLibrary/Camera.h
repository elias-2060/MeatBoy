//
// Created by elias on 03/12/2022.
//

#ifndef MEATBOY_CAMERA_H
#include "iostream"
#define MEATBOY_CAMERA_H
using namespace std;

class EntityModel;
class Camera {
private:
	float windowHeight;
	float windowWidth;
	/// dit is wat de player ziet op het scherm
	float cameraHeight;
	/// dit bepaald of de camera automatisch omhoog gaat of niet
	bool isAutomatic;

public:
	Camera(float w, float h);
	/// converts de logic coordinates naar pixel coordinates
	pair<float, float> coordinateToPixel(float x, float y, const EntityModel& entity) const;
	/// returned de width van de window
	float getWindowWidth() const;
	/// returned de height van de window
	float getWindowHeight() const;
	/// returned de current height van de screen dat de player ziet
	float getCameraHeight() const;
	/// door hier een waarde te adden gaat de screen dat de player ziet omhoog
	/// met die waarde
	void addCameraHeight(float h);
	/// set de camera automatic of niet
	void setIsAutomatic(bool a);
	/// returned of de camera automatic omhoog gaat of niet
	bool getIsAutomatic() const;
};

#endif // MEATBOY_CAMERA_H
