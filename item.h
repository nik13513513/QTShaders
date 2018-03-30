#pragma once 

#include <qquickitem.h>

/// <summary>
/// Item
/// </summary>
class Item : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    Item();

    void setColor(const QColor &color);
    QColor color() const;

signals:
    void colorChanged();

private:
    QColor m_color;

public:
    QSGNode * updatePaintNode(QSGNode *node, UpdatePaintNodeData *);
};
