#pragma once
#include <string>
using namespace std;
struct Violation
{
    string description;
    Violation* next;

    Violation(string desc)
    {
        description = desc;
        next = nullptr;
    }
};