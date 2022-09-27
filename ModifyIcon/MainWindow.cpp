#include "stdafx.h"
#include "MainWindow.h"
#include "FileIconWidget.h"

#include <Aproch\Include\Widget\ANavigationBar.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    m_navigationBar = ui.widgetNavigationBar;
    m_mainPageStack = ui.MainPageStack;
    m_browserPage = ui.BrowserPage;
    m_fileIconListWidget = ui.theFileIconListWidget;

    // �ļ�ͼ���б�ؼ�
    m_fileIconListWidget->setObjectName("fileIconListWidget");

    // ������
    m_navigationBar->setProperty(APropName_WidgetType, APropValue_Panel);
    m_navigationBar->setObjectName(AStr("aproch_navbar"));
    m_navigationBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    m_navigationBar->addGroup(tr("Home"));
    m_navigationBar->addItem(tr("Browser"));
    m_navigationBar->addItem(tr("Collection"));
    m_navigationBar->addItem(tr("Settings"));
    aproch::SNavTrackBarStyle style;
    //style.isFitItem = false;
    style.isAnimation = true;
    m_navigationBar->setTrackBarStyle(style);
}

MainWindow::~MainWindow()
{}
