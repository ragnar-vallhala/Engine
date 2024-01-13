#pragma once
#include "EngineUtils.h"
#include "shader.h"
class Mesh {

public:
	std::vector<Vertex> m_vertecies;
	std::vector<Texture> m_textures;
	std::vector<unsigned int> m_indices;

	Mesh(std::vector<Vertex> vertecies,
		std::vector<Texture> textures,
		std::vector<unsigned int> indices);

	void Draw(Shader& shader);

private:

	unsigned int m_VAO, m_EBO, m_VBO;

	void SetupMesh();


};