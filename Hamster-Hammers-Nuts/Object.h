#pragma once

#include "GL.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Hamster
{
	struct Transform
	{
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

		glm::mat4 make_local_to_world() const;
		glm::mat4 make_world_to_local() const;
	};

	struct Camera
	{
		Transform transform;
		//camera parameters (perspective):
		float fovy = glm::radians(60.0f); //vertical fov (in radians)
		float aspect = 4.0f / 3.0f; //x / y
		float near = 0.01f; //near plane
							//computed from the above:
		void set(float radius, float elevation, float azimuth, glm::vec3& target);
		glm::mat4 make_projection() const;
	};

	struct Object
	{
		Transform transform;
		//geometric info:
		GLuint start = 0;
		GLuint count = 0;
	};

	struct Light
	{
		Transform transform;
		//light parameters (directional):
		glm::vec3 intensity = glm::vec3(1.0f, 1.0f, 1.0f); //effectively, color
	};
}