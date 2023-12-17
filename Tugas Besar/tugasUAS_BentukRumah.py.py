from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

w, h = 700, 700

def draw_line(x1, y1, x2, y2, color, line_width):
    glColor3f(*color)
    glLineWidth(line_width)
    glBegin(GL_LINES)
    glVertex2f(x1, y1)
    glVertex2f(x2, y2)
    glEnd()

def draw_square():
    #didnding kiri
    glColor3f(1.0, 0.7, 0.0) # warna orange
    glBegin(GL_QUADS)
    glVertex2f(340, 60)
    glVertex2f(340, 340)
    glVertex2f(140, 340)
    glVertex2f(140, 60)
    glEnd()

    #atap kiri atas
    glColor3f(0.5, 0.2, 0.0) #warna Coklat
    glBegin(GL_QUADS)
    glVertex2f(390, 330)
    glVertex2f(390, 420)
    glVertex2f(140, 420)
    glVertex2f(110, 330)
    glEnd()

    #dinding pintu
    glColor3f(1.0, 0.5, 0.0) # warna orange
    glBegin(GL_QUADS)
    glVertex2f(550, 60)
    glVertex2f(550, 270)
    glVertex2f(340, 270)
    glVertex2f(340, 60)
    glEnd()

    #pintu
    glColor3f(0.2, 0.2, 0.2) #abu-abu
    glBegin(GL_QUADS)
    glVertex2f(500, 65)
    glVertex2f(500, 220)
    glVertex2f(400, 220)
    glVertex2f(400, 65)
    glEnd()
    #gagang pintu
    glLineWidth(4)
    glColor3f(0.1,0.1,0.1)
    glBegin(GL_LINES)
    glVertex2f(410,140)
    glVertex2f(410,155)
    glEnd()

    #gagang pintu
    glLineWidth(2)
    glColor3f(0.1,0.1,0.1)
    glBegin(GL_LINES)
    glVertex2f(420,147)
    glVertex2f(410,147)
    glEnd()
    #atap bawah
    glColor3f(0.5, 0.2, 0.0)#warna Coklat
    glBegin(GL_QUADS)
    glVertex2f(580,250)
    glVertex2f(550,320)
    glVertex2f(340,320)
    glVertex2f(310,250)    
    glEnd()

    #dinding atas atap
    glColor3f(1.0, 0.5, 0.0) # warna orange
    glBegin(GL_QUADS)
    glVertex2f(550,320)
    glVertex2f(550,370)
    glVertex2f(340,370)
    glVertex2f(340,320)    
    glEnd()

  #jendela atas
    glColor4f(0,0,0,0.8) # hitam
    glBegin(GL_QUADS)
    glVertex2f(500,330)
    glVertex2f(500,380)
    glVertex2f(400,380)
    glVertex2f(400,330)    
    glEnd()
# garis vertikal jendela atas
    glLineWidth(1)
    glColor3f(0.1,0.1,0.1)
    glBegin(GL_LINES)
    glVertex2f(500,350)
    glVertex2f(400,350)
    glEnd()
# garis horizontal jendela atas
    glLineWidth(1)
    glColor3f(0.1,0.1,0.1)
    glBegin(GL_LINES)
    glVertex2f(450,330)
    glVertex2f(450,380)
    glEnd()
 #jendela samping kiri
    glColor3f(0.2, 0.2, 0.2) #abu-abu
    glBegin(GL_QUADS)
    glVertex2f(230,200)
    glVertex2f(230,300)
    glVertex2f(170,300)
    glVertex2f(170,200)    
    glEnd()
 #jendela samping kanan
    glColor3f(0.2, 0.2, 0.2) #abu-abu
    glBegin(GL_QUADS)
    glVertex2f(310,200)
    glVertex2f(310,300)
    glVertex2f(250,300)
    glVertex2f(250,200)    
    glEnd()
    glLineWidth(3.0)


#pagar vertical kiri
    glColor3f(1.0, 1.0, 1.0)
    glLineWidth(4)
    glBegin(GL_LINES)
    glVertex2f(130,60)
    glVertex2f(130,160)
    glEnd()
#pagar horizontal bawah
    glColor3f(1.0, 1.0, 1.0)
    glLineWidth(4)
    glBegin(GL_LINES)
    glVertex2f(340,62)
    glVertex2f(130,62)
    glEnd()

#pagar horizontal atas
    glColor3f(1.0, 1.0, 1.0)
    glLineWidth(4)
    glBegin(GL_LINES)
    glVertex2f(340,160)
    glVertex2f(128,160)
    glEnd()

    # Garis pagar
    for x in range(140, 340, 10):
        draw_line(x, 60, x, 160, (1.0, 1.0, 1.0), 3)
    
    #atap tengah triangles
    glColor3f(0.4, 0.2, 0.0)  # warna Coklat
    glBegin(GL_TRIANGLES)
    glVertex2f(570,370)
    glVertex2f(445,460)
    glVertex2f(320,370)
    glEnd()
  
    #dinding triangles
    glColor3f(1.0, 0.5, 0.0)  # warna orange
    glBegin(GL_TRIANGLES)
    glVertex2f(550,370)
    glVertex2f(445,450)
    glVertex2f(340,370)
    glEnd()

def iterate():
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluOrtho2D(0.0, w, 0.0, h)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()

def show_Screen():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    iterate()
    draw_square()
    glutSwapBuffers()

def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA)
    glutInitWindowSize(w, h)
    glutCreateWindow(b'Arifatwa_D0221081')
    glutDisplayFunc(show_Screen)
    glutIdleFunc(show_Screen)
    glutMainLoop()

if __name__ == "__main__":
    main()
