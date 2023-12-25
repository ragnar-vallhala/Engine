#include "Launch.h"

int windowWidth = 800;
int windowHeight = 600;


float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};



void Launch::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    windowHeight = height;
    windowWidth = width;
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

   
    //===========================================================================================================================
    // --------------------------------------------------------------------------------------------------------------------------
    //===========================================================================================================================


    Entity myFirstObject{};
    myFirstObject._renderer.SetVBO(vertices, 6 * 6 * 6);
    myFirstObject._renderer.SetAttribPointer(0, 3, 6 * sizeof(float), 0);
    myFirstObject._renderer.SetAttribPointer(1, 3, 6 * sizeof(float), 3 * sizeof(float));
    myFirstObject._renderer.LoadShaders("../Engine/src/Shaders/ObjectVert.glsl", "../Engine/src/Shaders/ObjectFrag.glsl");
    myFirstObject.MoveTo(glm::vec3(0, 0, -3.2));

    glm::vec4 objectColor = glm::vec4(0.5f, 0.5f, 0.0f, 1.0f); //reflected


    Camera camera{};
    camera.MoveTo(glm::vec3(0, 0.0, 3.2));

    LightSource light{glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)}; //source
    light._renderer.SetVBO(vertices, 6 * 6 * 6);
    light._renderer.SetAttribPointer(0, 3, 6 * sizeof(float), 0);
    light._renderer.SetAttribPointer(1, 3, 6 * sizeof(float), 3 * sizeof(float));
    light._renderer.LoadShaders("../Engine/src/Shaders/LightSourceVert.glsl", "../Engine/src/Shaders/LightSourceFrag.glsl");
    light.MoveTo(glm::vec3(3.0, 2.0, -8.2));

    //===========================================================================================================================
    // --------------------------------------------------------------------------------------------------------------------------
    //===========================================================================================================================


    


    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.1f, 0.1f, 0.1f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        processInput(window);

        
        myFirstObject.RotateTo(glm::angleAxis(glm::radians((float)glfwGetTime()*90),glm::vec3(0.5,1.0,0.0)));
        myFirstObject._renderer._shader->useProgram();
        myFirstObject._renderer._shader->setMat4("view", glm::mat4(1.0f));
        myFirstObject._renderer._shader->setMat4("projection", camera.GetPerspectiveMatrix((float)windowWidth/(float)windowHeight));
        myFirstObject._renderer._shader->setMat4("transformation", myFirstObject.ModelMatrix());
        myFirstObject._renderer._shader->setVec4("color", objectColor);
        myFirstObject._renderer._shader->setVec4("lightColor", light.GetColor());
        myFirstObject._renderer.Render();
        

        light._renderer._shader->useProgram();
        light._renderer._shader->setMat4("view", glm::mat4(1.0f));
        light._renderer._shader->setMat4("projection", camera.GetPerspectiveMatrix((float)windowWidth / (float)windowHeight));
        light._renderer._shader->setMat4("transformation", light.ModelMatrix());
        light._renderer._shader->setVec4("lightColor", light.GetColor());
        light._renderer.Render();




        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    glfwTerminate();

}
