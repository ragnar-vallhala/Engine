#include "shader.h"


Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{	
	std::string vert{}, frag{};
	readFile(vertexShaderPath, vert);
	readFile(fragmentShaderPath, frag);
	const char* vertexShaderCode = vert.c_str();
	const char* fragmentShaderCode = frag.c_str();

	int success;			//get status of processes
	char* infoLog = new char[512];		//get the info in case of error


	//Creating and compiling the vertex shader
	unsigned int vertexID, fragmentID;
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexID);
	glGetShaderiv(vertexID,GL_COMPILE_STATUS,&success);

	//LOGGING in case of compilation failure
	if (!success) {
		glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
		LOG("ERROR:: COMPILATION OF SHADER FAILED "+ (std::string)vertexShaderPath)
	}

	//Creating and compiling the fragment shader
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentID);    
	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
		LOG("ERROR:: COMPILATION OF SHADER FAILED " + (std::string)fragmentShaderPath);
	}

	//Creating the shader program and attching shaders to it
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexID);
	glAttachShader(m_ID, fragmentID);
	glLinkProgram(m_ID);

	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
		LOG("ERROR:: LINKING OF PROGRAM FAILED " + (std::string)fragmentShaderPath + " & " + (std::string)vertexShaderPath);
	}
	

	//free the resources
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
	delete[] infoLog;
}

void Shader::useProgram()
{
	glUseProgram(m_ID);
}

Shader::~Shader()
{
	
	glDeleteProgram(m_ID);
	
}

void Shader::setBool(const char* variable, int value)
{	
	int uniformLocation = glGetUniformLocation(m_ID, variable);
	glUniform1i(uniformLocation, value);
}

void Shader::setVec1(const char* variable, float value)
{
	int uniformLocation = glGetUniformLocation(m_ID, variable);
	glUniform1f(uniformLocation, value);
}

void Shader::setVec4(const char* variable, float x, float y, float z, float w)
{
	int uniformLocation = glGetUniformLocation(m_ID, variable);
	glUniform4f(uniformLocation, x,y,z,w);
}

void Shader::setVec4(const char* variable, glm::vec4 vector)
{
	int uniformLocation = glGetUniformLocation(m_ID, variable);
	glUniform4f(uniformLocation, vector.x, vector.y, vector.z, vector.w);
}

void Shader::setMat4(const char* variable, glm::mat4 mat)
{
	int uniformLocation = glGetUniformLocation(m_ID, variable);
	glUniformMatrix4fv(uniformLocation,1,GL_FALSE, glm::value_ptr(mat));
	
}
