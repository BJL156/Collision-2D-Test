#include "Mesh.hpp"

Mesh::Mesh(float xpos, float ypos, float w, float h)
	: x(xpos), y(ypos), width(w), height(h)
{
	CreateObjects();
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
}

void Mesh::Draw(glm::vec2 size, Texture& texture, Shader& shader)
{
	if (wireFrame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	shader.Use();
	texture.Bind();

	glm::mat4 projection = glm::ortho(0.0f, size.x, size.y, 0.0f);
	glm::mat4 view = glm::mat4(1.0f);

	shader.SetMat4("projection", projection);
	shader.SetMat4("view", view);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	model = glm::scale(model, glm::vec3(width, height, 0.0f));

	shader.SetMat4("model", model);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Mesh::DrawSolid(glm::vec2 size, Shader& shader)
{
	if (wireFrame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	shader.Use();

	glm::mat4 projection = glm::ortho(0.0f, size.x, size.y, 0.0f);
	glm::mat4 view = glm::mat4(1.0f);

	shader.SetMat4("projection", projection);
	shader.SetMat4("view", view);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	model = glm::scale(model, glm::vec3(width, height, 0.0f));

	shader.SetMat4("model", model);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Mesh::CreateObjects()
{
	float vertices[] =
	{
		0.0f, 1.0f, // top left
		0.0f, 0.0f, // bottom left
		1.0f, 1.0f, // top right
		1.0f, 0.0f, // bottom right
	};
	unsigned int indices[] =
	{
		0, 1, 3,
		0, 2, 3
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
}