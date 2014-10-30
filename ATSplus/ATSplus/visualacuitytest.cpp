#include <GL/glew.h>
#include <GL\glut.h>
#include "visualacuitytest.h"

#include <objloader.hpp>

// include DevIL to load images
#include <IL/il.h>

#include <GL/freeglut.h>

// routines to  read the source code from file
#include "textfile.h"


// holder for the program id
GLuint p;
// holder for the vertex array object id
GLuint vao, textureID;

// ------------------------------------------------------------
//
//			Loading the image
//
// ------------------------------------------------------------

unsigned int ilLoadImage1(std::string filename) {

	ILboolean success;
	unsigned int imageID;

	// init DevIL. This needs to be done only once per application
	ilInit();
	// generate an image name
	ilGenImages(1, &imageID);
	// bind it
	ilBindImage(imageID);
	// match image origin to OpenGL’s
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	// load  the image
	success = ilLoadImage((ILstring)filename.c_str());
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	// check to see if everything went OK
	if (!success) {
		ilDeleteImages(1, &imageID);
		return 0;
	}
	else return imageID;
}


// ------------------------------------------------------------
//
//			Prepare texture
//
// ------------------------------------------------------------

void prepareTexture(int w, int h, unsigned char* data) {

	/* Create and load texture to OpenGL */
	glGenTextures(1, &textureID); /* Texture name generation */
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		w, h,
		0, GL_RGBA, GL_UNSIGNED_BYTE,
		data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

// --------------------------------------------------------
//
//			Shader Stuff
//
// --------------------------------------------------------

void setupShaders() {

	// variables to hold the shader's source code
	char *vs = NULL, *fs = NULL;

	// holders for the shader's ids
	GLuint v, f;

	// create the two shaders
	v = glCreateShader(GL_VERTEX_SHADER);
	f = glCreateShader(GL_FRAGMENT_SHADER);

	// read the source code from file
	vs = textFileRead("texture.vert");
	fs = textFileRead("texture.frag");

	// castings for calling the shader source function
	const char * vv = vs;
	const char * ff = fs;

	// setting the source for each shader
	glShaderSource(v, 1, &vv, NULL);
	glShaderSource(f, 1, &ff, NULL);

	// free the source strings
	free(vs); free(fs);

	// compile the sources
	glCompileShader(v);
	glCompileShader(f);

	// create a program and attach the shaders
	p = glCreateProgram();
	glAttachShader(p, v);
	glAttachShader(p, f);

	// Bind the fragment data output variable location
	// requires linking afterwards
	glBindFragDataLocation(p, 0, "outputF");

	// link the program
	glLinkProgram(p);

	GLint myLoc = glGetUniformLocation(p, "texUnit");
	glProgramUniform1d(p, myLoc, 0);

	// get the logs from the compile and link procedures
	GLint infologLength, charsWritten;
	char *infoLog;

	glGetShaderiv(v, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0)
	{
		infoLog = (char *)malloc(infologLength);
		glGetShaderInfoLog(v, infologLength, &charsWritten, infoLog);
		printf("\n%s\n", infoLog);
	}
	glGetShaderiv(f, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0)
	{
		infoLog = (char *)malloc(infologLength);
		glGetShaderInfoLog(f, infologLength, &charsWritten, infoLog);
		printf("\n%s\n", infoLog);
	}
	glGetProgramiv(p, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0)
	{
		infoLog = (char *)malloc(infologLength);
		glGetProgramInfoLog(p, infologLength, &charsWritten, infoLog);
		printf("\n%s\n", infoLog);
	}
}

VisualAcuityTest::VisualAcuityTest(QWidget * parent, const QGLWidget * shareWidget, Qt::WindowFlags f)
	: QGLWidget(parent, shareWidget, f)
{
	
	//setupShaders();

	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	//// the OpenGL version (major, minor)
	//glutInitContextVersion(3, 3);
	//// Profile selection, the core profile ensures no deprecated functions are used
	//glutInitContextProfile(GLUT_CORE_PROFILE);

}

VisualAcuityTest::~VisualAcuityTest()
{

}

void VisualAcuityTest::initializeGL()
{
	
	
	int w, h, id;
	unsigned char* data;

	// load image first so that window opens with image size
	//id = ilLoadImage1("test.jpg");
	id = ilLoadImage1("landoltC.png");
	// image not loaded
	if (id == 0)
	{
		printf("image not loaded\n");
	}

	ilBindImage(id);
	w = ilGetInteger(IL_IMAGE_WIDTH);
	h = ilGetInteger(IL_IMAGE_HEIGHT);
	data = ilGetData();


	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		//return -1;
	}

	//	Set up texture with the image data we got earlier
	prepareTexture(w, h, data);

	//	Load and prepare shaders
	setupShaders();

	glClearColor(0.2, 0.2, 0.2, 1);

	/*
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	
	//bool res = loadOBJ("cube.obj", vertices, uvs, normals); //cube, c_shape
	bool res = loadOBJ("c_shape.obj", vertices, uvs, normals); //cube, c_shape
	
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	*/

	// Data for the two triangles
	float position[] = { -1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f,

		1.0f, 1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.5f, 1.0f,
	};

	float textureCoord[] = {
		0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,

		1.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f };


	GLuint vertexLoc, texCoordLoc;

	// Get the locations of the attributes in the current program
	vertexLoc = glGetAttribLocation(p, "position");
	texCoordLoc = glGetAttribLocation(p, "texCoord");

	// Generate and bind a Vertex Array Object
	// this encapsulates the buffers used for drawing the triangle
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Generate two slots for the position and color buffers
	GLuint buffers[2];
	glGenBuffers(2, buffers);

	// bind buffer for vertices and copy data into buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(position), position, GL_STATIC_DRAW);
	glEnableVertexAttribArray(vertexLoc);
	glVertexAttribPointer(vertexLoc, 4, GL_FLOAT, 0, 0, 0);

	// bind buffer for normals and copy data into buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoord), textureCoord, GL_STATIC_DRAW);
	glEnableVertexAttribArray(texCoordLoc);
	glVertexAttribPointer(texCoordLoc, 2, GL_FLOAT, 0, 0, 0);

	// some GL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void VisualAcuityTest::paintGL()
{
	// clear the framebuffer (color and depth)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use the program p
	glUseProgram(p);
	// Bind the vertex array object
	glBindVertexArray(vao);
	// Bind texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	// draw the 6 vertices
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// swap buffers
	glutSwapBuffers();

	/*
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glVertex3f(0.0, 0.5, 0);
	glEnd();
	*/

	/*
	glColor3f(0.2, 0.2, 0.2);
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);
		
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableVertexAttribArray(0);
	//glDisableVertexAttribArray(1);

	*/


}

void VisualAcuityTest::resizeGL(int w, int h)
{

}

