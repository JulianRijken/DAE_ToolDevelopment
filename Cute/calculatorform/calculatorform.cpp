// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "calculatorform.h"

CalculatorForm::CalculatorForm(QWidget* parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    connect(m_ui.inputSpinBox1, &QSpinBox::valueChanged, this, &CalculatorForm::onInputChanged);
    connect(m_ui.inputSpinBox2, &QSpinBox::valueChanged, this, &CalculatorForm::onInputChanged);
}

void CalculatorForm::onInputChanged()
{
    const int sum = m_ui.inputSpinBox1->value() + m_ui.inputSpinBox2->value();
    m_ui.outputWidget->setText(QString::number(sum));

}


void CalculatorForm::on_inputSpinBox1_Changed(int value)
{
    //const int sum = value + m_ui.inputSpinBox2->value();
    //m_ui.outputWidget->setText(QString::number(sum));
}
void CalculatorForm::on_inputSpinBox2_Changed(int value)
{
    //const int sum = value + m_ui.inputSpinBox1->value();
    //m_ui.outputWidget->setText(QString::number(sum));
}
