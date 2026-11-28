
#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree t;

    t.add(50);
    t.add(50);
    t.add(40);
    t.add(30);
    t.add(45);
    t.add(60);
    t.add(70);
    t.add(65);

    cout << "Original Tree (LDR): ";
    t.displayLDR();

    cout << "\nParent Tests:\n";

    cout << "Parent of 60: " << t.getParentData(60) << endl;
    cout << "Parent of 50: " << t.getParentData(50) << endl;
    cout << "Parent of 65: " << t.getParentData(65) << endl;
    cout << "Parent of 45: " << t.getParentData(45) << endl;

    cout << "\nSearch Tests:\n";

    cout << (t.getNodeData(60) ? "Found" : "Not Found") << endl;
    cout << (t.getNodeData(100) ? "Found" : "Not Found") << endl;

    cout << "\nMaximum Right Tests:\n";

    cout << "Max Right of 40: " << t.maxRightData(40) << endl;
    cout << "Max Right of 50: " << t.maxRightData(50) << endl;

    cout << "\nHeight Tests:\n";

    cout << "DFS Height: " << t.maxDepthDFS() << endl;
    cout << "BFS Height: " << t.maxDepthBFS() << endl;

    cout << "\nDelete Leaf Node (30):\n";

    t.removeNode(30);
    t.displayLDR();

    cout << "\nDelete Node With One Child (60):\n";

    t.removeNode(60);
    t.displayLDR();

    cout << "\nDelete Node With Two Children (40):\n";

    t.removeNode(40);
    t.displayLDR();

    cout << "\nDelete Root (50):\n";

    t.removeNode(50);
    t.displayLDR();

    cout << "\nFinal Height:\n";

    cout << "DFS: " << t.maxDepthDFS() << endl;
    cout << "BFS: " << t.maxDepthBFS() << endl;

    return 0;
}
