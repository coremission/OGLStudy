#ifndef MESHMANAGER_h
#define MESHMANAGER_h

#include "Mesh.h"

#include <map>
#include <string>
#include <memory>

class MeshManager
{
private:
	static std::map<std::string, std::shared_ptr<Mesh>> meshMap;
public:
	static std::shared_ptr<Mesh> registerMesh(std::string id, std::vector<VertexData> vertices);
	static std::shared_ptr<Mesh> getQuadMesh();
};

#endif //MESHMANAGER_h