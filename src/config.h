#include <QObject>

#ifndef CONFIG_H
#define CONFIG_H

#define MAJOR_VERSION 1
#define MINOR_VERSION 1
#define PATCH_VERSION 5

#define YEAR 2020
#define MONTH 6
#define DAY 18

class Config : public QObject
{
    Q_OBJECT

public:



signals:

public slots:
    static int getVersionCode(){
        return MAJOR_VERSION*1000+MINOR_VERSION*100+PATCH_VERSION;
    }

    static QString getVersionName(){
        return QString("%1.%2.%3").arg(MAJOR_VERSION).arg(MINOR_VERSION).arg(PATCH_VERSION);
    }

    static QString getDate(){
        return QString("%1-%2-%3").arg(YEAR).arg(MONTH).arg(DAY);
    }

    static int32_t getSystem(){
        int result=0;
#ifdef Q_OS_WIN
        // Windows上的代码
        result=1;
#endif

#ifdef Q_OS_LINUX
        // Linux上的代码
        result=2;
#endif

#ifdef Q_OS_MAC
        // Mac上的代码
        result=3;
#endif
        return result;
    }

    static QString getSystemStr(){
        switch (getSystem()) {
        case 1:
            return "windows";
        case 2:
            return "linux";
        case 3:
            return "macOS";
        default:
            return "unknown";
        }
    }
};

#endif // CONFIG_H
