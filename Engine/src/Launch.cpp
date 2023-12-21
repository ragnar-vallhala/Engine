#include "Launch.h"



void Launch::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Launch::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}



void Launch::Run() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ashutosh", NULL, NULL);

    if (window == NULL) {
        LOGL("Failed to open");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);



    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOGL("Failed to initialize GLAD");
        return;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.1f, 0.1f, 0.1f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        processInput(window);



        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    glfwTerminate();

}

