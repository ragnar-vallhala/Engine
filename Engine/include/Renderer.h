#pragma once

#include "shader.h"
#include "EngineUtils.h"

class Renderer {
private:
	unsigned int _VAO;
	unsigned int _VBO;
	int _countOfVertices = 0;
	
	
	bool _isVBOSet = false;
	bool _isShaderSet = false;
	bool _isVertexAttribPointerSet = false;

	static unsigned int _activeVAO;
	
public:
	//variables
	Shader *_shader = nullptr;


	//functions

	//creates Vertex Array Object and Binds it
	Renderer();

	//Creates Vertex Buffer attribute and binds data to it
	void SetVBO(const float*,int);

	//Binds the VAO
	void BindVAO();

	//Checks is VAO is bound
	bool IsVAOBound();
	bool IsVertexAttribPointerSet();
	bool IsVBOSet();
	bool IsShaderSet();
	

	void SetAttribPointer(int attribIndex, int countOfValues, int stride, int offset);
	
	void LoadShaders(const char* VertexShaderPath, const char* FragmentShaderPath);

	//default count -1 means all the vertices are rendered
	void Render(int first = 0, int count = -1);

};