#include "Launch.h"

int windowWidth = 800;
int windowHeight = 600;

float vertices[] = {
    // positions          // normals           // texture coords
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
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
    myFirstObject._renderer.SetVBO(vertices, 6 * 6 * 8);
    myFirstObject._renderer.SetAttribPointer(0, 3, 8 * sizeof(float), 0);
    myFirstObject._renderer.SetAttribPointer(1, 3, 8 * sizeof(float), 3 * sizeof(float));
    myFirstObject._renderer.SetAttribPointer(2, 2, 8 * sizeof(float), 6 * sizeof(float));
    
    myFirstObject._renderer.BindVAO();
    unsigned int tex;
    glGenTextures(1, &tex);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    ImgData img = ImageLoader::getImage("../Engine/Resources/container.png");
    if (img.success) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "ERROR:: Can't load texture iamge"<< std::endl;
    }

    myFirstObject._renderer.LoadShaders("../Engine/src/Shaders/ObjectVert.glsl", "../Engine/src/Shaders/ObjectFrag.glsl");
    myFirstObject._renderer._shader->useProgram();
    glActiveTexture(GL_TEXTURE0);
    myFirstObject._renderer._shader->setBool("material.diffuseMap", 0);
    
    myFirstObject.MoveTo(glm::vec3(0.0, 0.0, -5.0));
    myFirstObject.RotateTo(glm::angleAxis(glm::radians(30.0f), glm::vec3(0.5, 1.0, 0.0)));

    glm::vec4 objectColor = glm::vec4(2.0f, 0.5f, 0.0f, 1.0f); //reflected


    Camera camera{};
    camera.MoveTo(glm::vec3(0, 0.0, 0.0));

    LightSource light{glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)}; //source
    light._renderer.SetVBO(vertices, 6 * 6 * 8);
    light._renderer.SetAttribPointer(0, 3, 8 * sizeof(float), 0);
    light._renderer.SetAttribPointer(1, 3, 8 * sizeof(float), 3 * sizeof(float));
    light._renderer.LoadShaders("../Engine/src/Shaders/LightSourceVert.glsl", "../Engine/src/Shaders/LightSourceFrag.glsl");
    light.MoveTo(glm::vec3(0.5, 0.0,-6.0));
    light.Scale((float)0.1);



    LightSource light1{ glm::vec4(0.0f, 0.0f, 1.0f, 1.0f) }; //source
    light1._renderer.SetVBO(vertices, 6 * 6 * 8);
    light1._renderer.SetAttribPointer(0, 3, 8 * sizeof(float), 0);
    light1._renderer.SetAttribPointer(1, 3, 8 * sizeof(float), 3 * sizeof(float));
    light1._renderer.LoadShaders("../Engine/src/Shaders/LightSourceVert.glsl", "../Engine/src/Shaders/LightSourceFrag.glsl");
    light1.MoveTo(glm::vec3(0.5, 0.0, -4.0));
    light1.Scale((float)0.1);

    //===========================================================================================================================
    // --------------------------------------------------------------------------------------------------------------------------
    //===========================================================================================================================



    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        processInput(window);

        
        

        glm::mat4 lightRotation = glm::mat4(1.0f);
        lightRotation = glm::translate(lightRotation, myFirstObject.GetPosition());
        lightRotation = lightRotation *  glm::toMat4(glm::angleAxis(glm::radians((float)glfwGetTime() * 30), glm::vec3(0.0, 1.0, 0.0)));
        lightRotation = glm::translate(lightRotation, -myFirstObject.GetPosition());

        light._renderer._shader->useProgram();
        light._renderer._shader->setMat4("view",                        lightRotation);
        light._renderer._shader->setMat4("projection",                  camera.GetPerspectiveMatrix((float)windowWidth / (float)windowHeight));
        light._renderer._shader->setMat4("transformation",              light.ModelMatrix());
        light._renderer._shader->setVec4("lightColor",                  light.GetColor());
        light._renderer.Render();



        glm::mat4 lightRotation1 = glm::mat4(1.0f);
        lightRotation1 = glm::translate(lightRotation1, myFirstObject.GetPosition());
        lightRotation1 = lightRotation1 * glm::toMat4(glm::angleAxis(glm::radians((float)glfwGetTime() * 30), glm::vec3(0.0, 1.0, 0.0)));
        lightRotation1 = glm::translate(lightRotation1, -myFirstObject.GetPosition());

        light1._renderer._shader->useProgram();
        light1._renderer._shader->setMat4("view",                       lightRotation1);
        light1._renderer._shader->setMat4("projection",                 camera.GetPerspectiveMatrix((float)windowWidth / (float)windowHeight));
        light1._renderer._shader->setMat4("transformation",             light1.ModelMatrix());
        light1._renderer._shader->setVec4("lightColor",                 light1.GetColor());
        light1._renderer.Render();

constexpr auto TAU = 6.28318530718;
constexpr auto f1  = 0.5;
constexpr auto f2  = 0.3;
constexpr auto f3  = 0.2;
constexpr auto f4  = 0.6;


        glm::vec4 light1Color = glm::vec4(glm::sin(glfwGetTime() * f1 * TAU) * 0.5 + 0.5, glm::cos(glfwGetTime() * f2 * TAU) * 0.5 + 0.5, 0.3f, 1.0f);
        glm::vec4 light2Color = glm::vec4(glm::cos(glfwGetTime() * f3 * TAU) * 0.5 + 0.5, glm::sin(glfwGetTime() * f4 * TAU) * 0.5 + 0.5, 0.4f, 1.0f);
        /*light.SetColor(light1Color);
        light1.SetColor(light2Color);*/


        myFirstObject._renderer._shader->useProgram();
        myFirstObject.RotateTo(glm::toMat4(glm::angleAxis(glm::radians((float)glfwGetTime()*18), glm::normalize(glm::vec3(-1.0, -1.0, 1.0)))));
        
        
        myFirstObject._renderer._shader->setMat4("view",                glm::mat4(1.0f));
        myFirstObject._renderer._shader->setMat4("projection",          camera.GetPerspectiveMatrix((float)windowWidth / (float)windowHeight));
        myFirstObject._renderer._shader->setMat4("transformation",      myFirstObject.ModelMatrix());

        
        myFirstObject._renderer._shader->setVec4("material.specular",   objectColor);
        myFirstObject._renderer._shader->setVec1("material.shininess",  1.0f);
        myFirstObject._renderer._shader->setVec1("material.brightness", 0.3f);


        myFirstObject._renderer._shader->setVec4("lightColor",          light.GetColor());
        myFirstObject._renderer._shader->setVec4("lightPosition",       lightRotation * light.ModelMatrix()  * glm::vec4(light.GetPosition(), 1.0f));
        myFirstObject._renderer._shader->setVec4("lightColor1",         light1.GetColor());
        myFirstObject._renderer._shader->setVec4("lightPosition1",      lightRotation1 * light1.ModelMatrix() * glm::vec4(light1.GetPosition(), 1.0f));
        myFirstObject._renderer._shader->setVec4("cameraPos",           glm::vec4(camera.GetPosition(),1.0));
        myFirstObject._renderer.Render();

        



        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    glfwTerminate();

}
