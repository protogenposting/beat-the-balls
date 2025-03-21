#pragma once

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    unsigned int id;
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char *vertexPath, const char *fragmentPath);

    // activate the shader
    // ------------------------------------------------------------------------
    void Use() const;

    // utility uniform functions
    // ------------------------------------------------------------------------
    void SetBool(const std::string &name, bool value);

    // ------------------------------------------------------------------------
    void SetInt(const std::string &name, int value);

    // ------------------------------------------------------------------------
    void SetFloat(const std::string &name, float value);

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void CheckCompileErorrs(unsigned int shader, const std::string &type);
};
