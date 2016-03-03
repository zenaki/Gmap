#ifndef PREVIEWER_H
#define PREVIEWER_H

#include "ui_gmap.h"

class Gmap : public QWidget, public Ui::Form
{
    Q_OBJECT

public:
    Gmap(QWidget *parent = 0);

public slots:
    void on_previewButton_clicked();
    void on_clearButton_clicked();

};

#endif
