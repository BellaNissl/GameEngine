#pragma once
#include "Vector2.h"
#include "Vector.h"

namespace PathAPI {
	/*
	*  This struct are the tiles the map consists of
	*/
	struct MY_ENGINE_API Tile {
		/*
		*  The upper left position of the tile
		*/
		Vector2 topPosition;

		/*
		*  The lower right position of the tile
		*/
		Vector2 bottomPosition;

		/*
		*  boolean that tells if the tile is walkable
		*/
		bool walkable;
	};

	/*
	*  This class creates a map of tiles
	*/
	class MY_ENGINE_API Map {
	public:
		/*
		*  Creates a Map with the info read from a string
		*  Sets rows, cols, width, height, tileWidth, tileHeight
		*  and creates tiles
		*  @param fileInfo is a string in the format 
		*  rowAmount, colAmount, width, height \n
		*  0s and 1s for each Tile telling if it is walkable or not 
		* 
		*  e.g.
		*  4, 5, 200, 250
		*  0 0 0 0 1
		*  0 0 1 0 1
		*  0 0 1 0 1
		*  0 0 1 1 1
		*/
		Map(std::string info);

		/*
		*  Creates a Map with the tiles known
		*  Sets rows, cols, width, height, tileWidth, tileHeight and tiles
		*  @param tiles of the map
		*  @param rows of the map
		*  @param columns of the map
		*/
		Map(const Vector<Tile>& tiles, const unsigned int& rows, const unsigned int& cols);
		
		/*
		*  Getter for the amount rows of the map
		*  @return the amount of rows in the map
		*/
		const unsigned int getRows() const;

		/*
		*  Getter for the amount of columns of the map
		*  @return the amount of columns in the map
		*/
		const unsigned int getColumns() const;

		/*
		*  Getter for the tiles vector
		*  @return the pointer to the vector object of all tiles
		*/
		const Vector<Tile>* getTiles() const;

		/*
		*  Getter for the width of the tiles
		*  @return width of the tiles
		*/
		const float getTileWidth() const;

		/*
		*  Getter for the heigth of the tiles
		*  @return heigth of the tiles
		*/
		const float getTileHeight() const;

		/*
		*  Getter for the width of the map
		*  @return width of the map
		*/
		const float getWidth() const;

		/*
		*  Getter for the heigth of the map
		*  @return heigth of the map
		*/
		const float getHeight() const;

	private:
		/*
		*  The amount of rows in the map
		*/
		unsigned int rows;

		/*
		*  The amount of columns in the map
		*/
		unsigned int cols;

		/*
		*  The width of the tiles
		*/
		float tileWidth;

		/*
		*  The height of the tiles
		*/
		float tileHeigth;

		/*
		*  The width of the map
		*/
		float width;

		/*
		*  The height of the map
		*/
		float heigth;

		/*
		*  Pointer to all the tiles of the map
		*/
		Vector<Tile>* tiles;
	};

	/*
	*  This class handles the pathfinding
	*/
	class MY_ENGINE_API Path {
	public:
		/* 
		*  Creates the path
		*  @param map is a map where the path should be found on
		*/
		Path(Map map);

		/*
		*  Looks for a path from start to finish
		*  @param start is the starting position of the path
		*  @param end is the end position of the path
		*  @return true if a path was found
		*/
		bool FindPath(const Vector2& start, const Vector2& end);

		/*
		*  Finds the fastest path from start to end 
		*  @param start is the starting position of the path
		*  @param end is the end position of the path
		*  @return true if a path was found
		*/
		bool FindOptimizedPath(const Vector2& start, const Vector2& end);

		/*
		*  Looks for a path going through all the passed destinations 
		*  @param destinations are all the destinations the path should visit
		*  @return true if a path was found
		*/
		bool FindPath(const Vector<Vector2>& destinations);

		/*
		*  Finds the fastest path containing all the passed destinations
		*  @param destinations are all the destinations the path should visit
		*  @return true if a path was found
		*/
		bool FindOptimizedPath(const Vector<Vector2>& destinations);

		/*
		*  Getter for the tiles
		*  @return the found tiles as a pointer
		*/
		const Vector<Tile>* getTiles() const;

	private:

		/*
		*  The found path in tiles on the map
		*/
		Vector<Tile>* tiles;
	};
}