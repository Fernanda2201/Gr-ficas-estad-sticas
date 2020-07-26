#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo= QPixmap(500,500);
    lienzo.fill(Qt::white);

    this->dibujar();

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{


    QPainter painter(&lienzo);
    //Crear un pincel para los bordes
    QPen pincel;
    //int n1=ui->inNota1->value();
    int x=0;
    int y=0;

    //Cambiando propiedades del pincel
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    painter.setPen(pincel);

    /*//Dibujar primera barra
    painter.drawRect(x+50, n1, 100,450-n1);*/

    //Crear un objeto color
    QColor colorRelleno( 152,128,148);
    //Crear otro objeto color
    QColor colorBorde( 59,38,55);

    //Cambiar el color del pincel
    pincel.setColor(colorBorde);
    //Volver el pincel al "pintor"(borde)
    painter.setPen(pincel);

    //Creando colores para la tercera barra
    QColor cBordeBarra3(56,79,79);
    QColor cRellenoBarra3( 85,172,172);

    //Establecinedo colores al pincel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);



    //Dibujar Linea de medidas Y
    painter.drawLine(x+20,y+145, 20,450);

    //Dibujar Linea de medidas X
    painter.drawLine(x+20,y+450, 500,450);

    // METRICA
        x=0;                 //Posicion en X
    int metrica =150;        //Limite de la metrica
    for (int i=145;i<450;i+=20) {
        //Dibujar metrica en Y (numeros)
        QString numeros= QString::number(metrica);
        metrica-=10;        //Se va restando de 10 en 10
        painter.drawText(x+30,i,numeros);
        //Dibujar metrica en Y (lineas)

        painter.drawLine(x+20,i,x+25,i);
    }


     //Graficar metrica en X
     painter.drawText(90,465,"Nota 1");
     painter.drawText(205,465,"Nota 2");
     painter.drawText(325,465,"Nota 3 ");


}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo= QFileDialog::getSaveFileName(this,"Guardar imagen", QString(),"Imagenes (*.png)");

    if(!nombreArchivo.isEmpty()){
        if(lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo gaurdado en: "+ nombreArchivo);
        else
            QMessageBox::warning(this, "Gaurdar imagen", "No se puedo guardar el archivo");
    }
}




void Principal::on_cmdPromedio_clicked()
{
    QPainter painter(&lienzo);
    QPen pincel;
    int n1=ui->inNota1->value();
    int n2=ui->inNota2->value();
    int n3=ui->inNota3->value();
    // Variable para implementar la posicion de x en en plano
    int x=0;

    //Cambiando propiedades del pincel
    pincel.setWidth(5);
    pincel.setJoinStyle(Qt::MiterJoin);
    QColor colorBarra1Borde(180,211,102);
    QColor colorBarra1Fondo(180,211,102);


    pincel.setColor(colorBarra1Borde);
    painter.setBrush(colorBarra1Fondo);

    painter.setPen(pincel);

    //Dibujar primera barra
    painter.drawRect(x+50, 447.2-n1*2, 100,n1*1.95);

    //Crear un objeto color
    QColor colorRelleno( 100,222,108);
    //Crear un otro objeto color
    QColor colorBorde(100,222,108);

    //Cambiar el color del pincel
    pincel.setColor(colorBorde);
    //Volver el pincel al "pintor"(borde)
    painter.setPen(pincel);

    //Establecer color  al Brush(relleno)
    painter.setBrush(colorRelleno);

    //Dibujar segunda barra
    painter.drawRect(x+170, 447.1-n2*2, 100,n2*1.95);

    //Creando colores para la tercera barra
    QColor cBordeBarra3(91,176,196);
    QColor cRellenoBarra3( 91,176,196);

    //Establecinedo colores al pincel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Dibujar Barra 3
    painter.drawRect(x+290,447.5-n3*2 ,100,n3*1.95);
    update();



}

void Principal::paintEvent(QPaintEvent *event)
{
    // Crear el painter de la ventana principal
        QPainter painter(this);
        // Dibujar la imagen
        painter.drawPixmap(20, 65, lienzo);

        // Acepatr el evento
        event->accept();
}




void Principal::on_actionNuevo_triggered()
{
    lienzo.fill(Qt::white);
    dibujar();
    ui->inNota1->setValue(0);
    ui->inNota2->setValue(0);
    ui->inNota3->setValue(0);
    update();
}
