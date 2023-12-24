#include "Entity.h"

Entity::Entity(glm::vec3 position, glm::quat rotation):
	_position(position),
	_rotation(rotation)
{
}

Entity::~Entity()
{
}

glm::mat4 Entity::GetLookAt(glm::vec3 cameraDirection, glm::vec3 cameraUp)
{
	return glm::lookAt(_position, cameraDirection, cameraUp);
}



glm::vec3 Entity::GetPosition()
{
	return _position;
}

glm::quat Entity::GetRotation()
{
	return _rotation;
}

glm::vec3 Entity::GetScale()
{
	return _scale;
}


void Entity::MoveWith(glm::vec3 step)
{
	_position += step;
}

void Entity::MoveTo(glm::vec3 position)
{
	_position = position;
}

void Entity::RotateWith(glm::quat rotation)
{
	_rotation = rotation * _rotation;
}

void Entity::RotateTo(glm::quat rotation)
{
	_rotation = rotation;
	_rotation = glm::normalize(_rotation);
}

void Entity::Scale(float scale)
{
	_scale *= scale;
}

void Entity::Scale(glm::vec3 scale)
{
	_scale *= scale;
}

glm::mat4 Entity::ModelMatrix()
{
	glm::mat4 tranformation(1.0f);
	tranformation = glm::translate(tranformation,_position);
	tranformation *= glm::toMat4(_rotation);
	tranformation = glm::scale(tranformation, _scale);

	return tranformation;
}



