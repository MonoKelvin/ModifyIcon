#pragma once
#include <QListWidget>

class FileIconWidget;

/** @brief 文件图标列表控件 */
class FileIconListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit FileIconListWidget(QWidget* parent = nullptr);

    /** @brief 添加图标 */
    FileIconWidget* addFile(const QString& filePath, bool isAddIfNotExist = false);

    /** @brief 设置工作路径，并自动加载文件图标 */
    bool setWorkspace(const QString& directory);

protected:
    void resizeEvent(QResizeEvent* ev) override;

private:
    /** @brief 工作路径 */
    QString m_workspace;
};

