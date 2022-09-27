#pragma once
#include <QWidget>

/** @brief 文件图标控件 */
class FileIconWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileIconWidget(QWidget* parent = nullptr);
    explicit FileIconWidget(const QString& filePath, QWidget* parent = nullptr);

    /** @brief 控件数据 */
    struct Data
    {
        /** @brief 软件文件地址 */
        QString filePath;

        /** @brief 图标图片 */
        QIcon iconPixmap;

        /** @brief 图标显示模式 */
        QIcon::Mode mode;

        Data();
    };

    /** @brief 给定文件路径生成图标控件 */
    bool setFile(const QString& filePath);

    /** @brief 重置控件内容 */
    void reset();

    /** @brief 设置图标大小 */
    void setIconSize(const QSize& size) const;

    /** @brief 获取图标大小 */
    QSize getIconSize() const;

    /** @brief 程序图标控件是否有效 */
    bool isValid() const;

private:
    virtual void paintEvent(QPaintEvent* paintEvent) override;

    /** @brief 初始化数据 */
    void _init(const QString& filePath);

private:
    /** @brief 数据 */
    Data m_data;

    /** @brief 文件名称标签控件 */
    QLabel* m_fileNameLabel;

    /** @brief 软件图标控件 */
    QLabel* m_iconPixmapLabel;
};

