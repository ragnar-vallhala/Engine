#include "Camera.h"



glm::vec3 Camera::GetDirection()
{
	return _cameraDirection;
}

void Camera::SetDirection(glm::vec3 newCameraDirection)
{
	_cameraDirection = newCameraDirection;
}

glm::mat4 Camera::GetPerspectiveMatrix(float aspectRatio)
{
	return glm::perspective(_fov, aspectRatio, _nearClipPlane, _farClipPlane);
}

float Camera::GetFOV()
{
	return glm::degrees(_fov);
}

void Camera::SetFOV(float angle)
{
	_fov = glm::radians(angle);
}

float Camera::GetNearClipPlane()
{
	return _nearClipPlane;
}

void Camera::SetNearClipPlane(float distance)
{
	_nearClipPlane = distance;
}

float Camera::GetFarClipPlane()
{
	return _farClipPlane;
}

void Camera::SetFarClipPlane(float distance)
{
	_farClipPlane = distance;
}
