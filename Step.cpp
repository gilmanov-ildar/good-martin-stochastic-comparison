/**
 * @file Step.cpp
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#include <QDebug>

#include "Step.h"

Step::Step(int number) :
    m_number(number),
    m_positiveCount(0),
    m_negativeCount(0),
    m_winMoney(0.0),
    m_lossMoney(0.0)
{
}

int Step::number() const
{
    return m_number;
}

int Step::positiveCount() const
{
    return m_positiveCount;
}

int Step::negativeCount() const
{
    return m_negativeCount;
}

int Step::totalCount() const
{
    return m_positiveCount + m_negativeCount;
}

qreal Step::winMoney() const
{
    return m_winMoney;
}

qreal Step::lossMoney() const
{
    return m_lossMoney;
}

qreal Step::totalMoney() const
{
    return m_winMoney + m_lossMoney;
}

void Step::addResult(qreal money)
{
    if(money >= 0)
    {
        m_positiveCount++;
        m_winMoney += money;
    }
    else
    {
        m_negativeCount++;
        m_lossMoney += money;
    }
}

void Step::print() const
{
    qDebug().noquote()
            << QString("Step: %1, Total bets: %2, +: %3, -: %4, Money +: %5, Money -: %6, Money Total: %7")
               .arg(number() + 1)
               .arg(totalCount() / 1000)
               .arg(positiveCount() / 1000)
               .arg(negativeCount() / 1000)
               .arg(winMoney() / 1000)
               .arg(lossMoney() / 1000)
               .arg(totalMoney() / 1000);
}
