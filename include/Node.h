#ifndef NODE_H
#define NODE_H

struct Node {
    int id;           // Unique node identifier
    double x, y;      // Coordinates
    bool isBoundary;  // Flag for boundary nodes

    Node(int id, double x, double y, bool isBoundary = false)
        : id(id), x(x), y(y), isBoundary(isBoundary) {}
};

#endif
