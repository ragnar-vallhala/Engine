#include "Launch.h"

int windowWidth = 800;
int windowHeight = 600;


const float vertices[] 
{
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};


glm::vec3 lightSourcePosition{ 1.0f, 1.0f, 1.0f };
glm::vec4 lightColor{ 1.0f, 1.0f, 1.0f,1.0f };
glm::vec3 objectPosition{ 0.0f, 0.0f, 0.0f};
glm::mat4 viewMatrix(1.0f);
glm::mat4 projectionMatrix(1.0f);
glm::mat4 transformationMatrix(1.0f);




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
    myFirstObject._renderer.SetVBO(vertices, 6 * 6 * 5);
    myFirstObject._renderer.SetAttribPointer(0, 3, 5 * sizeof(float), 0);
    myFirstObject._renderer.SetAttribPointer(1, 2, 5 * sizeof(float), 3 * sizeof(float));
    myFirstObject._renderer.LoadShaders("../Engine/src/Shaders/LightSourceVert.glsl", "../Engine/src/Shaders/LightSourceFrag.glsl");
    myFirstObject.MoveTo(glm::vec3(0, 0, -3.2));

    Camera camera{};
    camera.MoveTo(glm::vec3(0, 0, 3.2));

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
        myFirstObject._renderer._shader->setVec4("color", lightColor);
        myFirstObject._renderer.Render();
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    glfwTerminate();

}
