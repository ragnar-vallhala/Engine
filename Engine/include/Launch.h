#pragma once
#ifndef LAUNCH_H
#define LAUNCH_H
#include "EngineUtils.h"
#include "shader.h"
#include "image.h"
#include "Entity.h"
#include "Camera.h"
#include "LightSource.h"
class Launch {

public:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);      //adjusts images on resize
    static void processInput(GLFWwindow* window);          //handles inputs
    static void Run();
};

#endif