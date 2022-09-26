#include "stdafx.h"
#include "AppIconWidget.h"
#include "AppUtils.h"

#include <QLabel>
#include <QGraphicsDropShadowEffect>

const QString AObjName_IconPixmapLabel("appiconwidget_pixmap");
const QString AObjName_AppNameLabel("appiconwidget_appname");

AppIconWidget::Data::Data()
    : mode(QIcon::Mode::Normal)
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
    Q_ASSERT(nullptr != m_iconPixmapLabel);

    if (!QFileInfo(appFilePath).exists())
        return false;

    QFileInfo fileInfo(appFilePath);
    QString appName = fileInfo.fileName();

    m_data.filePath = appFilePath;

    const QIcon icon = AppUtils::GetApplicationIcon(m_data.filePath);
    if (!icon.isNull())
    {
        QPixmap pixmap = icon.pixmap(m_iconPixmapLabel->width(), m_iconPixmapLabel->height(), m_data.mode);
        m_iconPixmapLabel->setPixmap(pixmap);
        pixmap.save("E:/fuck.png");
    }
    else
    {
        // TODO: ÉèÖÃÄ¬ÈÏÍ¼±ê
    }
    
    m_appNameLabel->setText(appName);
}

void AppIconWidget::reset()
{
    m_data = Data();

    m_iconPixmapLabel->setText(ANull_String);
    m_iconPixmapLabel->setPixmap(QPixmap());

    m_appNameLabel->setText(ANull_String);
}

void AppIconWidget::setIconSize(const QSize& size) const
{
    Q_ASSERT(nullptr != m_iconPixmapLabel);
    m_iconPixmapLabel->setFixedSize(size);
}

QSize AppIconWidget::getIconSize() const
{
    Q_ASSERT(nullptr != m_iconPixmapLabel);
    return m_iconPixmapLabel->size();
}

bool AppIconWidget::isValid() const
{
    if (!QFileInfo(m_data.filePath).exists())
        return false;

    return true;
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
    m_iconPixmapLabel->setObjectName(AObjName_IconPixmapLabel);
    m_iconPixmapLabel->setAlignment(Qt::AlignCenter);
    m_iconPixmapLabel->setScaledContents(true);
    layout->addWidget(m_iconPixmapLabel, 4);

    m_appNameLabel = new QLabel(this);
    m_appNameLabel->setObjectName(AObjName_AppNameLabel);
    m_appNameLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(m_appNameLabel, 1);

    layout->setContentsMargins(36, 16, 36, 16);
    layout->setAlignment(Qt::AlignCenter);

    setIconSize(QSize(80, 80));
    setApp(filePath);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(50);
    effect->setOffset(0, 16);
    effect->setColor("#55b3b7be");
    this->setGraphicsEffect(effect);
}
