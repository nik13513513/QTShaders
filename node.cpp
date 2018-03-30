#include "node.h"
#include "shader.h"

CustomNode::CustomNode()
    : m_geometry(QSGGeometry::defaultAttributes_TexturedPoint2D(), 4)
{
    setGeometry(&m_geometry);

    QSGSimpleMaterial<State> *material = Shader::createMaterial();
    material->setFlag(QSGMaterial::Blending);
    setMaterial(material);
    setFlag(OwnsMaterial);
}

