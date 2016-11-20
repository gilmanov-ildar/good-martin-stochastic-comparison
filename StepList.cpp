/**
 * @file StepList.cpp
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#include <QDebug>

#include "StepList.h"
#include "Step.h"

StepList::StepList(int count)
{
    m_list.reserve(count);

    for(int i = 0; i < count; ++i)
    {
        m_list.push_back(Step(i));
    }
}

int StepList::positiveBets() const
{
    int result = 0;

    for(const Step &step : m_list)
    {
        result += step.positiveCount();
    }

    return result;
}

int StepList::negativeBets() const
{
    int result = 0;

    for(const Step &step : m_list)
    {
        result += step.negativeCount();
    }

    return result;
}

int StepList::totalBets() const
{
    int result = 0;

    for(const Step &step : m_list)
    {
        result += step.totalCount();
    }

    return result;
}

qreal StepList::winMoney() const
{
    qreal result = 0;

    for(const Step &step : m_list)
    {
        result += step.winMoney();
    }

    return result;
}

qreal StepList::lossMoney() const
{
    qreal result = 0;

    for(const Step &step : m_list)
    {
        result += step.lossMoney();
    }

    return result;
}

qreal StepList::totalMoney() const
{
    qreal result = 0;

    for(const Step &step : m_list)
    {
        result += step.totalMoney();
    }

    return result;
}

void StepList::addStepResult(int step, qreal money)
{
    Q_ASSERT(step < m_list.count());

    m_list[step].addResult(money);
}

void StepList::print() const
{
    qDebug().noquote()
            << QString("Total Bets: %1, +: %2, -: %3, Money +: %4, Money -: %5, Money Total: %6")
               .arg(totalBets() / 1000)
               .arg(positiveBets() / 1000)
               .arg(negativeBets() / 1000)
               .arg(winMoney() / 1000)
               .arg(lossMoney() / 1000)
               .arg(totalMoney() / 1000);

    for(const Step &step : m_list)
    {
        step.print();
    }
}
