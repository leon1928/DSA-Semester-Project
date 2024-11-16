#pragma once
#include "Libraries.h"

template <typename T1 = void, typename T2 = void, typename T3 = void>
class Node
{
public:
    T1 First;
    T2 Second;
    T3 Third;

    Node() : First(), Second(), Third() {}

    Node(T1 FirstValue) : First(FirstValue), Second(), Third() {}

    Node(T1 FirstValue, T2 SecondValue) : First(FirstValue), Second(SecondValue), Third() {}

    Node(T1 FirstValue, T2 SecondValue, T3 ThirdValue) : First(FirstValue), Second(SecondValue), Third(ThirdValue) {}
};