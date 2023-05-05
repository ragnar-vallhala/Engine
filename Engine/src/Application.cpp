#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include "shader.h"


#if 1
#define LOG(x) std::cout<<x<<std::endl;
#else
#define LOG(x)
#endif




/*
Function to load files
@param path: char array to the path of file
@param str: string reference to get the output[
*/
void loadFile(const char* path, std::string& str) {
    std::ifstream in;
    in.open(path);

    if (!in.is_open()) {
        LOG("Failed to open " + (std::string)path);
        return;
    }
    str = "";
    while (!in.eof()) {
        char temp[500];
        in.getline(temp, 500);
        str += (std::string)temp + '\n';
    }
    str += '\0';
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height);      //adjusts images on resize
void processInput(GLFWwindow* window);          //handles inputs


const char* vertexShaderSource;
const char* fragmentShaderSource;


void shaderInit(const char* vs,  const char* fs) {
    std::string str="";
    loadFile(vs, str);
    vertexShaderSource = str.c_str();
    std::string str1 = "";
    loadFile(fs, str1);
    fragmentShaderSource = str1.c_str();
    LOG(vertexShaderSource);
    LOG(fragmentShaderSource);
    
}



int main()
{   
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ashutosh", NULL, NULL);

    if (window == NULL) {
        LOG("Failed to open");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);


    shaderInit("../Engine/src/Shaders/vertex.glsl", "../Engine/src/Shaders/frag.glsl");


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG("Failed to initialize GLAD");
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
   
    float vertices1[] = {
        -0.5,0.5,0,
        -1,-0.5,0,
        0,-0.5,0
    };
    float vertices2[]={
        0,-0.5,0,
        0.5,0.5,0,
        1,-0.5,0
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 2,   // first triangle
        2, 3, 4  // second triangle
    };

    unsigned int VAOs[2], VBOs[2];
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);




    
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

   

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    

    //Creasting a vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    //Logging if vertex shader compilation fails
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LOG("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
        LOG(infoLog);
    }

    //Creating fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    //in case the fragment dhader compilation fails
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        LOG("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
    }

    //linking the shaders
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();


    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        LOG("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
        LOG(infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    shaderInit("../Engine/src/Shaders/vertex.glsl", "../Engine/src/Shaders/frag2.glsl");

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LOG("ERROR::VERTEXSHADER::2::COMPILATION FAILED");
        LOG(infoLog);
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        LOG("ERROR::FRAGMENT SHADER2 COMPILATION FAILED");
        LOG(infoLog);
    }

    unsigned int shaderProgram1;
    shaderProgram1 = glCreateProgram();
    glAttachShader(shaderProgram1, vertexShader);
    glAttachShader(shaderProgram1, fragmentShader);
    glLinkProgram(shaderProgram1);

    glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
        LOG("ERROR::LINKING PROGRAM1 FAILED");
        LOG(infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (!glfwWindowShouldClose(window))
    {
        clock_t t = clock();
        glClearColor(0.1f, 0.1f, 0.1f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        processInput(window);


        glUseProgram(shaderProgram);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glUseProgram(shaderProgram1);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        t = clock() - t;
        //LOG(((float)CLOCKS_PER_SEC)/t);
        
    }

    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteProgram(shaderProgram);

    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}