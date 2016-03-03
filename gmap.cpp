#include <QtWidgets>
#include <QtWebKitWidgets>
#include <QMessageBox>
#include "gmap.h"

Gmap::Gmap(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    webView->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);

}

void Gmap::on_previewButton_clicked()
{
//    QString Request = "-6.40333;106.88776;test;test.01;-6.40;106.88776;test2;test.02;";
//    webView->page()->mainFrame()->evaluateJavaScript(QString("split_LatLng('%1');").arg(Request));
//    QString Return = webView->page()->mainFrame()->evaluateJavaScript("Rtrn").toString();

    QString lat;
    QString lng;
    QString bName;
    QString sNumber;

    if (!Latitude->text().isEmpty() && !Longitude->text().isEmpty()) {
        lat = Latitude->text();
        lng = Longitude->text();
        bName = BoardName->text();
        sNumber = SerialNumber->text();

        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lat = %1;").arg(lat));
        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lng = %1;").arg(lng));
        webView->page()->mainFrame()->evaluateJavaScript(QString("board_name = '%1';").arg(bName));
        webView->page()->mainFrame()->evaluateJavaScript(QString("serial_number = '%1';").arg(sNumber));
        webView->page()->mainFrame()->evaluateJavaScript("setMarker()");
    } else {
        lat = webView->page()->mainFrame()->evaluateJavaScript("pin_lat").toString();
        lng = webView->page()->mainFrame()->evaluateJavaScript("pin_lng").toString();
        bName = webView->page()->mainFrame()->evaluateJavaScript("board_name").toString();
        sNumber = webView->page()->mainFrame()->evaluateJavaScript("serial_number").toString();

        Latitude->setText(lat);
        Longitude->setText(lng);
        BoardName->setText(bName);
        SerialNumber->setText(sNumber);

        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lat = %1;").arg(lat));
        webView->page()->mainFrame()->evaluateJavaScript(QString("pin_lng = %1;").arg(lng));
        webView->page()->mainFrame()->evaluateJavaScript(QString("board_name = '%1';").arg(bName));
        webView->page()->mainFrame()->evaluateJavaScript(QString("serial_number = '%1';").arg(sNumber));
        webView->page()->mainFrame()->evaluateJavaScript("setMarker()");
    }
}

void Gmap::on_clearButton_clicked()
{
    Latitude->clear();
    Longitude->clear();
    BoardName->clear();
    SerialNumber->clear();
}
