#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"

class QListWidget;
class QStackedWidget;

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

    /** @brief 导航栏 */
    aproch::ANavigationBar* m_navigationBar;

    /** @brief 主页面容器 */
    QStackedWidget* m_mainPageStack;

    /** @brief 浏览页面 */
    QWidget* m_browserPage;

    /** @brief 图标控件列表 */
    QListWidget* m_appIconListWidget;
};
