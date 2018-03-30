#include "item.h"
#include "shader.h"
#include "node.h"

Item::Item()
{
    setFlag(ItemHasContents, true);
}

void Item::setColor(const QColor &color)
{
    if (m_color != color) 
    {
        m_color = color;
        emit colorChanged();
        update();
    }
}
QColor Item::color() const
{
    return m_color;
}

QSGNode* Item::updatePaintNode(QSGNode *_node, UpdatePaintNodeData *)
{
    CustomNode *n = static_cast<CustomNode *>(_node);
    if (!_node)
        n = new CustomNode();

    QSGGeometry::updateTexturedRectGeometry(n->geometry(), boundingRect(), QRectF(0, 0, 1, 1));
    static_cast<QSGSimpleMaterial<State>*>(n->material())->state()->color = m_color;

    n->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

    return n;
}
