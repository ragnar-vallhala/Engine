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

   
    /*
            /////////////////////////////////////////////////////////////////////////
    */



    float vertices[] = {
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

    //float vertices[] = {
    //    -0.5,  0.5,  0.0,   0.0, 1.0,
    //     0.5,  0.5,  0.0,   1.0, 1.0,
    //     0.5, -0.5,  0.0,   1.0, 0.0,
    //    -0.5, -0.5,  0.0,   0.0, 0.0,
    //                        
    //    -0.5, -0.5, -1.0,   0.0, 0.0,
    //    -0.5,  0.5, -1.0,   0.0, 1.0,
    //     0.5,  0.5, -1.0,   1.0, 1.0,
    //     0.5, -0.5, -1.0,   1.0, 0.0
    //    
    //};

    //int indices[] = {
    //    // front face
    //     0, 1, 3,
    //     1, 2, 3,


    //     // top face
    //     0, 1, 5,
    //     1, 5, 6,

    //     // right face
    //     1, 2, 6,
    //     2, 6, 7,

    //     // left face
    //     0, 3, 4,
    //     3, 4, 7,

    //     // back face
    //     5, 6, 7,
    //     4, 5, 7,

    //     // bottom face
    //     2, 3, 7,
    //     2, 6, 7
    //};

    //float vertices[] = {
    //    // Front face
    //    -0.5,  0.5,  0.0,   0.0, 1.0,
    //     0.5,  0.5,  0.0,   1.0, 1.0,
    //     0.5, -0.5,  0.0,   1.0, 0.0,
    //    -0.5, -0.5,  0.0,   0.0, 0.0,

    //    // Back face
    //    -0.5, -0.5, -1.0,   0.0, 0.0,
    //    -0.5,  0.5, -1.0,   0.0, 1.0,
    //     0.5,  0.5, -1.0,   1.0, 1.0,
    //     0.5, -0.5, -1.0,   1.0, 0.0
    //};

    //int indices[] = {
    //    // Front face
    //    0, 1, 3,
    //    1, 2, 3,

    //    // Top face
    //    0, 1, 5,
    //    1, 5, 6,

    //    // Right face
    //    1, 2, 6,
    //    2, 6, 7,

    //    // Left face
    //    0, 3, 4,
    //    3, 4, 7,

    //    // Back face
    //    5, 6, 7,
    //    4, 5, 7,

    //    // Bottom face
    //    2, 3, 7,
    //    2, 6, 7
    //};


    /*float vertices[] = {
         0.0,  0.5, 0.0,
         0.5, -0.5, 0.0,
        -0.5, -0.5, 0.0
    };

    unsigned int indices[] = {
        0, 1, 2
    };*/

    

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    /*glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

    Shader *s = new Shader("../Engine/src/Shaders/vertex.glsl", "../Engine/src/Shaders/frag.glsl");

    unsigned int texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    ImgData img = ImageLoader::getImage("../Engine/Resources/a.jpeg");
    if (img.success) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width, img.height, 0, GL_RGB, GL_UNSIGNED_BYTE, img.data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Couldn't load image" << std::endl;
    }


    //transformation
    
    glm::vec3 axis(1.0, 1.0, 1.0);
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, -3.0f));

    glEnable(GL_DEPTH_TEST);
    /*
            /////////////////////////////////////////////////////////////////////////
    */
#define TAU 6.28318530718


    int windowHeight;
    int windowWidth;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.1f, 0.1f, 0.1f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        processInput(window);

        s->useProgram();

        glm::mat4 rotation = glm::mat4(1.0);
        rotation = glm::rotate(rotation, glm::radians(
           90.0f * (float)(glfwGetTime() * 0.25)
        ), axis);

        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        s->setMat4("transform", transform * rotation);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), ((float)windowWidth)/((float)windowHeight), 0.1f, 100.0f);
        s->setMat4("projection", projection);
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    glfwTerminate();

}

