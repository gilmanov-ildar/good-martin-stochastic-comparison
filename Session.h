/**
 * @file Session.h
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#ifndef SESSION_H
#define SESSION_H

#include "StepList.h"

class Session
{
public:
    Session(qreal baseBet,
            int steps,
            int iterations,
            int probability,
            qreal rate,
            const QVector<qreal> &betFactors);

    qreal baseBet() const;
    int steps() const;
    int iterations() const;
    int probability() const;
    qreal rate() const;
    QVector<qreal> betFactors() const;

    void run();
    void print() const;

private:
    qreal m_baseBet;
    int m_steps;
    int m_iterations;

    /// Probability of win in each bet, from 0 to 100
    int m_probability;

    qreal m_rate;

    QVector<qreal> m_betFactors;
    StepList m_stepList;

    bool runBet();
};

#endif // SESSION_H
