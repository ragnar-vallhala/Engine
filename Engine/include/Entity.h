#pragma once
#include "EngineUtils.h"
#include "Renderer.h"
class Entity {

private:
	glm::vec3 _position = glm::vec3(0.0, 0.0, 0.0);
	glm::quat _rotation = glm::quat(1.0,0.0,0.0,0.0);
	glm::vec3 _scale = glm::vec3(1.0, 1.0, 1.0);

public:

	//variables
	Renderer _renderer{};


	//functions

	Entity() {};
	Entity(glm::vec3 position, glm::quat rotation);
	~Entity();


	glm::mat4 GetLookAt(glm::vec3 cameraDirection, glm::vec3 cameraUp);

	glm::vec3 GetPosition();
	glm::quat GetRotation();
	glm::vec3 GetScale();

	//moves current position with new position
	void MoveWith(glm::vec3);

	//moves object to new position
	void MoveTo(glm::vec3);



	//rotate the existing roation with the new amount
	void RotateWith(glm::quat rotation);

	//rotates the entity to new amount starting from identity
	void RotateTo( glm::quat rotation);

	
	//Scales the entity
	void Scale(float);
	void Scale(glm::vec3);


	//Return the model matrix to convert the objexts vertices to world space
	glm::mat4 ModelMatrix();

};