#include <bits/stdc++.h>

using namespace std;

struct Point {
    float x, y;
    
    Point() : x(0), y(0) {}
    Point(float x, float y) : x(x), y(y) {}
};

// Function to compute the area of a convex polygon using the shoelace theorem
float polygonArea(const vector<Point>& polygon) {
    int n = polygon.size();
    float area = 0.0f;
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        area += polygon[i].x * polygon[next].y;
        area -= polygon[next].x * polygon[i].y;
    }
    return fabs(area) / 2.0f;
}

// Function to rotate a point by a given angle (counterclockwise)
Point rotatePoint(const Point& p, float angle) {
    float rad = angle * M_PI / 180.0f; // Convert to radians
    float cosA = cos(rad);
    float sinA = sin(rad);
    return Point(p.x * cosA - p.y * sinA, p.x * sinA + p.y * cosA);
}

// Function to compute the minimum bounding box for a rotated polygon
pair<int, int> minimumBoundingBox(const vector<Point>& polygon) {
    int n = polygon.size();
    float minArea = FLT_MAX;
    int bestWidth = 0, bestHeight = 0;
    
    for (int i = 0; i < n; i++) {
        // Compute the edge direction as the vector from point i to point (i + 1)
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];
        float dx = p2.x - p1.x;
        float dy = p2.y - p1.y;
        
        // Calculate the angle to rotate the edge to align with the x-axis
        float angle = atan2(dy, dx) * 180.0f / M_PI;
        
        // Rotate all the points by this angle
        vector<Point> rotated;
        for (const Point& p : polygon) {
            rotated.push_back(rotatePoint(p, angle));
        }
        
        // Compute the bounding box for the rotated polygon
        float minX = FLT_MAX, maxX = -FLT_MAX, minY = FLT_MAX, maxY = -FLT_MAX;
        for (const Point& p : rotated) {
            minX = min(minX, p.x);
            maxX = max(maxX, p.x);
            minY = min(minY, p.y);
            maxY = max(maxY, p.y);
        }
        
        // Calculate the area of the bounding box
        int width = (int)ceil(maxX - minX);
        int height = (int)ceil(maxY - minY);
        int area = width * height;
        
        // Update the best rectangle if this one is smaller
        if (area < minArea) {
            minArea = area;
            bestWidth = min(width, height);
            bestHeight = max(width, height);
        }
    }
    
    return {bestWidth, bestHeight};
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    // Get the dimensions of the minimum bounding rectangle
    pair<int, int> result = minimumBoundingBox(polygon);
    cout << result.first << " " << result.second << endl;
    
    return 0;
}
