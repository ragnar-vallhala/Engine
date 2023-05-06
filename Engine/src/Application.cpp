#include "EngineUtils.h"





void framebuffer_size_callback(GLFWwindow* window, int width, int height);      //adjusts images on resize
void processInput(GLFWwindow* window);          //handles inputs



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



    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG("Failed to initialize GLAD");
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
   
    float vertices1[] = {
        -0.5,0.5,0,
        -1.0,-0.5,0,
        0,-0.5,0
    };
    float vertices2[]={
            // positions         // colors
          0.5f, 0.5f, 0.0f,  0.5f, 0.0f, 0.0f,   // bottom right
         1.0, -0.5f, 0.0f,  0.0f, 0.5f, 0.0f,   // bottom left
          0.0f,  -0.5f, 0.0f,  0.0f, 0.0f, 0.5f    // top 
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

   

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);



    Shader *s1 = new Shader( "../Engine/src/Shaders/vertex.glsl", "../Engine/src/Shaders/frag.glsl" );

    Shader *s2 = new Shader("../Engine/src/Shaders/vertex2.glsl", "../Engine/src/Shaders/frag2.glsl");


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (!glfwWindowShouldClose(window))
    {
        
        glClearColor(0.1f, 0.1f, 0.1f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        processInput(window);



        float t = (float)glfwGetTime();
        float r = (cos(t) + 1) / 2;
        float g = (float)(cos(t+1.57) + 1) / 2;
        float b = (sin(t) + 1) / 2;

#ifdef COLOR_OUT
        LOGL(r);
        LOGL(" ");
        LOGL(g);
        LOGL(" ");
        LOG(b);
#endif
        
        s1->useProgram();
        s1->setVec4("c", r, g, b, 1.0);

        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        s2->useProgram();
        s2->setVec1("tim", t);
        
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    delete s1;
    delete s2;

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