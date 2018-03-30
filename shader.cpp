#include "shader.h"

int State::compare(const State *other) const
{
    uint rgb = color.rgba();
    uint otherRgb = other->color.rgba();

    if (rgb == otherRgb) {
        return 0;
    }
    else if (rgb < otherRgb) {
        return -1;
    }
    else {
        return 1;
    }
}


//const char* Shader::vertexShader() const 
//{
//    return
//        "attribute highp vec4 aVertex;                          \
//                 attribute highp vec2 aTexCoord;                \
//                 uniform highp mat4 qt_Matrix;                  \
//                 varying highp vec2 texCoord;                   \
//                 void main() {                                  \
//                    gl_Position = qt_Matrix * aVertex;          \
//                    texCoord = aTexCoord;                       \
//                }";
//}
//
//const char* Shader::fragmentShader() const
//{
//    return
//        "uniform lowp float qt_Opacity;                                           \
//                 uniform lowp vec4 color;                                           \
//                 varying highp vec2 texCoord;                                       \
//                 void main ()                                                       \
//                 {                                                                  \
//                     gl_FragColor = texCoord.y * texCoord.x * color * qt_Opacity;   \
//                 }";
//}

Shader::Shader()
{
    setShaderSourceFile(QOpenGLShader::Vertex, ":/shaders/brush.vsh");
    setShaderSourceFile(QOpenGLShader::Fragment, ":/shaders/brush.fsh");
}

QList<QByteArray> Shader::attributes() const
{
    return QList<QByteArray>() << "aVertex" << "aTexCoord";
}

void Shader::updateState(const State *state, const State *)
{
    program()->setUniformValue(id_color, state->color);
}

void Shader::resolveUniforms()
{
    id_color = program()->uniformLocation("color");
}
