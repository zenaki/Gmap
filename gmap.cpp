#include <QtWidgets>
#include <QtWebKitWidgets>
#include <QMessageBox>
#include "gmap.h"

Gmap::Gmap(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    webView->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);

    NetConfigMgr = new QNetworkConfigurationManager(this);
    connect(NetConfigMgr, SIGNAL(onlineStateChanged(bool)), this, SLOT(connection(bool)));

    if (NetConfigMgr->isOnline()) {
        QMessageBox::information(this, "Connection", "Internet Is Connected ..");
    } else {
        QMessageBox::critical(this, "Connection", "Internet Is Not Connected ..!!");
    }

}

void Gmap::on_previewButton_clicked()
{
//    QString Request = "-6.40333;106.88776;Module_1;RTU.01;-6.40;106.88776;Module_2;RTU.02";
    QString Request;
    Request.sprintf("%s;%s;%s;%s", Latitude->text().toUtf8().data(), Longitude->text().toUtf8().data(), BoardName->text().toUtf8().data(), SerialNumber->text().toUtf8().data());
    webView->page()->mainFrame()->evaluateJavaScript(QString("split_LatLng('%1');").arg(Request));
    webView->page()->mainFrame()->evaluateJavaScript("initMap();");
    webView->page()->mainFrame()->evaluateJavaScript("initMarker();");
    QString Return = webView->page()->mainFrame()->evaluateJavaScript("Rtrn").toString();
    Return.remove("undefined");

//    QString lat;
//    QString lng;
//    QString bName;
//    QString sNumber;

//    if (!Latitude->text().isEmpty() && !Longitude->text().isEmpty()) {
//        lat = Latitude->text();
//        lng = Longitude->text();
//        bName = BoardName->text();
//        sNumber = SerialNumber->text();

//        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lat = %1;").arg(lat));
//        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lng = %1;").arg(lng));
//        webView->page()->mainFrame()->evaluateJavaScript(QString("board_name = '%1';").arg(bName));
//        webView->page()->mainFrame()->evaluateJavaScript(QString("serial_number = '%1';").arg(sNumber));
//        webView->page()->mainFrame()->evaluateJavaScript("setMarker()");
//    } else {
//        lat = webView->page()->mainFrame()->evaluateJavaScript("pin_lat").toString();
//        lng = webView->page()->mainFrame()->evaluateJavaScript("pin_lng").toString();
//        bName = webView->page()->mainFrame()->evaluateJavaScript("board_name").toString();
//        sNumber = webView->page()->mainFrame()->evaluateJavaScript("serial_number").toString();

//        Latitude->setText(lat);
//        Longitude->setText(lng);
//        BoardName->setText(bName);
//        SerialNumber->setText(sNumber);

//        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lat = %1;").arg(lat));
//        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lng = %1;").arg(lng));
//        webView->page()->mainFrame()->evaluateJavaScript(QString("board_name = '%1';").arg(bName));
//        webView->page()->mainFrame()->evaluateJavaScript(QString("serial_number = '%1';").arg(sNumber));
//        webView->page()->mainFrame()->evaluateJavaScript("setMarker()");
//    }
}

void Gmap::on_clearButton_clicked()
{
    Latitude->clear();
    Longitude->clear();
    BoardName->clear();
    SerialNumber->clear();
}

void Gmap::connection(bool conn)
{
    if (conn) {
        QMessageBox::information(this, "Connection", "Internet Is Connected ..");
    } else {
        QMessageBox::critical(this, "Connection", "Internet Is Not Connected ..!!");
    }
}

void Gmap::on_Latitude_editingFinished()
{

}
