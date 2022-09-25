#include "stdafx.h"
#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWidget;
    mainWidget.show();
    mainWidget.move(QApplication::desktop()->screen()->rect().center() - mainWidget.rect().center());

    // DEBUG 测试加载默认样式表
    QPushButton styleBtn(QObject::tr("Reload Style Sheet"), &mainWidget);
    styleBtn.setProperty("buttonType", "test");
    QObject::connect(&styleBtn, &QPushButton::clicked, [&] {
        QFile style(AStr(":/App/Style/MainStyleSheet"));
        if (style.open(QFile::ReadOnly | QFile::Text))
        {
            a.setStyleSheet(style.readAll());
        }
        style.close();
    });
    styleBtn.show();
    styleBtn.resize(160, 36);
    styleBtn.move((mainWidget.width() - styleBtn.width()) * 0.5, 1);
    styleBtn.click();


    return a.exec();
}
