#pragma once


#include <GLFW/glfw3.h>

#include "Model.hpp"


class Control
{
public:
    // Window to be controlled
    static GLFWwindow * window;

    // Label of whether the mouse button is pressed
    static bool is_mouse_button_left_pressed;
    static bool is_mouse_button_right_pressed;
    static bool is_mouse_button_middle_pressed;

    // Models to be controlled
    static Model * models[];
    static int model_index;


    // Set the model to be controlled
    static void setModel(Model * model, int index);

    // Key callback
    static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);

    // Mouse button callback
    static void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
};