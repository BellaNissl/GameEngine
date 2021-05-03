#include "EnginePch.h"
#include <MyEngine.h>

class Sandbox : public MyEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

MyEngine::Application* MyEngine::CreateApplication() {
	// read from file in the format:
	// rowAmount, colAmount, width, height \n
	// 0s and 1s for each Tile telling if it is walkable or not
	//std::string fileInfo = 
	//	"4, 5, 200, 250\n0 0 0 0 1\n0 0 1 0 1\n0 0 1 0 1\n0 0 1 1 1"; 
	//	  
	//PathAPI::Map map(fileInfo);

	//Vector<PathAPI::Tile> tiles = Vector<PathAPI::Tile>(); // read from file
	//map = PathAPI::Map(tiles, 4, 5);

	//PathAPI::Path path(map);

	//Vector2 startPos(5.0, 5.0);
	//Vector2 endPos(340.0, 340.0);

	//if (path.FindPath(startPos, endPos)) {
	//	auto tiles = path.getTiles();	
	//	//Interpolate over found tiles
	//}

	return new Sandbox();
}