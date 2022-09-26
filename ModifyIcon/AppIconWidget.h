#pragma once
#include <QWidget>

/** @brief ���ͼ��ؼ� */
class AppIconWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AppIconWidget(QWidget* parent = nullptr);
    explicit AppIconWidget(const QString& appFilePath, QWidget* parent = nullptr);

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

    /** @brief ��������·������ͼ��ؼ� */
    bool setApp(const QString& appFilePath);

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

    /** @brief ������Ʊ�ǩ�ؼ� */
    QLabel* m_appNameLabel;

    /** @brief ���ͼ��ؼ� */
    QLabel* m_iconPixmapLabel;
};

