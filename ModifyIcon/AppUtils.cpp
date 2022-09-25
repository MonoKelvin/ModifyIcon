#include "stdafx.h"
#include "AppUtils.h"
#include <QFileIconProvider>

QIcon AppUtils::GetApplicationIcon(const QString& appFilePath)
{
    QFileInfo fileInfo(appFilePath);
    if (!fileInfo.exists())
        return QIcon();

    QFileIconProvider iconProvider;
    const QIcon icon = iconProvider.icon(fileInfo);

    return icon;
}
