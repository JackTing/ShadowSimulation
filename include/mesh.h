////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// This file is part of ShadowSimulation, a C++ app for schadow simulation    //
//                                                                            //
// Copyright (C) 2006 Alexandru Duliu                                         //
//                                                                            //
// ShadowSimulation is free software; you can redistribute it and/or          //
// modify it under the terms of the GNU  General Public License               //
// as published by the Free Software Foundation; either version 3             //
// of the License, or (at your option) any later version.                     //
//                                                                            //
// ShadowSimulation is distributed in the hope that it will be useful,        //
// but WITHOUT ANY WARRANTY; without even the implied warranty of             //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              //
// GNU General Public License for more details.                               //
//                                                                            //
// You should have received a copy of the GNU General Public License          //
// along with ShadowSimulation. If not, see <http://www.gnu.org/licenses/>.   //
//                                                                            //
///////////////////////////////////////////////////////////////////////////////

/***************************************************************
 *                                                             *
 * program  : Mesh                                             *
 * author   : Alexandru Duliu                                  *
 * version  : 0.1                                              *
 * e-mail   : duliu@in.tum.de                                  *
 *                                                             *
 ***************************************************************/
#ifndef MESH_H_
#define MESH_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mathutils.h"

class Mesh
{

protected:

	// Mesh type
	unsigned int meshType;
	int vertexPerFace;
	
	// Vertex data
	int vertexCount;
	float *vertices;
		
	// Index data
	int indexCount;
	unsigned int *indices;
	
	// Normal data
	int normalCount;
	float *normals;
	int faceNormalCount;
	float *faceNormals;
	
	// Texture Coordinate data
	int texCoordCount;
	float *texCoords;
	
	// Color data
	int colorCount;
	float *colors;
	int colorComponentCount;
	
	// various information
	float sizeX, sizeY, sizeZ;
	float centerX, centerY, centerZ;
	
	// analyze the mesh to determine its center and size
	void analyzeMesh();

	
public:

	static const unsigned int MESH_TYPE_TRIANGLES = 0x0001;
	static const unsigned int MESH_TYPE_QUADS = 0x0002;
	
	// empty constructor
	Mesh();
	
	// deconstructor
	~Mesh();
	
	// basic contructor
	Mesh(unsigned int meshType);
	
	// initialize Mesh
	void loadMesh(char *path);
	
	// calculate indices
	void calculateIndices();
	
	// calculate normals
	void calculateFaceNormals();
	void calculateNormals();

	// invert faces
	void invertFaces();
	void invertNormals();
	
	// center the mesh to (x,y,z)
	void centerMesh(float x, float y, float z);
	// center object to (0,0,0)
	void centerMesh();
	
	// scale the mesh to a new size, scale* gives the absolute size for that coordinate
	void resizeMesh(float newSizeX, float newSizeY, float newSizeZ);
	// scale the mesh so that it's max size on either coordinate is scale
	void resizeMesh(float newSize);

	// translate the Mesh
	void translateMesh(float transX, float transY, float transZ);

	// rotate the mesh
	void rotateMesh(float rotX, float rotY, float rotZ);
	
	// get the sizes of the Mesh
	inline float getSizeX();
	inline float getSizeY();
	inline float getSizeZ();
	
	// getters
	inline unsigned int getMeshType();
	inline int getVertexPerFace();
	
	inline int getVertexCount();
	inline float* getVertices();
		
	inline int getIndexCount();
	inline unsigned int* getIndices();
	
	inline int getNormalCount();
	inline float* getNormals();
	inline int getFaceNormalCount();
	inline float* getFaceNormals();
};

#include "mesh.inl"

#endif
