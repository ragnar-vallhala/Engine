#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>






#if 0
//#define COLOR_OUT			//Logs color for the triangle
#define TEST_LOG			//Logs the shader code read from files
#define LOG(x) std::cout<<x<<std::endl;
#define LOGL(x) std::cout<<x;
#else
#define LOG(x)
#define LOGL(x)
#endif



void readFile(const char* path, std::string &str);