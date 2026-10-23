#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>

namespace Geometry {

/**
 * @brief Represents a 2D point with integer coordinates.
 */
struct Point2D {
    int x{0};
    int y{0};
};

/**
 * @brief Represents an Axis-Aligned Bounding Box (AABB) in 2D space.
 */
struct AABB2D {
    Point2D min;
    Point2D max;

    /**
     * @brief Constructs a normalized AABB where min <= max on both axes.
     */
    constexpr AABB2D(int x1, int y1, int x2, int y2) noexcept
        : min{std::min(x1, x2), std::min(y1, y2)},
          max{std::max(x1, x2), std::max(y1, y2)} {}

    constexpr AABB2D(Point2D p1, Point2D p2) noexcept
        : min{std::min(p1.x, p2.x), std::min(p1.y, p2.y)},
          max{std::max(p1.x, p2.x), std::max(p1.y, p2.y)} {}
};

/**
 * @brief Represents a circle in 2D space.
 */
struct Circle2D {
    Point2D center;
    int radius{0};
};

/**
 * @brief Checks if a 2D circle overlaps with an axis-aligned bounding box (AABB).
 * 
 * Algorithm:
 * 1. Find the point on/inside the AABB closest to the circle's center using coordinate clamping.
 * 2. Calculate the squared Euclidean distance between this closest point and the circle center.
 * 3. Compare the squared distance against the squared radius using 64-bit arithmetic to prevent overflow.
 * 
 * Complexity:
 * - Time Complexity:  O(1)
 * - Space Complexity: O(1)
 * 
 * @param circle The circle definition (center and radius).
 * @param box The axis-aligned bounding box.
 * @return true if the circle and box intersect or touch, false otherwise.
 */
[[nodiscard]] constexpr bool checkOverlap(const Circle2D& circle, const AABB2D& box) noexcept {
    if (circle.radius < 0) {
        return false;
    }

    // Find the closest point (cx, cy) on the AABB to the circle center
    const int closestX = std::clamp(circle.center.x, box.min.x, box.max.x);
    const int closestY = std::clamp(circle.center.y, box.min.y, box.max.y);

    // Calculate distance deltas using 64-bit integers to prevent overflow during squaring
    const auto dx = static_cast<std::int64_t>(closestX - circle.center.x);
    const auto dy = static_cast<std::int64_t>(closestY - circle.center.y);
    const auto r  = static_cast<std::int64_t>(circle.radius);

    return (dx * dx + dy * dy) <= (r * r);
}

} // namespace Geometry

/**
 * @brief Standard Solution wrapper for LeetCode / competitive interface compatibility.
 */
class Solution {
public:
    /**
     * @brief Checks if a circle overlaps with a rectangle aligned with the Cartesian axes.
     * 
     * @param radius  Radius of the circle (>= 0).
     * @param xCenter X-coordinate of the circle's center.
     * @param yCenter Y-coordinate of the circle's center.
     * @param x1      X-coordinate of the rectangle's first corner.
     * @param y1      Y-coordinate of the rectangle's first corner.
     * @param x2      X-coordinate of the rectangle's opposite corner.
     * @param y2      Y-coordinate of the rectangle's opposite corner.
     * @return true if the circle and rectangle have at least one common point, false otherwise.
     */
    [[nodiscard]] constexpr bool checkOverlap(
        int radius,
        int xCenter,
        int yCenter,
        int x1,
        int y1,
        int x2,
        int y2
    ) const noexcept {
        const Geometry::Circle2D circle{{xCenter, yCenter}, radius};
        const Geometry::AABB2D box{x1, y1, x2, y2};
        return Geometry::checkOverlap(circle, box);
    }
};

// -----------------------------------------------------------------------------
// Test Suite / Verification
// -----------------------------------------------------------------------------
static void runUnitTests() {
    Solution solver;

    // Test Case 1: Standard overlapping circle (center outside, overlapping edge)
    assert(solver.checkOverlap(1, 0, 0, 1, -1, 3, 1) == true);

    // Test Case 2: Circle completely outside and separated
    assert(solver.checkOverlap(1, 1, 1, 1, -3, 2, -1) == false);

    // Test Case 3: Circle center inside rectangle
    assert(solver.checkOverlap(1, 0, 0, -1, -1, 1, 1) == true);

    // Test Case 4: Rectangle completely inside circle
    assert(solver.checkOverlap(10, 0, 0, -1, -1, 1, 1) == true);

    // Test Case 5: Touching exactly at corner
    assert(solver.checkOverlap(5, 0, 0, 3, 4, 10, 10) == true);

    // Test Case 6: Inverted corner coordinates (x1 > x2, y1 > y2)
    assert(solver.checkOverlap(1, 0, 0, 3, 1, 1, -1) == true);

    // Test Case 7: Zero radius (point-in-box check)
    assert(solver.checkOverlap(0, 2, 2, 1, 1, 3, 3) == true);
    assert(solver.checkOverlap(0, 0, 0, 1, 1, 3, 3) == false);

    std::cout << "All unit tests passed successfully!\n";
}

int main() {
    runUnitTests();
    return 0;
}