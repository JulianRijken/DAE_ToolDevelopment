// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include "ui_calculatorform.h"
#include "calculator.h"

class CalculatorForm : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorForm(QWidget *parent = nullptr);
   
private slots:
    
    void onValueChanged();

private:
    int m_first{};
    int m_second{};
    int m_result{};
    Ui::CalculatorForm m_ui;
    int CalculateResult(Calculator::CalcOperator operation);
    QString CalcOperatorToQString(Calculator::CalcOperator op) const;


};

#endif
