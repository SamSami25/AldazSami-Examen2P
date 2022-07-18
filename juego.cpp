#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    QPoint centro = ui->marco->geometry().center();
    m_circulo = new Circulo();
    m_circulo->setX(centro.x());
    m_circulo->setY(centro.y());
    mImagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    mImagen->fill(Qt::white);
    mPainter = new QPainter(mImagen);
    mPainter->setRenderHint(QPainter::Antialiasing);
    mPuedeDibujar = false;
    mNumeroLineas = 0;
}

Juego::~Juego()
{
    delete ui;
    delete mPainter;
    delete mImagen;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *mImagen);
    event->accept();
}

void Juego::mousePressEvent(QMouseEvent *event)
{
    mPuedeDibujar = true;
    xpos = event->pos();
    event->accept();
}

void Juego::mouseMoveEvent(QMouseEvent *event)
{
    if ( !mPuedeDibujar ) {
        event->accept();
        return;
    }
    ypos = event->pos();
    QPen pincel;
    pincel.setColor(Qt::black);
    pincel.setWidth(20);
   // mPainter->setPen(pincel);
    mPainter->drawEllipse(xpos.x(),xpos.y(),ypos.x()-xpos.x(),ypos.y()-xpos.y());
    update();
    xpos = ypos;
}

void Juego::mouseReleaseEvent(QMouseEvent *event)
{
    mPuedeDibujar = false;
    event->accept();
}


void Juego::on_btnArriba_released()
{

}


void Juego::on_btnAbajo_released()
{

}


void Juego::on_btnIzqueirda_released()
{

}


void Juego::on_btnDerecha_released()
{

}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar()
{
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::black);

    mPainter->setPen(pincel);
    mPainter->drawEllipse(xpos.x(),xpos.y(),ypos.x()- xpos.x(),ypos.y()-xpos.y());
    update();
}

