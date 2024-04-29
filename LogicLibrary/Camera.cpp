//
// Created by elias on 03/12/2022.
//
#include "Camera.h"
#include "EntityModel.h"

Camera::Camera(float w, float h) {
	windowWidth = w;
	windowHeight = h;
	cameraHeight = 0;
	isAutomatic = false;
}

pair<float, float> Camera::coordinateToPixel(float x, float y, const EntityModel& entity) const {
	pair<float, float> newPos(x, (windowHeight - ((y + entity.getHeight()) - cameraHeight)));
	return newPos;
}

float Camera::getWindowWidth() const {
	return windowWidth;
}

float Camera::getWindowHeight() const {
	return windowHeight;
}

float Camera::getCameraHeight() const {
	return cameraHeight;
}

void Camera::addCameraHeight(float h) {
	cameraHeight += h;
}

void Camera::setIsAutomatic(bool a) {
	isAutomatic = a;
}

bool Camera::getIsAutomatic() const {
	return isAutomatic;
}