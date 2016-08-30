#include "ray.hpp"

Ray transformRay(glm::mat4 const& mat, Ray const& ray)
{
	glm::vec4 a{ray.origin_,1.0f};
	glm::vec4 b{ray.direction_,0.0f};
	glm::vec3 origin(mat*a);
	glm::vec3 direction(mat*b);

	return {origin,direction};
}