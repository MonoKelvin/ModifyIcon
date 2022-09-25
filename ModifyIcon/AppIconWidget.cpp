#include "stdafx.h"
#include "AppIconWidget.h"
#include "AppUtils.h"
#include <QLabel>

AppIconWidget::Data::Data()
    : iconSize(48, 48)
    , mode(QIcon::Mode::Normal)
{
}

AppIconWidget::AppIconWidget(QWidget* parent)
    : QWidget(parent)
{
    _init(ANull_String);
}

AppIconWidget::AppIconWidget(const QString& appFilePath, QWidget* parent)
    : QWidget(parent)
{
    _init(appFilePath);
}

bool AppIconWidget::setApp(const QString& appFilePath)
{
    if (!QFileInfo(appFilePath).exists())
        return false;

    m_data.filePath = appFilePath;

    const QIcon icon = AppUtils::GetApplicationIcon(m_data.filePath);
    if (!icon.isNull())
    {
        QPixmap pixmap = icon.pixmap(m_data.iconSize.width(), m_data.iconSize.height(), m_data.mode);
        m_iconPixmapLabel->setPixmap(pixmap);
    }
}

QSize AppIconWidget::getIconSize() const
{
    return m_data.iconSize;
}

void AppIconWidget::paintEvent(QPaintEvent* paintEvent)
{
    APROCH_USE_STYLE_SHEET();
}

void AppIconWidget::_init(const QString& filePath)
{
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    layout->setSpacing(0);
    layout->setMargin(0);

    m_iconPixmapLabel = new QLabel(this);
    m_appNameLabel = new QLabel(m_data.appName, this);

    layout->addWidget(m_iconPixmapLabel, 4);
    layout->addWidget(m_appNameLabel, 1);

    setApp(filePath);
}
