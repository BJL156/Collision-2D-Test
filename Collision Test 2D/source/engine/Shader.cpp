#include "Shader.hpp"

Shader::Shader(const char* vertexFilepath, const char* fragmentFilepath)
{
	CreateShaderProgram(vertexFilepath, fragmentFilepath);
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

std::string Shader::GetFileContents(const char* filepath)
{
	std::ifstream file(filepath);
	if (!file.is_open()) {
		std::cout << "failed to open file" << std::endl;
	}

	std::stringstream fileStream;
	std::string line;
	while (std::getline(file, line)) {
		fileStream << line << std::endl;
	}
	file.close();

	std::string fileContents = fileStream.str();
	return fileContents;
}

void Shader::CreateShaderProgram(const char* vertexFilepath, const char* fragmentFilepath)
{
	std::string vertexCode = Shader::GetFileContents(vertexFilepath);
	std::string fragmentCode = Shader::GetFileContents(fragmentFilepath);

	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();

	std::cout << vertexShaderSource << std::endl;
	std::cout << fragmentShaderSource << std::endl;

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	if (!ShaderCompileSuccess(vertexShader)) {
		std::cout << "failed to compile vertex shader"<<std::endl;
	}

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	if (!ShaderCompileSuccess(fragmentShader)) {
		std::cout << "failed to compile fragment shader" << std::endl;
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	if (!ProgramLinkSuccess(ID)) {
		std::cout << "failed to link program" << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

bool Shader::ShaderCompileSuccess(unsigned int& shader)
{
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	return static_cast<bool>(success);
}

bool Shader::ProgramLinkSuccess(unsigned int& program)
{
	int success;
	glGetProgramiv(program, GL_COMPILE_STATUS, &success);
	return static_cast<bool>(success);
}
