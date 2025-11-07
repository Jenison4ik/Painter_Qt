#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QImage>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);

    void setPenColor(const QColor &color);
    void clear();
    void setEraserMode(bool enabled);
    void setDrawMode();
    void setBrushSize(int size); // 🔹 возможность менять размер кисти

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    QImage image;
    QPoint lastPoint;
    QColor penColor;
    QColor lastPenColor;
    bool drawing;
    bool eraserMode = false;

    // 🔹 Для визуализации кисти
    QPoint cursorPos;
    bool showBrush = false;
    int brushSize = 3;
};

#endif // CANVAS_H
