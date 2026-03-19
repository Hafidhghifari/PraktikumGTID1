#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>

float sudutRoda = 0.0f;

void lingkaran(float cx, float cy, float r, int jumlahTitik) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < jumlahTitik; i++) {
        float sudut = 2.0f * 3.1415926f * i / jumlahTitik;
        float x = cx + r * cos(sudut);
        float y = cy + r * sin(sudut);
        glVertex2f(x, y);
    }
    glEnd();
}

void persegi(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void gambarGunung(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void gambarMatahari() {
    glColor3f(1.0f, 0.9f, 0.0f);
    lingkaran(220.0f, 180.0f, 30.0f, 100);
}

void gambarAwan(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    lingkaran(x, y, 18.0f, 50);
    lingkaran(x + 18.0f, y + 8.0f, 20.0f, 50);
    lingkaran(x + 40.0f, y, 18.0f, 50);
    lingkaran(x + 20.0f, y - 8.0f, 18.0f, 50);
}

void gambarBackground() {
    // langit
    glColor3f(0.5f, 0.8f, 1.0f);
    persegi(-300.0f, 0.0f, 300.0f, 250.0f);

    // rumput
    glColor3f(0.0f, 0.75f, 0.0f);
    persegi(-300.0f, -120.0f, 300.0f, 0.0f);

    // jalan
    glColor3f(0.2f, 0.2f, 0.2f);
    persegi(-300.0f, -160.0f, 300.0f, -80.0f);

    // garis jalan
    glColor3f(0.9f, 0.9f, 0.9f);
    for (float i = -300.0f; i <= 300.0f; i += 90.0f) {
        persegi(i, -128.0f, i + 45.0f, -118.0f);
    }

    // gunung belakang
    glColor3f(0.35f, 0.45f, 0.35f);
    gambarGunung(-300.0f, 0.0f, -200.0f, 130.0f, -100.0f, 0.0f);
    gambarGunung(-130.0f, 0.0f, 0.0f, 190.0f, 130.0f, 0.0f);
    gambarGunung(60.0f, 0.0f, 180.0f, 150.0f, 300.0f, 0.0f);

    // gunung depan
    glColor3f(0.25f, 0.35f, 0.25f);
    gambarGunung(-260.0f, 0.0f, -150.0f, 100.0f, -40.0f, 0.0f);
    gambarGunung(-20.0f, 0.0f, 100.0f, 130.0f, 220.0f, 0.0f);

    gambarMatahari();
    gambarAwan(-220.0f, 170.0f);
    gambarAwan(-40.0f, 155.0f);
    gambarAwan(120.0f, 165.0f);
}

void gambarRoda() {
    // ban
    glColor3f(0.0f, 0.0f, 0.0f);
    lingkaran(0.0f, 0.0f, 15.0f, 100);

    // velg
    glColor3f(0.55f, 0.55f, 0.55f);
    lingkaran(0.0f, 0.0f, 8.0f, 100);

    // pusat roda
    glColor3f(0.85f, 0.85f, 0.85f);
    lingkaran(0.0f, 0.0f, 3.0f, 100);

    // jari-jari
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(-10.0f, -10.0f);
        glVertex2f( 10.0f,  10.0f);

        glVertex2f(-10.0f,  10.0f);
        glVertex2f( 10.0f, -10.0f);

        glVertex2f(-12.0f,  0.0f);
        glVertex2f( 12.0f,  0.0f);

        glVertex2f( 0.0f, -12.0f);
        glVertex2f( 0.0f,  12.0f);
    glEnd();
}

void gambarMobil() {
    // body utama
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-75.0f, -80.0f);
        glVertex2f(-75.0f, -35.0f);
        glVertex2f(-50.0f, -35.0f);
        glVertex2f(-22.0f, -10.0f);
        glVertex2f(25.0f, -10.0f);
        glVertex2f(50.0f, -35.0f);
        glVertex2f(75.0f, -35.0f);
        glVertex2f(75.0f, -80.0f);
    glEnd();

    // jendela kiri
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-43.0f, -35.0f);
        glVertex2f(-20.0f, -14.0f);
        glVertex2f(-3.0f, -14.0f);
        glVertex2f(-3.0f, -35.0f);
    glEnd();

    // jendela kanan
    glBegin(GL_POLYGON);
        glVertex2f(3.0f, -35.0f);
        glVertex2f(3.0f, -14.0f);
        glVertex2f(20.0f, -14.0f);
        glVertex2f(43.0f, -35.0f);
    glEnd();

    // garis tengah pintu
    glColor3f(0.75f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, -35.0f);
        glVertex2f(0.0f, -75.0f);
    glEnd();

    // gagang pintu
    glBegin(GL_LINES);
        glVertex2f(8.0f, -48.0f);
        glVertex2f(20.0f, -48.0f);
    glEnd();

    // lampu belakang
    glColor3f(1.0f, 0.0f, 0.0f);
    persegi(-75.0f, -58.0f, -68.0f, -48.0f);

    // lampu depan
    glColor3f(1.0f, 1.0f, 0.2f);
    persegi(68.0f, -58.0f, 75.0f, -48.0f);

    // cahaya lampu depan
    glColor3f(1.0f, 1.0f, 0.6f);
    glBegin(GL_TRIANGLES);
        glVertex2f(75.0f, -56.0f);
        glVertex2f(95.0f, -53.0f);
        glVertex2f(75.0f, -50.0f);
    glEnd();

    // roda kiri
    glPushMatrix();
        glTranslatef(-42.0f, -82.0f, 0.0f);
        glRotatef(sudutRoda, 0.0f, 0.0f, 1.0f);
        gambarRoda();
    glPopMatrix();

    // roda kanan
    glPushMatrix();
        glTranslatef(42.0f, -82.0f, 0.0f);
        glRotatef(sudutRoda, 0.0f, 0.0f, 1.0f);
        gambarRoda();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gambarBackground();
    gambarMobil();

    glutSwapBuffers();
}

void update(int value) {
    sudutRoda -= 5.0f;

    if (sudutRoda <= -360.0f) {
        sudutRoda += 360.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300.0, 300.0, -200.0, 250.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Mobil");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
