#ifndef TERRAINMAP_H
#define TERRAINMAP_H

#include <vector>
#include <QString>

// NOTE: '@' is a reserved character and has different functionality for
// most methods. Do not use as a regular value in the TerrainMap EVER.
// This character represents the keyword ALL.

// Test output for TerrainMap class.
void testTerrainMap();

class TerrainMap
{
public:
    TerrainMap(unsigned int const width, unsigned int const height);

    QString show();

    void fill(const char value);
    char at(const unsigned int xx, const unsigned int yy, const char def = '\0');
    bool set(const unsigned int xx, const unsigned int yy, const char value);
    bool replace(const unsigned int xx, const unsigned int yy, const char replace, const char value);

    void scatter(const char replace, const char value, const double chance);
    void automata(const char valueA, const char valueD);

private:
    unsigned int _width;
    unsigned int _height;

    std::vector<char> _mapList;
};

#endif // TERRAINMAP_H
