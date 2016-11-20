/**
 * @file main.cpp
 * @brief
 * @details
 * @date Created on 20.11.2016
 * @copyright 2016 DDwarf LLC, <dev@ddwarf.org>
 * @author Gilmanov Ildar <dev@ddwarf.org>
 */

#include "SessionList.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    SessionList sessionList;
    sessionList.run();
    sessionList.print();
}
