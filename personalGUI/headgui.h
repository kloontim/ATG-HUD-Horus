#ifndef HEADGUI_H
#define HEADGUI_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QResizeEvent>

//#include <LeptonThread.h>


class QLabel;
class QPixmap;
class QGridLayout;

class HeadGUI : public QMainWindow
{
    Q_OBJECT

public:
    HeadGUI(QWidget *parent = 0);
    ~HeadGUI();
    void test();

//public slots:
  //  void updateImage(unsigned short *, int, int);

signals:
    void certifyPersonaeSignal();
    void upSignal();
    void downSignal();
    void rightSignal();
    void leftSignal();
    void backSignal();
    void certifySignal();
    void coosingStatusSignal();
    //where does the signal go?
    void emergencySignal(int ID);
    void newStatusSignal(int ID,int vertical);
    void answeredMessage(int ID,int vertical);
    void confirmedID(int ID);
    //from where does the signal come?
    void updateBraceletSignal(int valueUp,int valueDown,int valueRight,int valueLeft,int valueBack,int valueCertify);
    void updateTempHeadSignal(int recentTemp);
    void updateTempFootSignal(int recentTemp);
    void updateCOHeadSignal(int recentCO);
    void updateCOFootSignal(int recentCO);
    void messageRecivedSignal(QString sendMessage);

private slots:
    void certifyPersonae();
    void up();
    void down();
    void right();
    void left();
    void back();
    void certify();
    void updateBracelet(int valueUp,int valueDown,int valueRight,int valueLeft,int valueBack,int valueCertify);
    void updateTempHead(int recentTemp);
    void updateTempFoot(int recentTemp);
    void updateCOHead(int recentCOHead);
    void updateCOFoot(int recentCOFoot);
    void coosingStatus();
    void messageRecived(QString sendMessage);

private:
    //other
    QGridLayout *layout;
    QWidget *mainWidget;
    void createConnections();
    void defauftValues();

    //navigation/communication
    void createCommunication();
    QLabel *Status;
    QLabel *Messages;
    int vertical;
    int horizontal;
    bool emergencyPossible;
    bool SendEmergency;
    bool otherSignals;
    int NumberDiffMenues = 2;
    bool answerPossible;
    int NumberDiffValues[3] = {4,2,5};
    QString Stati[4]={"Status1","Status2","Status3","Status4"};
    QString recivedMessage;
    QString messageAnswers[2] = {"angenommen","nicht verfügbar"};
    int recentStatus;

    //biometric data
    void createBiometric();
    QLabel *Personae;
    QLabel *TempHead;
    QLabel *TempFoot;
    QString unitTemp ="°C";
    QLabel *COHead;
    QLabel *COFoot;
    QString unitCO = "ppm";
    int ID;
    QString Name [5]= {" ","Aron Haselhoff","Timon Gronotte","Vicky Bietenbeck","Beke Pierick"};

    //for Camera
    void createIRPicture();
    QLabel *IRPicture;
    QVector<unsigned short> rawData;
    QImage rgbImage;
    enum { ImageWidth = 320, ImageHeight = 240 };
 //   LeptonThread *thread;//%
    unsigned short rawMin, rawMax;

};

#endif // HEADGUI_H