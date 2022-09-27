#include "stdafx.h"
#include "FileIconListWidget.h"
#include "FileIconWidget.h"

FileIconListWidget::FileIconListWidget(QWidget* parent)
    : QListWidget(parent)
{
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    setMovement(QListView::Static);
    setFlow(QListView::LeftToRight);
    setProperty("isWrapping", QVariant(true));
    setResizeMode(QListView::Adjust);
    setLayoutMode(QListView::Batched);
    setViewMode(QListView::IconMode);
    setUniformItemSizes(true);
    setWordWrap(false);
    setUpdatesEnabled(true);

    /// TEST
    QString strFilePath = "D:/Eagle/Eagle.exe";
    addFile(strFilePath);

    strFilePath = "D:/Houdini/Readme.txt";
    addFile(strFilePath);

    strFilePath = "E:/Project/Code/Aproch/Output/Debug/Aproch.exe";
    addFile(strFilePath);
    /// TEST END

    setWorkspace("E:/Project/Code/MonoStudio/ModifyIcon/x64/Debug");
}

FileIconWidget* FileIconListWidget::addFile(const QString& filePath, bool isAddIfNotExist)
{
    FileIconWidget* fileIconWidget = new FileIconWidget(filePath, this);
    if (!fileIconWidget->isValid())
    {
        fileIconWidget->deleteLater();
        return nullptr;
    }

    QListWidgetItem* pItem = new QListWidgetItem(this);
    pItem->setSizeHint(QSize(150, 150));

    addItem(pItem);
    setItemWidget(pItem, fileIconWidget);

    return fileIconWidget;
}

bool FileIconListWidget::setWorkspace(const QString& directory)
{
    QDir dir(directory);
    if (!dir.exists())
        return false;

    m_workspace = dir.absolutePath();

    clear();

    const QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files);
    for (const QFileInfo& fileInfo : fileInfoList)
    {
        addFile(fileInfo.absoluteFilePath());
    }
}

void FileIconListWidget::resizeEvent(QResizeEvent* ev)
{
    __super::resizeEvent(ev);
}
