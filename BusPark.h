#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Bus {
    int busNumber;
    string driverLastName;
    string driverFirstName;
    int routeNumber;
    int seatCount;
};

struct TreeNode {
    Bus bus;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Bus b);
};

class BusPark {
public:
    BusPark();
    void insertBus(Bus bus);
    TreeNode* searchBus(int busNumber);
    void displayBuses();
    void saveToFile(const string& filename);

private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, Bus bus);
    TreeNode* search(TreeNode* node, int busNumber);
    void inOrderDisplay(TreeNode* node);
    void saveToFileInOrder(TreeNode* node, ofstream& outFile);
};

void showMenu();

