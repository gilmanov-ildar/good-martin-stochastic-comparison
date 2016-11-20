/**
 * @file StepList.h
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#ifndef STEPLIST_H
#define STEPLIST_H

#include <QVector>
#include "Step.h"

class StepList
{
public:
    StepList(int count);

    int positiveBets() const;
    int negativeBets() const;
    int totalBets() const;

    qreal winMoney() const;
    qreal lossMoney() const;
    qreal totalMoney() const;

    void addStepResult(int step, qreal money);

    void print() const;

private:
    QVector<Step> m_list;
};

#endif // STEPLIST_H
