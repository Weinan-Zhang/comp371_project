#pragma once

#include <vector>
#include <unordered_map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

using std::vector;

class Utils {
public:
	static vector<GLdouble> getNormalForVertex(vector<GLdouble> pos_data, vector<GLuint> index_data) {
		std::vector<glm::vec3> verticesNormal;
		std::vector<GLdouble> norm_data;
		verticesNormal.resize((int)(pos_data.size() / 3));


		for (int i = 0; i < index_data.size(); i += 3)
		{
			// Organize vertex position data from pos_data vectors
			glm::vec3 curVertex = glm::vec3(pos_data[index_data[i] * 3], pos_data[index_data[i] * 3 + 1], pos_data[index_data[i] * 3 + 2]);
			glm::vec3 firstNextVertex = glm::vec3(pos_data[index_data[i + 1] * 3], pos_data[index_data[i + 1] * 3 + 1], pos_data[index_data[i + 1] * 3 + 2]);
			glm::vec3 secondNextVertex = glm::vec3(pos_data[index_data[i + 2] * 3], pos_data[index_data[i + 2] * 3 + 1], pos_data[index_data[i + 2] * 3 + 2]);
			// Get the face normal
			glm::vec3 vector1 = firstNextVertex - curVertex;
			glm::vec3 vector2 = secondNextVertex - curVertex;
			glm::vec3 faceNormal = glm::cross(vector1, vector2);
			

			// Add the face normal to the 3 vertices normal touching this face
			verticesNormal[index_data[i]] += faceNormal;
			verticesNormal[index_data[i + 1]] += faceNormal;
			verticesNormal[index_data[i + 2]] += faceNormal;
		}
		
		// Normalize vertices normal
		for (int i = 0; i < verticesNormal.size(); i++) {
			if (!(verticesNormal[i].x == 0 && verticesNormal[i].y == 0 && verticesNormal[i].z == 0)) {
				verticesNormal[i] = glm::normalize(verticesNormal[i]);
			}
		}
			
		// Generate vertices normal data vector
		for (glm::vec3 vertex : verticesNormal) {
			norm_data.push_back(vertex.x);
			norm_data.push_back(vertex.y);
			norm_data.push_back(vertex.z);
		}
		return norm_data;
	}

	static vector<GLdouble> getNormalForVertex(vector<GLdouble> pos_data) {
		std::unordered_map<string, glm::vec3> verticesNormal;
		std::vector<GLdouble> norm_data;

		for (int i = 0; i < pos_data.size(); i += 9)
		{
			// Organize vertex position data from pos_data vectors
			glm::vec3 curVertex = glm::vec3(pos_data[i], pos_data[i + 1], pos_data[i + 2]);
			glm::vec3 firstNextVertex = glm::vec3(pos_data[i+3], pos_data[i + 4], pos_data[i + 5]);
			glm::vec3 secondNextVertex = glm::vec3(pos_data[i + 6], pos_data[i + 7], pos_data[i + 8]);
			// Get the face normal
			glm::vec3 vector1 = firstNextVertex - curVertex;
			glm::vec3 vector2 = secondNextVertex - curVertex;
			glm::vec3 faceNormal = glm::cross(vector1, vector2);

			// Add the face normal to the 3 vertices normal touching this face
			verticesNormal[glm::to_string(curVertex)] += faceNormal;
			verticesNormal[glm::to_string(firstNextVertex)] += faceNormal;
			verticesNormal[glm::to_string(secondNextVertex)] += faceNormal;
		}

		// Normalize vertices normal
		std::unordered_map<string, glm::vec3>::iterator it = verticesNormal.begin();
		while (it != verticesNormal.end()) {
			if (!(it->second.x == 0 && it->second.y == 0 && it->second.z == 0)) {
				it->second = glm::normalize(it->second);
			}
			norm_data.push_back(it->second.x);
			norm_data.push_back(it->second.y);
			norm_data.push_back(it->second.z);
			it++;
		}
		return norm_data;
	}
};