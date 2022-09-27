#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"

class QListWidget;
class QStackedWidget;
class FileIconListWidget;

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

    /** @brief ������ */
    aproch::ANavigationBar* m_navigationBar;

    /** @brief ��ҳ������ */
    QStackedWidget* m_mainPageStack;

    /** @brief ���ҳ�� */
    QWidget* m_browserPage;

    /** @brief �ļ��ؼ��б� */
    FileIconListWidget* m_fileIconListWidget;
};
