#include "Program.h"

# define M_PI           3.14159265358979323846  /* pi */

GLuint ProgramMPGK::VAO;
GLuint ProgramMPGK::VBO;
GLuint ProgramMPGK::IBO;
GLuint ProgramMPGK::INDEKSY;
GLuint ProgramMPGK::programZShaderami;
GLuint ProgramMPGK::vertexShaderId;
GLuint ProgramMPGK::fragmentShaderId;
GLint ProgramMPGK::zmiennaShader;

float ProgramMPGK::naStopnie(float radiany) {
	return radiany * (180 / M_PI);
}
float ProgramMPGK::naRadiany(float stopnie) {
	return stopnie * (M_PI / 180);
}

ProgramMPGK::ProgramMPGK(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

ProgramMPGK::ProgramMPGK(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

ProgramMPGK::~ProgramMPGK()
{

}

void ProgramMPGK::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	glewExperimental = GLU_TRUE;
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Program");
}

void ProgramMPGK::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		//system("pause");
		exit(1);
	}
}

void  ProgramMPGK::wyswietl()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static GLfloat zmiana = 0.0f;
	zmiana += 0.0005f;
	glUniform1f(zmiennaShader, abs(sinf(zmiana)));//Wielko�� obiektu do shadera



	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (GLvoid*)(sizeof(GLfloat) * 4));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);


	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glPopMatrix();

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glutSwapBuffers();
}

void ProgramMPGK::usun()
{
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
	glDeleteProgram(programZShaderami);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);
	glDeleteVertexArrays(1, &VAO);
}

void ProgramMPGK::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}

