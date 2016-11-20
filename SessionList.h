/**
 * @file SessionList.h
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#ifndef SESSIONLIST_H
#define SESSIONLIST_H

#include <QList>
#include <QVector>

#include "Session.h"

class SessionList
{
public:
    SessionList();

    void run();
    void print() const;

private:
    QVector<qreal> m_flowFactors;
    QVector<qreal> m_fixFactors;

    QList<Session> m_list30_flow;
    QList<Session> m_list30_fix;

    QList<Session> m_list60_flow;
    QList<Session> m_list60_fix;

    QList<Session> m_list100_flow;
    QList<Session> m_list100_fix;

    QList<Session> m_list300_flow;
    QList<Session> m_list300_fix;

    void fillList(QList<Session> &sessionList,
                  const QVector<qreal> &betFactors,
                  const int iterations,
                  const int steps,
                  const qreal rate,
                  const qreal baseBet);

    void runList(QList<Session> &sessionList);
    void printList(const QList<Session> &sessionList) const;
};

#endif // SESSIONLIST_H
