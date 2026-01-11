#pragma once
#include <string>
#include "TreeNode.h"
using namespace std;

class TrafficDatabase
{
    TreeNode* root;

    TreeNode* insert(TreeNode* node, string number, string violation);
    TreeNode* find(TreeNode* node, string number);

    void printAll(TreeNode* node);
    void printRange(TreeNode* node, string from, string to);
    void printViolations(Violation* head);

public:
    TrafficDatabase();
    void addTicket(string number, string violation);
    void printAll();
    void printByNumber(string number);
    void printByRange(string from, string to);
};
