#pragma once
#include <QWidget>

/** @brief 软件图标控件 */
class AppIconWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AppIconWidget(QWidget* parent = nullptr);
    explicit AppIconWidget(const QString& appFilePath, QWidget* parent = nullptr);

    /** @brief 控件数据 */
    struct Data
    {
        /** @brief 软件名称 */
        QString appName;

        /** @brief 软件文件地址 */
        QString filePath;

        /** @brief 图标图片 */
        QIcon iconPixmap;

        /** @brief 图标尺寸 */
        QSize iconSize;

        /** @brief 图标显示模式 */
        QIcon::Mode mode;

        Data();
    };

    /** @brief 给定程序路径生成图标控件 */
    bool setApp(const QString& appFilePath);

    /** @brief 重置控件内容 */
    void reset();

    /** @brief 获取图标大小 */
    QSize getIconSize() const;

private:
    virtual void paintEvent(QPaintEvent* paintEvent) override;

    /** @brief 初始化数据 */
    void _init(const QString& filePath);

private:
    /** @brief 数据 */
    Data m_data;

    /** @brief 软件名称标签控件 */
    QLabel* m_appNameLabel;

    /** @brief 软件图标控件 */
    QLabel* m_iconPixmapLabel;
};

