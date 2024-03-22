// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include "ui_calculatorform.h"

class CalculatorForm : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorForm(QWidget *parent = nullptr);

private slots:
    void on_inputSpinBox1_Changed(int value);
    void on_inputSpinBox2_Changed(int value);

private:
    Ui::CalculatorForm m_ui;
};

#endif
