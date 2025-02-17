﻿#ifndef SPLITTERTHREAD_H
#define SPLITTERTHREAD_H
// 用git bash 分割是真的快，就是不知道有没有办法找到该源码
#include <QThread>
#include <QDebug>
#include <QMutex>

#include <string>
#include <fstream>

#include <iostream>
#include <vector>

using namespace std;


class SplitterThread : public QThread
{
    Q_OBJECT

    static const int ENC_UTF8 = 0;
    static const int ENC_UTF16_LE = 1;
    static const int ENC_UTF16_BE = 2;

public:
    explicit SplitterThread(QObject *parent = 0);
    void run();


    void setInputFile(string inputFile)
    {
        this->inputFile = inputFile;
    }

    void setOutputFile(string outputFile)
    {
        this->outputFile = outputFile;
    }

    void setLinesCount(int linesCount)
    {
        this->linesCount = linesCount;
    }

    void setIsSplitOnly2File(bool isSplitOnly2File)
    {
        this->m_isSplitOnly2File = isSplitOnly2File;
    }

private:
    std::string inputFile;
    std::string outputFile;
    int realLinesCount;
    int linesCount;

    QMutex m_lock;
    bool stopThread;
    bool m_isFirstTxt;
    bool m_isSplitOnly2File;

signals:

public slots:
    void stopImmediately();
};

#endif // SPLITTERTHREAD_H
