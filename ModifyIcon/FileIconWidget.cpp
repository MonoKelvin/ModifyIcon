#include "stdafx.h"
#include "FileIconWidget.h"
#include "AppUtils.h"

#include <QLabel>
#include <QGraphicsDropShadowEffect>

const QString AObjName_IconPixmapLabel("appiconwidget_pixmap");
const QString AObjName_AppNameLabel("appiconwidget_filename");

FileIconWidget::Data::Data()
    : mode(QIcon::Mode::Normal)
{
}

FileIconWidget::FileIconWidget(QWidget* parent)
    : QWidget(parent)
{
    _init(ANull_String);
}

FileIconWidget::FileIconWidget(const QString& appFilePath, QWidget* parent)
    : QWidget(parent)
{
    _init(appFilePath);
}

bool FileIconWidget::setFile(const QString& filePath)
{
    Q_ASSERT(nullptr != m_iconPixmapLabel);

    if (!QFileInfo(filePath).exists())
        return false;

    QFileInfo fileInfo(filePath);
    QString appName = fileInfo.fileName();

    m_data.filePath = filePath;

    const QIcon icon = AppUtils::GetApplicationIcon(m_data.filePath);
    if (!icon.isNull())
    {
        QPixmap pixmap = icon.pixmap(m_iconPixmapLabel->width(), m_iconPixmapLabel->height(), m_data.mode);
        m_iconPixmapLabel->setPixmap(pixmap);
    }
    else
    {
        // TODO: ÉèÖÃÄ¬ÈÏÍ¼±ê
    }
    
    m_fileNameLabel->setText(appName);
    aproch::SetElidedText(m_fileNameLabel, m_fileNameLabel->width());

    setToolTip(appName);
}

void FileIconWidget::reset()
{
    m_data = Data();

    m_iconPixmapLabel->setText(ANull_String);
    m_iconPixmapLabel->setPixmap(QPixmap());

    m_fileNameLabel->setText(ANull_String);
}

void FileIconWidget::setIconSize(const QSize& size) const
{
    Q_ASSERT(nullptr != m_iconPixmapLabel);
    m_iconPixmapLabel->setFixedSize(size);
}

QSize FileIconWidget::getIconSize() const
{
    Q_ASSERT(nullptr != m_iconPixmapLabel);
    return m_iconPixmapLabel->size();
}

bool FileIconWidget::isValid() const
{
    if (!QFileInfo(m_data.filePath).exists())
        return false;

    return true;
}

void FileIconWidget::paintEvent(QPaintEvent* paintEvent)
{
    APROCH_USE_STYLE_SHEET();
}

void FileIconWidget::_init(const QString& filePath)
{
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    layout->setSpacing(0);
    layout->setMargin(0);

    m_iconPixmapLabel = new QLabel(this);
    m_iconPixmapLabel->setObjectName(AObjName_IconPixmapLabel);
    m_iconPixmapLabel->setAlignment(Qt::AlignCenter);
    m_iconPixmapLabel->setScaledContents(true);
    layout->addWidget(m_iconPixmapLabel, 1, Qt::AlignCenter);

    m_fileNameLabel = new QLabel(this);
    m_fileNameLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_fileNameLabel->setObjectName(AObjName_AppNameLabel);
    m_fileNameLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(m_fileNameLabel, 1, Qt::AlignCenter);

    setFile(filePath);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(50);
    effect->setOffset(0, 16);
    effect->setColor("#55b3b7be");
    this->setGraphicsEffect(effect);
}
