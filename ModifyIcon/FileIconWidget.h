#pragma once
#include <QWidget>

/** @brief �ļ�ͼ��ؼ� */
class FileIconWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileIconWidget(QWidget* parent = nullptr);
    explicit FileIconWidget(const QString& filePath, QWidget* parent = nullptr);

    /** @brief �ؼ����� */
    struct Data
    {
        /** @brief ����ļ���ַ */
        QString filePath;

        /** @brief ͼ��ͼƬ */
        QIcon iconPixmap;

        /** @brief ͼ����ʾģʽ */
        QIcon::Mode mode;

        Data();
    };

    /** @brief �����ļ�·������ͼ��ؼ� */
    bool setFile(const QString& filePath);

    /** @brief ���ÿؼ����� */
    void reset();

    /** @brief ����ͼ���С */
    void setIconSize(const QSize& size) const;

    /** @brief ��ȡͼ���С */
    QSize getIconSize() const;

    /** @brief ����ͼ��ؼ��Ƿ���Ч */
    bool isValid() const;

private:
    virtual void paintEvent(QPaintEvent* paintEvent) override;

    /** @brief ��ʼ������ */
    void _init(const QString& filePath);

private:
    /** @brief ���� */
    Data m_data;

    /** @brief �ļ����Ʊ�ǩ�ؼ� */
    QLabel* m_fileNameLabel;

    /** @brief ���ͼ��ؼ� */
    QLabel* m_iconPixmapLabel;
};

