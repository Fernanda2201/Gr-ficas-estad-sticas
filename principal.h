#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionGuardar_triggered();
    void on_cmdPromedio_clicked();

    void on_actionNuevo_triggered();

protected:

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Principal *ui;
    QPixmap lienzo;
    void dibujar();
};
#endif // PRINCIPAL_H
