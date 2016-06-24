#include <QtWidgets>
#include <QtWebKitWidgets>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    centralWidget = new Gmap(this);
    setCentralWidget(centralWidget);
    this->setMap();
}

void MainWindow::setMap()
{
    QString fileName = ":/new/map/gmap.html";
    if(!QFile(fileName).exists()) {
        QMessageBox::critical(this, tr("Attention !!"),
        "File not found: " + fileName);
        return;
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Sorry .."),
            "Cannot Set Map ..\n" + file.errorString());
            return;
        }
        QTextStream out(&file);
        QString output = out.readAll();

        // display contents
        centralWidget->webView->setHtml(output);
        centralWidget->webView->page()->mainFrame()->evaluateJavaScript("initMarker();");
    }
}
