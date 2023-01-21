#include <stdio.h>
#include "cub3d.h"
struct Vector3 {
    float x, y, z;
};

struct Sphere {
    Vector3 position;
    float radius;
};

// Function to check if the ray intersects with the sphere
int intersects(Vector3 rayStart, Vector3 rayDir, Sphere sphere)
{
    Vector3 sphereToRay = {rayStart.x - sphere.position.x, rayStart.y - sphere.position.y, rayStart.z - sphere.position.z};
    float b = 2.0f * (rayDir.x * sphereToRay.x + rayDir.y * sphereToRay.y + rayDir.z * sphereToRay.z);
    float c = sphereToRay.x * sphereToRay.x + sphereToRay.y * sphereToRay.y + sphereToRay.z * sphereToRay.z - sphere.radius * sphere.radius;
    float discriminant = b * b - 4.0f * c;
    return discriminant > 0;
}

int main()
{
    Vector3 rayStart = {0, 0, 0}; // Starting point of the ray
    Vector3 rayDir = {1, 1, 1}; // Direction of the ray
    Sphere sphere = {{5, 5, 5}, 3}; // Sphere to check for intersection

    if (intersects(rayStart, rayDir, sphere)) {
        printf("Ray intersects with sphere!\n");
    } else {
        printf("Ray does not intersect with sphere.\n");
    }

    return 0;
}