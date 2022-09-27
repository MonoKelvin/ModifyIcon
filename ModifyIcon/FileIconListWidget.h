#pragma once
#include <QListWidget>

class FileIconWidget;

/** @brief �ļ�ͼ���б�ؼ� */
class FileIconListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit FileIconListWidget(QWidget* parent = nullptr);

    /** @brief ���ͼ�� */
    FileIconWidget* addFile(const QString& filePath, bool isAddIfNotExist = false);

    /** @brief ���ù���·�������Զ������ļ�ͼ�� */
    bool setWorkspace(const QString& directory);

protected:
    void resizeEvent(QResizeEvent* ev) override;

private:
    /** @brief ����·�� */
    QString m_workspace;
};

