// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include "calculatorform.h"

CalculatorForm::CalculatorForm(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    connect(m_ui.inputSpinBox1, &QSpinBox::valueChanged, this, &CalculatorForm::onValueChanged);
    connect(m_ui.inputSpinBox2, &QSpinBox::valueChanged, this, & CalculatorForm::onValueChanged);
    connect(m_ui.operatorSelector, &QComboBox::currentIndexChanged, this, &CalculatorForm::onValueChanged);

    m_ui.operatorSelector->addItem(QString("Add"));
    m_ui.operatorSelector->addItem(QString("Subtract"));
    m_ui.operatorSelector->addItem(QString("Multiply"));
    m_ui.operatorSelector->addItem(QString("Divide"));
    m_ui.operatorSelector->addItem(QString("Modulo"));
}

void CalculatorForm::onValueChanged() 
{
    m_first = m_ui.inputSpinBox1->value();
    m_second = m_ui.inputSpinBox2->value();
    Calculator::CalcOperator op = (Calculator::CalcOperator)m_ui.operatorSelector->currentIndex();
    m_result = CalculateResult(op);


    m_ui.listWidget->addItem(QString("Calculation: %1 %2 %3 = %4").arg( QString::number(m_first), CalcOperatorToQString(op), QString::number(m_second), QString::number(m_result)));

    m_ui.outputWidget->setText(QString::number(m_result));
}

QString CalculatorForm::CalcOperatorToQString(Calculator::CalcOperator op) const
{
    switch (op) 
    {
        default:
        case Calculator::CalcOperator::Add: return QString("+");
        case Calculator::CalcOperator::Subtract: return QString("-");
        case Calculator::CalcOperator::Multiply: return QString("*");
        case Calculator::CalcOperator::Divide: return QString("/");
        case Calculator::CalcOperator::Modulo: return QString("%");
    }
}

int CalculatorForm::CalculateResult(Calculator::CalcOperator op)
{
    Calculator calc{};
    return calc.Calculate(m_first,m_second,op);
}

