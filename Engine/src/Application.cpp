#include "EngineUtils.h"





void framebuffer_size_callback(GLFWwindow* window, int width, int height);      //adjusts images on resize
void processInput(GLFWwindow* window);          //handles inputs
void getFloat(float& val);


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
            // positions         // colors      //texture
          0.0f, 1.0f, 0.0f,  0.5f, 0.0f, 0.0f, 0.5f, 0.0f,  // bottom right
         -1.0,-1.0f, 0.0f,  0.0f, 0.5f, 0.0f,  0.0,1.0f, // bottom left
          1.0f,  -1.0f, 0.0f,  0.0f, 0.0f, 0.5f, 1.0f,  1.0f   // top 
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

   

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);



    Shader *s1 = new Shader( "../Engine/src/Shaders/vertex.glsl", "../Engine/src/Shaders/frag.glsl" );

    Shader *s2 = new Shader("../Engine/src/Shaders/vertex2.glsl", "../Engine/src/Shaders/frag2.glsl");
    //LOG("-------------------------------------------");
    float offx{}, offy{};
    /*LOG("Keep offsets from -0.5 to 0.5");
    LOG("GIVE OFFSET X ::  ");
    std::cin >> offx;
    LOG("\nGIVE OFFSET Y ::  ");
    std::cin >> offy;*/


    //Surely work on it soon 
    /* std::thread obj(getFloat, &offx);
    obj.join();
    std::thread obj1(getFloat, &offy);
    obj1.join();*/



    //Tex image parts below
    int width, height, nrChannels;
    unsigned char* data = stbi_load("../Engine/resources/crackGround.jpg", &width, &height, &nrChannels, 0);
    //generate texture
    unsigned int texture;
    if (data) {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
    }
    else {
        LOG("ERROR:: CAN'T LOAD TEXTURE");
    }
    
    

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
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        s2->useProgram();
        s2->setVec1("tim", t);
        
        s2->setVec1("offsetx", offx);
        
        s2->setVec1("offsety", offy);
        //glBindTexture(GL_TEXTURE_2D, texture);
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


void getFloat(float& val) {
    std::cin >> val;
    return;
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