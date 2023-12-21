
#pragma once
#ifndef LAUNCH_H
#define LAUNCH_H
#include "EngineUtils.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "image.h"

class Launch {
public:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);      //adjusts images on resize
    static void processInput(GLFWwindow* window);          //handles inputs
    static void Run();
};

#endif