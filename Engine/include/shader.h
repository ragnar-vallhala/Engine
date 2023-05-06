#pragma once

class Shader
{

public:
	unsigned int m_ID = 0; //id of the program associated

	/*Creates shader program from the file path of the shader source*/
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);

	
	/*Runs the shader program*/
	void useProgram();


	/*Destructor*/
	~Shader();


	
	/*Update uniform bool*/
	void setBool(  const char* variable, int value);


	/*Update uniform vec1*/
	void setVec1(const char* variable, float value);

	/*Update uniform vec4*/
	void setVec4(const char* variable, float x, float y, float z, float w);



};

