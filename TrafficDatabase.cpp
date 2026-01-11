#include <iostream>
#include "TrafficDatabase.h"
using namespace std;

TrafficDatabase::TrafficDatabase()
{
    root =nullptr;
}

TreeNode* TrafficDatabase::insert(TreeNode* node, string number, string violation)
{
    if (node == nullptr)
    {
        return new TreeNode(number, violation);
    }

    if (number < node->carNumber)
    {
        node->left = insert(node->left, number, violation);
    }
    else if (number > node->carNumber)
    {
        node->right = insert(node->right, number, violation);
    }
    else
    {
        Violation* newViolation = new Violation(violation);
        newViolation->next = node->violations;
        node->violations = newViolation;
    }
    return node;
}

void TrafficDatabase::addTicket(string number, string violation)
{
    root = insert(root, number, violation);
}

void TrafficDatabase::printViolations(Violation* head)
{
    Violation* current = head;
    while (current != nullptr)
    {
        cout << " - " << current->description << endl;
        current = current->next;
    }
}

void TrafficDatabase::printAll(TreeNode* node)
{
    if (node == nullptr) return;

    printAll(node->left);

    cout << "Car number: " << node->carNumber << endl;
    cout << "Violations:" << endl;
    printViolations(node->violations);
    cout << endl;

    printAll(node->right);
}

void TrafficDatabase::printAll()
{
    cout << "=== Full database ===" << endl;
    printAll(root);
}

TreeNode* TrafficDatabase::find(TreeNode* node, string number)
{
    if (node == nullptr) return nullptr;

    if (number == node->carNumber)
        return node;
    else if (number < node->carNumber)
        return find(node->left, number);
    else
        return find(node->right, number);
}

void TrafficDatabase::printByNumber(string number)
{
    TreeNode* result = find(root, number);

    if (result == nullptr)
    {
        cout << "No data for car number: " << number << endl;
        return;
    }

    cout << "Car number: " << result->carNumber << endl;
    cout << "Violations:" << endl;
    printViolations(result->violations);
    cout << endl;
}

void TrafficDatabase::printRange(TreeNode* node, string from, string to)
{
    if (node == nullptr) return;

    if (node->carNumber > from)
        printRange(node->left, from, to);

    if (node->carNumber >= from && node->carNumber <= to)
    {
        cout << "Car number: " << node->carNumber << endl;
        cout << "Violations:" << endl;
        printViolations(node->violations);
        cout << endl;
    }

    if (node->carNumber < to)
        printRange(node->right, from, to);
}

void TrafficDatabase::printByRange(string from, string to)
{
    cout << "=== Cars from " << from << " to " << to << " ===" << endl;
    printRange(root, from, to);
}