void ProgramMPGK::stworzenieVBO()
{
	const int iloscWierzcholkow = 36;
	Wektor WektoryWierzcholkow[iloscWierzcholkow] = {
		//Wzorzec
		/*
		-++
		-+-
		--+
		---
		//
		-+-
		++-
		---
		+--
		//
		++-
		+++
		+--
		+-+
		//
		-++
		+++
		--+
		+-+
		//
		-++
		+++
		-+-
		++-
		//
		--+
		+-+
		---
		+--

		*/
		//
		Wektor(-0.4f, 0.4f, 0.4f, 1.0f),
		Wektor(-0.4f, 0.4f, -0.4f, 1.0f),
		Wektor(-0.4f,  -0.4f, 0.4f, 1.0f),
		Wektor(-0.4f,  -0.4f, -0.4f, 1.0f),
		//
		Wektor(-0.4f, 0.4f, -0.4f, 1.0f),
		Wektor(0.4f, 0.4f, -0.4f, 1.0f),
		Wektor(-0.4f,  -0.4f, -0.4f, 1.0f),
		Wektor(0.4f,  -0.4f, -0.4f, 1.0f),
		//
		Wektor(0.4f, 0.4f, -0.4f, 1.0f),
		Wektor(0.4f, 0.4f, 0.4f, 1.0f),
		Wektor(0.4f,  -0.4f, -0.4f, 1.0f),
		Wektor(0.4f,  -0.4f, 0.4f, 1.0f),
		//
		Wektor(-0.4f, 0.4f, 0.4f, 1.0f),
		Wektor(0.4f, 0.4f, 0.4f, 1.0f),
		Wektor(-0.4f,  -0.4f, 0.4f, 1.0f),
		Wektor(0.4f,  -0.4f, 0.4f, 1.0f),
		//
		Wektor(-0.4f, 0.4f, 0.4f, 1.0f),
		Wektor(0.4f, 0.4f, 0.4f, 1.0f),
		Wektor(-0.4f,  0.4f, -0.4f, 1.0f),
		Wektor(0.4f,  0.4f, -0.4f, 1.0f),
		//
		Wektor(-0.4f, -0.4f, 0.4f, 1.0f),
		Wektor(0.4f, -0.4f, 0.4f, 1.0f),
		Wektor(-0.4f,  -0.4f, -0.4f, 1.0f),
		Wektor(0.4f,  -0.4f, -0.4f, 1.0f),
	};
	Wektor WektoryKolorow[iloscWierzcholkow] = {
		//
		Wektor(1.0f, 0.0f, 0.0f, 1.0f),
		Wektor(1.0f, 0.0f, 0.0f, 1.0f),
		Wektor(1.0f, 0.0f, 0.0f, 1.0f),
		Wektor(1.0f, 0.0f, 0.0f, 1.0f),
		//
		Wektor(0.0f,1.0f, 0.0f, 1.0f),
		Wektor(0.0f,1.0f, 0.0f, 1.0f),
		Wektor(0.0f,1.0f, 0.0f, 1.0f),
		Wektor(0.0f,1.0f, 0.0f, 1.0f),
		//
		Wektor(0.0f,0.0f, 1.0f, 1.0f),
		Wektor(0.0f,0.0f, 1.0f, 1.0f),
		Wektor(0.0f,0.0f, 1.0f, 1.0f),
		Wektor(0.0f,0.0f, 1.0f, 1.0f),
		//
		Wektor(1.0f,0.0f, 1.0f, 1.0f),
		Wektor(1.0f,0.0f, 1.0f, 1.0f),
		Wektor(1.0f,0.0f, 1.0f, 1.0f),
		Wektor(1.0f,0.0f, 1.0f, 1.0f),
		//
		Wektor(1.0f,1.0f, 0.0f, 1.0f),
		Wektor(1.0f,1.0f, 0.0f, 1.0f),
		Wektor(1.0f,1.0f, 0.0f, 1.0f),
		Wektor(1.0f,1.0f, 0.0f, 1.0f),
		//
		Wektor(1.0f,1.0f, 1.0f, 1.0f),
		Wektor(1.0f,1.0f, 1.0f, 1.0f),
		Wektor(1.0f,1.0f, 1.0f, 1.0f),
		Wektor(1.0f,1.0f, 1.0f, 1.0f),
	};

	//Stw�rz tablic� wierzcholki
	GLfloat wierzcholki[iloscWierzcholkow*2*4];
	GLint licznik = 0;
	for (int i = 0;i < iloscWierzcholkow;i++) {
			wierzcholki[licznik] = WektoryWierzcholkow[i].getX();
			licznik+=1;
			wierzcholki[licznik] = WektoryWierzcholkow[i].getY();
			licznik += 1;
			wierzcholki[licznik] = WektoryWierzcholkow[i].getZ();
			licznik += 1;
			wierzcholki[licznik] = WektoryWierzcholkow[i].getW();
			licznik += 1;
			wierzcholki[licznik] = WektoryKolorow[i].getX();
			licznik += 1;
			wierzcholki[licznik] = WektoryKolorow[i].getY();
			licznik += 1;
			wierzcholki[licznik] = WektoryKolorow[i].getZ();
			licznik += 1;
			wierzcholki[licznik] = WektoryKolorow[i].getW();
			licznik += 1;

	}

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(wierzcholki), wierzcholki, GL_STATIC_DRAW);

}

void ProgramMPGK::stworzenieIBO()
{
	GLuint indeksyTab[] = { 0,1,2, 1,2,3, //przednia sciana  
					 4,5,6, 5,6,7, //tylna sciana
					 8,9,10, 9,10,11, //prawa sciana 
					 12,13,14, 13,14,15, //lewa sciana
					 16,17,18, 17,18,19, //dolna sciana 
					 20,21,22, 21,21,23 //gorna sciana 
	};

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeksyTab), indeksyTab, GL_STATIC_DRAW);
}

