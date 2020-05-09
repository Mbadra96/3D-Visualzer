#pragma once
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Shape.h"

class Model : public Shape
{
public:
	Model(const std::string& filepath,float r=1.0f,float g =1.0f,float b = 1.0f, float a = 1.0f);
	void Draw(Shader& shader) override;
	~Model() override;
private:
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Mesh> m_Meshes;
	
};

