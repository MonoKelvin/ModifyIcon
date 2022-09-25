#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"

namespace aproch
{
    class ANavigationBar;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindowClass ui;

    /** @brief µ¼º½À¸ */
    aproch::ANavigationBar* m_navigationBar;
};
