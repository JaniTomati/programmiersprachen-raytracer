#include "ray.hpp"

Ray& Ray::transformRay(glm::mat4 const& mat) {
	glm::vec4 a {origin_, 1.0f};
	glm::vec4 b {direction_, 0.0f};
	glm::vec3 origin_ {mat * a};
	glm::vec3 direction_ {mat * b};

	return *this;
}

Ray transformRay(glm::mat4 const& mat, Ray& ray) {
	return ray.transformRay(mat);;
}