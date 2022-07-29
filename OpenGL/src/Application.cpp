// Include GLEW
#pragma once
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <iostream>

#include "Debug.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
//#include "Renderer.h"
#include "Texture.h"
#include "VertexBufferLayout.h"
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include <Windows.h>
#include <chrono>
#include <random>
#include <math.h>
#include <fstream>
#include "Text.h"
#include "Board.h"
#include "RenderItem.h"
#include "globals.cpp"
#include "CreateGame.h"
#include "Networking/Networking.h"
/*
data to jSON to server to client to data to baord
*/



GLFWwindow* InitWindow()
{
    // Initialise GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return nullptr;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window = glfwCreateWindow(Windowx, Windowy, "NameNoWindowWillUse", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return nullptr;

    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return nullptr;
    }

    std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    return window;
}


int main(void)
{

    GLFWwindow* window = InitWindow();
    if (!window)
        return -1;
    srand(time(NULL));
    HWND hWnd_Console = GetConsoleWindow();

    MoveWindow(hWnd_Console, 0, 0, 700, 400, TRUE);

    HWND hWnd_Game = FindWindowA(NULL, "NameNoWindowWillUse");
    POINT p;


    MoveWindow(hWnd_Game, 0, -25, Windowx, Windowy + 56, TRUE);
    ShowWindow(hWnd_Game, SHOW_FULLSCREEN);
    {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


        Renderer renderer;

        glfwSwapInterval(1);
        glfwWindowHint(GLFW_SAMPLES, 16);
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glDepthFunc(GL_LEQUAL);
        glDepthRange(0.0f, 1.0f);

        Board BoardMain(glm::vec4(0.1f, 0.3f, 0.7f, 1.0f), glm::vec4(0.3f, 0.2f, 1.0f, 1.0f));

        CreateGame Game;

        /*
        RenderItem Peice("res/shaders/Peice.shader", "res/textures/50.PNG");

        /*
                    std::vector<float> k = {
                +((Windowx / 8.0f) / Windowx) - (1.0f - (((Windowx / 8.0f) / Windowx)) - (i * (Windowx / 4.0f) / Windowx)), -((Windowy / 8.0f) / Windowy) - (1.0f - (((Windowy / 8.0f) / Windowy)) - (j * (Windowx / 4.0f) / Windowx)), 0.0f, 0.0f, colourR, colourG, colourB, colourA,
                +((Windowx / 8.0f) / Windowx) - (1.0f - (((Windowx / 8.0f) / Windowx)) - (i * (Windowx / 4.0f) / Windowx)), +((Windowy / 8.0f) / Windowy) - (1.0f - (((Windowy / 8.0f) / Windowy)) - (j * (Windowx / 4.0f) / Windowx)), 1.0f, 0.0f, colourR, colourG, colourB, colourA,
                -((Windowx / 8.0f) / Windowx) - (1.0f - (((Windowx / 8.0f) / Windowx)) - (i * (Windowx / 4.0f) / Windowx)), +((Windowy / 8.0f) / Windowy) - (1.0f - (((Windowy / 8.0f) / Windowy)) - (j * (Windowx / 4.0f) / Windowx)), 1.0f, 1.0f, colourR, colourG, colourB, colourA,
                -((Windowx / 8.0f) / Windowx) - (1.0f - (((Windowx / 8.0f) / Windowx)) - (i * (Windowx / 4.0f) / Windowx)), -((Windowy / 8.0f) / Windowy) - (1.0f - (((Windowy / 8.0f) / Windowy)) - (j * (Windowx / 4.0f) / Windowx)), 0.0f, 1.0f, colourR, colourG, colourB, colourA
         };
         
        std::vector<float> CubeData;
        std::vector<unsigned int> Floats = { 2, 2, 4 };
        float colourR = 0.0f;
        float colourG = 0.0f;
        float colourB = 0.0f;
        float colourA = 0.0f;
        int i = 0;
        int j = 0;
        CubeData = {
            +XCoordData, -YCoordData, 0.0f, 0.0f, colourR, colourG, colourB, colourA,
            +XCoordData, +YCoordData, 1.0f, 0.0f, colourR, colourG, colourB, colourA,
            -XCoordData, +YCoordData, 1.0f, 1.0f, colourR, colourG, colourB, colourA,
            -XCoordData, -YCoordData, 0.0f, 1.0f, colourR, colourG, colourB, colourA
        };

        Peice.AddData(CubeData, Floats);*/

        Networking NetworkingMain;



        do {
            //MoveWindow(hWnd_Game, 0, -25, Windowx, Windowy, TRUE);
            GLCall(glClearColor(0.0f/ 255.0f, 162.0f / 255.0f, 219.0f / 255.0f, 1.0f));
            glClearDepth(1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            renderer.Clear();

            BoardMain.RenderBoard();
            Game.Main();
            NetworkingMain.CreateJSON(Game.Pieces);
            // Swap buffers
            glfwSwapBuffers(window);
            glfwPollEvents();

        } // Check if the ESC key was pressed or the window was closed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    }

    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    return 0;
}