void ProgramMPGK::stworzenieProgramu()
{
	programZShaderami = glCreateProgram();

	if (programZShaderami == 0)
	{
		std::cerr << "Blad podczas tworzenia programu shaderow." << std::endl;
		//system("pause");
		exit(1);
	}

	const char * vertexShader;
	std::ifstream myfile0("vertexShader.txt");
	std::string contents0((std::istreambuf_iterator<char>(myfile0)),
		std::istreambuf_iterator<char>());
	vertexShader = contents0.c_str();

	const char * fragmentShader;
	std::ifstream myfile1("fragmentShader.txt");
	std::string contents1((std::istreambuf_iterator<char>(myfile1)),
		std::istreambuf_iterator<char>());
	fragmentShader = contents1.c_str();

	vertexShaderId = dodanieDoProgramu(programZShaderami, vertexShader, GL_VERTEX_SHADER);
	fragmentShaderId = dodanieDoProgramu(programZShaderami, fragmentShader, GL_FRAGMENT_SHADER);

	GLint linkowanieOK = 0;
	glLinkProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_LINK_STATUS, &linkowanieOK);
	if (linkowanieOK == GL_FALSE) {
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas linkowania programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(1);
	}

	GLint walidacjaOK = 0;
	glValidateProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_VALIDATE_STATUS, &walidacjaOK);
	if (walidacjaOK == GL_FALSE) {
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas walidacji programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(1);
	}

	glUseProgram(programZShaderami);

	zmiennaShader = glGetUniformLocation(programZShaderami, "zmianaShader");
	if (zmiennaShader == -1)
	{
		std::cerr << "Nie znalezion zmiennej uniform." << std::endl;
		//system("pause");
		exit(1);
	}
}

GLuint ProgramMPGK::dodanieDoProgramu(GLuint programZShaderami, const GLchar * tekstShadera, GLenum typShadera)
{
	GLuint shader = glCreateShader(typShadera);

	// 35633 -> vertex shader, 35632 -> fragment shader
	const GLchar * typShaderaTekst = typShadera == 35633 ? "vertex" : "fragment";

	if (shader == 0) {
		std::cerr << "Blad podczas tworzenia " << typShaderaTekst << " shadera." << std::endl;
		//system("pause");
		exit(0);
	}

	const GLchar * tekstShaderaTab[1];
	tekstShaderaTab[0] = tekstShadera;
	GLint dlugoscShadera[1];
	dlugoscShadera[0] = strlen(tekstShadera);
	glShaderSource(shader, 1, tekstShaderaTab, dlugoscShadera);

	glCompileShader(shader);
	GLint kompilacjaOK = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &kompilacjaOK);
	if (kompilacjaOK == GL_FALSE)
	{
		GLint dlugoscLoga = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetShaderInfoLog(shader, dlugoscLoga, NULL, &log[0]);
		std::cerr << std::endl;
		std::cerr << "Blad podczas kompilacji " << typShaderaTekst << " shadera." << std::endl;
		std::cerr << std::endl;
		std::cerr << "log: ";
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteShader(shader);
		//system("pause");
		exit(1);
	}

	glAttachShader(programZShaderami, shader);
	return shader;
}
void ProgramMPGK::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

int main(int argc, char** argv)
{

	ProgramMPGK obiektMPGK(786, 786, 100, 100);

	float mac[3][3] = { {1.0/3.0,2.0,3.0},{1.0,2.0,3.0},{4.0,0.0,0.0} };
	Macierz m1 = Macierz(mac);
	Macierz m2 = Macierz(2.0,3);

	Przeksztalcenia w;
	Macierz skalowania = w.macierzSkalowania(2.0f);
	Macierz obrotu = w.macierzObrotu3x3(obiektMPGK.naRadiany(0.5f));
	Macierz przesuniecia = w.macierzTranslacji(0.7);

	std::cout << m1 * m2;
	std::cout << std::endl;
	std::cout << m1 * skalowania;
	std::cout << std::endl;
	std::cout << m1 * obrotu;
	std::cout << std::endl;
	std::cout << m1 * przesuniecia;
	std::cout << std::endl;

	obiektMPGK.stworzenieOkna(argc, argv);
	obiektMPGK.inicjalizacjaGlew();
	obiektMPGK.sprawdzenieWersji();
	obiektMPGK.stworzenieVAO();
	obiektMPGK.stworzenieVBO();
	obiektMPGK.stworzenieIBO();
	obiektMPGK.stworzenieProgramu();
	glutDisplayFunc(obiektMPGK.wyswietl);
	glutIdleFunc(obiektMPGK.wyswietl);
	glutCloseFunc(obiektMPGK.usun);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();

	//system("pause");
	return 0;
}