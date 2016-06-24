#ifndef PREVIEWER_H
#define PREVIEWER_H

#include "ui_gmap.h"

#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>

class Gmap : public QWidget, public Ui::Form
{
    Q_OBJECT

public:
    Gmap(QWidget *parent = 0);

    QNetworkConfigurationManager *NetConfigMgr;

public slots:
    void on_previewButton_clicked();
    void on_clearButton_clicked();

    void connection(bool conn);

private slots:
    void on_Latitude_editingFinished();
};

#endif
