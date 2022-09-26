#include "stdafx.h"
#include "MainWindow.h"
#include "AppIconWidget.h"

#include <Aproch\Include\Widget\ANavigationBar.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    m_navigationBar = ui.widgetNavigationBar;
    m_mainPageStack = ui.MainPageStack;
    m_browserPage = ui.BrowserPage;
    m_appIconListWidget = ui.AppIconListWidget;

    m_appIconListWidget->setObjectName("appIconListWidget");

    // µ¼º½À¸
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

    /// TEST
    QString strFilePath = "D:/Eagle/Eagle.exe";
    QListWidgetItem* pItem = new QListWidgetItem(m_appIconListWidget);
    pItem->setSizeHint(QSize(150, 150));
    m_appIconListWidget->addItem(pItem);
    m_appIconListWidget->setItemWidget(pItem, new AppIconWidget(strFilePath, m_appIconListWidget));

    strFilePath = "D:/Houdini/Readme.txt";
    pItem = new QListWidgetItem(m_appIconListWidget);
    pItem->setSizeHint(QSize(150, 150));
    m_appIconListWidget->addItem(pItem);
    m_appIconListWidget->setItemWidget(pItem, new AppIconWidget(strFilePath, m_appIconListWidget));

    strFilePath = "E:/Project/Code/Aproch/Output/Debug/Aproch.exe";
    pItem = new QListWidgetItem(m_appIconListWidget);
    pItem->setSizeHint(QSize(150, 150));
    m_appIconListWidget->addItem(pItem);
    m_appIconListWidget->setItemWidget(pItem, new AppIconWidget(strFilePath, m_appIconListWidget));
}

MainWindow::~MainWindow()
{}
