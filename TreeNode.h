#pragma once
#include <string>
#include "Violation.h"
using namespace std;

struct TreeNode
{
    string carNumber;
    Violation* violations;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string number, string violation)
    {
        carNumber = number;
        violations = new Violation(violation);
        left = nullptr;
        right = nullptr;
    }
};