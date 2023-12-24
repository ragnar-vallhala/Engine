#include "Renderer.h"



unsigned int Renderer::_activeVAO = 0;



Renderer::Renderer()
{
	glGenVertexArrays(1, &_VAO);
	BindVAO();
}


void Renderer::SetVBO(const float* data, int count)
{
	
	BindVAO();
	glGenBuffers(1, &_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*count, data, GL_STATIC_DRAW);
	_countOfVertices = count;
	_isVBOSet = true;
}

void Renderer::BindVAO()
{
	if (IsVAOBound())
		return;

	glBindVertexArray(_VAO);
	_activeVAO = _VAO;
}

bool Renderer::IsVAOBound()
{	
	return _activeVAO==_VAO;
}

void Renderer::SetAttribPointer(int attribIndex, int countOfValues, int stride, int offset)
{
	BindVAO();
	glVertexAttribPointer(attribIndex, countOfValues, GL_FLOAT, GL_FALSE, stride, (void*)offset);
	glEnableVertexAttribArray(attribIndex);
	_isVertexAttribPointerSet = true;
}

bool Renderer::IsVertexAttribPointerSet()
{
	return _isVertexAttribPointerSet;
}


void Renderer::LoadShaders(const char* VertexShaderPath, const char* FragmentShaderPath)
{
	_shader = new Shader(VertexShaderPath, FragmentShaderPath);
	_isShaderSet = true;
}


bool Renderer::IsVBOSet()
{
	return _isVBOSet;
}

void Renderer::Render(int first, int count)
{
	if (count == -1)
		count = _countOfVertices;

	BindVAO();
	if (!(IsVAOBound() && IsVertexAttribPointerSet() && IsVBOSet() && IsShaderSet())) {
		throw std::runtime_error("Renderer not set Properly");
		return;
	}
	_shader->useProgram();
	
	glDrawArrays(GL_TRIANGLES, first, count);
			
}

bool Renderer::IsShaderSet()
{
	return _isShaderSet;
}
