#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>





#if 1
#define TEST_LOG			//Logs the shader code read from files
#define LOG(x) std::cout<<x<<std::endl;
#define LOGL(x) std::cout<<x;
#else
#define LOG(x)
#define LOGL(x)
#endif


void readFile(const char* path, std::string &str);


struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 uv;
};

struct Texture {
	unsigned int ID;
	std::string type;
};


