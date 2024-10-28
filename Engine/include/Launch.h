
#pragma once
#ifndef LAUNCH_H
#define LAUNCH_H
#include "EngineUtils.h"
#include "shader.h"
#include "image.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
class Launch {
private:
    typedef enum INPUT {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        FRONT,
        BACK
    }INPUT;


public:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);      //adjusts images on resize
    static void processInput(GLFWwindow* window);          //handles inputs
    static void Run();
    static glm::vec3 GetrandomPosition(glm::vec3 min, glm::vec3 max);
    static void UpdateViewMatrix(glm::mat4* view, INPUT input, float translationSpeed = 1.0f, float rotationSpeed = 1.0f);
};

#endif
