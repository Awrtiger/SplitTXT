﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDropEvent>
#include <QTime>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class SplitterThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSettings &getApplicationSettings() const;
    void doReadSettings(QSettings &settings);
    void doWriteSettings(QSettings &settings);

    QString formatPath(QString path);
    void initOutputTxtDirs(QString path);
    int calcTxtTotalLines(QString textFilePath);
    int getLineNumInTxt(QString searchStr);
    void mergeTxtFiles(QStringList fileList, QString outFilePath,
                       int intervalLinesNum = 1, int intervalLinesNum2 = 1);
    void generateSerialIndexTxt(QString fileName);

protected:
    void closeEvent(QCloseEvent *event);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *ev);

private slots:
    void splitThreadFinished();

    void on_openFileBtn_clicked();

    void on_startBtn_clicked();

    void on_openDir_clicked();

    void on_lineEdit_lineNum_textEdited(const QString &arg1);

    void on_lineEdit_docNum_textEdited(const QString &arg1);

    void on_switchComboBox_currentIndexChanged(int index);

    void on_lineEdit_IntervalLinesNum_textEdited(const QString &text);

    void on_checkBox_asymmetric_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    QTime m_startTime0;
    QTime m_startTime;
    QTime m_startTime2;
    QString m_outDir;

    SplitterThread *m_splitterThread;
    QString m_desktopDir;

    QString m_createDateTime;
    int m_totalLines;
    int m_intervalLinesNum;
};
#endif // MAINWINDOW_H
