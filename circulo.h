#ifndef CIRCULO_H
#define CIRCULO_H

#include <QPoint>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QInputDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>

class Circulo : public QPoint
{

public:
    Circulo();
    Circulo(int xpos, int ypos);

private:

};



#endif // CIRCULO_H
