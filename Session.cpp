/**
 * @file Session.cpp
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#include <QDateTime>
#include <QDebug>

#include "Session.h"

Session::Session(qreal baseBet,
                 int steps,
                 int iterations,
                 int probability,
                 qreal rate,
                 const QVector<qreal> &betFactors) :
    m_baseBet(baseBet),
    m_steps(steps),
    m_iterations(iterations),
    m_probability(probability),
    m_rate(rate),
    m_betFactors(betFactors),
    m_stepList(m_steps)
{
    Q_ASSERT(m_baseBet > 0);
    Q_ASSERT(m_steps > 0);
    Q_ASSERT(m_iterations > 0);
    Q_ASSERT(m_probability >= 0);
    Q_ASSERT(m_probability <= 100);
    Q_ASSERT(m_rate >= 0.0);
    Q_ASSERT(m_rate <= 1.0);
    Q_ASSERT(m_betFactors.count() == m_steps - 1);
}

qreal Session::baseBet() const
{
    return m_baseBet;
}

int Session::steps() const
{
    return m_steps;
}

int Session::iterations() const
{
    return m_iterations;
}

int Session::probability() const
{
    return m_probability;
}

qreal Session::rate() const
{
    return m_rate;
}

QVector<qreal> Session::betFactors() const
{
    return m_betFactors;
}

void Session::run()
{
    std::srand(QDateTime::currentDateTime().toTime_t());

    qreal bet = m_baseBet;
    int step = 0;

    for(int i = 0; i < m_iterations; ++i)
    {
        if(runBet())
        {
            m_stepList.addStepResult(step, bet * m_rate);

            bet = m_baseBet;
            step = 0;
        }
        else
        {
            m_stepList.addStepResult(step, -bet);

            if(step < m_steps - 1)
            {
                bet *= m_betFactors[step];
                step++;
            }
            else
            {
                bet = m_baseBet;
                step = 0;
            }
        }
    }
}

void Session::print() const
{
    QString betFactorsString;

    for(qreal factor : m_betFactors)
    {
        if(!betFactorsString.isEmpty())
        {
            betFactorsString.push_back(", ");
        }

        betFactorsString.push_back(QString::number(factor));
    }

    qInfo().noquote()
            << QString("Base Bet: %1, Probability: %2, Rate: %3, Steps: %4, Iterations: %5, Bet Factors: [%6]")
               .arg(m_baseBet, 3)
               .arg(m_probability / 100.0, 0, 'f', 2, '0')
               .arg(m_rate)
               .arg(m_steps)
               .arg(m_iterations)
               .arg(betFactorsString);

    qInfo().noquote()
            << QString("Gain Without Martin: Money +: %1, Money -: %2, Total Money: %3")
               .arg(m_iterations * m_baseBet * (m_probability) / 100.0)
               .arg(m_iterations * m_baseBet * (100.0 - m_probability) / 100.0, 0)
               .arg(m_iterations * m_baseBet * (m_probability - 50.0) / 100.0, 0);

    m_stepList.print();
}

bool Session::runBet()
{
    int result = std::rand() % 100;
    return result < m_probability;
}
