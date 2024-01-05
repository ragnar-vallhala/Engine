#include "Launch.h"

glm::mat4 view = glm::mat4(1.0f);
glm::mat4 look = glm::mat4(1.0f);

void Launch::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Launch::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, true);


    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        UpdateViewMatrix(&view, FRONT, 0.01);
    }
        
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        UpdateViewMatrix(&view, BACK, 0.01);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        UpdateViewMatrix(&view, LEFT, 0.01);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        UpdateViewMatrix(&view, RIGHT, 0.01);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        UpdateViewMatrix(&view, DOWN, 0.01);
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        UpdateViewMatrix(&view, UP, 0.01);
    }
}


//Tobe removed
void GetCubePos(int  num, std::vector<glm::vec3>* positions);

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

    ImgData icon = ImageLoader::getImage("../Engine/Resources/nb.jpg");
    if (icon.success) {
        glfwSetWindowIcon(window, 1, (GLFWimage*)icon.data);
    }
    else {
        std::cout << "Can't Load Image" << std::endl;
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
    
    /*glm::vec3 axis(1.0, 1.0, 1.0);
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, -3.0f));*/

    glEnable(GL_DEPTH_TEST);
    /*
            /////////////////////////////////////////////////////////////////////////
    */
#define TAU 6.28318530718


    int windowHeight;
    int windowWidth;

    std::vector<glm::vec3> positions;
    int numCubes = 100;
    GetCubePos(numCubes, &positions);
    

    std::vector<glm::vec3> axis{glm::vec3(1.0,0.0,0.0), glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 0.0, 1.0),
                                glm::vec3(1.0, 1.0, 0.0), glm::vec3(1.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 1.0), 
                                glm::vec3(1.0, 1.0, 1.0), };


    int time = 0;
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    







    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.1f, 0.1f, 0.1f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        processInput(window);

        
       /* if (glfwGetTime() - time > 2) {
            GetCubePos(numCubes, &positions);
            time = glfwGetTime();
        }*/
        
        
        
        for (int i{}; i < numCubes; i++) {
            s->useProgram();
            glfwGetWindowSize(window, &windowWidth, &windowHeight);
            glm::mat4 projection = glm::perspective(glm::radians(45.0f), ((float)windowWidth) / ((float)windowHeight), 0.1f, 100.0f);
            s->setMat4("projection", projection);
            glm::mat4 translation = glm::mat4(1.0f);
            translation = glm::translate(translation, positions[i]);
    
            glm::mat4  rotation = glm::mat4(1.0f);
            rotation = glm::rotate(rotation, glm::radians((float)glfwGetTime() * 10.0f), axis[i % 7]);
            s->setMat4("transform", view * translation * rotation);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        
        
        
        
        
        //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    glfwTerminate();

}

glm::vec3 Launch::GetrandomPosition(glm::vec3 min, glm::vec3 max)
{
    float x = (min.x - max.x) * 100;
    float y = (min.y - max.y) * 100;
    float z = (min.z - max.z) * 100;


    float numx, numy, numz;

    if (x != 0)
        numx = rand() % ((int)x);
    else
        numx = 0.0;
    
    if (y != 0)
        numy = rand() % ((int)y);
    else
        numy = 0.0;

    if (z != 0)
        numz = rand() % ((int)z);
    else
        numz = 0.0;

    glm::vec3 result = glm::vec3(numx, numy, numz);
    result /= 100;
    result += min;
    
    return result;
}
void GetCubePos(int  num ,std::vector<glm::vec3>* positions) {
    positions->clear();

    for (int i{}; i < num; i++) {
        positions->push_back(Launch::GetrandomPosition(glm::vec3(-20.0, -20.0, -60.0), glm::vec3(10.0, 10.0, -5.0)));
    }

}


void Launch::UpdateViewMatrix(glm::mat4* view, INPUT input, float translationSpeed, float rotationSpeed)
{

    switch (input) {
    case FRONT:
        *view = glm::translate(*view, glm::vec3(0.0, 0.0, 1.0) * translationSpeed);
        break;
    case LEFT:
        *view = glm::translate(*view, glm::vec3(1.0, 0.0, 0.0) * translationSpeed);
        break;
    case RIGHT:
        *view = glm::translate(*view, glm::vec3(-1.0, 0.0, 0.0) * translationSpeed);
        break;
    case BACK:
        *view = glm::translate(*view, glm::vec3(0.0, 0.0, -1.0) * translationSpeed);
        break;
    case UP:
        *view = glm::translate(*view, glm::vec3(0.0, -1.0, 0.0) * translationSpeed);
        break;
    case DOWN:
        *view = glm::translate(*view, glm::vec3(0.0, 1.0, 0.0) * translationSpeed);
        break;
    default:
        return;
    }
}