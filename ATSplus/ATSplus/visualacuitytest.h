#ifndef VISUALACUITYTEST_H
#define VISUALACUITYTEST_H

#include <QGLWidget>
#include <glm/glm/glm.hpp>

class VisualAcuityTest : public QGLWidget
{
	Q_OBJECT

public:
	VisualAcuityTest(QWidget * parent = 0, const QGLWidget * shareWidget = 0, Qt::WindowFlags f = 0);
	~VisualAcuityTest();

	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);



private:
	GLuint vertexbuffer;
	// Read our .obj file
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs; // Won't be used at the moment.
	std::vector<glm::vec3> normals; // Won't be used at the moment.
};

#endif // VISUALACUITYTEST_H
