#pragma once
#include "EngineUtils.h"
#include "Entity.h"
class Camera : public Entity{

private:
	glm::vec3 _cameraDirection = glm::vec3(0.0, 0.0, -1.0);
	glm::vec3 _cameraUp = glm::vec3(1.0, 0.0, 0.0);

	float _fov = glm::radians(45.0f);
	float _nearClipPlane = 0.1f;
	float _farClipPlane = 100.0f;

public:

	Camera() {
	};
	glm::vec3 GetDirection();
	void SetDirection(glm::vec3);

	glm::mat4 GetPerspectiveMatrix(float aspectRatio);

	float GetFOV();

	//angle in degrees
	void SetFOV(float);

	float GetNearClipPlane();
	void SetNearClipPlane(float);
	
	float GetFarClipPlane();
	void SetFarClipPlane(float);


};