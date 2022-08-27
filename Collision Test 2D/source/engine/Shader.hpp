#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/type_ptr.hpp>

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

class Shader
{
public:
	Shader(const char* vertexFilepath, const char* fragmentFilepath);
	~Shader();

	void Use() { glUseProgram(ID); }

	static std::string GetFileContents(const char* filepath);

	void SetMat4(const char* name, glm::mat4 mat4)
		{ glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat4)); }
private:
	void CreateShaderProgram(const char* vertexFilepath, const char* fragmentFilepath);

	bool ShaderCompileSuccess(unsigned int& shader);
	bool ProgramLinkSuccess(unsigned int& program);

	unsigned int ID;
};