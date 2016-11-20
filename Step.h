/**
 * @file Step.h
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#ifndef STEP_H
#define STEP_H

#include <QObject>

class Step
{
public:
    Step(int number = -1);

    int number() const;

    int positiveCount() const;
    int negativeCount() const;
    int totalCount() const;

    qreal winMoney() const;
    qreal lossMoney() const;
    qreal totalMoney() const;

    void addResult(qreal money);
    void print() const;

private:
    int m_number;

    int m_positiveCount;
    int m_negativeCount;

    qreal m_winMoney;
    qreal m_lossMoney;
};

#endif // STEP_H
