#pragma once


#include <glm/glm.hpp>


class Camera
{
private:
	// Position of the camera
	double x_pos;
	double y_pos;
	double z_pos;

	// Angle of the camera
	double theta;
	double rho;

	// Angle of the field of view
	double fov;

	// Aspect ratio of the field of view
	double aspect;

public:
	Camera(glm::vec3 pos, double aspect);

	glm::mat4 getViewMat();

	glm::mat4 getProjectionMat();

	glm::vec3 getCameraPos();

	void cursor_pos_callback(GLFWwindow * window, double x_pos, double y_pos);

	void window_size_callback(int width, int height);
};