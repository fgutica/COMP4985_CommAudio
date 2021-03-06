/*---------------------------------------------------------------------------------------
--	SOURCE FILE:		audioplayer.h -   Header for audioplayer.cpp
--
--	PROGRAM:			Server.exe
--
--
--	DATE:				Febuary 19 2015
--
--	DESIGNERS:			Filip Gutica
--
--	PROGRAMMERS:		Filip Gutica
--
--	NOTES:
--	Class definition for the local audioplayer for our server.
---------------------------------------------------------------------------------------*/
#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QAudioDecoder>
#include <QAudioBuffer>
#include <QBuffer>
#include <Windows.h>

namespace Ui {
class AudioPlayer;
}

class AudioPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit AudioPlayer(QWidget *parent = 0);
    ~AudioPlayer();
    void setAudio(QString);

private slots:
    void on_btnPlay_clicked();

    void on_btnPause_clicked();

    void on_sliderProgress_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

    void on_btnResume_clicked();


private:
    void PlayMusic();
    Ui::AudioPlayer *ui;
    QMediaPlayer *player;
    QString filePath;
};

struct AudioStruct
{
    AudioPlayer* myPlayer;
    QAudioBuffer buff;
    QAudioFormat fmt;
};

DWORD WINAPI AudioThread(LPVOID param);

#endif // AUDIOPLAYER_H
