#include "BusPark.h"

TreeNode::TreeNode(Bus b) : bus(b), left(nullptr), right(nullptr) {}

BusPark::BusPark() : root(nullptr) {}

void BusPark::insertBus(Bus bus) {
    root = insert(root, bus);
}

TreeNode* BusPark::searchBus(int busNumber) {
    return search(root, busNumber);
}

void BusPark::displayBuses() {
    inOrderDisplay(root);
}

void BusPark::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        saveToFileInOrder(root, outFile);
        outFile.close();
    }
    else {
        cout << "Unable to open file";
    }
}

TreeNode* BusPark::insert(TreeNode* node, Bus bus) {
    if (node == nullptr) {
        return new TreeNode(bus);
    }

    if (bus.busNumber < node->bus.busNumber) {
        node->left = insert(node->left, bus);
    }
    else if (bus.busNumber > node->bus.busNumber) {
        node->right = insert(node->right, bus);
    }

    return node;
}

TreeNode* BusPark::search(TreeNode* node, int busNumber) {
    if (node == nullptr || node->bus.busNumber == busNumber) {
        return node;
    }

    if (busNumber < node->bus.busNumber) {
        return search(node->left, busNumber);
    }
    else {
        return search(node->right, busNumber);
    }
}

void BusPark::inOrderDisplay(TreeNode* node) {
    if (node != nullptr) {
        inOrderDisplay(node->left);
        cout << "Bus Number: " << node->bus.busNumber << ", Driver: " << node->bus.driverLastName << " " << node->bus.driverFirstName
            << ", Route Number: " << node->bus.routeNumber << ", Seat Count: " << node->bus.seatCount << endl;
        inOrderDisplay(node->right);
    }
}

void BusPark::saveToFileInOrder(TreeNode* node, ofstream& outFile) {
    if (node != nullptr) {
        saveToFileInOrder(node->left, outFile);
        outFile << "Bus Number: " << node->bus.busNumber << ", Driver: " << node->bus.driverLastName << " " << node->bus.driverFirstName
            << ", Route Number: " << node->bus.routeNumber << ", Seat Count: " << node->bus.seatCount << endl;
        saveToFileInOrder(node->right, outFile);
    }
}

void showMenu() {
    cout << "1. Add bus" << endl;
    cout << "2. Search bus by number" << endl;
    cout << "3. Display all buses" << endl;
    cout << "4. Save buses to file" << endl;
    cout << "5. Exit" << endl;
}

