/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SETTINGSINJECTORDIALOG_H
#define SETTINGSINJECTORDIALOG_H

#include <QDialog>
#include <QSerialPort>

QT_BEGIN_NAMESPACE

namespace Ui {
class SettingsInjectorDialog;
}

class QIntValidator;

QT_END_NAMESPACE

class SettingsInjectorDialog : public QDialog
{
    Q_OBJECT

public:
    struct InjectorSettings {
        QString name1;
        QString name2;
        QString name3;
        qint32 speed1;
        qint32 speed2;
        qint32 speed3;
        double stepsPerMicrolitre1;
        double stepsPerMicrolitre2;
        double stepsPerMicrolitre3;
        double bubbleVolume1;
        double bubbleVolume2;
        double bubbleVolume3;
        double ejectMixVolume1;
        double ejectMixVolume2;
        double ejectMixVolume3;
        qint32 pwmUp1;
        qint32 pwmDown1;
        qint32 pwmUp2;
        qint32 pwmDown2;
        qint32 pwmUp3;
        qint32 pwmDown3;
    };

    explicit SettingsInjectorDialog(QWidget *parent = nullptr);
    ~SettingsInjectorDialog();

    InjectorSettings settings() const;

signals:
    void settingsInjectorApplyClicked();

private slots:
    void apply();

private:
    void updateSettings();
    void loadSettings();

private:
    Ui::SettingsInjectorDialog *m_ui = nullptr;
    InjectorSettings m_currentSettings;
    QIntValidator *m_intValidator = nullptr;
};

#endif // SETTINGSINJECTORDIALOG_H
