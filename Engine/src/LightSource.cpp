#include "LightSource.h"

LightSource::LightSource(): _color{glm::vec4(1.0,1.0,1.0,1.0)}
{
}

LightSource::LightSource(glm::vec4 color): _color(color)
{
}

glm::vec4 LightSource::GetColor()
{
	return _color;
}

void LightSource::SetColor(glm::vec4 color)
{
	_color = color;
}
