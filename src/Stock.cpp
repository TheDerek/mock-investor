//
// Created by derek on 25/07/16.
//

#include "Stock.h"

const long double Stock::equity()
{
    return (long double) quantity * company.getBid();
}
