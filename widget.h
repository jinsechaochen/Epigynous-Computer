#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include "com.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //���ڴ򿪹رհ�ť�����ķ���
	void OpenPushButton();

	void StopPointRun();

    void SetTimer();

    void SetPointButton();

    void SetInchButton();

    //����COM���
    void SetComButton();

    void SetResetButton();

private:
    Ui::Widget *ui;

    //���ڹ�����
    Com* m_pCom = new Com;
	QTimer* pTimerInch = new QTimer;

    QVector<QByteArray> m_vecPointArrSend;
    int m_iCurPointNum = 0;
	QTimer* pTimerPoint = new QTimer;

    QTimer* pTimerTrack = new QTimer;
    QVector<QByteArray> m_vecArrSend;
    int m_iSendCurNum = 0;

public slots:

    //�ۺ���
    void RecvInfoFromSerialSlot(QByteArray);
	void SendInfoFromSerialSlot(QByteArray);
	void AddText(QString strInfo, bool bRecv = true);

private:

};

#endif // WIDGET_H
