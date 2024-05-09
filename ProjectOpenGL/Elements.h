#pragma once
void addBuildingType1(int buildingTextureId1) {
	int boardLength = 100;
	int boardWidth = 100;
	float marginOffset = 5.0f;

	float buildingWidth = 5.0f;
	float buildingHeight = 8.0f;
	float buildingDepth = 5.0f;

	for (int i = 0; i < 10; i++) {
		float posX = marginOffset + i * 10;
		float posY = 0;
		float posZ = marginOffset;

		drawBuilding(posX, posY, posZ, buildingWidth, buildingHeight, buildingDepth, buildingTextureId1);

		posZ = boardWidth - marginOffset;
		drawBuilding(posX, posY, posZ, buildingWidth, buildingHeight, buildingDepth, buildingTextureId1);
	}
}

void addBuildingsType2(int buildingTextureId2) {
	int boardLength = 100;
	int boardWidth = 100;
	float buildingWidth = 2.0f;
	float buildingHeight = 8.0f;
	float buildingDepth = 5.0f;

	for (int i = 0; i < 5; i++) {
		float posX = 25 + i * 15;
		float posY = 0;
		float posZ = 25;

		drawBuilding(posX, posY, posZ, buildingWidth, buildingHeight, buildingDepth, buildingTextureId2);

		posZ = boardWidth - 20;
		drawBuilding(posX, posY, posZ, buildingWidth, buildingHeight, buildingDepth, buildingTextureId2);
	}
}

void addBuildingsType3(int buildingTextureId3) {
	int boardLength = 100;
	int boardWidth = 100;

	float buildingWidth = 2.0f;
	float buildingHeight = 4.0f;
	float buildingDepth = 2.0f;

	for (int i = 0; i < 3; i++) {
		float posX = 45 + i * 10;
		float posY = 0;
		float posZ = 45;

		drawBuilding(posX, posY, posZ, buildingWidth, buildingHeight, buildingDepth, buildingTextureId3);

		posZ = boardWidth - 45;
		drawBuilding(posX, posY, posZ, buildingWidth, buildingHeight, buildingDepth, buildingTextureId3);
	}
}

////void addTree(int trunkTextureId, int crownTextureId) {
////	float trunkHeight = 3.0f;
////	float trunkRadius = 0.25f;
////	float crownRadius = 1.5f;
////
////	float posX1 = 20;
////	float posZ1 = 20;
////	float posX2 = 25;
////	float posZ2 = 20;
////
////	drawTree(posX1, 0, posZ1, trunkHeight, trunkRadius, crownRadius, trunkTextureId, crownTextureId);
////	drawTree(posX2, 0, posZ2, trunkHeight, trunkRadius, crownRadius, trunkTextureId, crownTextureId);
////}

void addTree(int trunkTextureId, int crownTextureId) {
	
	float trunkHeight = 3.0f;
	float trunkRadius = 0.25f;
	float crownRadius = 1.5f;

	float spacing = 10.0f;

	float treePositions[][2] = {
		{10, 10},
		{15, 15},
		{20, 10},
		{30, 10},
		{40, 15},
		{45, 20},
		{60, 22},
		{68, 18},
	};

	for (int i = 0; i < sizeof(treePositions) / sizeof(treePositions[0]); i++) {
		float posX = treePositions[i][0];
		float posZ = treePositions[i][1];

		drawTree(posX, 0, posZ, trunkHeight, trunkRadius, crownRadius, trunkTextureId, crownTextureId);
	}
}


void addRoad(int roadTexture) {
	float outerLength = 100.0f;
	float outerWidth = 40.0f;
	float roadWidth = 5.0f;
	float roadHeight = 0.1f;

	drawRoad(roadTexture, 60.0f, 100.0f, 40.0f, 20.0f, 0.1f);
}

void addRoadWithTree(int trunkTextureId, int crownTextureId) {
	int boardWidth = 100;
	int boardLength = 100;

	float roadOuterX1 = (boardLength - 60.0f) / 2.0f;
	float roadOuterX2 = roadOuterX1 + 60.0f;
	float roadOuterZ1 = (boardWidth - 40.0f) / 2.0f;
	float roadOuterZ2 = roadOuterZ1 + 40.0f;

	 float trunkHeight = 3.0f;
	 float trunkRadius = 0.25f;
	 float crownRadius = 1.5f;

	float treeSpacing = 10.0f;

	for (float z = roadOuterZ1; z <= roadOuterZ2; z += treeSpacing) {
		drawTree(roadOuterX1 - 0.2f, 0, z, trunkHeight, trunkRadius, crownRadius, trunkTextureId, crownTextureId);
	}

	for (float z = roadOuterZ1; z <= roadOuterZ2; z += treeSpacing) {
		drawTree(roadOuterX2 + 0.1f, 0, z, trunkHeight, trunkRadius, crownRadius, trunkTextureId, crownTextureId);
	}

	for (float z = roadOuterZ1 - 5.0f; z <= roadOuterZ2 + 5.0f; z += treeSpacing) {
		drawTree(roadOuterX1 - 10.0f, 0, z, trunkHeight, trunkRadius, crownRadius, trunkTextureId, crownTextureId);
	}

	for (float z = roadOuterZ1 - 5.0f; z <= roadOuterZ2 + 5.0f; z += treeSpacing) {
		drawTree(roadOuterX2 + 10.0f, 0, z, trunkHeight, trunkRadius, crownRadius, trunkTextureId, crownTextureId);
	}
}
