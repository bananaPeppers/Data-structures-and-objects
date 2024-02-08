#include <iostream>
#include <sstream>
#include "point.h"

using namespace std;

// functions
void findHull(point p[], int, point hull[], int);
bool insideHull(point, point[], int);
bool turnsLeft(point, point, point);
bool isLessThan(point, point);
int compare(const void *, const void *);

// global variables
int SIZE = 100;

int main()
{
    // variables and initialzations
    int nCops, nPeople, nRobbers, ncHull, nrHull;
    point cops[SIZE], copHull[SIZE], robbers[SIZE], robberHull[SIZE], person;
    int safe = 0, robbed = 0, inDanger = 0;

    // get the input
    cin >> nCops >> nRobbers >> nPeople;

    // points for cops
    for (int count = 0; count < nCops; count++)
        cin >> cops[count];

    // points for robbers
    for (int count = 0; count < nRobbers; count++)
        cin >> robbers[count];

    // find hull for cops and robbers
    findHull(cops, nCops, copHull, ncHull);
    findHull(robbers, nRobbers, robberHull, nrHull);

    // more calculations

    for (int count = 0; count < nPeople; count++)
    {
        cin >> person;
        // check inside hull
        if (insideHull(person, copHull, ncHull))
        {
            safe++;
        }
        else if (insideHull(person, robberHull, nrHull))
        {
            robbed++;
        }
        else
        {
            inDanger++;
        }
    }

    // print out the output
    cout << "Safe: " << safe << endl;
    cout << "robbed: " << robbed << endl;
    cout << "In Danger: " << inDanger << endl;

    return 0;
}

// find hull function
void findHull(point p[], int k, point hull[], int &nHull)
{
    int32_t t = 1, u = 1;
    point lower[k], upper[k];

    // sort on x coords
    qsort(p, k, sizeof(point), compare);

    // lower half of polygon
    lower[0] = p[0];
    for (int count = 1; count <= t - 1; count++)
    {
        while ((t > 0) && !turnsLeft(lower[t - 1], lower[t], p[count]))
        {
            t = t - 1;
        }
        t = t + 1;
        lower[t] = p[count];
    }

    // upper half of polygon
    upper[0] = p[t - 1];
    for (int count = t - 2; count >= 0; count--)
    {
        while ((u > 0) && !turnsLeft(upper[u - 1], upper[u], p[count]))
        {
            u = u - 1;
        }
        u = u + 1;
        upper[u] = p[count];
    }

    nHull = 0;
    for (int i = 0; i < t; i++)
        hull[nHull++] = lower[i];
    for (int i = 0; i < u; i++)
        hull[nHull++] = upper[i];
}

// inside hull function
bool insideHull(point p, point hull[], int k)
{
    for (int count = 0; count < k; count++)
    {
        int a = (count + 1) % k;
        if (turnsLeft(hull[count], hull[a], p))
        {
            return false;
        }
    }
    return true;
}

int compare(const void *a, const void *b)
{
    point *pa = (point *)a, *pb = (point *)b;

    if (pa->getX() < pb->getX())
        return -1;
    if (pa->getX() > pb->getX())
        return 1;
    return (pa->getY() > pb->getY()) - (pa->getY() < pb->getY());
}

bool turnsLeft(point a, point b, point c)
{

    return (b - a) * (c - a) > 0;
}

bool isLessThan(point a, point b)
{

    if (a.getX() < b.getX())
        return true;
    else if (a.getX() > b.getX())
        return false;
    return a.getY() < b.getY();
}
