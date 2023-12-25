#pragma once
#include "Entity.h"
#include "EngineUtils.h"


class LightSource : public Entity {
private:
	glm::vec4 _color;
	

public:

	Renderer _renderer{};

	LightSource();
	LightSource(glm::vec4);

	glm::vec4 GetColor();
	void SetColor(glm::vec4);

};

