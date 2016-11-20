/**
 * @file SessionList.cpp
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#include <QDebug>

#include "SessionList.h"

SessionList::SessionList()
{
    m_flowFactors.push_back(75.0 / 30.0);
    m_flowFactors.push_back(180.0 / 75.0);
    m_flowFactors.push_back(540.0 / 180.0);
    m_flowFactors.push_back(1620.0 / 540.0);
    m_flowFactors.push_back(6000.0 / 1620.0);
    m_flowFactors.push_back(18000.0 / 6000.0);

    m_fixFactors.push_back(2.5);
    m_fixFactors.push_back(2.5);
    m_fixFactors.push_back(2.5);
    m_fixFactors.push_back(2.5);
    m_fixFactors.push_back(2.5);
    m_fixFactors.push_back(2.5);

    const int iterations = 12 * 1000 * 1000;
    const int steps = 7;
    const qreal rate = 0.9;

    qreal baseBet = 30;

    fillList(m_list30_flow, m_flowFactors, iterations, steps, rate, baseBet);
    fillList(m_list30_fix, m_fixFactors, iterations, steps, rate, baseBet);

    baseBet = 60;

    fillList(m_list60_flow, m_flowFactors, iterations, steps, rate, baseBet);
    fillList(m_list60_fix, m_fixFactors, iterations, steps, rate, baseBet);

    baseBet = 100;

    fillList(m_list100_flow, m_flowFactors, iterations, steps, rate, baseBet);
    fillList(m_list100_fix, m_fixFactors, iterations, steps, rate, baseBet);

    baseBet = 300;

    fillList(m_list300_flow, m_flowFactors, iterations, steps, rate, baseBet);
    fillList(m_list300_fix, m_fixFactors, iterations, steps, rate, baseBet);
}

void SessionList::run()
{
    qInfo().noquote() << "Start...";

    runList(m_list30_flow);
    runList(m_list30_fix);

    runList(m_list60_flow);
    runList(m_list60_fix);

    runList(m_list100_flow);
    runList(m_list100_fix);

    runList(m_list300_flow);
    runList(m_list300_fix);

    qInfo().noquote() << "Finish";
}

void SessionList::print() const
{
    QString rowDelimiter("****************************************************************************************");
    QString headerTemplateFix("BASE BET: %1, FIX BET FACTORS");
    QString headerTemplateFlow("BASE BET: %1, FLOW BET FACTORS");

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << "START TEST RESULTS";
    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFlow.arg(30, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list30_flow);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFix.arg(30, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list30_fix);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFlow.arg(60, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list60_flow);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFix.arg(60, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list60_fix);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFlow.arg(100, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list100_flow);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFix.arg(100, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list100_fix);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFlow.arg(300, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list300_flow);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << headerTemplateFix.arg(300, 3);
    qInfo().noquote() << rowDelimiter;
    printList(m_list300_fix);

    qInfo().noquote() << rowDelimiter;
    qInfo().noquote() << "END TEST RESULTS";
    qInfo().noquote() << rowDelimiter;
}

void SessionList::fillList(QList<Session> &sessionList,
                           const QVector<qreal> &betFactors,
                           const int iterations,
                           const int steps,
                           const qreal rate,
                           const qreal baseBet)
{
    for(int probability = 50; probability <= 100; probability += 5)
    {
        sessionList.push_back(Session(baseBet, steps, iterations, probability, rate, betFactors));
    }
}

void SessionList::runList(QList<Session> &sessionList)
{
    for(Session &session : sessionList)
    {
        session.run();
    }
}

void SessionList::printList(const QList<Session> &sessionList) const
{
    for(const Session &session : sessionList)
    {
        session.print();
        qInfo().noquote() << "";
    }
}
